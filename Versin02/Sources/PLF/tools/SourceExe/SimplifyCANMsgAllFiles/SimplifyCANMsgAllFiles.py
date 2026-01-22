
import sys
import os
import time
import getpass
import shutil
import glob
import re

# -*- coding: UTF-8 -*-


#定义正则表达式
#在替换时要使用分组，所以这里定义了四个分组
#2018年3月28日 14:41:08，修改匹配错误\d->\w
gMsgReg = r"(([RT]X_CAN\d_)(.*?)(_Proxy_0x\w{1,3}))"




def CleanMsgInFile(strFilePath):
    #检测文件是否存在
    if os.path.exists(strFilePath):
        #read file content
        fHandle = open(strFilePath,"r")
        strFileContent = fHandle.read()
        fHandle.close()

        pattern = re.compile(gMsgReg,re.I)
        #先查看是否有匹配的内容，只有有内容匹配时，才对文件操作
        isMatched = pattern.search(strFileContent)
        if isMatched !=None:
            #正则替换，将第3
            strNew = pattern.sub(r"\3",strFileContent)

            #将得到的新的字符串，其中名字已经替换过了，存储到文件中
            fHandle = open(strFilePath,'w')
            fHandle.write(strNew)
            fHandle.close()

    else:
        pass



'''
1.00
    Create this tool to process all C and H and JIL files.
2.00
    find a bug. In gMsgReg = r"(([RT]X_CAN\d_)(.*?)(_Proxy_0x\d{1,3}))"
    the last \d should be \w to include ABCDEF vlaue in Hex format.
'''
def PrintVersion():
    strVersion = "1.00"
    print "%s version is %s"%(os.path.basename(sys.argv[0]),strVersion)


if __name__ == '__main__':

    PrintVersion()
    #遍历当前所有的文件，替换相应的文件夹中的内容，
    #gen文件夹下的不再替换

    for root, dirs, files in os.walk(r"."):
        for each in files:
            if ".c" == each[-2:].lower() or ".h" == each[-2:].lower() or ".jil" == each[-4:].lower():
                #这里CAN_MSG_CFG.jil文件不能处理，它是由Excel生成的，是生成代码的源
                if each.upper() != "CAN_MSG_CFG.jil".upper():
                #对每个文件进行处理替换报文头尾
                    CleanMsgInFile(root+"\\"+each)
                    print root+"\\"+each+"Processed \n"

    print "Process files Over, please close the program."
    input()

