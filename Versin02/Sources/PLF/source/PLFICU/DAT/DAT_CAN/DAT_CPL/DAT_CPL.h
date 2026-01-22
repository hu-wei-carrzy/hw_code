

#ifndef I_DAT_CPL_H
#define I_DAT_CPL_H

//------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//
// #include <system_file_name.h>
// #include "project_file_name.h"
//------------------------------------------------------------------------------
#include "ARCH_CFG.h"


#include "DAT_CPL_INCLUDE.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_CDL.h"
#include "DAT_CNL.h"
#include "DAT_CIL.h"
#if defined(Coverity_Not_Kill_Recursive_Include)
#include "DAT_CNM.h"
#endif

#else
#include ".\..\DAT_CDL\DAT_CDL.h"
#include ".\..\DAT_CNL\DAT_CNL.h"
#include ".\..\DAT_CIL\DAT_CIL.h"
#if defined(Coverity_Not_Kill_Recursive_Include)
#include ".\..\DAT_CNM\DAT_CNM.h"
#endif

#endif

#include "DAT_CPL_CFG.h"



//#define Debug_Output_By_Can
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

//------------------------------------------------------------------------------
// Exported Macros
//
// #define LAYCmpMacroName(...)   (MacroDefinition)
//------------------------------------------------------------------------------

// ---------------------------------------------------
//      Macros used by DAT_CPLx.H
// ---------------------------------------------------
// These macro uses the second level macro

#define mDATCplReadBuffer( NomTrame, Octet , Index, Acces )\
        mDATCplReadBuffer##Acces( NomTrame, Octet , Index )
#define mDATCplWriteBuffer( NomTrame, Octet , Index, Val, Acces )\
        mDATCplWriteBuffer##Acces( NomTrame, Octet , Index, Val )

#define mDATCplWriteU32Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces ) \
    mDATCplWriteU32Bit##Acces( NomTrame, Octet , Bit, TailleBit, Val)
#define mDATCplReadU32Bit( NomTrame, Octet , Bit, TailleBit, Acces )   \
    mDATCplReadU32Bit##Acces( NomTrame, Octet , Bit, TailleBit)

#define mDATCplWriteU16Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces ) \
    mDATCplWriteU16Bit##Acces( NomTrame, Octet , Bit, TailleBit, Val)
#define mDATCplReadU16Bit( NomTrame, Octet , Bit, TailleBit, Acces )   \
    mDATCplReadU16Bit##Acces( NomTrame, Octet , Bit, TailleBit)

#define mDATCplWriteU8Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces )  \
    mDATCplWriteU8Bit##Acces( NomTrame, Octet , Bit, TailleBit, Val)
#define mDATCplReadU8Bit( NomTrame, Octet , Bit, TailleBit, Acces )    \
    mDATCplReadU8Bit##Acces( NomTrame, Octet , Bit, TailleBit )

#define mDATCplWriteU1Bit( NomTrame, Octet , Bit, Val, Acces )             \
    mDATCplWriteU1Bit##Acces( NomTrame, Octet , Bit, Val)
#define mDATCplReadU1Bit( NomTrame, Octet , Bit, Acces )               \
    mDATCplReadU1Bit##Acces( NomTrame, Octet , Bit)


// Signed types
#define mDATCplWriteS8Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces )  \
    mDATCplWriteU8Bit##Acces( NomTrame, Octet , Bit, TailleBit, ((U8)Val))
#define mDATCplReadS8Bit( NomTrame, Octet , Bit, TailleBit, Acces )    \
    (S8)mDATCplReadU8Bit##Acces( NomTrame, Octet , Bit, TailleBit )

#define mDATCplWriteS16Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces ) \
    mDATCplWriteU16Bit( NomTrame, Octet , Bit, TailleBit, ((U16)Val), Acces )
#define mDATCplReadS16Bit( NomTrame, Octet , Bit, TailleBit, Acces )   \
    (S16)mDATCplReadU16Bit( NomTrame, Octet , Bit, TailleBit, Acces )

#define mDATCplWriteS32Bit( NomTrame, Octet , Bit, TailleBit, Val, Acces ) \
    mDATCplWriteU32Bit( NomTrame, Octet , Bit, TailleBit, ((U32)Val), Acces )
#define mDATCplReadS32Bit( NomTrame, Octet , Bit, TailleBit, Acces )   \
    (S32)mDATCplReadU32Bit( NomTrame, Octet , Bit, TailleBit, Acces )


// -------------------------------------------
//           Second level macros
//           These macro use yhe third level macro
// -------------------------------------------
// Read / Write U1Bit

#define mDATCplWriteU1BitDelayed( NomTrame, Octet , Bit, Val)   \
    {                                                           \
        if( Val )                                               \
        {                                                       \
            mDATCplGetBuffer(NomTrame)[Octet] |= (1<<(Bit));    \
        }                                                       \
        else                                                    \
        {                                                       \
            mDATCplGetBuffer(NomTrame)[Octet] &= ~(1<<(Bit));   \
        }                                                       \
    }

#define mDATCplWriteU1BitImmediate( NomTrame, Octet , Bit, Val) \
    {                                                           \
        if( mDATCplReadU1BitDelayed(NomTrame,Octet,Bit) != Val )\
        {                                                       \
        mDATCplWriteU1BitDelayed(NomTrame, Octet , Bit, Val)    \
        mDATCplSendMessage(NomTrame);                           \
        }                                                       \
    }

#define mDATCplReadU1BitDelayed( NomTrame, Octet , Bit)    \
    ((BOOL)( (((U8)mDATCplGetBuffer(NomTrame)[Octet]) & ((U8)(1<<(Bit))) ) != 0 ))


// ----------------------------------
// Read / Write U8Bit

#define mDATCplDec8( Bit, TailleBit )   (U8)((Bit)+1-(TailleBit))
#define mDATCplMask8( Bit, TailleBit )     (U8)((1<<TailleBit) -1) 

#define mDATCplWriteU8BitDelayed( FrameName, Byte , Bit, BitSize, Val)       \
    {                                                                        \
        /* Check the data don't overflow its max value */                    \
        mLIBassert( ( (Val) & ~mDATCplMask8( Bit, BitSize ) ) == 0 );        \
        /* In the frame, delete the data bits */                             \
        mDATCplGetBuffer(FrameName)[Byte] = (U8)(                            \
        ((U8)(  mDATCplGetBuffer(FrameName)[Byte]                            \
         &((U8)(  ~(mDATCplMask8(Bit,BitSize) << mDATCplDec8(Bit,BitSize)))) \
        ))                                                                   \
        /* Set the data bits */                                              \
        |((U8)((Val) << mDATCplDec8( Bit, BitSize ))));                      \
    }

#define mDATCplWriteU8BitImmediate( NomTrame, Octet , Bit, TailleBit, Val)  \
    {                                                                       \
        if( mDATCplReadU8BitDelayed(NomTrame,Octet,Bit,TailleBit) != Val )  \
        {                                                                   \
        mDATCplWriteU8BitDelayed(NomTrame, Octet , Bit, TailleBit, Val);    \
        mDATCplSendMessage(NomTrame);                                       \
        }                                                                   \
    }

#define mDATCplReadU8BitDelayed( NomTrame, Octet , Bit, TailleBit)          \
    ( ( mDATCplGetBuffer(NomTrame)[Octet] >>                                \
        mDATCplDec8( Bit, TailleBit )        ) &                            \
        mDATCplMask8(Bit,TailleBit)               )

// ----------------------------------
// Read / Write U16Bit

#define mDATCplWriteU16BitDelayed( NomTrame, Octet , Bit, TailleBit, Val)  \
    {                                                                       \
        mLIBassert( (TailleBit) == 16 );                                    \
        mLIBassert( (Bit) == 7 );                                           \
                                                                            \
        mDATCplGetBuffer(NomTrame)[Octet]   = (U8)((Val) >> 8);         \
        mDATCplGetBuffer(NomTrame)[Octet+1] = (U8)((Val) &  0xFF);      \
    }

#define mDATCplWriteU16BitImmediate( NomTrame, Octet , Bit, TailleBit, Val) \
    {                                                                       \
        mDATCplWriteU16BitDelayed(NomTrame, Octet , Bit, TailleBit, Val);   \
        mDATCplSendMessage(NomTrame);                                       \
    }

#define mDATCplReadU16BitDelayed( NomTrame, Octet , Bit, TailleBit ) \
  (U16)(((U16)mDATCplGetBuffer(NomTrame)[Octet  ] << 8 ) +           \
            ((U16)mDATCplGetBuffer(NomTrame)[Octet+1]      )   )

// ----------------------------------
// Read / Write U32Bit

#define mDATCplWriteU32BitDelayed( FrameName, Byte , Bit, BitSize, Val)     \
    {                                                                       \
        mLIBassert( (BitSize) == 32 || (BitSize) == 24);                    \
        mLIBassert( (Bit) == 7 );                                           \
        if ( (BitSize) == 24 )                                              \
        {                                                                   \
           mDATCplGetBuffer(FrameName)[Byte+2] = (U8)((Val) & 0xFF);        \
           mDATCplGetBuffer(FrameName)[Byte+1] = (U8)(((Val)>>8) & 0xFF);   \
           mDATCplGetBuffer(FrameName)[Byte]   = (U8)(((Val)>>16) & 0xFF);  \
        }                                                                   \
        else                                                                \
        {                                                                   \
            mDATCplGetBuffer(FrameName)[Byte]   = (U8)(((Val)>>24)       ); \
            mDATCplGetBuffer(FrameName)[Byte+1] = (U8)(((Val)>>16) & 0xFF); \
            mDATCplGetBuffer(FrameName)[Byte+2] = (U8)(((Val)>> 8) & 0xFF); \
            mDATCplGetBuffer(FrameName)[Byte+3] = (U8)(((Val)    ) & 0xFF); \
        }                                                                   \
    }

#define mDATCplWriteU32BitImmediate( NomTrame, Octet , Bit, TailleBit, Val) \
    {                                                                       \
        mDATCplWriteU32BitDelayed(NomTrame, Octet , Bit, TailleBit, Val);   \
        mDATCplSendMessage(NomTrame);                                       \
    }

#define mDATCplReadU32BitDelayed( FrameName, Byte , Bit, BitSize )  \
        mDATCplReadU32BitDelayed2( FrameName, Byte , Bit, BitSize )

#define mDATCplReadU32BitDelayed2( FrameName, Byte , Bit, BitSize ) \
    mDATCplReadU32BitDelayed_##BitSize##Bit( FrameName, Byte)

// Only for BitSize = 24 and BitPosition = 7
#define mDATCplReadU32BitDelayed_247( FrameName, Byte)                  \
            (U32)(((U32)mDATCplGetBuffer(FrameName) [Byte  ] << 16 ) +  \
            ((U32)mDATCplGetBuffer(FrameName)       [Byte+1] <<  8 ) +  \
            ((U32)mDATCplGetBuffer(FrameName)       [Byte+2]       ))

// Only for BitSize = 32 and BitPosition = 7
#define mDATCplReadU32BitDelayed_327( FrameName, Byte)                  \
            (U32)(((U32)mDATCplGetBuffer(FrameName) [Byte  ] << 24 ) +  \
            ((U32)mDATCplGetBuffer(FrameName)       [Byte+1] << 16 ) +  \
            ((U32)mDATCplGetBuffer(FrameName)       [Byte+2] <<  8 ) +  \
            ((U32)mDATCplGetBuffer(FrameName)       [Byte+3]       ))

// ----------------------------------
// Read / Write Table

#define mDATCplWriteBufferDelayed( NomTrame, Octet , Index, Val )  \
    {                                                              \
        mDATCplGetBuffer(NomTrame)[Octet+Index] = Val;             \
    }

#define mDATCplWriteBufferImmediate( NomTrame, Octet , Index, Val ) \
    {                                                               \
        mDATCplWriteBufferDelayed( NomTrame, Octet , Index, Val );  \
        mDATCplSendMessage(NomTrame);                               \
    }

#define mDATCplReadBufferDelayed( NomTrame, Octet , Index ) \
    ( mDATCplGetBuffer(NomTrame)[Octet+Index] )


#define mSERControlPeriodTxEnable(FrameName)\
        ( mDATCplSetFlag(DATCplPeriodTxFlag, cDATCdlD_UUTxHandle##FrameName))

#define mSERControlPeriodTxDisable(FrameName)\
        ( mDATCplClearFlag(DATCplPeriodTxFlag,cDATCdlD_UUTxHandle##FrameName))

#define mSERControlTrigTxEnable(FrameName)  \
    ( mDATCplSetFlag(DATCplTrigTxFlag, cDATCdlD_UUTxHandle##FrameName))
#define mSERControlTrigTxDisable(FrameName)  \
    ( mDATCplClearFlag(DATCplTrigTxFlag,cDATCdlD_UUTxHandle##FrameName))


#define mDATCplReadTrameReceived(FrameName)                 \
 (mDATCplIsSetFlag(DATCplTableTramesPresentes, cDATCdlD_UURxHandle##FrameName))

#define mDATCpClearTrameReceived(FrameName)                 \
 (mDATCplClearFlag(DATCplTableTramesPresentes, cDATCdlD_UURxHandle##FrameName))

// ----------------------------------

//Macros for the diag message access
#define mSERReadStructMsgDiagLAPDiaResponseDefault(pDestination)\
        mLIBmemcpy(pDestination, &ImageDiagnosticMessage, sizeof(tMsgDiag))

//"cDATCnlN_USHandleDiagP2P_0x18DAE7F9" can be replace in function of the project parameterization
// for the name of the USDT message for the response diag
#define mSERWriteStructMsgDiagLAPDiaResponseDefault(pSource)\
        mDATCnlLngHandle(cDATCnlN_USHandleDiagP2P_0x18DAE7F9) = *(pSource.Length);\
        mLIBmemcpy(DATCnlTableROM[cDATCnlN_USHandleDiagP2P_0x18DAE7F9].pBuffer, pSource.Buffer, *(pSource.Length))

// Frame transmission
#define mSERControlCANEmission(NomTrame)                \
         DATCilSendMessage( cDATCilI_TxHandle##NomTrame )

//  -------------------------------------------
//              Third level Macros
//  -------------------------------------------
//These macro use the DAT_CIL API

#define  mDATCplGetBuffer(NomTrame)              \
        mDATCplGetBuffer##NomTrame()

#define mDATCplGetBufferImageEmission(NomTrame ) \
    mDATCplGetBufferImageEmission##NomTrame()

#define mDATCplGetBufferMaskDiag(NomTrame)       \
    mDATCplGetBufferMaskDiag##NomTrame()

#define  mDATCplSendMessage(NomTrame)            \
        DATCilSendMessage(  cDATCilI_TxHandle##NomTrame  )


//  -------------------------------------------
//Access macro for bit operation on Tab flag
//  -------------------------------------------

#define mDATCplSetFlag(Tab, Handle)\
        Tab[ ((U8)Handle>>3)] |= (((U8)1)<<( (U8)(Handle & (U8)0x07)))

#define mDATCplClearFlag(Tab, Handle)\
        Tab[ ((U8)Handle>>3)] &= ~(((U8)1)<<( (U8)(Handle & (U8)0x07)))

#define mDATCplIsSetFlag(Tab, Handle)\
        ((BOOL)(Tab[ ((U8)Handle>>3)] & (((U8)1)<<( (U8)(Handle & (U8)0x07)))) != 0)

#define mDATCplIsClearFlag(Tab, Handle)\
        ((BOOL)(Tab[ ((U8)Handle>>3)] & (((U8)1)<<( (U8)(Handle & (U8)0x07)))) == 0)

#define mDATCplClearAllFlag(Tab)        \
        mLIBmemset(Tab, 0, sizeof(Tab))

#define mDATCplSetAllFlag(Tab)        \
        mLIBmemset(Tab, 0xFF, sizeof(Tab))

#define cDATCplTxFlagLength (U8)((cDATCdl_NbUUTx-1)/8 + 1)
#define cDATCplRxFlagLength (U8)((cDATCdl_NbUURx-1)/8 + 1)

#define cCanInvalidFrameAddress     ((tAddress) 0xFFFFU)

#define mSERReadtAddressReceivedNmFrameAddressDefault()   (DATCplGetRxNmFrameAddress())
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
extern U8 DATCplPeriodTxFlag[cDATCplTxFlagLength];
extern U8 DATCplTrigTxFlag[cDATCplTxFlagLength];
extern U8 DATCplTableTramesPresentes[cDATCplRxFlagLength];
extern U8 DATCplTableTramesPresentes2nd[cDATCplRxFlagLength];
extern U8 DATCplTableMsgReceivedFlg[cDATCplRxFlagLength];
extern tDATCplpBuffersRx  DATCplImageBuffersReception;

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

#ifdef M_MULTIBUS_CAN
//typedef tDATCdlIdCanalCan tDATCilIdCanalCan;//add by zjb
extern void DATCpl_P_Init(tDATCilIdCanalCan IdCanalCan);
#else
extern void DATCpl_P_Init(void);
#endif
#ifdef M_MULTIBUS_CAN
extern void DATCpl_P_Stop(tDATCilIdCanalCan IdCanalCan);
#else
void DATCpl_P_Stop(void);
#endif
extern void DATCplInit(void);
extern void DATCplTick(void);
extern tAddress DATCplGetRxNmFrameAddress(void);


#endif

