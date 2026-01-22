
//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      ICU511
// Language:     C
// -----------------------------------------------------------------------------
// Component:  ��дDID
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time: 2017��11��23�� 15:27:59
//zjb
//1���޸Ĳ���DIDдʱû���ж���Ч��Χ������
//2���¼�һ���ļ���ר�Ŷ���������Ч��Χ
//2017��11��23�� 15:55:03
//zjb
//EEP���ô���EEP_VehicleType->EEP_ShowVehType
//2017��11��24�� 09:17:43
//zjb
//�޸ĵ�ѹ�궨����ѹ�궨��Χֵ
//2017��11��24�� 11:07:11
//zjb, 3350
//�޸�ʱ���޷���ȡ��bug
//2017��11��24�� 13:36:23
//zjb ,3349
//�޸��û��ɱ��λ�ô�����������󣬲�����0��ʾ�Ƿ���ԭ���ǵ���0�Ƿ���
//��ʼλ��0x10��0x01�෴
//2017��11��27�� 15:30:18
//zjb ,3356
//�޸Ķ�ȡ����ֵʱ�Ľ���������ж��Ƿ���IOC�������档
//WriteDID_DI_AllCfgTypeCallback�У����Ӵ��룬��ʾ��ʵ�ִ˹���
//2017��11��29�� 17:04:11
//zjb, 3342
//�޸���ѹ�궨��ʽ����ʹ����ѹģ�鵼���Ĺ�ʽ��
//2017��12��6�� 10:25:02
//zjb,3358
//1:ʹ�õ�����ʽ��ʾ��׼��ѹ������ʹ��������
//2;ʵ�ֹܽű궨����
//3:��������DID_LeftFuel-->DID_LeftFuel_RVal
//4:ʵ����ѹ�͵�Դ�궨����
//2017��12��7�� 16:23:08
//zjb,3358
//�޸ı궨����Bug��ʵ�ֶ�ȡ���йܽŹ���
//2017��12��14�� 14:04:13
//zjb
//�޸��ⷢ���Ĳ���ֵ��ֻ����CAN4 ʱ���Ž����ݷ���ͼ�ΰ�
//2017��12��14�� 15:15:24
//zjb
//�޸�FD23��һϵ��ID�������������ʱ�������⣬U16������ֻ����һ��U8.
//2017��12��14�� 16:45:54
//zjb
//������BCM313�Աȷ��֣��ϴ�U16����U8�������ģ���Ϊ���ʱ�䵥λ��10;ms��
//EEP�з�����2���ֽڣ��������Ҫ��ֻ����һ���ֽڡ��޸�EEPĬ��ֵ���ɡ�
//����ָ�ԭ״��
//2017��12��15�� 10:27:27
//zjb
//�޸���ѹ�궨ʱ��������ѹֵ���Ȳ�һ�µ����⣬���µĵ�ѹ����Ϊ0.001V�궨ʹ�þ���Ϊ0.01V
//2017��12��23�� 09:42:25
//zjb,3519
//1����Ϸ��ص���ֵLAPFuelGetDisplayVal�����У����ع���ǰ��ֵ��������߿�������
//2��DID���������Ա�����DID������������������
//FuelCal-->FuelRValWrite
//FuelDisplayVal-->FuelRValRead
//2017��12��23�� 10:06:50
//FFFF��zjb
//ReadAllDigitalInputCallback�����У�bug�޸ġ�
//��BCM313����һ�£��������������0�������������1
//2018��1��9�� 10:27:34
//FFFF��zjb
//ReadDID_OUT4OutDiagCurrentCallback��Out4����ϵ������ƴ���
//д���˺�Out3һ����
//2018��1��24�� 15:37:34
//zjb
//����Wifi�ȹ�������궨����FuncCal
//2018��5��22�� 18:35:32��
//zjb
//�¼ӱ궨��Ļ�ܽŹ��ܺ���
//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define LAP_RWI   "LAP_RWI"


//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#define cLAP_RWI_SELFINCLUDE

#include "LAP_RWI.h"
#ifdef TOS_PERF_CNT_ENABLE
#include "TOS_PERFCNT.H"
#endif




//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Length of WriteDataByIdentifiers response
#define cLngRepWriteDataByIdentifier                ((U8)3)

#define cDefaultFrequency         ((U32)cPWMPeriodInHzSMRS*100)                // resolution is 0.0001HZ
#define cFrequencyDeviation        ((U32)(cDefaultFrequency*75)/100000)        // +-0.075%
#define cDefaultFrequencyMin    (cDefaultFrequency - cFrequencyDeviation)
#define cDefaultFrequencyMax    (cDefaultFrequency + cFrequencyDeviation)
#define cClockDefaultFreq        (1)//(mSERRead(U32Bit,NVM_RTCClkFreqDefaultValue,Default))    // resolution is 0.01HZ
#define cFrequencyInputCoef     (cClockDefaultFreq/cDefaultFrequency)
#define cAdAccury     			(1024)

#define cVINLength  ((U8)17)
#define cU8DiagDelayTimeMaxValue       (U8)200U // 1bit = 10ms, means 2000ms
//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------
#define mIsValidBCDCode(v)                ((((v) & 0x0F) <= 0x09) && (((v) & 0xF0) <= 0x90))

#define    mChgBCDToASCII(v)                (((((v) & 0xF0) >> 4) * 10) + ((v) & 0x0F))
#define mIsValidYear(Year)                (((Year )>=0)&&((Year )<=9999))
#define mIsValidMonth(Month)            (((Month)>=1)&&((Month)<=12  ))

#define cu16PwrOutUpperLimit            (U16)64255
#define cu8DITypeSetInvalid             0x03
#define cCfgU16OilPrsLowWarningLimit    (U16)1000U



#define cCAN1ComOut   1U
#define cCAN2ComOut   2U
#define cCAN3ComOut   3U
#define cCAN4ComOut   4U
#define mSetCANComOutput(CanName, Byte0, Byte1, Byte2, Byte3, Byte4, Byte5, Byte6, Byte7) \
    mSERWriteMsgBuffer(U8Bit,CanName,0U,Byte0,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,1U,Byte1,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,2U,Byte2,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,3U,Byte3,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,4U,Byte4,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,5U,Byte5,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,6U,Byte6,Default); \
    mSERWriteMsgBuffer(U8Bit,CanName,7U,Byte7,Default);
//------------------------------------------------------------------------------
// Local types
//
// typedef Expression    tTypeName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Data prefix
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
//
// -----------------------------------------------------------------------------
// Local data
//
// static  tType   u8VariableName;  
// static  tType*  pu8VariableName; 
//------------------------------------------------------------------------------
#ifdef cWriteDataByIdentifier_Used
    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
BOOL bWaitEEPROMWriting;
    #endif
#endif
#define cu8DIChannelCnt   57U
#define cPostiveDI        0U
#define cNegDIFor4P5mA    1U
#define cNegDIFor20mA      2U
#define cNegDIFor100mA    3U

#define cU8AirPrsCalSeq     4U
#define cU8AirPrsCalRange   2U

#define cU8BatVolCalSeq     6U
#define cU8BatVolCalRange   2U

#define eCar_Count        6U
#define cu8BrakeLiningWarnMax 100U
#define cu8UserPrefPosSize 4U

/*����оƬ6200��ADת��Ϊ��Ӧ��mA�����ٱ�����߾��ȣ�ת��ϵ��(����ʱʹ��)����ʽ������mA��= (100*AD*300*4763mV)/(1200��*1023),
 *����������ϵ��1/300 1.2K 10λAD AD�ο���ѹ4763mV*/
#define cu16Is6200Ad2MaOver100Ratio ((U16)116U)/*���ݵ�·ת����IS�ܽŻ���ϵ��*/
/*ADת��Ϊ��Ӧ��mV��ѹת��ϵ������ʽ����ѹ��mV��= (100*AD*(15k��+100k��)*4763mV)/(1023*15k��)��
 *������100k--15k 10λAD AD�ο���ѹ4763mV***/
#define cu16Ad2Mv100Ratio ((U16)3570U)

#define cu16Ad2Mv100Ratio12VDec ((10U + 20U) / 10U) * LIBGetADBaseVol() / 1024U / 10U
/*10K,20K��ѹ���裬4763mv��ʾ�ο�Դ*/


typedef struct
{
    U8 u8DIChannel;
    U8 u8DIType;
}stDIList;


static const U8 u8AnaDIPosArray[cu8DIChannelCnt] =
{
    100,    61,    22,    11,    12,    8,    47,    87,    35,    9,
    48,    34,    21,    57,    83,    96,    70,    75,    5,    18,
    31,    30,    17,    4,    43,    69,    95,    82,    56,    94,
    68,    42,    3,    16,    29,    54,    80,    93,    67,    41,
    2,    15,    28,    81,    55,    26,    13,    0,    39,    65,
    91,    27,    14,    1,    40,    66,    92,
};



//����������ֵ����Դ��������ݿ��еĴ������궨��Ŀ
static  const  U16  AirPressureCalTbl[cU8AirPrsCalSeq][cU8AirPrsCalRange] =
{
    //��λ0.001V��35��ʾ0.35V
    {35U ,  65U},
    {135U, 165U},
    {235U, 265U},
    {335U, 365U}
};
static  const  U16  BatVolCalTbl[cU8BatVolCalSeq][cU8BatVolCalRange] =
{
    //��λ0.001V��19100��ʾ19.1V
    {19100U, 20900U},
    {21000U, 23000U},
    {23000U, 25000U},
    {25900U, 28100U},
    {28800U, 31200U},
    {30700U, 33300U}
};
//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
//
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------
//static U8 su8CanComOutChn = 0U;
//------------------------------------------------------------------------------
// Local function prototypes
//
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------



/*
static  U8 ReadAppDataFingerPintCallback(void);
static  U8 ReadAppSoftFingerPrintCallback(void);
static  U8 ReadAppVerCallback(void);
static  U8 ReadCalDataCallback(void);
static  U8 ReadPrdtModelCallback(void);
static  U8 WriteAppDataFingerPintCallback(void);
static  U8 WriteAppSoftFingerPrintCallback(void);
static  U8 WriteECUHWVersionCallback(void);
static  U8 WritePrdtModelCallback(void);
static  U8 WriteECUPartNumberCallback(void);
*/
//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

//QACJ 3218:arozdik: 
//  Unresolvable QaC warning. This constant array is only used in 
//  one function but moving this definition at block scope
//  results in another QaC warning: 3223.
mLAPDiaRDBIandWDBIConstantsInitializaion()

static  U16  NegCtrInputRCalFun(U16 NegCtrGate, U8 NegCtrClass);
static  U16  NegCtrGateCalFun(U16 NegInputR, U8 NegCtrClass);
static  U16  PosCtrInputVolCalFun(U16 PosCtrGate);
static  U16  PosCtrGateCalFun(U16 PosCtrVol);
#if 0
static  U16 SensorValueToADValue(U16 u16SensorValue);
#endif


//�������Ŀǰû��ʹ��
//����д���������ַ�������ǵ���ֵ����λO��Ҳ�����ǵ�ѹֵ����λmV
//bcm313���Խ����Ǳ��Ŀ�������ֵ��ֵ�궨��
static U8 WriteDID_DI_INCfgCallback( void)
{
    U16 u16UpperLimitInput = 0U;
    U16 u16LowerLimitInput = 0U;

    U8  u8UpperLimitH = 0U;
    U8  u8UpperLimitL = 0U;
    U8  u8LowerLimitH = 0U;
    U8  u8LowerLimitL = 0U;

    U8  u8ChIndex = 0U;
    u8ChIndex = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];
    u8UpperLimitH = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos +1U];
    u8UpperLimitL = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos +2U];
    u8LowerLimitH = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos +3U];
    u8LowerLimitL = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos +4U];

    //�����������ֵ
    u16UpperLimitInput  = ((U16)u8UpperLimitH << 8U) + u8UpperLimitL;
    u16LowerLimitInput  = ((U16)u8LowerLimitH << 8U) + u8LowerLimitL;

/*    //�����ж������أ����Ǹ��أ�Ȼ�������Ӧ��DI���ͣ��������Ӧ����ֵ���ѹֵ
    if(cFalse == IsPinCfgEnable(u8ChIndex))
    {
        //����е�ͨ����֧�ּ���򷵻ط���Ӧ
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    else
    {
        if((u8ChIndex >= 1U) && (u8ChIndex <= cU8PinMaxNum))
        {
            if((u16UpperLimitInput <= cU16DICalValueMax) && (u16LowerLimitInput <= cU16DICalValueMax))
            {
                //������ĸ����ܽţ������������ƻ��Ǹ����ƣ�
                if(IsPinPstv(u8ChIndex))
                {
                    //mSERWriteTable(U16Bit, EEP_DIUpperLimit, u8ChIndex - 1U, u16UpperLimitInput, Default);
                }
                else
                {
                    //mSERWriteTable(U16Bit, EEP_DILowerLimit, u8ChIndex - 1U, u16UpperLimitInput, Default);
                }

                if(u16LowerLimitInput != cU16DICalValueMax)
                {
                    if(IsPinPstv(u8ChIndex))
                    {
                        //mSERWriteTable(U16Bit, EEP_DILowerLimit, u8ChIndex - 1U, u16LowerLimitInput, Default);
                    }
                    else
                    {
                        //mSERWriteTable(U16Bit, EEP_DIUpperLimit, u8ChIndex - 1U, u16LowerLimitInput, Default);
                    }

                }
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
        }
        else
        {
            LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
        }
    }*/

    return 0;
}

static U8 ReadDID_EEPVerCallback( void)
{
    U8 u8EEPVer;
    U8 u8EEPRevision;

    u8EEPVer = mSERRead(U8Bit, EEP_EEPROMVersion, Default);
    u8EEPRevision = mSERRead(U8Bit, EEP_EEPROMRevision, Default);

    LAPDiaResponseWriteByte(u8EEPVer);
    LAPDiaResponseWriteByte(u8EEPRevision);

    return 0;
}

static U8 ReadDID_BatVoltageCallback( void)
{
#if 0	//TODO:XXX
    U16 u16ReadValue;
    u16ReadValue = mSERRead(U16Bit, BatVoltage, Default);
    if(u16ReadValue <= 64255)
    {
        LAPDiaResponseWriteByte(u16ReadValue >> 8U);
        LAPDiaResponseWriteByte(u16ReadValue);
    }
    else
    {
        //
    }
#endif
    return 0;
}

static U8 ReadDID_Bat2VoltageCallback( void)
{
#if 0	//TODO:XXX
    U16 u16ReadValue;
    u16ReadValue = mSERRead(U16Bit, Bat2Voltage, Default);
    if(u16ReadValue <= 64255)
    {
        LAPDiaResponseWriteByte(u16ReadValue >> 8U);
        LAPDiaResponseWriteByte(u16ReadValue);
    }
    else
    {
        //
    }
#endif
    return 0;
}

static U8 ReadDID_Bat3VoltageCallback( void)
{
#if 0	//TODO:XXX
    U16 u16ReadValue;
    u16ReadValue = mSERRead(U16Bit, Bat3Voltage, Default);

    if(u16ReadValue <= 64255)
    {
        LAPDiaResponseWriteByte(u16ReadValue >> 8U);
        LAPDiaResponseWriteByte(u16ReadValue);
    }
    else
    {
        //
    }
#endif
    return 0;
}

static U8 ReadDID_PwrOUTStateCallback( void)
{
#if 0	//TODO:XXX
	U8 u8ReadBuf[(cMaxChnIndex / 4U) + 1];		/*ÿ��ͨ��ռ2��bitλ, +1��Ϊ�˷�ֹ������Ϊ0*/
	U8 u8Loop;

	mSERReadStruct(LAPPout, GetOutState, u8ReadBuf, Default);
	for (u8Loop=0; u8Loop<((cMaxChnIndex / 4U) + 1); u8Loop++)
	{
		LAPDiaResponseWriteByte(u8ReadBuf[u8Loop]);
	}
#endif
	return 0;
}

static U8 ReadDID_PwrOUTDiagStateCallback( void)
{
#if 0	//TODO:XXX
	U8 u8ReadBuf[cMaxChnIndex + 1u];
	U8 u8Loop;

	mSERReadStruct(LAPPout, GetOutDiagState, u8ReadBuf, Default);
	for (u8Loop=0; u8Loop<=cMaxChnIndex; u8Loop++)
	{
		LAPDiaResponseWriteByte(u8ReadBuf[u8Loop]);
	}
#endif
	return 0;
}

static U8 ReadDID_DigitalSwStaCallback(void)
{
#if 0	//TODO:XXX
	U8 u8AdSw1;
	U8 u8AdSw2;
	U8 u8AdSw3;
	U8 u8AdSw4;

	U8 u8DinDat;
#define READ_AND_SEND(a,b,c,d)															\
	u8AdSw1 = mSERRead(U1Bit,a,Default);												\
	u8AdSw2 = mSERRead(U1Bit,b,Default);												\
	u8AdSw3 = mSERRead(U1Bit,c,Default);												\
	u8AdSw4 = mSERRead(U1Bit,d,Default);												\
	u8DinDat = (u8AdSw4 << 6u) + (u8AdSw3 << 4u) + (u8AdSw2 << 2u) + (u8AdSw1 << 0u);	\
	LAPDiaResponseWriteByte(u8DinDat);

#define READ_AND_SEND2(a,b)																	\
	u8AdSw1 = mSERRead(U1Bit,a,Default);												\
	u8AdSw2 = mSERRead(U1Bit,b,Default);												\
	u8DinDat = (u8AdSw2 << 2u) + (u8AdSw1 << 0u);										\
	LAPDiaResponseWriteByte(u8DinDat);

//	READ_AND_SEND(ADVAL_IN1, ADVAL_IN2, ADVAL_IN3, ADVAL_IN4);
//	READ_AND_SEND(ADVAL_IN5, ADVAL_IN6, ADVAL_IN7, ADVAL_IN8);
//	READ_AND_SEND(ADVAL_IN9, ADVAL_IN10, ADVAL_IN11, ADVAL_IN12);
//	READ_AND_SEND(ADVAL_IN13, ADVAL_IN14, DI_WakeUp_P, DI_WakeUp_N);
//	READ_AND_SEND(DI_ID0, DI_ID1, DI_ID2, IsBat1Normal);
	READ_AND_SEND2(IsBat2Normal, IsBat3Normal);
#endif
	return 0;
}

static U8 ReadDID_AnalogInputValCallback(void)
{
#if 0	//TODO:XXX
	U16 u16ReadValue = mSERRead(U16Bit, AnaValue, Default);

	LAPDiaResponseWriteByte(u16ReadValue >> 8U);
	LAPDiaResponseWriteByte(u16ReadValue);
#endif
	return 0;
}

static U8 WriteDID_EEPVerCallback( void)
{

    U8 u8DataMaster = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];
    U8 u8DataSlave  = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos + 1] ;

    if(mIsValidBCDCode(u8DataMaster) &&
       mIsValidBCDCode(u8DataSlave )  )
    {
        mSERWrite(U8Bit,EEP_EEPROMVersion, u8DataMaster,  Default );
        mSERWrite(U8Bit,EEP_EEPROMRevision, u8DataSlave,  Default );
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    return 0;

}

// Default AFC for different car variants 0.01L/100KM


//==============================================================================
//=========================== LOCAL FUNCTIONS 0=================================
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#if 0
static U8 LapRwiChgAscToBcd(U8 u8DataAsc)
{
    U8    u8Bcd = 0;

	u8Bcd = ((u8DataAsc / 10U) << 4U) + (u8DataAsc % 10U);

    return(u8Bcd);
}
#endif
//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#if 0
static    BOOL    LapRwiIsGuageKeyPointDegreeValid(U16 u16Default,U16 u16Degree)
{
/*
    BOOL    bReturn;

    if(u16Default >= 500)
    {
        if((u16Degree >= (u16Default - cGaugeKeyPointMaxDeviation))&&(u16Degree <= (u16Default + cGaugeKeyPointMaxDeviation)))
        {
            bReturn = cTrue;
        }
        else
        {
            bReturn = cFalse;
        }
    }
    else
    {
        bReturn = cFalse;
    }
    return(bReturn);
    */
    return cTrue;

}
#endif

//==============================================================================
//=========================== LOCAL FUNCTIONS 1=================================
//==============================================================================

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static void WDBIPositiveResponse( void)
{
    // copy DID
    LAPDiaResponse.Buffer[1] = LAPDiaMemorizedRequest.Buffer[cLAPDiaService + (U8)1];
    LAPDiaResponse.Buffer[2] = LAPDiaMemorizedRequest.Buffer[cLAPDiaService + (U8)2];

    // prepare response
    LAPDiaPreparePositiveResponseSimple(cLngRepWriteDataByIdentifier);
}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : LAPRwiReadDataByIdentifier
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef cReadDataByIdentifier_Used
void LAPRwiReadDataByIdentifier(void)
{
    #if (cLAPDiaLngBufferResponse >0xFFUL)
        U16 DIDPosition;
    #else
        U8  DIDPosition;
    #endif
        BOOL bOverflow;

    #ifndef I_ENV_DIA_H /*UTEST*/
        //mLDBTrace("DIAG : ReadDataByLocalIdentifier");
    #endif

    LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;

    if(0)//cFalse==mSERRead(U1Bit, IsDiagBatNormal , Default))
    {
        LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
    }
    else if(LAPDiaMemorizedRequest.Length == 3)
    {
        DIDPosition = 1;
        LAPDiaResponseBegin();

        do
        {
            U32 DIDIndex;
            U16 DataIdentifier;

            // 3. 读取请求中的DID
            DataIdentifier = LAPDiaMemorizedRequest.Buffer[DIDPosition+1] +
                             ((U16)LAPDiaMemorizedRequest.Buffer[DIDPosition] << 8);

            // copy DID to response复制DID到响应
            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[DIDPosition]);
            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[DIDPosition+1]);

            // find index of DID查找DID索引
            DIDIndex = LAPDiaFindDIDIndex( RDBIDids, DataIdentifier, cLAPDiaRDBIDidsCount);

            if( DIDIndex < (U32)cLAPDiaRDBIDidsCount)
            {
                // check if DID is supported in active session
                //QACJ 0506: arozdik - points to the Value.检查DID是否在当前会话中支持
                if( (pLAPDiaActiveSession->SessionMask & RDBIDidBySession[DIDIndex]) != 0)
                {

                    // call callback function调用DID对应的回调函数
                    RDBIDidCallbacks[DIDIndex]();
                }
                else
                {
                    // not supported in active session当前会话不支持该DID
                    LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
                }
            } 
            else
            {
                //DID不存在
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }

            // next DID移动到下一个DID
            DIDPosition += 2;

            bOverflow = LAPDiaIsResponseLengthOverflow(); 

        } while( (DIDPosition < LAPDiaMemorizedRequest.Length) &&
                 (LAPDiaResponse.NegativeCode == cLAPDiaServiceIsCorrect) &&
                 (bOverflow == cFalse) );


        bOverflow = LAPDiaIsResponseLengthOverflow(); 
        // check for response buffer overflow
        if( (LAPDiaResponse.NegativeCode == cLAPDiaServiceIsCorrect) &&
            (bOverflow != cFalse) )
        {
            LAPDiaResponse.NegativeCode = cLAPDiaResponseTooLong;
        }
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
    }

    if( LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
    {
        LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
    }
    else
    {
        LAPDiaPreparePositiveResponse( LAPDiaResponse.Length);
    }
}
#endif //cReadDataByIdentifier_Used

//==============================================================================
// DESCRIPTION : LAPRwiWriteDataByIdentifier
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#ifdef cWriteDataByIdentifier_Used
void LAPRwiWriteDataByIdentifier(void)
{
    #if (cLAPDiaLngBufferResponse >0xFFUL)
        U16 DIDPosition;
    #else
        U8  DIDPosition;
    #endif

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cFalse;
    #endif

    #ifndef I_ENV_DIA_H /*UTEST*/
        mLDBTrace("DIAG : WriteDataByIdentifier");
    #endif

    LAPDiaResponseBegin();

    if(LAPDiaIsPhysicalAddress() == cFalse)
    {
        LAPDiaResponse.NegativeCode = cLAPDiaServiceNotSupported;
        LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
    }
    else if(0) //(mSERRead(U1Bit, AD_IGOn, Default) == cFalse)
    {
        LAPDiaResponse.NegativeCode = cLAPDiaConditionsNotCorrect;
        LAPDiaPrepareNegativeResponse( LAPDiaResponse.NegativeCode);
    }
    else
    {
        // By default, we define :
        LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;

        if (LAPDiaActiveService.Step == cLAPDiaStartOfService)
        {
            // check minimum request length
            if( LAPDiaMemorizedRequest.Length > 2)
            {
                U32 DIDIndex;
                U16 DataIdentifier;

                DIDPosition = 1;

                DataIdentifier = LAPDiaMemorizedRequest.Buffer[2] +
                                 ((U16)LAPDiaMemorizedRequest.Buffer[1] << 8);

                // find index of DID
                DIDIndex = LAPDiaFindDIDIndex( WDBIDids, DataIdentifier, cLAPDiaWDBIDidsCount);

                if( DIDIndex < (U32)cLAPDiaWDBIDidsCount)
                {
                    // check if DID is supported in active session
                    //QACJ 0506: arozdik - points to the Value.
                    if( (pLAPDiaActiveSession->SessionMask & WDBIDidBySession[DIDIndex]) != 0)
                    {
                        // check if length of request is correct (if needed)
                        if( (WDBIDidReqLength[DIDIndex] == 0) ||
                            (LAPDiaMemorizedRequest.Length == WDBIDidReqLength[DIDIndex]) )
                        {
                            // default response - Correct
                            LAPDiaResponse.NegativeCode = cLAPDiaServiceIsCorrect;

                            // call callback function
                            WDBIDidCallbacks[DIDIndex]();

                            // copy DID to response
                            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[DIDPosition]);
                            LAPDiaResponseWriteByte( LAPDiaMemorizedRequest.Buffer[DIDPosition+1]);

                        }
                        else
                        {
                            // invalid message length
                            LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
                        }
                    }
                    else
                    {
                        // not supported in active session
                        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
                    }
                }
                else
                {
                    LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
                }
            }
            else
            {
                // invalid message length
                LAPDiaResponse.NegativeCode = cLAPDiaIncorrectMessageLengthOrInvalidFormat;
            }

            if (LAPDiaResponse.NegativeCode != cLAPDiaServiceIsCorrect)
            {
                LAPDiaPrepareNegativeResponse(LAPDiaResponse.NegativeCode);

                #ifndef I_ENV_DIA_H /*UTEST*/
                  //  mLDBTrace("DIAG : wrong message : cLAPDiaInvalidFormat error generated");
                #endif
            }
            else //if (LAPDiaResponse.NegativeCode == cLAPDiaServiceIsCorrect)
            {
                #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
                if (bWaitEEPROMWriting == cTrue)
                {
                    //Waiting for the end of EEPROM access, the graph will re launch the treatement
                    LAPDiaActiveService.Step = cLAPDiaFirstStep;
                }
                else
                #endif
                {
                    WDBIPositiveResponse();
                }
            }
        }
        else // if (LAPDiaActiveService.Step != cLAPDiaStartOfService)
        {
            #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
            //Other request treatments called by the graph
            if(mSERRead(U1Bit, IsEepProcessing, Default) == cFalse)
            {
                WDBIPositiveResponse();
            }
            else
            {
                //  waiting for the end of EEPROM access
            }
            #endif
        }
    }
}
#endif //cWriteDataByIdentifier_Used




//==============================================================================
// DESCRIPTION : LAPRwiOpenSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPRwiOpenSession (void)
{
    //Example on a session except default session
    //if (LAPDiaActiveSession.SessionIdentifier != cLAPDiaIdDefaultSession)
    //{
    //}
}




//==============================================================================
// DESCRIPTION : LAPRwiCloseSession
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LAPRwiCloseSession (void)
{
    //Example on a session except default session
    //if (LAPDiaActiveSession.SessionIdentifier != cLAPDiaIdDefaultSession)
    //{
    //}
}

//==============================================================================
// DESCRIPTION : ECUPartNumber
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUPartNumberCallback(void)
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0; u8Loop < cU8ECUPartNumberDataLength; u8Loop++)
    {
        u8ReadValue = mSERReadTable(U8Bit, EEP_ECUPartNumber, u8Loop, Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
//==============================================================================
// DESCRIPTION : SystemSupplierID
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadSystemSupplierIDCallback(void)
{
    U8 u8ReadValue = 0U;
    U8 u8Loop = 0U;

    for(u8Loop = 0U; u8Loop < 5U; u8Loop++)
    {
        u8ReadValue=mSERReadTable(U8Bit, EEP_SystemSupplierID, u8Loop , Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
//==============================================================================
// DESCRIPTION : ECUManufacturingDate
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUManufacturingDateCallback(void)
{
    U8 u8ReadValue = 0U;
    U8 u8Loop = 0U;

    for(u8Loop = 0;u8Loop < cU8ECUManufacturingDateLength;u8Loop++)
    {
        u8ReadValue = mSERReadTable(U8Bit, EEP_ECUManufacturingDate, u8Loop , Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
//==============================================================================
// DESCRIPTION : ECUSerialNumber
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUSerialNumberCallback(void)
{
    U8 u8ReadValue = 0U;
    U8 u8Loop = 0U ;

    for(u8Loop = 0;u8Loop < cU8ECUSerialNumberLegnth;u8Loop++)
    {
        u8ReadValue=mSERReadTable(U8Bit, EEP_ECUSerialNumber, u8Loop , Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}

//==============================================================================
// DESCRIPTION : System Name
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
#if 0
static U8 ReadSystemNameCallback(void)
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < sizeof(cau8SystemName); u8Loop++)
    {
        u8ReadValue=cau8SystemName[u8Loop];
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : VIN
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadVINCallback(void)
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0U; u8Loop < cVINLength; u8Loop++)
    {
        u8ReadValue = mSERReadTable(U8Bit, EEP_VINCode, u8Loop, Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0U;
}
//==============================================================================
// DESCRIPTION : WriteVINCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 WriteVINCallback(void)
{
    U8 u8WriteValue;
    U8 u8Loop;

    for(u8Loop = 0U; u8Loop < cVINLength;u8Loop++)
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
        mSERWriteTable(U8Bit, EEP_VINCode,u8Loop, u8WriteValue, Default);
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
#if 0
//==============================================================================
// DESCRIPTION : ReadECUHWNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUHWNumberCallback(void)
{
    U8 u8ReadValue;
    U8 u8Loop;

    //because the ECUHWNumber=0XF192 has different length in different session ID.
    //so you have to check current session ID first.

    for(u8Loop = 0;u8Loop < 7;u8Loop++)
    {
        //u8ReadValue=mSERReadTable(U8Bit, NVM_SystemSupplierECUHardwareNumber, u8Loop,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    if (LAPDiaGetActiveSession() == cLAPDiaIdJCISession)
    {
        //u8ReadValue=mSERRead(U8Bit, NVM_HWVersion,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }
    else
    {
        //do nothing
    }


    return 0;
}
//==============================================================================
// DESCRIPTION : WriteECUHWNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 WriteECUHWNumberCallback(void)
{
    //U8 u8WriteValue;
    U8 u8Loop;

    //because the ECUHWNumber=0XF192 has different length in different session ID.
    //so you have to check current session ID first.
    if (LAPDiaGetActiveSession() == cLAPDiaIdJCISession)
    {
        for(u8Loop = 0;u8Loop < 7;u8Loop++)
        {
            //u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        //    mSERWriteTable(U8Bit, NVM_SystemSupplierECUHardwareNumber, u8Loop, u8WriteValue, Default);
        }
        //u8WriteValue=LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        //mSERWrite(U8Bit, NVM_HWVersion,u8WriteValue , Default);

        #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
        bWaitEEPROMWriting = cTrue;
        #endif
    }
    else
    {
        //error
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : ECUHWVersion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUHWVersionCallback(void)
{
    U8    u8Loop = 0U;
    U8    u8ReadValue = 0U;

    for(u8Loop = 0U; u8Loop < cU8ECUHWVersionDataLength; u8Loop ++)
    {
        u8ReadValue = mSERReadTable(U8Bit, EEP_HWVersion, u8Loop, Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}

#if 0
//==============================================================================
// DESCRIPTION : ECUSWVersion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static U8 ReadECUSWVersionCallback(void)
{
#if !defined(COMPILATION_NATIVE)
	//cLIBBooBootLoaderVersionAddress(0xDF201CUL) is defined in MAPPING.txt
	//and Bootloader project's START_L.ASM. The real Bootloader version is defined
	//in Bootloader project's LIB_VER.h
	U8 u8BootVerH= *(((U8 *)cLIBBooBootLoaderVersionAddress));
	U8 u8BootVerL= *(((U8 *)cLIBBooBootLoaderVersionAddress)+1);
#else
	U8 u8BootVerH = 0;
	U8 u8BootVerL = 0;
#endif

	LAPDiaResponseWriteByte(cSw_Version_BCD);
	LAPDiaResponseWriteByte(cSw_Revision_BCD);
	LAPDiaResponseWriteByte((u8BootVerH));
	LAPDiaResponseWriteByte((u8BootVerL));
	return 0;
}
#endif
//==============================================================================
// DESCRIPTION : WriteProductReferenceAndReversionCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 WriteProductReferenceAndReversionCallback( void )
{
//Total 11Bytes:1SID+2DID+Data(8)
//8 Bytes ASCII

    //U8 u8WriteValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 8;u8Loop++)
    {
        //u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        //mSERWriteTable(U8Bit, NVM_JCIProductReferenceAndRevision, u8Loop, u8WriteValue, Default);
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : ReadProductReferenceAndReversionCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadProductReferenceAndReversionCallback( void )
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 8;u8Loop++)
    {
        //u8ReadValue = mSERReadTable(U8Bit, NVM_JCIProductReferenceAndRevision, u8Loop ,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}

#endif
//==============================================================================
// DESCRIPTION : PCBAReferenceAndReversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       

#if 0
static U8 WritePCBAReferenceAndReversionWithSwNVMCallback( void )
{
//Total 12Bytes:1SID+2DID+Data(9)
//9 Bytes ASCII

    //U8 u8WriteValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 9;u8Loop++)
    {
        //u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        //NVM_PCBAReferenceAndRevisionWithSwE2P, the E2P should be NVM in N330.
        //mSERWriteTable(U8Bit, NVM_PCBAReferenceAndRevisionWithSwE2P, u8Loop, u8WriteValue, Default);
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : PCBAReferenceAndReversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadPCBAReferenceAndReversionWithSwNVMCallback( void )
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 9;u8Loop++)
    {
        //NVM_PCBAReferenceAndRevisionWithSwE2P, the E2P should be NVM in N330.
        //u8ReadValue = mSERReadTable(U8Bit, NVM_PCBAReferenceAndRevisionWithSwE2P, u8Loop ,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }
    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : WritePCBASerialNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 WritePCBASerialNumberCallback( void )
{
    //Total 12Bytes:1SID+2DID+Data(4)
    //4 Bytes BCD

    U8        u8WriteValue;
    U8        u8Loop;
    BOOL    bDataValid;

    //if !BCD code,NRC = Request out of range,see SMRS

    bDataValid = cTrue;

    for(u8Loop = 0;u8Loop < 4;u8Loop++)
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        if(mIsValidBCDCode(u8WriteValue))
        {
            //no statement
        }
        else
        {
            bDataValid = cFalse;
            break;
        }
    }

    if(bDataValid)
    {
        for(u8Loop = 0;u8Loop < 4;u8Loop++)
        {
            u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
            //mSERWriteTable(U8Bit, NVM_PCBASerialNumber, u8Loop, u8WriteValue, Default);
        }

        #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
        bWaitEEPROMWriting = cTrue;
        #endif
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : ReadPCBASerialNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadPCBASerialNumberCallback( void )
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 4;u8Loop++)
    {
        //u8ReadValue = mSERReadTable(U8Bit, NVM_PCBASerialNumber, u8Loop ,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }
    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : EEPAndSWVersionAndReversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadEEPAndSWAndBootloaderVersionReversionCallback( void )
{
    U8    u8NVMVersion = 0;
    U8    u8NVMRevision = 0;
    U8    u8BCD;
#if !defined(COMPILATION_NATIVE)
    //cLIBBooBootLoaderVersionAddress(0xDF201CUL) is defined in MAPPING.txt
    //and Bootloader project's START_L.ASM. The real Bootloader version is defined
    //in Bootloader project's LIB_VER.h
    U8 u8BootVerH= *(((U8 *)cLIBBooBootLoaderVersionAddress));
    U8 u8BootVerL= *(((U8 *)cLIBBooBootLoaderVersionAddress)+1);
#else
    U8 u8BootVerH = 0;
    U8 u8BootVerL = 0;
#endif


    //u8NVMVersion  = mSERRead(U8Bit, NVM_NVMVersion, Default);
    //u8NVMRevision = mSERRead(U8Bit, NVM_NVMRevision, Default);

    u8BCD = LapRwiChgAscToBcd(u8NVMVersion);
    LAPDiaResponseWriteByte(u8BCD);

    u8BCD = LapRwiChgAscToBcd(u8NVMRevision);
    LAPDiaResponseWriteByte(u8BCD);

    LAPDiaResponseWriteByte(cSw_Version_BCD);
    LAPDiaResponseWriteByte(cSw_Revision_BCD);

    LAPDiaResponseWriteByte(u8BootVerH);
    LAPDiaResponseWriteByte(u8BootVerL);

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : SMDManufacturingDate
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadSMDManufacturingDateCallback( void )
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 4;u8Loop++)
    {
        //u8ReadValue = mSERReadTable(U8Bit, NVM_SMDManufacturingDate, u8Loop ,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
static	BOOL	DATTRC_IsLeapYear(U16 u16Year)
{
	BOOL	bReturn;

	if(0U == (u16Year & 0x03U)) // can be divided by 4
	{
		if(0U == (u16Year % 100U)) // can be divided by 100
		{
			if(0U == (u16Year % 400U))
			{
				bReturn = cTrue;
			}
			else
			{
				bReturn = cFalse;
			}
		}
		else
		{
			bReturn = cTrue;
		}
	}
	else //can not be divided by 4
	{
		bReturn = cFalse; //nonleap year
	}

	return(bReturn);
}

//==============================================================================
// DESCRIPTION :
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
U8	DATTRC_GetMaxValidDay(U16 u16Year,U8 u8Month)
{
#if 1
	U8	u8Return;

	switch(u8Month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			u8Return = 31U;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			u8Return = 30U;
			break;
		case 2:
			if(DATTRC_IsLeapYear(u16Year))
			{
				u8Return = 29U;
			}
			else
			{
				u8Return = 28U;
			}
			break;
		default: // para error
			u8Return = 0x00U;
			break;
	}
#endif
	return(u8Return);
}

//==============================================================================
// DESCRIPTION : ECUManufacturingDate
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 WriteECUManufacturingDateCallback( void )
{
	U16		u16Year = 0U;
	U8		u8Year_H = 0U;
	U8		u8Year_L = 0U;
	U8		u8Month = 0U;
	U8		u8Day = 0U;
	U8      u8Hour = 0U;
	U8      u8Minite = 0U;

	U8		u8WriteValue = 0U;
	U8		u8Loop = 0U;
	BOOL	bDataValid = cTrue;

	for(u8Loop = 0U;u8Loop < cU8ECUManufacturingDateLength;u8Loop++)
	{
		u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
		if(mIsValidBCDCode(u8WriteValue))
		{
			//no statement
		}
		else
		{
			bDataValid = cFalse;
			break;
		}
	}

	if(bDataValid)
	{
		u8Minite = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[8U]);
		u8Hour = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[7U]);
		u8Day   = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[6U]);
		u8Month = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[5U]);
		u8Year_L = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[4U]);
		u8Year_H = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[3U]);

		u16Year  = u8Year_H * 100U + u8Year_L;

		if(((u16Year >= 2016U)&&(u16Year <= 9999U)) &&
		   ((u8Day > 0U)&&(u8Day <= DATTRC_GetMaxValidDay(u16Year,u8Month))) &&
		   (u8Hour < 24U) &&
		   (u8Minite < 60U))
		{
			for(u8Loop = 0U; u8Loop < cU8ECUManufacturingDateLength; u8Loop++)
			{
				u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
				mSERWriteTable(U8Bit, EEP_ECUManufacturingDate, u8Loop, u8WriteValue, Default);
			}
			/*
			#if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)  //�ж�EEP�����Ƿ�ʹ��?banfy
			bWaitEEPROMWriting = cTrue;
			#endif
			*/
		}
		else
		{
			LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
		}
	}
	else
	{
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}

	return 0;
}
//==============================================================================
// DESCRIPTION : SMDPlantNumber
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 WriteSystemSupplierIDCallback( void )
{
//Total 6Bytes:1SID+2DID+Data(3)
//BCD type
    U8    u8WriteValue = 0U;
    U8    u8Loop = 0U;
    BOOL  bDataValid = cTrue;

    for(u8Loop = 0U;u8Loop < cU8SystemSupplierIDLength;u8Loop++)
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
        if(mIsValidBCDCode(u8WriteValue))
        {
            //no statement
        }
        else
        {
            bDataValid = cFalse;
            break;
        }
    }

    if(bDataValid)
    {
        for(u8Loop = 0U; u8Loop < cU8SystemSupplierIDLength; u8Loop++)
        {
            u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
            mSERWriteTable(U8Bit, EEP_SystemSupplierID, u8Loop, u8WriteValue, Default);
        }
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
//==============================================================================
// DESCRIPTION : ReadSMDPlantNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadSMDPlantNumberCallback( void )
{
    U8 u8ReadValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 3;u8Loop++)
    {
        //u8ReadValue = mSERReadTable(U8Bit, NVM_SMDPlantNumber, u8Loop ,Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : WriteSMDPlantNumberCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
#if 0
static U8 WriteSMDPlantNumberCallback( void )
{
    U8 u8WriteValue;
    U8 u8Loop;

    for(u8Loop = 0;u8Loop < 3;u8Loop++)
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        if(mIsValidBCDCode(u8WriteValue))
        {
            // nothing...
        }
        else
        {
            LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            break;
        }
    }

    if(cLAPDiaServiceIsCorrect == LAPDiaResponse.NegativeCode)
    {
        for(u8Loop = 0;u8Loop < 3;u8Loop++)
        {
            u8WriteValue = LAPDiaMemorizedRequest.Buffer[3+u8Loop];
        //    mSERWriteTable(U8Bit, NVM_SMDPlantNumber, u8Loop, u8WriteValue, Default);
        }

        #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
        bWaitEEPROMWriting = cTrue;
        #endif
    }

    return 0;
}
#endif


/*
 *�������������㺯��
 *NegCtrGate : AD��ֵ
 *NegCtrClass�� �������� 0:4.5mA 1:20mA 2:100mA
 *4.5mA: ((9120 - 700)/(2000 + Rinput))*Rinput x(15/(100 + 15))/(4760 / 1024) = AdGate
 *20mA:  (24000*Rinput + 840)/(1200 + Rinput)x(15/(100 + 15))/(4760 / 1024) = AdGate
 *100mA: ((24000 - 700)/(220 + Rinput))*Rinput x(15/(100 + 15))/(4760 / 1024) = AdGate
 */
static U16 NegCtrInputRCalFun(U16 NegCtrGate, U8 NegCtrClass)
{
    U32 NegCtrR = 0U;
    switch(NegCtrClass)
    {
    case 0U:
        if(NegCtrGate > 218U)
        {
            NegCtrR = 64255U;
        }
        else
        {
            //NegCtrR = (U32)(23U * 500U * 2000U) *(U32)NegCtrGate /(3U * 1024U * 842U - 23U * 500U * (U32)NegCtrGate);
            NegCtrR = (uint64_t)((uint64_t)NegCtrGate * 23000000U) / (uint64_t)(2586624U - (uint64_t)NegCtrGate * 11500U);
        }
        break;
    case 1U:
        if(0U == NegCtrGate)
        {
            NegCtrR = 0U;
        }
        else if(NegCtrGate > 629U)
        {
            NegCtrR = 64255U;
        }
        else
        {
            //NegCtrR = (uint64_t)((23U * 500U * 1200U) * (uint64_t)NegCtrGate - 3U * 1024U * 2400U) /(3U * 1024U * 2400U - 23U * 500U * (U32)NegCtrGate);
            //NegCtrR = (uint64_t)((uint64_t)NegCtrGate * 138000U - 73728U) / (uint64_t)(73728U - (uint64_t)NegCtrGate * 115U);
            NegCtrR = ((U32)NegCtrGate * 138000U - 73728U) / (73728U - (U32)NegCtrGate * 115U);
        }
        break;
    case 2U:
        if(NegCtrGate > 620U)
        {
            NegCtrR = 64255U;
        }
        else
        {
            //NegCtrR = (U32)(23U * 500U * 220U) * (U32)NegCtrGate /(3U * 1024U * 2330U - 23U * 500U * (U32)NegCtrGate);
            //NegCtrR = (uint64_t)(2530000U) * (uint64_t)NegCtrGate / (uint64_t)(7157760U - 11500U * (uint64_t)NegCtrGate);
            NegCtrR = 2530000U * (U32)NegCtrGate / (7157760U - 11500U * (U32)NegCtrGate);
        }
        break;
    default:
        break;
    }
    return (U16)NegCtrR;
}
/*
 *������ֵ����
 */
static  U16  NegCtrGateCalFun(U16 NegInputR, U8 NegCtrClass)
{
    U32 NegCtrGate = 0U;

    switch(NegCtrClass)
    {
    case 0U:
        NegCtrGate = (uint64_t)(2586624U *((uint64_t)NegInputR)) / (uint64_t)(11500U * (2000U + ((uint64_t)NegInputR)) );
        break;
    case 1U:
        NegCtrGate = (uint64_t)(73728U * ((uint64_t)NegInputR + 1U)) / (138000U + (uint64_t)NegInputR * 115U);
        break;
    case 2U:
        NegCtrGate = (uint64_t)(7157760U * ((uint64_t)NegInputR)) / (2530000U + 11500U * (uint64_t)NegInputR);
        break;
    default:
        break;
    }
    return (U16)NegCtrGate;
}
/*
 * ���������ѹ���㺯��
 */
static  U16  PosCtrInputVolCalFun(U16 PosCtrGate)
{
    U32 PosCtrVol = 0U;

    PosCtrVol = (U32)(23U * LIBGetADBaseVol() * ((U32)PosCtrGate)) / (1024U * 3U);
    return (U16)PosCtrVol;
}

/*
 * ����������ֵ���㺯��
 */
static  U16 PosCtrGateCalFun(U16 PosCtrVol)
{
    U32 PosCtrGate = 0U;

    PosCtrGate = (U32)(1024U * 3U * ((U32)PosCtrVol))/(23U * LIBGetADBaseVol());
    return (U16)PosCtrGate;
}
//==============================================================================
// DESCRIPTION : SpeedRatio/VehicleManufacturerSparePartNumber
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 WriteSpeedRatioCallback( void )
{

    U16 u16SpeedRatio = 0;
    U16 u16High = 0;
    U16 u16Low = 0;

    u16High = (U16)(LAPDiaMemorizedRequest.Buffer[3]);
    u16Low  = (U16)(LAPDiaMemorizedRequest.Buffer[4]);
    u16SpeedRatio = (u16High<<8U) + u16Low;

    if(u16SpeedRatio <= cCfgU16SpeedRatioLimit)
    {
       // mSERWrite(U16Bit, EEP_SpeedRatio, u16SpeedRatio, Default);
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}

//==============================================================================
// DESCRIPTION : AllDigitalInput��ǰ��ȡ��ֵΪ����ͨ���Ĳ���ֵ��ADֵ�����ٽ���ת��Ϊ������裨ŷ�����ѹ��mV����
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 ReadAllDigitalInputCallback( void )
{
    U8  u8Loop        = 0U;
    U8  u8DIType      = 0U;
    U8  u8RetType = 0U;
    U16 u16CurADVal  = 0U;
    U16 u16RetVal = 0U;
    U8  u8ADIndex = 0U;


    for(u8Loop = 0U; u8Loop < cu8DIChannelCnt; u8Loop ++)
    {
        //�ر�ע�⣺���������Ǵ�1��ʼ��
        //u8DIType = GetPinType(u8Loop + 1U);

        //rem ��ΪADIndex����VBA�Զ����ɵģ����Ա�֤��ֵ��������AD����
        //u8ADIndex = GetADIndex(u8Loop + 1U);

        //�������u8Loop��Ϊ�����������ͨ������ֵ
        //u16CurADVal = mSERReadTable(U16Bit, GetDIValue, u8ADIndex, Default);

        //2017��12��23�� 10:06:50
        //FFFF��zjb
        //�����BCM313����һ�£��������������0�������������1
//        if(IsPinPstv(u8Loop + 1U))
//        {
//            u16RetVal = PstvCtrlVoltVal(u16CurADVal);
//            u8RetType = 1U;
//        }
//        else
//        {
//            u16RetVal = NegCtrRVal(u16CurADVal, u8DIType);
//            u8RetType = 0U;
//        }

        LAPDiaResponseWriteByte(u8RetType );
        LAPDiaResponseWriteByte(u16RetVal >> 8U);
        LAPDiaResponseWriteByte((U8)u16RetVal );
    }

    return 0;
}

//==============================================================================
// DESCRIPTION : LcdVop
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 ReadSWTestDataGroupCallback( void )
{
#if 0
    U32 u32V;
    U16 u16V;
    U8  u8V;
    // ---------------[ Odo ]
    //u32V = mSERRead(U32Bit,     NVM_OdoTotal, Default);
    LAPDiaResponseWriteByte((U8)(u32V >>24));
    LAPDiaResponseWriteByte((U8)(u32V >>16));
    LAPDiaResponseWriteByte((U8)(u32V >> 8));
    LAPDiaResponseWriteByte((U8)(u32V));

    //u16V  = mSERRead(U16Bit,     NVM_OdoTotal_PluseEdgeNum, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V  = mSERRead(U16Bit,     NVM_OdoTrip, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V  = mSERRead(U16Bit,     NVM_OdoTrip_PluseEdgeNum, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    // ----------------- [ AFC ]
    //u16V  = mSERRead(U16Bit,     NVM_AFC_Exp, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V  = mSERRead(U16Bit,     NVM_AFC_Disp, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V  = mSERRead(U16Bit,     NVM_AFC_ExpCoef, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V  = mSERRead(U16Bit,     NVM_AFC_ExpCoefDelta, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u32V  = mSERRead(U32Bit,     NVM_AFC_Calc_Odo, Default);
    LAPDiaResponseWriteByte((U8)(u32V >>24));
    LAPDiaResponseWriteByte((U8)(u32V >>16));
    LAPDiaResponseWriteByte((U8)(u32V >> 8));
    LAPDiaResponseWriteByte((U8)(u32V));

    //u32V  = mSERRead(U32Bit,     NVM_AFC_Calc_Ifv, Default);
    LAPDiaResponseWriteByte((U8)(u32V >>24));
    LAPDiaResponseWriteByte((U8)(u32V >>16));
    LAPDiaResponseWriteByte((U8)(u32V >> 8));
    LAPDiaResponseWriteByte((U8)(u32V));

    // ----------------- [ DTE ]
    //u16V  = mSERRead(U16Bit,     NVM_DTE_Para_AFC, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    // ---------------- [ LCD ]
    //u16V  = mSERRead(U16Bit, NVM_LCD_BarCode_VLcd, Default);
    LAPDiaResponseWriteByte((U8)(u16V >> 8));
    LAPDiaResponseWriteByte((U8)(u16V));

    u16V = mSERRead(U16Bit, MtxLcdTempAdc, Default);
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    u16V = mSERRead(U16Bit , MtxLcdTempPhysical, Default);
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    // ----------------[ AI ]
    //u16V = mSERRead(U16Bit,AI_BacklightLevel,Default);
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    //u16V = mSERRead(U16Bit, AI_BatSupply, Default);
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    u16V = mSERRead(U16Bit,BacklightResistance,Default); //1ohm
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    u16V = mSERRead(U16Bit , BatVoltage, Default); //0.01 v
    LAPDiaResponseWriteByte((U8)(u16V>>8));
    LAPDiaResponseWriteByte((U8)(u16V));

    // Gauge Key Point
    ReadAllADValueCallback_Internal();
    ReadFuelLevelConversionCallback_Internal();
    ReadSpeedMeterConversionCallback_Internal();
    ReadTachoMeterConversionCallback_Internal();

    // Reset Times
    //u8V = mSERRead(U8Bit , NVM_ResetTimes_Total, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_ResetTimes_PwrExt, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_ResetTimes_WatchDog, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_ResetTimes_SWReset, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_ResetTimes_CLK, Default);
    LAPDiaResponseWriteByte(u8V);

    // HMI
    //u8V = mSERRead(U8Bit , NVM_Odo_Reset_Counter, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_Odo_Reset_Max, Default);
    LAPDiaResponseWriteByte(u8V);

    // Diag
    //u8V = mSERRead(U8Bit , NVM_SecurityAccessTimes, Default);
    LAPDiaResponseWriteByte(u8V);

    // GroupFuel
   //u8V = mSERRead(U8Bit , NVM_FuelWeakDampTime, Default);
    LAPDiaResponseWriteByte(u8V);

    //u8V = mSERRead(U8Bit , NVM_FuelStrongDampTime, Default);
    LAPDiaResponseWriteByte(u8V);
#endif
    return 0;

}
//==============================================================================
// DESCRIPTION : LcdVop
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
static U8 WriteSWTestDataGroupCallback(void)
{
#if 0
    U16 u16SubId =  (LAPDiaMemorizedRequest.Buffer[3]<<8) + (LAPDiaMemorizedRequest.Buffer[4]);

    switch(u16SubId)
    {
        case 0x0000:
            if(15 == LAPDiaMemorizedRequest.Length)
            {
                U16 u16V;
                U32 u32V;
                u32V=     ((U32)LAPDiaMemorizedRequest.Buffer[5]<<24) + ((U32)LAPDiaMemorizedRequest.Buffer[6]<<16)
                        + ((U32)LAPDiaMemorizedRequest.Buffer[7]<<8) + ((U32)LAPDiaMemorizedRequest.Buffer[8]);
                mSERWrite(U32Bit, XCP_OdoTotal, u32V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[9]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[10]);
                mSERWrite(U16Bit, XCP_OdoTotal_PluseEdgeNum, u16V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[11]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[12]);
                mSERWrite(U16Bit, XCP_OdoTrip, u16V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[13]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[14]);
                mSERWrite(U16Bit, XCP_OdoTrip_PluseEdgeNum, u16V,Default);
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0001:
            if(21 == LAPDiaMemorizedRequest.Length)
            {
                U16 u16V;
                U32 u32V;
                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[5]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[6]);
                //mSERWrite(U16Bit, NVM_AFC_Exp, u16V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[7]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[8]);
                //mSERWrite(U16Bit, NVM_AFC_Disp, u16V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[9]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[10]);
                //mSERWrite(U16Bit, XCP_AFC_ExpCoef, u16V,Default);

                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[11]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[12]);
                //mSERWrite(U16Bit, NVM_AFC_ExpCoefDelta, u16V,Default);

                u32V=     ((U32)LAPDiaMemorizedRequest.Buffer[13]<<24) + ((U32)LAPDiaMemorizedRequest.Buffer[14]<<16)
                        + ((U32)LAPDiaMemorizedRequest.Buffer[15]<<8) + ((U32)LAPDiaMemorizedRequest.Buffer[16]);
                //mSERWrite(U32Bit, XCP_AFC_Calc_Odo, u32V,Default);

                u32V=     ((U32)LAPDiaMemorizedRequest.Buffer[17]<<24) + ((U32)LAPDiaMemorizedRequest.Buffer[18]<<16)
                        + ((U32)LAPDiaMemorizedRequest.Buffer[19]<<8) + ((U32)LAPDiaMemorizedRequest.Buffer[20]);
                //mSERWrite(U32Bit, XCP_AFC_Calc_Ifv, u32V,Default);
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0002:
            if(7 == LAPDiaMemorizedRequest.Length)
            {
                U16 u16V;
                u16V = ((U16)LAPDiaMemorizedRequest.Buffer[5]<<8) + ((U16)LAPDiaMemorizedRequest.Buffer[6]);
                mSERWrite(U16Bit, XCP_DTE_Para_AFC, u16V,Default);
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0003:
            if(7 == LAPDiaMemorizedRequest.Length)
            {
                U16 u16VLcd = (LAPDiaMemorizedRequest.Buffer[5]<<8) + (LAPDiaMemorizedRequest.Buffer[6]);
            //    mSERWrite(U16Bit, NVM_LCD_BarCode_VLcd, u16VLcd,Default);
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0004:
            if(17 == LAPDiaMemorizedRequest.Length)
            {
            //    WriteAllADValueCallback_Internal();
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0005:
            if(17 == LAPDiaMemorizedRequest.Length)
            {
                //WriteFuelLevelConversionCallback_Internal();
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0006:
            if(15 == LAPDiaMemorizedRequest.Length)
            {
                WriteSpeedMeterConversionCallback_Internal();
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        case 0x0007:
            if(15 == LAPDiaMemorizedRequest.Length)
            {
                WriteTachoMeterConversionCallback_Internal();
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;

        case 0x0008:
            if(7 == LAPDiaMemorizedRequest.Length)
            {
                U8 u8V;
                u8V=   LAPDiaMemorizedRequest.Buffer[5];
            //    mSERWrite(U8Bit , NVM_FuelWeakDampTime, u8V ,Default);

                u8V=   LAPDiaMemorizedRequest.Buffer[6];
            //    mSERWrite(U8Bit , NVM_FuelStrongDampTime, u8V ,Default);
            }
            else
            {
                LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            }
            break;
        default:
            LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
            break;
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    if(cLAPDiaServiceIsCorrect == LAPDiaResponse.NegativeCode)
    {
        bWaitEEPROMWriting = cTrue;
    }
    #endif

#endif
    return 0;
}

//==============================================================================
// DESCRIPTION : AllADValue
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
#if 0
static U8 ReadAllADValueCallback( void )
{
    U8      u8Loop;
    U16     u16ADValue = (U16)0U;


    for(u8Loop = 0;u8Loop < 72;u8Loop++)
    {
        //����Ҫ�ȴ��°������ˣ���ȡ��Ч����
        //u16ADValue = mSERReadBuffer(ADDataByNum, u8Loop,Default);
        u16ADValue = u8Loop;
        //u16Degree[u8Loop] = u8Loop*256+u8Loop;
        LAPDiaResponseWriteByte((U8)(u16ADValue>>8));
        LAPDiaResponseWriteByte((U8)(u16ADValue));
    }

    return 0;

}
#endif
//==============================================================================
// DESCRIPTION : FuelLevelConversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
#if 0
static U8 WriteFuelLevelConversionCallback( void )
{
/*
Calibration point    Default value(1 means 0.01?
Electronic Zero        500
Warning                3000
F                    24000
*/
    U16    u16Degree[3];

    u16Degree[0] = (((U16)(LAPDiaMemorizedRequest.Buffer[3])) << 8) + LAPDiaMemorizedRequest.Buffer[4];
    u16Degree[1] = (((U16)(LAPDiaMemorizedRequest.Buffer[5])) << 8) + LAPDiaMemorizedRequest.Buffer[6];
    u16Degree[2] = (((U16)(LAPDiaMemorizedRequest.Buffer[7])) << 8) + LAPDiaMemorizedRequest.Buffer[8];

    if(    LapRwiIsGuageKeyPointDegreeValid(  500,u16Degree[0]) &&
        LapRwiIsGuageKeyPointDegreeValid( 3000,u16Degree[1]) &&
        LapRwiIsGuageKeyPointDegreeValid(24000,u16Degree[2]))
    {
         //mSERWriteTable(U16Bit, NVM_ConversionOffsetsTable, cDATMotFG, u16Degree[0], Default);
         //mSERWrite(U16Bit, NVM_OutputOneEighthFG,  u16Degree[1], Default);
         //mSERWrite(U16Bit, NVM_OutputMaxFG,        u16Degree[2], Default);

        #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
        bWaitEEPROMWriting = cTrue;
        #endif

         TOSSendControl(cTOSControlLAPDiaSMLoadNvMImmediate);
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }
    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : FuelLevelConversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
#if 0
static U8 ReadFuelLevelConversionCallback( void )
{
    U16    u16Degree[3];
    U8    u8Loop;

    u8Loop = 0;

    //u16Degree[u8Loop++] = mSERReadTable(U16Bit, NVM_ConversionOffsetsTable, cDATMotFG, Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputOneEighthFG,Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputMaxFG,Default);

    for(u8Loop = 0;u8Loop < 3;u8Loop++)
    {
        LAPDiaResponseWriteByte((U8)(u16Degree[u8Loop] >> 8));
        LAPDiaResponseWriteByte((U8)(u16Degree[u8Loop]));
    }

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : FuelLevelConversion
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadFuelLevelConversionCallback_Internal( void )
{
    U16    u16Degree[cU8NbConvPointFG];
    U8    u8Loop;

    u8Loop = 0;

    //u16Degree[u8Loop++] = mSERReadTable(U16Bit, NVM_ConversionOffsetsTable, cDATMotFG, Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputOneEighthFG,Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputOneFourthFG,Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputHalfFG,Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputThreeFourthFG,Default);
    //u16Degree[u8Loop++] = mSERRead(U16Bit,NVM_OutputMaxFG,Default);

    for(u8Loop = 0;u8Loop < cU8NbConvPointFG;u8Loop++)
    {
        LAPDiaResponseWriteByte((U8)(u16Degree[u8Loop] >> 8));
        LAPDiaResponseWriteByte((U8)(u16Degree[u8Loop]));
    }

    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : RunInTestConf
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 WriteRunInTestConfCallback( void )
{
//    mSERWriteTable(U8Bit, NVM_RunInTestModeConfiguration,0,LAPDiaMemorizedRequest.Buffer[3],Default);
//    mSERWriteTable(U8Bit, NVM_RunInTestModeConfiguration,1,LAPDiaMemorizedRequest.Buffer[4],Default);

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : ReadRunInTestConfCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadRunInTestConfCallback( void )
{
    //LAPDiaResponseWriteByte((U8)(mSERReadTable(U8Bit, NVM_RunInTestModeConfiguration,0,Default)));
    //LAPDiaResponseWriteByte((U8)(mSERReadTable(U8Bit, NVM_RunInTestModeConfiguration,1,Default)));

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : RunInTestResult
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
#if 0
static U8 ReadRunInTestResultCallback( void )
{
    //LAPDiaResponseWriteByte((U8)(mSERReadTable(U8Bit, NVM_RunInTestModeResult,0,Default)));
    //LAPDiaResponseWriteByte((U8)(mSERReadTable(U8Bit, NVM_RunInTestModeResult,1,Default)));

    return 0;
}
#endif
//==============================================================================
// DESCRIPTION : ClusterSerialNumber
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================                       
static U8 WriteECUSerialNumberCallback( void )
{
    U8        u8WriteValue = 0U;
    U8        u8Loop = 0U;

    for(u8Loop = 0U; u8Loop < cU8ECUSerialNumberLegnth; u8Loop++)
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
        mSERWriteTable(U8Bit, EEP_ECUSerialNumber, u8Loop, u8WriteValue, Default);
    }

    #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)
    bWaitEEPROMWriting = cTrue;
    #endif

    return 0;
}
//==============================================================================
// DESCRIPTION : ReadBootFingerPrint_Block0Callback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
#if 0
static U8 ReadBootFingerPrint_Block0Callback(void)
{
enum
{
    cProgrammingDate_Year        , //Byte 4
    cProgrammingDate_Month        , //Byte 5
    cProgrammingDate_Day        , //Byte 6
    cTesterSerialNumber_0        , //Byte 7
    cTesterSerialNumber_1        , //Byte 8
    cTesterSerialNumber_2        , //Byte 9
    cTesterSerialNumber_3        , //Byte 10
    cTesterSerialNumber_4        , //Byte 11
    cTesterSerialNumber_5        , //Byte 12
    cFingurePrintNumMax
};

#ifndef COMPILATION_NATIVE
    #define    pECUFingurePrint    (0xFC0004)
#else
    U8    u8ECUFingurePrintBuf[cFingurePrintNumMax];
    #define    pECUFingurePrint    u8ECUFingurePrintBuf
#endif
    U8    u8Loop;
    U8    u8Data;
    LAPDiaResponseWriteByte(0x00); //block id 0
    for(u8Loop = 0;u8Loop < cFingurePrintNumMax;u8Loop++)
    {
        #ifndef COMPILATION_NATIVE
        u8Data = ( ( U8*)pECUFingurePrint )[u8Loop];
        #else
        u8Data = pECUFingurePrint[u8Loop];
        #endif
        LAPDiaResponseWriteByte(u8Data);
    }
    return 0;
}
#endif

//==============================================================================
// DESCRIPTION : ReadCalSWVerCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
static U8 ReadCalSWVerCallback(void)
{
    U8  u8Loop = 0U;
    //U8   u8VerData = 0U;
    /*TODO:�궨�����汾��δʵ�֣�����ֱ�ӷ���0*/

    for(u8Loop = 0U; u8Loop < cU8AppVerLength; u8Loop++)
    {
    	LAPDiaResponseWriteByte(0x20);
    }

    return 0;
/*
    for(u8Loop = 0U; u8Loop < cCfgU8Ver_UsedLength; u8Loop++)
    {
        u8VerData = *((U8*)(cCalSWVerAddr + u8Loop));
        LAPDiaResponseWriteByte(u8VerData);
    }

    mLIBassert(cU8AppVerLength >  cCfgU8Ver_UsedLength);
    for(u8Loop = 0U; u8Loop <(cU8AppVerLength - cCfgU8Ver_UsedLength ) ; u8Loop++)
    {
        LAPDiaResponseWriteByte(0x20);
    }
    return 0U;//ReadVehicleManufacturerSparePartNumberCallback();
*/
}

/*ע������ṹ��Bootloader�ṹ��ͬ������ṹ���ı���ͬ������*/
typedef struct
{
	unsigned char  u8FileLng[4U];
	unsigned char  u8CRCVal[4U];
	unsigned char  u8VerInfo[16U];
	unsigned char  u8PrdtInfo[32U];
	unsigned char  u8BCDDate[8];
	unsigned char  u8Reserved[128U-64U];
}StLoaderHeaderInfoTyp;
#define cBootloaderInfoAddr (0x410)

static U8 ReadLoderSWVerCallback(void)
{
	U8  u8Loop = 0U;
	StLoaderHeaderInfoTyp * p;

	p = (StLoaderHeaderInfoTyp *)cBootloaderInfoAddr;
	for(u8Loop = 0; u8Loop<cCfgU8Ver_UsedLength; u8Loop++)
	{
		LAPDiaResponseWriteByte(p->u8VerInfo[u8Loop]);
	}

	for(u8Loop = 0; u8Loop <(cU8AppVerLength - cCfgU8Ver_UsedLength ) ; u8Loop++)
	{
		LAPDiaResponseWriteByte(0x20);
	}

	return 0;
}

static U8 ReadBCMChnCfgRamAddrCallback(void)
{
	U16 u16Loop = 0U;
	U32 u32Address;
	U8 * u8Dat;

	u32Address = (U32)&DATSbkMirrors.GroupBCMCfg0;
	u8Dat = (U8 *)&u32Address;
	for(u16Loop=0; u16Loop<4; u16Loop++)
	{
		LAPDiaResponseWriteByte(*(u8Dat + 3 - u16Loop));
	}

	return 0;
}

//==============================================================================
// DESCRIPTION : ReadCalDataVerCallback
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : not used now
//==============================================================================
static U8 ReadCalDataVerCallback(void)
{
    U8  u8Loop = 0U;
    //U8   u8VerData = 0U;
    /*TODO:���������汾��δʵ�֣�����ֱ�ӷ���0*/

    for(u8Loop = 0U; u8Loop < cU8AppDataLength; u8Loop++)
    {
    	LAPDiaResponseWriteByte(0x20);
    }

    return 0;
}

static U8 ReadAppDataFingerPintCallback(void)
{
    //Length = 13, Default = 0XFF

     U8  u8Loop = 0U;
    U8  u8WriteValue = 0U;
    for(u8Loop = 0;u8Loop < cU8AppSoftFingerPrintLength;u8Loop++)
    {
        u8WriteValue = mSERReadTable(U8Bit, EEP_DataFingerPrintDataID, u8Loop, Default);
        LAPDiaResponseWriteByte(u8WriteValue);
    }

    return 0;
}

static U8 ReadAppSoftFingerPrintCallback(void)
{
    //Length = 13, Default = 0XFF
    U8  u8Loop = 0U;
    U8  u8WriteValue = 0U;
    for(u8Loop = 0;u8Loop < cU8AppSoftFingerPrintLength;u8Loop++)
    {
        u8WriteValue = mSERReadTable(U8Bit, EEP_SWFingerPrintDataID, u8Loop, Default);
        LAPDiaResponseWriteByte(u8WriteValue);
    }

    return 0;
}


static U8 ReadAppVerCallback(void)
{
    //Length = 16, Default = ��
    U8  u8Loop = 0U;

    LAPDiaResponseWriteByte(cCfgU8Ver_First);
    LAPDiaResponseWriteByte(cCfgU8Ver_Second);
    LAPDiaResponseWriteByte(cCfgU8Ver_Third);
    LAPDiaResponseWriteByte(cCfgU8Ver_Fourth);
    LAPDiaResponseWriteByte(cCfgU8Ver_Fifth);
    LAPDiaResponseWriteByte(cCfgU8Ver_Sixth);
    LAPDiaResponseWriteByte(cCfgU8Ver_Seventh);
    LAPDiaResponseWriteByte(cCfgU8Ver_Eighth);
    LAPDiaResponseWriteByte(cCfgU8Ver_Ninth);
    LAPDiaResponseWriteByte(cCfgU8Ver_Ten);

    mLIBassert(cU8AppVerLength >  cCfgU8Ver_UsedLength);
    for(u8Loop = 0; u8Loop <(cU8AppVerLength - cCfgU8Ver_UsedLength ) ; u8Loop++)
    {
        LAPDiaResponseWriteByte(0x20);
    }

    return 0;
}

static U8 ReadPrdtModelCallback(void)
{
    U8    u8Loop = 0U;
    U8    u8ReadValue = 0U;

    for(u8Loop = 0U; u8Loop < cU8ProductModelDataLength; u8Loop ++)
    {
        u8ReadValue = mSERReadTable(U8Bit, EEP_ProductModelType, u8Loop, Default);
        LAPDiaResponseWriteByte(u8ReadValue);
    }

    return 0;
}

static U8 WriteAppDataFingerPintCallback(void)
{
	U8    u8Loop = 0U;
	U8    u8WriteValue = 0U;
	BOOL  bDataValid = cTrue;

	U16		u16Year = 0U;
	U8		u8Year_H = 0U;
	U8		u8Year_L = 0U;
	U8		u8Month = 0U;
	U8		u8Day = 0U;
	U8      u8Hour = 0U;
	U8      u8Minite = 0U;

	for(u8Loop = 0U;u8Loop < 6U;u8Loop++)//ǰ6�ֽ�Ϊʱ����Ϣ��BCD����
	{
		u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
		if(mIsValidBCDCode(u8WriteValue))
		{
			//no statement
		}
		else
		{
			bDataValid = cFalse;
			break;
		}
	}

	if(bDataValid)
	{
		//ʱ����ϢҪ��ʱ�����Ч�Խ����ж�
		u8Minite = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[8U]);
		u8Hour = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[7U]);
		u8Day   = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[6U]);
		u8Month = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[5U]);
		u8Year_L = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[4U]);
		u8Year_H = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[3U]);

		u16Year  = u8Year_H * 100U + u8Year_L;

		if(((u16Year >= 2016U)&&(u16Year <= 9999U)) &&
		   ((u8Day > 0U)&&(u8Day <= DATTRC_GetMaxValidDay(u16Year,u8Month))) &&
		   (u8Hour < 24U) &&
		   (u8Minite < 60U))
		{
			for(u8Loop = 0U; u8Loop < cU8AppDataFingerPintLength; u8Loop++)
			{
				u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
				mSERWriteTable(U8Bit, EEP_DataFingerPrintDataID, u8Loop, u8WriteValue, Default);
			}

			#if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)  //�ж�EEP�����Ƿ�ʹ��?banfy
			bWaitEEPROMWriting = cTrue;
			#endif
		}
		else
		{
			LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
		}
	}
	else
	{
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}

	return 0;
}

static U8 WriteAppSoftFingerPrintCallback(void)
{
	U8    u8Loop = 0U;
	U8    u8WriteValue = 0U;
	BOOL  bDataValid = cTrue;
	U16		u16Year = 0U;
	U8		u8Year_H = 0U;
	U8		u8Year_L = 0U;
	U8		u8Month = 0U;
	U8		u8Day = 0U;
	U8      u8Hour = 0U;
	U8      u8Minite = 0U;

	for(u8Loop = 0U;u8Loop < 6U;u8Loop++)//ǰ6�ֽ�Ϊʱ����Ϣ��BCD����
	{
		u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
		if(mIsValidBCDCode(u8WriteValue))
		{
			//no statement
		}
		else
		{
			bDataValid = cFalse;
			break;
		}
	}

	if(bDataValid)
	{
		//ʱ����ϢҪ��ʱ�����Ч�Խ����ж�
		u8Minite = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[8U]);
		u8Hour = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[7U]);
		u8Day   = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[6U]);
		u8Month = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[5U]);
		u8Year_L = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[4U]);
		u8Year_H = mChgBCDToASCII(LAPDiaMemorizedRequest.Buffer[3U]);

		u16Year  = u8Year_H * 100 + u8Year_L;

		if(((u16Year >= 2016U)&&(u16Year <= 9999U)) &&
		   ((u8Day > 0U)&&(u8Day <= DATTRC_GetMaxValidDay(u16Year,u8Month))) &&
		   (u8Hour < 24U) &&
		   (u8Minite < 60U))
		{
			for(u8Loop = 0U; u8Loop < cU8AppSoftFingerPrintLength; u8Loop++)
			{
				u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
				mSERWriteTable(U8Bit, EEP_SWFingerPrintDataID, u8Loop, u8WriteValue, Default);
			}

			#if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)  //�ж�EEP�����Ƿ�ʹ��?banfy
			bWaitEEPROMWriting = cTrue;
			#endif
		}
		else
		{
			LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
		}
	}
	else
	{
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}

	return 0;
}

static U8 WriteECUHWVersionCallback(void)
{
	U8    u8Loop = 0U;
	U8    u8ReadValue = 0U;
	BOOL  bIsInvalidValue = cTrue;

	for(u8Loop = 0U; u8Loop < cU8ECUHWVersionDataLength; u8Loop ++)
	{
		u8ReadValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
		if( ('0'> u8ReadValue) || ((u8ReadValue > '9') && ('A'> u8ReadValue)) || (u8ReadValue > 'Z'))
		{
			bIsInvalidValue = cFalse;
			break;
		}
	}

	if(cTrue == bIsInvalidValue)
	{
		for(u8Loop = 0U; u8Loop < cU8ECUHWVersionDataLength; u8Loop ++)
		{
			u8ReadValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
			mSERWriteTable(U8Bit, EEP_HWVersion, u8Loop, u8ReadValue, Default);
		}
	}
	else
	{
		LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
	}

    return 0;
}

static U8 WritePrdtModelCallback(void)
{
    U8    u8Loop = 0U;
    U8    u8ReadValue = 0U;

    for(u8Loop = 0U; u8Loop < cU8ProductModelDataLength; u8Loop ++)
    {
        u8ReadValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
       mSERWriteTable(U8Bit, EEP_ProductModelType, u8Loop, u8ReadValue, Default);
    }

    return 0;
}
static U8 WriteECUPartNumberCallback(void)
{
    U8    u8Loop = 0U;
    U8    u8WriteValue = 0U;
#if 0
    BOOL  bDataValid = cTrue;

    //2017��11��7�� 16:25:32
    //��ǰʹ��10���ֽڵı�ʾPartNumber�������ֲ�����Χ���ơ�

    for(u8Loop = 0U;u8Loop < cU8ECUPartNumberDataLength;u8Loop++)//ǰ6�ֽ�Ϊʱ����Ϣ��BCD����
    {
        u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];

        if(mIsValidBCDCode(u8WriteValue))
        {
            //no statement
        }
        else
        {
            bDataValid = cFalse;
            break;
        }
    }

    if(bDataValid)
#else
    if(cTrue)
#endif
    {
        for(u8Loop = 0U; u8Loop < cU8ECUPartNumberDataLength; u8Loop++)
        {
            u8WriteValue = LAPDiaMemorizedRequest.Buffer[3U + u8Loop];
            mSERWriteTable(U8Bit, EEP_ECUPartNumber, u8Loop, u8WriteValue, Default);
        }
        #if defined(cLIBStkEep_Used) || defined(cLIBStkDFA_Used)  //�ж�EEP�����Ƿ�ʹ��?banfy
        bWaitEEPROMWriting = cTrue;
        #endif
    }
    else
    {
        LAPDiaResponse.NegativeCode = cLAPDiaRequestOutOfRange;
    }

    return 0;
}


void DID_ResposeReadDiagInfo(U16 * data, U8 length)
{
	U8 u8Loop;
	U8 u8LHByte;
	U8 u8LLByte;

	for(u8Loop=0; u8Loop<=length; u8Loop++)
	{
		u8LHByte = data[u8Loop] >> 8u;
		u8LLByte = data[u8Loop];
		LAPDiaResponseWriteByte(u8LHByte);
		LAPDiaResponseWriteByte(u8LLByte);
	}
}

static U8 ReadDID_OUTStartDiagDelayTimeCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, StartDiagDelayTime, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

static U8 ReadDID_OUTCloseDiagDelayTimeCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, CloseDiagDelayTime, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

static U8 ReadDID_OUTFaultConfirmTimeCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, FaultConfirmTime, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

static U8 ReadDID_OUTOverloadCurrentCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, OverloadCurrent, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

static U8 ReadDID_OUTOpenCurrentCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, OpenCurrent, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

void DID_ReadDiagInfo(U16 *data, U8 length)
{
	U8 u8Loop;
	U8 u8LHByte;
	U8 u8LLByte;

	for(u8Loop=0; u8Loop<=length; u8Loop++)
	{
		u8LHByte = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos + (u8Loop * 2u) + 0u];
		u8LLByte = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos + (u8Loop * 2u) + 1u];

		data[u8Loop] = (u8LHByte << 8u) + u8LLByte;
	}
}

static U8 WriteDID_OUTStartDiagDelayTimeCallback(void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	DID_ReadDiagInfo(data, cMaxChnDiagIndex);
	mSERWriteStruct(LAPPoutSetChnCfg, StartDiagDelayTime, data, Default);
#endif
	return 0;
}

static U8 WriteDID_OUTCloseDiagDelayTimeCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	DID_ReadDiagInfo(data, cMaxChnDiagIndex);
	mSERWriteStruct(LAPPoutSetChnCfg, CloseDiagDelayTime, data, Default);
#endif
	return 0;
}

static U8 WriteDID_OUTFaultConfirmTimeCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	DID_ReadDiagInfo(data, cMaxChnDiagIndex);
	mSERWriteStruct(LAPPoutSetChnCfg, FaultConfirmTime, data, Default);
#endif
	return 0;
}

static U8 WriteDID_OUTOverloadCurrentCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	DID_ReadDiagInfo(data, cMaxChnDiagIndex);
	mSERWriteStruct(LAPPoutSetChnCfg, OverloadCurrent, data, Default);
#endif
	return 0;
}

static U8 WriteDID_OUTOpenCurrentCallback( void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	DID_ReadDiagInfo(data, cMaxChnDiagIndex);
	mSERWriteStruct(LAPPoutSetChnCfg, OpenCurrent, data, Default);
#endif
	return 0;
}

static U8 ReadMsgTmOutSleepDelayCallback(void)
{
    U16 u16Data = mSERRead(U16Bit, EEP_MsgTmOutSleepDelay, Default);

    U8   u8LHByte =   (U8)(u16Data>>8U);
    U8   u8LLByte =    (U8)(u16Data>>0U);

    LAPDiaResponseWriteByte(u8LHByte);
    LAPDiaResponseWriteByte(u8LLByte);

    return 0;
}

static U8 WriteMsgTmOutSleepDelayCallback(void)
{
	U16 u16Data = 0U;

	U16	u16LHByte = 0U;
	U16 u16LLByte = 0U;

	u16LHByte = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos + 0U] ;
	u16LLByte = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos + 1U] ;

	u16Data = (u16LHByte << 8U) + (u16LLByte);

	mSERWrite(U16Bit,EEP_MsgTmOutSleepDelay, u16Data, Default );
	mSERControl(Eep, GlobalUpDateEepGroupGroupOdo);

    return 0;
}

extern U32 u32SysRunCount;
static U8 ReadDID_SysRunTimeCallback(void)
{
	U8 u8HHByte;
	U8 u8HLByte;
	U8 u8LHByte;
	U8 u8LLByte;

	u8HHByte = (u32SysRunCount >> 24U);
	u8HLByte = (u32SysRunCount >> 16U);
	u8LHByte = (u32SysRunCount >> 8U);
	u8LLByte = (u32SysRunCount >> 0U);

	LAPDiaResponseWriteByte(u8HHByte);
	LAPDiaResponseWriteByte(u8HLByte);
	LAPDiaResponseWriteByte(u8LHByte);
	LAPDiaResponseWriteByte(u8LLByte);

	return 0;
}

static U8 ReadTestMode_IOCtrlCallback(void)
{
	U8 u8Buf;

	u8Buf = mSERRead(U1Bit, IsTestMode, Default);

	LAPDiaResponseWriteByte(u8Buf);

	return 0;
}

static U8 ReadDID_PoutCurrentFeedBackCallback(void)
{
#if 0	//TODO:XXX
	U16 data[cMaxChnDiagIndex + 1u];

	mSERReadStruct(LAPPoutGetChnCfg, CurrentFeedback, data, Default);

	DID_ResposeReadDiagInfo(data, cMaxChnDiagIndex);
#endif
	return 0;
}

static U8 ReadDID_PoutVoltageFeedbackCallback(void)
{
#if 0	//TODO:XXX
	U16 data[cVOL_DIAG_CHN];

	mSERReadStruct(LAPPoutGetChnCfg, VoltageFeedback, data, Default);

	DID_ResposeReadDiagInfo(data, cVOL_DIAG_CHN);
#endif
	return 0;
}

//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDIInputCallback(void)
{
    U8 u8ReadValue1 = 0U;
    U8 u8ReadValue2 = 0U;
    U8 u8ReadValue3 = 0U;
    U8 u8ReadValue4 = 0U;
    U8 u8ReadValue5 = 0U;
#if 0
    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_DIO1_Reserve,Default))
    {
    	u8ReadValue1 = u8ReadValue1 | 0x01;
    }
    else
    {
    	u8ReadValue1 = u8ReadValue1 & 0xFC;
    }

    //bit 2 3
    if(cTrue == mSERRead(U1Bit,DI_DIO2_Reserve,Default))
    {
    	u8ReadValue1 = u8ReadValue1 | 0x04;
    }
    else
    {
    	u8ReadValue1 = u8ReadValue1 & 0xF3;
    }

    //bit 4 5
    if(cTrue == mSERRead(U1Bit,DI_FrontClosedSig,Default))
    {
    	u8ReadValue1 = u8ReadValue1 | 0x10;
    }
    else
    {
    	u8ReadValue1 = u8ReadValue1 & 0xCF;
    }

    //bit 6 7
    if(cTrue == mSERRead(U1Bit,DI_BackClosedSig,Default))
    {
    	u8ReadValue1 = u8ReadValue1 | 0x40;
    }
    else
    {
    	u8ReadValue1 = u8ReadValue1 & 0x3F;
    }

    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_PinchSig,Default))
    {
    	u8ReadValue2 = u8ReadValue2 | 0x01;
    }
    else
    {
    	u8ReadValue2 = u8ReadValue2 & 0xFC;
    }

    //bit 2 3
    if(cTrue == mSERRead(U1Bit,DI_DoorOutKeySig,Default))
    {
    	u8ReadValue2 = u8ReadValue2 | 0x04;
    }
    else
    {
    	u8ReadValue2 = u8ReadValue2 & 0xF3;
    }

    //bit 4 5
    if(cTrue == mSERRead(U1Bit,DI_SpeedSig,Default))
    {
    	u8ReadValue2 = u8ReadValue2 | 0x10;
    }
    else
    {
    	u8ReadValue2 = u8ReadValue2 & 0xCF;
    }


    //bit 6 7
    if(cTrue == mSERRead(U1Bit,DI_OpenSig,Default))
    {
    	u8ReadValue2 = u8ReadValue2 | 0x40;
    }
    else
    {
    	u8ReadValue2 = u8ReadValue2 & 0x3F;
    }

    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_CloseSig,Default))
    {
    	u8ReadValue3 = u8ReadValue3 | 0x01;
    }
    else
    {
    	u8ReadValue3 = u8ReadValue3 & 0xFC;
    }

    //bit 2 3
    if(cTrue == mSERRead(U1Bit,DI_OnPowerSig,Default))
    {
    	u8ReadValue3 = u8ReadValue3 | 0x04;
    }
    else
    {
    	u8ReadValue3 = u8ReadValue3 & 0xF3;
    }

    //bit 4 5
    if(cFalse == mSERRead(U1Bit,DI_EmergencySig,Default))
    {
    	u8ReadValue3 = u8ReadValue3 | 0x10;
    }
    else
    {
    	u8ReadValue3 = u8ReadValue3 & 0xCF;
    }

    //bit 6 7
    if(cFalse == mSERRead(U1Bit,DI_OpenLidSig,Default))
    {
    	u8ReadValue3 = u8ReadValue3 | 0x40;
    }
    else
    {
    	u8ReadValue3 = u8ReadValue3 & 0x3F;
    }

    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_BackClosedSig,Default))
    {
    	u8ReadValue4 = u8ReadValue4 | 0x01;
    }
    else
    {
    	u8ReadValue4 = u8ReadValue4 & 0xFC;
    }

    //bit 2 3
    if(cTrue == mSERRead(U1Bit,DI_BackOpenedSig,Default))
    {
    	u8ReadValue4 = u8ReadValue4 | 0x04;
    }
    else
    {
    	u8ReadValue4 = u8ReadValue4 & 0xF3;
    }

    //bit 4 5
    if(cFalse == mSERRead(U1Bit,DI_EmergencyRestrainSig,Default))
    {
    	u8ReadValue4 = u8ReadValue4 | 0x10;
    }
    else
    {
    	u8ReadValue4 = u8ReadValue4 & 0xCF;
    }

    //bit 6 7
    if(cTrue == mSERRead(U1Bit,DI_LowPressureSig,Default))
    {
    	u8ReadValue4 = u8ReadValue4 | 0x40;
    }
    else
    {
    	u8ReadValue4 = u8ReadValue4 & 0x3F;
    }

    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_DIOF1_Reserve,Default))
    {
    	u8ReadValue5 = u8ReadValue5 | 0x01;
    }
    else
    {
    	u8ReadValue5 = u8ReadValue5 & 0xFC;
    }

#endif
    LAPDiaResponseWriteByte(u8ReadValue1);
    LAPDiaResponseWriteByte(u8ReadValue2);
    LAPDiaResponseWriteByte(u8ReadValue3);
    LAPDiaResponseWriteByte(u8ReadValue4);
    LAPDiaResponseWriteByte(u8ReadValue5);

    return 0;
}
//===================================================================
// DESCRIPTION : ģ��������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllADCInputCallback(void)
{
    U16 u16ReadValue[3] = {0,0,0} ;
    U8 u8Loop = 0U;
    U16 u16ReadTemp = 0U;

/*    u16ReadTemp =  mSERRead(U16Bit,ADISVAL_0_5V_AD1,Default);
    u16ReadTemp =  u16ReadTemp*1000*5/cAdAccury;
    u16ReadValue[0] = u16ReadTemp;

    u16ReadTemp =  mSERRead(U16Bit,ADISVAL_0_5V_AD2,Default);
    u16ReadTemp =  u16ReadTemp*1000*5/cAdAccury;
    u16ReadValue[1] = u16ReadTemp;

    u16ReadTemp =  mSERRead(U16Bit,ADISVAL_0_5V_AD3,Default);
    u16ReadTemp =  u16ReadTemp*1000*5/cAdAccury;
    u16ReadValue[2] = u16ReadTemp;*/

    for(u8Loop = 0U; u8Loop < 3U; u8Loop++)
    {
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop] >> 8U));
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop]));
    }

    return 0;
}
//===================================================================
// DESCRIPTION : ��������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllButtonInputCallback( void)
{
    U8 u8ReadValue1 = 0U;
#if 0
    //bit 0 1
    if(cTrue == mSERRead(U1Bit,DI_StudySig,Default))
    {
    	u8ReadValue1 = u8ReadValue1 | 0x01;
    }
    else
    {
    	u8ReadValue1 = u8ReadValue1 & 0xFC;
    }
#endif
    LAPDiaResponseWriteByte(u8ReadValue1);
    return 0;

}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllOhmInputCallback( void)
{
    U16 u16ReadValue[4] = {0,0,0,0} ;
    U8 u8Loop = 0U;
    U16 u16ReadTemp = 0U;

/*    u16ReadTemp =  mSERRead(U16Bit,ADVAL_RIN_AD4,Default);
    u16ReadTemp =  u16ReadTemp*1000*5/cAdAccury;
    u16ReadValue[0] = u16ReadTemp;

    u16ReadTemp =  mSERRead(U16Bit,ADVAL_RIN_AD5,Default);
    u16ReadTemp = u16ReadTemp*1000*5/cAdAccury;
    if((u16ReadValue[0] - u16ReadTemp) <= 0)
    {
    	u16ReadTemp = u16ReadValue[0]-1;
    }
    u16ReadTemp = (u16ReadTemp*10000)/(u16ReadValue[0] - u16ReadTemp);
    u16ReadValue[1] = u16ReadTemp;

    u16ReadTemp =  mSERRead(U16Bit,ADVAL_RIN_AD6,Default);
    u16ReadTemp = u16ReadTemp*1000*5/cAdAccury;
    u16ReadValue[2] = u16ReadTemp;

    u16ReadTemp =  mSERRead(U16Bit,ADVAL_RIN_AD7,Default);
    u16ReadTemp = u16ReadTemp*1000*5/cAdAccury;
    if((u16ReadValue[2] - u16ReadTemp) <= 0)  //
    {
    	u16ReadTemp = u16ReadValue[2]-1;
    }*/
    u16ReadTemp = (u16ReadTemp*10000)/(u16ReadValue[2] - u16ReadTemp);
    u16ReadValue[3] = u16ReadTemp;

    for(u8Loop = 0U; u8Loop < 4U; u8Loop++)
    {
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop] >> 8U));
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop]));
    }

    return 0;
}
//===================================================================
// DESCRIPTION : ����¶�������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllTemperInputCallback( void)
{
    U16 u16ReadValue[1] = {0};
    U8 u8Loop = 0U;
    U16 u16ReadTemp = 0U;

    //u16ReadTemp = mSERRead(U16Bit,ADVAL_PCB_TEMP_AIN,Default);
    u16ReadTemp = (u16ReadTemp*51)/(cAdAccury*10 - u16ReadTemp*15);
    if((u16ReadTemp >= 2)&&(u16ReadTemp <= 9))
	{
        u16ReadValue[0] = 30;
	}
    else
    {
        u16ReadValue[0] = 100;
    }

  	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop] >> 8U));
   	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop]));

    return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO1outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN1,1);
//	BSPOutputCtr(OUT_CTL_H_1,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO1outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN1,1);
		//BSPOutputCtr(OUT_CTL_H_1,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN1,0);
		//BSPOutputCtr(OUT_CTL_H_1,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO2outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN1,1);
//	BSPOutputCtr(OUT_CTL_H_2,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO2outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN1,1);
		//BSPOutputCtr(OUT_CTL_H_2,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN1,0);
		//BSPOutputCtr(OUT_CTL_H_2,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO3outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN1,1);
//	BSPOutputCtr(OUT_CTL_H_3,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO3outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN1,1);
		//BSPOutputCtr(OUT_CTL_H_3,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN1,0);
		//BSPOutputCtr(OUT_CTL_H_3,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO4outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN1,1);
//	BSPOutputCtr(OUT_CTL_H_4,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO4outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN1,1);
		//BSPOutputCtr(OUT_CTL_H_4,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN1,0);
		//BSPOutputCtr(OUT_CTL_H_4,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO5outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_5,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO5outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN2,1);
		//BSPOutputCtr(OUT_CTL_H_5,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN2,0);
		//BSPOutputCtr(OUT_CTL_H_5,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO6outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_6,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO6outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN2,1);
		//BSPOutputCtr(OUT_CTL_H_6,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN2,0);
		//BSPOutputCtr(OUT_CTL_H_6,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO7outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_7,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO7outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN2,1);
		//BSPOutputCtr(OUT_CTL_H_7,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN2,0);
		//BSPOutputCtr(OUT_CTL_H_7,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO8outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_8,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO8outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN2,1);
		//BSPOutputCtr(OUT_CTL_H_8,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN2,0);
		//BSPOutputCtr(OUT_CTL_H_8,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO9outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_9,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO9outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN3,1);
		//BSPOutputCtr(OUT_CTL_H_9,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN3,0);
		//BSPOutputCtr(OUT_CTL_H_9,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO10outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_10,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO10outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN3,1);
		//BSPOutputCtr(OUT_CTL_H_10,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN3,0);
		//BSPOutputCtr(OUT_CTL_H_10,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO11outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_11,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO11outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN3,1);
		//BSPOutputCtr(OUT_CTL_H_11,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN3,0);
		//BSPOutputCtr(OUT_CTL_H_11,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDO12outputCallback( void)
{
//	BSPOutputCtr(OUT_DEN2,1);
//	BSPOutputCtr(OUT_CTL_H_12,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDO12outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_DEN3,1);
		//BSPOutputCtr(OUT_CTL_H_12,1);
	}
	else
	{
		//BSPOutputCtr(OUT_DEN3,0);
		//BSPOutputCtr(OUT_CTL_H_12,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDOF1outputCallback( void)
{

//	BSPOutputCtr(OUT_CTL3408_F1,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDOF1outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_CTL3408_F1,1);
	}
	else
	{
		//BSPOutputCtr(OUT_CTL3408_F1,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : ����������״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllDOF2outputCallback( void)
{
//	BSPOutputCtr(OUT_CTL3408_F2,1);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllDOF2outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_CTL3408_F2,1);
	}
	else
	{
		//BSPOutputCtr(OUT_CTL3408_F2,0);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllLED1outputCallback( void)
{
//	BSPOutputCtr(OUT_IO_LED5,0);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllLED1outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_IO_LED5,0);
	}
	else
	{
		//BSPOutputCtr(OUT_IO_LED5,1);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllLED2outputCallback( void)
{
//	BSPOutputCtr(OUT_IO_LED1,0);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllLED2outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_IO_LED1,0);
	}
	else
	{
		//BSPOutputCtr(OUT_IO_LED1,1);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllLED3outputCallback( void)
{
//	BSPOutputCtr(OUT_IO_LED4,0);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllLED3outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_IO_LED4,0);
	}
	else
	{
		//BSPOutputCtr(OUT_IO_LED4,1);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllLED4outputCallback( void)
{
//	BSPOutputCtr(OUT_IO_LED3,0);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllLED4outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_IO_LED3,0);
	}
	else
	{
		//BSPOutputCtr(OUT_IO_LED3,1);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllLED5outputCallback( void)
{
//	BSPOutputCtr(OUT_IO_LED2,0);

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteAllLED5outputCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

	if(cTrue == u8Data)
	{
		//BSPOutputCtr(OUT_IO_LED2,0);
	}
	else
	{
		//BSPOutputCtr(OUT_IO_LED2,1);
	}

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadAllBATInputCallback( void)
{
    U16 u16ReadValue[4] = {0,0,0,0} ;
    U8 u8Loop = 0U;
    U16 u16ReadTemp = 0U;

/*    u16ReadTemp = mSERRead(U16Bit,AD_BAT_P_ADC,Default);
    u16ReadTemp = u16ReadTemp*5*11000/cAdAccury;
    u16ReadValue[0] = u16ReadTemp;

    u16ReadTemp = mSERRead(U16Bit,AD_8VADC,Default);
    u16ReadTemp = u16ReadTemp*5*3000/cAdAccury;
    u16ReadValue[1] = u16ReadTemp;

    u16ReadTemp = mSERRead(U16Bit,ADVAL_VCC_ADC,Default);
    u16ReadTemp = u16ReadTemp*5*2000/cAdAccury;
    u16ReadValue[2] = u16ReadTemp;

    u16ReadTemp = mSERRead(U16Bit,AD_5V_SENSOR_ADC,Default);
    u16ReadTemp = u16ReadTemp*5*2000/cAdAccury;
    u16ReadValue[3] = u16ReadTemp;*/


    for(u8Loop = 0U; u8Loop < 4U; u8Loop++)
    {
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop] >> 8U));
    	LAPDiaResponseWriteByte((U8)(u16ReadValue[u8Loop]));
    }

    return 0;

}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 ReadDID_TestEnableCallback( void)
{
	U8 u8Loop = 0U;

	//u8Loop = mSERRead(U8Bit,TestEnableFlag,Default);

	LAPDiaResponseWriteByte((U8)(u8Loop));

	return 0;
}
//===================================================================
// DESCRIPTION : Led����״̬, �޴洢, DLC:3, Hex
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//===================================================================
static U8 WriteDID_TestEnableCallback( void)
{
	U8 u8Data = LAPDiaMemorizedRequest.Buffer[cCfgU8ReqDataStartPos];

/*	if(cTrue == u8Data)
	{
		mSERWrite(U8Bit,TestEnableFlag,cTrue,Default);
	}
	else
	{
		mSERWrite(U8Bit,TestEnableFlag,cFalse,Default);
	}*/

    //BSPOutputCtr(OUT_DEN1,0);
    //BSPOutputCtr(OUT_DEN2,0);
    //BSPOutputCtr(OUT_DEN3,0);
    //BSPOutputCtr(OUT_CTL3408_F1,0);
    //BSPOutputCtr(OUT_CTL3408_F2,0);
    //BSPOutputCtr(OUT_IO_LED1,1);
    //BSPOutputCtr(OUT_IO_LED2,1);
    //BSPOutputCtr(OUT_IO_LED3,1);
    //BSPOutputCtr(OUT_IO_LED4,1);
    //BSPOutputCtr(OUT_IO_LED5,1);

	return 0;
}

