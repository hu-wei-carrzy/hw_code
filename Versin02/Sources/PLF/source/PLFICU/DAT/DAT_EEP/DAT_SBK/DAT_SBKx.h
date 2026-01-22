/*---------------------------------------------------------------------------

                This software is JCI property
                -----------------------------

    Duplication or disclosure is prohibited without JCI
    written permission.
    This file has been automatically generated with an excel file,
    by a visual basic macro.

 File                        : DAT_SBKx.h
 Project                     : STK
 Fonction                    : EEP
 Author                      : Author
 Automatically generated on  : 2025/9/1 a 16:05:43 
 Source file                 : DAT_EEP_CFG.XLS
 Macro version               : 01.43
 Configuration version       : 01.00

---------------------------------------------------------------------------*/

#ifndef I_DAT_SBKx_PARAM_H
#define I_DAT_SBKx_PARAM_H (1)


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
#define cDATSbkNumberOfBankCopy    1

// Definit le numero de chaque banque utilisee
// Define the number of each bank
#define cDATSbkHandleErrorGroup    (tDATSbkSingleBankHandle)0UL
#define cDATSbkHandleGroupTraceability    (tDATSbkSingleBankHandle)1UL
#define cDATSbkHandleGroupPlantTraceability    (tDATSbkSingleBankHandle)2UL
#define cDATSbkHandleGroupDiagReserved    (tDATSbkSingleBankHandle)3UL
#define cDATSbkHandleGroupPlantCalibiration    (tDATSbkSingleBankHandle)4UL
#define cDATSbkHandleGroupReset    (tDATSbkSingleBankHandle)5UL
#define cDATSbkHandleGroupSbkReadOnly1    (tDATSbkSingleBankHandle)6UL
#define cDATSbkHandleGroupSbkReadOnly2    (tDATSbkSingleBankHandle)7UL
#define cDATSbkHandleGroupBCMCfg0    (tDATSbkSingleBankHandle)8UL
#define cDATSbkHandleGroupBCMCfg1    (tDATSbkSingleBankHandle)9UL
#define cDATSbkHandleGroupBCMCfg2    (tDATSbkSingleBankHandle)10UL
#define cDATSbkHandleGroupBCMCfg3    (tDATSbkSingleBankHandle)11UL
#define cDATSbkHandleGroupEEPInitCtrl    (tDATSbkSingleBankHandle)12UL

// Definit la taille de chaque banque
//  (taille en mot de 2 octets en RAM sans le checksum)
// Define size of each bank
//  (size in word of 2 byte in RAM without checksum)
#define cDATSbkSizeErrorGroup    11U
#define cDATSbkSizeGroupTraceability    63U
#define cDATSbkSizeGroupPlantTraceability    23U
#define cDATSbkSizeGroupDiagReserved    4U
#define cDATSbkSizeGroupPlantCalibiration    4U
#define cDATSbkSizeGroupReset    3U
#define cDATSbkSizeGroupSbkReadOnly1    40U
#define cDATSbkSizeGroupSbkReadOnly2    2U
#define cDATSbkSizeGroupBCMCfg0    1U
#define cDATSbkSizeGroupBCMCfg1    1U
#define cDATSbkSizeGroupBCMCfg2    1U
#define cDATSbkSizeGroupBCMCfg3    1U
#define cDATSbkSizeGroupEEPInitCtrl    4U

// Definit la taille de la RAM de travail
//  qui doit être la taille de la plus grande bank + 1 pour le checksum
//  cette déclaration doit être cohérente avec
//  cDATEepBufferSize dans DAT_EEPp.h
// Define max size of working RAM
//  which is size of the largest double bank (in RAM)
//  must be coherent with
//  cDATEepBufferSize dans DAT_EEPp.h
#define cDATSbkSizeMaxSbk  64

// Definit le nombre de groupes utilises
// Define number of group used
#define cNbSbk 13

// défini le handle de process de la premiere banque
// (+1 pour les banques suivantes)
#define cDATSbkFirstProcessHandle 0

// défini le nombre d'enregistrements pour chaque banque (toujours >= 1 !!!)
// define the number of records for each bank (always >= 1 !!!)

//--------------------------------------------------------------------------
//----  Declaration des macros exportees par ce composant ------------------
//--------------------------------------------------------------------------
// Macro de remplissage des banques ROM
// Macro wich fills ROM banks
#define mSERSbkInitTableBankROM() \
  {DATSbkMirrors.ErrorGroup, (tDATEepOffset)cDATSbkSizeErrorGroup }, \
  {DATSbkMirrors.GroupTraceability, (tDATEepOffset)cDATSbkSizeGroupTraceability }, \
  {DATSbkMirrors.GroupPlantTraceability, (tDATEepOffset)cDATSbkSizeGroupPlantTraceability }, \
  {DATSbkMirrors.GroupDiagReserved, (tDATEepOffset)cDATSbkSizeGroupDiagReserved }, \
  {DATSbkMirrors.GroupPlantCalibiration, (tDATEepOffset)cDATSbkSizeGroupPlantCalibiration }, \
  {DATSbkMirrors.GroupReset, (tDATEepOffset)cDATSbkSizeGroupReset }, \
  {DATSbkMirrors.GroupSbkReadOnly1, (tDATEepOffset)cDATSbkSizeGroupSbkReadOnly1 }, \
  {DATSbkMirrors.GroupSbkReadOnly2, (tDATEepOffset)cDATSbkSizeGroupSbkReadOnly2 }, \
  {DATSbkMirrors.GroupBCMCfg0, (tDATEepOffset)cDATSbkSizeGroupBCMCfg0 }, \
  {DATSbkMirrors.GroupBCMCfg1, (tDATEepOffset)cDATSbkSizeGroupBCMCfg1 }, \
  {DATSbkMirrors.GroupBCMCfg2, (tDATEepOffset)cDATSbkSizeGroupBCMCfg2 }, \
  {DATSbkMirrors.GroupBCMCfg3, (tDATEepOffset)cDATSbkSizeGroupBCMCfg3 }, \
  {DATSbkMirrors.GroupEEPInitCtrl, (tDATEepOffset)cDATSbkSizeGroupEEPInitCtrl }

//--------------------------------------------------------------------------
//----  Declaration des structures exportees par ce composant --------------
//--------------------------------------------------------------------------

// Structure qui definit les images en RAM
// Struct define RAM mirrors
typedef struct
{
  U16 ErrorGroup[cDATSbkSizeErrorGroup];
  U16 GroupTraceability[cDATSbkSizeGroupTraceability];
  U16 GroupPlantTraceability[cDATSbkSizeGroupPlantTraceability];
  U16 GroupDiagReserved[cDATSbkSizeGroupDiagReserved];
  U16 GroupPlantCalibiration[cDATSbkSizeGroupPlantCalibiration];
  U16 GroupReset[cDATSbkSizeGroupReset];
  U16 GroupSbkReadOnly1[cDATSbkSizeGroupSbkReadOnly1];
  U16 GroupSbkReadOnly2[cDATSbkSizeGroupSbkReadOnly2];
  U16 GroupBCMCfg0[cDATSbkSizeGroupBCMCfg0];
  U16 GroupBCMCfg1[cDATSbkSizeGroupBCMCfg1];
  U16 GroupBCMCfg2[cDATSbkSizeGroupBCMCfg2];
  U16 GroupBCMCfg3[cDATSbkSizeGroupBCMCfg3];
  U16 GroupEEPInitCtrl[cDATSbkSizeGroupEEPInitCtrl];
} tDATSbkMirrors;

#endif
