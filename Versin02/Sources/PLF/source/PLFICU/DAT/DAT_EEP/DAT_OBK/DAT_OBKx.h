/*---------------------------------------------------------------------------

                This software is JCI property
                -----------------------------

    Duplication or disclosure is prohibited without JCI
    written permission.
    This file has been automatically generated with an excel file,
    by a visual basic macro.

 File                        : DAT_OBKx.h
 Project                     : STK
 Fonction                    : EEP
 Author                      : Author
 Automatically generated on  : 2025/9/1 a 16:05:43 
 Source file                 : DAT_EEP_CFG.XLS
 Macro version               : 01.43
 Configuration version       : 01.00

---------------------------------------------------------------------------*/

#ifndef I_DAT_OBKx_PARAM_H
#define I_DAT_OBKx_PARAM_H (1)


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
#define cDATObkNumberOfBankCopy    4

// Definit le numero de chaque banque utilisee
// Define the number of each bank
#define cDATObkHandleGroupOdo    (tDATObkOdometerBankHandle)0UL

// Definit la taille de chaque banque
//  (taille en mot de 2 octets en RAM sans le checksum)
// Define size of each bank
//  (size in word of 2 byte in RAM without checksum)
#define cDATObkSizeGroupOdo    4U

// Definit la taille de la RAM de travail
//  qui doit être la taille de la plus grande bank + 1 pour le checksum
//  cette déclaration doit être cohérente avec
//  cDATEepBufferSize dans DAT_EEPp.h
// Define max size of working RAM
//  which is size of the largest double bank (in RAM)
//  must be coherent with
//  cDATEepBufferSize dans DAT_EEPp.h
#define cDATObkSizeMaxObk  5

// Definit le nombre de groupes utilises
// Define number of group used
#define cNbObk 1

// défini le handle de process de la premiere banque
// (+1 pour les banques suivantes)
#define cDATObkFirstProcessHandle 13

// défini le nombre d'enregistrements pour chaque banque (toujours >= 1 !!!)
// define the number of records for each bank (always >= 1 !!!)

//--------------------------------------------------------------------------
//----  Declaration des macros exportees par ce composant ------------------
//--------------------------------------------------------------------------
// Macro de remplissage des banques ROM
// Macro wich fills ROM banks
#define mSERObkInitTableBankROM() \
  {DATObkMirrors.GroupOdo, (tDATEepOffset)cDATObkSizeGroupOdo }

//--------------------------------------------------------------------------
//----  Declaration des structures exportees par ce composant --------------
//--------------------------------------------------------------------------

// Structure qui definit les images en RAM
// Struct define RAM mirrors
typedef struct
{
  U16 GroupOdo[cDATObkSizeGroupOdo];
} tDATObkMirrors;

#endif
