/*
this file is used to log the loader version info.
this file is created by zhaojbb at 2017.05.03
file version is located in starting address of App
code. 
 */

#include <string.h>
#include <stdio.h>

#define cU8Str_AppVer   "V0.020.03 "    /* 主版本号为1~99，占用2位，为了显示考虑，在最后一位添加空格，主版本变成2位时，就可以自动兼容显示 */

typedef struct
{
	//特别注意：如下两行不能编译，因为这两个区域是留给App使用的，
	//程序中不能占用
	//unsigned char  u8AppValidFlag[8U];
	//unsigned char  u8AppRunFlag[8U];
	unsigned char  u8FileLng[4U];
	unsigned char  u8CRCVal[4U];
	unsigned char  u8VerInfo[16U];
	unsigned char  u8PrdtInfo[32U];
	unsigned char  u8BCDDate[8];
	unsigned char  u8Reserved[128U-80U];
}tAppHeader;

const tAppHeader appHeaderInfo __attribute__ ((section(".Sec_App_Header"))) =
{
		//特别注意：如下两行不能编译，因为这两个区域是留给App使用的，
		//程序中不能占用
		//.u8AppRunFlag = "12345678",
		//.u8AppValidFlag = "12345678",
		.u8FileLng = "AABB",
		.u8FileLng = "AABB",
		.u8VerInfo = cU8Str_AppVer,
		.u8PrdtInfo = "12345678123456781234567812345678",
		.u8BCDDate = "12345678"
};

const unsigned char *cU8App_Pointer = &(appHeaderInfo.u8VerInfo[0]);


 //增加编译时间 2018年7月2日10:36:55
 static const char* sMonthTab[12U] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
 void GetCompileDate(unsigned char *CompileDate)
 {
 	unsigned int i = 0U;
 	unsigned int len = 0U;
	char date[20] = {0};
	char tmp_buf[8] = {0};

	(void)sprintf(date, "%s", __DATE__);//编译日期

	for(len = 0U; len < strlen(date); len++)
	{
		if(date[len] != ' ')
		{
			break;    //去掉开始的空格
		}
	}

	/********解析月********/
	(void)strncpy(tmp_buf, &date[len], 3U);
	len += 3U;
	for(i = 0U; i < 12U; i++)
 	{
 		if(0U == strncmp(tmp_buf, sMonthTab[i], 3U))
 		{
 			(void)sprintf((char *)&CompileDate[5], "%02d", (i + 1));
 			break;
 		}
 	}
	CompileDate[7] = '/';

	/********解析日********/
	len += 1U;
 	if(date[len] == ' ')
 	{
 		CompileDate[8] = '0';
 		len ++;
 		CompileDate[9] = date[len];
 		len ++;
 	}
 	else
 	{
 		CompileDate[8] = date[len];
 		len ++;
 		CompileDate[9] = date[len];
 		len ++;
 	}

 	/********解析年********/
 	len += 1U;
 	CompileDate[0] = date[len];
 	len ++;
 	CompileDate[1] = date[len];
 	len ++;
 	CompileDate[2] = date[len];
 	len ++;
 	CompileDate[3] = date[len];
 	len ++;
 	CompileDate[4] = '/';
 }
