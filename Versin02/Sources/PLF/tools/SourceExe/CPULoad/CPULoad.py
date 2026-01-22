
import re
import sys
import time
import struct
import os
from ctypes import *


'''
struct sTaskMetrics
{
    uint32 u32MinCallPeriod;
    uint32 u32MaxCallPeriod;
    uint32 u32AvgCallPeriod;
    uint32 u32TotalExecutionTime;
    uint32 u32Executions;
    uint32 u32MinExecutionTime;
    uint32 u32MaxExecutionTime;
    tTimeStamp LastTimestampOccurrence;
    uint8 u8LastOverflowOccurrence;
    uint8 u8TaskId;
};

'''

##class sTaskMetrics(Structure):
##    _fields_ = [
##        ("u32MinCallPeriod",          c_ubyte,  4),
##        ("u32MaxCallPeriod",          c_ubyte,  4),
##        ("u32AvgCallPeriod",          c_ubyte,  4),
##        ("u32TotalExecutionTime",     c_ubyte,  4),
##        ("u32Executions",             c_ubyte,  4),
##        ("u32MinExecutionTime",       c_ubyte,  4),
##        ("u32MaxExecutionTime",       c_ubyte,  4),
##        ("LastTimestampOccurrence",   c_ubyte,  2),
##        ("u8LastOverflowOccurrence",  c_ubyte,  1),
##        ("u8TaskId",                  c_ubyte,  1)
##    ]

gStrFilePath1 = r".\..\..\..\XXX\YYY\SCC2Gen\GEN\jili.h"
gStrFilePath2 = r".\..\..\..\XXX\YYY\LAP\LAP_CPULOAD\Portable\SRV_CpuMetrics_TimerDriver.c"
gStrFilePath3 = r".\..\..\..\XXX\YYY\LAP\LAP_CPULOAD\SRV_CpuTaskAndIntNum.h"

def GetBinContent(fileName):
    fHandle = open(fileName, 'rb')
    strContent = fHandle.read()
    fHandle.close()
    return strContent

member = ["u32MinCallPeriod",
    "u32MaxCallPeriod",
    "u32AvgCallPeriod",
    "u32TotalExecutionTime",
    "u32Executions",
    "u32MinExecutionTime",
    "u32MaxExecutionTime",
    "LastTimestampOccurrence",
    "u8LastOverflowOccurrence",
    "u8TaskId"]

mapTaskID2Name ={
"1"   : "Scheudler",
"2"   : "IdleState",
"0"   : "MainLoop",
"10"  : "IdleTask",

##"11":"DATCpuRefreshWatchDogTask",
##"12":"GraphEngineTask",
##"13":"DATBlkTask",
##"14":"DATDouTask",
##"15":"DATDinTask",
##"16":"DATSENSORTask",
##"17":"DATEepTask",
##"18":"DATDtcTask",
##"19":"DATBatTask",
##"20":"DATAnaTask",
##"21":"DATCVTTask",
##"22":"DATRtcTask",
##"23":"DATPnlTask",
##"24":"DATCdlCANReceptionTask",
##"25":"DATCdlCANTransmissionTask",
##"26":"DATPanTask",
##"27":"STK_CXDR_Stpr_Task",
##"28":"DATCnmTick",
##"29":"LAPMmiTask",
##"30":"DATModTask",
##"31":"TOSClock",

##"100":  "CAN0_ISR",
##"101":  "CAN1_ISR",
##"102":  "RTC_ISR",
##"103":  "MOTOR_ISR",
##"104":  "Speed_ISR",

"254":  "CPUTractTask",
"255": "error"
}

p1 = re.compile(r"#define mTOSTaskList\s+\\\n *{\\\n *DATCpuIdleTask *,\\\n((?: *\w+ *,\\\n)+)")
q1 = re.compile(r"(\w+)+")

p2 = re.compile(r"cIntEnterCPUTrace[(](\w+), *(\w+)[)]\ncIntLeaveCPUTrace[(]\w+[)]")

gLenth = [0,0]

#扫描获取mapTaskID2Name
def GetMapTaskID2Name():
    fHandle = open(gStrFilePath1, 'r')
    strFile = fHandle.read()
    fHandle.close()

    lTaskTemp = p1.findall(strFile)
    lTask = q1.findall(lTaskTemp[0])

    for each in range(len(lTask)):
        mapTaskID2Name[str(each+11)] = lTask[each]

    gLenth[0] = str(len(lTask))

    fTemp = open(gStrFilePath2, 'r')
    strFile = fTemp.read()
    fTemp.close()

    lCpuTrace =p2.findall(strFile)
    print lCpuTrace
    for each in range(len(lCpuTrace)):
        a,b = lCpuTrace[each]
        mapTaskID2Name[b] = a
    gLenth[1] = str(len(lCpuTrace))
    print mapTaskID2Name


def PrintTaskInfo(paraList,fHandle):
##    print "TaskName:%s"%(mapTaskID2Name["%d"%paraList[-1]])
    strTemp = ""
    strTemp =  "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,TaskName:%s"%\
            (paraList[0],paraList[1],paraList[2],paraList[3],paraList[4],\
            paraList[5],paraList[6],paraList[7],paraList[8],paraList[9],mapTaskID2Name["%d"%paraList[-1]])
    fHandle.write(strTemp+"\n")
##    print mapTaskID2Name[paraList[-1]]
##    for each in paraList:
####        print member[paraList.index(each)], "=", each
##        print each
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
    gStrFilePath1 = SubRealSourcePath(gStrFilePath1)
    gStrFilePath2 = SubRealSourcePath(gStrFilePath2)
    gStrFilePath3 = SubRealSourcePath(gStrFilePath3)

    GetMapTaskID2Name()

    ResultFile = open(gStrFilePath3,"w+")

    ResultFile.write("#ifndef SRV_CpuTaskAndIntNum_H\n#define SRV_CpuTaskAndIntNum_H\n")

    ResultFile.write("\n#define cTOSMaxTaskNumber (" + gLenth[0] +"UL)\n")
    ResultFile.write("#define cNumberUsedInterrupts ((unit8)" + gLenth[1] + "UL)\n")
    ResultFile.write("\n#endif\n")
    ResultFile.close()

    strBin = GetBinContent("CPULoad.bin")
    counter = len(mapTaskID2Name)
    loop = 0
    fHandle = open("CPULoadResult.csv","w")
    strTemp = ""
    strTemp =  "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,"%\
            (member[0],member[1],member[2],member[3],member[4],\
            member[5],member[6],member[7],member[8],member[9])
    fHandle.write(strTemp+"\n")

    for loop in xrange(counter):
        structTuple = struct.unpack("IIIIIIIHBB",strBin[32*loop:32+32*loop])
        if loop == 9:
            pass
        PrintTaskInfo( list(structTuple),fHandle)
    fHandle.close()


##    structObj = sTaskMetrics(strBin[0:64])
##    print struct.unpack("I",strBin[0:4])

 ##   print "u32AvgCallPeriod = %d"%((int(strBin[0:4], 10)) )



