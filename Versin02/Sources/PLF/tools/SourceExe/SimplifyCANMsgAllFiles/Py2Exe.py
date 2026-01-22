 # -*- coding: utf-8-*-
from distutils.core import setup
from glob import glob
import py2exe
import os, sys
import shutil


gListPyFile=[]
gCommonName=r"AutoGenChannels"
for strFileName in glob("*.py"):
    global gListPyFile
    global gCommonName
    gListPyFile.append(strFileName)
    if strFileName!=os.path.basename(sys.argv[0]):
        gCommonName = strFileName

if len(gListPyFile)>2:
    print '''More than 2 Py file,only allow 2 files(one is Py2Exe.py and
    another is the file for generated exe file name) in current folder'''
    exit()


gPyName = gCommonName.split(".")[0]+".py"
gExeName = gCommonName.split(".")[0]+".exe"


if len(sys.argv) == 1:
    sys.argv.append("py2exe")

includes = ["encodings", "encodings.*"]
options = {"py2exe":
             {   "compressed": 1,
                 "optimize": 2,
                 "includes": includes,
   "dist_dir": "bin",
                 "bundle_files": 1
             }
           }
setup(
     version = "0.1",
     description = u'ParseExcel',
     name = gPyName,
     options = options,
     zipfile = None,
     console=[{"script": gPyName}],
     )
os.remove("bin//w9xpopen.exe")
shutil.rmtree("build")

shutil.move(".\\bin\\%s"%gExeName,".\\%s"%gExeName)

#os.system("del /f /q %s"%gExeName)
#os.system("copy /y .\bin\%s   .\%s"%(gExeName,gExeName))
#shutil.copyfile(r".\bin\"+gExeName,gExeName)
#print "OK"
