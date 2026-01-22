

#ifndef I_DAT_CPUP_H
#define I_DAT_CPUP_H

//----------------------------------------------------------------------------------------------------------------------
// Included files to resolve specific definitions in this file
//----------------------------------------------------------------------------------------------------------------------
//#include "deftypes.h"
#include "ARCH_CFG.h"


#include "DAT_CPU_INCLUDE.h"
//Set cDATCpuWatermarkResetAddress in the section for target to end_of_the_stack address.
//If the stack is not at fixed position, its end address could be determined from the map file.
//If the stack usage overwrites the value at this address, the target is reset.
//Optionally, cDATCpuWatermarkAssertAddress could be set in the target section to point somewhere
//in the stack just for having a notification (assertion) when running a debug version on the target
//and the stack usage overwrites the value there.
//Generally, both addresses should be multiply of 4 (the two less significant bits equal to zero).

//To help the development to choose an adequate stack size, unused stack space measurement functionality is available.
//By default it is enabled when cDATCpuWatermarkResetAddress is defined.
//Currently the calculated value could be seen on the emulator: global variable u32DATCpuUnUsedStackSize.

//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------
#define cGraphEnginePeriodMs    ((U32)20UL)

// The watch-dog allow to check if the software is blocked in a loop.
// According to the priority of the task, there is to value of timeout :
// if the task priority is greater than watchdog task the timeout is
// - cRefreshWatchDogPeriodMs
// if the task priority is lower than watchdog task the timeout is
// - cWatchDogIdleTaskTimeoutMs
#define cRefreshWatchDogPeriodMs            ((U32)640U)//    ((U32)80UL)
#define cWatchDogIdleTaskTimeoutMs        ((U32)640U)  // ((U32)1000UL)

#ifdef COMPILATION_NATIVE
// settings for  Windows unit test
// DO NOT EDIT!
    #define cDATCpuWinSimStackSize 100
    #define cDATCpuWatermarkAssertAddress &DATCpuWinSimStack[cDATCpuWinSimStackSize/3]
    #define cDATCpuWatermarkAssertValue cDATCpuWatermarkDefaultValue
    #define cDATCpuWatermarkResetValue cDATCpuWatermarkDefaultValue
#else
// settings for target
    //extern U8 _systemstack;
    //extern U8 _systemstack_top;

    //
    //extern from link file,
	//value: Top>Limit
	extern unsigned long int __StackTop[];
	extern unsigned long int __StackLimit[];


// TODO: set values according to your target
    // stack assert watermark
    // if enabled,  it is recommended to be = stack_end - 10% stack size
    //#define cDATCpuWatermarkAssertAddress cDATCpuWatermarkDisable
    //#define cDATCpuWatermarkAssertAddress       \
    //    (U32)(((((U32)(ADDRESS_USR_STACK_END) - (U32)(ADDRESS_BOOT_USR_STACK_END)) >> 3U) + (U32)(ADDRESS_BOOT_USR_STACK_END)) & (U32)0xFFFFFFFCU)


	#define cDATCpuWatermarkAssertAddress \
	           (U32)(((((U32)(__StackTop) - (U32)(__StackLimit)) >> 3U) + (U32)(__StackLimit)) & (U32)0xFFFFFFFCU)


    #define cDATCpuWatermarkAssertValue cDATCpuWatermarkDefaultValue
    // stack reset watermark
    // if enabled, it is recommended to be = stack_end for downward
    // (decreasing in depth) stack, and = stack_end - 4 for upward (increasing in depth)
    // stack.
    //#define cDATCpuWatermarkResetAddress cDATCpuWatermarkDisable
	//#define cDATCpuWatermarkResetAddress ADDRESS_BOOT_USR_STACK_END //(U32)(&_systemstack)

	#define cDATCpuWatermarkResetAddress   (__StackLimit + 32)
    #define cDATCpuWatermarkResetValue cDATCpuWatermarkDefaultValue
#endif

//Stack unused space measurement:
#define cDATCpuStackContentsValue	 ((U8)0x5AU) // value to fill initially the stack with, old is 0X69

//Stack overflow protection:
// if assigned to watermark address, disables corresponding check and action
#define cDATCpuWatermarkDisable ((U32)0x00UL)
// or other value, but do not use 0
#define cDATCpuWatermarkDefaultValue ((U32)0x0BADBAD0UL)

// By default the unused stack size is periodically measured in idle processing.
// Define DISABLE_IDLE_MEASURE in order to save runtime performance in idle processing and bit of a RAM (4 bytes).
// Alternative to check the unused stack size in this case will be to use a dedicated diagnostic service.
// #define DISABLE_IDLE_MEASURE 

#if !defined(DEBUG)
//¨¨¨ª?t¡¤¡é2?¨º¡À¡ê?¨°??¡§¨°a???1¡ä?1|?¨¹¡ê?2?¨º1¨®??????¨¬2a1|?¨¹?¡ê
#define DISABLE_IDLE_MEASURE
#endif

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------
typedef U32 tDATCpuStackWatermarkValue;  // normally 32 bits is an adequate choice here, probably on some 8 bit MCUs 16 bits could be prefered

//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------
#ifdef COMPILATION_NATIVE
// settings for  Windows unit test
// DO NOT EDIT!
    // we will simulate the stack in an array, just to be able to run the Windows unit test on it
    extern tDATCpuStackWatermarkValue DATCpuWinSimStack[];
    // only for unit testing in Windows: true when stack overflow reset will be called on target
    extern BOOL bDATCpuWinSimReset;
    // only for unit testing in Windows: false when assert watermark is overwritten
    extern BOOL bDATCpuFirstWatermarkAssert;
    // only for unit testing in Windows
    extern U32 u32DATCpuUnUsedStackSize;
    // the following two are manipulated from the unit test in order to be able
    //to test both upward and downward stacks
    extern tDATCpuStackWatermarkValue *cDATCpuWatermarkResetAddress;
    extern U8 *pDATCpuInStack;
#else
// settings for target
    extern U32 u32DATCpuUnUsedStackSize;
#endif


// #define DAT_CPU_ENABLE_HALT // To be use only on V850 ES Fx3Sx3Dx3

//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------
#ifdef COMPILATION_NATIVE
// settings for  Windows unit test
// DO NOT EDIT!
    #define mDATCpuGetUnUsedStackSizeEnabled() (cTrue)
#else
// settings for target
// TODO:
// in the final product this functionality should be disabled!
//this is for release version
#if defined(DISABLE_IDLE_MEASURE)
 #define mDATCpuGetUnUsedStackSizeEnabled() (cFalse)  
#else
 #define mDATCpuGetUnUsedStackSizeEnabled() (cFalse)
#endif
//this macro for CPU stack test
//  #define mDATCpuGetUnUsedStackSizeEnabled() (cDATCpuWatermarkResetAddress != cDATCpuWatermarkDisable)
// if enabled, see variable u32DATCpuUnUsedStackSize value in emulator
#endif

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
#endif   /* I_DAT_CPUP_H */
