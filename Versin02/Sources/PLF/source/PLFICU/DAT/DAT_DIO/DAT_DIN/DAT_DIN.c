//******************************************************************************
// Copyright:    This software is JYD property.
//               Duplication or disclosure without JYD written authorization
//               is prohibited.
// -----------------------------------------------------------------------------
// Project:      BCM313
// Language:     C
// -----------------------------------------------------------------------------
// Component:  sample the active line inputs to maintain the system active
// -----------------------------------------------------------------------------
//******************************************************************************
// This line is used to separate code and file header.This is begin.
//*****************************BEGIN_NOMOVE*************************************
// Time:2016-08-31 09:24:09
// 1: add code to sample the active line inputs after power lock release
// 2:

//*****************************END_NOMOVE***************************************
// This line is used to separate code and file header. This is last line.
//******************************************************************************

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------
#define dat_Din  "dat_Din"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------

#include "dat_Din.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

#if (defined(DATDIN_FAST_FILTER_X3) || defined(DATDIN_FAST_FILTER_X5))

#if( cDATDinWordNbrToFilterInNormalModeNonType > 1UL )
#define SeveralWordToFilter
#endif

#endif


//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

// the byte ByteNbr of the buffer BufferNbr of the SampleBuffers array
#define mFilteredBuffer()    (DATDinInputBuffers.Filtered)
#define mNonFilteredBuffer() (DATDinInputBuffers.NonFiltered)
#define mStateChangeBuffer() (DATDinInputBuffers.StateChange)

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
#ifndef M_DEBUG
    static tDATDinState     State;
    #ifndef DATDIN_FAST_FILTER_X3
        #ifndef DATDIN_FAST_FILTER_X5
            static U8 CptArray [cDATDinLastBitPosInNominalMode+1];
        #else
        static tDATDinWord Memo1[cDATDinWordNbrToFilterInNormalMode];
        static tDATDinWord Memo2[cDATDinWordNbrToFilterInNormalMode];
        static tDATDinWord Memo3[cDATDinWordNbrToFilterInNormalMode];
        static tDATDinWord Memo4[cDATDinWordNbrToFilterInNormalMode];
        static tDATDinWord Memo5[cDATDinWordNbrToFilterInNormalMode];
        #endif
    #else
        static tDATDinWord B0[cDATDinWordNbrToFilterInNormalMode];
        static tDATDinWord B1[cDATDinWordNbrToFilterInNormalMode];
    #endif
#else
    // for unitary test
    tDATDinState     State;
    #ifndef DATDIN_FAST_FILTER_X3
        #ifndef DATDIN_FAST_FILTER_X5
        U8 CptArray [cDATDinLastBitPosInNominalMode+1];
        #else
        tDATDinWord Memo1[cDATDinWordNbrToFilterInNormalMode];
        tDATDinWord Memo2[cDATDinWordNbrToFilterInNormalMode];
        tDATDinWord Memo3[cDATDinWordNbrToFilterInNormalMode];
        tDATDinWord Memo4[cDATDinWordNbrToFilterInNormalMode];
        tDATDinWord Memo5[cDATDinWordNbrToFilterInNormalMode];
        #endif
    #else
        tDATDinWord B0[cDATDinWordNbrToFilterInNormalMode];
        tDATDinWord B1[cDATDinWordNbrToFilterInNormalMode];
    #endif
#endif

static tTOSAlarm  PeriodicAlarm; // the periodic alarm


static tMsg       InputMsg;

#ifdef WAKE_BY_DIN

#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    #if(defined(DATDIN_FAST_FILTER_X3)||defined(DATDIN_FAST_FILTER_X5))
    #ifdef SeveralWordToFilter
        static U8  NumberOfWordToFilter;
    #endif
    #else
        static U8  PositionOfLastLogicalInput;
    #endif

#endif
#endif

// Time: 2016-08-30 18:38:51
static BOOL sbIsEnterSleeped;

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------
#ifndef DATDIN_FAST_FILTER_X3
#ifndef DATDIN_FAST_FILTER_X5
static const U8 CptHigherLimit[cDATDinLastBitPosInNominalMode+1] = mDATDinInitHigherFilterValue();
#endif
#endif

//------------------------------------------------------------------------------
// Exported data
//
// tType   u8LAYCmpVariableName; (LAY: 3 characters to identify the layer)
// tType*  pu8LAYCmpVariableName;(Cmp: 3 characters to identify the component)
//------------------------------------------------------------------------------
tDATDinLogicalInputBuffers DATDinInputBuffers;

//------------------------------------------------------------------------------
// Constant exported data
//
//             (LAY: 3 characters to identify the layer)
//             (Cmp: 3 characters to identify this component)
// 
// const tType   LAYCmpVariableName;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

#ifdef WAKE_BY_DIN
static BOOL Filter(void);
#else
static void Filter(void);
#endif
static void DATDinWakeupAfterPowerLockRelease(void);
//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================


//============================================================================
//  DESCRIPTION : Function's objectives : update the input counter. For each 
//                logical input, we look is the sample is different as the 
//                filtered input. In this case a counter is incremented. 
//                When the counter reach a specified value. The state of the 
//                filtered input change.
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
#ifdef DATDIN_FAST_FILTER_X5

#ifdef WAKE_BY_DIN
static BOOL Filter(void)
#else
static void Filter(void)
#endif
{
    #ifdef WAKE_BY_DIN
    BOOL IsFilterNotStable = cFalse;
    #endif
    tDATDinWord Change,ConfChange;
    
    tDATDinWord Tmp1[cDATDinWordNbrToFilterInNormalMode];
    tDATDinWord Tmp2[cDATDinWordNbrToFilterInNormalMode];
    tDATDinWord Tmp3[cDATDinWordNbrToFilterInNormalMode];
    tDATDinWord Tmp4[cDATDinWordNbrToFilterInNormalMode];

    // This algorithm is faster than the classical.
    // The input bit are not filtered bit by bit 
    // but word by word.

    // Each input is linked the filter output by a boolean expression.
    // This expression use 6 state bit : Memo1..Memo5
    // MemoX represent the value of the counter (see classical filter)

    // Cpt is increase when IN != OUT
    // Cpt is decrease when IN == OUT

    // OUT state change when CPT reach 5

#ifdef SeveralWordToFilter

    U8 i;

    #ifdef WAKE_BY_DIN
    #ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    for( i=0; i < NumberOfWordToFilter ; i++ )
    #else
    for( i=0; i < cDATDinWordNbrToFilter ; i++ )
    #endif
    #else
    for( i=0; i < cDATDinWordNbrToFilterInNormalMode ; i++ )
    #endif
    {
        Change = ((tDATDinWord*)DATDinInputBuffers.Filtered)[i];
        Change ^= ((tDATDinWord*)DATDinInputBuffers.NonFiltered)[i];
        Tmp1[i]      = ~Change;
        Tmp2[i]      = (Tmp1[i] & Memo2[i]) | (Change & Memo3[i]);
        Tmp3[i]      = (Tmp1[i] & Memo1[i]) | (Change & Memo4[i]);
        ConfChange  = Change & Memo2[i];
        Tmp4[i]      = ConfChange | (Tmp1[i] & Memo5[i]) | (Memo4[i] & ((tDATDinWord)~Tmp3[i]));

        Memo4[i] = (Tmp1[i] & Memo3[i]) | (Change & Memo5[i]);
        Memo2[i] = Change & Memo1[i];
        Memo1[i] = Tmp2[i];
        Memo3[i] = Tmp3[i];
        Memo5[i] = Tmp4[i];
        
        ((tDATDinWord*)DATDinInputBuffers.StateChange)[i] = ConfChange;
        ((tDATDinWord*)DATDinInputBuffers.Filtered)[i] ^= ConfChange;

        #ifdef WAKE_BY_DIN
        if( (Memo1[i] | Memo2[i] |Memo3[i] |Memo4[i]) != 0 )
        {
            IsFilterNotStable = cTrue;
        }
        #endif
    }
#else
        Change = ((tDATDinWord*)DATDinInputBuffers.Filtered)[0];
        Change ^= ((tDATDinWord*)DATDinInputBuffers.NonFiltered)[0];
        Tmp1[0]      = ~Change;
        Tmp2[0]      = (Tmp1[0] & Memo2[0]) | (Change & Memo3[0]);
        Tmp3[0]      = (Tmp1[0] & Memo1[0]) | (Change & Memo4[0]);
        ConfChange  = Change & Memo2[0];
        Tmp4[0]      = ConfChange | (Tmp1[0] & Memo5[0]) | (Memo4[0] & ((tDATDinWord)~Tmp3[0]));

        Memo4[0] = (Tmp1[0] & Memo3[0]) | (Change & Memo5[0]);
        Memo2[0] = Change & Memo1[0];
        Memo1[0] = Tmp2[0];
        Memo3[0] = Tmp3[0];
        Memo5[0] = Tmp4[0];

        ((tDATDinWord*)DATDinInputBuffers.StateChange)[0] = ConfChange;
        ((tDATDinWord*)DATDinInputBuffers.Filtered)[0] ^= ConfChange;
        
        #ifdef WAKE_BY_DIN
        if( (Memo1[0] | Memo2[0] |Memo3[0] |Memo4[0]) != 0 )
        {
            IsFilterNotStable = cTrue;
        }
        #endif

#endif

#ifdef WAKE_BY_DIN
    return(IsFilterNotStable);
#endif
}

#else
//============================================================================
//  DESCRIPTION : Function's objectives : update the input counter. For each 
//                logical input, we look is the sample is different as the 
//                filtered input. In this case a counter is incremented. 
//                When the counter reach a specified value. The state of the 
//                filtered input change.
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
#ifdef DATDIN_FAST_FILTER_X3

#ifdef WAKE_BY_DIN
static BOOL Filter(void)
#else
static void Filter(void)
#endif
{
    #ifdef WAKE_BY_DIN
    BOOL IsFilterNotStable = cFalse;
    #endif
    tDATDinWord OldB1,Chgt;

    // This algrithm is faster than the classical.
    // The input bit are not filtered bit by bit 
    // but word by word.

    // Each input is linked the filter output by a boolean expression.
    // This expression use two state bit : B0 and B1
    // B0 and B1 represent the value of the counter (see classical filter)
    // B0=0, B1=0 => Cpt=0
    // B0=1, B1=0 => Cpt=1
    // B0=0, B1=1 => Cpt=2

    // Cpt is increase when IN != OUT
    // Cpt is decrease when IN == OUT

    // OUT state change when CPT reach 3

#ifdef SeveralWordToFilter

    U8 i;

    #ifdef WAKE_BY_DIN
    #ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    for( i=0; i < NumberOfWordToFilter ; i++ )
    #else
    for( i=0; i < cDATDinWordNbrToFilter ; i++ )
    #endif
    #else
    for( i=0; i < cDATDinWordNbrToFilterInNormalMode ; i++ )
    #endif
    {
        Chgt = ((tDATDinWord*)DATDinInputBuffers.Filtered)[i];
        Chgt ^= ((tDATDinWord*)DATDinInputBuffers.NonFiltered)[i];
        OldB1 = B1[i];
        B1[i] = B0[i] & Chgt;
        B0[i] = B1[i] ^ Chgt ^ OldB1;
        Chgt &= OldB1;
        ((tDATDinWord*)DATDinInputBuffers.StateChange)[i] = Chgt;
        ((tDATDinWord*)DATDinInputBuffers.Filtered)[i] ^= Chgt;
        
        #ifdef WAKE_BY_DIN
        if( (B0[i] | B1[i] ) != 0 )
        {
            IsFilterNotStable = cTrue;
        }
        #endif
    }
#else

    Chgt  = ((tDATDinWord*)DATDinInputBuffers.Filtered)[0U];
    Chgt ^= ((tDATDinWord*)DATDinInputBuffers.NonFiltered)[0U];
    OldB1 = B1[0U];
    B1[0U] = B0[0U] & Chgt;
    B0[0U] = B1[0U] ^ Chgt ^ OldB1;
    Chgt &= OldB1;
    ((tDATDinWord*)DATDinInputBuffers.StateChange)[0U] = Chgt;
    ((tDATDinWord*)DATDinInputBuffers.Filtered)[0U] ^= Chgt;

    #ifdef WAKE_BY_DIN
    if( (B0[0U] | B1[0U] ) != 0U )
    {
        IsFilterNotStable = cTrue;
    }
    #endif

#endif

#ifdef WAKE_BY_DIN
    return(IsFilterNotStable);
#endif
}

#else

//============================================================================
//  DESCRIPTION : Function's objectives : update the input counter. For each 
//                logical input, we look is the sample is different as the 
//                filtered input. In this case a counter is incremented. 
//                When the counter reach a specified value. The state of the 
//                filtered input change.
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
#ifdef WAKE_BY_DIN
static BOOL Filter(void)
#else
static void Filter(void)
#endif
{
    U8 Input;
    U8* pFilteredCurrentByte;
    U8* pNonFilteredCurrentByte;
    U8* pStateChangeCurrentByte;
    U8 Mask;
    U8 NbBytes;
    BOOL FilterNotStabilized;

    pFilteredCurrentByte    = DATDinInputBuffers.Filtered;
    pNonFilteredCurrentByte = DATDinInputBuffers.NonFiltered;
    pStateChangeCurrentByte = DATDinInputBuffers.StateChange;
    NbBytes=0;
    Mask = ((U8)0x01UL);
    FilterNotStabilized = cFalse;
    
    // Clear the state change buffer
    mLIBmemset(mStateChangeBuffer(), 0, cDATDinBufferSize);

    #ifdef WAKE_BY_DIN
    for (Input=0; Input <= PositionOfLastLogicalInput ; Input++)
    #else
    for (Input=0; Input <= cDATDinLastBitPosInNominalMode ; Input++)
    #endif
    { // loop for the input

        if ( (pNonFilteredCurrentByte[NbBytes] & Mask ) == (pFilteredCurrentByte[NbBytes] & Mask ) )
        {//the filtered value is the same as the non filtered
            if (CptArray[Input] > 0 )
            {
                (CptArray[Input])--;
            }
        }
        else
        {
            (CptArray[Input])++;

            if ( CptArray[Input] >= CptHigherLimit[Input] )
            {
                pFilteredCurrentByte[NbBytes] ^= Mask;
                pStateChangeCurrentByte[NbBytes] |= Mask;
                CptArray[Input] = ((U8)0x00UL);
            }
        } // if  ... Mask ...

        if (Mask == ((U8)0x80UL))
        {
            Mask = ((U8)0x01UL);
            NbBytes ++;
        }
        else
        {
            Mask <<= 1;
        }
        
        if(CptArray[Input] != 0)
        {
            FilterNotStabilized = cTrue;
        }
    }
#ifdef WAKE_BY_DIN
    return(FilterNotStabilized);
#endif
}
#endif
#endif

/*============================================================================
  DESCRIPTION : 检测电源锁释放后，如果有新的激信号，则重新激活系统

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none

  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
static void DATDinWakeupAfterPowerLockRelease(void)
{

}

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================
//============================================================================
//  DESCRIPTION : Initialise DAT_Din component
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinInit(const U8* pBuffer)
{
#ifdef DATDIN_FAST_FILTER_X5
    mLIBmemset(Memo1, 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset(Memo2, 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset(Memo3, 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset(Memo4, 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset(Memo5, ((U8)0xFFUL), cDATDinWordNbrToFilterInNormalMode);

    // Initialize unused byte of buffer
    mLIBmemset(mFilteredBuffer(), 0, cDATDinBufferSize);
    mLIBmemset(mNonFilteredBuffer(), 0, cDATDinBufferSize);
    mLIBmemset(mStateChangeBuffer(), 0, cDATDinBufferSize);
#else
#ifdef DATDIN_FAST_FILTER_X3
    (void)mLIBmemset((void*)B0, 0U, cDATDinWordNbrToFilterInNormalMode);
    (void)mLIBmemset((void*)B1, 0U, cDATDinWordNbrToFilterInNormalMode);

    // Initialize unused byte of buffer
    (void) mLIBmemset((void*)mFilteredBuffer(), 0U, cDATDinBufferSize);
    (void)mLIBmemset((void*)mNonFilteredBuffer(), 0U, cDATDinBufferSize);
    (void) mLIBmemset((void*)mStateChangeBuffer(), 0U, cDATDinBufferSize);
#else
    mLIBmemset(CptArray, 0, cDATDinLastBitPosInNominalMode);
#endif
#endif

    (void)mLIBmemcpy((void*)mFilteredBuffer(), pBuffer, cDATDinBufferUseSize);
    (void)mLIBmemcpy((void*)mNonFilteredBuffer(), pBuffer, cDATDinBufferUseSize);
    InputMsg.pBuffer = DATDinInputBuffers.NonFiltered;
    InputMsg.Lng    = cDATDinBufferUseSize;

    
    #ifdef WAKE_BY_DIN
#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    #if (defined(DATDIN_FAST_FILTER_X3) || defined(DATDIN_FAST_FILTER_X5))
    #ifdef SeveralWordToFilter
        NumberOfWordToFilter = cDATDinWordNbrToFilterInSleepMode;
    #endif
    #else
        PositionOfLastLogicalInput = cDATDinLastBitPosInSleepMode;
    #endif
#endif

    State = cDATDinConfirmWakeUpMode;
    sbIsEnterSleeped = cFalse;

    #else
    State = cDATDinStopMode;
    #endif
    if(State){}//to avoid a warning in release mode
}


#ifdef WAKE_BY_DIN
#ifndef WAKE_BY_DIN_INTERRUPT
//============================================================================
//  DESCRIPTION : Read the logical input. This task is activated 
//                periodicaly
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinReadTask(void)
{

    LDBReceiveWithAddr(cLDBChannelLDB_DIN, cLDBDIDirectInput_Addr, &InputMsg);

    // Invalidate some inputs
    DATPinSelection(); 

    switch(State)
    {
      case cDATDinSleepMode:
      {
#if 0
        // Time: 2016-08-30 18:36:31
        //在这里，FilterNotStabilized这个变量是检测四个DI输入也就是四个按键是否能稳定，如果其不稳定，也就是值
        //有变化，那么要激活系统。现在不使用四个按键激活，所以不使用这部分代码。
        BOOL FilterNotStabilized;
        U8 i;

        FilterNotStabilized = cFalse;
        //Filtering is not active
        for(i=0; i<= cDATDinLastBytePosInSleepMode; i++)
        {
          if(DATDinInputBuffers.Filtered[i] != DATDinInputBuffers.NonFiltered[i])
          {
            FilterNotStabilized = cTrue;
          }
        }

        if(FilterNotStabilized != cFalse)
        {
          TOSSendControl(cTOSControlActiveSleepRequest);
          TOSCancelAlarm(&PeriodicAlarm);
          PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
          TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));

          State = cDATDinConfirmWakeUpMode;

          Filter();
          DATPinStateChange();
        }
#endif

        // Time: 2016-08-30 18:48:26
        //如果sbIsEnterSleeped为值，表示LAPSupEnterSleep已经执行过了，且电源锁定已经释放了。
        //电源锁释放后20ms（具体时间可以配置）会运行到这里。然后开始检测是否有新的激活输入。
        if(sbIsEnterSleeped)
        {
            DATDinWakeupAfterPowerLockRelease();
        }


        break;
      }
      case cDATDinConfirmWakeUpMode :
      {


        // Time：2016-08-30 18:36:47
        //这里将这部分代码注释掉，当进入到这个状态时，表示系统准备下电，所有的激活输入都已经关闭。
        //这里直接跳转折到下一个状态,State = cDATDinSleepMode;在cDATDinSleepMode状态下检测
        //可能的新的外部激活信号.
        //Filter()这个函数是检测DI端口，也就是目前软件中的四个按键是否有信号变化，信号是否稳定，当前
        //我们是不允许按键将系统激活的，所以这里不用这个函数。
        BOOL FilterNotStabilized;
        //Filtering is active
        //DAT_DIN must not go to sleep mode before filtering counter are stabilized
        FilterNotStabilized = Filter();

        DATPinStateChange();

        State = cDATDinSleepMode;
        sbIsEnterSleeped = cFalse;

        if(FilterNotStabilized == cFalse)
        {
#if 0
            //The input change has not woke up the application and filtering is finished
            State = cDATDinSleepMode;

            TOSCancelAlarm(&PeriodicAlarm);
            PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
            TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinSleepSamplingPeriodValueMs));
#endif
        }



        break;
      }

      case cDATDinNormalMode ://nominal mode 
      {
        (void)Filter();
        DATPinStateChange();
        sbIsEnterSleeped = cFalse;
        break;
      }

      default:
            mLIBassert(cFalse);
      break;
  }
}

#else


//============================================================================
//  DESCRIPTION : Read the logical input. This task is activated 
//                periodicaly
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinReadTask(void)
{
    BOOL FilterNotStabilized;

    FilterNotStabilized = cFalse;

	switch(State)
	{
		case cDATDinSleepMode:
		{
			//IT Wake up has occured
			TOSSendControl(cTOSControlActiveSleepRequest);
			PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
			TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));

			State = cDATDinConfirmWakeUpMode;
			break;
		}

		case cDATDinConfirmWakeUpMode :
		{
			// Reading
			LDBReceiveWithoutAddr(cLDBChannelLDB_DIN, &InputMsg);

			// Invalidate some inputs
			DATPinSelection();

			//Filter
			FilterNotStabilized = Filter();

			// Inform PIN
			DATPinStateChange();

			if ((FilterNotStabilized == cFalse)
					&& (State != cDATDinNormalMode))
			{//The input change has not wake up the application and filtering is finished

				State = cDATDinSleepMode;

				TOSCancelAlarm(&PeriodicAlarm);
				//To enable input interrupt in case of a return of a confirmation state
				LDBControl(cLDBChannelLDB_DIN,cLDBDinEnableWakeUpInterrupt);
			}
			break;
		}

		case cDATDinNormalMode ://Nominal mode
		{
			// Reading
			LDBReceiveWithoutAddr(cLDBChannelLDB_DIN, &InputMsg);

			// Invalidate some inputs
			DATPinSelection();
			Filter();
			DATPinStateChange();
			break;
		}

		default:
			mLIBassert(cFalse);
			break;
	}
}

#endif
#else
//No wake up mode
//============================================================================
//  DESCRIPTION : Read the logical input. This task is activated 
//                periodicaly
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinReadTask(void)
{
	U8 u8AddrLoop = 0;
  // Reading
  //LDBReceiveWithoutAddr(cLDBChannelLDB_DIN, &InputMsg);
  for(u8AddrLoop=0;u8AddrLoop<=cDINAll_AddrNum;u8AddrLoop++)
  {
	  LDBReceiveWithAddr(cLDBChannelLDB_DIN, (tAddress)u8AddrLoop, &InputMsg);
  }

  // Invalidate some inputs
  DATPinSelection();

  Filter();

  //Inform PIN
  DATPinStateChange();

}
#endif

//============================================================================
//  DESCRIPTION : Define the call-back called by the LDB. This 
//                function is called when the On/Off input are copied
//  
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinCallBackRxWithoutAddr(tStatus Statut)
{
    mLIBassert(Statut == cLDBCorrect);

    Statut = Statut; // to avoid compiler warning on target
}


#ifdef WAKE_BY_DIN
#ifndef WAKE_BY_DIN_INTERRUPT
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in nominal mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinEnterActiveState(void)
{
#ifdef cLDBChannelLDB_DIN
	LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterNominalMode);
#endif
    TOSCancelAlarm(&PeriodicAlarm);
    PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));

    sbIsEnterSleeped = cFalse;

#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
#ifdef DATDIN_FAST_FILTER_X5
    mLIBmemset((U8*)Memo1 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize );
    mLIBmemset((U8*)Memo2 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo3 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo4 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo5 + cDATDinLastBytePosInSleepMode+1, ((U8)0xFFUL), cDATDinNormalModeInitByteSize);
    #ifdef SeveralWordToFilter
    NumberOfWordToFilter = cDATDinWordNbrToFilterInNormalMode;
    #endif
#else
    #ifdef DATDIN_FAST_FILTER_X3
        mLIBmemset(((U8*)B0) + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
        mLIBmemset(((U8*)B1) + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    #ifdef SeveralWordToFilter
        NumberOfWordToFilter = cDATDinWordNbrToFilterInNormalMode;
    #endif
    #else
        mLIBmemset(&CptArray[cDATDinLastBitPosInSleepMode+1], 0, ((U8)(cDATDinLastBitPosInNominalMode - cDATDinLastBitPosInSleepMode)));
        PositionOfLastLogicalInput = cDATDinLastBitPosInNominalMode;
    #endif
#endif
#endif

    State = cDATDinNormalMode;
}

#else
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in nominal mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinEnterActiveState(void)
{
	LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterNominalMode);

    TOSCancelAlarm(&PeriodicAlarm);
    PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));

#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
#ifdef DATDIN_FAST_FILTER_X5
    mLIBmemset((U8*)Memo1 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo2 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo3 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo4 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)Memo5 + cDATDinLastBytePosInSleepMode+1, ((U8)0xFFUL), cDATDinNormalModeInitByteSize);
    #ifdef SeveralWordToFilter
    NumberOfWordToFilter = cDATDinWordNbrToFilterInNormalMode;
    #endif
#else
#ifdef DATDIN_FAST_FILTER_X3
    mLIBmemset((U8*)B0 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    mLIBmemset((U8*)B1 + cDATDinLastBytePosInSleepMode+1, 0, cDATDinNormalModeInitByteSize);
    #ifdef SeveralWordToFilter
    NumberOfWordToFilter = cDATDinWordNbrToFilterInNormalMode;
    #endif
#else
    mLIBmemset(&CptArray[cDATDinLastBitPosInSleepMode+1], 0, cDATDinNormalModeInitByteSize);
    PositionOfLastLogicalInput = cDATDinLastBitPosInNominalMode;
#endif
#endif

#endif

    State = cDATDinNormalMode;
}
#endif
#else
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in nominal mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinEnterActiveState(void)
{
	mLIBassert(State != cDATDinNormalMode);

    LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterNominalMode);

    PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));

#ifdef DATDIN_FAST_FILTER_X5
    mLIBmemset((U8*)Memo1 , 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset((U8*)Memo2 , 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset((U8*)Memo3 , 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset((U8*)Memo4 , 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset((U8*)Memo5 , ((U8)0xFFUL), cDATDinWordNbrToFilterInNormalMode);
#else
#ifdef DATDIN_FAST_FILTER_X3
    mLIBmemset((U8*)B0, 0, cDATDinWordNbrToFilterInNormalMode);
    mLIBmemset((U8*)B1, 0, cDATDinWordNbrToFilterInNormalMode);
#else
    mLIBmemset(CptArray, 0, cDATDinLastBitPosInNominalMode);
#endif
#endif

    State = cDATDinNormalMode;
}
#endif


#ifdef WAKE_BY_DIN
#ifndef WAKE_BY_DIN_INTERRUPT
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in sleep mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinLeaveActiveState(void)
{
#ifdef cLDBChannelLDB_DIN
	LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterSleepMode);
#endif

    //The counter must decrease before going into sleep mode
    State = cDATDinConfirmWakeUpMode;
    sbIsEnterSleeped = cFalse;

#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    #if (defined(DATDIN_FAST_FILTER_X3)||defined(DATDIN_FAST_FILTER_X5))
    #ifdef SeveralWordToFilter
        NumberOfWordToFilter = cDATDinWordNbrToFilterInSleepMode;
    #endif
    #else
        PositionOfLastLogicalInput = cDATDinLastBitPosInSleepMode;
    #endif
#endif
}
#else
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in sleep mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinLeaveActiveState(void)
{
	LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterSleepMode);
    //The counter must decrease before going into sleep mode
    State = cDATDinConfirmWakeUpMode;

#ifndef DATDIN_SAME_SLEEP_AND_NORMAL_INPUT
    #if (defined(DATDIN_FAST_FILTER_X3)||defined(DATDIN_FAST_FILTER_X5))
    #ifdef SeveralWordToFilter
        NumberOfWordToFilter = cDATDinWordNbrToFilterInSleepMode;
    #endif
    #else
        PositionOfLastLogicalInput = cDATDinLastBitPosInSleepMode;
    #endif
#endif
}
#endif
#else
//============================================================================
//  DESCRIPTION : Put the DAT_DIN in sleep mode
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinLeaveActiveState(void)
{
	TOSCancelAlarm(&PeriodicAlarm);

    State = cDATDinStopMode;

    LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterSleepMode);
}
#endif

#ifdef WAKE_BY_DIN
#ifndef WAKE_BY_DIN_INTERRUPT
//============================================================================
//  DESCRIPTION : Start DAT_DIN
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinLeaveStartingStepState(void)
{
    //To permit to the input to be stabilized before going into sleep mode,
    //and avoid to miss a wake up condition
    PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinSleepSamplingPeriodValueMs));
}
#else
/*============================================================================
  DESCRIPTION : Start DAT_DIN

  PARAMETERS (Type,Name,Min,Max) :  none

  RETURN VALUE :  none
 
  DESIGN INFORMATION :  refer to Detailed Design Document
============================================================================*/
void DATDinLeaveStartingStepState(void)
{
    //To permit to the input to be stabilized before going into sleep mode,
    //and avoid to miss a wake up condition (IT are not authorized)
    PeriodicAlarm.TaskID = cTOSTaskID_ReadLogical;
    TOSSetRelAlarm(&PeriodicAlarm, 0, mTOSConvMsEnTickAlarm(cDATDinNominalSamplingPeriodValueMs));
}
#endif
#else
//============================================================================
//  DESCRIPTION : Start DAT_DIN
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinLeaveStartingStepState(void)
{
    State = cDATDinStopMode;
    LDBControl(cLDBChannelLDB_DIN,cLDBDinEnterSleepMode);
}
#endif

//============================================================================
//  DESCRIPTION : CallBack from the LDB layer after a DAT control
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinCallBackEndCtrl(tCtrl Ctrl, tStatus Statut)
{
    mLIBassert(Statut==cLDBCorrect);
    Statut = Statut;  // pour eviter un warning a la compilation sur cible
    Ctrl = Ctrl;      // pour eviter un warning a la compilation sur cible

}

//============================================================================
//  DESCRIPTION : Spontanous callback from the LDB (Interrupt context)
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinCallBackCtrl(tCtrl Ctrl,tStatus Status)
{
	//唤醒DIO读取任务，看看是否是真正的
    TOSActivateTask(cTOSTaskID_ReadLogical);

    Ctrl = Ctrl;
    Status = Status;

}

//============================================================================
//  DESCRIPTION : Maintain the application in active sleep state if need
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
// 
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================
void DATDinMaintainActiveSleepState(void)
{
#if 0	//TODO:XXX
#ifdef WAKE_BY_DIN
    if(State == cDATDinConfirmWakeUpMode)
    {
        TOSWriteSignal(cTOSSignalSomebodyMaintainActiveSleepState);
    }
#endif
#endif
}

//============================================================================
//  DESCRIPTION : LAP_SUP enter-sleep action has done, just notify this model.
//
//  PARAMETERS (Type,Name,Min,Max) :  none
//
//  RETURN VALUE :  none
//
//  DESIGN INFORMATION :  refer to Detailed Design Document
//============================================================================

void DATDinEnterSleep(void)
{
    sbIsEnterSleeped = cTrue;
}

/* 关闭VCC_SW开关 */
void DATDinWillEnterSleep(void)
{
//	BSPOutputCtr(OUT_VCC_SW_CTRL, TurnON);
}

/* 打开VCC_SW开关 */
void DATDinWillLeaveSleep(void)
{
//	BSPOutputCtr(OUT_VCC_SW_CTRL, TurnOFF);
}
