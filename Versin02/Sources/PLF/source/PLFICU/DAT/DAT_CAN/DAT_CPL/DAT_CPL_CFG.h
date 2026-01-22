

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------

#ifndef I_DAT_CPL_CFG_H
#define I_DAT_CPL_CFG_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CPLx.h"
#include "DAT_CPLPx.h"
#else
#include ".\..\..\..\SCC2Gen\GEN\DAT_CPLx.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_CPLPx.h"
#endif

//------------------------------------------------------------------------------
// Data prefix for constant & data
//
// unsigned int {u8,u16,u32} / signed int {s8,s16,s32} 
// register size unsigned int {r} / float {f32,f64}  / s for struct 
// no prefix for other types.
//
//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------
#define	DATCplInitBuffersReception			InitBuffersReception
#define	DATCplDefaultBuffersReception		DefaultBuffersReception
#define	DATCplInitBuffersEmission			InitBuffersEmission

/*-------------------------------------------------------------------------
  Macro exportees

  #define mCOMNomMacro   (DefinitionDeLaMacro)
  -------------------------------------------------------------------------*/ 
//0x170 消息用于DATIfv_FuelConsumptionRcved，燃油量计算
//0x221     DATCvtVehSpdRcved(); DATOdo_WheelSpdRcved();实现车速和轮速计算
//0x155 发动机转速计算
//模式都是接收到消息后，启动一个任务。
//Zjb add. later will add according task code.
//#define	mDATCanMsgRcvedPro(RxHandle)
#define	mDATCanMsgRcvedPro( RxHandle )												\
{																					\
	/*App message*/																	\
	switch( RxHandle )																\
	{ 																				\
		case cDATCdlD_UURxHandleICUCMD_0x150:									\
			break;																	\
		default:																	\
			break;																	\
	}																				\
}

//If Msg time out,Received flag is cleared before this macro is called!
//Caution:Not all of the signal should be set to default value!!!
//Caution!!!!!!!!!!!!!!!!!!!!!!!!1Caution!!!!!!!!!!!!!!!!!!!!!!!!
//Be care of this process!!!!!!!!
//This action should be confirmed by application programmer!!!!!!
#define	mDATCanMsgTimeoutPro(RxHandle)	      \
{                                             \
    switch(RxHandle)                          \
	{                                         \
	case (cDATCdlD_UURxHandleRPM_EEC1_0X0CF00400):      \
	case (cDATCdlD_UURxHandleU8_CoolantTemperature_ET1_0X18FEEE00):      \
	case (cDATCdlD_UURxHandleOilPressure_EFLP1_0X18FEEF00):     \
	case (cDATCdlD_UURxHandleCatalystTankLevel_TI1_0X18FE563D):      \
	case (cDATCdlD_UURxHandleCatalystTankLevel_TI1_0X18FE5600):      \
	SetFrameDefaultValue(RxHandle);break;     \
	default:break;                            \
	}                                         \
}

#define	mDATCanMsgTimeoutPro_Old(RxHandle)																\
{																									\
	switch( RxHandle )																				\
	{																								\
		case cDATCdlD_UURxHandleTCU_0x151:														\
				SetFrameDefaultValue(cDATCdlD_UURxHandleTCU_0x151);								\
				break;																				\
		case cDATCdlD_UURxHandleEMS_0x153:														\
				SetFrameDefaultValue(cDATCdlD_UURxHandleEMS_0x153);								\
				break;																				\
		case cDATCdlD_UURxHandleEMS_0x155:															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleEMS_0x155);								\
				break;																				\
		case cDATCdlD_UURxHandleEMS_0x156: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleEMS_0x156);									\
				break;																				\
		case cDATCdlD_UURxHandleEMS_0x170: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleEMS_0x170);									\
				break;																				\
		case cDATCdlD_UURxHandleAWD_0x190: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleAWD_0x190);									\
				break;																				\
		case cDATCdlD_UURxHandleESP_0x214: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleESP_0x214);									\
				break;																				\
		case cDATCdlD_UURxHandleESP_0x221: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleESP_0x221);									\
				break;																				\
		case cDATCdlD_UURxHandleTCU_0x230: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleTCU_0x230);									\
				break;																				\
		case cDATCdlD_UURxHandleEPS_0x260: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleEPS_0x260);									\
				break;																				\
		case cDATCdlD_UURxHandleBCM_0x310: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleBCM_0x310);									\
				break;																				\
		case cDATCdlD_UURxHandleBCM_0x311: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleBCM_0x311);									\
				break;																				\
		case cDATCdlD_UURxHandleBCM_0x312: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleBCM_0x312);									\
				break;																				\
		case cDATCdlD_UURxHandlePEPS_0x320: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandlePEPS_0x320);									\
				break;																				\
		case cDATCdlD_UURxHandleSRS_0x350: 															\
				SetFrameDefaultValue(cDATCdlD_UURxHandleSRS_0x350);									\
				break;																				\
		default:																					\
				break;																				\
	}																								\
}


#define	mDATCanMsgTimeoutDTCPro(RxHandle)                                                           \
{																									\
	switch( RxHandle )																				\
	{																								\
		case cDATCdlD_UURxHandleCatalystTankLevel_TI1_0X18FE563D:														\
				mSERWriteTable(U1Bit,DTCFaults,eDTCIDPEPSFrameLost,cTrue,Default);					\
				/*mDATControl(Dtc, ReportDTCStatus);*/													\
				break;																				\
		case cDATCdlD_UURxHandleCatalystTankLevel_TI1_0X18FE5600:														\
				mSERWriteTable(U1Bit,DTCFaults,eDTCIDBCMFrameLost,cTrue,Default);					\
				/*mDATControl(Dtc, ReportDTCStatus);*/													\
				break;																				\
		default:																					\
				break;																				\
	}																								\
}


#define	mDATCanMsgTimeoutDTCPro_Old(RxHandle)															\
{																									\
	switch( RxHandle )																				\
	{																								\
		case cDATCdlD_UURxHandlePEPS_0x320:														\
				mSERWriteTable(U1Bit,DTCFaults,eDTCIDPEPSFrameLost,cTrue,Default);					\
				/*mDATControl(Dtc, ReportDTCStatus);*/													\
				break;																				\
		case cDATCdlD_UURxHandleBCM_0x310:														\
				mSERWriteTable(U1Bit,DTCFaults,eDTCIDBCMFrameLost,cTrue,Default);					\
				/*mDATControl(Dtc, ReportDTCStatus);*/													\
				break;																				\
		default:																					\
				break;																				\
	}																								\
}




#define	mDATCanMsgDTCEnable()																		\
{																									\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossGW1, (U1)1, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossGW2, (U1)1, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossPEPS4, (U1)1, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM1, (U1)1, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM2, (U1)1, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM3, (U1)1, Default);			\
}

#define	mDATCanMsgDTCDisable()																		\
{																									\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossGW1, (U1)0, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossGW2, (U1)0, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossPEPS4, (U1)0, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM1, (U1)0, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM2, (U1)0, Default);			\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_FrameLossBCM3, (U1)0, Default);			\
}

#define	mDATCanBusDTCEnable()																		\
{																									\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_BusOff, (U1)1, Default);					\
}

#define	mDATCanBusDTCDisable()																		\
{																									\
	mSERWriteTable(U1Bit, DTCMonitoringCycles, eDTCFunCom_BusOff, (U1)0, Default);					\
}
    
#define cNM_ErrAct				((U8)0)
#define cNM_ErrPassive			((U8)1)
#define cNM_BusOff				((U8)2)
#define cNM_Notused				((U8)3)


extern U8  DATCnmGetCANControllerStatus();
#define	mSERReadU8BitCanControllerStatusDefault()		(DATCnmGetCANControllerStatus())


//Diag macro limit condition
//Not using STK Tx forbid,because it will influence NM  (RxHandle)%8U
#define	mDATCanMsgIsRxDisable(RxHandle)			(((su8HandleDisableRxCtrlArr[(RxHandle)/8U]) >> ( (RxHandle)%8U)) & 0x00000001)
#define	mDATCanMsgRxEnable(RxHandle)			(((su8HandleDisableRxCtrlArr[(RxHandle)/8U]) &= ~(((U32)1) << ( (RxHandle)%8U))))
#define	mDATCanMsgRxDisable(RxHandle)			(((su8HandleDisableRxCtrlArr[(RxHandle)/8U]) |=  (((U32)1) << ( (RxHandle)%8U))))

#define	mDATCanMsgIsTxDisable(TxHandle)			(((su8HandleDisableTxCtrlArr[((TxHandle)/8U)]) >> ((TxHandle)%8U)) & 0x00000001)
#define	mDATCanMsgTxEnable(TxHandle)			(((su8HandleDisableTxCtrlArr[((TxHandle)/8U)]) &= ~(((U32)1) << ((TxHandle)%8U))))
#define	mDATCanMsgTxDisable(TxHandle)			(((su8HandleDisableTxCtrlArr[((TxHandle)/8U)]) |=  (((U32)1) << ((TxHandle)%8U))))


/******************以下空间代码参与CanEmission.py自动生成代码，请勿在其中增加其他代码******/
#define	mSERReadU1BitNoMsgToClusterOnCANDefault()		(DatCplNoMsgToClusterOnCANBus())

#define mDATCanIsMsgNotLost(v)  mDATCanIsMsgNotLost##v
#define mDATCanIsMsgNotLostICUCMD_0x150 (mDATCplReadAppTrameReceived(ICUCMD_0x150))
#define mDATCanIsMsgNotLostICUCMD1_0x160 (mDATCplReadAppTrameReceived(ICUCMD1_0x160))
#define mDATCanIsMsgNotLostBCM_4_0x392 (mDATCplReadAppTrameReceived(BCM_4_0x392))
#define mDATCanIsMsgNotLostRLDCM_1_0x3AE (mDATCplReadAppTrameReceived(RLDCM_1_0x3AE))
#define mDATCanIsMsgNotLostRCM_1_0x2D1 (mDATCplReadAppTrameReceived(RCM_1_0x2D1))
#define mDATCanIsMsgNotLostFRZCU_1_0x2AB (mDATCplReadAppTrameReceived(FRZCU_1_0x2AB))
#define mDATCanIsMsgNotLostFLZCU_9_0x49D (mDATCplReadAppTrameReceived(FLZCU_9_0x49D))
#define mDATCanIsMsgNotLostFLZCU_5_0x35B (mDATCplReadAppTrameReceived(FLZCU_5_0x35B))
#define mDATCanIsMsgNotLostFLZCU_1_0x23B (mDATCplReadAppTrameReceived(FLZCU_1_0x23B))
#define mDATCanIsMsgNotLostTMS_1_0x494 (mDATCplReadAppTrameReceived(TMS_1_0x494))
#define mDATCanIsMsgNotLostRCM_3_0x2DB (mDATCplReadAppTrameReceived(RCM_3_0x2DB))
#define mDATCanIsMsgNotLostRLDCM_2_0x2C8 (mDATCplReadAppTrameReceived(RLDCM_2_0x2C8))
#define mDATCanIsMsgNotLostRLDCM_3_0x437 (mDATCplReadAppTrameReceived(RLDCM_3_0x437))
#define mDATCanIsMsgNotLostRLDRM_1_0x2E8 (mDATCplReadAppTrameReceived(RLDRM_1_0x2E8))
#define mDATCanIsMsgNotLostRRDCM_1_0x3BE (mDATCplReadAppTrameReceived(RRDCM_1_0x3BE))
#define mDATCanIsMsgNotLostRLCR_1_0x447 (mDATCplReadAppTrameReceived(RLCR_1_0x447))
#define mDATCanIsMsgNotLostRLCR_2_0x450 (mDATCplReadAppTrameReceived(RLCR_2_0x450))
#define mDATCanIsMsgNotLostICC_COM_8_0x510 (mDATCplReadAppTrameReceived(ICC_COM_8_0x510))

#define mDATCplIsMsgReceived(v)  mDATCplIsMsgReceived##v
#define mDATCplIsMsgReceivedICUCMD_0x150 (mDATCplIsMsgReceived2(ICUCMD_0x150))
#define mDATCplIsMsgReceivedICUCMD1_0x160 (mDATCplIsMsgReceived2(ICUCMD1_0x160))
#define mDATCplIsMsgReceivedBCM_4_0x392 (mDATCplIsMsgReceived2(BCM_4_0x392))
#define mDATCplIsMsgReceivedRLDCM_1_0x3AE (mDATCplIsMsgReceived2(RLDCM_1_0x3AE))
#define mDATCplIsMsgReceivedRCM_1_0x2D1 (mDATCplIsMsgReceived2(RCM_1_0x2D1))
#define mDATCplIsMsgReceivedFRZCU_1_0x2AB (mDATCplIsMsgReceived2(FRZCU_1_0x2AB))
#define mDATCplIsMsgReceivedFLZCU_9_0x49D (mDATCplIsMsgReceived2(FLZCU_9_0x49D))
#define mDATCplIsMsgReceivedFLZCU_5_0x35B (mDATCplIsMsgReceived2(FLZCU_5_0x35B))
#define mDATCplIsMsgReceivedFLZCU_1_0x23B (mDATCplIsMsgReceived2(FLZCU_1_0x23B))
#define mDATCplIsMsgReceivedTMS_1_0x494 (mDATCplIsMsgReceived2(TMS_1_0x494))
#define mDATCplIsMsgReceivedRCM_3_0x2DB (mDATCplIsMsgReceived2(RCM_3_0x2DB))
#define mDATCplIsMsgReceivedRLDCM_2_0x2C8 (mDATCplIsMsgReceived2(RLDCM_2_0x2C8))
#define mDATCplIsMsgReceivedRLDCM_3_0x437 (mDATCplIsMsgReceived2(RLDCM_3_0x437))
#define mDATCplIsMsgReceivedRLDRM_1_0x2E8 (mDATCplIsMsgReceived2(RLDRM_1_0x2E8))
#define mDATCplIsMsgReceivedRRDCM_1_0x3BE (mDATCplIsMsgReceived2(RRDCM_1_0x3BE))
#define mDATCplIsMsgReceivedRLCR_1_0x447 (mDATCplIsMsgReceived2(RLCR_1_0x447))
#define mDATCplIsMsgReceivedRLCR_2_0x450 (mDATCplIsMsgReceived2(RLCR_2_0x450))
#define mDATCplIsMsgReceivedICC_COM_8_0x510 (mDATCplIsMsgReceived2(ICC_COM_8_0x510))

#define mDATCplIsMsgReceived2(FrameName)                 \
 (mDATCplIsSetFlag(DATCplTableMsgReceivedFlg, cDATCdlD_UURxHandle##FrameName))

#define mDATCplReadAppTrameReceived(FrameName)                 \
 (mDATCplIsSetFlag(DATCplTableTramesPresentes2nd, cDATCdlD_UURxHandle##FrameName))

#define mDATCpClearAppTrameReceived(FrameName)                 \
 (mDATCplClearFlag(DATCplTableTramesPresentes2nd, cDATCdlD_UURxHandle##FrameName))


//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

//LAP presentation buffer
typedef		tDATCplBuffersRx	tDATCplpBuffersRx;



//------------------------------------------------------------------------------
// Exported data
//
// extern  tType   u8LAYCmpVariableName;
// extern  tType*  ps32LAYCmpVariableName; 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constant exported data
//
// extern const tType  s8LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
extern	BOOL	DatCplNoMsgToClusterOnCANBus(void);


#endif

