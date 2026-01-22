/*============================================================================
  Project ......................... COMMON
  Component ....................... DAT_PEE
  File revision.................... :   1.3  $
  Last modification date .......... $Modtime:   Jan 31 2013 09:46:32  $
  -------------------------------------------------------------------------
  Copyright ... This software is JYD property. Duplication or
                disclosure is prohibited without JYD written permission
  ------------------------------------------------------------------------- 
    
  - This file should only contain data useful to the programmer to use
    this comp                   CONFIG_LIN_Slave_M16C_SCC2\$(SIMU_EXE)
onent
  - Component exported macros, constants and types are defined in this file
  - Component exported variables and functions are declared in this file 
    with the "extern" keyword
  
  -------------------------------------------------------------------------
  DAT_PEE.h file review :
  
    :   P:/STANDARD/AEH/STK/PVCS/archives/STK/CMP/SOURCES/DAT/EEP/DAT_PEE/Dat_pee.h-arc  $
 * 
 *    Rev 1.3   Aug 05 2003 13:31:18   abarbae
 * PON URD42 BODY_SW 239 :  Ajouter un outil de selection de configuration au Starter-Kit .
 * 
 *    Rev 1.2   Jun 12 2003 17:46:22   aguillg
 * Can Integration
 * 
 *    Rev 1.1   Jun 12 2003 09:59:40   aguillg
 * EEP Integration
 * 
 *    Rev 1.0   Apr 08 2003 12:19:00   aguillg
 * Initial revision.


  ==========================================================================*/

#ifndef I_DAT_PEE_H
#define I_DAT_PEE_H


/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "DAT_EEP.h"
#include "DAT_DEA.h"
#include "DAT_SBK.h"
#include "DAT_DBK.h"
#include "DAT_OBK.h"
#include "DAT_DTC_DATAEXPORT.h"
#include "DAT_DTC_FUNCEXPORT.h"
#include "DAT_DTC_TYPEEXPORT.h"
#else
#include ".\..\DAT_EEP\DAT_EEP.h"
#include ".\..\DAT_DEA\DAT_DEA.h"
#include ".\..\DAT_SBK\DAT_SBK.h"
#include ".\..\DAT_DBK\DAT_DBK.h"
#include ".\..\DAT_OBK\DAT_OBK.h"
#include ".\..\DAT_EEP_DATAEXPORT.h"
#include ".\..\..\DAT_DTC\DAT_DTC_DATAEXPORT.h"
#include ".\..\..\DAT_DTC\DAT_DTC_FUNCEXPORT.h"
#include ".\..\..\DAT_DTC\DAT_DTC_TYPEEXPORT.h"
#endif

#include "DAT_PEE_INCLUDE.h"

#include "DAT_PEEx.h"
#include "DAT_PEE_CFG.h"

#include "DAT_PEE_INIT_GEN.h"
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

/*-----------------------------------------------------------------------------
          Macro redefinition for only Renault or Nissan managment
  ---------------------------------------------------------------------------*/
#undef mSERReadU1BitEEPRenaultNissanDefault
#define mSERReadU1BitEEPRenaultNissanDefault() (cFalse)

/*-----------------------------------------------------------------------------
                        Macros used by DAT_PEEx.H
  ---------------------------------------------------------------------------*/

/* These macros use macros of second level */

#define mSERPeeReadBuffer( Strategy, GroupName, Byte , Index, Access )\
        mSERPeeReadTable( U8Bit, Strategy, GroupName, Byte, Index, Access )

#define mSERPeeWriteBuffer( Strategy, GroupName, Byte , Index, Val, Access )\
        mSERPeeWriteTable( U8Bit, Strategy, GroupName, Byte, Index, Val, Access )

#define mSERPeeReadTable( TypeDonnee, Strategy, GroupName, Byte, Index, Access )\
        mSERPeeReadTable##TypeDonnee##Access( Strategy, GroupName, Byte , Index )

#define mSERPeeWriteTable( TypeDonnee, Strategy, GroupName, Byte, Index, Val, Access )\
        mSERPeeWriteTable##TypeDonnee##Access( Strategy, GroupName, Byte , Index, Val )


#define mGetU8Ptr( Strategy,GroupName,Byte ) \
        (& (((U8 *) &DAT##Strategy##Mirrors.GroupName)[(Byte)]))


/* Unsigned types */

#define mSERPeeWriteU32Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access ) \
    mSERPeeWriteU32Bit##Access( Strategy, GroupName, Byte , Bit, BitSize, Val)
#define mSERPeeReadU32Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )   \
    ( mSERPeeReadU32Bit##Access( Strategy, GroupName, Byte , Bit, BitSize))

#define mSERPeeWriteU16Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access ) \
    mSERPeeWriteU16Bit##Access( Strategy, GroupName, Byte , Bit, BitSize, Val)
#define mSERPeeReadU16Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )   \
    ( mSERPeeReadU16Bit##Access( Strategy, GroupName, Byte , Bit, BitSize))

#define mSERPeeWriteU8Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access )  \
    mSERPeeWriteU8Bit##Access( Strategy, GroupName, Byte , Bit, BitSize, Val)
#define mSERPeeReadU8Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )    \
    ((U8) mSERPeeReadU8Bit##Access( Strategy, GroupName, Byte , Bit, BitSize ))

#define mSERPeeWriteU1Bit( Strategy, GroupName, Byte , Bit, Val, Access )             \
    mSERPeeWriteU1Bit##Access( Strategy, GroupName, Byte , Bit, Val)
#define mSERPeeReadU1Bit( Strategy, GroupName, Byte , Bit, Access )               \
    (mSERPeeReadU1Bit##Access( Strategy, GroupName, Byte , Bit))


/* Signed types */

#define mSERPeeWriteS8Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access )  \
    mSERPeeWriteU8Bit##Access( Strategy, GroupName, Byte , Bit, BitSize, ((U8)Val))
#define mSERPeeReadS8Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )    \
    ((S8) mSERPeeReadU8Bit##Access( Strategy, GroupName, Byte , Bit, BitSize ))

#define mSERPeeWriteS16Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access ) \
    mSERPeeWriteU16Bit( Strategy, GroupName, Byte , Bit, BitSize, ((U16)Val), Access )
#define mSERPeeReadS16Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )   \
    ((S16) mSERPeeReadU16Bit( Strategy, GroupName, Byte , Bit, BitSize, Access ))

#define mSERPeeWriteS32Bit( Strategy, GroupName, Byte , Bit, BitSize, Val, Access ) \
    mSERPeeWriteU32Bit( Strategy, GroupName, Byte , Bit, BitSize, ((U32)Val), Access )
#define mSERPeeReadS32Bit( Strategy, GroupName, Byte , Bit, BitSize, Access )   \
    ((S32) mSERPeeReadU32Bit( Strategy, GroupName, Byte , Bit, BitSize, Access ))

/*-----------------------------------------------------------------------------
                            Macros of second level
  ---------------------------------------------------------------------------*/

/* These macros use macros of third level */

/* Read / Write U1Bit */

#define mSERPeeWriteU1BitDelayed( Strategy, GroupName, Byte , Bit, Val)  \
    {                                                           \
        if( Val )                                               \
        {                                                       \
            *(mGetU8Ptr( Strategy, GroupName,Byte)) |= (U8)(1<<(Bit));    \
        }                                                       \
        else                                                    \
        {                                                       \
            *(mGetU8Ptr( Strategy, GroupName,Byte)) &= (U8)(((U16)(~(U16)(1<<(Bit)))& 0x00FFU));   \
        }                                                       \
    }

#define mSERPeeWriteU1BitImmediate( Strategy, GroupName, Byte , Bit, Val)   \
    {                                                                       \
        if( mSERPeeReadU1BitDelayed( Strategy, GroupName,Byte,Bit) != Val ) \
        {                                                                   \
          if( Val )                                                         \
          {                                                                 \
              *(mGetU8Ptr( Strategy, GroupName,Byte)) |= ((U8)(1<<(Bit)) ); \
          }                                                                 \
          else                                                              \
          {                                                                 \
              *(mGetU8Ptr( Strategy, GroupName,Byte)) &= ((U8)(((U16)(~(U16)(1<<(Bit)))& 0x00FFU)));   \
          }                                                                 \
          mSERControl(Eep,UpDateEepGroup##GroupName);                       \
        }                                                                   \
    }

#define mSERPeeReadU1BitDelayed( Strategy, GroupName, Byte , Bit)    \
   ((BOOL)( (*(mGetU8Ptr( Strategy, GroupName,Byte)) & ((U8)(1<<(Bit)))) != 0U ))


/* Read / Write U8Bit */

#define mSERPeeDec8( Bit, BitSize )   ((U8)((Bit)+1U-(BitSize)))
#define mSERPeeMask8( Bit, BitSize )     ((U8)((1<<(BitSize)) -1U))

#define mSERPeeWriteU8BitDelayed( Strategy, GroupName, Byte , Bit, BitSize, Val)        \
    {                                                                                   \
        /* Check the data don't overflow its max value */                               \
        /* On verifie que la donnee ne depasse pas sa valeur maxi */                    \
        if( ( (Val) & ~mSERPeeMask8( Bit, BitSize ) ) == 0U )                            \
        {                                                                               \
            /* In the frame, delete the data bits */                                    \
            /* Dans la trame, on efface les bits de la donnee */                        \
            (*(mGetU8Ptr( Strategy, GroupName,Byte))) = (U8)(                           \
                      (  (*(mGetU8Ptr( Strategy, GroupName,Byte))) &                    \
                           ((U8)((U16)(~(U16)(mSERPeeMask8(Bit,BitSize) << mSERPeeDec8(Bit,BitSize)))& 0x00FF))     \
                      )                                                                 \
            /* Set the data bits */                                                     \
            /* On postionne les bits de la donnee */                                    \
                      | (U8)((Val) << mSERPeeDec8( Bit, BitSize ))                      \
                                                             );                         \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            /* incorrect value in Val: would affect also other bits */                  \
            mLIBassert(cFalse);                                                         \
        }                                                                               \
    }

   
#define mSERPeeWriteU8BitImmediate( Strategy, GroupName, Byte , Bit, BitSize, Val)    \
    {                                                                                 \
        if( mSERPeeReadU8BitDelayed( Strategy, GroupName,Byte,Bit,BitSize) != (Val) ) \
        {                                                                             \
          mSERPeeWriteU8BitDelayed( Strategy, GroupName, Byte , Bit, BitSize, Val);   \
          mSERControl(Eep,UpDateEepGroup##GroupName);                                 \
        }                                                                             \
    }

#define mSERPeeReadU8BitDelayed( Strategy, GroupName, Byte , Bit, BitSize) \
    ((U8)( ( *(mGetU8Ptr( Strategy, GroupName,Byte)) >>                    \
        mSERPeeDec8( Bit, BitSize )        ) &                             \
        mSERPeeMask8(Bit,BitSize)               ))


/* Read / Write U16Bit */

#define mSERPeeWriteU16BitDelayed( Strategy, GroupName, Byte , Bit, BitSize, Val)  \
          *((U16 *) mGetU8Ptr( Strategy, GroupName,Byte) )   = Val;

#define mSERPeeWriteU16BitImmediate( Strategy, GroupName, Byte , Bit, BitSize, Val)    \
    {                                                                                  \
        if( mSERPeeReadU16BitDelayed( Strategy, GroupName,Byte,Bit,BitSize) != (Val) ) \
        {                                                                              \
          mSERPeeWriteU16BitDelayed( Strategy, GroupName, Byte , Bit, BitSize, Val);   \
          mSERControl(Eep,UpDateEepGroup##GroupName);                                  \
        }                                                                              \
    }

#define mSERPeeReadU16BitDelayed( Strategy, GroupName, Byte , Bit, BitSize )       \
   ((U16)(*((U16 *) mGetU8Ptr( Strategy, GroupName,Byte) )))


/* Read / Write U32Bit */

#define mSERPeeWriteU32BitDelayed( Strategy, GroupName, Byte , Bit, BitSize, Val)                       \
        {                                                                                               \
           *((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)) )   = (U16)((Val) & 0x0000FFFFU);              \
           *((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+2) )   = (U16)(((Val) & 0xFFFF0000U)>> 16U) ;  \
        }

#define mSERPeeWriteU32BitImmediate( Strategy, GroupName, Byte , Bit, BitSize, Val)  \
    {                                                                                \
      if( mSERPeeReadU32BitDelayed( Strategy, GroupName,(Byte),(Bit),(BitSize)) != (Val) ) \
      {                                                                              \
        mSERPeeWriteU32BitDelayed( Strategy, GroupName, (Byte) , (Bit), (BitSize), (Val));   \
        mSERControl(Eep,UpDateEepGroup##GroupName);                                  \
      }                                                                              \
    }

#define mSERPeeReadU32BitDelayed( Strategy, GroupName, Byte , Bit, BitSize )        \
  ( (U32) ((U32) (*((U16 *) mGetU8Ptr( Strategy, GroupName, (Byte)) )) +               \
               (U32) ( ((U32) (*((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+2)))) << 16 )))


/* Read / Write Buffer */

#define mSERPeeWriteBufferDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                        \
        *mGetU8Ptr( Strategy, GroupName,(Byte)+(Index)) = Val;               \
    }

#define mSERPeeWriteBufferImmediate( Strategy, GroupName, Byte , Index, Val )      \
    {                                                                              \
        if(mSERPeeReadBufferDelayed( Strategy, GroupName, Byte , Index ) != (Val)) \
        {                                                                          \
          mSERPeeWriteBufferDelayed( Strategy, GroupName, Byte , Index, Val );     \
          mSERControl(Eep,UpDateEepGroup##GroupName);                              \
        }                                                                          \
    }

#define mSERPeeReadBufferDelayed( Strategy, GroupName, Byte , Index )         \
    (*mGetU8Ptr( Strategy, GroupName,(Byte)+(Index)))


/* Read / Write Array Types */

#define mSERPeeWriteTableU8BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                            \
    *mGetU8Ptr( Strategy, GroupName,(Byte)+(Index)) = Val;                       \
    }

#define mSERPeeWriteTableU8BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                             \
      if(mSERPeeReadTableU8BitDelayed(Strategy, GroupName, Byte, Index) != (Val)) \
      {                                                                           \
        mSERPeeWriteTableU8BitDelayed( Strategy, GroupName, Byte , Index, Val );  \
        mSERControl(Eep,UpDateEepGroup##GroupName);                               \
      }                                                                           \
    }

#define mSERPeeWriteTableS8BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                            \
      * ((S8 *) mGetU8Ptr( Strategy, GroupName,(Byte)+(Index))) = Val;           \
    }

#define mSERPeeWriteTableS8BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                             \
      if(mSERPeeReadTableS8BitDelayed(Strategy, GroupName, Byte, Index) != (Val)) \
      {                                                                           \
        mSERPeeWriteTableS8BitDelayed( Strategy, GroupName, Byte , Index, Val );  \
        mSERControl(Eep,UpDateEepGroup##GroupName);                               \
      }                                                                           \
    }

#define mSERPeeWriteTableU16BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                             \
    * ((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*2U))) = Val;         \
    }

#define mSERPeeWriteTableU16BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                              \
      if(mSERPeeReadTableU16BitDelayed(Strategy, GroupName, Byte, Index) != (Val)) \
      {                                                                            \
        mSERPeeWriteTableU16BitDelayed( Strategy, GroupName, Byte , Index, Val );  \
        mSERControl(Eep,UpDateEepGroup##GroupName);                                \
      }                                                                            \
    }

#define mSERPeeWriteTableS16BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                             \
       * ((S16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*2))) = Val;      \
    }

#define mSERPeeWriteTableS16BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                             \
      if(mSERPeeReadTableS16BitDelayed(Strategy, GroupName, Byte, Index) != (Val))  \
      {                                                                           \
        mSERPeeWriteTableS16BitDelayed( Strategy, GroupName, Byte , Index, Val ); \
        mSERControl(Eep,UpDateEepGroup##GroupName);                               \
      }                                                                           \
    }

#define mSERPeeWriteTableU32BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                                             \
       *((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4U)) )   = (U16)((Val) & 0x0000FFFFU);\
       *((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4U)+2U) ) = (U16)(((Val) & 0xFFFF0000U)>> 16U) ;\
    }

#define mSERPeeWriteTableU32BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                              \
      if(mSERPeeReadTableU32BitDelayed(Strategy, GroupName, Byte, Index) != (Val)) \
      {                                                                            \
        mSERPeeWriteTableU32BitDelayed( Strategy, GroupName, Byte , Index, Val );  \
        mSERControl(Eep,UpDateEepGroup##GroupName);                                \
      }                                                                            \
    }

#define mSERPeeWriteTableS32BitDelayed( Strategy, GroupName, Byte , Index, Val )  \
    {                                                               \
       *((S16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4U)) )   = (S16)((Val) & 0x0000FFFFU);\
       *((S16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4U)+2U) ) = (S16)(((Val) & 0xFFFF0000U)>> 16U) ;\
    }

#define mSERPeeWriteTableS32BitImmediate( Strategy, GroupName, Byte , Index, Val ) \
    {                                                                              \
      if(mSERPeeReadTableS32BitDelayed(Strategy, GroupName, Byte, Index) != (Val)) \
      {                                                                            \
        mSERPeeWriteTableS32BitDelayed( Strategy, GroupName, Byte , Index, Val );  \
        mSERControl(Eep,UpDateEepGroup##GroupName);                                \
      }                                                                            \
    }

#define mSERPeeReadTableU8BitDelayed( Strategy, GroupName, Byte , Index )  \
    (*mGetU8Ptr( Strategy, GroupName,(Byte)+(Index)))

#define mSERPeeReadTableS8BitDelayed( Strategy, GroupName, Byte , Index )  \
    (* ((S8 *) mGetU8Ptr( Strategy, GroupName,(Byte)+(Index))))

#define mSERPeeReadTableU16BitDelayed( Strategy, GroupName, Byte , Index )  \
    (* ((U16 *)mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*2))))

#define mSERPeeReadTableS16BitDelayed( Strategy, GroupName, Byte , Index )  \
    (* ((S16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*2))))

#define mSERPeeReadTableU32BitDelayed( Strategy, GroupName, Byte , Index )  \
    ( (U32) ((U32)(*((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4) ) )) + \
               (U32)( ((U32) (*((U16 *) mGetU8Ptr( Strategy, GroupName,(Byte)+((Index)*4)+2)))) << 16 )))

#define mSERPeeReadTableS32BitDelayed( Strategy, GroupName, Byte , Index )  \
    ( (S32) mSERPeeReadTableU32BitDelayed( Strategy, GroupName, Byte , Index ) )

#define mSERReadU1BitIsEepProcessingDefault()  DATEepIsProcessing()

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/
extern BOOL DATPeeCompNOk;
extern BOOL DATEepromCheckingIsDone;
extern U16  DATPeeBytePosition;
extern U8   DATPeeBuffer[4];

/*-------------------------------------------------------------------------
  Exported data

  extern  tType   CMPVariableName;
  extern  tType*  pCMPVariableName; 
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/ 
extern void DATPeeInit(void);
extern void DATPeeStartReadingEEP(void);
BOOL DATPeeIsReadFinished(void);

extern void DATPeeDTCProcess(void);
extern BOOL DATPeeIsTimerElapsed(void);
extern void DATPeeRestoreBanks(void);
extern void DATPeeStartTimer(void);
#endif   /* I_DAT_PEE_H */
