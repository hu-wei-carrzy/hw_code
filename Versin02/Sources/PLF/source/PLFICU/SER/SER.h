
#ifndef _SER_H_
#define _SER_H_ (1)

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "ARCH_CFG.h"

#include "SER_LIB.h"


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

// The following constants define the "DataType" parameter used in mSERRead
// and mSERWrite macro.
// By concatenation, they'll form new macro. As a consequence, those constants
// don't have to respect classical programmation rules.

// unsigned 1 bit data
#ifdef	U1Bit
  #error "You must not define U1Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // U1Bit

// unsigned 8 bit data
#ifdef	U8Bit
  #error "You must not define U8Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // U8Bit

// signed 8 bit data
#ifdef	S8Bit
  #error "You must not define S8Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // S8Bit

// unsigned 16 bit data
#ifdef	U16Bit
  #error "You must not define U16Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // U16Bit

// signed 16 bit data
#ifdef	S16Bit
  #error "You must not define S16Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // S16Bit

// unsigned 32 bit data
#ifdef	U32Bit
  #error "You must not define U32Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // U32Bit

// signed 32 bit data
#ifdef	S32Bit
  #error "You must not define S32Bit. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // S32Bit


// The following constants define the "processingType" parameter used in mSERRead
// and mSERWrite macro.

#ifdef	Default
  #error "You must not define Default. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // Default

#ifdef	Immediate
  #error "You must not define Immediate. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // Immediat

#ifdef	Delayed
  #error "You must not define Delayed. This lexem is concatenated with mSERRead and mSERWrite macro."
#endif // Differe

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/

//////////////////////////   CONSOMMATION    /////////////////////////////////
#define mSERRead(DataType, DataName, TreatmentType)	\
        mSERRead2(DataType, DataName, TreatmentType)

#define mSERRead2(DataType, DataName, TreatmentType)	\
	mSERRead ## DataType ## DataName ## TreatmentType()

#define mSERReadBuffer(DataName, Index, TreatmentType)	\
        mSERReadBuffer2(DataName, Index, TreatmentType)

#define mSERReadBuffer2(DataName, Index, TreatmentType)	\
	mSERReadBuffer ## DataName ## TreatmentType( Index )

#define mSERReadTable(DataType, ArrayName, Index, TreatmentType)	\
        mSERReadTable2(DataType, ArrayName, Index, TreatmentType)
#define mSERReadTable2(DataType, ArrayName, Index, TreatmentType)	\
	mSERReadTable ## DataType ## ArrayName ## TreatmentType( Index )

#define mSERReadStruct(DataType, DataName, pDestination, TreatmentType)	\
        mSERReadStruct2(DataType, DataName, pDestination, TreatmentType)
#define mSERReadStruct2(DataType, DataName, pDestination, TreatmentType)	\
	mSERReadStruct ## DataType ## DataName ## TreatmentType( pDestination )

//new add for 502 2016Äê11ÔÂ22ÈÕ 11:33:39,zjb
#define mSERReadDBuffer(BufferName, First, Second, TreatmentType) \
     mSERReadDBuffer2(BufferName, First, Second, TreatmentType)

#define mSERReadDBuffer2(BufferName, First, Second, TreatmentType) \
    mSERReadDBuffer ## BufferName ## TreatmentType (First, Second)

//new add for502
#define mSERReadMsgBuffer(Datatype,MsgName,Index,Treatmenttype)  \
	mSERReadMsgBuffer2(Datatype,MsgName,Index,Treatmenttype)

#define mSERReadMsgBuffer2(Datatype,MsgName,Index,Treatmenttype) \
        mDATCplGetBuffer(MsgName)[Index]

#define mSERWriteMsgBuffer(Datatype,MsgName,Index,Value,Treatmenttype)  \
	mSERWriteMsgBuffer2(Datatype,MsgName,Index,Value,Treatmenttype)

#define mSERWriteMsgBuffer2(Datatype,MsgName,Index,Value,Treatmenttype) \
        mDATCplGetBuffer(MsgName)[Index] = (Value)

//////////////////////////    PRODUCTION    /////////////////////////////////
#define mSERWrite(DataType, DataName, ValueToWrite, TreatmentType)	\
        mSERWrite2(DataType, DataName, ValueToWrite, TreatmentType)

#define mSERWrite2(DataType, DataName, ValueToWrite, TreatmentType)	\
	mSERWrite ## DataType ## DataName ## TreatmentType( ValueToWrite )

#define mSERWriteBuffer(DataName, Index, ValueToWrite, TreatmentType)	\
        mSERWriteBuffer2(DataName, Index, ValueToWrite, TreatmentType)

#define mSERWriteBuffer2(DataName, Index, ValueToWrite, TreatmentType)	\
	mSERWriteBuffer ## DataName ## TreatmentType( Index, ValueToWrite )

#define mSERWriteTable(DataType, ArrayName, Index, ValueToWrite, TreatmentType)	\
        mSERWriteTable2(DataType, ArrayName, Index, ValueToWrite, TreatmentType)

#define mSERWriteTable2(DataType, ArrayName, Index, ValueToWrite, TreatmentType)	\
	mSERWriteTable ## DataType ## ArrayName ## TreatmentType( Index, ValueToWrite )

#define mSERWriteStruct(DataType, DataName, pSource, TreatmentType)	\
        mSERWriteStruct2(DataType, DataName, pSource, TreatmentType)

#define mSERWriteStruct2(DataType, DataName, pSource, TreatmentType)	\
	mSERWriteStruct ## DataType ## DataName ## TreatmentType( pSource )

//////////////////////////    CONTROLE    /////////////////////////////////

#define mSERControl(Objet,Controle)\
    mSERControl##Objet(Controle)

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

/*-------------------------------------------------------------------------
  End of includes non re entry
  -------------------------------------------------------------------------*/
#endif   /* _SER_H_ */

