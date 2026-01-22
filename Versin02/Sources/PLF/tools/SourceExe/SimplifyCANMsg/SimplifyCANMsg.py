
import sys
import os
import time
import getpass
import shutil
import glob
import re

# -*- coding: UTF-8 -*-


#定义正则表达式，用于替换消息的前缀和后缀
#在替换时要使用分组，所以这里定义了四个分组
#2018年3月28日 14:41:08，修改匹配错误\d->\w
gMsgReg = r"(([RT]X_CAN\d_)(.*?)(_Proxy_0x\w{1,3}))"



#其中的XXX,YYY是要被替换掉的
#这里列举了所有要替换的文件的名字
gAllFilsList = [                              \
    r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CDL\DAT_CDL.c",            \
    r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CDL\RxSpontTable.h",       \
    r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL_CFG.h",        \
    r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL_GEN_FILE.h",   \
    r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL.jil",          \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CDLp.h",               \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CNLp.h",               \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CILp.h",               \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\LAP_Diax.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPLpx.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL1x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL2x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL3x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL4x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL5x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL6x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL7x.h",              \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\jil.h",                    \
    r".\..\..\..\XXX\YYY\SCC2Gen\GEN\jili.h",                   \
    ]


def CleanMsgInFile(strFilePath):
    #检测文件是否存在
    if os.path.exists(strFilePath):
        #2018年3月26日 09:03:41
        #这里做个特殊处理，复制一份DAT_CDLp.h文件给BSP_CAN.c来使用。
        if "DAT_CDLP.H" in strFilePath.upper():
            strNewFilePath = strFilePath
            strNewFilePath = strNewFilePath.replace("DAT_CDLp.h","DAT_CDLPHTXT")
            shutil.copyfile(strFilePath,strNewFilePath)

        #读取文件内容
        fHandle = open(strFilePath,"r")
        strFileContent = fHandle.read()
        fHandle.close()

        pattern = re.compile(gMsgReg,re.I)
        #正则替换，将第3分组替换整体
        strNew = pattern.sub(r"\3",strFileContent)

        #将得到的新的字符串，其中名字已经替换过了，存储到文件中
        fHandle = open(strFilePath,'w')
        fHandle.write(strNew)
        fHandle.close()

    else:
        #print "Not file " + strFilePath
        pass


'''
1.00
    zjb create this file to simplify the CAN message usage.
2.00
    find a bug. In BSP_CAN.c, the ExcelVBA need the original DAT_CDLp.h
    file to get detailed info to fill received table.
    so here I get a copy of DAT_CDLp.h for BSP_CAN

3.00
    find a bug. In gMsgReg = r"(([RT]X_CAN\d_)(.*?)(_Proxy_0x\d{1,3}))"
    the last \d should be \w to include ABCDEF vlaue in Hex format.
'''
def PrintVersion():
    strVersion = "1.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)

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
    PrintVersion()
    for each in  gAllFilsList:
        realFilepath = SubRealSourcePath(each)
        CleanMsgInFile(realFilepath)
        #print realFilepath+"over\n"

