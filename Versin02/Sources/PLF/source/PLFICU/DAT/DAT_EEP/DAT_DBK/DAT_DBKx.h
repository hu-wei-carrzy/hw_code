/*---------------------------------------------------------------------------

                This software is JCI property
                -----------------------------

    Duplication or disclosure is prohibited without JCI
    written permission.
    This file has been automatically generated with an excel file,
    by a visual basic macro.

 File                        : DAT_DBKx.h
 Project                     : STK
 Fonction                    : EEP
 Author                      : Author
 Automatically generated on  : 2025/9/1 a 16:05:43 
 Source file                 : DAT_EEP_CFG.XLS
 Macro version               : 01.43
 Configuration version       : 01.00

---------------------------------------------------------------------------*/

#ifndef I_DAT_DBKx_PARAM_H
#define I_DAT_DBKx_PARAM_H (1)


#include   "ARCH_CFG.h"
#ifdef cHeadIncludeType_Directly
#include   "deftypes.h"
#else
#include   ".\..\..\..\LIB\LIB_API\deftypes.h"
#endif
//--------------------------------------------------------------------------
//----  Declaration des constantes exportees par ce composant --------------
//--------------------------------------------------------------------------

// Definit le nombre de copies de ce type de banque
// Define the number of bank copy for this bank type
#define cDATDbkNumberOfBankCopy    2

// Definit le numero de chaque banque utilisee
// Define the number of each bank
#define cDATDbkHandleGroupSTKDTC    (tDATDbkDoubleBankHandle)0UL
#define cDATDbkHandleGroupDTC    (tDATDbkDoubleBankHandle)1UL
#define cDATDbkHandleGroupDIUpperLimit    (tDATDbkDoubleBankHandle)2UL
#define cDATDbkHandleGroupDILowerLimit    (tDATDbkDoubleBankHandle)3UL
#define cDATDbkHandleGroupDIType    (tDATDbkDoubleBankHandle)4UL
#define cDATDbkHandleGroupSensorCal    (tDATDbkDoubleBankHandle)5UL
#define cDATDbkHandleGroupSensorCal1    (tDATDbkDoubleBankHandle)6UL
#define cDATDbkHandleGroupSensorCal2    (tDATDbkDoubleBankHandle)7UL

// Definit la taille de chaque banque
//  (taille en mot de 2 octets en RAM sans le checksum)
// Define size of each bank
//  (size in word of 2 byte in RAM without checksum)
#define cDATDbkSizeGroupSTKDTC    12U
#define cDATDbkSizeGroupDTC    40U
#define cDATDbkSizeGroupDIUpperLimit    60U
#define cDATDbkSizeGroupDILowerLimit    60U
#define cDATDbkSizeGroupDIType    8U
#define cDATDbkSizeGroupSensorCal    68U
#define cDATDbkSizeGroupSensorCal1    60U
#define cDATDbkSizeGroupSensorCal2    79U

// Definit la taille de la RAM de travail
//  qui doit être la taille de la plus grande bank + 1 pour le checksum
//  cette déclaration doit être cohérente avec
//  cDATEepBufferSize dans DAT_EEPp.h
// Define max size of working RAM
//  which is size of the largest double bank (in RAM)
//  must be coherent with
//  cDATEepBufferSize dans DAT_EEPp.h
#define cDATDbkSizeMaxDbk  80

// Definit le nombre de groupes utilises
// Define number of group used
#define cNbDbk 8

// défini le handle de process de la premiere banque
// (+1 pour les banques suivantes)
#define cDATDbkFirstProcessHandle 14

// défini le nombre d'enregistrements pour chaque banque (toujours >= 1 !!!)
// define the number of records for each bank (always >= 1 !!!)

//--------------------------------------------------------------------------
//----  Declaration des macros exportees par ce composant ------------------
//--------------------------------------------------------------------------
// Macro de remplissage des banques ROM
// Macro wich fills ROM banks
#define mSERDbkInitTableBankROM() \
  {DATDbkMirrors.GroupSTKDTC, (tDATEepOffset)cDATDbkSizeGroupSTKDTC }, \
  {DATDbkMirrors.GroupDTC, (tDATEepOffset)cDATDbkSizeGroupDTC }, \
  {DATDbkMirrors.GroupDIUpperLimit, (tDATEepOffset)cDATDbkSizeGroupDIUpperLimit }, \
  {DATDbkMirrors.GroupDILowerLimit, (tDATEepOffset)cDATDbkSizeGroupDILowerLimit }, \
  {DATDbkMirrors.GroupDIType, (tDATEepOffset)cDATDbkSizeGroupDIType }, \
  {DATDbkMirrors.GroupSensorCal, (tDATEepOffset)cDATDbkSizeGroupSensorCal }, \
  {DATDbkMirrors.GroupSensorCal1, (tDATEepOffset)cDATDbkSizeGroupSensorCal1 }, \
  {DATDbkMirrors.GroupSensorCal2, (tDATEepOffset)cDATDbkSizeGroupSensorCal2 }

//--------------------------------------------------------------------------
//----  Declaration des structures exportees par ce composant --------------
//--------------------------------------------------------------------------

// Structure qui definit les images en RAM
// Struct define RAM mirrors
typedef struct
{
  U16 GroupSTKDTC[cDATDbkSizeGroupSTKDTC];
  U16 GroupDTC[cDATDbkSizeGroupDTC];
  U16 GroupDIUpperLimit[cDATDbkSizeGroupDIUpperLimit];
  U16 GroupDILowerLimit[cDATDbkSizeGroupDILowerLimit];
  U16 GroupDIType[cDATDbkSizeGroupDIType];
  U16 GroupSensorCal[cDATDbkSizeGroupSensorCal];
  U16 GroupSensorCal1[cDATDbkSizeGroupSensorCal1];
  U16 GroupSensorCal2[cDATDbkSizeGroupSensorCal2];
} tDATDbkMirrors;

#endif
