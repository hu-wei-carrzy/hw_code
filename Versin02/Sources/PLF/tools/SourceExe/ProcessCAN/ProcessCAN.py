
import sys
import os
import time
import getpass
import shutil
import glob
import re

'''
将其中的11位ID值换成真正的29位ID值
#define cDATCdlIdentTxDiagOnCanPAP      ((tAddress)0x600UL)
#define cDATCdlIdentTxDiagOnCanDiffusion      ((tAddress)0x998UL)
#define cDATCdlIdentTxTX_CAN1_LocalTime_0x18FEE617_Proxy_0x180      ((tAddress)0x18FEE617UL)
#define cDATCdlIdentTxTX_CAN1_Mile_0x18FEC117_Proxy_0x281      ((tAddress)0x18FEC117UL)
'''
gRegNormalMsg=r"#define\s+cDATCdlIdentTxTX_CAN\d_\w+?_0x(\w+?)_Proxy_0x\w+?\s{1,}\((\(tAddress\)0x\w+UL)\)"
gRegSubID = r"\(\(tAddress\)0x(\w+)UL\)"
gRegP2P = r"cDATCdlIdentTxDiagOnCanPAP\s+\(\(tAddress\)0x(\d+)UL\)"
gRegDiffusion=r"cDATCdlIdentTxDiagOnCanDiffusion\s+\(\(tAddress\)0x(\d+)UL\)"



gStrDATCDLpFilePath = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\DAT_CDLp.h"
gStrRxSpontTableHFilePath = r".\..\..\..\XXX\YYY\DAT\DAT_CAN\DAT_CDL\RxSpontTable.h"

gRegRXHandle = r"#define\s{1,}(cDATCdlD_UURxHandle(?P<MsgName>\w+))\s{1,}\(\(tDATCdlD_UURxHandle\)(\d{1,})\)"
gRxCBKDemo = r"{CallBackReceptionMsgName, ((tAddress)0xFFFFFFFFUL)}"
gRxCBKFuncHeader = """#define mDATCdlDefRxSpontTable()  \\
const tRxSpontWithAddr DATCanRxSpontTable[] = \\
{"""




def GetRxMsgName():
    strFileContent = ""
    strRxCBKList = ""
    strEachLine = ""

    if os.path.exists(gStrDATCDLpFilePath):
        #fMsg2Hadnle = open("Msg2Handle.txt","w")
        fHandle = open(gStrDATCDLpFilePath,"r")
        strFileContent = fHandle.read()
        #查找每个接收消息的句柄
        for each in (re.findall(gRegRXHandle,strFileContent,re.S)):
            #查找每个句柄值
            #print each[1]
            strRxCBKList = strRxCBKList + gRxCBKDemo.replace("MsgName", each[1]) + ",\\\n"
            #fMsg2Hadnle.write(each[1] + "----" + each[2] + "\n")
        #fMsg2Hadnle.close()

        #listTest = re.findall(gRegNormalMsg,strFileContent,re.I)
        #print listTest
        for each in (re.findall(gRegNormalMsg,strFileContent,re.I)):
            #print each[0] + "---" + each[1] + "\n"
            strFileContent = strFileContent.replace(each[1],"(tAddress)0x" +  each[0]+"UL")
            pass
        fHandle.close()

        fNew = open(gStrDATCDLpFilePath,"w")
        fNew.write(strFileContent)
        fNew.close()

        return gRxCBKFuncHeader + strRxCBKList[0:-3] + "};"
    else:
        print "Not find DAT_CDLp.h , please check"

'''
1.00
    Create this tool
2.00
    bug fix about the gRegNormalMsg
    bug:
        #define cDATCdlIdentTxTX_CAN0_RedarSw_0x18FFFD17_Proxy_0x100      ((tAddress)0x100UL)
    the original all 100UL will be replaced by 0x18FFFD17.
    include the 100UL not in this macro.
    now the expand the scope:100UL->(tAddress)0x100UL

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
    gStrDATCDLpFilePath = SubRealSourcePath(gStrDATCDLpFilePath)
    gStrRxSpontTableHFilePath = SubRealSourcePath(gStrRxSpontTableHFilePath)

    PrintVersion()
    fHandle = open(gStrRxSpontTableHFilePath,"w")
    fHandle.write( GetRxMsgName())
    fHandle.close()