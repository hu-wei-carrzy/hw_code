

#ifndef I_LIB_H
#define I_LIB_H (1)


/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "deftypes.h"

#include "ARCH_CFG.h"


#ifdef cHeadIncludeType_Directly
#include "lib_itp.h"
#include "lib_crc.h"
#include "lib_queue.h"
#else
#include ".\..\LIB_ITP\lib_itp.h"
#include ".\..\LIB_CRC\lib_crc.h"
#include ".\..\LIB_QUEUE\lib_queue.h"
#endif

#ifdef cHeadIncludeType_Directly
#include "LIB_VER.h"
#else
#include ".\..\LIB_VER\LIB_VER.h"
#endif


#ifndef _QAC_
    #ifdef COMPILATION_NATIVE
      #include <string.h>
      #ifndef UTEST
        #include <assert.h>
      #else
        #include "Testeur.h"
      #endif //UTEST
    #else
      #include <string.h>

// if your compiler's libraries define correctly the function assert,
// you can include Assert.h. Else, you can use the default managment.

// #include <assert.h>

// The default management calls the function LIBAssertionFailed when a
// error is detected. The macro is not defined when DEBUG option is not
// set.
    #endif
#else
// System's libraries are not includes in QAC configuration
#endif

/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/
#define cU16ADBaseVol   ((U16)4763U)

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 




#ifndef _QAC_

    #define mLIBmemset(ptr,mtf,len) memset( ptr, mtf, len )
    #define mLIBmemcpy(ptr,src,len) memcpy( ptr, src, len )
    #define mLIBmemcmp(ptr,src,len) memcmp( ptr, src, len )

    #ifdef COMPILATION_NATIVE
        #ifndef ATTOL_COV
            #ifndef UTEST
                #define mLIBassert(Condition)   assert( Condition )
            #else
                #define mLIBassert(Condition)   mTSTAssert(Condition)
            #endif
        #else
// In the configuration ATTOL COVERAGE
// Assert are not defined.
            #define mLIBassert(Condition)
        #endif
    #else
// If your compiler define assert, you can use this macro :
// #define mLIBassert(Condition)   assert( Condition )

// The default management calls the function LIBAssertionFailed when
// a error is detected. The macro is not defined when DEBUG option
// is not set.
           #ifdef DEBUG
                #define mLIBassert(Condition) \
                    if((Condition) == cFalse) \
                    {                         \
                        LIBAssertionFailed(__FILE__, sizeof(__FILE__), __LINE__); \
                    }
            #else
                #define mLIBassert(Condition)

            #endif
    #endif
#else
// QAC configuration
extern void NOP(void);
extern void *memconsumer;

extern int QACmemcmp( const void *ptr,const void *src, unsigned int len);
extern void * QACmemcpy(void *ptr, const void *src, unsigned int len);
extern void * QACmemset(void *ptr, int mtf, unsigned int len);
extern void QACassert(int Condition);

    #define mLIBmemset(ptr,mtf,len) (memconsumer = QACmemset(ptr,mtf,len))
    #define mLIBmemcpy(ptr,src,len) (memconsumer = QACmemcpy(ptr, src, len))
    #define mLIBmemcmp(ptr,src,len) QACmemcmp(ptr,src,len)
    #define mLIBassert(Condition)   QACassert(Condition)
#endif

//单元测试所用，用于兼容单元测试环境
#define UTPrintf1(Par1)
#define UTPrintf2(Par1,Par2)
#define UTPrintf3(Par1,Par2,Par3)
#define UTPrintf4(Par1,Par2,Par3,Par4)
#define UTPrintf5(Par1,Par2,Par3,Par4,Par5)

#define UTFuncEnter(funcName)
#define UTFuncLeave(funcName)

#ifdef PCDEBUG
#define mPCDebugErr()           while(1){(*(U32*)0xFFFFFFFF) = 1U;}
#define mPChkHandle(Handle)     if(cU8InValidHadnle == (Handle)){(*(U32*)0xFFFFFFFF) = 1U;}

#else
#define mPCDebugErr()
#define mPChkHandle(Handle)
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
//Semaphore macros...
#define mLIBSetSemaphore(Semaphore)                                            \
    Semaphore = cTrue

#define mLIBClearSemaphore(Semaphore)                                          \
    Semaphore = cFalse

#define mLIBIsSemaphoreSet(Semaphore)                                          \
    (BOOL)((Semaphore) != cFalse)

#define mLIBIsSemaphoreCleared(Semaphore)                                      \
    (BOOL)((Semaphore) == cFalse)



#define IRQ_DISABLE_LOCAL()  __asm volatile ("cpsid i" : : : "memory");


#define IRQ_RESTORE()  __asm volatile ("cpsie i" : : : "memory");
//...end of semaphore macros.
/*-------------------------------------------------------------------------
  Constant exported data

  extern const tType  CMPVariableName;
  -------------------------------------------------------------------------*/ 

/*-------------------------------------------------------------------------
  Exported functions

  extern tReturnType CMPFunctionName(tTypeArgument1 ArgumentName1, ... );
  -------------------------------------------------------------------------*/ 
extern void LIBAssertionFailed(char *file_name, U32 file_name_length, U32 line_num);
extern BOOL DATPanIsIgOn(void);
extern void TOSSchedule(void);
extern U32  LIBGetCurTime(void );
/*extern U16 LIBGetADBaseVol(void);*/

#define LIBGetADBaseVol()     cU16ADBaseVol



//this is a control key for CPU Load test.
//#define TRACE_CPU_ACTIVE

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif /* I_LIB_H */
