/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE
*   This software is the property of Chery Technologies. Any information contained in this
*   doc should not be reproduced, or used, or disclosed without the written authorization from
*   HiRain Technologies.
************************************************************************************************
*   File Name       : DAT_PAN.h
************************************************************************************************
*   Project/Product :
*   Title           :
*   Author          :
************************************************************************************************
*   Description     : This file is used to implement the callback function.
*
************************************************************************************************
*   Limitations     :
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#                    Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*   1.0         2024/1/1      zhaojiangbo     N/A                    Original
*   1.1         2025/10/28    Na.hu           N/A                    修改PAN的文件格式
************************************************************************************************
* END_FILE_HDR*/
#ifndef I_DAT_PAN_H
#define I_DAT_PAN_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_PAN_CFG.h"
#include "DAT_PAN_INCLUDE.h"
#include "DAT_PANx.h"
#else
#include "DAT_PAN_INCLUDE.h"
#include "DAT_PAN_CFG.h"
#include ".\..\..\..\SCC2Gen\GEN\DAT_PANx.h"
#endif

//------------------------------------------------------------------------------
// Data prefix for constant & data: see coding guideline
//
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Exported type
//
// typedef Expression tLAYCmpTypeName;
//------------------------------------------------------------------------------

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
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------
#define mDATPanReadU8Bit(Frame, Byte, Bit, BitSize, TypeTraitement) \
                                    (mDATPanReadU8Bit##TypeTraitement((Byte)))

#define mDATPanReadU8BitImmediate(Channel)  (mDATAnaGetValue((Channel)))

#define mDATPanReadU8BitDelayed(Channel)    (mDATAnaGetFilteredValue((Channel)))

#define mDATPanReadU8BitDefault(Channel)    (mDATAnaGetFilteredValue((Channel)))


#define mDATPanReadU16Bit(Trame, Word, Bit, BitSize, TypeTraitement) \
                                    (mDATPanReadU16Bit##TypeTraitement((Word)))

#define mDATPanReadU16BitImmediate(BytePos)  (mDATAnaGetValue((BytePos)/2U))

#define mDATPanReadU16BitDelayed(BytePos)   (mDATAnaGetFilteredValue((BytePos)/2U))

#define mDATPanReadU16BitDefault(BytePos)   (mDATAnaGetFilteredValue((BytePos)/2))

//===========================================================================


//------------------------------------------------------------------------------
// Exported functions
//
// extern tReturnType LAYCmpFunctionName(tTypeArgument1 ArgumentName1, ... );
//------------------------------------------------------------------------------
//DATPan
extern  void    DATPanInit(void);
extern  void    DATPanStart(void);
extern  void    DATPanStop(void);
extern  void    DATPanTask(void);
extern  void    DATPanRefresh(void);

#endif   /* I_DAT_PAN_H */

