/*--------------------------------------------------------------------------
Body Identification
--------------------------------------------------------------------------*/
#define LDB_AD "LDB_AD"
#include "LDB_AD.h"

#define cADC0ChnMax 				9U
#define cADCChnExp 			     	18U
#define cADC1ChnMax 				6U

// ADC0通道选择
const U8 u8AD0ChnSel[cADC0ChnMax] =
{
	eAdHdCh0, eAdHdCh1, eAdHWCh2, eAdHWCh4,
	eAdHWCh9, eAdHWCh10, eAdHWCh11,eAdHWCh14,
	eAdHWCh15
};

// ADC1通道选择
const U8 u8AD1ChnSel[cADC1ChnMax] =
{
	eAdHWCh2, eAdHWCh3, eAdHWCh4, eAdHWCh5,
	eAdHWCh6, eAdHWCh13
};

static U8 su8ADChsSel;
static BOOL sbADConverflag ;
static U16 su16AD0buff[cADC0ChnMax];
static U16 su16AD1buff[cADC1ChnMax];
static U16 su16ADCbuff[cADCChnExp];

/**************************************************************************************************
 名称：LDBADInit
 作用：AD模块初始化
  输入：无
 返回：无
 描述：由于有些通道需要LDB层知道，不需要BSP层知道，所以此处通道选择放到AD初始化后，结束初始化前
**************************************************************************************************/
void LDBADInit(void)
{
    BSPAdInit();			// AD主模块初始化
}

/**************************************************************************************************
 名称：LDBScanChn
 作用：AD模块启动
  输入：无
 返回：无
 描述：此处启动AD模块进行扫描
**************************************************************************************************/
void LDBScanChn(void)
{
	static U8 u8adcindex=0;
	if(u8adcindex==8){
		//BSPOutputCtr(OUT_DSEL1_2, 0);
		//BSPOutputCtr(OUT_DSEL3_4, 0);
	}else if(u8adcindex==15){
		//BSPOutputCtr(OUT_DSEL1_2, 1);
		//BSPOutputCtr(OUT_DSEL3_4, 0);
	}else if(u8adcindex==16){
		//BSPOutputCtr(OUT_DSEL1_2, 0);
		//BSPOutputCtr(OUT_DSEL3_4, 1);
	}else if(u8adcindex==17){
		//BSPOutputCtr(OUT_DSEL1_2, 1);
		//BSPOutputCtr(OUT_DSEL3_4, 1);
	}
	
	if (BSPAdReadAdc0ConversionFlg())
	{
		if(u8adcindex<9){
			su16ADCbuff[u8adcindex] = BSPAdReadAdc0Value();
		}else if(u8adcindex>8 && u8adcindex<15){
			su16ADCbuff[u8adcindex] = BSPAdReadAdc1Value();
		}else if(u8adcindex>14 && u8adcindex<18){
			su16ADCbuff[u8adcindex] = BSPAdReadAdc0Value();
		}
		u8adcindex ++;
		if(u8adcindex >= 18){
			u8adcindex = 0;
			sbADConverflag = cTrue;
		}

		if(u8adcindex<9){
			BSPAdSelectADC0chn(u8AD0ChnSel[u8adcindex]);
		}else if(u8adcindex>8 && u8adcindex<15){
			BSPAdSelectADC1chn(u8AD1ChnSel[u8adcindex-9]);
		}else if(u8adcindex==15){
			BSPAdSelectADC0chn(u8AD0ChnSel[u8adcindex-7]);
		}else if (u8adcindex==16){
			BSPAdSelectADC0chn(u8AD0ChnSel[u8adcindex-8]);
		}else if (u8adcindex==17){
			BSPAdSelectADC0chn(u8AD0ChnSel[u8adcindex-9]);
		}

		BSPAdClearAdc0ConversionFlag();
	}
}
/*	if (BSPAdReadAdc0ConversionFlg())
	{
		su16AD0buff[u8adc0index] = BSPAdReadAdc0Value() ;
		u8adc0index ++;
		if(u8adc0index >= cADC0ChnMax)
		{
			u8adc0index = 0;
			sbADConverflag = cTrue;
		}

		BSPAdSelectADC0chn(u8AD0ChnSel[u8adc0index]);
	}*/

/**************************************************************************************************
 名称：LDBAdReadConvertedValue
 作用：读取转换完成的数据到pMsg
  输入：pMsg——数据地址
 返回：无
 描述：依次将数据读进来
**************************************************************************************************/
void LDBAdReadConvertedValue(U16* pMsg)
{
   uint8_t u8index = 0;

   for(u8index = 0; u8index <cADCChnExp ; u8index ++ )
   {
	   pMsg[u8index] = su16ADCbuff[u8index];
   }
}

/**************************************************************************************************
 名称：LDBADReceiveWithAddr
 作用：读取AD模块的数据
  输入：addr——数据类型，pMsg——数据地址
 返回：无
 描述：1.cLDBADAdrIsScanOver——读取AD是否转换完成；
 	  2.cLDBADReadAdValues——读取AD的数据；
**************************************************************************************************/
void LDBADReceiveWithAddr(tAddress addr, tMsg* pMsg)
{
    mLIBassert((pMsg != (tMsg *)NULL) && (pMsg->pBuffer != (U8*)NULL));

    switch(addr)
    {
		case cLDBADAdrIsScanOver:
			pMsg->pBuffer[0U] = sbADConverflag;
			sbADConverflag = cFalse;
			break;

		case cLDBADReadAdValues:
			LDBAdReadConvertedValue((U16*)(pMsg->pBuffer));
			break;

		default:
			break;
    }
}

/**************************************************************************************************
 名称：LDBADControl
 作用：控制AD模块
  输入：Ctrl——控制类型
 返回：无
 描述：主要提供给上层服务
**************************************************************************************************/
void LDBADControl(tCtrl Ctrl)
{
    switch(Ctrl)
    {
        case cLDBADEnterActiveMode :
            BSPAdStart();
            break;

       case cLDBADEnterSleepMode :
    	   BSPAdStop();
            break;

       case cLDBADStartAD:
    	   BSPAdStart();
           break;

       case cLDBADStopAD:
    	   BSPAdStop();
    	   break;

       case cLDBADStartADScan:
    	   LDBScanChn();
    	   break;

       default :
            mLIBassert(cFalse);
            break;
   }
}

