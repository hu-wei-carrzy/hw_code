
#ifndef I_DAT_H
#define I_DAT_H (1)

/*-------------------------------------------------------------------------
  Included files to resolve specific definitions in this file

  #include <system_file_name.h>
  #include "project_file_name.h"
  -------------------------------------------------------------------------*/
#include "deftypes.h"
#include "DATparam.h"


/*-------------------------------------------------------------------------
  Constant data

  #define cCMPConstantName   ((tType) ConstantValue)
  -------------------------------------------------------------------------*/

// The following constants define the "DataType" parameter used in mDATRead
// and MDatWrite macro.
// By concatenation, they'll form new macro. As a consequence, those constants
// don't have to respect classical programmation rules.

// unsigned 1 bit data
#ifdef	U1Bit
  #error "You must not define U1Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // U1Bit

// unsigned 8 bit data
#ifdef	U8Bit
  #error "You must not define U8Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // U8Bit

// signed 8 bit data
#ifdef	S8Bit
  #error "You must not define S8Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // S8Bit

// unsigned 16 bit data
#ifdef	U16Bit
  #error "You must not define U16Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // U16Bit

// signed 16 bit data
#ifdef	S16Bit
  #error "You must not define S16Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // S16Bit

// unsigned 32 bit data
#ifdef	U32Bit
  #error "You must not define U32Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // U32Bit

// signed 32 bit data
#ifdef	S32Bit
  #error "You must not define S32Bit. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // S32Bit


// The following constants define the "processingType" parameter used in mDATRead
// and MDatWrite macro.

#ifdef	Default
  #error "You must not define Default. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // Default

#ifdef	Immediate   
  #error "You must not define Immediate. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // Immediat

#ifdef	Delayed	   
  #error "You must not define Delayed. This lexem is concatenated with mDATRead and mDATWrite macro."
#endif // Differe

/*-------------------------------------------------------------------------
  Exported Macro

  #define mCMPMacroName   (MacroDefinition)
  -------------------------------------------------------------------------*/ 

//////////////////////////   CONSOMMATION    /////////////////////////////////
#define mDATRead(DataType, DataName, TreatmentType)	\
        mDATRead2(DataType, DataName, TreatmentType)

#define mDATRead2(DataType, DataName, TreatmentType)	\
	mDATRead ## DataType ## DataName ## TreatmentType()

#define mDATReadBuffer(DataName, Index, TreatmentType)	\
        mDATReadBuffer2(DataName, Index, TreatmentType)

#define mDATReadBuffer2(DataName, Index, TreatmentType)	\
	mDATReadBuffer ## DataName ## TreatmentType( Index )

#define mDATReadTable(DataType, ArrayName, Index, TreatmentType)	\
        mDATReadTable2(DataType, ArrayName, Index, TreatmentType)
#define mDATReadTable2(DataType, ArrayName, Index, TreatmentType)	\
	mDATReadTable ## DataType ## ArrayName ## TreatmentType( Index )

#define mDATReadStruct(DataType, DataName, pDestination, TreatmentType)	\
        mDATReadStruct2(DataType, DataName, pDestination, TreatmentType)
#define mDATReadStruct2(DataType, DataName, pDestination, TreatmentType)	\
	mDATReadStruct ## DataType ## DataName ## TreatmentType( pDestination )



//////////////////////////    PRODUCTION    /////////////////////////////////
#define mDATWrite(DataType, DataName, ValueToWrite, TreatmentType)	\
        mDATWrite2(DataType, DataName, ValueToWrite, TreatmentType)

#define mDATWrite2(DataType, DataName, ValueToWrite, TreatmentType)	\
	mDATWrite ## DataType ## DataName ## TreatmentType( ValueToWrite )

#define mDATWriteBuffer(DataName, Index, ValueToWrite, TreatmentType)	\
        mDATWriteBuffer2(DataName, Index, ValueToWrite, TreatmentType)

#define mDATWriteBuffer2(DataName, Index, ValueToWrite, TreatmentType)	\
	mDATWriteBuffer ## DataName ## TreatmentType( Index, ValueToWrite )

#define mDATWriteTable(DataType, ArrayName, Index, ValueToWrite, TreatmentType)	\
        mDATWriteTable2(DataType, ArrayName, Index, ValueToWrite, TreatmentType)

#define mDATWriteTable2(DataType, ArrayName, Index, ValueToWrite, TreatmentType)	\
	mDATWriteTable ## DataType ## ArrayName ## TreatmentType( Index, ValueToWrite )

#define mDATWriteStruct(DataType, DataName, pSource, TreatmentType)	\
        mDATWriteStruct2(DataType, DataName, pSource, TreatmentType)

#define mDATWriteStruct2(DataType, DataName, pSource, TreatmentType)	\
	mDATWriteStruct ## DataType ## DataName ## TreatmentType( pSource )

//////////////////////////    CONTROLE    /////////////////////////////////

#define mDATControl(Objet,Controle)\
    mDATControl##Objet(Controle)  

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
#endif   /* I_DAT_H */

