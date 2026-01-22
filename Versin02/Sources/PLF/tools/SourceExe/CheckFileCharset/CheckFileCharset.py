# coding=utf-8

import sys
import os
import getpass
import shutil
import chardet
import csv
import time
import threading


def CheckFileCharSet():
    fOut = file("FileCharset.csv","wb")
    writer = csv.writer(fOut)
    writer.writerow(["FileName", "CharSet"])

    print "Start serach all files, may consume 120s "
    print "this is still some bug in this file,if more than 120s there is not action,please close it by manual."
    print "doing.......\n"
    for root,dirs,files in os.walk(r".\..\..\..\source" ):
        for Each in files:
            strFileName = Each.upper()
            #如果超时，直接退出

            if ".C" in strFileName or (".H" in strFileName and ".HGR" not in strFileName) or ".JIL" in strFileName:
                #如果是.c/.h/jil文件，那么检测其编码格式
                with open(root+"\\" + Each,"rb") as t:
                    text = t.read()
                    nowCharset =  chardet.detect(text)['encoding']
                    writer.writerow([strFileName,nowCharset])



    fOut.close()

def TimeOutPro():
    tstart = time.time()
    tElipse = time.time() - tstart

    while True:
        tElipse = time.time() - tstart
        if tElipse > 120:
            break
    os._exit()


class TCheckFile(threading.Thread):
    def __init__(self,arg):
        super(TCheckFile,self).__init__()
        self.arg = arg

    def run(self):
        CheckFileCharSet()


class TCheckTime(threading.Thread):
    def __init__(self,arg):
        super(TCheckTime,self).__init__()
        self.arg = arg

    def run(self):
        TimeOutPro()



if __name__ == '__main__':
##    tTime = TCheckTime(1)
##    tFile = TCheckFile(2)
##
##    tTime.start()
##    tFile.start()
    CheckFileCharSet()
    pass

