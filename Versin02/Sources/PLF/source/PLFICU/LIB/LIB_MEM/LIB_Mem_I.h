#ifndef LIB_Mem_I_H
#define LIB_Mem_I_H

#include "basedef.h"

#ifndef _QAC_
//**********************************************************************************************************************

// ---------------------------------------------------------------------------------------------------------------------
// Component:    Library Memory - Functional Interfaces
// ---------------------------------------------------------------------------------------------------------------------
/* $Log::   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LIB_Mem_I.h-arc                                     $
 * 
 *    Rev 1.1   Feb 12 2014 16:52:48   azhao26
 * Cm065183:modify the generated comment error when implement the CPU load test
* 
*    Rev 1.0   Feb 12 2014 12:43:42   azhao26
* Initial revision.
*/
//**********************************************************************************************************************
#endif

// ---------------------------------------------------------------------------------------------------------------------
// UML::IMem
// ---------------------------------------------------------------------------------------------------------------------

 void LIB_Mem_MemCpy (void * const pDestP, const void * const pSrcP, const uint16 u16CountP);
 void LIB_Mem_MemSet (void * const pDestP, const uint8 u8ValueP, const uint16 u16CountP);
 boolean LIB_Mem_MemCmp (const void * const pBuf1P, const void * const pBuf2P, const uint16 u16CountP);
 void LIB_Mem_MemMove(void * const pDestP, const void * const pSrcP, const uint16 u16CountP);

// ---------------------------------------------------------------------------------------------------------------------
// UML::IString
// ---------------------------------------------------------------------------------------------------------------------
uint16 LIB_Mem_StrLen(const uint8 * const pu8szStrP);

// ---------------------------------------------------------------------------------------------------------------------
// UML::IMask
// ---------------------------------------------------------------------------------------------------------------------
#define c32MAXMask                  ((uint32)0xFFFFFFFF)

#define LIB_Mem_MaskSet( Typecast, pContainer, Mask )                                                                  \
    ( (pContainer) = ( (Typecast)( (uint32)(pContainer) | (uint32)(Mask) ) ) )


#define LIB_Mem_MaskClear( Typecast, pContainer, Mask )                                                                \
    ( (pContainer) = ( (Typecast)( (uint32)(pContainer) & ( c32MAXMask^( (uint32)(Mask) ) ) ) ) )


#define LIB_Mem_MaskCompare( Container, Mask )                                                                        \
    (boolean)( (Mask) == ( (uint32)(Container) & (uint32)(Mask) ) ) 

#endif // LIB_Mem_I_H
