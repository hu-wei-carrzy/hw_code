/*<WLEGHead>
|---------------------------------------------------------------------------------------------
| Project Name:     SAIC MIFA PLG
| File Name:       
|
|  Description:     
|
|---------------------------------------------------------------------------------------------
|                          All rights reserved
|---------------------------------------------------------------------------------------------
|
|                            CONFIDENTIAL
|
|
|---------------------------------------------------------------------------------------------
|                       R E V I S I O N   H I S T O R Y
|---------------------------------------------------------------------------------------------
| Date        Version   Author  Description
|                               Why                 What
| --------------------------------------------------------------------------------------------
| 02-12-2016  01.00      William Wei     Creation            First Version      
|---------------------------------------------------------------------------------------------
<WLEGHead>*/

#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/*******************************************************************************
 *   Includes
 *******************************************************************************/
//#include "Platform_Types.h"
#include "Compiler.h"
#include "typedefs.h"
#include"../../LIB/LIB_MEM/Platform_Types.h"


/*******************************************************************************
 *   Macro
 *******************************************************************************/
#define STD_HIGH     (1)
#define STD_LOW      (0)

#define STD_ACTIVE   (1)
#define STD_IDLE     (0)

#define STD_ON       (1)
#define STD_OFF      (0)

/* This typedef has been addedf or OSEK compliance */                        
#ifndef STATUSTYPEDEFINED  
    #define STATUSTYPEDEFINED  
   // #define E_OK    (0) 
    /* OSEK compliance */ 
    typedef unsigned char StatusType; 
#endif 
 
//#define E_NOT_OK  (1) 
                                                
/*******************************************************************************
*   Typedef 
*******************************************************************************/                                                                   
//typedef uint8 Std_ReturnType;

typedef struct                                          
{
    uint16 vendorID;                           
    uint16 moduleID;
    uint8  instanceID;
    uint8  sw_major_version;                         
    uint8  sw_minor_version;
    uint8  sw_patch_version;
}Std_VersionInfoType;

/*******************************************************************************
*   Insos Special 
*******************************************************************************/

#define STD_CONFIG_VARIANTS_PRECOMPILE  (1) 
#define STD_CONFIG_VARIANTS_LINKTIME    (2) 
#define STD_CONFIG_VARIANTS_POSTBUILD   (3)  


/* Module ID */


/* Init State */
typedef enum
{
    STD_UNINITIALIZED = 0,
    STD_INITIALIZED = 1  
}Std_InitStateType; 




#endif  /* _STD_TYPES_H_ */
