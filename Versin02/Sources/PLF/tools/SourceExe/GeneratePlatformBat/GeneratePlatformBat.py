'''
1.00
    2016-10-20 11:00:44 Create this tool,
    工具链移植时执行一次，生成匹配新项目的.bat文件

'''
import sys
import os
import time
import getpass
import shutil
import glob
import re


gStrBatPathOld = r".\PlatformEntry.bat"
gStrBatPathNew = r".\..\PlatformEntry.bat"

gRegBat = r"\\XXX\\YYY"
gRealPath = r""

def ChangeBat():
    if os.path.exists(gStrBatPathOld):
        fHandle = open(gStrBatPathOld,"r")
        strFileContent = fHandle.read()
        fHandle.close()

        strSub = re.sub(gRegBat,gRealPath,strFileContent)
        #print strSub

        fHandle = open(gStrBatPathNew,"w")
        fHandle.write(strSub)
        fHandle.close()

    else:
        print "Not find PlatformEntry.bat , please check"


def PrintVersion():
    strVersion = "1.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)

#搜索真正的路径
def SubRealSourcePath():
    global gRealPath

    strReg = r".+(\\\w+\\\w+)\\LAP\\LAP_SUP"
    for root,dirs,files in os.walk(r".\..\..\.."):#搜索当前路径
        for Each in files:
            if Each == "LAP_SUP.c": #找到LAP_SUP.c，将LAP文件夹前面两层路径提取出来
                List = re.findall(strReg,root)
                gRealPath = List[0]

if __name__ == '__main__':

    PrintVersion()

    SubRealSourcePath()
    ChangeBat()