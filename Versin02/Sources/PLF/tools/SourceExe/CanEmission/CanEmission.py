# coding=utf-8

#-------------------------------------------------------------------------------
# Name:
# Purpose:增加can报文时生成函数DATCplPreparerEmission的部分代码
#
# Author:      zhangchaom
#
# Created:     30/08/2016
# Copyright:   (c) zhangchaom 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import sys
import os
import time
import getpass
import shutil
import glob
import re


gIntMaxTxNumber = 200
gstrTxHandle2ChContentTemplate = """
#ifndef DAT_CPL_TXHANDLE2CH_H
#define DAT_CPL_TXHANDLE2CH_H

#define cLDBChannelCanPosHolder       ((U8)0xFFU)
#define cU8MaxTxHandle                ((U8)MAXHANDLENUMUU)

static const U8 scu8TxHandle2Ch[MAXHANDLENUMU] =
{
ARRAYCONTENT
};


static const U8 su8TxHandle2TxMsgLng[MAXHANDLENUMU]  =
{
ARRAYTXMSGLNG
};
#endif
"""


gStrDatCplFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL.c"
gstrSearchPath = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CDLp.h"
gstrSearchPath2 = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPLpx.h"
gstrSearchPath3 = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL_CFG.h"
gstrSearchPath4 = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\CAN_MSG_CFG.jil"#报文配置文件地址
gstrGenFilePath5 = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL_GEN_FILE.h"#生成文件存放地址

def SearchMacro(strFilePath):
    strResult = ""

    FileTemp = open(strFilePath,"r")
    strFile = FileTemp.read()
    FileTemp.close

    regComment1 = r"/\*[\s\S]*?\*/"#???
    regComment2 = r"//.*"
    #must fisrt match /**/ and then match //
    strFile = re.sub(regComment1,"",strFile,flags=re.S)
    strFile = re.sub(regComment2,"",strFile)

    ListTxHandle = p1.findall(strFile)
    ListTxSize = p2.findall(strFile)
##    print ListTxHandle,"\n",ListTxSize

    if len(ListTxHandle) == len(ListTxSize):
        for x in range(len(ListTxHandle)):

            strResult =strResult + " "*8 + "case " + ListTxHandle[x] + ":\n" + " "*12 + "mDATCdlLngTxHandle(TxHandle) = " + ListTxSize[x] + ";\n"+" "*12 + "break;\n\n"
    else:
        print "TxHandle Number not equle ListTxSize Number"

    return strResult

def WriteNewMacro(strNew):
    FileTemp = open(gStrDatCplFilePath,"r+")
    strFile = FileTemp.read()
    FileTemp.close

    #regComment3 = r"case"
    regComment3 = r"( +case[( ] *cDATCdlD_UUTxHandleTX_\w+ *[) ]*:\n +mDATCdlLngTxHandle[(]TxHandle[)].+;\n +break;\n\n)+"

    strFile = re.sub(regComment3,strNew,strFile)

    FileTemp = open(gStrDatCplFilePath,"w+")

    FileTemp.write(strFile)

    FileTemp.close

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

#下面由zjb添加，目的是为了设置发送消息的默认值
#这里要查找的Task结构体元素可能不全，所以
#筛选的条件要加宽
gReTxDefaultValStruct=r"\bTXMsgDefaultValues.*?{(.*?)};"
gReEachMsg=r"\b(TX\w+)\s{0,}=\s{0,}0x(\w{2})\s{0,};"
gListEaachMsg=[]


gReSendInitVal=r"define\s{1,}cDATCplInitBuffer\w+\s{1,}(.*)"
gReData = r"0x(\w{2})UL"

gReDiagMsgID = r"\bDiagTxMsgID.*?{(.*?)};"
gReEachDiagID = r"\b(DiagMsg\w{3})\s*=\s*(0x\w+).*?"
gListEachDiagMsgId = []

def SetTxMsgDeaultVal():
    global gListEaachMsg
    for intFileIndex in xrange(1,6):
        strFilePath = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL"+ "%s"%intFileIndex + "x.h"
        strFilePath = SubRealSourcePath(strFilePath)

        if os.path.exists(strFilePath):
            strFileContent = ""
            with open(strFilePath) as fileHandle:
                strFileContent = fileHandle.read()
                for eachTxMsg in gListEaachMsg:
                    #这里动态定义正则表达式，来查找相应的发送消息
                    reTxMsg = r"define\s{1,}cDATCplInitBuffer" + eachTxMsg[0] + r"\s{1,}(.*)"
                    result = re.search(reTxMsg,strFileContent,re.I)
                    #没有查找到消息，退出当前循环
                    if result == None:
                        continue
                    strTmp = result.group(0)
                    strAutoGenDefaultVal = re.search(gReData,strTmp,re.I).group(0)
                    if len(strAutoGenDefaultVal) > 0:
                        #如果找到默认数据
                        #2017年9月5日 08:46:05，这里出现过一个Bug，原来只是拿第一个字节的内容
                        #去替换其它7个字节，如果字节内容全部为0，则可以替换成功。但是发现一个
                        #特别奇怪的现象，个别字节内容不为0，这样就不能替换了。现在换个方式，
                        #将生成的字节中，只要满足\w{2}的都换成FF，不管其具体内容是什么
                        strNewVal =re.sub(gReData,"0X"+eachTxMsg[1]+"UL",strTmp)
                        strFileContent = strFileContent.replace(result.group(0), strNewVal)
                    else:
                        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                        print "data format error please check struct TXMsgDefaultValues"

                        sys.exit()


            with open(strFilePath,"w") as fileHandle:
                fileHandle.write(strFileContent)
                pass



        else:
            #文件不存在，表示分析完成，结束
            break


def GetTxMsgDefaultVals():
    global gListEaachMsg
    global gListEachDiagMsgId

    strJILFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\CAN_MSG_CFG.jil"
    strJILFilePath = SubRealSourcePath(strJILFilePath)

    with open(strJILFilePath,'r') as strFielHandle:
        gReTxDefaultValStructObj = re.compile(gReTxDefaultValStruct,re.S)
        fileContent = strFielHandle.read()
        temptest = gReTxDefaultValStructObj.findall(fileContent)
        for each in gReTxDefaultValStructObj.findall(fileContent):
            #这里得到结构体的内容，然后对结构体内容解析，得到
            #各个消息及其对应的默认值,添加re.I不区分大小写
            gListEaachMsg = re.findall(gReEachMsg,each,re.I)
##            for eachMsg in re.findall(gReEachMsg,each,re.I):
##                print eachMsg
##            print each


    if len(gListEaachMsg) == 0:
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "please define the Tx message default value in CAN_MSG_CFG.jil"
        sys.exit()

#下面这部分是设置发送诊断报文ID的
    gReDiagMsgIDStructObj = re.compile(gReDiagMsgID,re.S)
    Tmp = gReDiagMsgIDStructObj.findall(fileContent)
    for each in Tmp:
        gListEachDiagMsgId =re.findall(gReEachDiagID,each,re.I)

    if (len(gListEachDiagMsgId) == 0) or (len(gListEachDiagMsgId) > 2):
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "please check DiagTxMsgID in CAN_MSG_CFG.jil"
        sys.exit()




def ProCPLFile(strFilePath):
    with open(strFilePath,"r") as strFileContent:
        #得到文件内容，希望遍历所有的行得到相应消息的默认值地址
        pass

'''

'''
#修改诊断报文发送ID
def WriteDiagTxMsgAddress():
    global gListEachDiagMsgId

    FileTemp = open(gstrSearchPath,"r+")
    strFile = FileTemp.read()
    FileTemp.close

    for each in gListEachDiagMsgId:
        if each[0] == "DiagMsgP2P":
            strP2PId = each[1]
        elif  each[0] == "DiagMsgP2A":
            strP2AId = each[1]
        else:
            continue

    strTail = "UL)//generate by CanEmission"
    reDiagP2PObject = re.compile("(.*cDATCdlIdentTxTX.*DiagP2P.*tAddress\))0x(\w+)(.*)",re.I)
    strFile = reDiagP2PObject.sub("\g<1>" + strP2PId + strTail,strFile)#注意这里r"\1" + strP2AId会报错

    reDiagP2AObject = re.compile("(.*cDATCdlIdentTxTX.*DiagP2A.*tAddress\))0x(\w+)(.*)",re.I)
    strFile = reDiagP2AObject.sub("\g<1>" + strP2AId + strTail,strFile)

    FileTemp = open(gstrSearchPath,"w+")

    FileTemp.write(strFile)

    FileTemp.close


#精简报文是否超时宏 add by zc 2016-12-7 16:35:04
#增加报文是否收到标志相关宏  add by zc 2016-12-12 15:02:57
#2017-2-13 11:03:46  识别mDATReadU1BitNoMsgToClusterOnCANDefault改为mSERReadU1BitNoMsgToClusterOnCANDefault
def Write_mIsMsgLostMacro():

    FileTemp = open(gstrSearchPath2,"r+")
    strFile = FileTemp.read()
    FileTemp.close

    p3 = "U8 (RX_Can\d_(\w+_0x[\da-fA-F]{7,8})_Proxy\w+)"#查找报文信息
    p4 = "#define	mSERReadU1BitNoMsgToClusterOnCANDefault[\s\S]+#define mDATCplReadAppTrameReceived.*"  #生成的文件放在此处

    ListMsg = re.findall(p3, strFile, re.I) #找到要写的所有报文信息

    strWrite = "#define mDATCanIsMsgNotLost(v)  mDATCanIsMsgNotLost##v\n"
    strWrite2 = "#define mDATCplIsMsgReceived(v)  mDATCplIsMsgReceived##v\n"

    for x in range(len(ListMsg)):#len(ListMsg)
            strWrite = strWrite + "#define mDATCanIsMsgNotLost" + ListMsg[x][1] + " (mDATCplReadAppTrameReceived(" \
            + ListMsg[x][0] + "))\n"
            strWrite2 = strWrite2 + "#define mDATCplIsMsgReceived" + ListMsg[x][1] + " (mDATCplIsMsgReceived2(" \
            + ListMsg[x][0] + "))\n"

    strWrite = strWrite + "\n" + strWrite2

    strWrite = strWrite + "\n#define mDATCplIsMsgReceived2(FrameName)                 \\\n"
    strWrite = strWrite + " (mDATCplIsSetFlag(DATCplTableMsgReceivedFlg, cDATCdlD_UURxHandle##FrameName))\n"
    strWrite += r"\n#define mDATCplReadAppTrameReceived(FrameName)                 \\"
    strWrite = r"#define	mSERReadU1BitNoMsgToClusterOnCANDefault()		(DatCplNoMsgToClusterOnCANBus())\n\n" + strWrite

    FileTemp2 = open(gstrSearchPath3,"r+")
    strFile2 = FileTemp2.read()
    FileTemp2.close
    strFile2 = re.sub(p4, strWrite, strFile2)

    FileTemp = open(gstrSearchPath3,"w+")

    FileTemp.write(strFile2)

    FileTemp.close



def GenTxAndCANChMetrix():
    intChNum = 0
    strTxMsgName = ""
    strCh="cLDBChannelCan"
    #the initial value is 2, one TxHandle for P2P diag msg
    #one TxHandle for P2A diag msg
    intMaxTxHandle = 2

    listCh = []
    listTxMsgLng = []
    #here ocupy some place for lager use
    for x in xrange(0,gIntMaxTxNumber):
        listCh.append("cLDBChannelCanPosHolder")
        #将发送消息的默认长度设置为8字节,注意一定要写成字符串形式
        listTxMsgLng.append("8")

    strCDLph = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CDLp.h"
    strCpl1xhFixedPart = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CPL"
    strCDLph = SubRealSourcePath(strCDLph)
    strCpl1xhFixedPart = SubRealSourcePath(strCpl1xhFixedPart)

    #find the expression #define cDATCplNumberOfDataTX_CAN0_FuelReq_0x18EA0021_Proxy_0x300   3
    regTx = r"#define\s{1,}cDATCplNumberOfData(\w+)\s{1,}\d{1,}"
    #define cDATCdlD_UUTxHandleTX_CAN0_FuelReq_0x18EA0021_Proxy_0x300      ((tDATCdlD_UUTxHandle)2UL)
    regHandle =r"(#define\s{1,}cDATCdlD_UUTxHandle\w{1,}\s{1,}\(\(tDATCdlD_UUTxHandle\)(\d{1,})UL)"


    #get content
    fHandle = open(strCDLph)
    strCDLContent = fHandle.read()
    fHandle.close()


    #the following code is used to get CAN channels count.
    #the possible name is DAT_CPL1x.h,DAT_CPL2x.h, DAT_CPL3x.h,...
    for fileIndex in xrange(1,8):
        fileName = strCpl1xhFixedPart+ "%d"%fileIndex + "x.h"
        try:
            fHandle = open(fileName)
            #strSpecialCh must be before intChNum update
            #becuse the Ch number first start with 0
            strSpecicalCh = strCh + "%d"%intChNum
            intChNum = intChNum + 1
            strFileContent = fHandle.read()
            fHandle.close()



            for strTxMsgName in re.findall(regTx,strFileContent,re.S):
                #-----------------------------------
                for eachTxHandle in re.findall(regHandle,strCDLContent):
                    if  strTxMsgName in eachTxHandle[0]:
                        #find the correct TxHandle
                        #print eachTxHandle[0],eachTxHandle[1]
                        #here skip the 0XFFFFAABB message ,this message is not used
                        #it is just for only one  CAN channel project.
                        if "FFFFAABB"  in eachTxHandle[0].upper():
                            continue

                        ##########################################################
                        # 新加用于生成发送消息长度数组
                        try:
                            #这里要得到各个消息的发送的长度,正则表达式是根据消息名临时生成的
                            #这里添加代码，实现由Handle号来查找生成的发送消息的长度
                            #  #define cDATCdlTailleMinHCUState_0x18FF1724      ((U8)8)
                            regTxMsgLng = r"(#define\s{1,}cDATCdlTaille" + strTxMsgName + "\s{1,}\(\(U8\)(\d{1,})UL)"
                            oMatch = re.search(regTxMsgLng, strCDLContent,re.I)
                            if oMatch != None:
                                listTxMsgLng[int(eachTxHandle[1])] =  oMatch.group(2)

                            else:
                                #无法找到消息长度默认值，出错
                                print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                                print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                                print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                                print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                                sys.exit()


                        except IndexError as err:
                            #出错退出
                            sys.exit(1)
                            pass
                        ####################################################

                        intMaxTxHandle = intMaxTxHandle + 1

                        try:
                            #there is only one valid handle,so here break
                            listCh[int(eachTxHandle[1])] = strSpecicalCh

                            break
                        except IndexError as err:
                            print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                            print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                            print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                            print "!!!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                            print "please define the Tx message default value in CAN_MSG_CFG.jil"
                            sys.exit()
                        break
                #----------------------------------

                #gen file


        except IOError as err:
            #no file exist, means this is the end
            break
    #for end


    #here we get the TxHandle and the TxHandle number, this is enough
    #to generate file
    strArrContent = ""
    strArrMsgLng = ""
    for intIndex in xrange(0,intMaxTxHandle):
        strArrContent = strArrContent + "    " + listCh[intIndex] + ",\n"
        strArrMsgLng = strArrMsgLng + "    " + listTxMsgLng[intIndex] + ",\n"


    strFileContent = gstrTxHandle2ChContentTemplate.replace("ARRAYCONTENT",strArrContent)
    strFileContent = strFileContent.replace("MAXHANDLENUMU","%d"%intMaxTxHandle)


    #将消息长度内容替换
    strFileContent = strFileContent.replace("ARRAYTXMSGLNG",strArrMsgLng)

    strTxHandl2ChFileName =   r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CPL\DAT_CPL_TXHANDLE2CH.h"
    strTxHandl2ChFileName = SubRealSourcePath(strTxHandl2ChFileName)
    fHandle = open(strTxHandl2ChFileName,'w')
    fHandle.write(strFileContent)
    fHandle.close()



#搜索报文配置消息名称
def SearchKindOfMsgName():

    FileTemp = open(gstrSearchPath,"r+")
    strFile = FileTemp.read()
    FileTemp.close

    pTxMsgName = "cDATCdlIdentTx(TX\w+)"
    pRxMsgName = "cDATCdlIdentRx(RX\w+)"
    pDiagMsgName = "cDATCdlIdentRx(\w+DiagP2\w+)"

    ListTxMsgName = re.findall(pTxMsgName, strFile, re.I)#找到所有的发送报文名字
    ListRxMsgName = re.findall(pRxMsgName, strFile, re.I)#找到所有的接收报文名字
    ListDiagMsgName = re.findall(pDiagMsgName, strFile, re.I)

    for eachDiagMsg in ListDiagMsgName:
        ListTxMsgName.remove(eachDiagMsg)

    #如果接收报文中有ID为0xFFFFAABB的报文，从接收列表中删除，0XFFFFAABB为占位的无用报文
    for deleteTemp in ListRxMsgName:
        if "0xFFFFAABB" in deleteTemp:
            ListRxMsgName.remove(deleteTemp)
            break
    #print ListDiagMsgName

    #使能与禁止接收报文的宏生成
    str_DatCplDiagEnableAppRx = "#define mMacroDatCplDiagEnableAppRx() \\\n"
    str_DatCplDiagDisableAppRx = "#define mMacroDatCplDiagDisableAppRx() \\\n"
    for x in ListRxMsgName:
        str_DatCplDiagEnableAppRx += "    mDATCanMsgRxEnable(cDATCdlD_UURxHandle" + x + ");\\\n"
        str_DatCplDiagDisableAppRx += "    mDATCanMsgRxDisable(cDATCdlD_UURxHandle" + x + ");\\\n"


    #使能与禁止发送报文的宏生成
    str_DatCplDiagEnableAppTx = "#define mMacroDatCplDiagEnableAppTx() \\\n"
    str_DatCplDiagDisableAppTx = "#define mMacroDatCplDiagDisableAppTx() \\\n"
    for x in ListTxMsgName:
        str_DatCplDiagEnableAppTx += "    mDATCanMsgTxEnable(cDATCdlD_UUTxHandle" + x + ");\\\n"
        str_DatCplDiagDisableAppTx += "    mDATCanMsgTxDisable(cDATCdlD_UUTxHandle" + x + ");\\\n"


    FileTemp = open(gstrGenFilePath5,"w+")
    FileTemp.write("// this file is generated by CanEmission.py\n\n")
    FileTemp.write(str_DatCplDiagEnableAppRx + "\n\n")
    FileTemp.write(str_DatCplDiagDisableAppRx + "\n\n")
    FileTemp.write(str_DatCplDiagEnableAppTx + "\n\n")
    FileTemp.write(str_DatCplDiagDisableAppTx + "\n\n")
    FileTemp.close

'''
1.00
    CanEmission.exe version is 1.00,file create
2.00
    add function to set Tx message default values
3.00
    add function to gen channel and Tx message relationship
4.00
    add function to gen DAT_CPL_GEN_FILE.h
5.00
    使诊断发送报文ID可以通过CAN_MSG_CFG.JIL配置
6.00
    修复字符串替换时的一个小Bug，现在使用正则表示式替换，保证替换完整性
7.00
    在将长消息名修改为短消息名时，DATCplPreparerEmission函数内部，发送消息
    的长度无法正确设置。所以，这里修改消息长度设置方式。通过生成数组方式，
    以Handle做为索引，查找其生成的发送消息的长度。这样可以简化代码
'''
def PrintVersion():
    strVersion = "6.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)


def main():
    pass

if __name__ == '__main__':
    main()

    gStrDatCplFilePath = SubRealSourcePath(gStrDatCplFilePath)
    gstrSearchPath = SubRealSourcePath(gstrSearchPath)
    gstrSearchPath2 = SubRealSourcePath(gstrSearchPath2)
    gstrSearchPath3 = SubRealSourcePath(gstrSearchPath3)
    gstrSearchPath4 = SubRealSourcePath(gstrSearchPath4)
    gstrGenFilePath5 = SubRealSourcePath(gstrGenFilePath5)

    p1 = re.compile(r"#define +(cDATCdlD_UUTxHandleTX_\w+)")
    p2 = re.compile(r"#define +(cDATCdlTailleTX_\w+)")

    PrintVersion()
    #不再使用宏的方式设置发送消息长度值
    #WriteNewMacro(SearchMacro(gstrSearchPath))

    #赵江波添加，用于设置每个发送消息的默认值
    GetTxMsgDefaultVals()
    SetTxMsgDeaultVal()


    #修改诊断报文发送ID，可以通过配置文件进行ID的配置 add by zc 2017-4-13 10:48:52
    WriteDiagTxMsgAddress()

    #精简报文是否超时宏 add by zc 2016-12-7 16:35:04
    Write_mIsMsgLostMacro()

    #添加Dat_cpl中禁止使能报文发送相关代码
    SearchKindOfMsgName()

    #gen DAT_CPL_TXHANDLE2CH.h file
    GenTxAndCANChMetrix()
