//----  Mono-inclusion Definition-----
#ifndef I_LDB_DOU_CFG_H
#define I_LDB_DOU_CFG_H 

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "ldb.h"
#include "BSP_DIO.h"
#else
#include ".\..\LDB\LDB_API\ldb.h"
#include ".\..\..\..\BSP\BSP_DIO\BSP_DIO.h"
#endif
/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
  Exported Macros

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/

#define  mLDBDOUCfg(DOGroup,DOPin,DODir)       WPREGBIT_GPIO(DOGroup,DOPin,DODir)

#ifdef cLIBStkSimIOFor59X
//Note:here both include direct output and indirect output through HC595
#define  mLDBDouSetDOByGroup_3(Buffer)                                      \
                                                                             \
    mLDBDousWriteData(3,1,7                     ,((Buffer[5] & 0x80) >> 7) );\
    mLDBDousWriteData(3,1,6                     ,((Buffer[5] & 0x40) >> 6) );\
    mLDBDousWriteData(3,1,5                     ,((Buffer[5] & 0x20) >> 5) );\
    mLDBDousWriteData(3,1,4                     ,((Buffer[5] & 0x10) >> 4) );\
    mLDBDousWriteData(3,1,3                     ,((Buffer[5] & 0x08) >> 3) );\
    mLDBDousWriteData(3,1,2                     ,((Buffer[5] & 0x04) >> 2) );\
    mLDBDousWriteData(3,1,1                     ,((Buffer[5] & 0x02) >> 1) );\
    mLDBDousWriteData(3,1,0                     ,((Buffer[5] & 0x01) >> 0) );\
                                                                              \
    mLDBDousWriteData(3,0,7                     ,((Buffer[6] & 0x80) >> 7) );\
    mLDBDousWriteData(3,0,6                     ,((Buffer[6] & 0x40) >> 6) );\
    mLDBDousWriteData(3,0,5                     ,((Buffer[6] & 0x20) >> 5) );\
    mLDBDousWriteData(3,0,4                     ,((Buffer[6] & 0x10) >> 4) );\
    mLDBDousWriteData(3,0,3                     ,((Buffer[6] & 0x08) >> 3) );\
    mLDBDousWriteData(3,0,2                     ,((Buffer[6] & 0x04) >> 2) );\
    mLDBDousWriteData(3,0,1                     ,((Buffer[6] & 0x02) >> 1) );\
    mLDBDousWriteData(3,0,0                     ,((Buffer[6] & 0x01) >> 0) );\
                                                                             \
    mLDBDousLRSendData(3);  \

#define  mLDBDouSetDOByGroup_2(Buffer)                                 \
    mLDBDousWriteData(2,1,7                     ,((Buffer[3] & 0x80) >> 7) );\
    mLDBDousWriteData(2,1,6                     ,((Buffer[3] & 0x40) >> 6) );\
    mLDBDousWriteData(2,1,5                     ,((Buffer[3] & 0x20) >> 5) );\
    mLDBDousWriteData(2,1,4                     ,((Buffer[3] & 0x10) >> 4) );\
    mLDBDousWriteData(2,1,3                     ,((Buffer[3] & 0x08) >> 3) );\
    mLDBDousWriteData(2,1,2                     ,((Buffer[3] & 0x04) >> 2) );\
    mLDBDousWriteData(2,1,1                     ,((Buffer[3] & 0x02) >> 1) );\
    mLDBDousWriteData(2,1,0                     ,((Buffer[3] & 0x01) >> 0) );\
                                                                             \
    mLDBDousWriteData(2,0,7                     ,((Buffer[4] & 0x80) >> 7) );\
    mLDBDousWriteData(2,0,6                     ,((Buffer[4] & 0x40) >> 6) );\
    mLDBDousWriteData(2,0,5                     ,((Buffer[4] & 0x20) >> 5) );\
    mLDBDousWriteData(2,0,4                     ,((Buffer[4] & 0x10) >> 4) );\
    mLDBDousWriteData(2,0,3                     ,((Buffer[4] & 0x08) >> 3) );\
    mLDBDousWriteData(2,0,2                     ,((Buffer[4] & 0x04) >> 2) );\
    mLDBDousWriteData(2,0,1                     ,((Buffer[4] & 0x02) >> 1) );\
    mLDBDousWriteData(2,0,0                     ,((Buffer[4] & 0x01) >> 0) );\
                                                                             \
    mLDBDousLRSendData(2);\



//将数据写入到u8LDBDousDataBufHC59xGroup_1/2/3[]数组中，Buffer[]来自DAT层的数据
#define mLDBDouSetDOByGroup_1(Buffer)                                   \
    mLDBDousWriteData(1,2,7                     ,((Buffer[0] & 0x80) >> 7) );\
    mLDBDousWriteData(1,2,6                     ,((Buffer[0] & 0x40) >> 6) );\
    mLDBDousWriteData(1,2,5                     ,((Buffer[0] & 0x20) >> 5) );\
    mLDBDousWriteData(1,2,4                     ,((Buffer[0] & 0x10) >> 4) );\
    mLDBDousWriteData(1,2,3                     ,((Buffer[0] & 0x08) >> 3) );\
    mLDBDousWriteData(1,2,2                     ,((Buffer[0] & 0x04) >> 2) );\
    mLDBDousWriteData(1,2,1                     ,((Buffer[0] & 0x02) >> 1) );\
    mLDBDousWriteData(1,2,0                     ,((Buffer[0] & 0x01) >> 0) );\
                                                                             \
    mLDBDousWriteData(1,1,7                     ,((Buffer[1] & 0x80) >> 7) );\
    mLDBDousWriteData(1,1,6                     ,((Buffer[1] & 0x40) >> 6) );\
    mLDBDousWriteData(1,1,5                     ,((Buffer[1] & 0x20) >> 5) );\
    mLDBDousWriteData(1,1,4                     ,((Buffer[1] & 0x10) >> 4) );\
    mLDBDousWriteData(1,1,3                     ,((Buffer[1] & 0x08) >> 3) );\
    mLDBDousWriteData(1,1,2                     ,((Buffer[1] & 0x04) >> 2) );\
    mLDBDousWriteData(1,1,1                     ,((Buffer[1] & 0x02) >> 1) );\
    mLDBDousWriteData(1,1,0                     ,((Buffer[1] & 0x01) >> 0) );\
                                                                             \
    mLDBDousWriteData(1,0,7                     ,((Buffer[2] & 0x80) >> 7) );\
    mLDBDousWriteData(1,0,6                     ,((Buffer[2] & 0x40) >> 6) );\
    mLDBDousWriteData(1,0,5                     ,((Buffer[2] & 0x20) >> 5) );\
    mLDBDousWriteData(1,0,4                     ,((Buffer[2] & 0x10) >> 4) );\
    mLDBDousWriteData(1,0,3                     ,((Buffer[2] & 0x08) >> 3) );\
    mLDBDousWriteData(1,0,2                     ,((Buffer[2] & 0x04) >> 2) );\
    mLDBDousWriteData(1,0,1                     ,((Buffer[2] & 0x02) >> 1) );\
    mLDBDousWriteData(1,0,0                     ,((Buffer[2] & 0x01) >> 0) );\
                                                                            \
    mLDBDousLRSendData(1);\

#define mLDBDouSetDO(Buffer)   \
        mBSPDIOSetDODirect(Buffer)   \
        mLDBDouSetDOByGroup_3(Buffer)\
        mLDBDouSetDOByGroup_1(Buffer)\
        mLDBDouSetDOByGroup_2(Buffer)

#endif

#ifdef cCfg_UARTFor59X

#define mLDBDouInit()


#define mLDBDouSetDO(Buffer)                \
        mBSPDIOSetDODirect(Buffer)

#endif

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/


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


#endif
