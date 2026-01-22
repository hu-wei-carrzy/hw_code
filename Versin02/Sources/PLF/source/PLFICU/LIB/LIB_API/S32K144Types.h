#ifndef _S32K144TYPES_H_
#define _S32K144TYPES_H_


typedef unsigned char boolean_t;
typedef unsigned char		uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned long int   uint32_t;
typedef long int   			int32_t ;
typedef unsigned long long uint64_t;


/** generic error codes */
typedef enum en_result
{
    Ok                          = 0,  ///< No error
    Error                       = 1,  ///< Non-specific error code
    ErrorAddressAlignment       = 2,  ///< Address alignment does not match
    ErrorAccessRights           = 3,  ///< Wrong mode (e.g. user/system) mode is set
    ErrorInvalidParameter       = 4,  ///< Provided parameter is not valid
    ErrorOperationInProgress    = 5,  ///< A conflicting or requested operation is still in progress
    ErrorInvalidMode            = 6,  ///< Operation not allowed in current mode
    ErrorUninitialized          = 7,  ///< Module (or part of it) was not initialized properly
    ErrorBufferFull             = 8,  ///< Circular buffer can not be written because the buffer is full
    ErrorTimeout                = 9   ///< A requested operation could not be completed
} en_result_t;

 /**
 *****************************************************************************
 ** \brief ICU edge detection
 ** 
 ** Enum for the different possible edge detection modes
 *****************************************************************************/
typedef enum en_icu_edge_detection
{
    IcuNoEdge      = 0x00, /*!< Edge detection is disabled, hence the channel is disabled */
    IcuRisingEdge  = 0x01, /*!< Detect only rising edges */
    IcuFallingEdge = 0x02, /*!< Detect only falling edges */
    IcuBothEdges   = 0x03  /*!< Detect all edges */
} en_icu_edge_detection_t;

/** function pointer type to void/void function*/
typedef void (*func_ptr_t)(void);

/**
 *****************************************************************************
 ** \brief ICU channel configuration
 ** 
 ** The ICU configuration is done on a per channel basis
 *****************************************************************************/
typedef struct stc_icu_channel_config
{
    /** Set edge detection mode (enables the channel if != IcuNoEdge) */
    en_icu_edge_detection_t   enEdgeDetection; 

    /** \brief Interrupt callback for edge detection event interrupt */
    /** If a NULL pointer is provided by the application, the corresponding */
    /** interrupt will not be enabled. */
    func_ptr_t                pfnCallback;  
} stc_icu_channel_config_t;

 
#ifndef TRUE
    /** Value is true (boolean_t type) */
    #define TRUE        ((boolean_t) 1)
#endif

#ifndef FALSE
    /** Value is false (boolean_t type) */
    #define FALSE       ((boolean_t) 0)
#endif
#endif
