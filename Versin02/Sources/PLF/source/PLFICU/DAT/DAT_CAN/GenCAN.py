
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
gRegNormalMsg=r"#define\s+cDATCdlIdentTxTX_CAN\d_\w+?_0x(\w+?)_Proxy_0x\w+?\s{1,}\(\(tAddress\)0x(\w+UL)\)"
gRegSubID = r"\(\(tAddress\)0x(\w+)UL\)"
gRegP2P = r"cDATCdlIdentTxDiagOnCanPAP\s+\(\(tAddress\)0x(\d+)UL\)"
gRegDiffusion=r"cDATCdlIdentTxDiagOnCanDiffusion\s+\(\(tAddress\)0x(\d+)UL\)"



gStrDATCDLpFilePath = r".\..\..\SCC2Gen\GEN\DAT_CDLp.h"
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
        fMsg2Hadnle = open("Msg2Handle.txt","w")
        fHandle = open(gStrDATCDLpFilePath,"r")
        strFileContent = fHandle.read()
        #查找每个接收消息的句柄
        for each in (re.findall(gRegRXHandle,strFileContent,re.S)):
            #查找每个句柄值
            #print each[1]
            strRxCBKList = strRxCBKList + gRxCBKDemo.replace("MsgName", each[1]) + ",\\\n"
            fMsg2Hadnle.write(each[1] + "----" + each[2] + "\n")
        fMsg2Hadnle.close()

        #strTest = "#define cDATCdlIdentTxTX_CAN1_DiagP2P_0x18DA10F1_Proxy_0x800      ((tAddress)0x801UL)\n"
        #strTest.replace("801","AAAAA")
        #查找每个发送消息的句柄

        for each in (re.findall(gRegNormalMsg,strFileContent)):
            #strFileContent = re.sub(gRegSubID,"((tAddress)0x"+each[0]+"UL)",strFileContent)
            strFileContent = strFileContent.replace(each[1],each[0]+"UL")
            pass
        fHandle.close()

        fNew = open(gStrDATCDLpFilePath,"w")
        fNew.write(strFileContent)
        fNew.close()

        return gRxCBKFuncHeader + strRxCBKList[0:-3] + "};"
    else:
        print "Not find DAT_CDLp.h , please check"


if __name__ == '__main__':
    fHandle = open(".\DAT_CDL\RxSpontTable.h","w")
    fHandle.write( GetRxMsgName())
    fHandle.close()