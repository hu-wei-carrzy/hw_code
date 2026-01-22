/*---------------------------------------------------------------------------

                This software is JCI property
                -----------------------------

    Duplication or disclosure is prohibited without JCI
    written permission.
    This file has been automatically generated with an excel file,
    by a visual basic macro.

 File                        : DAT_EEPx.h
 Project                     : STK
 Fonction                    : EEP
 Author                      : Author
 Automatically generated on  : 2025/9/1 a 16:05:43 
 Source file                 : DAT_EEP_CFG.XLS
 Macro version               : 01.43
 Configuration version       : 01.00

---------------------------------------------------------------------------*/

#ifndef I_DAT_EEPx_PARAM_H
#define I_DAT_EEPx_PARAM_H (1)


//--------------------------------------------------------------------------
//----  Declaration des constantes exportees par ce composant --------------
//--------------------------------------------------------------------------

// Definit le nombre de process
// Define number of process
#define cDATEepNumberOfProcess 23U

// Taille du buffer partage
// Size of shared buffer
#define cDATEepBufferSize  (U16)80

// Definit la structure de l'eeprom
// Define eeprom structure
//{Offset, Size, Call back number}
#define mDATEepDeclareBlocList()    \
  {    0,   12, cDATEepCallBackSbkNumber }, \
  {   12,   64, cDATEepCallBackSbkNumber }, \
  {   76,   24, cDATEepCallBackSbkNumber }, \
  {  100,    5, cDATEepCallBackSbkNumber }, \
  {  125,    5, cDATEepCallBackSbkNumber }, \
  {  920,    4, cDATEepCallBackSbkNumber }, \
  {  924,   41, cDATEepCallBackSbkNumber }, \
  {  965,    3, cDATEepCallBackSbkNumber }, \
  {  968,    2, cDATEepCallBackSbkNumber }, \
  {  970,    2, cDATEepCallBackSbkNumber }, \
  {  972,    2, cDATEepCallBackSbkNumber }, \
  {  974,    2, cDATEepCallBackSbkNumber }, \
  {  976,    5, cDATEepCallBackSbkNumber }, \
  {  105,   20, cDATEepCallBackObkNumber }, \
  {  130,   26, cDATEepCallBackDbkNumber }, \
  {  156,   82, cDATEepCallBackDbkNumber }, \
  {  238,  122, cDATEepCallBackDbkNumber }, \
  {  360,  122, cDATEepCallBackDbkNumber }, \
  {  482,   18, cDATEepCallBackDbkNumber }, \
  {  500,  138, cDATEepCallBackDbkNumber }, \
  {  638,  122, cDATEepCallBackDbkNumber }, \
  {  760,  160, cDATEepCallBackDbkNumber }, \
  {    0,    0, cDATEepCallBackDeaNumber }

// Numeros des callback
// Callback numbers
#define cDATEepCallBackSbkNumber 0
#define cDATEepCallBackObkNumber 1
#define cDATEepCallBackDbkNumber 2
#define cDATEepCallBackDeaNumber 3

// Nombre de callback
// Number of callback
#define cDATEepNumberOfCallBack   (U16)4

// Liste des callback
// Callback list
#define mDATEepDeclareCallBackList()\
    DATSbkCallBackEep,              \
    DATObkCallBackEep,              \
    DATDbkCallBackEep,              \
    DATDeaCallBackEep,              \

#endif
