#ifndef _QAC_
//**********************************************************************************************************************
// Company:      Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:    This software is JCI property.
//               Duplication or disclosure without JCI written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:      N330
// Language:     ANSI-C
// ---------------------------------------------------------------------------------------------------------------------
// Component:    Library Memory - Implementation
// ---------------------------------------------------------------------------------------------------------------------
/* $Log:   //DI_JMC_N330_IC/archives/1016282/DEV/BUILD/SOURCES/LIB_Mem_C.c-arc  $
 * 
 *    Rev 1.1   Feb 12 2014 16:52:50   azhao26
 * Cm065183:modify the generated comment error when implement the CPU load test
*
*    Rev 1.0   Feb 12 2014 12:43:40   azhao26
* Initial revision.
*/

//**********************************************************************************************************************
#endif

//======================================================================================================================
// BODY IDENTIFICATION
//======================================================================================================================
#define LIB_Mem_C   "LIB_Mem_C"

//======================================================================================================================
// INCLUDED FILES
//======================================================================================================================
#include "LIB_Mem_RI.h"
#include "LIB_Mem_I.h"
//#include "DEFTYPES.h"
#include ".\..\..\LAP_LIB.h"
// Uncomment this file if you need to put a configuration options!
//#include "LIB_Mem_Cfg.h"

//======================================================================================================================
// PRIVATE MACROS
//======================================================================================================================
#ifndef NULL
#define NULL 0
#endif
//======================================================================================================================
// PRIVATE TYPES
//======================================================================================================================

//======================================================================================================================
// PRIVATE DATA
//======================================================================================================================

//======================================================================================================================
// CONSTANT PRIVATE DATA
//======================================================================================================================

//======================================================================================================================
// FORWARD DECLARATIONS OF PRIVATE FUNCTIONS
//======================================================================================================================

//======================================================================================================================
// PRIVATE FUNCTIONS
//======================================================================================================================

//======================================================================================================================
// PUBLIC FUNCTIONS
//======================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
// UML::IMem
// ---------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Copies given Count bytes from pSrc to pDest buffer.
//
// PARAMETERS:          pDestP � destination buffer
//                      pSrcP � source buffer
//                      u16CountP �  number of bytes to be copied
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  If it is possible to buffers to overlap use MemMove function
//                      Size of data to copy MUST fit in destination buffer !
//                      In case of failure nothing happens 
//----------------------------------------------------------------------------------------------------------------------
void LIB_Mem_MemCpy (void * const pDestP, const void * const pSrcP, const uint16 u16CountP)
{

    uint8 * const pu8DestBufL = (uint8 * const)pDestP;
    const uint8 * const pu8SrcBufL = (const uint8 * const)pSrcP;
 
    uint16 u16IdxL;

    if( (NULL != pu8DestBufL ) && ( NULL != pu8SrcBufL ) && ( (uint16)0 != u16CountP ) )
    {
        
        if (
             // Dest buffer starts after Src buffer
//QACJ 0490: anikolns: check for overlapping areas
             ( pu8DestBufL > ( &pu8SrcBufL[u16CountP-1] ) ) ||
             // Src buffer start after Dest buffer
             ( ( &pu8DestBufL[u16CountP-1] ) < pu8SrcBufL )
           )
        {
            u16IdxL = 0;

            while( u16IdxL < u16CountP )
            {
                pu8DestBufL[u16IdxL] = pu8SrcBufL[u16IdxL];
                ++u16IdxL;
            }
        }
        else
        {
            // QAC
        }
   
    }
    else
    {
        // QAC
    }
}


//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Sets buffers to a specified byte value.
//
// PARAMETERS:          pDestP � buffer with set value
//                      u8ValueP � byte value
//                      u16CountP �  number of bytes    
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  In case of failure nothing happens
//----------------------------------------------------------------------------------------------------------------------
void LIB_Mem_MemSet (void * const pDestP, const uint8 u8ValueP, const uint16 u16CountP)
{
    uint8 * const pu8BufL = (uint8 * const)pDestP;
    uint16 u16IdxL;

    if( ( NULL != pu8BufL ) )
    {
        u16IdxL = u16CountP;

        while( u16IdxL > (uint16)0 )
        {
            --u16IdxL;
            pu8BufL[u16IdxL] = u8ValueP;
        }
    }
    else
    {
        // QAC
    }
}


//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Compare characters in two buffers.
//
// PARAMETERS:          const void * const pBuf1P � first buffer.
//                      const void * const pBuf2P � second buffer.
//                      const u16CountP           �  number of bytes to be compared
//
// RETURN VALUE:        cTrue - pBuf1 identical to pBuf2;
//                      cFalse- pBuf1 different from pBuf2
//                      or any of the pointers is NULL (note: even if the both pointers are NULL);
//                      or u16Count = 0
//
// DESIGN INFORMATION: 
//----------------------------------------------------------------------------------------------------------------------
boolean LIB_Mem_MemCmp (const void * const pBuf1P, const void * const pBuf2P, const uint16 u16CountP)
{
    boolean bRetL = cTrue;

    const uint8 * const pu8Buf1L = (const uint8 * const )pBuf1P;
    const uint8 * const pu8Buf2L = (const uint8 * const )pBuf2P;

    uint16 u16IdxL;

    if( ( NULL != pu8Buf1L ) && ( NULL != pu8Buf2L ) && ( 0 != u16CountP ))
    {
        u16IdxL = u16CountP;

        while( ( cTrue == bRetL ) && ( u16IdxL > (uint16)0 ))
        {
            --u16IdxL;

            if( pu8Buf1L[u16IdxL] != pu8Buf2L[u16IdxL] )
            {
                bRetL = cFalse;
            }
        }
    }
    else
    {
        bRetL = cFalse;
    }

    return bRetL;
}


//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         The MemMove function copies Count bytes of characters from pSrc to pDest.
//                      If some regions of the source area and the destination overlap,
//                      it ensures that the original source bytes in the overlapping region
//                      are copied before being overwritten.
//
// PARAMETERS:          pDestP � destination buffer
//                      pSrcP � source buffer
//                      u16CountP �  number of bytes to be copied
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  Size of data to copy MUST fit in destination buffer !
//                      In case of failure nothing happens
//----------------------------------------------------------------------------------------------------------------------
void LIB_Mem_MemMove(void * const pDestP, const void* const pSrcP, const uint16 u16CountP)
{
    uint8 * const pu8DestBufL = (uint8 * const)pDestP;
    const uint8 * const pu8SrcBufL = (const uint8 * const)pSrcP;

    uint16 u16IdxL;

    if( (NULL != pu8DestBufL ) && ( NULL != pu8SrcBufL ) )
    {

        if( (uint16)0 != u16CountP)
        {
            
//QACJ 0490: anikolns: check for overlapping areas
            if( (pu8DestBufL < pu8SrcBufL) && (&(pu8DestBufL[u16CountP-1]) >= pu8SrcBufL) )
            {
                u16IdxL = (uint16)0;

                while( u16IdxL < u16CountP )
                {
                    pu8DestBufL[u16IdxL] = pu8SrcBufL[u16IdxL];
                    ++u16IdxL;
                }
            }
            else
            {
                // Dest buffer starts before end of Src buffer or buffers do not overlap
                u16IdxL = u16CountP;

                while( u16IdxL > (uint16)0 )
                {
                    --u16IdxL;

                    pu8DestBufL[u16IdxL] = pu8SrcBufL[u16IdxL];
                }
            }
        }
        else
        {
            // QAC
        }
    }
    else
    {
        // QAC
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// UML::IString
// ---------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:      Calculate the length of a string
//
// PARAMETERS:       const uint8 * const pu8szStrP  - Pointer to the string
//
// RETURN VALUE:     uint16 - Invalid argument or strng size is 0
//                   
//
// DESIGN INFORMATION:
//----------------------------------------------------------------------------------------------------------------------
uint16 LIB_Mem_StrLen(const uint8 * const pu8szStrP)
{
    uint16 u16Length = 0;
    

    if ( NULL != pu8szStrP )
    {
        while ( (uint8)0 != pu8szStrP[u16Length] )
        {
            ++u16Length;
        }
    }
   
    return u16Length;
}
