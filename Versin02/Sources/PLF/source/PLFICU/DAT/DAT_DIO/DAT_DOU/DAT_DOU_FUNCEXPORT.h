#ifndef I_DAT_DOU_FUNCEXPORT_H
#define I_DAT_DOU_FUNCEXPORT_H

extern void DATDouCtrl(tCtrl Ctrl);
extern void DATDouOutPut(tAddress tLDBDouAdr,U8 u8Par);

#define	mSERControlTT(Ctrl)							mSERControlTT##Ctrl()
#define mSERControlTTStart()                        DATDouCtrl(cLDBDouEnableTTSymbol)//LDBControl(cLDBChannelLDB_DOU,cLDBDouEnableTTSymbol)
#define mSERControlTTStop()                         DATDouCtrl(cLDBDouDisableTTSymbol)//LDBControl(cLDBChannelLDB_DOU,cLDBDouDisableTTSymbol)

#define mSERControlPower(Ctrl)                      mSERControlPower##Ctrl()
#define mSERControlPowerLock()                      DATDouCtrl(cLDBDouPowerLock)
#define mSERControlPowerRelease()                   DATDouCtrl(cLDBDouPowerRelease)


#define mSERControl12V(Ctrl)                           mSERControl12V##Ctrl()
#define mSERControl12VEnable()                     DATDouCtrl(cLDBDou12VEnable)
#define mSERControl12VDisable()                    DATDouCtrl(cLDBDou12VDisable)

#define mSERControlMX6Switch(Ctrl)                        mSERControlMX6Switch##Ctrl()
#define mSERControlMX6SwitchEnable()                      DATDouCtrl(cLDBDouMX6SwitchEnable)
#define mSERControlMX6SwitchDisable()                      DATDouCtrl(cLDBDouMX6SwitchDisable)


#define mSERControlCVBS(Ctrl)                           mSERControlCVBS##Ctrl()
#define mSERControlCVBSEnable()                     DATDouCtrl(cLDBDouCVBSEnable)
#define mSERControlCVBSDisable()                    DATDouCtrl(cLDBDouCVBSDisable)


#define mSERControlTXB(Ctrl)                           mSERControlTXB##Ctrl()
#define mSERControlTXBEnable()                     DATDouCtrl(cLDBDouTXBEnable)
#define mSERControlTXBDisable()                    DATDouCtrl(cLDBDouTXBDisable)

#define mSERControlFrStby(Lvl)                              DATDouOutPut(cLDBDouAdrFrStby,(Lvl))
#define mSERControl5T050Close(Ch)                     DATDouOutPut(cLDBDouAdr5T050Close,(Ch))
#define mSERControl5T050Open(Ch)                     DATDouOutPut(cLDBDouAdr5T050Open,(Ch))
#define mSERControl6200Close(Ch)                       // DATDouOutPut(cLDBDouAdr6200Close,(Ch))
#define mSERControl6200Open(Ch)                        //  DATDouOutPut(cLDBDouAdr6200Open,(Ch))

#define mSERControlLCDBoardHWRst(Ctrl)             mSERControlLCDBoardHWRst##Ctrl()
#define mSERControlLCDBoardHWRstEnable()        DATDouCtrl(cLDBDouLCDBoardHWRstEnable)
#define mSERControlLCDBoardHWRstDisable()        DATDouCtrl(cLDBDouLCDBoardHWRstDisable)


#define mSERControlLCDBoardSWRst(Ctrl)             mSERControlLCDBoardSWRst##Ctrl()
#define mSERControlLCDBoardSWRstEnable()        DATDouCtrl(cLDBDouLCDBoardSWRstEnable)
#define mSERControlLCDBoardSWRstDisable()        DATDouCtrl(cLDBDouLCDBoardSWRstDisable)

#define mSERControlMCUWakeUp(Ctrl)                 mSERControlMCUWakeUp##Ctrl()
#define mSERControlMCUWakeUpEnable()            DATDouCtrl(cLDBDouMCUWakeUpEnable)
#define mSERControlMCUWakeUpDisable()           DATDouCtrl(cLDBDouMCUWakeUpDisable)


#define mSERControlSndIC(Ctrl)                mSERControlSndIC##Ctrl()
#define mSERControlSndICEnable()              DATDouCtrl(cLDBDouSndICEnable)
#define mSERControlSndICDisable()              DATDouCtrl(cLDBDouSndICDisable)

#define mSERControlKeyLED(Ctrl)                mSERControlKeyLED##Ctrl()
#define mSERControlKeyLEDEnable()              DATDouCtrl(cLDBDouKeyLEDEnable)
#define mSERControlKeyLEDDisable()              DATDouCtrl(cLDBDouKeyLEDDisable)

#define mSERControl6200Dsel(Ch)                        DATDouOutPut(cLDBDouAdr6200Dsel,(Ch))

#endif
