

#ifndef I_LIB_ITP_H
#define I_LIB_ITP_H (1)


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/

#include "ARCH_CFG.h"

#ifdef cHeadIncludeType_Directly
#include "deftypes.h"
#else
#include ".\..\LIB_API\deftypes.h"
#endif

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 
#define mLIBCharacteristicLineApply(pInterpolStruct, Value)  \
                        (LIBCharacteristicLineApply((pInterpolStruct), (Value)))

/*-------------------------------------------------------------------------
  Exported type

  struct  sCMPStructureName { ... };
  union   uCMPUnionName { ... };
  enum    eCMPEnumerationName { ... };
  typedef Expression tCMPTypeName;

  -------------------------------------------------------------------------*/
// Linear Interpolation Structure containing :
// - a pointer on the input table (X-table)
// - a pointer on the output table (Y-table)
// - the total number of points of the interpolation (= nb segments + 1)
typedef struct
{
  U16* pInput;
  U16* pOutput;
  U8 NbPoints;
} tInterpol;

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
extern U16 LIBCharacteristicLineApply(const tInterpol* , U16);

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif /* I_LIB_ITP_H */
