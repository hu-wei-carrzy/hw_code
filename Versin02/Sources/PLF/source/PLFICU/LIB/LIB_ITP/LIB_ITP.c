

/*--------------------------------------------------------------------------
  Body Identification
  --------------------------------------------------------------------------*/

#define LIB_ITP   "LIB_ITP"

/*-------------------------------------------------------------------------
  Included files

  #include <system_file_name.h>
  #include "project_file_name.h"
  --------------------------------------------------------------------------*/
#include "..\LIB_API\lib.h"
#include "lib_itp.h"

/*--------------------------------------------------------------------------
  Local constants

  #define cConstantName   ((tType) ConstantValue)
  --------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local macross

  #define mMacroName   (MacroDefinition)
  --------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local types

  struct  sStructureName { ... };
  union   uUnionName { ... };
  enum    eEnumerationName { ... };
  typedef Expression tTypeName;
  --------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local data

  static  tType   VariableName;
  static  tType*  pVariableName; 
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Constant local data

  static const tType  VariableName;
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Exported data

  tType   CMPVariableName;      (CMP: 3 characters to identify this component)
  tType*  pCMPVariableName;     (CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
  Constant exported data
 
  const tType   CMPVariableName;(CMP: 3 characters to identify this component)
  --------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
  Local function prototypes
  
  static tTypeRetour FunctionName(tTypeArgument1 ArgumentName1, ... );
  --------------------------------------------------------------------------*/

/*============================================================================
  =========================== LOCAL FUNCTIONS ================================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION :
  
  PARAMETERS (Type,Name,Min,Max) :   none

  RETURN VALUE :   none
 
  DESIGN INFORMATION :   refer to Detailed Design Document
  ==========================================================================*/
//static type FunctionName(...)

/*============================================================================
  =========================== EXPORTED FUNCTIONS =============================
  ==========================================================================*/

/*============================================================================
  DESCRIPTION : Achieve Linear Interpolation for a multi-segment 
  characteristic.
  
  PARAMETERS (Type,Name,Min,Max) :  
  pInterpol : pointer on a ROM structure containing the information needed 
              to describe the interpolation (see definition of tInterpol)

  InputValue : Value to convert. The input range is 0 -> 0xFFFF

  RETURN VALUE :  Interpoled value. The output range is 0 -> 0xFFFF
 
  DESIGN INFORMATION :  
  if Input Value is lower than the lowest X-value, saturate to this value
  if Input Value is higher than the highest X-value, saturate to this value
  otherwise, apply linear interpolation calculation :
  n is the correct conversion segment number.
  X(n) is the X-value of the nth point.
  Y(n) is the Y-value of the nth point
  Input is the input value
  Output is the result of the interpolation

  if Y(n+1) > Y(n) -> rising characteristic 
                                         Y(n+1) - Y(n) 
    => Output = Y(n) + (Input - X(n)) * ---------------
                                         X(n+1) - X(n)

  if Y(n+1) < Y(n) -> falling characteristic
                                         Y(n) - Y(n+1) 
    => Output = Y(n) - (Input - X(n)) * ---------------
                                         X(n+1) - X(n)

============================================================================*/
U16 LIBCharacteristicLineApply(const tInterpol* pInterpol, U16 InputValue)
{
    U8 u;
    U32 ul;

    mLIBassert( pInterpol != NULL );
    mLIBassert( pInterpol->NbPoints > 0 );
    mLIBassert( pInterpol->pInput != NULL );
    mLIBassert( pInterpol->pOutput != NULL );

    // Low-saturation of the value
    if(InputValue <= pInterpol->pInput[0])
    {
        ul = pInterpol->pOutput[0];
    }
    // High-saturation of the value
    else
    {
        if(InputValue >= pInterpol->pInput[pInterpol->NbPoints - 1])
        {
            ul = pInterpol->pOutput[pInterpol->NbPoints - 1];
        }
        // else, the value belongs to a segment... which one ?
        else
        {
            // look for the correct segment of conversion
            for(u = 1; u < (pInterpol->NbPoints - 1); ++u)
            {
                if(InputValue <= pInterpol->pInput[u])
                {
                    // as soon as X(n) is higher than the input value,
                    // we know the correct segment of conversion.
                    break;
                }
                else
                {
                }
            }
            // since we compare to the end point, the segment number is -1.
            u--;

            // Apply linear interpolation calculation
            ul = (U32)(InputValue - pInterpol->pInput[u]);    //(x-x1)

            // -> rising chraracteristic
            if(pInterpol->pOutput[u] < pInterpol->pOutput[u + 1])
            {
                ul *= (U32)(pInterpol->pOutput[u + 1] - pInterpol->pOutput[u]); //*(y2-y1)
                ul /= (U32)(pInterpol->pInput[u + 1] - pInterpol->pInput[u]); ///(x2-x1)
                ul += (U32)pInterpol->pOutput[u];
            }
            else
            // -> falling chraracteristic
            {
                ul *= (U32)(pInterpol->pOutput[u] - pInterpol->pOutput[u + 1]); //*(y2-y1)
                ul /= (U32)(pInterpol->pInput[u + 1] - pInterpol->pInput[u]); ///(x2-x1)
                ul = (U32)pInterpol->pOutput[u] - ul;
            }
        }
    }

    // the value returned is cast on 16 bits.
    return ((U16)ul);

}
