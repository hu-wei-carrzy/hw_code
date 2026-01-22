import sys
import os
import mmap
import msvcrt
import binascii


##################################################

#从Hex得到Bin文件

def PrintStr(strOut):
    type = sys.getfilesystemencoding()
    print strOut.decode('UTF-8').encode(type)


strUsage = '''
************************************************************************
本文件的目的是从给产线的下载Hex文件中得到Bin数据，此数据是专用于
ICU511项目远程升级的AppData。下载地址固定为0X1A00008,这个值在串口
升级程序中固定在程序中
************************************************************************
'''
#############################################
#给产线的文件的名字，这个要能够动态识别
strFileName = "standalone_tcflash"
def GetHexFileName(strFileName):
    return strFileName+".hex"

def GetBinFileName(strFileName):
    return strFileName + '.bin'

#############################################
strFlag1 = r":20000800F000A0"
strFlag2 = r"78563412"
#检查文件中是否有相应字符串，
#以此检查文件合法性
def CheckFileValid(strFileLine):
    if strFlag1 in strFileLine:
        return True
    else:
        return False
#############################################
#这里从文件中得到具体Bin数据，为了简单起见，不做特别
#判断，只判断每行的长度。标准的长度为：
#:200008000001A00000FF0B00785634124861486148612E546869732069732070726F6A651C
#对于最后一行，如果长度不满足，是单独取其数据
strDemoLine = r":20000800F000A00000FF0B00785634124861486148612E546869732069732070726F6A652D"


#最小长度，包括头，地址，校验和
#XX表示数据，YY表示校验和
strMinDemoLine = r":200008XXYY"
intMinLen =  len(strMinDemoLine)
def CheckLineValid(strFileLine):

    bRet = True
    #这里减少1，是为了去除最后的1个换行符号
    intLineLen = len(strFileLine) - 1
    if intLineLen < intMinLen:
        #小于最小长度
        bRet = False
    elif intLineLen >len(strDemoLine):
        #大于最大长度
        bRet = False
    #如果长度信息为0，则此行无效
    elif strFileLine[1:1+2] == "00":
        bRet = False
    #记录类型为扩展地址，非数据，所以不用归入到Bin文件中。
    elif strFileLine[7:7+2] == '04':
        #print strFileLine
        bRet = False
    else:
        pass

    return bRet

def GetBinFromLine(strFileLine):
    #数据是在每一行的固定位置
    intLineLen = len(strFileLine)
    #这里减少3是去除最后2个数字，再加上1个换行符
    return strFileLine[7:intLineLen-2 - 1]



#if __name__ == '__main__':
def GetBinFromHexFile(strFileName):

    if  not os.path.exists(strFileName+".hex"):
        PrintStr(strFileName+".hex 文件不存在，请查证");
        print ord(msvcrt.getch())
        os._exit()

    #打开文件,读取内容，关闭文件
    hFileHanle = open(strFileName + ".hex", "r")
    strFileLines = hFileHanle.readlines()
    hFileHanle.close()

    #检测文件是否包含特定字符串，这是判断合法性的依据
    #前面的74个字符内定定要包含相应内容，否则出错
    if CheckFileValid(strFileLines[1]) == False:
        PrintStr("文件不合法，可能没有经过HexView处理")
        print ord(msvcrt.getch())
        os._exit()

    fHForUART = open(strFileName+".bin","wb")

    intLineLen = 0
    #将第一行忽略了，因为它不是真实的数据
    for eachLine in strFileLines[1:]:
        if CheckLineValid(eachLine) == True:
            #print GetBinFromLine(eachLine)
            intLineLen = len(eachLine)
            strBin = eachLine[9:intLineLen - 3]
            #print strBin
            #print binascii.a2b_hex(eachLine[2:20])
            filedata2 = bytearray(binascii.a2b_hex(strBin))
            fHForUART.write(filedata2)

    fHForUART.close()

#######################################################


#######################################################

def GetHexLineChkSum(strHexLine):
    #计算方式，计算整行的除去最后一个字节以外的所有字节和，然后0x100-和

    intSum = 0
    intLoop = 0
    #这里判断文件长度，必须是奇数
    if len(strHexLine)%2 != 1:
        print "Hex line length error,pleasse check"
        os._exit()

    #这里输入的是一个完整的Hex文件行，
    #校验和计算方式最后一个字节前的所有16进相加，
    #自然溢出，校验和=0x100-累加和
    for intLoop  in  range(0,len(strHexLine[1:]) - 2, 2):
        strEachByte = strHexLine[intLoop+1:intLoop+1 +2]
        intEachByte = int(strEachByte,16)
        intSum = intSum + intEachByte
    intSum = intSum%256
    intSum = 0x100  - intSum
    #对数据强制设置为2个字节，且转化为大写字母
    strSum = ("%02x"%intSum).upper()
    return strSum


listcrc32_tab= [\
        0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,\
        0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,\
        0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,\
        0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,\
        0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,\
        0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,\
        0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,\
        0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,\
        0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,\
        0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,\
        0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,\
        0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,\
        0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,\
        0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,\
        0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,\
        0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,\
        0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,\
        0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,\
        0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,\
        0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,\
        0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,\
        0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,\
        0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,\
        0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,\
        0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,\
        0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,\
        0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,\
        0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,\
        0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,\
        0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,\
        0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,\
        0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,\
        0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,\
        0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,\
        0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,\
        0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,\
        0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,\
        0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,\
        0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,\
        0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,\
        0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,\
        0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,\
        0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,\
        0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,\
        0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,\
        0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,\
        0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,\
        0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,\
        0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,\
        0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,\
        0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,\
        0x2d02ef8dL]

'''
listcrc16tab[256]= [\
	0x0000L,0x1021L,0x2042L,0x3063L,0x4084L,0x50a5L,0x60c6L,0x70e7L,\
	0x8108L,0x9129L,0xa14aL,0xb16bL,0xc18cL,0xd1adL,0xe1ceL,0xf1efL,\
	0x1231L,0x0210L,0x3273L,0x2252L,0x52b5L,0x4294L,0x72f7L,0x62d6L,\
	0x9339L,0x8318L,0xb37bL,0xa35aL,0xd3bdL,0xc39cL,0xf3ffL,0xe3deL,\
	0x2462L,0x3443L,0x0420L,0x1401L,0x64e6L,0x74c7L,0x44a4L,0x5485L,\
	0xa56aL,0xb54bL,0x8528L,0x9509L,0xe5eeL,0xf5cfL,0xc5acL,0xd58dL,\
	0x3653L,0x2672L,0x1611L,0x0630L,0x76d7L,0x66f6L,0x5695L,0x46b4L,\
	0xb75bL,0xa77aL,0x9719L,0x8738L,0xf7dfL,0xe7feL,0xd79dL,0xc7bcL,\
	0x48c4L,0x58e5L,0x6886L,0x78a7L,0x0840L,0x1861L,0x2802L,0x3823L,\
	0xc9ccL,0xd9edL,0xe98eL,0xf9afL,0x8948L,0x9969L,0xa90aL,0xb92bL,\
	0x5af5L,0x4ad4L,0x7ab7L,0x6a96L,0x1a71L,0x0a50L,0x3a33L,0x2a12L,\
	0xdbfdL,0xcbdcL,0xfbbfL,0xeb9eL,0x9b79L,0x8b58L,0xbb3bL,0xab1aL,\
	0x6ca6L,0x7c87L,0x4ce4L,0x5cc5L,0x2c22L,0x3c03L,0x0c60L,0x1c41L,\
	0xedaeL,0xfd8fL,0xcdecL,0xddcdL,0xad2aL,0xbd0bL,0x8d68L,0x9d49L,\
	0x7e97L,0x6eb6L,0x5ed5L,0x4ef4L,0x3e13L,0x2e32L,0x1e51L,0x0e70L,\
	0xff9fL,0xefbeL,0xdfddL,0xcffcL,0xbf1bL,0xaf3aL,0x9f59L,0x8f78L,\
	0x9188L,0x81a9L,0xb1caL,0xa1ebL,0xd10cL,0xc12dL,0xf14eL,0xe16fL,\
	0x1080L,0x00a1L,0x30c2L,0x20e3L,0x5004L,0x4025L,0x7046L,0x6067L,\
	0x83b9L,0x9398L,0xa3fbL,0xb3daL,0xc33dL,0xd31cL,0xe37fL,0xf35eL,\
	0x02b1L,0x1290L,0x22f3L,0x32d2L,0x4235L,0x5214L,0x6277L,0x7256L,\
	0xb5eaL,0xa5cbL,0x95a8L,0x8589L,0xf56eL,0xe54fL,0xd52cL,0xc50dL,\
	0x34e2L,0x24c3L,0x14a0L,0x0481L,0x7466L,0x6447L,0x5424L,0x4405L,\
	0xa7dbL,0xb7faL,0x8799L,0x97b8L,0xe75fL,0xf77eL,0xc71dL,0xd73cL,\
	0x26d3L,0x36f2L,0x0691L,0x16b0L,0x6657L,0x7676L,0x4615L,0x5634L,\
	0xd94cL,0xc96dL,0xf90eL,0xe92fL,0x99c8L,0x89e9L,0xb98aL,0xa9abL,\
	0x5844L,0x4865L,0x7806L,0x6827L,0x18c0L,0x08e1L,0x3882L,0x28a3L,\
	0xcb7dL,0xdb5cL,0xeb3fL,0xfb1eL,0x8bf9L,0x9bd8L,0xabbbL,0xbb9aL,\
	0x4a75L,0x5a54L,0x6a37L,0x7a16L,0x0af1L,0x1ad0L,0x2ab3L,0x3a92L,\
	0xfd2eL,0xed0fL,0xdd6cL,0xcd4dL,0xbdaaL,0xad8bL,0x9de8L,0x8dc9L,\
	0x7c26L,0x6c07L,0x5c64L,0x4c45L,0x3ca2L,0x2c83L,0x1ce0L,0x0cc1L,\
	0xef1fL,0xff3eL,0xcf5dL,0xdf7cL,0xaf9bL,0xbfbaL,0x8fd9L,0x9ff8L,\
	0x6e17L,0x7e36L,0x4e55L,0x5e74L,0x2e93L,0x3eb2L,0x0ed1L,0x1ef0L]
'''
'''
U32 Crc_CalculateCRC32(const U8 *dataPtr, U32 len, U32 startVal )
{
	U32 i;
	U32 crc32val = startVal;

	for (i = 0; i < len; i++) {
		crc32val = crc32_tab[(crc32val ^ dataPtr[i]) & 0xff] ^ (crc32val >> 8);
	}

	return crc32val;
}
'''


def GetCRC32(u8Data,u32Len,u32StartVal):
    temCrc32Val = u32StartVal
    u32Len = 1
    '''
        #u8Data要进行更新，以便于下一次计算，其原来的计算方式为：
        	for (i = 0; i < len; i++) {
		crc32val = crc32_tab[(crc32val ^ dataPtr[i]) & 0xff] ^ (crc32val >> 8);
	}
    '''
    temCrc32Val = listcrc32_tab[(temCrc32Val ^ u8Data) & 0xFF] ^ (temCrc32Val >> 8)

    return temCrc32Val



'''
def GetCRC16(u8Data,u32Len,u16StartVal):
    temCrc16Val = u16StartVal
    u16Loop = 0

    for u16Loop in xrange( 0, u32Len):
        temCrc32Val = listcrc16tab[(temCrc16Val ^ u8Data) & 0xFF] ^ (temCrc16Val >> 8)
'''

#这两个值是定死的，不可修改，否则可能导致错误
#第一个值的意义是在bin文件中，这个偏移量的值是
#CRC结构体的位置，这个位置第一个4字节是开始校验的
#地址，第二个4字节是校验的字节的数量，第三个字节是
#校验和，其中第一个4字节是固定的，不可修改
#第二个4字节是根据Bin文件大小来修改，第三个4字节
#根据计算结果来更改
intCrcAddrOffset = 0x000100E0+4
#这个值是校验和计算开始的地址
#这个地址处的值是软件版本号
intDataStartOffset = 0x000100F0
intDataSize = 0

'''
校验两个文件的存在性
校验Hex文件合法性，同时得到那一行数据，主要校验那一行对不对

计算校验和，包括得到Bin大小
根据校验和改写Hex文件，
完成
'''
strFileName = "standalone_tcflash"
strNewFileName = "standalone_tcflash_withCRC32"
strBanner = "************************************************************************\n"

#这个字符串在hex文件中一定存在，它是默认值，如果没有这行数据
#则此hex文件一定是错的
#这一行数据是从处理过的（经过Heview剪切过）的第二行数据
strCRCLineTemplate =r":20000800F000A00000FF0B00785634124861486148612E546869732069732070726F6A652D"
####################r":20000800F0000A0000FF0B00785634124861486148612E546869732069732070726F6A65C3"

def ChkHexValid():
    #这里按行读取Hex文件的内容，如果其中的默认一行，
    #内容合法，则可以认定此文件合法
    fHandle = open(strFileName + ".Hex")
    strFileContentList = fHandle.read()
    fHandle.close()

    if strCRCLineTemplate not in strFileContentList:
        PrintStr("%s.hex文件格式不正确，不包含默认行数据%s,请确认"%(strFileName,strCRCLineTemplate))
        print ord(msvcrt.getch())
        os._exit()
    else:
        print strBanner
        PrintStr("%s.hex校验校验正确,准备计算校验和\n"%strFileName)

def PrintStr(strOut):
    type = sys.getfilesystemencoding()
    print strOut.decode('UTF-8').encode(type)




def GetCRC():
    #计算校验和，计算思路：
    #读取Bin文件，从Bin文件固定的偏移量处，开始计算校验和，
    #计数的字节的数量=文件大小-偏移量，得到校验和后，
    #形成一个新的Hex文件行，替换原来固有的Hex行

    #得到文件大小

    fileSize = os.path.getsize(strFileName+".bin")
    print "Bin file size %d\n"%fileSize
    #这里为了测试，将文件大小固定为123456


    print strBanner
    PrintStr("%s.bin文件大小为(字节)：%d\n"%(strFileName,fileSize))

    #开始的空间有预留，从0XA00008-0XA000F0，这部分区间是不用的，
    #是不参与校验的，所以这部分空间要跨过去，这部分大小要去除
    intStartAddr = 0XF0 - 8

    intDataSize = fileSize - intStartAddr
    #读取文件内容，准备做校验和
    #通过内存映射文件方式读取文件大小
    #用这个方式读取文件，有个好处，将文件读取到内存中，
    #可以像操作内存一样的操作文件，方便计算校验和
    m = mmap.mmap(os.open(strFileName + ".bin",os.O_RDWR),0)
    #一次性读取所有的内容到内存中
    data = m.read(fileSize)
    #将数据转化为列表，以便于对每个字节计算校验和
    #从偏移量intDataStartOffset读取，直到文件结束
    dataList = list(map(ord,data[intStartAddr: ]))
    #输出固定范围的校验和
    #dataList = list(map(ord,data[intStartAddr: intStartAddr + 256*986 + 113]))
    #dataList = map(ord,data[intDataStartOffset:intDataStartOffset+10])
    #print dataList


    #开始计算校验和，CRC的初始值FFFFFFFFL
    intCrcStartVal = 0xFFFFFFFFL
    intLoop = 0
    for eachData in dataList:
        intLoop = intLoop + 1
        intCrcStartVal = GetCRC32(eachData,1,intCrcStartVal)
    m.close()


    print strBanner
    PrintStr("校验字节数量:0X%08X\nCRC32校验和为:0X%08X"%(intDataSize,intCrcStartVal))
    return (intDataSize,intCrcStartVal)


#根据输入的数字，得到小端形式，长度为8，
#如果输入数字为255，16进制0xFF,则返回FF000000
def GetLittleEndDataStr(intVal):
    strTmp = hex(intVal)

    #去除可能的L
    if strTmp[-1] == "L" or strTmp[-1] == "l":
        strTmp = strTmp[:-1]
    #去除前端的0x
    strTmp = strTmp[2:]
    #转化为小端并进行补齐操作，保证数据长度为8
    strTmp = "0"* (8-len(strTmp)) + strTmp

    if len(strTmp) != 8:
        PrintStr("数据长度不正确，请确认")
        print ord(msvcrt.getch())
        os._exit()

    #转化为小端形式
    strTmp = strTmp[6:8] + strTmp[4:6] + strTmp[2:4] + strTmp[0:2]

    #将字符串中字母转化为大写
    strTmp = strTmp.upper()
    return strTmp

def GetNewHexLine(intCRCSize, intCRCVal):
    #形成一个新行
    global strCRCLineTemplate

    #转化成16进制的字符串形式
    strCRCSize = GetLittleEndDataStr(intCRCSize)
    strCrcVale = GetLittleEndDataStr(intCRCVal)

    #":20000800 0001A000 00FF0B00 78563412 4861486148612E546869732069732070726F6A651C"
    #[0:9+8]，9+8得到的是开头及开始校验地址，后面依次是CRC计算大小，CRC值，具体数据值
    #注意：此行的最后部分校验和错误的，后面要重新计算并替换
    strNewHexLine = strCRCLineTemplate[0:9+8] + strCRCSize+ strCrcVale + strCRCLineTemplate[-42:]

    #这里增加一个冗余性判断，保证新生成的行

    if len(strNewHexLine) != len(strCRCLineTemplate):
        print "len error , please check"
        print ord(msvcrt.getch())
        os._exit()

    #对新行计算校验和
    strHexSum = GetHexLineChkSum(strNewHexLine)
    #对生成的校验和校验其长度，必须是一个字节，长度为2
    if len(strHexSum) != 2:
        print "Hex check sum length not right,please check"
        print ord(msvcrt.getch())
        os._exit()

    #用新生成的校验和替换原来的
    strNewHexLine = strNewHexLine[:-2] + strHexSum
    print strBanner
    PrintStr("处理%s.hex文件,要替换其中包含CRC校验和的一行数据"%strFileName)
    PrintStr("Old Hex Line：%s"%strCRCLineTemplate)
    PrintStr("New Hex Line：%s\n"%strNewHexLine)
    print strBanner
    return strNewHexLine




def GenNewHexFile(strNewHexLine):
    #根据得到的新的行，替换原来的Hex文件的一行，生成一个新的文件
    fHandle = open(strFileName + ".hex")
    strFileContentOld = fHandle.read()
    fHandle.close()

    #这里严格起见，判断长度是否一致
    if len(strNewHexLine) == len(strCRCLineTemplate):
        strFileContentNew = strFileContentOld.replace(strCRCLineTemplate,strNewHexLine)
    else:
        print "len error,please check"
    pass

    fHandle = open(strNewFileName + ".hex","w")
    fHandle.write(strFileContentNew)
    fHandle.close()

    print strBanner
    PrintStr("校验和处理完成，新生成的文件名字为%s_withCRC32.hex，%s.bin\n"%(strFileName,strFileName))
    PrintStr("Hex文件可用于Loader下载，生成的Bin文件可用于串口升级")
    PrintStr("请对比文件，保证结果正常性\n请按任意键退出\n")

    #print ord(msvcrt.getch())

strUsage = '''
************************************************************************
本文件的目的是计算校验和，它依赖于%s.bin和%s.hex文件，
请使用者保证二文件内容的一致性。最原始的
%s.hex文件不做任何修改,每运行一次此文件，会
生成一个文件：%s.hex此文件是经过校验和计算的，可用于下载
************************************************************************
'''%(strFileName,strFileName,strFileName,strNewFileName)
if __name__ == '__main__':
    PrintStr (strUsage)
    #先从Hex得到Bin文件
    GetBinFromHexFile(strFileName)

    (intCRCSize, intCRCVal) = GetCRC()

    strNewHexLine = GetNewHexLine(intCRCSize, intCRCVal)

    GenNewHexFile(strNewHexLine)

    #再次得到Bin文件，这次的源Hex文件就已经经过校验和计算了
    GetBinFromHexFile(strFileName+"_withCRC32")

    PrintStr("生成完成，请按任意键退出")
    print ord(msvcrt.getch())
