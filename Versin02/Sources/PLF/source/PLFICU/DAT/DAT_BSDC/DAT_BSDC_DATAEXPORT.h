#ifndef I_DAT_BSDC_DATAEXPORT_H
#define I_DAT_BSDC_DATAEXPORT_H


#define mSERReadU16BitBSDCAMaxCurDefault()                 DATBSDC_GetMaxCur_A()
#define mSERWriteU8BitBSDCASetDutyDefault(value)           DATBSDC_A_SetDuty(value)
#define mSERWriteU8BitBSDCASetDirectionDefault(value)      DATBSDC_A_SetDirection(value)
#define mSERWriteU8BitBSDCBrakeDefault(value)              Motor_Brake(value)
#define mSERWriteU8BitBSDCHIZDefault(value)                Motor_HIZ(value)
#define mSERReadU16BitBSDCAGetHall1Default()               DATBSDC_GetHall1_A()
#define mSERReadU16BitBSDCAGetHall2Default()               DATBSDC_GetHall2_A()
 #define mSERReadU8BitBSDCAHallDirectionDefault()          DATBSDC_A_DualHall_Direction()  

#define mSERReadU16BitBSDCBMaxCurDefault()                 DATBSDC_GetMaxCur_B()
#define mSERWriteU8BitBSDCBSetDutyDefault(value)           DATBSDC_B_SetDuty(value)
#define mSERWriteU8BitBSDCBSetDirectionDefault(value)      DATBSDC_B_SetDirection(value)

#define mSERReadU16BitBSDCCMaxCurDefault()                 DATBSDC_GetMaxCur_C()
#define mSERWriteU8BitBSDCCSetDutyDefault(value)           DATBSDC_C_SetDuty(value)
#define mSERWriteU8BitBSDCCSetDirectionDefault(value)      DATBSDC_C_SetDirection(value)

#define mSERReadU16BitBSDCDMaxCurDefault()                 DATBSDC_GetMaxCur_D()
#define mSERWriteU8BitBSDCDSetDutyDefault(value)           DATBSDC_D_SetDuty(value)
#define mSERWriteU8BitBSDCDSetDirectionDefault(value)      DATBSDC_D_SetDirection(value)
#define mSERReadU16BitBSDCDGetHall1Default()               DATBSDC_GetHall1_D()
#define mSERReadU16BitBSDCDGetHall2Default()               DATBSDC_GetHall2_D()


#define mSERReadU8BitBSDCADutyFdDefault()                  DATBSDC_A_DutyFd()
#define mSERReadU8BitBSDCBDutyFdDefault()                  DATBSDC_B_DutyFd()
#define mSERReadU8BitBSDCCDutyFdDefault()                  DATBSDC_C_DutyFd()
#define mSERReadU8BitBSDCDDutyFdDefault()                  DATBSDC_D_DutyFd()

#define mSERReadU16BitOutButtonDefault()  				   DATBSDC_GET_SpeedD()

#define mSERReadU1BitMotorStateDefault()  				   DATBSDC_DRV_StateFd()



#endif

