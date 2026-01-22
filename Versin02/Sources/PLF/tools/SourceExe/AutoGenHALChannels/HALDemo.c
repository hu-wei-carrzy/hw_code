

//------------------------------------------------------------------------------
// Body Identification
//------------------------------------------------------------------------------

#define HAL   "HAL"

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "HAL.h"

//------------------------------------------------------------------------------
// Local constants
//
// #define cConstantName   ((tType) ConstantValue)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Local macros
//
// #define mMacroName   (MacroDefinition)
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------
// Constant local data
//
// static const tType  VariableName;
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------
// Local function prototypes
// 
// static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------

//==============================================================================
//=========================== LOCAL FUNCTIONS ==================================
//==============================================================================

//==============================================================================
//=========================== EXPORTED FUNCTIONS ===============================
//==============================================================================

//==============================================================================
// DESCRIPTION : Init of the LDB layer
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBInit(void)
{
    LDBSupPreInit();

	LDBInitContent

	LDBSupEndInit();
}

//==============================================================================
// DESCRIPTION : enter in sleep mode
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBEnterSleepMode(void)
{
  LDBEnterSleepModeContent
  LDBSupEnterSleepMode();
}

//==============================================================================
// DESCRIPTION : Leave sleep mode
//
// PARAMETERS (Type,Name,Min,Max) :   none
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBLeaveSleepMode(void)
{
  LDBSupLeaveSleepMode();
  LDBLeaveSleepModeContent
}


//==============================================================================
// DESCRIPTION : Switching of the send with address access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Addr: Start address of the data to write
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSendWithAddr (tChannel Channel, tAddress Addr, tMsg *pMsg )
{
    switch (Channel)
    {
	
	LDBSendWithAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the prepare to send with address access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Addr: Start address of the data to write
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBPrepareSendWithAddr (tChannel Channel, tAddress Addr, tMsg *pMsg )
{
    switch (Channel)
    {
	
	LDBPrepareSendWithAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the send without address access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBSendWithoutAddr (tChannel Channel, tMsg *pMsg )
{
    switch (Channel)
    {
	
	LDBSendWithoutAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the prepare to send without address access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBPrepareSendWithoutAddr(tChannel Channel, tMsg* pMsg)
{
    switch (Channel)
    {
		
	LDBPrepareSendWithoutAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the received with address access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Addr: Start address of the data to write
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBReceiveWithAddr(tChannel Channel, tAddress Addr, tMsg *pMsg)
{
    switch (Channel)
    {

	LDBReceiveWithAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the received without address access
//
// PARAMETERS (Type,Name,Min,Max) :   none
//      - Channel: Channel identifier
//      - *pMsg: datas buffer
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBReceiveWithoutAddr(tChannel Channel, tMsg *pMsg)
{
    switch (Channel)
    {

	LDBReceiveWithoutAddrContent
	
    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the control access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBControl (tChannel Channel, tCtrl Ctrl)
{
    switch (Channel)
    {

	LDBControlContent

    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the callback authorize access
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - CallBackAutorise: Ctrue or cFalse
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBEnableCallBack (tChannel Channel, BOOL CallBackAuthorize )
{
    switch (Channel)
    {

    LDBEnableCallBackContent

    default :
        mLIBassert(cFalse);
        break;
    }
}


//==============================================================================
// DESCRIPTION : Switching of the callback for each channel
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCallBackControl (tChannel Channel, tCtrl Ctrl, tStatus Status)
{
    switch (Channel)
    {

    LDBCallBackControlContent

    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the callback end for each channel
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCallBackEndControl (tChannel Channel, tCtrl Ctrl, tStatus Status)
{
    switch (Channel)
    {

    LDBCallBackEndControlContent

    default :
        mLIBassert(cFalse);
        break;
    }
}
//==============================================================================
// DESCRIPTION : Switching of the callback for each channel,for Rx 
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCallBackRxWithAddr (tChannel Channel, tAddress Addr, tStatus Status)
{
    switch (Channel)
    {

    LDBCallBackRxWithAddrContent

    default :
        mLIBassert(cFalse);
        break;
    }
}

//==============================================================================
// DESCRIPTION : Switching of the callback for each channel,for Tx
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCallBackTxWithAddr (tChannel Channel, tAddress Addr, tStatus Status)
{
    switch (Channel)
    {

    LDBCallBackTxWithAddrContent

    default :
        mLIBassert(cFalse);
        break;
    }
}


//==============================================================================
// DESCRIPTION : callback from Irq for each channel
//
// PARAMETERS (Type,Name,Min,Max) :
//      - Channel: Channel identifier
//      - Ctrl: Control type
//
// RETURN VALUE :   none
//
// DESIGN INFORMATION : (pseudo code, algorithm ... )
//==============================================================================
void LDBCallBackFromIrqWithAddr (tChannel Channel, tAddress Addr, tStatus Status)
{
    switch (Channel)
    {

    LDBCallBackFromIrqWithAddrContent

    default :
        mLIBassert(cFalse);
        break;
    }
}




