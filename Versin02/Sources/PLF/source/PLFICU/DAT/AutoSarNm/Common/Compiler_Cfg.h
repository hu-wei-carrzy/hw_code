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

#ifndef _COMPILER_CFG_H_
#define _COMPILER_CFG_H_

/*******************************************************************************
 *   BSW START
 *******************************************************************************/
#define BSW_CODE
#define BSW_VAR_NOINIT
#define BSW_VAR_POWER_ON_INIT
#define BSW_VAR_FAST
#define BSW_VAR
#define BSW_CONST
#define BSW_APPL_CODE
#define BSW_APPL_CONST
#define BSW_APPL_DATA
#define BSW_CALLOUT_CODE
/*******************************************************************************
 *   BSW END
 *******************************************************************************/

/*******************************************************************************
 *   CAN Communication Stack START
 *******************************************************************************/

/*******************************************************************************
 *   CAN Driver START
 *******************************************************************************/
#define CAN_PUBLIC_CODE                /* API functions                       */
#define CAN_PUBLIC_CONST               /* API constants                       */

#define CAN_PRIVATE_CODE               /* Internal functions                  */

#define CAN_PRIVATE_DATA               /* Module internal data                */
#define CAN_PRIVATE_CONST              /* Internal ROM Data                   */

#define CAN_APPL_CODE                  /* callbacks of the Application        */
#define CAN_APPL_CONST                 /* Applications' ROM Data              */
#define CAN_APPL_DATA                  /* Applications' RAM Data              */
#define CAN_FAST_DATA                  /* 'Near' RAM Data                     */

#define CAN_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define CAN_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define CAN_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define CAN_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define CAN_CONST                      /* Data Constants                      */
/*******************************************************************************
 *   CAN Driver END
 *******************************************************************************/

/*******************************************************************************
 *   CAN Interface START
 *******************************************************************************/
#define CANIF_PUBLIC_CODE                /* API functions                     */
#define CANIF_PUBLIC_CONST               /* API constants                     */

#define CANIF_PRIVATE_CODE               /* Internal functions                */

#define CANIF_PRIVATE_DATA               /* Module internal data              */
#define CANIF_PRIVATE_CONST              /* Internal ROM Data                 */

#define CANIF_APPL_CODE                  /* callbacks of the Application      */
#define CANIF_APPL_CONST                 /* Applications' ROM Data            */
#define CANIF_APPL_DATA                  /* Applications' RAM Data            */
#define CANIF_FAST_DATA                  /* 'Near' RAM Data                   */

#define CANIF_CONFIG_CONST               /* Desc. Tables -> Config-dependent  */
#define CANIF_CONFIG_DATA                /* Config. dependent (reg. size) data*/

#define CANIF_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define CANIF_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define CANIF_CONST                      /* Data Constants                    */
/*******************************************************************************
 *   CAN Interface END
 *******************************************************************************/

/*******************************************************************************
 *   CCP START
 *******************************************************************************/
#define CCP_PUBLIC_CODE                /* API functions                       */
#define CCP_PUBLIC_CONST               /* API constants                       */

#define CCP_PRIVATE_CODE               /* Internal functions                  */

#define CCP_PRIVATE_DATA               /* Module internal data                */
#define CCP_PRIVATE_CONST              /* Internal ROM Data                   */

#define CCP_APPL_CODE                  /* callbacks of the Application        */
#define CCP_APPL_CONST                 /* Applications' ROM Data              */
#define CCP_APPL_DATA                  /* Applications' RAM Data              */
#define CCP_FAST_DATA                  /* 'Near' RAM Data                     */

#define CCP_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define CCP_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define CCP_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define CCP_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define CCP_CONST                      /* Data Constants                      */
/*******************************************************************************
 *   CCP END
 *******************************************************************************/
/*******************************************************************************
*   XCP START
*******************************************************************************/

#define XCP_PUBLIC_CODE                /* API functions                       */
#define XCP_PUBLIC_CONST               /* API constants                       */

#define XCP_PRIVATE_CODE               /* Internal functions                  */

#define XCP_PRIVATE_DATA               /* Module internal data                */
#define XCP_PRIVATE_CONST              /* Internal ROM Data                   */

#define XCP_APPL_CODE                  /* callbacks of the Application        */
#define XCP_APPL_CONST                 /* Applications' ROM Data              */
#define XCP_APPL_DATA                  /* Applications' RAM Data              */
#define XCP_FAST_DATA                  /* 'Near' RAM Data                     */


#define XCP_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define XCP_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define XCP_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define XCP_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define XCP_CONST                      /* Data Constants                      */


/*******************************************************************************
*   XCP END
*******************************************************************************/

/*******************************************************************************
 *   CANTP START
 *******************************************************************************/
#define CANTP_PUBLIC_CODE              /* API functions                       */
#define CANTP_PUBLIC_CONST             /* API constants                       */

#define CANTP_PRIVATE_CODE             /* Internal functions                  */

#define CANTP_PRIVATE_DATA             /* Module internal data                */
#define CANTP_PRIVATE_CONST            /* Internal ROM Data                   */

#define CANTP_APPL_CODE                /* callbacks of the Application        */
#define CANTP_APPL_CONST               /* Applications' ROM Data              */
#define CANTP_APPL_DATA                /* Applications' RAM Data              */
#define CANTP_FAST_DATA                /* 'Near' RAM Data                     */

#define CANTP_CONFIG_CONST             /* Desc. Tables -> Config-dependent    */
#define CANTP_CONFIG_DATA              /* Config. dependent (reg. size) data  */

#define CANTP_INIT_DATA                /* Data which is initialized during
                                        Startup                               */
#define CANTP_NOINIT_DATA              /* Data which is not initialized during
                                        Startup                               */
#define CANTP_CONST                    /* Data Constants                      */
/*******************************************************************************
 *   CANTP END
 *******************************************************************************/

/*******************************************************************************
 *   DCM START
 *******************************************************************************/
#define DCM_CODE                       /* FOR CONFIG DOCUMENT                 */
#define DCM_VARIABLE                   /* FOR CONFIG DOCUMENT                 */
#define DCM_PUBLIC_CODE                /* API functions                       */
#define DCM_PUBLIC_CONST               /* API constants                       */

#define DCM_PRIVATE_CODE               /* Internal functions                  */

#define DCM_PRIVATE_DATA               /* Module internal data                */
#define DCM_PRIVATE_CONST              /* Internal ROM Data                   */

#define DCM_APPL_CODE                  /* callbacks of the Application        */
#define DCM_APPL_CONST                 /* Applications' ROM Data              */
#define DCM_APPL_DATA                  /* Applications' RAM Data              */

#define DCM_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define DCM_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define DCM_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define DCM_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define DCM_CONST                      /* Data Constants                      */
/*******************************************************************************
 *   DCM END
 *******************************************************************************/

/*******************************************************************************
 *   COM START
 *******************************************************************************/
#define COM_PUBLIC_CODE                /* API functions                       */
#define COM_PUBLIC_CONST               /* API constants                       */

#define COM_PRIVATE_CODE               /* Internal functions                  */

#define COM_PRIVATE_DATA               /* Module internal data                */
#define COM_PRIVATE_CONST              /* Internal ROM Data                   */

#define COM_APPL_CODE                  /* callbacks of the Application        */
#define COM_APPL_CONST                 /* Applications' ROM Data              */
#define COM_APPL_DATA                  /* Applications' RAM Data              */
#define COM_FAST_DATA                  /* 'Near' RAM Data                     */

#define COM_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define COM_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define COM_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define COM_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define COM_CONST                      /* Data Constants                      */
#define COM_AUTOMOTIVE                 /* Automotive                          */
/*******************************************************************************
 *   COM END
 *******************************************************************************/

/*******************************************************************************
 *   OSEKNM START
 *******************************************************************************/
#define OSEKNM_PUBLIC_CODE             /* API functions                       */
#define OSEKNM_PUBLIC_CONST            /* API constants                       */

#define OSEKNM_PRIVATE_CODE            /* Internal functions                  */

#define OSEKNM_PRIVATE_DATA            /* Module internal data                */
#define OSEKNM_PRIVATE_CONST           /* Internal ROM Data                   */

#define OSEKNM_APPL_CODE               /* callbacks of the Application        */
#define OSEKNM_APPL_CONST              /* Applications' ROM Data              */
#define OSEKNM_APPL_DATA               /* Applications' RAM Data              */
#define OSEKNM_FAST_DATA               /* 'Near' RAM Data                     */

#define OSEKNM_CONFIG_CONST            /* Desc. Tables -> Config-dependent    */
#define OSEKNM_CONFIG_DATA             /* Config. dependent (reg. size) data  */

#define OSEKNM_INIT_DATA               /* Data which is initialized during
                                          Startup                             */
#define OSEKNM_NOINIT_DATA             /* Data which is not initialized during
                                          Startup                             */
#define OSEKNM_CONST                   /* Data Constants                      */
/*******************************************************************************
 *   OSEKNM END
 *******************************************************************************/

/*******************************************************************************
 *   CAN Communication Stack END
 *******************************************************************************/

/*******************************************************************************
 *   LIN Communication Stack START
 *******************************************************************************/

/*******************************************************************************
 *   LIN Driver START
 *******************************************************************************/
#define LIN_PUBLIC_CODE                /* API functions                       */
#define LIN_PUBLIC_CONST               /* API constants                       */

#define LIN_PRIVATE_CODE               /* Internal functions                  */

#define LIN_PRIVATE_DATA               /* Module internal data                */
#define LIN_PRIVATE_CONST              /* Internal ROM Data                   */

#define LIN_APPL_CODE                  /* callbacks of the Application        */
#define LIN_APPL_CONST                 /* Applications' ROM Data              */
#define LIN_APPL_DATA                  /* Applications' RAM Data              */
#define LIN_FAST_DATA                  /* 'Near' RAM Data                     */

#define LIN_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define LIN_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define LIN_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define LIN_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define LIN_CONST                      /* Data Constants                      */
/*******************************************************************************
 *   LIN Driver END
 *******************************************************************************/

/*******************************************************************************
 *   LIN Interface START
 *******************************************************************************/
#define LINIF_PUBLIC_CODE                /* API functions                     */
#define LINIF_PUBLIC_CONST               /* API constants                     */

#define LINIF_PRIVATE_CODE               /* Internal functions                */

#define LINIF_PRIVATE_DATA               /* Module internal data              */
#define LINIF_PRIVATE_CONST              /* Internal ROM Data                 */

#define LINIF_APPL_CODE                  /* callbacks of the Application      */
#define LINIF_APPL_CONST                 /* Applications' ROM Data            */
#define LINIF_APPL_DATA                  /* Applications' RAM Data            */
#define LINIF_FAST_DATA                  /* 'Near' RAM Data                   */

#define LINIF_CONFIG_CONST               /* Desc. Tables -> Config-dependent  */
#define LINIF_CONFIG_DATA                /* Config. dependent (reg. size) data*/

#define LINIF_INIT_DATA                  /* Data which is initialized during
                                            Startup                           */
#define LINIF_NOINIT_DATA                /* Data which is not initialized during
                                            Startup                           */
#define LINIF_CONST                      /* Data Constants                    */
/*******************************************************************************
 *   LIN Interface END
 *******************************************************************************/

/*******************************************************************************
 *   LIN Communication Stack END
 *******************************************************************************/

/*******************************************************************************
 *   NVM START
 *******************************************************************************/
#define NVM_CODE
#define NVM_VAR_NOINIT
#define NVM_VAR_POWER_ON_INIT
#define NVM_VAR_FAST
#define NVM_VAR
#define NVM_CONST
#define NVM_APPL_CODE
#define NVM_APPL_CONST
#define NVM_APPL_DATA
#define NVM_CALLOUT_CODE
/*******************************************************************************
 *   NVM END
 *******************************************************************************/
/*******************************************************************************
*   CAN Network Management START
*******************************************************************************/
#define CANNM_CODE
#define CANNM_VAR_NOINIT
#define CANNM_VAR_POWER_ON_INIT

#define CANNM_VAR_FAST
#define CANNM_VAR
#define CANNM_CONST

#define CANNM_APPL_CODE
#define CANNM_APPL_CONST
#define CANNM_APPL_DATA

#define CANNM_CALLOUT_CODE
/*******************************************************************************
*   CAN Network Management END
*******************************************************************************/

/*******************************************************************************
 *   MEMIF START
 *******************************************************************************/
#define MEMIF_CODE
#define MEMIF_VAR_NOINIT
#define MEMIF_VAR_POWER_ON_INIT
#define MEMIF_VAR_FAST
#define MEMIF_VAR
#define MEMIF_CONST
#define MEMIF_APPL_CODE
#define MEMIF_APPL_CONST
#define MEMIF_APPL_DATA
#define MEMIF_CALLOUT_CODE
/*******************************************************************************
 *   MEMIF END
 *******************************************************************************/

/*******************************************************************************
 *   DEM START
 *******************************************************************************/
#define DEM_CODE /* FOR CONFIG DOCUMENT */
#define DEM_VARIABLE /* FOR CONFIG DOCUMENT */
#define DEM_PUBLIC_CODE /* API functions */
#define DEM_PUBLIC_CONST /* API constants */

#define DEM_PRIVATE_CODE /* Internal functions */

#define DEM_PRIVATE_DATA /* Module internal data */
#define DEM_PRIVATE_CONST /* Internal ROM Data */

#define DEM_APPL_CODE /* callbacks of the Application */
#define DEM_APPL_CONST /* Applications' ROM Data */
#define DEM_APPL_DATA /* Applications' RAM Data */

#define DEM_CONFIG_CONST /* Desc. Tables -> Config-dependent */
#define DEM_CONFIG_DATA /* Config. dependent (reg. size) data */

#define DEM_INIT_DATA /* Data which is initialized during
    Startup */
#define DEM_NOINIT_DATA /* Data which is not initialized during
    Startup */
#define DEM_CONST /* Data Constants */


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
 **                      Configuration data                                   **
*******************************************************************************/
/*
 * The following memory and pointer classes can be configured per module.
 * These #defines are passed to the compiler abstraction macros in Compiler.h
 *
 * Note:
 * module internal functions (statics) that get into one section
 * (together with API) shall fit into one page.
 */
/* ---------------------------------------------------------------------------*/
/*                   General                                                  */
/* ---------------------------------------------------------------------------*/
#define REGSPACE                       /* Registers                           */

/* ---------------------------------------------------------------------------*/
/*                   MCU                                                      */
/* ---------------------------------------------------------------------------*/

#define MCU_PUBLIC_CODE                /* API functions                       */
#define MCU_PUBLIC_CONST               /* API constants                       */

#define MCU_PRIVATE_CODE               /* Internal functions                  */

#define MCU_PRIVATE_DATA               /* Module internal data                */
#define MCU_PRIVATE_CONST              /* Internal ROM Data                   */

#define MCU_APPL_CODE                  /* callbacks of the Application        */
#define MCU_APPL_CONST                 /* Applications' ROM Data              */
#define MCU_APPL_DATA                  /* Applications' RAM Data              */

#define MCU_FAST_CODE                   /* API functions                       */
#define MCU_FAST_CONST                  /* API constants                       */
#define MCU_FAST_DATA                   /* API constants                       */

#define MCU_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define MCU_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define MCU_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define MCU_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define MCU_CONST                      /* Data Constants                      */
#define MCU_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define MCU_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   GPT                                                      */
/* ---------------------------------------------------------------------------*/

#define GPT_PUBLIC_CODE                /* API functions                       */
#define GPT_PUBLIC_CONST               /* API constants                       */

#define GPT_PRIVATE_CODE               /* Internal functions                  */

#define GPT_PRIVATE_DATA               /* Module internal data                */
#define GPT_PRIVATE_CONST              /* Internal ROM Data                   */

#define GPT_APPL_CODE                  /* callbacks of the Application        */
#define GPT_APPL_CONST                 /* Applications' ROM Data              */
#define GPT_APPL_DATA                  /* Applications' RAM Data              */

#define GPT_FAST_CODE                   /* API functions                       */
#define GPT_FAST_CONST                  /* API constants                       */
#define GPT_FAST_DATA                   /* API constants                       */

#define GPT_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define GPT_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define GPT_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define GPT_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define GPT_CONST                      /* Data Constants                      */
#define GPT_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define GPT_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   WDG   DRIVER A                                           */
/* ---------------------------------------------------------------------------*/

#define WDG_59_DRIVERA_PUBLIC_CODE        /* API functions                    */
#define WDG_59_DRIVERA_PUBLIC_CONST       /* API constants                    */

#define WDG_59_DRIVERA_PRIVATE_CODE       /* Internal functions               */

#define WDG_59_DRIVERA_PRIVATE_DATA       /* Module internal data             */
#define WDG_59_DRIVERA_PRIVATE_CONST      /* Internal ROM Data                */

#define WDG_59_DRIVERA_APPL_CODE          /* callbacks of the Application     */
#define WDG_59_DRIVERA_APPL_CONST         /* Applications' ROM Data           */
#define WDG_59_DRIVERA_APPL_DATA          /* Applications' RAM Data           */

#define WDG_59_DRIVERA_FAST_CODE           /* API functions                    */
#define WDG_59_DRIVERA_FAST_CONST          /* API constants                    */
#define WDG_59_DRIVERA_FAST_DATA           /* API constants                    */

#define WDG_59_DRIVERA_CONFIG_CONST       /* Desc. Tables -> Config-dependent */
#define WDG_59_DRIVERA_CONFIG_DATA        /* Config. dependent (reg. size)
                                             data                             */

#define WDG_59_DRIVERA_INIT_DATA          /* Data which is initialized during
                                             Startup                          */
#define WDG_59_DRIVERA_NOINIT_DATA        /* Data which is not initialized
                                             during Startup                   */
#define WDG_59_DRIVERA_CONST              /* Data Constants                   */
#define WDG_59_DRIVERA_VAR             /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define WDG_59_DRIVERA_VAR_NOINIT      /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   WDG   DRIVER B                                           */
/* ---------------------------------------------------------------------------*/

#define WDG_59_DRIVERB_PUBLIC_CODE        /* API functions                    */
#define WDG_59_DRIVERB_PUBLIC_CONST       /* API constants                    */

#define WDG_59_DRIVERB_PRIVATE_CODE       /* Internal functions               */

#define WDG_59_DRIVERB_PRIVATE_DATA       /* Module internal data             */
#define WDG_59_DRIVERB_PRIVATE_CONST      /* Internal ROM Data                */

#define WDG_59_DRIVERB_APPL_CODE          /* callbacks of the Application     */
#define WDG_59_DRIVERB_APPL_CONST         /* Applications' ROM Data           */
#define WDG_59_DRIVERB_APPL_DATA          /* Applications' RAM Data           */

#define WDG_59_DRIVERB_FAST_CODE           /* API functions                    */
#define WDG_59_DRIVERB_FAST_CONST          /* API constants                    */
#define WDG_59_DRIVERB_FAST_DATA           /* API constants                    */

#define WDG_59_DRIVERB_CONFIG_CONST       /* Desc. Tables -> Config-dependent */
#define WDG_59_DRIVERB_CONFIG_DATA        /* Config. dependent (reg. size)
                                             data                             */

#define WDG_59_DRIVERB_INIT_DATA          /* Data which is initialized during
                                             Startup                          */
#define WDG_59_DRIVERB_NOINIT_DATA        /* Data which is not initialized
                                             during Startup                   */
#define WDG_59_DRIVERB_CONST              /* Data Constants                   */
#define WDG_59_DRIVERB_VAR             /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define WDG_59_DRIVERB_VAR_NOINIT      /* Memory class for global variables   */
                                       /* which are initialized by driver     */
/* ---------------------------------------------------------------------------*/
/*                   WDG   DRIVER C                                           */
/* ---------------------------------------------------------------------------*/

#define WDG_59_DRIVERC_PUBLIC_CODE        /* API functions                    */
#define WDG_59_DRIVERC_PUBLIC_CONST       /* API constants                    */

#define WDG_59_DRIVERC_PRIVATE_CODE       /* Internal functions               */

#define WDG_59_DRIVERC_PRIVATE_DATA       /* Module internal data             */
#define WDG_59_DRIVERC_PRIVATE_CONST      /* Internal ROM Data                */

#define WDG_59_DRIVERC_APPL_CODE          /* callbacks of the Application     */
#define WDG_59_DRIVERC_APPL_CONST         /* Applications' ROM Data           */
#define WDG_59_DRIVERC_APPL_DATA          /* Applications' RAM Data           */

#define WDG_59_DRIVERC_FAST_CODE           /* API functions                    */
#define WDG_59_DRIVERC_FAST_CONST          /* API constants                    */
#define WDG_59_DRIVERC_FAST_DATA           /* API constants                    */

#define WDG_59_DRIVERC_CONFIG_CONST       /* Desc. Tables -> Config-dependent */
#define WDG_59_DRIVERC_CONFIG_DATA        /* Config. dependent (reg. size)
                                             data                             */

#define WDG_59_DRIVERC_INIT_DATA          /* Data which is initialized during
                                             Startup                          */
#define WDG_59_DRIVERC_NOINIT_DATA        /* Data which is not initialized
                                             during Startup                   */
#define WDG_59_DRIVERC_CONST              /* Data Constants                   */
#define WDG_59_DRIVERC_VAR             /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define WDG_59_DRIVERC_VAR_NOINIT      /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   PORT                                                     */
/* ---------------------------------------------------------------------------*/

#define PORT_PUBLIC_CODE                /* API functions                      */
#define PORT_PUBLIC_CONST               /* API constants                      */

#define PORT_PRIVATE_CODE               /* Internal functions                 */

#define PORT_PRIVATE_DATA               /* Module internal data               */
#define PORT_PRIVATE_CONST              /* Internal ROM Data                  */

#define PORT_APPL_CODE                  /* callbacks of the Application       */
#define PORT_APPL_CONST                 /* Applications' ROM Data             */
#define PORT_APPL_DATA                  /* Applications' RAM Data             */

#define PORT_FAST_CODE                   /* API functions                      */
#define PORT_FAST_CONST                  /* API constants                      */
#define PORT_FAST_DATA                   /* API constants                      */

#define PORT_CONFIG_CONST               /* Desc. Tables -> Config-dependent   */
#define PORT_CONFIG_DATA                /* Config. dependent (reg. size) data */

#define PORT_INIT_DATA                  /* Data which is initialized during
                                           Startup                            */
#define PORT_NOINIT_DATA                /* Data which is not initialized during
                                           Startup                            */
#define PORT_CONST                      /* Data Constants                     */
#define PORT_VAR                        /* Memory class for global variables  */
                                        /* which are initialized after every  */
                                        /* reset                              */
#define PORT_VAR_NOINIT                 /* Memory class for global variables  */
                                        /* which are initialized by driver    */

/* ---------------------------------------------------------------------------*/
/*                   DIO                                                      */
/* ---------------------------------------------------------------------------*/

#define DIO_PUBLIC_CODE                /* API functions                       */
#define DIO_PUBLIC_CONST               /* API constants                       */

#define DIO_PRIVATE_CODE               /* Internal functions                  */

#define DIO_PRIVATE_DATA               /* Module internal data                */
#define DIO_PRIVATE_CONST              /* Internal ROM Data                   */

#define DIO_APPL_CODE                  /* callbacks of the Application        */
#define DIO_APPL_CONST                 /* Applications' ROM Data              */
#define DIO_APPL_DATA                  /* Applications' RAM Data              */

#define DIO_FAST_CODE                   /* API functions                       */
#define DIO_FAST_CONST                  /* API constants                       */
#define DIO_FAST_DATA                   /* API constants                       */

#define DIO_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define DIO_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define DIO_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define DIO_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define DIO_CONST                      /* Data Constants                      */
#define DIO_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define DIO_VAR_INIT                   /* Memory class for global variables   */
                                       /* which are initialized by RAM     */
#define DIO_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   FEE                                                      */
/* ---------------------------------------------------------------------------*/

#define FEE_PUBLIC_CODE                /* API functions                       */
#define FEE_PUBLIC_CONST               /* API constants                       */

#define FEE_PRIVATE_CODE               /* Internal functions                  */

#define FEE_PRIVATE_DATA               /* Module internal data                */
#define FEE_PRIVATE_CONST              /* Internal ROM Data                   */

#define FEE_APPL_CODE                  /* callbacks of the Application        */
#define FEE_APPL_CONST                 /* Applications' ROM Data              */
#define FEE_APPL_DATA                  /* Applications' RAM Data              */

#define FEE_FAST_CODE                   /* API functions                       */
#define FEE_FAST_CONST                  /* API constants                       */
#define FEE_FAST_DATA                   /* API constants                       */

#define FEE_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define FEE_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define FEE_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define FEE_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define FEE_CONST                      /* Data Constants                      */
#define FEE_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define FEE_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   PWM                                                      */
/* ---------------------------------------------------------------------------*/

#define PWM_PUBLIC_CODE                /* API functions                       */
#define PWM_PUBLIC_CONST               /* API constants                       */

#define PWM_PRIVATE_CODE               /* Internal functions                  */

#define PWM_PRIVATE_DATA               /* Module internal data                */
#define PWM_PRIVATE_CONST              /* Internal ROM Data                   */

#define PWM_APPL_CODE                  /* callbacks of the Application        */
#define PWM_APPL_CONST                 /* Applications' ROM Data              */
#define PWM_APPL_DATA                  /* Applications' RAM Data              */

#define PWM_FAST_CODE                   /* API functions                       */
#define PWM_FAST_CONST                  /* API constants                       */
#define PWM_FAST_DATA                   /* API constants                       */

#define PWM_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define PWM_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define PWM_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define PWM_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define PWM_CONST                      /* Data Constants                      */
#define PWM_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define PWM_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   SPI                                                      */
/* ---------------------------------------------------------------------------*/

#define SPI_PUBLIC_CODE                /* API functions                       */
#define SPI_PUBLIC_CONST               /* API constants                       */

#define SPI_PRIVATE_CODE               /* Internal functions                  */

#define SPI_PRIVATE_DATA               /* Module internal data                */
#define SPI_PRIVATE_CONST              /* Internal ROM Data                   */

#define SPI_APPL_CODE                  /* callbacks of the Application        */
#define SPI_APPL_CONST                 /* Applications' ROM Data              */
#define SPI_APPL_DATA                  /* Applications' RAM Data              */

#define SPI_FAST_CODE                   /* API functions                       */
#define SPI_FAST_CONST                  /* API constants                       */
#define SPI_FAST_DATA                   /* API constants                       */

#define SPI_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define SPI_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define SPI_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define SPI_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define SPI_CONST                      /* Data Constants                      */
#define SPI_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define SPI_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   ADC                                                      */
/* ---------------------------------------------------------------------------*/

#define ADC_PUBLIC_CODE                /* API functions                       */
#define ADC_PUBLIC_CONST               /* API constants                       */

#define ADC_PRIVATE_CODE               /* Internal functions                  */

#define ADC_PRIVATE_DATA               /* Module internal data                */
#define ADC_PRIVATE_CONST              /* Internal ROM Data                   */

#define ADC_APPL_CODE                  /* callbacks of the Application        */
#define ADC_APPL_CONST                 /* Applications' ROM Data              */
#define ADC_APPL_DATA                  /* Applications' RAM Data              */

#define ADC_FAST_CODE                   /* API functions                       */
#define ADC_FAST_CONST                  /* API constants                       */
#define ADC_FAST_DATA                   /* API constants                       */

#define ADC_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define ADC_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define ADC_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define ADC_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define ADC_CONST                      /* Data Constants                      */
#define ADC_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ADC_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   ICU                                                      */
/* ---------------------------------------------------------------------------*/

#define ICU_PUBLIC_CODE                /* API functions                       */
#define ICU_PUBLIC_CONST               /* API constants                       */

#define ICU_PRIVATE_CODE               /* Internal functions                  */

#define ICU_PRIVATE_DATA               /* Module internal data                */
#define ICU_PRIVATE_CONST              /* Internal ROM Data                   */

#define ICU_APPL_CODE                  /* callbacks of the Application        */
#define ICU_APPL_CONST                 /* Applications' ROM Data              */
#define ICU_APPL_DATA                  /* Applications' RAM Data              */

#define ICU_FAST_CODE                   /* API functions                       */
#define ICU_FAST_CONST                  /* API constants                       */
#define ICU_FAST_DATA                   /* API constants                       */

#define ICU_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define ICU_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define ICU_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define ICU_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define ICU_CONST                      /* Data Constants                      */
#define ICU_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ICU_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */


/* -------------------------------------------------------------------------- */
/*             FlexRay Driver                                                 */
/* -------------------------------------------------------------------------- */
#define FR_PRIVATE_CODE                /* module internal functions           */
#define FR_PRIVATE_CONST               /* module internal consts              */
#define FR_PRIVATE_DATA                /* module internal data                */

#define FR_PUBLIC_CODE                 /* API functions                       */
#define FR_PUBLIC_CONST                /* API constants                       */
#define FR_CODE
#define FR_APPL_CODE                   /* callbacks of the Application        */
#define FR_APPL_CONST                  /* Applications' ROM Data              */

#define FR_FAST_CODE                   /* API functions                        */
#define FR_FAST_CONST                  /* API constants                        */
#define FR_FAST_DATA                   /* API constants                        */

#define FR_INIT_DATA                   /* module variables                    */
#define FR_CONST                       /* module constants                    */

#define FR_VAR_NO_INIT                 /* module variables that are           */
                                              /* not initialized              */
#define FR_VAR_POWER_ON_INIT           /* module variables that are           */
                                             /* initialized on Powerup        */
#define FR_VAR                         /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define FR_VAR_NOINIT                  /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/*
 * the applications' data blocks must have the same classifier
 * like the EEPIF expects
 */
#define FR_APPL_DATA              /* Applications' Ram Data                   */
#define FR_CONFIG_CONST           /* Descriptor Tables -> Config-dependent    */
#define FR_CONFIG_DATA            /* Configuration dependent (reg. size) data */
#define FR_DATA                   /* Global Variables                         */

/* ---------------------------------------------------------------------------*/
/*                   CAN                                                      */
/* ---------------------------------------------------------------------------*/

#define CAN_RSCAN_PUBLIC_CODE          /* API functions                       */
#define CAN_RSCAN_PUBLIC_CONST         /* API constants                       */

#define CAN_RSCAN_PRIVATE_CODE         /* Internal functions                  */

#define CAN_RSCAN_PRIVATE_DATA         /* Module internal data                */
#define CAN_RSCAN_PRIVATE_CONST        /* Internal ROM Data                   */

#define CAN_RSCAN_APPL_CODE            /* callbacks of the Application        */
#define CAN_RSCAN_APPL_CONST           /* Applications' ROM Data              */
#define CAN_RSCAN_APPL_DATA            /* Applications' RAM Data              */
#define CAN_RSCAN_FAST_DATA            /* 'Near' RAM Data                     */

#define CAN_RSCAN_FAST_CODE            /* API functions                       */
#define CAN_RSCAN_FAST_CONST           /* API constants                       */


#define CAN_RSCAN_CONFIG_CONST         /* Desc. Tables -> Config-dependent    */
#define CAN_RSCAN_CONFIG_DATA          /* Config. dependent (reg. size) data  */

#define CAN_RSCAN_INIT_DATA            /* Data which is initialized during
                                          Startup                             */
#define CAN_RSCAN_NOINIT_DATA          /* Data which is not initialized during
                                          Startup                             */
#define CAN_RSCAN_CONST                /* Data Constants                      */
#define CAN_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define CAN_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

                                     /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   FLS                                                      */
/* ---------------------------------------------------------------------------*/

#define FLS_PUBLIC_CODE                /* API functions                       */
#define FLS_PUBLIC_CONST               /* API constants                       */

#define FLS_PRIVATE_CODE               /* Internal functions                  */

#define FLS_PRIVATE_DATA               /* Module internal data                */
#define FLS_PRIVATE_CONST              /* Internal ROM Data                   */

#define FLS_APPL_CODE                  /* callbacks of the Application        */
#define FLS_APPL_CONST                 /* Applications' ROM Data              */
#define FLS_APPL_DATA                  /* Applications' RAM Data              */
#define FLS_FAST_DATA                  /* 'Near' RAM Data                     */

#define FLS_FAST_CODE                   /* API functions                       */
#define FLS_FAST_CONST                  /* API constants                       */
#define FLS_FAST_DATA                   /* API constants                       */

#define FLS_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define FLS_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define FLS_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define FLS_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define FLS_CONST                      /* Data Constants                      */
#define FLS_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define FLS_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */

/* ---------------------------------------------------------------------------*/
/*                   FLSTST                                                   */
/* ---------------------------------------------------------------------------*/

#define FLSTST_PUBLIC_CODE                /* API functions                    */
#define FLSTST_PRIVATE_CODE               /* Internal functions               */
#define FLSTST_PUBLIC_CONST               /* API constants                    */

#define FLSTST_APPL_CODE                  /* callbacks of the Application        */
#define FLSTST_APPL_CONST                 /* Applications' ROM Data              */
#define FLSTST_APPL_DATA                  /* Applications' RAM Data              */
#define FLSTST_FAST_DATA                  /* 'Near' RAM Data                     */

#define FLSTST_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define FLSTST_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define FLSTST_INIT_DATA                  /* Data which is initialized during    */
                                          /*Startup                              */
#define FLSTST_NOINIT_DATA                /* Data which is not initialized during */
                                          /*Startup                              */
#define FLSTST_CONST                      /* Data Constants                      */
#define FLSTST_FAST_CODE                   /* API functions                       */
#define FLSTST_FAST_CONST                  /* API constants                       */
#define FLSTST_FAST_DATA                   /* API constants                       */

/* ---------------------------------------------------------------------------*/
/*                   CORTST                                                   */
/* ---------------------------------------------------------------------------*/

#define CORTST_PUBLIC_CODE             /* API functions                       */
#define CORTST_PRIVATE_CODE            /* Internal functions                  */

#define CORTST_APPL_CODE               /* callbacks of the Application        */
#define CORTST_APPL_DATA               /* Applications' RAM Data              */

#define CORTST_CONFIG_CONST            /* Desc. Tables -> Config-dependent    */
#define CORTST_CONFIG_DATA             /* Config. dependent (reg. size) data  */

#define CORTST_INIT_DATA               /* Data which is initialized during    */
                                       /* Startup                             */
#define CORTST_NOINIT_DATA             /* Data which is not initialized during*/
                                       /* Startup                             */
#define CORTST_CONST                   /* Data Constants                      */
#define CORTST_FAST_CODE               /* API functions                       */

/* ---------------------------------------------------------------------------*/
/*                   RAMTST                                                   */
/* ---------------------------------------------------------------------------*/

#define RAMTST_PUBLIC_CODE                /* API functions                    */
#define RAMTST_PUBLIC_CONST               /* API constants                    */

#define RAMTST_PRIVATE_CODE               /* Internal functions               */

#define RAMTST_PRIVATE_DATA               /* Module internal data             */
#define RAMTST_PRIVATE_CONST              /* Internal ROM Data                */

#define RAMTST_APPL_CODE                  /* callbacks of the Application     */
#define RAMTST_APPL_CONST                 /* Applications' ROM Data           */
#define RAMTST_APPL_DATA                  /* Applications' RAM Data           */
#define RAMTST_FAST_DATA                  /* 'Near' RAM Data                  */


#define RAMTST_CONFIG_CONST               /* Desc. Tables -> Config-dependent */
#define RAMTST_CONFIG_DATA                /* Config. dependent (reg. size)
                                                                        data  */

#define RAMTST_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define RAMTST_NOINIT_DATA                /* Data which is not initialized
                                          during Startup                      */
#define RAMTST_CONST                      /* Data Constants                   */

#define RAMTST_CODE

/* ---------------------------------------------------------------------------*/
/*                   ETH                                                      */
/* ---------------------------------------------------------------------------*/

#define ETH_59_PUBLIC_CODE                /* API functions                       */
#define ETH_59_PUBLIC_CONST               /* API constants                       */

#define ETH_59_PRIVATE_CODE               /* Internal functions                  */

#define ETH_59_PRIVATE_DATA               /* Module internal data                */
#define ETH_59_PRIVATE_CONST              /* Internal ROM Data                   */

#define ETH_59_APPL_CODE                  /* callbacks of the Application        */
#define ETH_59_APPL_CONST                 /* Applications' ROM Data              */
#define ETH_59_APPL_DATA                  /* Applications' RAM Data              */

#define ETH_59_FAST_CODE                   /* API functions                       */
#define ETH_59_FAST_CONST                  /* API constants                       */
#define ETH_59_FAST_DATA                   /* API constants                       */

#define ETH_59_CONFIG_CONST               /* Desc. Tables -> Config-dependent    */
#define ETH_59_CONFIG_DATA                /* Config. dependent (reg. size) data  */

#define ETH_59_INIT_DATA                  /* Data which is initialized during
                                          Startup                             */
#define ETH_59_NOINIT_DATA                /* Data which is not initialized during
                                          Startup                             */
#define ETH_59_CONST                      /* Data Constants                      */
#define ETH_59_VAR                        /* Memory class for global variables   */
                                       /* which are initialized after every   */
                                       /* reset                               */
#define ETH_59_VAR_NOINIT                 /* Memory class for global variables   */
                                       /* which are initialized by driver     */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
 *   DEM END
 *******************************************************************************/
/*******************************************************************************
 *   DEM END
 *******************************************************************************/

#endif/* _COMPILER_CFG_H_ */
