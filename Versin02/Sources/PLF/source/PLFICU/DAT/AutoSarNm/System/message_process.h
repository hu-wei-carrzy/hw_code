
#ifndef __MESSAGE_PROCESS_H
#define __MESSAGE_PROCESS_H
/*********************************************************************************************
** Global Structures' Definition
*********************************************************************************************/
//#define _CONFIG_LIN_Slave
//#define _CONFIG_LIN_Master
#define _CONFIG_CAN_Bus

//#define _SGMW_COM
//#define _SGM_COM
//#define _CTCS_COM
//#define _DEARCC_COM
//#define _MAXUS_COM
      //#define _MAXUS_COM_PLG
      //#define _MAXUS_COM_PSD
            //#define _MAXUS_COM_PSD_R
	    //#define _MAXUS_COM_PSD_L
//#define _DFMC_COM
//#define _DFLZM_COM
//#define _BAIC_COM
        //#define _BAIC_COM_C52X
        //#define _BAIC_COM_C62X
	//#define _BAIC_COM_C46DB
	//#define _BAIC_COM_B30X
	//#define _BAIC_COM_N51AB
	      //#define _BAIC_COM_N51AB_AUTOSAR
	      //#define _BAIC_COM_N51AB_OSEK
//#define _FAW_COM
//#define _CHANGAN_COM
//#define _NIU_COM
//#define _XIAOPENG_COM
     //#define _XIAOPENG_SDCL
     //#define _XIAOPENG_SDCR
     
#define _CHERY_COM
     //#define _CHERY_COM_PLG
     #define _CHERY_COM_PD
           //#define _CHERY_COM_PD_FL
	   //#define _CHERY_COM_PD_FR    
	   //#define _CHERY_COM_PD_RL
	   #define _CHERY_COM_PD_RR
	   
//#define _VOYAH_COM
     //#define _VOYAH_COM_PLG
     //#define _VOYAH_COM_PD
           //#define _VOYAH_COM_PD_FL
	   //#define _VOYAH_COM_PD_FR    
	   //#define _VOYAH_COM_PD_RL
	   //#define _VOYAH_COM_PD_RR	
//#define _AUDI_COM
     //#define _AUDI_COM_PLG
     //#define _AUDI_COM_PD
           //#define _AUDI_COM_PD_FL
	   //#define _AUDI_COM_PD_FR    
	   //#define _AUDI_COM_PD_RL
	   //#define _AUDI_COM_PD_RR
     

#ifdef _CHERY_COM 
    #ifdef _CHERY_COM_PD
      //#define _CONFIG_AppAuthorize 
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
      //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
	    //#define _CONFIG_VehicleSpeed_E2E
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
	    //#define _CONFIG_VehicleGearLever_E2E
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      #define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleRemoteMode  /*Reserved for RVSMode*/
      
      //#define _CONFIG_VehicleDriveMode
           //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      
      #define _CONFIG_VehicleMode
            //#define _CONFIG_VehicleMode_Real
            //#define _CONFIG_VehicleMode_DisableMode
	    //#define _CONFIG_VehicleMode_SmallOpenMode
	    #define _CONFIG_VehicleMode_MechanicalMode	
	        #ifdef _CHERYE0X_PD_VehicleMode_Factory_Learn
	    #define _CONFIG_VehicleMode_MechanicalMode_Disable
	          #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByCPIDLearn
		  #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByDriverButton
		#endif  
      #define _CONFIG_VehicleBrake
            #define _CONFIG_VehicleBrake_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleBrake_ShortPress
            #define _CONFIG_VehicleBrake_LongPress
                   #define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    	
      #define _CONFIG_VehicleCrash            
            #define _CONFIG_VehicleCrash_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleCrash_DisableMode 
	        #ifndef _CHERYE0X_PD_InginDurability 
	    #define _CONFIG_VehicleCrash_SmallOpenMode
	        #endif
	    //#define _CONFIG_VehicleCrash_MechanicalMode
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      #define _CONFIG_VehicleClean            
            //#define _CONFIG_VehicleClean_Real
	    //#define _CONFIG_VehicleClean_E2E
            //#define _CONFIG_VehicleClean_DisableMode 
	    //#define _CONFIG_VehicleClean_SmallOpenMode
	    #define _CONFIG_VehicleClean_MechanicalMode	    
      
      #define _CONFIG_TouchPad               
            #define _CONFIG_TouchPad_FallEdge
	       #ifndef _CHERYE0X_PD_ShowFixture_LiXiangL7Vehicle
	    #define _CONFIG_TouchPad_Disable
	          #define _CONFIG_TouchPad_Disable_ByTouchPad
	       #endif
	       #ifdef _CHERYE0X_PD_ShowFixture_LiXiangL7Vehicle
	    #define _CONFIG_TouchPad_ReleaseOnly
	       #endif
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
	    //#define _CONFIG_TouchPad_Opening_Reverse_StopSoft
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Closing_Reverse_StopSoft
	    #define _CONFIG_TouchPad_Open_Default 
	  #ifndef _CHERYE0X_PD_OutsideHandleInsideCapacity_Disable  
      #define _CONFIG_TouchPad_2nd
            #define _CONFIG_TouchPad_2nd_FallEdge
	         //#define _CONFIG_TouchPad_2nd_FallEdge_ReleaseOnly_ShortPress_PowerOpen
	    //#define _CONFIG_TouchPad_2nd_ShortPress	   	         
            //#define _CONFIG_TouchPad_2nd_LongPress
            //#define _CONFIG_TouchPad_2nd_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_2nd_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_2nd_Authorize_PKE
	    //#define _CONFIG_TouchPad_2nd_Authorize_Combine
            //#define _CONFIG_TouchPad_2nd_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_2nd_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_2nd_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_2nd_Opening_Reverse
	    //#define _CONFIG_TouchPad_2nd_Opening_Reverse_StopSoft
            //#define _CONFIG_TouchPad_2nd_Closing_Reverse
	    //#define _CONFIG_TouchPad_2nd_Closing_Reverse_StopSoft
	    //#define _CONFIG_TouchPad_2nd_Open_Default 	    
	         #ifdef _CHERYE0X_PD_OutsideHandleInsideSwitch_Enable
	    #define _CONFIG_TouchPad_2nd_Close_Default	 
	    #define _CONFIG_TouchPad_2nd_OnlyInOpen
            #define _CONFIG_TouchPad_2nd_Disable
	          #define _CONFIG_TouchPad_2nd_Disable_ByTouchPad
		  #define _CONFIG_TouchPad_2nd_Disable_ByPKETrunkButton
	         #endif
	  #endif
      //#define _CONFIG_RemoteKey
           //#define _CONFIG_RemoteKey_Opening_Reverse
	   //#define _CONFIG_RemoteKey_Opening_Reverse_StopSoft
           //#define _CONFIG_RemoteKey_Closing_Reverse
	   //#define _CONFIG_RemoteKey_Closing_Reverse_StopSoft
      //#define _CONFIG_FobLongPress
           //#define _CONFIG_FobLongPress_Opening_Reverse
	   //#define _CONFIG_FobLongPress_Opening_Reverse_StopSoft
           //#define _CONFIG_FobLongPress_Closing_Reverse
	   //#define _CONFIG_FobLongPress_Closing_Reverse_StopSoft
           //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
           //#define _CONFIG_FobShortPress_Opening_Reverse
	   //#define _CONFIG_FobShortPress_Opening_Reverse_StopSoft
           //#define _CONFIG_FobShortPress_Closing_Reverse
	   //#define _CONFIG_FobShortPress_Closing_Reverse_StopSoft
           //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch 
	   #if defined _CHERYE0X_PD_ShowFixture || defined _CHERYE0X_PD_KnockButton_Enable
      #define _CONFIG_KnockButton
           //#define _CONFIG_KnockButton_Opening_Reverse
	   //#define _CONFIG_KnockButton_Opening_Reverse_StopSoft
           //#define _CONFIG_KnockButton_Closing_Reverse
	   //#define _CONFIG_KnockButton_Closing_Reverse_StopSoft
	   #endif	   
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_KickSensor_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
	    //#define _CONFIG_KickSensor_Opening_Reverse_StopSoft
            //#define _CONFIG_KickSensor_Closing_Reverse
	    //#define _CONFIG_KickSensor_Closing_Reverse_StopSoft
      #define _CONFIG_PKETrunkButton
                 #ifdef _CHERYE0X_PD_OutsideHandleInsideSwitch_Enable
            #define _CONFIG_PKETrunkButton_Disable
	          #define _CONFIG_PKETrunkButton_Disable_ByTouchPad
		  #define _CONFIG_PKETrunkButton_Disable_ByTouchPad_2nd
	         #endif
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
	    //#define _CONFIG_PKETrunkButton_Opening_Reverse_StopSoft
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Closing_Reverse_StopSoft
	    //#define _CONFIG_PKETrunkButton_Open_Default
	    #define _CONFIG_PKETrunkButton_Open_Disable
	    #define _CONFIG_PKETrunkButton_Close_Default
      #define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_ShortPress
            //#define _CONFIG_VirtualButton_LongPress
            //#define _CONFIG_VirtualButton_Opening_Reverse
	    //#define _CONFIG_VirtualButton_Opening_Reverse_StopSoft
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_Closing_Reverse_StopSoft
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      #define _CONFIG_InsideButton
                 #ifdef _CHERYE0X_PD_InsideHandleLongPress
            #define _CONFIG_InsideButton_ShortPress
            #define _CONFIG_InsideButton_LongPress
	    #define _CONFIG_InsideButton_LongPress_Open_Default
	         #endif
            //#define _CONFIG_InsideButton_Opening_Reverse
	    //#define _CONFIG_InsideButton_Opening_Reverse_StopSoft
            //#define _CONFIG_InsideButton_Closing_Reverse
	    //#define _CONFIG_InsideButton_Closing_Reverse_StopSoft
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased	    
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress	          
            //#define _CONFIG_DriverButton_Opening_Reverse
	    //#define _CONFIG_DriverButton_Opening_Reverse_StopSoft
            //#define _CONFIG_DriverButton_Closing_Reverse
	    //#define _CONFIG_DriverButton_Closing_Reverse_StopSoft
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
	    //#define _CONFIG_DriverButton_LongPress_Open_Default
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
	    //#define _CONFIG_DriverButtonStop_Opening_Reverse_StopSoft
            //#define _CONFIG_DriverButtonStop_Closing_Reverse 
	    //#define _CONFIG_DriverButtonStop_Closing_Reverse_StopSoft
      
      #define _CONFIG_LatchReleaseState	  
         #if defined _CONFIG_LatchControl_NoPowerRelease || defined _CONFIG_LatchControl_NoPowerCinch 
      #define _CONFIG_PawlSignal	 
      #define _CONFIG_SecondarySignal	
         #endif
	 #ifdef _CONFIG_LatchControl_NoPowerCinch
      #define _CONFIG_PositionSignal
         #endif
      
      #define _CONFIG_CentralLockSignal
      #define _CONFIG_ChildLockSignal
      #define _CONFIG_LatchSignal
           //#define _CONFIG_LatchSignal_LatchSwitch
           //#define _CONFIG_LatchSignal_Transmit
           #ifdef _CHERYE0X_PD_SeatBelt_Enable
       #define _CONFIG_SeatBelt
             #define _CONFIG_SeatBelt_Opening_Reverse
       #define _CONFIG_SeatOccupied
           #endif
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
	   #ifdef _CHERYE0X_PD_PadControl_DualModeAutoShowCar
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             #define _CONFIG_AppOpen_KeepOpening
	     #define _CONFIG_AppOpen_Closing_Reverse
	     #define _CONFIG_AppOpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             #define _CONFIG_AppClose_KeepClosing
	     #define _CONFIG_AppClose_Opening_Reverse
	     #define _CONFIG_AppClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine    
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
	     #define _CONFIG_AppStop_MechanicalMode
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      #define _CONFIG_AppButton
             //#define _CONFIG_AppButton_Opening_Reverse
             //#define _CONFIG_AppButton_Closing_Reverse
	     //#define _CONFIG_AppButton_ReleaseOnlyInReleased
      #define _CONFIG_AppEnable	
      #define _CONFIG_AppReset	
      #define _CONFIG_AppDemoMode
           #endif
      
      //#define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     #define _CONFIG_VRClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch  
      //#define _CONFIG_VRStopDirectly	     
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_RKEOpen
              #define _CONFIG_RKEOpen_KeepOpening
	      #define _CONFIG_RKEOpen_Closing_Reverse
	      #define _CONFIG_RKEOpen_Closing_Reverse_StopSoft
	      //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_RKEClose 
              #define _CONFIG_RKEClose_KeepClosing
	      #define _CONFIG_RKEClose_Opening_Reverse
	      #define _CONFIG_RKEClose_Opening_Reverse_StopSoft
      #define _CONFIG_RKEStopOpen
              #define _CONFIG_RKEStopOpen_PowerOpenWhileLatchCinch
      #define _CONFIG_RKEStopClose 
              #define _CONFIG_RKEStopClose_PowerOpenWhileLatchCinch
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      
      #define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      #define _CONFIG_VoiceOpen
             #define _CONFIG_VoiceOpen_KeepOpening
	     #define _CONFIG_VoiceOpen_Closing_Reverse
	     #define _CONFIG_VoiceOpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      #define _CONFIG_VoiceClose
             #define _CONFIG_VoiceClose_KeepClosing
	     #define _CONFIG_VoiceClose_Opening_Reverse
	     #define _CONFIG_VoiceClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      #define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             #define _CONFIG_BLEClose_KeepClosing
	     #define _CONFIG_BLEClose_Opening_Reverse
	     #define _CONFIG_BLEClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      #define _CONFIG_BLEButton
           //#define _CONFIG_BLEButton_Opening_Reverse
	   //#define _CONFIG_BLEButton_Opening_Reverse_StopSoft
           //#define _CONFIG_BLEButton_Closing_Reverse
	   //#define _CONFIG_BLEButton_Closing_Reverse_StopSoft
	   //#define _CONFIG_BLEButton_ReleaseOnlyInReleased
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    #define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      #define _CONFIG_VehicleSpeedHigh_IgnoreCommand_InClosing
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      #define _CONFIG_AdasRadar
            ////#define _CONFIG_AdasRadar_Real
	    ////#define _CONFIG_AdasRadar_PreferSafe
	    #define _CONFIG_AdasRadar_PreferFunction
            #define _CONFIG_AdasRadar_Detect_Cyclic
            //#define _CONFIG_AdasRadar_Detect_Event
	          //#define _CONFIG_AdasRadar_CommandDelay
		           //#define _CONFIG_AdasRadar_CommandDelay_FromClose
			   //#define _CONFIG_AdasRadar_CommandDelay_FromOpen
			   //#define _CONFIG_AdasRadar_CommandDelay_PullHandle
	          //#define _CONFIG_AdasRadar_DelayCheck
		           //#define _CONFIG_AdasRadar_DelayCheck_FromClose
			   //#define _CONFIG_AdasRadar_DelayCheck_FromOpen    
	    #define _CONFIG_AdasRadar_ReleaseToPowerOpen
	    #define _CONFIG_AdasRadar_StopDirectly	    	  
	    #define _CONFIG_AdasRadar_MiniStop
	    //#define _CONFIG_AdasRadar_MechanicalMode

	    //#define _CONFIG_AdasRadar_SmallOpenMode
	    #define _CONFIG_AdasRadar_Lost_Disable
	    #define _CONFIG_AdasRadar_Disable
	          #define _CONFIG_AdasRadar_RearCorner_Enable
		  //#define _CONFIG_MmwRadar_Disable_Manual
	    
	    #define _CONFIG_AdasRadar_RearCorner_Error
	    #define _CONFIG_AdasRadar_RearCorner_Obstacle
	    //#define _CONFIG_AdasRadar_RearCorner_Angle
	          //#define _CONFIG_AdasRadar_RearCorner_Angle_Actual
		  //#define _CONFIG_AdasRadar_RearCorner_Angle_Delta	    
	    
	    #define _CONFIG_AdasRadar_RearCorner_Distance
            #define _CONFIG_AdasRadar_RearCornerX_Distance
            #define _CONFIG_AdasRadar_RearCornerY_Distance
	    #define _CONFIG_AdasRadar_RearCornerZ_Distance
	    #define _CONFIG_AdasRadar_RearCorner_RadarSelf
	    //#define _CONFIG_AdasRadar_FrontCorner_Error
	    //#define _CONFIG_AdasRadar_FrontCorner_Obstacle
	    //#define _CONFIG_AdasRadar_FrontCorner_Angle
	            //#define _CONFIG_AdasRadar_FrontCorner_Angle_Actual
		    //#define _CONFIG_AdasRadar_FrontCorner_Angle_Delta
	    //#define _CONFIG_AdasRadar_FrontCorner_Distance
            //#define _CONFIG_AdasRadar_FrontCornerX_Distance
            //#define _CONFIG_AdasRadar_FrontCornerY_Distance
	    //#define _CONFIG_AdasRadar_FrontCornerZ_Distance
	    //#define _CONFIG_AdasRadar_FrontCorner_RadarSelf	
      #define _CONFIG_MmwRadar	
	        #ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe
	        #else
		    #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe	   
		   #else
	    #define _CONFIG_MmwRadar_PreferFunction 
	           #endif	    
	        #endif
	    //#define _CONFIG_MmwRadar_Detect_Cyclic
            #define _CONFIG_MmwRadar_Detect_Event
	          #define _CONFIG_MmwRadar_CommandDelay
		           //#define _CONFIG_MmwRadar_CommandDelay_FromClose
			   #define _CONFIG_MmwRadar_CommandDelay_FromOpen
			   #define _CONFIG_MmwRadar_CommandDelay_PullHandle
	          #define _CONFIG_MmwRadar_DelayCheck
		           #define _CONFIG_MmwRadar_DelayCheck_FromClose
			   //#define _CONFIG_MmwRadar_DelayCheck_FromOpen	    
	    #define _CONFIG_MmwRadar_ReleaseToPowerOpen
	    //#define _CONFIG_MmwRadar_StopDirectly
	    #define _CONFIG_MmwRadar_MiniStop
	    //#define _CONFIG_MmwRadar_MechanicalMode    
	    #define _CONFIG_MmwRadar_Error
	         //#define _CONFIG_MmwRadar_Error_DoorStop
	    #define _CONFIG_MmwRadar_Obstacle
	    #define _CONFIG_MmwRadar_Angle
	          #define _CONFIG_MmwRadar_Angle_NonSafeDistance
	          //#define _CONFIG_MmwRadar_Angle_SafeDistance
	          #define _CONFIG_MmwRadar_Angle_Actual
		  //#define _CONFIG_MmwRadar_Angle_Delta		  		  
	    #define _CONFIG_MmwRadar_Distance
                  #define _CONFIG_MmwRadarX_Distance
                  #define _CONFIG_MmwRadarY_Distance
	          #define _CONFIG_MmwRadarZ_Distance
	          //#define _CONFIG_MmwRadarD_Distance
	    #define _CONFIG_MmwRadar_DeadZone
	    #define _CONFIG_MmwRadar_PauseOpen
	          #define _CONFIG_MmwRadar_PauseOpen_ContinueTimes
	    #define _CONFIG_MmwRadar_RadarSelf	  
	    //#define _CONFIG_MmwRadar_PowerOpen_Disable
	    #define _CONFIG_MmwRadar_Lost_Disable
	    #define _CONFIG_MmwRadar_Disable
	          #define _CONFIG_MmwRadar_Disable_Unlearn
	          //#define _CONFIG_MmwRadar_Disable_OpenCloseSwitch_LongPress
		      #ifdef _CHERYE0X_PD_116_MmwRadar_Disable_Manual
		  #define _CONFIG_MmwRadar_Disable_Manual   
		      #endif
	    
	    
      #define _CONFIG_SonicRadar 
		#ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe  
	        #else  
		   #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe 	   
		   #else
	    #define _CONFIG_SonicRadar_PreferFunction  
	           #endif
	        #endif
            //#define _CONFIG_SonicRadar_Detect_Cyclic
            #define _CONFIG_SonicRadar_Detect_Event
	          #define _CONFIG_SonicRadar_CommandDelay
		           //#define _CONFIG_SonicRadar_CommandDelay_FromClose
			   #define _CONFIG_SonicRadar_CommandDelay_FromOpen
			   #define _CONFIG_SonicRadar_CommandDelay_PullHandle
	          #define _CONFIG_SonicRadar_DelayCheck
		           #define _CONFIG_SonicRadar_DelayCheck_FromClose
			   //#define _CONFIG_SonicRadar_DelayCheck_FromOpen
	    #define _CONFIG_SonicRadar_ReleaseToPowerOpen
	    //#define _CONFIG_SonicRadar_StopDirectly
	    #define _CONFIG_SonicRadar_MiniStop
	    //#define _CONFIG_SonicRadar_MechanicalMode
	    
	    #define _CONFIG_SonicRadar_Error
	          //#define _CONFIG_SonicRadar_Error_DoorStop
	          //#define _CONFIG_SonicRadar_Error_AllRadarFault /*for OTS1 Vehicle Build*/
		  //#define _CONFIG_SonicRadar_Error_DisableRadarVoltage
            #define _CONFIG_SonicRadar_Obstacle
	    #define _CONFIG_SonicRadar_Angle	
	          #define _CONFIG_SonicRadar_Angle_NonSafeDistance
	          //#define _CONFIG_SonicRadar_Angle_SafeDistance		  
	          #define _CONFIG_SonicRadar_Angle_Actual
		  //#define _CONFIG_SonicRadar_Angle_Delta
            #define _CONFIG_SonicRadar1_Distance
            #define _CONFIG_SonicRadar2_Distance
	    #define _CONFIG_SonicRadar3_Distance	    
	    #define _CONFIG_SonicRadar_DeadZone
	    #define _CONFIG_SonicRadar_PauseOpen
	          #define _CONFIG_SonicRadar_PauseOpen_ContinueTimes	    
            #define _CONFIG_SonicRadar_RadarSelf
	    ////#define _CONFIG_SonicRadar_PowerOpen_Disable
	    #define _CONFIG_SonicRadar_Lost_Disable
	    #define _CONFIG_SonicRadar_Disable
	              #define _CONFIG_SonicRadar_Disable_Unlearn
	              #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	          #define _CONFIG_SonicRadar_Disable_OpenCloseSwitch_LongPress
	              #endif
		      #ifdef _CHERYE0X_PD_631_SonicRadar_Disable_Manual
		  #define _CONFIG_SonicRadar_Disable_Manual   
		      #endif
	    	    
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_TargetPositionOpen
            //#define _CONFIG_TargetPositionOpen_KeepOpening
            //#define _CONFIG_TargetPositionOpen_Closing_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
      //#define _CONFIG_TargetPositionClose
            //#define _CONFIG_TargetPositionClose_KeepClosing
	    //#define _CONFIG_TargetPositionClose_Opening_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
	  
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer
      #define _CONFIG_TimeInformation

      #define _CONFIG_DoorStatus
            #define _CONFIG_DoorStatus_SideDoor
	        #ifdef _CHERY_COM_PD_FL
	          #define _CONFIG_DoorStatus_DriverDoor
		#endif  
		#ifdef _CHERY_COM_PD_FR
	          #define _CONFIG_DoorStatus_PassengerDoor
		#endif  
		#ifdef _CHERY_COM_PD_RL  
	          #define _CONFIG_DoorStatus_RearLeftDoor
		#endif  
		#ifdef _CHERY_COM_PD_RR  
	          #define _CONFIG_DoorStatus_RearRightDoor
		#endif  
	    //#define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
	    #define _CONFIG_DoorStatus_TrunkDoor
      #define _CONFIG_WindowsPosition
            #define _CONFIG_WindowsPosition_SideDoor
	    //#define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
            #define _CONFIG_BusTemperature
	    #define _CONFIG_BusTemperature_PowerModeOFF_Invalid
	    //#define _CONFIG_Bus_Board_Temperature_Delta
	    
      #define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   #define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_E2E
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	
	   //#define _CONFIG_BusIncline_NoReal_BoardInclineOnly
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink 
           //#define _CONFIG_BusIncline_Compensation
		 
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode  	    
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      #define _CONFIG_AutoOpenEnable
      //#define _CONFIG_ObstcalAlarmEnable
      //#define _CONFIG_BLEEnable
      #define _CONFIG_VoiceEnable
      #define _CONFIG_BrakeEnable
      #define _CONFIG_RKEEnable 
         #ifdef _CHERYE0X_PD_PadControl_DualModeAutoShowCar
      #define _CONFIG_DoorPadMode
      #define _CONFIG_DoorDemoMode
	 #endif
      
      //#define _CONFIG_ManualOperateEnable
      //#define _CONFIG_MotorHoldEnable
      #define _CONFIG_DoorPowerMode
      
      #define _CONFIG_ConfigurationTrigger
      #define _CONFIG_SideDoorOpeningMode
      #define _CONFIG_LeftAndRightRudder
      #define _CONFIG_BNCM
                
      #define _CONFIG_SmallOpenMode  
          #define _CONFIG_SmallOpenMode_IgnoreRadar
	     #ifdef _CHERYE0X_PD_SmallOpenMode_MiniStop_DisablePowerOpen
	  #define _CONFIG_SmallOpenMode_DisableMode
	     #endif	  
           #ifndef _CHERYE0X_PD_InginDurability
      #define _CONFIG_MechanicalMode  
           #define _CONFIG_MechanicalMode_WaitCurrentOperateEnd
	   #define _CONFIG_MechanicalMode_LatchFindeHomeAfterPowerOn
           #endif
      //#define _CONFIG_ZCULost_MechanicalMode
      #define _CONFIG_MiniStopMode	
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      #define _CONFIG_MessageTx_Information
   #endif  
   #ifdef _CHERY_COM_PLG
      //#define _CONFIG_AppAuthorize 
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
      //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      #define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    #define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            #define _CONFIG_VehicleAntiTheft_CycleNoActive
      #define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      #define _CONFIG_VehicleRemoteMode  /*Reserved for RVSMode*/
      
      //#define _CONFIG_VehicleDriveMode
           //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
           //#define _CONFIG_RemoteKey_Opening_Reverse
           //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
           //#define _CONFIG_FobLongPress_Opening_Reverse
           //#define _CONFIG_FobLongPress_Closing_Reverse
           //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
           //#define _CONFIG_FobShortPress_Opening_Reverse
           //#define _CONFIG_FobShortPress_Closing_Reverse
           //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            #define _CONFIG_KickSensor_Authorize
	    #define _CONFIG_KickSensor_Authorize_PKE
	    #define _CONFIG_KickSensor_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    #define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased	    
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            #define _CONFIG_DriverButton_LongPress
	          #define _CONFIG_DriverButton_LongPress_NewPressAfterStop
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      #define _CONFIG_CommandDelay_Cancel
            #define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             #define _CONFIG_AppOpen_KeepOpening
	     #define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             #define _CONFIG_AppClose_KeepClosing
	     #define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine    
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch          
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      #define _CONFIG_VehicleSpeedHigh_DefautClose
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	              //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce 
      #define _CONFIG_VehicleCrash
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_Real
            #define _CONFIG_VehicleCrash_DisableMode 
	    #define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            ////#define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature	   
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      #define _CONFIG_SmallOpenMode
      #define _CONFIG_MechanicalMode
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      #define _CONFIG_MessageTx_Information
   #endif   
#endif



#ifdef _VOYAH_COM 
    #ifdef _VOYAH_COM_PD
      //#define _CONFIG_AppAuthorize 
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
      //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
	    //#define _CONFIG_VehicleSpeed_E2E
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
	    //#define _CONFIG_VehicleGearLever_E2E
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      //#define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleRemoteMode  /*Reserved for RVSMode*/
      
      #define _CONFIG_VehicleDriveMode
           #define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      #define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      
      #define _CONFIG_VehicleMode              
            //#define _CONFIG_VehicleMode_Real
            //#define _CONFIG_VehicleMode_DisableMode
	    //#define _CONFIG_VehicleMode_SmallOpenMode
	    #define _CONFIG_VehicleMode_MechanicalMode	
	        #ifdef _CHERYE0X_PD_VehicleMode_Factory_Learn
	    #define _CONFIG_VehicleMode_MechanicalMode_Disable
	          #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByCPIDLearn
		  #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByDriverButton
		#endif  
      #define _CONFIG_VehicleBrake
            #define _CONFIG_VehicleBrake_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleBrake_ShortPress
            #define _CONFIG_VehicleBrake_LongPress
                   #define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    	
      #define _CONFIG_VehicleCrash            
            //#define _CONFIG_VehicleCrash_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_SmallOpenMode
	    #define _CONFIG_VehicleCrash_MechanicalMode
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      //#define _CONFIG_VehicleClean            
            //#define _CONFIG_VehicleClean_Real
	    //#define _CONFIG_VehicleClean_E2E
            //#define _CONFIG_VehicleClean_DisableMode 
	    //#define _CONFIG_VehicleClean_SmallOpenMode
	    //#define _CONFIG_VehicleClean_MechanicalMode
      #define _CONFIG_VehicleRain	
            #define _CONFIG_VehicleRain_Real
	    //#define _CONFIG_VehicleClean_E2E
      
      //#define _CONFIG_TouchPad               
            //#define _CONFIG_TouchPad_FallEdge
	    //#define _CONFIG_TouchPad_Disable
	          //#define _CONFIG_TouchPad_Disable_ByTouchPad
	    //#define _CONFIG_TouchPad_ReleaseOnly
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default 
      //#define _CONFIG_TouchPad_2nd
            //#define _CONFIG_TouchPad_2nd_FallEdge
	         //#define _CONFIG_TouchPad_2nd_FallEdge_ReleaseOnly_ShortPress_PowerOpen
	    //#define _CONFIG_TouchPad_2nd_ShortPress	   	         
            //#define _CONFIG_TouchPad_2nd_LongPress
            //#define _CONFIG_TouchPad_2nd_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_2nd_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_2nd_Authorize_PKE
	    //#define _CONFIG_TouchPad_2nd_Authorize_Combine
            //#define _CONFIG_TouchPad_2nd_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_2nd_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_2nd_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_2nd_Opening_Reverse
            //#define _CONFIG_TouchPad_2nd_Closing_Reverse
	    //#define _CONFIG_TouchPad_2nd_Open_Default 	    
	    //#define _CONFIG_TouchPad_2nd_Close_Default	 
	    //#define _CONFIG_TouchPad_2nd_OnlyInOpen
            //#define _CONFIG_TouchPad_2nd_Disable
	          //#define _CONFIG_TouchPad_2nd_Disable_ByTouchPad
		  //#define _CONFIG_TouchPad_2nd_Disable_ByPKETrunkButton
	
      //#define _CONFIG_RemoteKey
           //#define _CONFIG_RemoteKey_Opening_Reverse
           //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
           //#define _CONFIG_FobLongPress_Opening_Reverse
           //#define _CONFIG_FobLongPress_Closing_Reverse
           //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
           //#define _CONFIG_FobShortPress_Opening_Reverse
           //#define _CONFIG_FobShortPress_Closing_Reverse
           //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KnockButton
           //#define _CONFIG_KnockButton_Opening_Reverse
           //#define _CONFIG_KnockButton_Closing_Reverse	   
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_KickSensor_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Disable
	          //#define _CONFIG_PKETrunkButton_Disable_ByTouchPad
		  //#define _CONFIG_PKETrunkButton_Disable_ByTouchPad_2nd
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
	    //#define _CONFIG_PKETrunkButton_Open_Disable
	    //#define _CONFIG_PKETrunkButton_Close_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_ShortPress
            //#define _CONFIG_VirtualButton_LongPress
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	    //#define _CONFIG_InsideButton_LongPress_Open_Default
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased	    
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
	    //#define _CONFIG_DriverButton_LongPress_Open_Default
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      #define _CONFIG_LatchReleaseState	  
         #if defined _CONFIG_LatchControl_NoPowerRelease || defined _CONFIG_LatchControl_NoPowerCinch 
      #define _CONFIG_PawlSignal	 
      #define _CONFIG_SecondarySignal	
      #define _CONFIG_AjarSignal
         #endif
	 #ifdef _CONFIG_LatchControl_NoPowerCinch
      #define _CONFIG_PositionSignal
         #endif
      
      //#define _CONFIG_CentralLockSignal
      #define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
           //#define _CONFIG_LatchSignal_LatchSwitch
           //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_SeatBelt
            //#define _CONFIG_SeatBelt_Opening_Reverse
      //#define _CONFIG_SeatOccupied
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine    
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
	     //#define _CONFIG_AppStop_MechanicalMode
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      //#define _CONFIG_AppButton
             //#define _CONFIG_AppButton_Opening_Reverse
             //#define _CONFIG_AppButton_Closing_Reverse
	     //#define _CONFIG_AppButton_ReleaseOnlyInReleased
      //#define _CONFIG_AppEnable	
      //#define _CONFIG_AppReset	
      //#define _CONFIG_AppDemoMode
      
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     #define _CONFIG_VROpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     #define _CONFIG_VRClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             #define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch  
      #define _CONFIG_VRSmallOpen	
             #define _CONFIG_VRSmallOpen_SmallOpenMode
      //#define _CONFIG_VRStopDirectly	     
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_RKEOpen
              //#define _CONFIG_RKEOpen_KeepOpening
	      //#define _CONFIG_RKEOpen_Closing_Reverse
	      //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      //#define _CONFIG_RKEClose 
              //#define _CONFIG_RKEClose_KeepClosing
	      //#define _CONFIG_RKEClose_Opening_Reverse
      //#define _CONFIG_RKEStopOpen
              //#define _CONFIG_RKEStopOpen_PowerOpenWhileLatchCinch
      //#define _CONFIG_RKEStopClose 
              //#define _CONFIG_RKEStopClose_PowerOpenWhileLatchCinch
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      //#define _CONFIG_BLEButton
           //#define _CONFIG_BLEButton_Opening_Reverse
           //#define _CONFIG_BLEButton_Closing_Reverse
	   //#define _CONFIG_BLEButton_ReleaseOnlyInReleased
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    #define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      //#define _CONFIG_VehicleSpeedHigh_IgnoreCommand_InClosing
      //#define _CONFIG_VehicleSpeedStop
            //#define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      #define _CONFIG_AdasRadar
            ////#define _CONFIG_AdasRadar_Real
	    ////#define _CONFIG_AdasRadar_PreferSafe
	    #define _CONFIG_AdasRadar_PreferFunction
            #define _CONFIG_AdasRadar_Detect_Cyclic
            //#define _CONFIG_AdasRadar_Detect_Event
	          //#define _CONFIG_AdasRadar_CommandDelay
		           //#define _CONFIG_AdasRadar_CommandDelay_FromClose
			   //#define _CONFIG_AdasRadar_CommandDelay_FromOpen
			   //#define _CONFIG_AdasRadar_CommandDelay_PullHandle
	          //#define _CONFIG_AdasRadar_DelayCheck
		           //#define _CONFIG_AdasRadar_DelayCheck_FromClose
			   //#define _CONFIG_AdasRadar_DelayCheck_FromOpen    
	    #define _CONFIG_AdasRadar_ReleaseToPowerOpen
	    #define _CONFIG_AdasRadar_StopDirectly	    	  
	    #define _CONFIG_AdasRadar_MiniStop	       
	    //#define _CONFIG_AdasRadar_MechanicalMode	
	    //#define _CONFIG_AdasRadar_SmallOpenMode
	    #define _CONFIG_AdasRadar_Lost_Disable
	    #define _CONFIG_AdasRadar_Disable
	          #define _CONFIG_AdasRadar_RearCorner_Enable
		  //#define _CONFIG_MmwRadar_Disable_Manual
	    
	    #define _CONFIG_AdasRadar_RearCorner_Error
	    #define _CONFIG_AdasRadar_RearCorner_Obstacle
	    //#define _CONFIG_AdasRadar_RearCorner_Angle
	          //#define _CONFIG_AdasRadar_RearCorner_Angle_Actual
		  //#define _CONFIG_AdasRadar_RearCorner_Angle_Delta	    
	    
	    #define _CONFIG_AdasRadar_RearCorner_Distance
            #define _CONFIG_AdasRadar_RearCornerX_Distance
            #define _CONFIG_AdasRadar_RearCornerY_Distance
	    #define _CONFIG_AdasRadar_RearCornerZ_Distance
	    #define _CONFIG_AdasRadar_RearCorner_RadarSelf
	    //#define _CONFIG_AdasRadar_FrontCorner_Error
	    //#define _CONFIG_AdasRadar_FrontCorner_Obstacle
	    //#define _CONFIG_AdasRadar_FrontCorner_Angle
	            //#define _CONFIG_AdasRadar_FrontCorner_Angle_Actual
		    //#define _CONFIG_AdasRadar_FrontCorner_Angle_Delta
	    //#define _CONFIG_AdasRadar_FrontCorner_Distance
            //#define _CONFIG_AdasRadar_FrontCornerX_Distance
            //#define _CONFIG_AdasRadar_FrontCornerY_Distance
	    //#define _CONFIG_AdasRadar_FrontCornerZ_Distance
	    //#define _CONFIG_AdasRadar_FrontCorner_RadarSelf	
      #define _CONFIG_MmwRadar	
	        #ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe
	        #else
		    #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe	   
		   #else
	    #define _CONFIG_MmwRadar_PreferFunction 
	           #endif	    
	        #endif
	    //#define _CONFIG_MmwRadar_Detect_Cyclic
            #define _CONFIG_MmwRadar_Detect_Event
	          #define _CONFIG_MmwRadar_CommandDelay
		           //#define _CONFIG_MmwRadar_CommandDelay_FromClose
			   #define _CONFIG_MmwRadar_CommandDelay_FromOpen
			   #define _CONFIG_MmwRadar_CommandDelay_PullHandle
	          #define _CONFIG_MmwRadar_DelayCheck
		           #define _CONFIG_MmwRadar_DelayCheck_FromClose
			   //#define _CONFIG_MmwRadar_DelayCheck_FromOpen	    
	    #define _CONFIG_MmwRadar_ReleaseToPowerOpen
	    //#define _CONFIG_MmwRadar_StopDirectly
	    #define _CONFIG_MmwRadar_MiniStop
	    //#define _CONFIG_MmwRadar_MechanicalMode    
	    #define _CONFIG_MmwRadar_Error
	         //#define _CONFIG_MmwRadar_Error_DoorStop
	    #define _CONFIG_MmwRadar_Obstacle
	    #define _CONFIG_MmwRadar_Angle
	          #define _CONFIG_MmwRadar_Angle_NonSafeDistance
	          //#define _CONFIG_MmwRadar_Angle_SafeDistance
	          #define _CONFIG_MmwRadar_Angle_Actual
		  //#define _CONFIG_MmwRadar_Angle_Delta		  		  
	    #define _CONFIG_MmwRadar_Distance
                  #define _CONFIG_MmwRadarX_Distance
                  #define _CONFIG_MmwRadarY_Distance
	          #define _CONFIG_MmwRadarZ_Distance
	          //#define _CONFIG_MmwRadarD_Distance
	    #define _CONFIG_MmwRadar_DeadZone
	    #define _CONFIG_MmwRadar_PauseOpen
	          #define _CONFIG_MmwRadar_PauseOpen_ContinueTimes
	    #define _CONFIG_MmwRadar_RadarSelf	  
	    //#define _CONFIG_MmwRadar_PowerOpen_Disable
	    #define _CONFIG_MmwRadar_Lost_Disable
	    #define _CONFIG_MmwRadar_Disable
	          #define _CONFIG_MmwRadar_Disable_Unlearn
	          //#define _CONFIG_MmwRadar_Disable_OpenCloseSwitch_LongPress
		      #ifdef _CHERYE0X_PD_116_MmwRadar_Disable_Manual
		  #define _CONFIG_MmwRadar_Disable_Manual   
		      #endif
	    
	    
      #define _CONFIG_SonicRadar 
		#ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe  
	        #else  
		   #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe 	   
		   #else
	    #define _CONFIG_SonicRadar_PreferFunction  
	           #endif
	        #endif
            //#define _CONFIG_SonicRadar_Detect_Cyclic
            #define _CONFIG_SonicRadar_Detect_Event
	          #define _CONFIG_SonicRadar_CommandDelay
		           //#define _CONFIG_SonicRadar_CommandDelay_FromClose
			   #define _CONFIG_SonicRadar_CommandDelay_FromOpen
			   #define _CONFIG_SonicRadar_CommandDelay_PullHandle
	          #define _CONFIG_SonicRadar_DelayCheck
		           #define _CONFIG_SonicRadar_DelayCheck_FromClose
			   //#define _CONFIG_SonicRadar_DelayCheck_FromOpen
	    #define _CONFIG_SonicRadar_ReleaseToPowerOpen
	    //#define _CONFIG_SonicRadar_StopDirectly
	    #define _CONFIG_SonicRadar_MiniStop
	    //#define _CONFIG_SonicRadar_MechanicalMode
	    
	    #define _CONFIG_SonicRadar_Error
	          #define _CONFIG_SonicRadar_Error_DoorStop
	          //#define _CONFIG_SonicRadar_Error_AllRadarFault /*for OTS1 Vehicle Build*/
		  //#define _CONFIG_SonicRadar_Error_DisableRadarVoltage
            #define _CONFIG_SonicRadar_Obstacle
	    #define _CONFIG_SonicRadar_Angle	
	          #define _CONFIG_SonicRadar_Angle_NonSafeDistance
	          //#define _CONFIG_SonicRadar_Angle_SafeDistance		  
	          #define _CONFIG_SonicRadar_Angle_Actual
		  //#define _CONFIG_SonicRadar_Angle_Delta
            #define _CONFIG_SonicRadar1_Distance
            #define _CONFIG_SonicRadar2_Distance
	    #define _CONFIG_SonicRadar3_Distance	    
	    #define _CONFIG_SonicRadar_DeadZone
	    #define _CONFIG_SonicRadar_PauseOpen
	          #define _CONFIG_SonicRadar_PauseOpen_ContinueTimes	    
            #define _CONFIG_SonicRadar_RadarSelf
	    ////#define _CONFIG_SonicRadar_PowerOpen_Disable
	    #define _CONFIG_SonicRadar_Lost_Disable
	    #define _CONFIG_SonicRadar_Disable
	              #define _CONFIG_SonicRadar_Disable_Unlearn
	              #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	          #define _CONFIG_SonicRadar_Disable_OpenCloseSwitch_LongPress
	              #endif
		      #ifdef _CHERYE0X_PD_631_SonicRadar_Disable_Manual
		  #define _CONFIG_SonicRadar_Disable_Manual   
		      #endif
	    	    
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_TargetPositionOpen
            //#define _CONFIG_TargetPositionOpen_KeepOpening
            //#define _CONFIG_TargetPositionOpen_Closing_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
      //#define _CONFIG_TargetPositionClose
            //#define _CONFIG_TargetPositionClose_KeepClosing
	    //#define _CONFIG_TargetPositionClose_Opening_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
	  
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer
      #define _CONFIG_TimeInformation

      #define _CONFIG_DoorStatus
            #define _CONFIG_DoorStatus_SideDoor
	        #ifdef _VOYAH_COM_PD_FL
	          #define _CONFIG_DoorStatus_DriverDoor
		#endif  
		#ifdef _VOYAH_COM_PD_FR
	          #define _CONFIG_DoorStatus_PassengerDoor
		#endif  
		#ifdef _VOYAH_COM_PD_RL  
	          #define _CONFIG_DoorStatus_RearLeftDoor
		#endif  
		#ifdef _VOYAH_COM_PD_RR  
	          #define _CONFIG_DoorStatus_RearRightDoor
		#endif  
	    //#define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
	    #define _CONFIG_DoorStatus_TrunkDoor
      #define _CONFIG_WindowsPosition
            #define _CONFIG_WindowsPosition_SideDoor
	    //#define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
            #define _CONFIG_BusTemperature
	    #define _CONFIG_BusTemperature_PowerModeOFF_Invalid
	    //#define _CONFIG_Bus_Board_Temperature_Delta
	    
      #define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   #define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_E2E
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	
	   //#define _CONFIG_BusIncline_NoReal_BoardInclineOnly
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink 
           //#define _CONFIG_BusIncline_Compensation
		 
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode  	    
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      //#define _CONFIG_ObstcalAlarmEnable
      //#define _CONFIG_BLEEnable
      //#define _CONFIG_VoiceEnable
      #define _CONFIG_BrakeEnable
      //#define _CONFIG_RKEEnable 
     
      //#define _CONFIG_ManualOperateEnable
      //#define _CONFIG_MotorHoldEnable
      //#define _CONFIG_DoorPowerMode                 
      #define _CONFIG_CinchEnable 
      #define _CONFIG_BeltEnable
      #define _CONFIG_WindEnable
      #define _CONFIG_SpeedMode 
      
      //#define _CONFIG_ConfigurationTrigger
      //#define _CONFIG_SideDoorOpeningMode
      //#define _CONFIG_LeftAndRightRudder
      //#define _CONFIG_BNCM
                
      #define _CONFIG_SmallOpenMode  
          #define _CONFIG_SmallOpenMode_IgnoreRadar
           #ifndef _CHERYE0X_PD_InginDurability
      #define _CONFIG_MechanicalMode  
           #define _CONFIG_MechanicalMode_WaitCurrentOperateEnd
	   #define _CONFIG_MechanicalMode_LatchFindeHomeAfterPowerOn
           #endif
      //#define _CONFIG_ZCULost_MechanicalMode
      #define _CONFIG_MiniStopMode	
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      #define _CONFIG_MessageTx_Information
   #endif  
#endif   


#ifdef _AUDI_COM 
    #ifdef _AUDI_COM_PD
      //#define _CONFIG_AppAuthorize 
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
      //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
	    //#define _CONFIG_VehicleSpeed_E2E
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
	    //#define _CONFIG_VehicleGearLever_E2E
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      #define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleRemoteMode  /*Reserved for RVSMode*/
      
      //#define _CONFIG_VehicleDriveMode
           //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      
      #define _CONFIG_VehicleMode
            //#define _CONFIG_VehicleMode_Real
            //#define _CONFIG_VehicleMode_DisableMode
	    //#define _CONFIG_VehicleMode_SmallOpenMode
	    #define _CONFIG_VehicleMode_MechanicalMode	
	        #ifdef _CHERYE0X_PD_VehicleMode_Factory_Learn
	    #define _CONFIG_VehicleMode_MechanicalMode_Disable
	          #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByCPIDLearn
		  #define _CONFIG_VehicleMode_MechanicalMode_Disable_ByDriverButton
		#endif  
      #define _CONFIG_VehicleBrake
            #define _CONFIG_VehicleBrake_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleBrake_ShortPress
            #define _CONFIG_VehicleBrake_LongPress
                   #define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    	
      #define _CONFIG_VehicleCrash            
            #define _CONFIG_VehicleCrash_Real
	    //#define _CONFIG_VehicleBrake_E2E
            //#define _CONFIG_VehicleCrash_DisableMode 
	        #ifndef _CHERYE0X_PD_InginDurability 
	    //#define _CONFIG_VehicleCrash_SmallOpenMode
	        #endif
	    //#define _CONFIG_VehicleCrash_MechanicalMode
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      #define _CONFIG_VehicleClean            
            //#define _CONFIG_VehicleClean_Real
	    //#define _CONFIG_VehicleClean_E2E
            //#define _CONFIG_VehicleClean_DisableMode 
	    //#define _CONFIG_VehicleClean_SmallOpenMode
	    #define _CONFIG_VehicleClean_MechanicalMode	    
      
      #define _CONFIG_TouchPad               
            #define _CONFIG_TouchPad_FallEdge
	    #define _CONFIG_TouchPad_Disable
	          #define _CONFIG_TouchPad_Disable_ByTouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default 	
      #define _CONFIG_TouchPad_2nd
            #define _CONFIG_TouchPad_2nd_FallEdge
	         //#define _CONFIG_TouchPad_2nd_FallEdge_ReleaseOnly_ShortPress_PowerOpen
	    //#define _CONFIG_TouchPad_2nd_ShortPress	   	         
            //#define _CONFIG_TouchPad_2nd_LongPress
            //#define _CONFIG_TouchPad_2nd_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_2nd_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_2nd_Authorize_PKE
	    //#define _CONFIG_TouchPad_2nd_Authorize_Combine
            //#define _CONFIG_TouchPad_2nd_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_2nd_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_2nd_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_2nd_Opening_Reverse
            //#define _CONFIG_TouchPad_2nd_Closing_Reverse
	    //#define _CONFIG_TouchPad_2nd_Open_Default 	    
	         #ifdef _CHERYE0X_PD_OutsideHandleInsideSwitch_Enable
	    #define _CONFIG_TouchPad_2nd_Close_Default	 
	    #define _CONFIG_TouchPad_2nd_OnlyInOpen
            #define _CONFIG_TouchPad_2nd_Disable
	          #define _CONFIG_TouchPad_2nd_Disable_ByTouchPad
		  #define _CONFIG_TouchPad_2nd_Disable_ByPKETrunkButton
	         #endif
      //#define _CONFIG_RemoteKey
           //#define _CONFIG_RemoteKey_Opening_Reverse
           //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
           //#define _CONFIG_FobLongPress_Opening_Reverse
           //#define _CONFIG_FobLongPress_Closing_Reverse
           //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
           //#define _CONFIG_FobShortPress_Opening_Reverse
           //#define _CONFIG_FobShortPress_Closing_Reverse
           //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_KickSensor_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      #define _CONFIG_PKETrunkButton
                 #ifdef _CHERYE0X_PD_OutsideHandleInsideSwitch_Enable
            #define _CONFIG_PKETrunkButton_Disable
	          #define _CONFIG_PKETrunkButton_Disable_ByTouchPad
		  #define _CONFIG_PKETrunkButton_Disable_ByTouchPad_2nd
	         #endif
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
	    #define _CONFIG_PKETrunkButton_Open_Disable
	    #define _CONFIG_PKETrunkButton_Close_Default
      #define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_ShortPress
            //#define _CONFIG_VirtualButton_LongPress
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      #define _CONFIG_InsideButton
                 #ifdef _CHERYE0X_PD_InsideHandleLongPress
            #define _CONFIG_InsideButton_ShortPress
            #define _CONFIG_InsideButton_LongPress
	    #define _CONFIG_InsideButton_LongPress_Open_Default
	         #endif
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased	    
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
	    //#define _CONFIG_DriverButton_LongPress_Open_Default
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      #define _CONFIG_LatchReleaseState	  
         #if defined _CONFIG_LatchControl_NoPowerRelease || defined _CONFIG_LatchControl_NoPowerCinch 
      #define _CONFIG_PawlSignal	 
      #define _CONFIG_SecondarySignal	
         #endif
	 #ifdef _CONFIG_LatchControl_NoPowerCinch
      #define _CONFIG_PositionSignal
         #endif
      
      #define _CONFIG_CentralLockSignal
      #define _CONFIG_ChildLockSignal
      #define _CONFIG_LatchSignal
           //#define _CONFIG_LatchSignal_LatchSwitch
           //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_SeatBelt
             //#define _CONFIG_SeatBelt_Opening_Reverse
      //#define _CONFIG_SeatOccupied
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Closing_Reverse_StopSoft
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Opening_Reverse_StopSoft
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine    
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
	     //#define _CONFIG_AppStop_MechanicalMode
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      //#define _CONFIG_AppButton
             //#define _CONFIG_AppButton_Opening_Reverse
             //#define _CONFIG_AppButton_Closing_Reverse
	     //#define _CONFIG_AppButton_ReleaseOnlyInReleased
      //#define _CONFIG_AppEnable	
      //#define _CONFIG_AppReset	
      //#define _CONFIG_AppDemoMode
      
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch   
      #define _CONFIG_VRStopDirectly	     
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_RKEOpen
              #define _CONFIG_RKEOpen_KeepOpening
	      #define _CONFIG_RKEOpen_Closing_Reverse
	      //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_RKEClose 
              #define _CONFIG_RKEClose_KeepClosing
	      #define _CONFIG_RKEClose_Opening_Reverse
      #define _CONFIG_RKEStopOpen
              #define _CONFIG_RKEStopOpen_PowerOpenWhileLatchCinch
      #define _CONFIG_RKEStopClose 
              #define _CONFIG_RKEStopClose_PowerOpenWhileLatchCinch
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      
      #define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      #define _CONFIG_VoiceOpen
             #define _CONFIG_VoiceOpen_KeepOpening
	     #define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      #define _CONFIG_VoiceClose
             #define _CONFIG_VoiceClose_KeepClosing
	     #define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      #define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             #define _CONFIG_BLEClose_KeepClosing
	     #define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      #define _CONFIG_BLEButton
           //#define _CONFIG_BLEButton_Opening_Reverse
           //#define _CONFIG_BLEButton_Closing_Reverse
	   //#define _CONFIG_BLEButton_ReleaseOnlyInReleased
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    #define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      #define _CONFIG_VehicleSpeedHigh_IgnoreCommand_InClosing
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      #define _CONFIG_AdasRadar
            ////#define _CONFIG_AdasRadar_Real
	    ////#define _CONFIG_AdasRadar_PreferSafe
	    #define _CONFIG_AdasRadar_PreferFunction
            #define _CONFIG_AdasRadar_Detect_Cyclic
            //#define _CONFIG_AdasRadar_Detect_Event
	          //#define _CONFIG_AdasRadar_CommandDelay
		           //#define _CONFIG_AdasRadar_CommandDelay_FromClose
			   //#define _CONFIG_AdasRadar_CommandDelay_FromOpen
			   //#define _CONFIG_AdasRadar_CommandDelay_PullHandle
	          //#define _CONFIG_AdasRadar_DelayCheck
		           //#define _CONFIG_AdasRadar_DelayCheck_FromClose
			   //#define _CONFIG_AdasRadar_DelayCheck_FromOpen    
	    #define _CONFIG_AdasRadar_ReleaseToPowerOpen
	    #define _CONFIG_AdasRadar_StopDirectly	    	  
	    #define _CONFIG_AdasRadar_MiniStop
	    //#define _CONFIG_AdasRadar_MechanicalMode
	    //#define _CONFIG_AdasRadar_SmallOpenMode
	    #define _CONFIG_AdasRadar_Lost_Disable
	    #define _CONFIG_AdasRadar_Disable
	          #define _CONFIG_AdasRadar_RearCorner_Enable
		  //#define _CONFIG_MmwRadar_Disable_Manual
	    
	    #define _CONFIG_AdasRadar_RearCorner_Error
	    #define _CONFIG_AdasRadar_RearCorner_Obstacle
	    //#define _CONFIG_AdasRadar_RearCorner_Angle
	          //#define _CONFIG_AdasRadar_RearCorner_Angle_Actual
		  //#define _CONFIG_AdasRadar_RearCorner_Angle_Delta	    
	    
	    #define _CONFIG_AdasRadar_RearCorner_Distance
            #define _CONFIG_AdasRadar_RearCornerX_Distance
            #define _CONFIG_AdasRadar_RearCornerY_Distance
	    #define _CONFIG_AdasRadar_RearCornerZ_Distance
	    #define _CONFIG_AdasRadar_RearCorner_RadarSelf
	    //#define _CONFIG_AdasRadar_FrontCorner_Error
	    //#define _CONFIG_AdasRadar_FrontCorner_Obstacle
	    //#define _CONFIG_AdasRadar_FrontCorner_Angle
	            //#define _CONFIG_AdasRadar_FrontCorner_Angle_Actual
		    //#define _CONFIG_AdasRadar_FrontCorner_Angle_Delta
	    //#define _CONFIG_AdasRadar_FrontCorner_Distance
            //#define _CONFIG_AdasRadar_FrontCornerX_Distance
            //#define _CONFIG_AdasRadar_FrontCornerY_Distance
	    //#define _CONFIG_AdasRadar_FrontCornerZ_Distance
	    //#define _CONFIG_AdasRadar_FrontCorner_RadarSelf	
      #define _CONFIG_MmwRadar	
	        #ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe
	        #else
		    #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_MmwRadar_Real
	    #define _CONFIG_MmwRadar_PreferSafe	   
		   #else
	    #define _CONFIG_MmwRadar_PreferFunction 
	           #endif	    
	        #endif
	    //#define _CONFIG_MmwRadar_Detect_Cyclic
            #define _CONFIG_MmwRadar_Detect_Event
	          #define _CONFIG_MmwRadar_CommandDelay
		           #define _CONFIG_MmwRadar_CommandDelay_FromClose
			   #define _CONFIG_MmwRadar_CommandDelay_FromOpen
			   #define _CONFIG_MmwRadar_CommandDelay_PullHandle
	          #define _CONFIG_MmwRadar_DelayCheck
		           #define _CONFIG_MmwRadar_DelayCheck_FromClose
			   //#define _CONFIG_MmwRadar_DelayCheck_FromOpen	    
	    #define _CONFIG_MmwRadar_ReleaseToPowerOpen
	    //#define _CONFIG_MmwRadar_StopDirectly
	    #define _CONFIG_MmwRadar_MiniStop
	    //#define _CONFIG_MmwRadar_MechanicalMode    
	    #define _CONFIG_MmwRadar_Error
	         //#define _CONFIG_MmwRadar_Error_DoorStop
	    //#define _CONFIG_MmwRadar_Obstacle
	    #define _CONFIG_MmwRadar_Angle
	          #define _CONFIG_MmwRadar_Angle_NonSafeDistance
	          //#define _CONFIG_MmwRadar_Angle_SafeDistance
	          #define _CONFIG_MmwRadar_Angle_Actual
		  //#define _CONFIG_MmwRadar_Angle_Delta		  		  
	    #define _CONFIG_MmwRadar_Distance
                  #define _CONFIG_MmwRadarX_Distance
                  #define _CONFIG_MmwRadarY_Distance
	          #define _CONFIG_MmwRadarZ_Distance
	          #define _CONFIG_MmwRadarD_Distance
	    #define _CONFIG_MmwRadar_DeadZone
	    ////#define _CONFIG_MmwRadar_PauseOpen
	          ////#define _CONFIG_MmwRadar_PauseOpen_ContinueTimes
	    #define _CONFIG_MmwRadar_RadarSelf	  
	    //#define _CONFIG_MmwRadar_PowerOpen_Disable
	    #define _CONFIG_MmwRadar_Lost_Disable
	    #define _CONFIG_MmwRadar_Disable
	          #define _CONFIG_MmwRadar_Disable_Unlearn
	          //#define _CONFIG_MmwRadar_Disable_OpenCloseSwitch_LongPress
		      #ifdef _CHERYE0X_PD_116_MmwRadar_Disable_Manual
		  #define _CONFIG_MmwRadar_Disable_Manual   
		      #endif
	    
	    
      #define _CONFIG_SonicRadar 
		#ifndef _CHERYE0X_PD_InginDurability
            #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe  
	        #else  
		   #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	    #define _CONFIG_SonicRadar_Real   
	    #define _CONFIG_SonicRadar_PreferSafe 	   
		   #else
	    #define _CONFIG_SonicRadar_PreferFunction  
	           #endif
	        #endif
            //#define _CONFIG_SonicRadar_Detect_Cyclic
            #define _CONFIG_SonicRadar_Detect_Event
	          #define _CONFIG_SonicRadar_CommandDelay
		           //#define _CONFIG_SonicRadar_CommandDelay_FromClose
			   #define _CONFIG_SonicRadar_CommandDelay_FromOpen
			   #define _CONFIG_SonicRadar_CommandDelay_PullHandle
	          #define _CONFIG_SonicRadar_DelayCheck
		           #define _CONFIG_SonicRadar_DelayCheck_FromClose
			   //#define _CONFIG_SonicRadar_DelayCheck_FromOpen
	    #define _CONFIG_SonicRadar_ReleaseToPowerOpen
	    //#define _CONFIG_SonicRadar_StopDirectly
	    #define _CONFIG_SonicRadar_MiniStop
	    //#define _CONFIG_SonicRadar_MechanicalMode
	    
	    #define _CONFIG_SonicRadar_Error
	          //#define _CONFIG_SonicRadar_Error_DoorStop
	          //#define _CONFIG_SonicRadar_Error_AllRadarFault /*for OTS1 Vehicle Build*/
		  //#define _CONFIG_SonicRadar_Error_DisableRadarVoltage
            #define _CONFIG_SonicRadar_Obstacle
	    #define _CONFIG_SonicRadar_Angle	
	          #define _CONFIG_SonicRadar_Angle_NonSafeDistance
	          //#define _CONFIG_SonicRadar_Angle_SafeDistance		  
	          #define _CONFIG_SonicRadar_Angle_Actual
		  //#define _CONFIG_SonicRadar_Angle_Delta
            #define _CONFIG_SonicRadar1_Distance
            #define _CONFIG_SonicRadar2_Distance
	    #define _CONFIG_SonicRadar3_Distance	    
	    #define _CONFIG_SonicRadar_DeadZone
	    #define _CONFIG_SonicRadar_PauseOpen
	          #define _CONFIG_SonicRadar_PauseOpen_ContinueTimes	    
            #define _CONFIG_SonicRadar_RadarSelf
	    ////#define _CONFIG_SonicRadar_PowerOpen_Disable
	    #define _CONFIG_SonicRadar_Lost_Disable
	    #define _CONFIG_SonicRadar_Disable
	              #define _CONFIG_SonicRadar_Disable_Unlearn
	              #ifdef _CHERYE0X_PD_InginDurability_RealRadar_DisalbeByOpenCloseSwitch
	          #define _CONFIG_SonicRadar_Disable_OpenCloseSwitch_LongPress
	              #endif
		      #ifdef _CHERYE0X_PD_631_SonicRadar_Disable_Manual
		  #define _CONFIG_SonicRadar_Disable_Manual   
		      #endif
    
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode        
      
      #define _CONFIG_TargetPositionOpen
            //#define _CONFIG_TargetPositionOpen_KeepOpening
            //#define _CONFIG_TargetPositionOpen_Closing_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
      #define _CONFIG_TargetPositionClose
            //define _CONFIG_TargetPositionClose_KeepClosing
	    //#define _CONFIG_TargetPositionClose_Opening_Reverse
	    //#define _CONFIG_TargetPositionOpen_Disable
      
      //#define _CONFIG_MusicControl	    
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
 
      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer
      #define _CONFIG_TimeInformation

      #define _CONFIG_DoorStatus
            #define _CONFIG_DoorStatus_SideDoor
	        #ifdef _AUDI_COM_PD_FL
	          #define _CONFIG_DoorStatus_DriverDoor
		#endif  
		#ifdef _AUDI_COM_PD_FR
	          #define _CONFIG_DoorStatus_PassengerDoor
		#endif  
		#ifdef _AUDI_COM_PD_RL  
	          #define _CONFIG_DoorStatus_RearLeftDoor
		#endif  
		#ifdef _AUDI_COM_PD_RR  
	          #define _CONFIG_DoorStatus_RearRightDoor
		#endif  
	    //#define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
	    #define _CONFIG_DoorStatus_TrunkDoor
      #define _CONFIG_WindowsPosition
            #define _CONFIG_WindowsPosition_SideDoor
	    //#define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
            #define _CONFIG_BusTemperature
	    #define _CONFIG_BusTemperature_PowerModeOFF_Invalid
	    //#define _CONFIG_Bus_Board_Temperature_Delta
	    
      #define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   #define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_E2E
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	
	   //#define _CONFIG_BusIncline_NoReal_BoardInclineOnly
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink 
           //#define _CONFIG_BusIncline_Compensation
		 
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode  	    
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      #define _CONFIG_AutoOpenEnable
      //#define _CONFIG_ObstcalAlarmEnable
      //#define _CONFIG_BLEEnable
      #define _CONFIG_VoiceEnable
      #define _CONFIG_BrakeEnable
      #define _CONFIG_RKEEnable 
      
      #define _CONFIG_ManualOperateEnable
      #define _CONFIG_MotorHoldEnable
      #define _CONFIG_DoorPowerMode
      
      #define _CONFIG_ConfigurationTrigger
      #define _CONFIG_SideDoorOpeningMode
      #define _CONFIG_LeftAndRightRudder
      #define _CONFIG_BNCM
                
      #define _CONFIG_SmallOpenMode  
           #define _CONFIG_SmallOpenMode_IgnoreRadar
           #ifndef _CHERYE0X_PD_InginDurability
      #define _CONFIG_MechanicalMode  
           #define _CONFIG_MechanicalMode_WaitCurrentOperateEnd
	   #define _CONFIG_MechanicalMode_LatchFindeHomeAfterPowerOn
           #endif	   
      //#define _CONFIG_ZCULost_MechanicalMode
           
      #define _CONFIG_MiniStopMode	
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      #define _CONFIG_MessageTx_Information
   #endif     
#endif



#ifdef _SGMW_COM
      #define _CONFIG_AppAuthorize
            #define _CONFIG_AppAuthorize_Clear_InClosed
	    #define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever     
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 
      
      //#define _CONFIG_VehicleDriveMode
           //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      #define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      //#define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      //#define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose 
      
      #define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake   
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	       
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      //#define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
            #define _CONFIG_BusTemperature
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      
#endif
#ifdef _SGM_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            #define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
           
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 	    
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default
      #define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_KickSensor_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse      
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      #define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      #define _CONFIG_ComfortOpen
      #define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      //#define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
           
      
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      //#define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake  
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	      
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      #define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl	  
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      //#define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            //#define _CONFIG_DoorStatus_OnlyFrontDoor
            //#define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            //#define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature
      
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      
      #define _CONFIG_FOBMode
           #define _FOBMode_No_Activation_EngineStop
           //#define _FOBMode_EngineStop
      

#endif

#ifdef _CTCS_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            #define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      #define _CONFIG_RemindStart
      #define _CONFIG_RemindStop
      //#define _CONFIG_ComfortClose
      #define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      #define _CONFIG_RemindStart
      #define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine 
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
            //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      #define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake   
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	        
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
             
      
      
      //#define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif

#ifdef _DEARCC_COM
      #define _CONFIG_AppAuthorize
            #define _CONFIG_AppAuthorize_Clear_InClosed
	    #define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      #define _CONFIG_FobAuthorize
            #define _CONFIG_FobAuthorize_Clear_InClosed
	    #define _CONFIG_FobAuthorize_Clear_Timeout
      #define _CONFIG_AntiLockAuthorize
            #define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    #define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            #define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            #define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            #define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode  
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine  
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      //#define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      //#define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake  
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	        
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
           
      
      
      //#define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            #define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode           	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink
 
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif

#ifdef _XIAOPENG_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
           
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever    
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 
      
      #define _CONFIG_VehicleDriveMode
           //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine 
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	    #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      #define _CONFIG_AppStepOpen
      #define _CONFIG_AppStepClose
	     
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      #define _CONFIG_VRStepOpen
      #define _CONFIG_VRStepClose
      
      #define _CONFIG_AutoOpen
      #define _CONFIG_AutoClose
      #define _CONFIG_AutoStop
      #define _CONFIG_AutoStepOpen
      #define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      #define _CONFIG_BLEOpen
            //#define _CONFIG_BLEOpen_Authorize
	    //#define _CONFIG_BLEOpen_Authorize_Combine
            //#define _CONFIG_BLEOpen_KeepOpening
	    //#define _CONFIG_BLEOpen_Closing_Reverse
	    //#define _CONFIG_BLEOpen_Reverse_Warning
	    //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
            //#define _CONFIG_BLEClose_Authorize
	    //#define _CONFIG_BLEClose_Authorize_Combine
            //#define _CONFIG_BLEClose_KeepClosing
	    //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      #define _CONFIG_BLEStop
            //#define _CONFIG_BLEStop_Authorize
	    //#define _CONFIG_BLEStop_Authorize_Combine
	    //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	    //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      #define _CONFIG_BLEStepOpen
      #define _CONFIG_BLEStepClose
      
      #define _CONFIG_RKEOpen
      #define _CONFIG_RKEClose     
      #define _CONFIG_RKEStopOpen
      #define _CONFIG_RKEStopClose     
      #define _CONFIG_RKEStepOpen
      #define _CONFIG_RKEStepClose    
      
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    #define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock 
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      #define _CONFIG_VehicleDriveModeStop
            #define _CONFIG_VehicleDriveModeStop_InOpening
	    #define _CONFIG_VehicleDriveModeStop_InClosing
	    
      
      #define _CONFIG_VehicleBrake
            //#define _CONFIG_VehicleBrake_Real
            #define _CONFIG_VehicleBrake_LongPress
                  #define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      #define _CONFIG_SonicRadar
           #define _CONFIG_SonicRadar_Real
           #define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      #define _CONFIG_Vehicle_KeyMode 
            #define _CONFIG_KeyOpenMode
            #define _CONFIG_KeyCloseMode
      
      #define _CONFIG_MusicControl
      #define _CONFIG_SlidePosition
          #define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse

      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
             #define _CONFIG_DoorStatus_TrunkDoor
	     #define _CONFIG_DoorStatus_SideDoor
	     //#define _CONFIG_DoorStatus_RearGate
             #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
             #define _CONFIG_WindowsPosition_SideDoor
	     //#define _CONFIG_WindowsPosition_RearGate
             #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      //#define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode           	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      #define _CONFIG_CloseSpeedLevel
#endif

#ifdef _MAXUS_COM
   #ifdef _MAXUS_COM_PLG
      #define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    #define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      #define _CONFIG_PKEAuthorize
            #define _CONFIG_PKEAuthorize_Clear_InClosed
	    #define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 	    
      
      //#define _CONFIG_VehicleDriveMode
              //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            #define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    #define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            #define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    #define _CONFIG_TouchPad_OpenedFully_Disable
	    #define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            #define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            #define _CONFIG_KickSensor_Authorize
	    #define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            #define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      #define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             #define _CONFIG_AppOpen_KeepOpening
	     #define _CONFIG_AppOpen_Closing_Reverse
	     #define _CONFIG_AppOpen_Reverse_Warning
	     #define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             #define _CONFIG_AppClose_KeepClosing
	     #define _CONFIG_AppClose_Opening_Reverse
	     #define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine  
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	    #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     #define _CONFIG_VROpen_Reverse_Warning
	     #define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     #define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    #define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      #define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      #define _CONFIG_VehicleBrake  
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      #define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      #define _CONFIG_SlidePosition
          #define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  #define _CONFIG_SlidePosition_SlideOpen
	         #define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 #define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  #define _CONFIG_SlidePosition_SlideClose
	         #define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 #define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
           
      
      //#define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_HoodDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      #define _CONFIG_BusIncline
           #define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   #define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink   
      
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            #define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode           	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable	   
	   
      //#define _CONFIG_DTCPush_DTCStatusAllBit_Cycles
      #define _CONFIG_DTCPush_DTCStatusBit1_OneTime
      #define _CONFIG_DebugMessage
           #define _CONFIG_DebugMessage_OpenCloseSwitch_LongPress
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
   #endif
   
   #ifdef _MAXUS_COM_PSD
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever  
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      #define _CONFIG_VehicleHandBrake
            #define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      
      //#define _CONFIG_VehicleDriveMode
              //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             #define _CONFIG_AppOpen_KeepOpening
	     #define _CONFIG_AppOpen_Closing_Reverse
	     #define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             #define _CONFIG_AppClose_KeepClosing
	     #define _CONFIG_AppClose_Opening_Reverse
	     #define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine  
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     #define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     #define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      #define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             #define _CONFIG_BLEOpen_KeepOpening
	     #define _CONFIG_BLEOpen_Closing_Reverse
	     #define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             #define _CONFIG_BLEClose_KeepClosing
	     #define _CONFIG_BLEClose_Opening_Reverse
	     #define _CONFIG_BLEClose_Reverse_Warning
      #define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      //#define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      //#define _CONFIG_VehicleSpeedStop
            //#define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      #define _CONFIG_VehicleBrake  
            #define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      #define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
           
      
      
      #define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    #define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_HoodDoor
	    //#define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            #define _CONFIG_WindowsPosition_SideDoor
	    //#define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      #define _CONFIG_BusIncline
           #define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   #define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink  
      
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            #define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode           	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable	   

      //#define _CONFIG_DTCPush_DTCStatusAllBit_Cycles
      #define _CONFIG_DTCPush_DTCStatusBit1_OneTime
      #define _CONFIG_DebugMessage
            #define _CONFIG_DebugMessage_OpenCloseSwitch_LongPress
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
   #endif
#endif

#ifdef _DFMC_COM
      #define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      #define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
            #define _CONFIG_VehiclePowerMode_RemoteON_Equal_ON
      #define _CONFIG_VehicleGearLever  
            //#define _CONFIG_VehicleGearLever_Real
      //#define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      #define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode  
      
      #define _CONFIG_VehicleDriveMode
            //#define _CONFIG_VehicleDriveMode_Real
      #define _CONFIG_VehicleChargeState
      #define _CONFIG_VehicleSOC
      #define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
           #define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
            //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    #define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      #define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      #define _CONFIG_AppOpen
             #define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             #define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine  
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_AutoOpen
      #define _CONFIG_AutoClose
      #define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      #define _CONFIG_BLEOpen
             #define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
             #define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
              //#define _CONFIG_BLEStop_Authorize
	      //#define _CONFIG_BLEStop_Authorize_Combine
	      //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	      //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange
	    
      #define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    #define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake   
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      #define _CONFIG_BusoffStop_InOpening
      //#define _CONFIG_BusoffStop_InClosing
	    
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      #define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 

      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable	   
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      #define _CONFIG_BusIncline
           #define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   #define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_DTCPush_DTCStatusAllBit_Cycles
      #define _CONFIG_DTCPush_DTCStatusBit1_OneTime
      #define _CONFIG_DebugMessage
           #define _CONFIG_DebugMessage_OpenCloseSwitch_LongPress
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif

#ifdef _BAIC_COM
   #ifdef _BAIC_COM_C52X
      #define _CONFIG_AppAuthorize
   #endif
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
   #ifdef _BAIC_COM_C52X   
      #define _CONFIG_BLEAuthorize
   #endif   
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
     #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C46DB)
      #define _CONFIG_PKEAuthorize
     #endif	    
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever  
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode  
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC   
      #define _CONFIG_VehicleVoltage
      #define _CONFIG_VehicleMode
              #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
           #define _CONFIG_VehicleMode_DisableMode
	   #define _CONFIG_VehicleMode_Recovery_PowerModeOfftoOn
	      #endif
      
      #define _CONFIG_TouchPad
            #define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    #define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            #define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      #define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
            #define _CONFIG_RemoteKey_ReleaseOnlyInReleased
      //#define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            #define _CONFIG_KickSensor_Authorize
	    #define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      #define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
             #define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      #define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            #define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      #define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock

      
      #define _CONFIG_AppOpen
            #ifdef _BAIC_COM_C52X
             #define _CONFIG_AppOpen_Authorize
	     #define _CONFIG_AppOpen_Authorize_Combine
	    #endif 
             #define _CONFIG_AppOpen_KeepOpening
	     #define _CONFIG_AppOpen_Closing_Reverse
	     #define _CONFIG_AppOpen_Reverse_Warning
	     #define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
            #ifdef _BAIC_COM_C52X 
             #define _CONFIG_AppClose_Authorize
	     #define _CONFIG_AppClose_Authorize_Combine
	    #endif 
             #define _CONFIG_AppClose_KeepClosing
	     #define _CONFIG_AppClose_Opening_Reverse
	     #define _CONFIG_AppClose_Reverse_Warning
      #define _CONFIG_AppStop
            #ifdef _BAIC_COM_C52X
             #define _CONFIG_AppStop_Authorize
	     #define _CONFIG_AppStop_Authorize_Combine 
	    #endif  
	    //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	    #define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
     #ifdef _BAIC_COM_C62X	     
      #define _CONFIG_VROpen
             #define _CONFIG_VROpen_KeepOpening
	     #define _CONFIG_VROpen_Closing_Reverse
	     #define _CONFIG_VROpen_Reverse_Warning
	     #define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             #define _CONFIG_VRClose_KeepClosing
	     #define _CONFIG_VRClose_Opening_Reverse
	     #define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
     #endif  
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      #define _CONFIG_AutoOpen
	    #define _CONFIG_AutoOpen_KeepClosing
            #define _CONFIG_AutoOpen_KeepOpening
	    //#define _CONFIG_AutoOpen_Closing_Reverse
	    //#define _CONFIG_AutoOpen_Reverse_Warning
      #define _CONFIG_AutoClose
            #define _CONFIG_AutoClose_KeepOpening
            #define _CONFIG_AutoClose_KeepClosing
	    //#define _CONFIG_AutoClose_Opening_Reverse
	    //#define _CONFIG_AutoClose_Reverse_Warning
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
    #if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C46DB)  
      #define _CONFIG_VoiceOpen
             #define _CONFIG_VoiceOpen_KeepOpening
	     #define _CONFIG_VoiceOpen_Closing_Reverse
	     #define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      #define _CONFIG_VoiceClose
             #define _CONFIG_VoiceClose_KeepClosing
	     #define _CONFIG_VoiceClose_Opening_Reverse
	     #define _CONFIG_VoiceClose_Reverse_Warning
      #define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
     #endif
     
      #define _CONFIG_BLEOpen
            #ifdef _BAIC_COM_C52X
             #define _CONFIG_BLEOpen_Authorize
	     #define _CONFIG_BLEOpen_Authorize_Combine
	    #endif 
             #define _CONFIG_BLEOpen_KeepOpening
	     #define _CONFIG_BLEOpen_Closing_Reverse
	     #define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      #define _CONFIG_BLEClose
            #ifdef _BAIC_COM_C52X
             #define _CONFIG_BLEClose_Authorize
	     #define _CONFIG_BLEClose_Authorize_Combine
	    #endif 
             #define _CONFIG_BLEClose_KeepClosing
	     #define _CONFIG_BLEClose_Opening_Reverse
	     #define _CONFIG_BLEClose_Reverse_Warning
      #define _CONFIG_BLEStop
            #ifdef _BAIC_COM_C52X 
             #define _CONFIG_BLEStop_Authorize
	     #define _CONFIG_BLEStop_Authorize_Combine
	    #endif 
	    //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	    #define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
  
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake 
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      #define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            #define _CONFIG_VehicleCrash_DisableMode 
	    #define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
            //#define _CONFIG_SlidePosition_SinglePosition
	    //#define _CONFIG_SlidePosition_MultPosition
	    //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	    //#define _CONFIG_SlidePosition_SlideOpen
	          //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		  //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	    //#define _CONFIG_SlidePosition_SlideClose
	          //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		  //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
            
      
      
      #define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
            #ifdef _BAIC_COM_C62X 
            #define _CONFIG_Odometer_ObstacleAdder
	    #endif
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 	    
       
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      #define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            #define _CONFIG_ModeStatus_GarageMode
            #define _CONFIG_ModeStatus_ManualMode          	   
      #define _CONFIG_KickSensorEnable
      #define _CONFIG_FlasherEnable
      #define _CONFIG_BuzzerEnable
      #define _CONFIG_AutoOpenEnable
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature
      #define _CONFIG_BusIncline
           #define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   #define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink 		 

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      //#define _CONFIG_SaveInitialData
#endif

#ifdef _DFLZM_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout	    
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize	    
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever  
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode  
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC   
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            #define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
            //#define _CONFIG_RemoteKey_ReleaseOnlyInReleased
      #define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      #define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
             //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock

      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine  
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      	     
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
	    //#define _CONFIG_AutoOpen_KeepClosing
            //#define _CONFIG_AutoOpen_KeepOpening
	    //#define _CONFIG_AutoOpen_Closing_Reverse
	    //#define _CONFIG_AutoOpen_Reverse_Warning
      //#define _CONFIG_AutoClose
            //#define _CONFIG_AutoClose_KeepOpening
            //#define _CONFIG_AutoClose_KeepClosing
	    //#define _CONFIG_AutoClose_Opening_Reverse
	    //#define _CONFIG_AutoClose_Reverse_Warning
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose 
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
     // #define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
     
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
  
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      #define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      //#define _CONFIG_VehicleGearLeverStop
            //#define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake 
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
            //#define _CONFIG_SlidePosition_SinglePosition
	    //#define _CONFIG_SlidePosition_MultPosition
	    //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	    //#define _CONFIG_SlidePosition_SlideOpen
	          //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		  //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	    //#define _CONFIG_SlidePosition_SlideClose
	          //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		  //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
            
      
      
      #define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
            //#define _CONFIG_Odometer_ObstacleAdder
      #define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 	    
       
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode          	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      #define _CONFIG_BusIncline
           #define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           #define _CONFIG_BusIncline_Valid
	   #define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   #define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
      //#define _CONFIG_SaveInitialData
#endif

#ifdef _NIU_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            #define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            #define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever  
            #define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode  
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      #define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    #define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock

      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine 
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     #define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
            //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	    //#define _CONFIG_GarageHeightRequest_InPowerOperation
	    //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake   
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	    
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      #define _CONFIG_EngineSpeed
      #define _CONFIG_Odometer 
      #define _CONFIG_TimeInformation
      
      //#define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    //#define _CONFIG_DoorStatus_RearGate
            //#define _CONFIG_DoorStatus_Closed_Default
      //#define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    //#define _CONFIG_WindowsPosition_RearGate
            //#define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      //#define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 	    
       
      #define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable
      #define _CONFIG_ObstcalAlarmEnable
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif

#ifdef _FAW_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      //#define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      //#define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    //#define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      //#define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      //#define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit
 
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock
      
      //#define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      //#define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine 
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      #define _CONFIG_VRStop
             #define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch  
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose
      
      //#define _CONFIG_RestoreRequest
      //#define _CONFIG_GarageHeightRequest
             //#define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	     //#define _CONFIG_GarageHeightRequest_InPowerOperation
	     //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      //#define _CONFIG_AntiFalseLock
      #define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake 
            //#define _CONFIG_VehicleBrake_Real
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	       
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    //#define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode   
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      
          
      
      
      //#define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      #define _CONFIG_SunRoofPosition
            #define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus
      
      //#define _CONFIG_VehicleTemperature
           //#define _CONFIG_BusTemperature
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode            	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable	
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink

      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif

#ifdef _CHANGAN_COM
      //#define _CONFIG_AppAuthorize
            //#define _CONFIG_AppAuthorize_Clear_InClosed
	    //#define _CONFIG_AppAuthorize_Clear_Timeout
       //#define _CONFIG_BLEAuthorize
            //#define _CONFIG_BLEAuthorize_Clear_InClosed
	    //#define _CONFIG_BLEAuthorize_Clear_Timeout
      //#define _CONFIG_FobAuthorize
            //#define _CONFIG_FobAuthorize_Clear_InClosed
	    //#define _CONFIG_FobAuthorize_Clear_Timeout
      //#define _CONFIG_AntiLockAuthorize
            //#define _CONFIG_AntiLockAuthorize_Clear_InClosed
	    //#define _CONFIG_AntiLockAuthorize_Clear_Timeout
      //#define _CONFIG_PKEAuthorize
            //#define _CONFIG_PKEAuthorize_Clear_InClosed
	    //#define _CONFIG_PKEAuthorize_Clear_Timeout
      
      #define _CONFIG_VehicleSpeed
            //#define _CONFIG_VehicleSpeed_Real
      #define _CONFIG_VehiclePowerMode
            //#define _CONFIG_VehiclePowerMode_Real
      #define _CONFIG_VehicleGearLever 
            //#define _CONFIG_VehicleGearLever_Real
      #define _CONFIG_VehicleLock
            //#define _CONFIG_VehicleLock_Real
      #define _CONFIG_VehicleAntiTheft
            //#define _CONFIG_VehicleAntiTheft_Real
            //#define _CONFIG_VehicleAntiTheft_CycleNoActive
      //#define _CONFIG_VehicleHandBrake
            //#define _CONFIG_VehicleHandBrake_Real
      //#define _CONFIG_VehicleChildLock
            //#define _CONFIG_VehicleChildLock_Real	    
      //#define _CONFIG_VehicleRemoteMode 
      
      //#define _CONFIG_VehicleDriveMode
             //#define _CONFIG_VehicleDriveMode_Real
      //#define _CONFIG_VehicleChargeState
      //#define _CONFIG_VehicleSOC
      //#define _CONFIG_VehicleVoltage
      //#define _CONFIG_VehicleMode
           //#define _CONFIG_VehicleMode_DisableMode
      
      //#define _CONFIG_TouchPad
            //#define _CONFIG_TouchPad_Authorize_FallEdge
	    //#define _CONFIG_TouchPad_Authorize_ShortPress
	    //#define _CONFIG_TouchPad_Authorize_PKE
	    //#define _CONFIG_TouchPad_Authorize_Combine
            //#define _CONFIG_TouchPad_ReleaseOnlyInReleased
	    //#define _CONFIG_TouchPad_OpenedFully_Disable
	    //#define _CONFIG_TouchPad_ReleaseGarage_Disable
	    //#define _CONFIG_TouchPad_Opening_Reverse
            //#define _CONFIG_TouchPad_Closing_Reverse
	    //#define _CONFIG_TouchPad_Open_Default
      #define _CONFIG_RemoteKey
            //#define _CONFIG_RemoteKey_Opening_Reverse
            //#define _CONFIG_RemoteKey_Closing_Reverse
      //#define _CONFIG_FobLongPress
            //#define _CONFIG_FobLongPress_Opening_Reverse
            //#define _CONFIG_FobLongPress_Closing_Reverse
            //#define _CONFIG_FobLongPress_ReleaseOnlyInReleased
      //#define _CONFIG_FobShortPress
            //#define _CONFIG_FobShortPress_Opening_Reverse
            //#define _CONFIG_FobShortPress_Closing_Reverse
            //#define _CONFIG_FobShortPress_PowerOpenWhileLatchCinch
      #define _CONFIG_KickSensor
            //#define _CONFIG_KickSensor_Authorize
	    //#define _CONFIG_KickSensor_Authorize_PKE
	    //#define _CONFIG_AppOpen_Authorize_Combine
	    #define _CONFIG_KickSensor_InOpen_DefaultClose
	    //#define _CONFIG_KickSensor_InOpen_Reversal
	    //#define _CONFIG_KickSensor_Opening_Reverse
            //#define _CONFIG_KickSensor_Closing_Reverse
      #define _CONFIG_PKETrunkButton
            //#define _CONFIG_PKETrunkButton_Opening_Reverse
            //#define _CONFIG_PKETrunkButton_Closing_Reverse
	    //#define _CONFIG_PKETrunkButton_Open_Default
      #define _CONFIG_VirtualButton
            //#define _CONFIG_VirtualButton_Opening_Reverse
            //#define _CONFIG_VirtualButton_Closing_Reverse
	    //#define _CONFIG_VirtualButton_ReleaseOnlyInReleased
      //#define _CONFIG_InsideButton
            //#define _CONFIG_InsideButton_ShortPress
            //#define _CONFIG_InsideButton_LongPress
	          
            //#define _CONFIG_InsideButton_Opening_Reverse
            //#define _CONFIG_InsideButton_Closing_Reverse		  
            //#define _CONFIG_InsideButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButton
            //#define _CONFIG_DriverButton_ShortPress
            //#define _CONFIG_DriverButton_LongPress
	          
            //#define _CONFIG_DriverButton_Opening_Reverse
            //#define _CONFIG_DriverButton_Closing_Reverse		  
            //#define _CONFIG_DriverButton_ReleaseOnlyInReleased
      //#define _CONFIG_DriverButtonStop 
            //#define _CONFIG_DriverButtonStop_Opening_Reverse
            //#define _CONFIG_DriverButtonStop_Closing_Reverse
      
      //#define _CONFIG_LatchReleaseState	    
      //#define _CONFIG_PawlSignal	 
      //#define _CONFIG_SecondarySignal	
      //#define _CONFIG_PositionSignal	
      //#define _CONFIG_CentralLockSignal
      //#define _CONFIG_ChildLockSignal
      //#define _CONFIG_LatchSignal
      //#define _CONFIG_LatchSignal_Transmit	    
      	    
      //#define _CONFIG_DelayClose
      //#define _CONFIG_ManualRelease	
      //#define _CONFIG_ComfortClose
      //#define _CONFIG_RemindStart
      //#define _CONFIG_RemindStop          
      //#define _CONFIG_CommandDelay_Cancel
            //#define _CONFIG_CommandDelay_Cancel_ByFobLock	    
      
      #define _CONFIG_AppOpen
             //#define _CONFIG_AppOpen_Authorize
	     //#define _CONFIG_AppOpen_Authorize_Combine
             //#define _CONFIG_AppOpen_KeepOpening
	     //#define _CONFIG_AppOpen_Closing_Reverse
	     //#define _CONFIG_AppOpen_Reverse_Warning
	     //#define _CONFIG_AppOpen_ReleaseOnlyInReleased
      #define _CONFIG_AppClose
             //#define _CONFIG_AppClose_Authorize
	     //#define _CONFIG_AppClose_Authorize_Combine
             //#define _CONFIG_AppClose_KeepClosing
	     //#define _CONFIG_AppClose_Opening_Reverse
	     //#define _CONFIG_AppClose_Reverse_Warning
      //#define _CONFIG_AppStop
             //#define _CONFIG_AppStop_Authorize
	     //#define _CONFIG_AppStop_Authorize_Combine 
	     //#define _CONFIG_AppStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_AppStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_AppStepOpen
      //#define _CONFIG_AppStepClose
      
      #define _CONFIG_VROpen
             //#define _CONFIG_VROpen_KeepOpening
	     //#define _CONFIG_VROpen_Closing_Reverse
	     //#define _CONFIG_VROpen_Reverse_Warning
	     //#define _CONFIG_VROpen_ReleaseOnlyInReleased
      #define _CONFIG_VRClose
             //#define _CONFIG_VRClose_KeepClosing
	     //#define _CONFIG_VRClose_Opening_Reverse
	     //#define _CONFIG_VRClose_Reverse_Warning
      //#define _CONFIG_VRStop     
             //#define _CONFIG_VRStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VRStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_VRStepOpen
      //#define _CONFIG_VRStepClose
      
      //#define _CONFIG_AutoOpen
      //#define _CONFIG_AutoClose
      //#define _CONFIG_AutoStop
      //#define _CONFIG_AutoStepOpen
      //#define _CONFIG_AutoStepClose    
      
      //#define _CONFIG_VoiceOpen
             //#define _CONFIG_VoiceOpen_KeepOpening
	     //#define _CONFIG_VoiceOpen_Closing_Reverse
	     //#define _CONFIG_VoiceOpen_Reverse_Warning
	     //#define _CONFIG_VoiceOpen_ReleaseOnlyInReleased
      //#define _CONFIG_VoiceClose
             //#define _CONFIG_VoiceClose_KeepClosing
	     //#define _CONFIG_VoiceClose_Opening_Reverse
	     //#define _CONFIG_VoiceClose_Reverse_Warning
      //#define _CONFIG_VoiceStop
             //#define _CONFIG_VoiceStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_VoiceStop_ReleaseOnlyDuringPowerCinch
      
      //#define _CONFIG_BLEOpen
             //#define _CONFIG_BLEOpen_Authorize
	     //#define _CONFIG_BLEOpen_Authorize_Combine
             //#define _CONFIG_BLEOpen_KeepOpening
	     //#define _CONFIG_BLEOpen_Closing_Reverse
	     //#define _CONFIG_BLEOpen_Reverse_Warning
	     //#define _CONFIG_BLEOpen_ReleaseOnlyInReleased
      //#define _CONFIG_BLEClose
             //#define _CONFIG_BLEClose_Authorize
	     //#define _CONFIG_BLEClose_Authorize_Combine
             //#define _CONFIG_BLEClose_KeepClosing
	     //#define _CONFIG_BLEClose_Opening_Reverse
	     //#define _CONFIG_BLEClose_Reverse_Warning
      //#define _CONFIG_BLEStop
             //#define _CONFIG_BLEStop_Authorize
	     //#define _CONFIG_BLEStop_Authorize_Combine
	     //#define _CONFIG_BLEStop_PowerOpenDuringPowerCinch
	     //#define _CONFIG_BLEStop_ReleaseOnlyDuringPowerCinch
      //#define _CONFIG_BLEStepOpen
      //#define _CONFIG_BLEStepClose
      
      //#define _CONFIG_RKEOpen
      //#define _CONFIG_RKEClose     
      //#define _CONFIG_RKEStopOpen
      //#define _CONFIG_RKEStopClose     
      //#define _CONFIG_RKEStepOpen
      //#define _CONFIG_RKEStepClose     
      
      //#define _CONFIG_RestoreRequest
      #define _CONFIG_GarageHeightRequest
           #define _CONFIG_GarageHeightRequest_Buzzer_Flasher
	   //#define _CONFIG_GarageHeightRequest_InPowerOperation
	   //#define _CONFIG_GarageHeightRequest_SpindleModeChange

      //#define _CONFIG_AntiFalseLock
      //#define _CONFIG_VehicleSpeedLearn
      //#define _CONFIG_VehicleSpeedHigh_DefautClose
      
      #define _CONFIG_VehicleSpeedStop
            #define _CONFIG_VehicleSpeedStop_InOpening
	    //#define _CONFIG_VehicleSpeedStop_InClosing
            //#define _CONFIG_VehicleSpeedStop_StartClose
	    //#define _CONFIG_VehicleSpeedStop_HighSpeedWarningInOpen
      #define _CONFIG_VehicleGearLeverStop
            #define _CONFIG_VehicleGearLeverStop_InOpening
	    //#define _CONFIG_VehicleGearLeverStop_InClosing
      //#define _CONFIG_VehicleDriveModeStop
            //#define _CONFIG_VehicleDriveModeStop_InOpening
	    //#define _CONFIG_VehicleDriveModeStop_InClosing
      
      //#define _CONFIG_VehicleBrake  
            //#define _CONFIG_VehicleBrake_ShortPress
            //#define _CONFIG_VehicleBrake_LongPress
                   //#define _CONFIG_VehicleBrake_LongPress_NewBreakAfterStop
	         
      //#define _CONFIG_SonicRadar
           //#define _CONFIG_SonicRadar_Real
           //#define _CONFIG_SonicRadar_Obstacle
	   //#define _CONFIG_SonicRadar_Data
                 //#define _CONFIG_SonicRadar1_Distance
                 //#define _CONFIG_SonicRadar2_Distance
		 //#define _CONFIG_SonicRadar_DeadZone
	         //#define _CONFIG_SonicRadar_PauseOpen
	               //#define _CONFIG_SonicRadar_PauseOpen_ContinueTimes
	         
		 //#define _CONFIG_SonicRadar_Debounce
      //#define _CONFIG_VehicleCrash 
            //#define _CONFIG_VehicleCrash_Real
            //#define _CONFIG_VehicleCrash_DisableMode 
	    //#define _CONFIG_VehicleCrash_Recovery_PowerModeOfftoOn
	    #define _CONFIG_VehicleCrash_Recovery_Timeout
      
      //#define _CONFIG_Vehicle_KeyMode
          //#define _CONFIG_KeyOpenMode
          //#define _CONFIG_KeyCloseMode    
      
      //#define _CONFIG_MusicControl
      //#define _CONFIG_SlidePosition
          //#define _CONFIG_SlidePosition_SinglePosition
	  //#define _CONFIG_SlidePosition_MultPosition
	  //#define _CONFIG_SlidePosition_MultPosition_BackToDefaultValue
	  //#define _CONFIG_SlidePosition_SlideOpen
	         //#define _CONFIG_SlidePosition_SlideOpen_KeepOpening
		 //#define _CONFIG_SlidePosition_SlideOpen_Closing_Reverse
	  //#define _CONFIG_SlidePosition_SlideClose
	         //#define _CONFIG_SlidePosition_SlideClose_KeepClosing
		 //#define _CONFIG_SlidePosition_SlideClose_Opening_Reverse
      

      //define _CONFIG_EngineSpeed
      //#define _CONFIG_Odometer
      //#define _CONFIG_TimeInformation
      
      #define _CONFIG_DoorStatus
            //#define _CONFIG_DoorStatus_TrunkDoor
	    //#define _CONFIG_DoorStatus_SideDoor
	    #define _CONFIG_DoorStatus_RearGate
            #define _CONFIG_DoorStatus_Closed_Default
      #define _CONFIG_WindowsPosition
            //#define _CONFIG_WindowsPosition_SideDoor
	    #define _CONFIG_WindowsPosition_RearGate
            #define _CONFIG_WindowsPosition_Closed_Default     
      //#define _CONFIG_SunRoofPosition
            //#define _CONFIG_SunRoofPosition_Closed_Default
      #define _CONFIG_BlowerSpeed	    
      //#define _CONFIG_RearWiperStatus 
      
      #define _CONFIG_VehicleTemperature
           #define _CONFIG_BusTemperature
	   //#define _CONFIG_BusTemperature_PowerModeOFF_Invalid
      
      //#define _CONFIG_FunctionEnable_KeepAfterWakeup 
      //#define _CONFIG_ModeStatus
            //#define _CONFIG_ModeStatus_NormalMode
            //#define _CONFIG_ModeStatus_GarageMode
            //#define _CONFIG_ModeStatus_ManualMode           	   
      //#define _CONFIG_KickSensorEnable
      //#define _CONFIG_FlasherEnable
      //#define _CONFIG_BuzzerEnable
      //#define _CONFIG_AutoOpenEnable		   
      
      //#define _CONFIG_BusIncline
           //#define _CONFIG_BusIncline_Only
	   //#define _CONFIG_BusIncline_BoardIncline_Together
           //#define _CONFIG_BusIncline_Valid
	   //#define _CONFIG_BusIncline_HistoryValueWhilePark
	   //#define _CONFIG_BusIncline_HistoryValueWhileClosed
	   //#define _CONFIG_BusIncline_KeepAfterWakeup	   
           //#define _CONFIG_BusIncline_ChipXYZ
	         //#define _CONFIG_BusIncline_ChipXYZ_WitLink
      
      //#define _CONFIG_OpenSpeedLevel
      //#define _CONFIG_CloseSpeedLevel
#endif


#ifdef _DFLZM_COM
/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x1U
#define _ODOMETER_VALID         0x0U

/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x1U
#define _SPEED_VALID         0x0U

/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x1U
#define _ENGINE_VALID         0x0U

/*TimeInformation_Valid*/
#define _TIME_INVALID       0x1U
#define _TIME_VALID         0x0U

/*Incline_Valid*/
#define _Incline_Invalid     0x1U
#define _Incline_Valid       0x0U

/*OutdT*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_70       0xDCU
#define _BUS_TEMPERATURE_80       0xF0U

/* AC1_Status_BlowerSpeed_Lvl   */
#define _AC1_Status_BlowerSpeed_Lvl_OFF_No_wind 0x0U
#define _AC1_Status_BlowerSpeed_Lvl_Level_1     0x1U
#define _AC1_Status_BlowerSpeed_Lvl_Level_2     0x2U
#define _AC1_Status_BlowerSpeed_Lvl_Level_3     0x3U
#define _AC1_Status_BlowerSpeed_Lvl_Level_4     0x4U
#define _AC1_Status_BlowerSpeed_Lvl_Level_5     0x5U
#define _AC1_Status_BlowerSpeed_Lvl_Level_6     0x6U
#define _AC1_Status_BlowerSpeed_Lvl_Level_7     0x7U
#define _AC1_Status_BlowerSpeed_Lvl_Level_8     0x8U

/* AC2_Fdbk_RearACBlwrSpd_Lvl*/
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Invalid                       0x0U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_OFF_No_wind                   0x1U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Level_1_Min_blower_speed      0x2U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Level_2                       0x3U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Level_3                       0x4U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Level_4                       0x5U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Level_5                       0x6U
#define _AC2_Fdbk_RearACBlwrSpd_Lvl_Reserved                      0x7U

/* BCM_DriverDoorSt*/
/* BCM_PassDoorSt*/
/* BCM_RLDoorSt*/
/* BCM_RRDoorSt*/
#define _BCM_DoorSt_Closed    0x0U
#define _BCM_DoorSt_Open      0x1U

/* LDCM1_Status_WinPostion_FL*/
/* LDCM1_Status_WinPostion_RL*/
/* RDCM1_Status_WinPostion_FR*/
/* RDCM1_Status_WinPostion_RR*/
#define _DCM1_Status_WinPostion_0_Percent    0x0U
#define _DCM1_Status_WinPostion_10_Percent   0x1U
#define _DCM1_Status_WinPostion_20_Percent   0x2U


/* BCM1_Status_AntiThief*/
#define _BCM1_Status_AntiThief_DisArmed         0x0U
#define _BCM1_Status_AntiThief_Reserved0        0x1U
#define _BCM1_Status_AntiThief_Armed            0x2U
#define _BCM1_Status_AntiThief_Alarm            0x3U
#define _BCM1_Status_AntiThief_Reserved1        0x4U
#define _BCM1_Status_AntiThief_Partially Armed  0x5U

/* BCM1_Status_DriverSW_BackDoor */
#define _BCM1_Status_DriverSW_BackDoor_OFF      0x0U
#define _BCM1_Status_DriverSW_BackDoor_ON       0x1U

/* BCM3_Status_SrPos */
#define _BCM3_Status_SrPos_Invalid                          0x0U
#define _BCM3_Status_SrPos_Tilt_up                          0x1U
#define _BCM3_Status_SrPos_Vent_area                        0x2U
#define _BCM3_Status_SrPos_Antipinch_in_vent                0x3U
#define _BCM3_Status_SrPos_Fully_close                      0x4U
#define _BCM3_Status_SrPos_Antipinch_in_partially_slide     0x5U 
#define _BCM3_Status_SrPos_Partially_slide                  0x6U
#define _BCM3_Status_SrPos_Fully_open                       0x7U

/* ICE1_Set_PLGOpen_Lvl*/
#define _ICE1_Set_PLGOpen_Lvl_Invalid     0x0U
#define _ICE1_Set_PLGOpen_Lvl_Level_1     0x1U
#define _ICE1_Set_PLGOpen_Lvl_Level_2     0x2U
#define _ICE1_Set_PLGOpen_Lvl_Level_3     0x3U
#define _ICE1_Set_PLGOpen_Lvl_Level_4     0x4U
#define _ICE1_Set_PLGOpen_Lvl_Level_5     0x5U

/* ICE22_Set_PLG_OnOff */
#define _ICE22_Set_PLG_OnOff_Invalid      0x0U
#define _ICE22_Set_PLG_OnOff_PLG_Off      0x1U
#define _ICE22_Set_PLG_OnOff_PLG_On       0x2U
#define _ICE22_Set_PLG_OnOff_Reserved     0x3U

/* PEPS_Ign_Key_POS*/
#define _PEPS_Ign_Key_POS_Lock      0x0U
#define _PEPS_Ign_Key_POS_ACC       0x1U
#define _PEPS_Ign_Key_POS_ON        0x2U
#define _PEPS_Ign_Key_POS_Start     0x3U

/* Luggage_Door_Lock_Cmd */
#define _Luggage_Door_Lock_Cmd_Inactive   0x0U
#define _Luggage_Door_Lock_Cmd_Active     0x1U

/* PEPS1_Statue_BackHandleSW */
#define _PEPS1_Statue_BackHandleSW_OFF    0x0U
#define _PEPS1_Statue_BackHandleSW_On     0x1U

/* PEPS1_Statue_RKE_BackDoorKey */
#define _PEPS1_Statue_RKE_BackDoorKey_Unpress         0x0U
#define _PEPS1_Statue_RKE_BackDoorKey_Short_Press     0x1U
#define _PEPS1_Statue_RKE_BackDoorKey_Long_Press      0x2U
#define _PEPS1_Statue_RKE_BackDoorKey_Reserved        0x3U

/* PEPS2_Status_KS_ActvInactv */
#define _PEPS2_Status_KS_ActvInactv_Inactive          0x0U 
#define _PEPS2_Status_KS_ActvInactv_Active            0x1U

/* SBM1_CMD_LuggageDoor */
#define _SBM1_CMD_LuggageDoor_Invalid     0x0U
#define _SBM1_CMD_LuggageDoor_Switch_On   0x1U
#define _SBM1_CMD_LuggageDoor_Switch_Off  0x2U

/* ECU4_IND_ECUStatus */
#define _ECU4_IND_ECUStatus_Engine_stop_not_running   0x0U
#define _ECU4_IND_ECUStatus_Cranking                  0x1U
#define _ECU4_IND_ECUStatus_Reserved                  0x2U
#define _ECU4_IND_ECUStatus_Eninge_running            0x3U
#define _ECU4_IND_ECUStatus_Fault_detected            0x7U


/* TX*/
/* PLG1_RQ_HazardRemind_Mode */
#define _PLG1_RQ_HazardRemind_Mode_Off                      0x0U
#define _PLG1_RQ_HazardRemind_Mode_Anti_pinch_reverse       0x1U  
#define _PLG1_RQ_HazardRemind_Mode_Forced_stop              0x2U
#define _PLG1_RQ_HazardRemind_Mode_Warning                  0x3U
#define _PLG1_RQ_HazardRemind_Mode_Memory_position          0x4U
#define _PLG1_RQ_HazardRemind_Mode_User_Operation_Accepted  0x5U
#define _PLG1_RQ_HazardRemind_Mode_User_Operation_Denied    0x6U

 /* PLG1_Status_CurrentState_Mode */
#define _PLG1_Status_CurrentState_Mode_Initializing   0x0U
#define _PLG1_Status_CurrentState_Mode_Normal         0x1U
#define _PLG1_Status_CurrentState_Mode_Abnormality    0x2U
#define _PLG1_Status_CurrentState_Mode_Invalid        0x3U  

/* PLG1_Fdbk_PLGSystemMotion */
#define _PLG1_Fdbk_PLGSystemMotion_Invalid            0x0U
#define _PLG1_Fdbk_PLGSystemMotion_Full_Close         0x1U
#define _PLG1_Fdbk_PLGSystemMotion_Full_Open          0x2U
#define _PLG1_Fdbk_PLGSystemMotion_Opening            0x3U
#define _PLG1_Fdbk_PLGSystemMotion_Closing            0x4U
#define _PLG1_Fdbk_PLGSystemMotion_Stopped            0x5U

/* PLG1_Status_PLGLearing */
#define _PLG1_Status_PLGLearing_Unlearn   0x0U
#define _PLG1_Status_PLGLearing_Learned   0x1U

/* PLG1_Fdbk_PLGOpen_Lvl  */
#define _PLG1_Fdbk_PLGOpen_Lvl_Invalid    0x0U
#define _PLG1_Fdbk_PLGOpen_Lvl_Level_1    0x1U
#define _PLG1_Fdbk_PLGOpen_Lvl_Level_2    0x2U
#define _PLG1_Fdbk_PLGOpen_Lvl_Level_3    0x3U
#define _PLG1_Fdbk_PLGOpen_Lvl_Level_4    0x4U
#define _PLG1_Fdbk_PLGOpen_Lvl_Level_5    0x5U

/* PLG1_Status_Secondary_Pos  */
#define _PLG1_Status_Secondary_Pos_Inactive     0x0U
#define _PLG1_Status_Secondary_Pos_Active       0x1U

/* PLG1_Status_LatchReset  */
#define _PLG1_Status_LatchReset_Inactive        0x0U
#define _PLG1_Status_LatchReset_Active          0x1U

/* PLG1_Status_LatchPawl */
#define _PLG1_Status_LatchPawl_Inactive         0x0U
#define _PLG1_Status_LatchPawl_Active           0x1U

/* PLG1_Status_MotorStall */
#define _PLG1_Status_MotorStall_Normal               0x0U
#define _PLG1_Status_MotorStall_Anti_pinch_Event     0x1U

/* PLG1_Status_BackDoorMicSW */
#define _PLG1_Status_BackDoorMicSW_Inactive     0x0U
#define _PLG1_Status_BackDoorMicSW_Active       0x1U

/* PLG1_Status_PLGClosingSW */
#define _PLG1_Status_PLGClosingSW_Inavtice      0x0U
#define _PLG1_Status_PLGClosingSW_Active        0x1U

/* PLG1_Status_DriverSideSW */
#define _PLG1_Status_DriverSideSW_Inactive      0x0U
#define _PLG1_Status_DriverSideSW_Active        0x1U

#endif

#ifdef _BAIC_COM
/*C52X*/
/*TcuActGear */
#define _TcuActGear_Initial    0x0U
#define _TcuActGear_P          0x1U
#define _TcuActGear_R          0x2U
#define _TcuActGear_N          0x3U
#define _TcuActGear_1st        0xBU
#define _TcuActGear_2nd        0xCU
#define _TcuActGear_3rd        0xDU
#define _TcuActGear_4th        0xEU
#define _TcuActGear_5th        0xFU
#define _TcuActGear_6th        0x10U
#define _TcuActGear_7th        0x11U

/*TcuActGearVld */
#define _TcuActGearVld_Initialing    0x0U
#define _TcuActGearVld_Valid         0x1U
#define _TcuActGearVld_Invalid       0x2U

/*EngStrtd */
#define _EngStrtd_Engine_not_started    0x0U
#define _EngStrtd_Engine_started        0x1U

/*RestDoorLockStsSwt */
#define _RestDoorLockStsSwt_initialing    0x0U
#define _RestDoorLockStsSwt_Locked        0x1U
#define _RestDoorLockStsSwt_Unlocked      0x2U
#define _RestDoorLockStsSwt_Invalid       0x3U

/*EngRunng*/
#define _EngRunng_Engine_NOT_running    0x0U
#define _EngRunng_Cranking              0x1U
#define _EngRunng_Engine_running        0x2U
#define _EngRunng_Fault                 0x3U

/*RemKeyFctForLock*/
#define _RemKeyFctForLock_Inactive            0x0U
#define _RemKeyFctForLock_Lock_all_doors      0x1U
#define _RemKeyFctForLock_Unlock_driver_door  0x2U
#define _RemKeyFctForLock_Unlock_all_doors    0x3U
#define _RemKeyFctForLock_TailgateRelease     0x4U

/*DlyClsModEnaSts*/
#define _DlyClsModEnaSts_initialing   0x0U
#define _DlyClsModEnaSts_Unabled      0x1U
#define _DlyClsModEnaSts_Enabled      0x2U
#define _DlyClsModEnaSts_Invalid      0x3U

/*DlyClsMod*/
#define _DlyClsMod_initialing        0x0U
#define _DlyClsMod_Normal            0x1U
#define _DlyClsMod_Delay_Close_Mod   0x2U
#define _DlyClsMod_Invalid           0x3U

/*KeyFctCmdCod*/
#define _KeyFctCmdCod_Inactive               0x0U
#define _KeyFctCmdCod_wake_up_the_vehicle    0x1U
#define _KeyFctCmdCod_welcome_light_on       0x2U
#define _KeyFctCmdCod_Unlock_all_doors       0x3U
#define _KeyFctCmdCod_lock_all_doors         0x4U
#define _KeyFctCmdCod_Easy_trunk_light_on    0x5U
#define _KeyFctCmdCod_TailgateRelease        0x6U
#define _KeyFctCmdCod_Tailgatelock           0x7U
#define _KeyFctCmdCod_Unlock_driver_door     0x8U

/*DoorHndlSnsrCmd*/
#define _DoorHndlSnsrCmd_initialing        0x0U
#define _DoorHndlSnsrCmd_DrvLock           0x1U
#define _DoorHndlSnsrCmd_DrvUnlock         0x2U
#define _DoorHndlSnsrCmd_PassLock          0x3U
#define _DoorHndlSnsrCmd_PassUnlock        0x4U
#define _DoorHndlSnsrCmd_RLLock            0x5U
#define _DoorHndlSnsrCmd_RLUnlock          0x6U
#define _DoorHndlSnsrCmd_RRLock            0x7U
#define _DoorHndlSnsrCmd_RRUnlock          0x8U
#define _DoorHndlSnsrCmd_TailgateRelease   0x9U
#define _DoorHndlSnsrCmd_TailgateLock      0xaU

/*DHS_CMD*/
#define _DHS_CMD_initial           0x0U
#define _DHS_CMD_DrvLock           0x1U
#define _DHS_CMD_DrvUnlock         0x2U
#define _DHS_CMD_PassLock          0x3U
#define _DHS_CMD_PassUnlock        0x4U
#define _DHS_CMD_RLLock            0x5U
#define _DHS_CMD_RLUnlock          0x6U
#define _DHS_CMD_RRLock            0x7U
#define _DHS_CMD_RRUnlock          0x8U
#define _DHS_CMD_TailgateRelease   0x9U
#define _DHS_CMD_TailgateLock      0xaU


/*LgtSnsrSts*/
/*LgtSnsrSts*/
#if defined(_BAIC_COM_C52X) || defined(_BAIC_COM_C62X)
#define _LgtSnsrSts_Initializing    0x0U
#define _LgtSnsrSts_Valid           0x1U
#define _LgtSnsrSts_Invalid         0x2U
#define _Incline_Valid              0x0U
#endif

#ifdef _BAIC_COM_C46DB
#define _LgtSnsrSts_Initializing    0x0U
#define _LgtSnsrSts_Valid           0x1U
#define _LgtSnsrSts_Invalid         0x2U
#define _Incline_Valid              0x1U
#endif


/*TmPtmOperCmd*/
#define _TmPtmOperCmd_Inactive      0x0U
#define _TmPtmOperCmd_Open          0x1U
#define _TmPtmOperCmd_close         0x2U
#define _TmPtmOperCmd_stop          0x3U

/*SmtEntryFctCmd*/
#define _SmtEntryFctCmd_Inactive            0x0U
#define _SmtEntryFctCmd_lock_all_doors      0x4U
#define _SmtEntryFctCmd_TailgateRelease     0x6U
#define _SmtEntryFctCmd_initialing          0x7U
#define _SmtEntryFctCmd_invalid             0x8U


/*RemCtrlMod*/
#define _RemCtrlMod_In_Nor_Mode                 0x0U
#define _RemCtrlMod_In_RES_Mode                 0x1U
#define _RemCtrlMod_In_RLC_Mode                 0x2U
#define _RemCtrlMod_In_Bluetooth_Control_Mode   0x3U
#define _RemCtrlMod_In_Bluetooth_Start_Mode     0x4U
#define _RemCtrlMod_In_Auto_electricity_Mode    0x5U
#define _RemCtrlMod_In_RPA_Mode                 0x6U


/*AirbDeploymtSts*/
#define _AirbDeploymtSts_No_Crash                            0x0U
#define _AirbDeploymtSts_Front_Belt_tensioner_deployment     0x1U
#define _AirbDeploymtSts_Front_Airbag_deployment             0x2U
 

/*WinPosn_FR*/
/*WinPosn_RR*/
/*WinPosn_FL*/
/*WinPosn_RL*/
#define _WinPosn_0_Percent            0x0U
#define _WinPosn_10_Percent           0x14U
#define _WinPosn_100_Percent          0xC8U

/*BDCRptSunRPosn*/
#define _BDCRptSunRPosn_Tilt_up          0x0U
#define _BDCRptSunRPosn_10_Pecent        0xAU
#define _BDCRptSunRPosn_Fully_open       0x64U
#define _BDCRptSunRPosn_Fully_close      0x65U
#define _BDCRptSunRPosn_Vent_area        0x66U

    #ifdef _BAIC_COM_C52X
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x2U
#define _SPEED_VALID         0x1U

/*PwrMod*/
#define _PwrMod_OFF       0x0U
#define _PwrMod_ACC       0x1U
#define _PwrMod_IGN_ON    0x2U
#define _PwrMod_CRANK     0x3U

/*PwrModVld*/
#define _PwrModVld_Invaild     0x1U
#define _PwrModVld_Vaild       0x2U

/*DrvrDoorOpenStsSwt*/
/*PassDoorOpenStsSwt*/
/*ReLeDoorOpenStsSwt*/
/*ReRiDoorOpenStsSwt*/
#define _DoorSts_initialing    0x0U
#define _DoorSts_Closed        0x1U
#define _DoorSts_Open          0x2U
#define _DoorSts_Invalid       0x3U
#define _DoorSts_Reserved      0x0U

/*DrvrDoorLockStsSwt */
/*PassDoorLockStsSwt*/
/*ReLeDoorLockStsSwt*/
/*ReRiDoorLockStsSwt*/
#define _DrvrDoorLockStsSwt_initialing    0x0U
#define _DrvrDoorLockStsSwt_Locked        0x1U
#define _DrvrDoorLockStsSwt_Unlocked      0x2U
#define _DrvrDoorLockStsSwt_Invalid       0x3U

/*TrIntSwt */
#define _TrIntSwt_initialing    0x0U
#define _TrIntSwt_Not_active    0x1U
#define _TrIntSwt_Active        0x2U
#define _TrIntSwt_Invalid       0x3U

/*TrExtSwt */
#define _TrExtSwt_initialing    0x0U
#define _TrExtSwt_Not_active    0x1U
#define _TrExtSwt_Active        0x2U
#define _TrExtSwt_Invalid       0x3U

/*AcBlowrLelDisp*/
#define _AcBlowrLelDisp_Initializing    0x0U
#define _AcBlowrLelDisp_Level_0         0x1U
#define _AcBlowrLelDisp_Level_1         0x2U
#define _AcBlowrLelDisp_Level_2         0x3U
#define _AcBlowrLelDisp_Level_3         0x4U
#define _AcBlowrLelDisp_Level_4         0x5U
#define _AcBlowrLelDisp_Level_5         0x6U
#define _AcBlowrLelDisp_Level_6         0x7U
#define _AcBlowrLelDisp_Level_7         0x8U
#define _AcBlowrLelDisp_Level_8         0x9U

/*AcRecircDisp*/
#define _AcRecircDisp_Initializing          0x0U
#define _AcRecircDisp_Not_display           0x1U
#define _AcRecircDisp_Display_Fresh_Air     0x2U
#define _AcRecircDisp_Display_Recirculation 0x3U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*RemAuthentRes*/
#define _RemAuthentRes_initialing                     0x0U
#define _RemAuthentRes_No_anthentication_or_failure   0x1U
#define _RemAuthentRes_IAnthentication_success        0x2U
#define _RemAuthentRes_Invalid                        0x3U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PtmOperSwt*/
#define _PtmOperSwt_Inactive    0x0U
#define _PtmOperSwt_ON          0x1U
#define _PtmOperSwt_Open        0x2U
#define _PtmOperSwt_Close       0x3U
#define _PtmOperSwt_Stop        0x4U
#define _PtmOperSwt_Invalid     0x7U
#define _PtmOperSwt_Active      0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x2U
#define _ODOMETER_VALID         0x1U
    #endif

    #ifdef _BAIC_COM_C62X
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x2U
#define _SPEED_VALID         0x0U

/*DR_DOOR_OPEN*/
/*PA_DOOR_OPEN*/
/*REAR_LEFT_DOOR_OPEN*/
/*REAR_RIGHT_DOOR_OPEN*/
#define _DoorSts_Closed        0x0U
#define _DoorSts_Open          0x1U

/*DOOR_UNLOCKED_DRIVER */
#define _DrvrDoorLockStsSwt_Locked        0x0U
#define _DrvrDoorLockStsSwt_Unlocked      0x1U

/*TRUNK_RELEASE_SWITCH_STATUS */
#define _TrIntSwt_Not_active    0x0U
#define _TrIntSwt_Active        0x1U

/*TRUNK_SWTICH_REQUEST */
#define _TrExtSwt_Not_active    0x0U
#define _TrExtSwt_Active        0x1U

/*AC_Dis_BlowerLevel */
#define _AcBlowrLelDisp_Level_0         0x0U
#define _AcBlowrLelDisp_Level_1         0x1U
#define _AcBlowrLelDisp_Level_2         0x2U
#define _AcBlowrLelDisp_Level_3         0x3U
#define _AcBlowrLelDisp_Level_4         0x4U
#define _AcBlowrLelDisp_Level_5         0x5U
#define _AcBlowrLelDisp_Level_6         0x6U
#define _AcBlowrLelDisp_Level_7         0x7U
#define _AcBlowrLelDisp_Level_8         0x8U

/*AC_Dis_FreshRecir*/
#define _AcRecircDisp_Not_display           0x0U
#define _AcRecircDisp_Display_Fresh_Air     0x1U
#define _AcRecircDisp_Display_Recirculation 0x2U

/*VALID_OTEMP*/
#define _OutdTVld_Valid                       0x0U
#define _OutdTVld_Value_below_lower_limit     0x1U

/*PwrModVld*/
#define _PwrModVld_Invaild     0x1U
#define _PwrModVld_Vaild       0x2U

/*POWER_MODE_PEPS */
#define _PwrMod_OFF       0x0U
#define _PwrMod_ACC       0x1U
#define _PwrMod_IGN_ON    0x2U
#define _PwrMod_CRANK     0x4U

/*REMOTE_AUTHENTICATION_RESULT*/
#define _RemAuthentRes_No_anthentication_or_failure   0x0U
#define _RemAuthentRes_IAnthentication_success        0x1U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_Inactive       0x0U
#define _AntiThiefIndcr_active         0x1U
#define _AntiThiefIndcr_alarm          0x2U
#define _AntiThiefIndcr_Invalid        0x3U

/*PtmOperSwt*/
#define _PtmOperSwt_Inactive    0x0U
#define _PtmOperSwt_ON          0x1U
#define _PtmOperSwt_OFF         0x2U
#define _PtmOperSwt_Stop        0x3U
#define _PtmOperSwt_Invalid     0x7U
#define _PtmOperSwt_Active      0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x1U
#define _ODOMETER_VALID         0x0U
   #endif

   #ifdef _BAIC_COM_C46DB
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x2U
#define _SPEED_VALID         0x1U

/*PwrMod*/
#define _PwrMod_OFF       0x0U
#define _PwrMod_ACC       0x1U
#define _PwrMod_IGN_ON    0x2U
#define _PwrMod_CRANK     0x3U

/*PwrModVld*/
#define _PwrModVld_Invaild     0x1U
#define _PwrModVld_Vaild       0x2U

/*DrvrDoorOpenStsSwt*/
/*PassDoorOpenStsSwt*/
/*ReLeDoorOpenStsSwt*/
/*ReRiDoorOpenStsSwt*/
#define _DoorSts_initialing    0x0U
#define _DoorSts_Closed        0x1U
#define _DoorSts_Open          0x2U
#define _DoorSts_Invalid       0x3U
#define _DoorSts_Reserved      0x0U

/*DrvrDoorLockStsSwt */
/*PassDoorLockStsSwt*/
/*ReLeDoorLockStsSwt*/
/*ReRiDoorLockStsSwt*/
#define _DrvrDoorLockStsSwt_initialing    0x0U
#define _DrvrDoorLockStsSwt_Locked        0x1U
#define _DrvrDoorLockStsSwt_Unlocked      0x2U
#define _DrvrDoorLockStsSwt_Invalid       0x3U

/*TrIntSwt */
#define _TrIntSwt_initialing    0x0U
#define _TrIntSwt_Not_active    0x1U
#define _TrIntSwt_Active        0x2U
#define _TrIntSwt_Invalid       0x3U

/*TrExtSwt */
#define _TrExtSwt_initialing    0x0U
#define _TrExtSwt_Not_active    0x1U
#define _TrExtSwt_Active        0x2U
#define _TrExtSwt_Invalid       0x3U

/*AcBlowrLelDisp*/
#define _AcBlowrLelDisp_Initializing    0x0U
#define _AcBlowrLelDisp_Level_0         0x1U
#define _AcBlowrLelDisp_Level_1         0x2U
#define _AcBlowrLelDisp_Level_2         0x3U
#define _AcBlowrLelDisp_Level_3         0x4U
#define _AcBlowrLelDisp_Level_4         0x5U
#define _AcBlowrLelDisp_Level_5         0x6U
#define _AcBlowrLelDisp_Level_6         0x7U
#define _AcBlowrLelDisp_Level_7         0x8U
#define _AcBlowrLelDisp_Level_8         0x9U

/*AcRecircDisp*/
#define _AcRecircDisp_Initializing          0x0U
#define _AcRecircDisp_Not_display           0x1U
#define _AcRecircDisp_Display_Fresh_Air     0x2U
#define _AcRecircDisp_Display_Recirculation 0x3U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*RemAuthentRes*/
#define _RemAuthentRes_initialing                     0x0U
#define _RemAuthentRes_No_anthentication_or_failure   0x1U
#define _RemAuthentRes_IAnthentication_success        0x2U
#define _RemAuthentRes_Invalid                        0x3U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PtmOperSwt*/
#define _PtmOperSwt_Inactive    0x0U
#define _PtmOperSwt_ON          0x1U
#define _PtmOperSwt_Open        0x2U
#define _PtmOperSwt_Close       0x3U
#define _PtmOperSwt_Stop        0x4U
#define _PtmOperSwt_Invalid     0x7U
#define _PtmOperSwt_Active      0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x2U
#define _ODOMETER_VALID         0x1U 

/*VCU_230_STRATEGY_SHIFT_POSITION*/
#define _VCU_230_STRATEGY_SHIFT_POSITION_Void    0x0U
#define _VCU_230_STRATEGY_SHIFT_POSITION_P       0x1U
#define _VCU_230_STRATEGY_SHIFT_POSITION_N       0x2U
#define _VCU_230_STRATEGY_SHIFT_POSITION_R       0x3U
#define _VCU_230_STRATEGY_SHIFT_POSITION_D       0x4U
#define _VCU_230_STRATEGY_SHIFT_POSITION_E       0x6U
#define _VCU_230_STRATEGY_SHIFT_POSITION_S       0x7U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*PEPS_RemLockCmd*/
#define _PEPS_RemLockCmd_Inactive             0x0U
#define _PEPS_RemLockCmd_Lock                 0x1U
#define _PEPS_RemLockCmd_Unlock               0x3U
#define _PEPS_RemLockCmd_Tailgate_Release     0x4U
#define _PEPS_RemLockCmd_Panic                0x5U
#define _PEPS_RemLockCmd_Tailgate_active      0x6U
#define _PEPS_RemLockCmd_Tailgate_hallt       0x7U

/*PEPS_PollingFctCmd*/
#define _PEPS_PollingFctCmd_Welcome_Light_Off             0x0U
#define _PEPS_PollingFctCmd_Welcome_Light_On              0x1U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light_Off 0x2U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light-On  0x3U
#define _PEPS_PollingFctCmd_Lock                          0x4U
#define _PEPS_PollingFctCmd_Unlock                        0x5U
#define _PEPS_PollingFctCmd_Tailgate Open                 0x6U

/*PEPS_KeyInCarRmn*/
#define _PEPS_KeyInCarRmn_No_Information             0x0U
#define _PEPS_KeyInCarRmn_Key_In_Reminder            0x1U

/*PEPS_AuthentFb_PKC*/
#define _PEPS_AuthentFb_PKC_Invalid             0x0U
#define _PEPS_AuthentFb_PKC_Inactive            0x1U
#define _PEPS_AuthentFb_PKC_Active              0x2U

/*PEPS_AuthentFb_TBOX*/
#define _PEPS_AuthentFb_TBOX_Invalid             0x0U
#define _PEPS_AuthentFb_TBOX_Inactive            0x1U
#define _PEPS_AuthentFb_TBOX_Active              0x2U

/*PDCU_RefrshModRestrntFctCmd*/
#define _PDCU_RefrshModRestrntFctCmd_Init             0x0U
#define _PDCU_RefrshModRestrntFctCmd_K15L             0x1U
#define _PDCU_RefrshModRestrntFctCmd_Non              0x2U

/*ETRS_PBtnSts*/
#define _ETRS_PBtnSts_Not_Press          0x0U
#define _ETRS_PBtnSts_Pressed            0x1U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PLGM_TrActnHandCmd*/
#define _PLGM_TrActnHandCmd_Inactive                              0x0U
#define _PLGM_TrActnHandCmd_Open_Request_Pulling_Up_By_Hand       0x1U
#define _PLGM_TrActnHandCmd_Close_Request_Pulling_Down_By_Hand    0x2U

/*PLGM_OperMod*/
#define _PLGM_OperMod_Normal_mode          0x0U
#define _PLGM_OperMod_Transport_mode       0x1U
#define _PLGM_OperMod_Exhibition_mode      0x2U

/*PLGM_UsrSetTrMaxHeiResFb*/
#define _PLGM_UsrSetTrMaxHeiResFb_Not_Setting          0x0U
#define _PLGM_UsrSetTrMaxHeiResFb_Successful_Setting   0x1U
#define _PLGM_UsrSetTrMaxHeiResFb_Failed_Setting       0x2U
   #endif
   
#ifdef _BAIC_COM_B30X
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x2U
#define _SPEED_VALID         0x1U

/*PwrMod*/
#define _PwrMod_OFF       0x0U
#define _PwrMod_ACC       0x1U
#define _PwrMod_IGN_ON    0x2U
#define _PwrMod_CRANK     0x3U

/*PwrModVld*/
#define _PwrModVld_Invaild     0x1U
#define _PwrModVld_Vaild       0x2U

/*DrvrDoorOpenStsSwt*/
/*PassDoorOpenStsSwt*/
/*ReLeDoorOpenStsSwt*/
/*ReRiDoorOpenStsSwt*/
#define _DoorSts_initialing    0x0U
#define _DoorSts_Closed        0x1U
#define _DoorSts_Open          0x2U
#define _DoorSts_Invalid       0x3U
#define _DoorSts_Reserved      0x0U

/*DrvrDoorLockStsSwt */
/*PassDoorLockStsSwt*/
/*ReLeDoorLockStsSwt*/
/*ReRiDoorLockStsSwt*/
#define _DrvrDoorLockStsSwt_initialing    0x0U
#define _DrvrDoorLockStsSwt_Locked        0x1U
#define _DrvrDoorLockStsSwt_Unlocked      0x2U
#define _DrvrDoorLockStsSwt_Invalid       0x3U

/*TrIntSwt */
#define _TrIntSwt_initialing    0x0U
#define _TrIntSwt_Not_active    0x1U
#define _TrIntSwt_Active        0x2U
#define _TrIntSwt_Invalid       0x3U

/*TrExtSwt */
#define _TrExtSwt_initialing    0x0U
#define _TrExtSwt_Not_active    0x1U
#define _TrExtSwt_Active        0x2U
#define _TrExtSwt_Invalid       0x3U

/*AcBlowrLelDisp*/
#define _AcBlowrLelDisp_Initializing    0x0U
#define _AcBlowrLelDisp_Level_0         0x1U
#define _AcBlowrLelDisp_Level_1         0x2U
#define _AcBlowrLelDisp_Level_2         0x3U
#define _AcBlowrLelDisp_Level_3         0x4U
#define _AcBlowrLelDisp_Level_4         0x5U
#define _AcBlowrLelDisp_Level_5         0x6U
#define _AcBlowrLelDisp_Level_6         0x7U
#define _AcBlowrLelDisp_Level_7         0x8U
#define _AcBlowrLelDisp_Level_8         0x9U

/*AcRecircDisp*/
#define _AcRecircDisp_Initializing          0x0U
#define _AcRecircDisp_Not_display           0x1U
#define _AcRecircDisp_Display_Fresh_Air     0x2U
#define _AcRecircDisp_Display_Recirculation 0x3U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*RemAuthentRes*/
#define _RemAuthentRes_initialing                     0x0U
#define _RemAuthentRes_No_anthentication_or_failure   0x1U
#define _RemAuthentRes_IAnthentication_success        0x2U
#define _RemAuthentRes_Invalid                        0x3U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PtmOperSwt*/
#define _PtmOperSwt_Inactive    0x0U
#define _PtmOperSwt_ON          0x1U
#define _PtmOperSwt_Open        0x2U
#define _PtmOperSwt_Close       0x3U
#define _PtmOperSwt_Stop        0x4U
#define _PtmOperSwt_Invalid     0x7U
#define _PtmOperSwt_Active      0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x2U
#define _ODOMETER_VALID         0x1U 

/*VCU_230_STRATEGY_SHIFT_POSITION*/
#define _VCU_230_STRATEGY_SHIFT_POSITION_Void    0x0U
#define _VCU_230_STRATEGY_SHIFT_POSITION_P       0x1U
#define _VCU_230_STRATEGY_SHIFT_POSITION_N       0x2U
#define _VCU_230_STRATEGY_SHIFT_POSITION_R       0x3U
#define _VCU_230_STRATEGY_SHIFT_POSITION_D       0x4U
#define _VCU_230_STRATEGY_SHIFT_POSITION_E       0x6U
#define _VCU_230_STRATEGY_SHIFT_POSITION_S       0x7U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*PEPS_RemLockCmd*/
#define _PEPS_RemLockCmd_Inactive             0x0U
#define _PEPS_RemLockCmd_Lock                 0x1U
#define _PEPS_RemLockCmd_Unlock               0x3U
#define _PEPS_RemLockCmd_Tailgate_Release     0x4U
#define _PEPS_RemLockCmd_Panic                0x5U
#define _PEPS_RemLockCmd_Tailgate_active      0x6U
#define _PEPS_RemLockCmd_Tailgate_hallt       0x7U

/*PEPS_PollingFctCmd*/
#define _PEPS_PollingFctCmd_Welcome_Light_Off             0x0U
#define _PEPS_PollingFctCmd_Welcome_Light_On              0x1U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light_Off 0x2U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light-On  0x3U
#define _PEPS_PollingFctCmd_Lock                          0x4U
#define _PEPS_PollingFctCmd_Unlock                        0x5U
#define _PEPS_PollingFctCmd_Tailgate Open                 0x6U

/*PEPS_KeyInCarRmn*/
#define _PEPS_KeyInCarRmn_No_Information             0x0U
#define _PEPS_KeyInCarRmn_Key_In_Reminder            0x1U

/*PEPS_AuthentFb_PKC*/
#define _PEPS_AuthentFb_PKC_Invalid             0x0U
#define _PEPS_AuthentFb_PKC_Inactive            0x1U
#define _PEPS_AuthentFb_PKC_Active              0x2U

/*PEPS_AuthentFb_TBOX*/
#define _PEPS_AuthentFb_TBOX_Invalid             0x0U
#define _PEPS_AuthentFb_TBOX_Inactive            0x1U
#define _PEPS_AuthentFb_TBOX_Active              0x2U

/*PDCU_RefrshModRestrntFctCmd*/
#define _PDCU_RefrshModRestrntFctCmd_Init             0x0U
#define _PDCU_RefrshModRestrntFctCmd_K15L             0x1U
#define _PDCU_RefrshModRestrntFctCmd_Non              0x2U

/*ETRS_PBtnSts*/
#define _ETRS_PBtnSts_Not_Press          0x0U
#define _ETRS_PBtnSts_Pressed            0x1U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PLGM_TrActnHandCmd*/
#define _PLGM_TrActnHandCmd_Inactive                              0x0U
#define _PLGM_TrActnHandCmd_Open_Request_Pulling_Up_By_Hand       0x1U
#define _PLGM_TrActnHandCmd_Close_Request_Pulling_Down_By_Hand    0x2U

/*PLGM_OperMod*/
#define _PLGM_OperMod_Normal_mode          0x0U
#define _PLGM_OperMod_Transport_mode       0x1U
#define _PLGM_OperMod_Exhibition_mode      0x2U

/*PLGM_UsrSetTrMaxHeiResFb*/
#define _PLGM_UsrSetTrMaxHeiResFb_Not_Setting          0x0U
#define _PLGM_UsrSetTrMaxHeiResFb_Successful_Setting   0x1U
#define _PLGM_UsrSetTrMaxHeiResFb_Failed_Setting       0x2U
   #endif   
   
   #ifdef _BAIC_COM_N51AB
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x2U
#define _SPEED_VALID         0x1U

/*PwrMod*/
#define _PwrMod_OFF       0x0U
#define _PwrMod_ACC       0x1U
#define _PwrMod_IGN_ON    0x2U
#define _PwrMod_CRANK     0x3U

/*PwrModVld*/
#define _PwrModVld_Invaild     0x1U
#define _PwrModVld_Vaild       0x2U

/*DrvrDoorOpenStsSwt*/
/*PassDoorOpenStsSwt*/
/*ReLeDoorOpenStsSwt*/
/*ReRiDoorOpenStsSwt*/
#define _DoorSts_initialing    0x0U
#define _DoorSts_Closed        0x1U
#define _DoorSts_Open          0x2U
#define _DoorSts_Invalid       0x3U
#define _DoorSts_Reserved      0x0U

/*DrvrDoorLockStsSwt */
/*PassDoorLockStsSwt*/
/*ReLeDoorLockStsSwt*/
/*ReRiDoorLockStsSwt*/
#define _DrvrDoorLockStsSwt_initialing    0x0U
#define _DrvrDoorLockStsSwt_Locked        0x1U
#define _DrvrDoorLockStsSwt_Unlocked      0x2U
#define _DrvrDoorLockStsSwt_Invalid       0x3U

/*TrIntSwt */
#define _TrIntSwt_initialing    0x0U
#define _TrIntSwt_Not_active    0x1U
#define _TrIntSwt_Active        0x2U
#define _TrIntSwt_Invalid       0x3U

/*TrExtSwt */
#define _TrExtSwt_initialing    0x0U
#define _TrExtSwt_Not_active    0x1U
#define _TrExtSwt_Active        0x2U
#define _TrExtSwt_Invalid       0x3U

/*AcBlowrLelDisp*/
#define _AcBlowrLelDisp_Initializing    0x0U
#define _AcBlowrLelDisp_Level_0         0x1U
#define _AcBlowrLelDisp_Level_1         0x2U
#define _AcBlowrLelDisp_Level_2         0x3U
#define _AcBlowrLelDisp_Level_3         0x4U
#define _AcBlowrLelDisp_Level_4         0x5U
#define _AcBlowrLelDisp_Level_5         0x6U
#define _AcBlowrLelDisp_Level_6         0x7U
#define _AcBlowrLelDisp_Level_7         0x8U
#define _AcBlowrLelDisp_Level_8         0x9U

/*AcRecircDisp*/
#define _AcRecircDisp_Initializing          0x0U
#define _AcRecircDisp_Not_display           0x1U
#define _AcRecircDisp_Display_Fresh_Air     0x2U
#define _AcRecircDisp_Display_Recirculation 0x3U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*RemAuthentRes*/
#define _RemAuthentRes_initialing                     0x0U
#define _RemAuthentRes_No_anthentication_or_failure   0x1U
#define _RemAuthentRes_IAnthentication_success        0x2U
#define _RemAuthentRes_Invalid                        0x3U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PtmOperSwt*/
#define _PtmOperSwt_Inactive    0x0U
#define _PtmOperSwt_ON          0x1U
#define _PtmOperSwt_Open        0x2U
#define _PtmOperSwt_Close       0x3U
#define _PtmOperSwt_Stop        0x4U
#define _PtmOperSwt_Invalid     0x7U
#define _PtmOperSwt_Active      0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x2U
#define _ODOMETER_VALID         0x1U 

/*VCU_230_STRATEGY_SHIFT_POSITION*/
#define _VCU_230_STRATEGY_SHIFT_POSITION_Void    0x0U
#define _VCU_230_STRATEGY_SHIFT_POSITION_P       0x1U
#define _VCU_230_STRATEGY_SHIFT_POSITION_N       0x2U
#define _VCU_230_STRATEGY_SHIFT_POSITION_R       0x3U
#define _VCU_230_STRATEGY_SHIFT_POSITION_D       0x4U
#define _VCU_230_STRATEGY_SHIFT_POSITION_E       0x6U
#define _VCU_230_STRATEGY_SHIFT_POSITION_S       0x7U

/*OutdTVld*/
#define _OutdTVld_Initializing                0x0U
#define _OutdTVld_Valid                       0x1U
#define _OutdTVld_Value_below_lower_limit     0x2U
#define _OutdTVld_Value_above_upper_limit     0x3U
#define _OutdTVld_Invalid                     0x7U

/*PEPS_RemLockCmd*/
#define _PEPS_RemLockCmd_Inactive             0x0U
#define _PEPS_RemLockCmd_Lock                 0x1U
#define _PEPS_RemLockCmd_Unlock               0x3U
#define _PEPS_RemLockCmd_Tailgate_Release     0x4U
#define _PEPS_RemLockCmd_Panic                0x5U
#define _PEPS_RemLockCmd_Tailgate_active      0x6U
#define _PEPS_RemLockCmd_Tailgate_hallt       0x7U

/*PEPS_PollingFctCmd*/
#define _PEPS_PollingFctCmd_Welcome_Light_Off             0x0U
#define _PEPS_PollingFctCmd_Welcome_Light_On              0x1U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light_Off 0x2U
#define _PEPS_PollingFctCmd_Easy_Trunk_Indicate_Light-On  0x3U
#define _PEPS_PollingFctCmd_Lock                          0x4U
#define _PEPS_PollingFctCmd_Unlock                        0x5U
#define _PEPS_PollingFctCmd_Tailgate Open                 0x6U

/*PEPS_KeyInCarRmn*/
#define _PEPS_KeyInCarRmn_No_Information             0x0U
#define _PEPS_KeyInCarRmn_Key_In_Reminder            0x1U

/*PEPS_AuthentFb_PKC*/
#define _PEPS_AuthentFb_PKC_Invalid             0x0U
#define _PEPS_AuthentFb_PKC_Inactive            0x1U
#define _PEPS_AuthentFb_PKC_Active              0x2U

/*PEPS_AuthentFb_TBOX*/
#define _PEPS_AuthentFb_TBOX_Invalid             0x0U
#define _PEPS_AuthentFb_TBOX_Inactive            0x1U
#define _PEPS_AuthentFb_TBOX_Active              0x2U

/*PDCU_RefrshModRestrntFctCmd*/
#define _PDCU_RefrshModRestrntFctCmd_Init             0x0U
#define _PDCU_RefrshModRestrntFctCmd_K15L             0x1U
#define _PDCU_RefrshModRestrntFctCmd_Non              0x2U

/*ETRS_PBtnSts*/
#define _ETRS_PBtnSts_Not_Press          0x0U
#define _ETRS_PBtnSts_Pressed            0x1U

/*AntiThiefIndcr*/
#define _AntiThiefIndcr_initialing     0x0U
#define _AntiThiefIndcr_Inactive       0x1U
#define _AntiThiefIndcr_active         0x2U
#define _AntiThiefIndcr_alarm          0x3U
#define _AntiThiefIndcr_Invalid        0x4U

/*PLGM_TrActnHandCmd*/
#define _PLGM_TrActnHandCmd_Inactive                              0x0U
#define _PLGM_TrActnHandCmd_Open_Request_Pulling_Up_By_Hand       0x1U
#define _PLGM_TrActnHandCmd_Close_Request_Pulling_Down_By_Hand    0x2U

/*PLGM_OperMod*/
#define _PLGM_OperMod_Normal_mode          0x0U
#define _PLGM_OperMod_Transport_mode       0x1U
#define _PLGM_OperMod_Exhibition_mode      0x2U

/*PLGM_UsrSetTrMaxHeiResFb*/
#define _PLGM_UsrSetTrMaxHeiResFb_Not_Setting          0x0U
#define _PLGM_UsrSetTrMaxHeiResFb_Successful_Setting   0x1U
#define _PLGM_UsrSetTrMaxHeiResFb_Failed_Setting       0x2U
   #endif
/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x2U
#define _ENGINE_VALID         0x1U

/*TimeInformation_Valid*/
#define _TIME_INVALID       0x1U
#define _TIME_VALID         0x0U

/*OutdT*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_70       0xDCU
#define _BUS_TEMPERATURE_80       0xF0U



/*PtmEna*/
#define _PtmEna_Inactive          0x0U
#define _PtmEna_ON                0x1U
#define _PtmEna_OFF               0x2U
#define _PtmEna_Invalid           0x3U


/*PtmFootKickSwt*/
#define _PtmFootKickSwt_Inactive          0x0U
#define _PtmFootKickSwt_ON                0x1U
#define _PtmFootKickSwt_OFF               0x2U
#define _PtmFootKickSwt_Invalid           0x3U

/*PtmLiWarmSwt*/
#define _PtmLiWarmSwt_Inactive          0x0U
#define _PtmLiWarmSwt_ON                0x1U
#define _PtmLiWarmSwt_OFF               0x2U
#define _PtmLiWarmSwt_Invalid           0x3U

/*PtmSoundSwt*/
#define _PtmSoundSwt_Inactive          0x0U
#define _PtmSoundSwt_ON                0x1U
#define _PtmSoundSwt_OFF               0x2U
#define _PtmSoundSwt_Invalid           0x3U

/*PtmSmtEntrySwt*/
#define _PtmSmtEntrySwt_Inactive          0x0U
#define _PtmSmtEntrySwt_ON                0x1U
#define _PtmSmtEntrySwt_OFF               0x2U
#define _PtmSmtEntrySwt_Invalid           0x3U

/*PtmSmtEntrySet*/
#define _PtmSmtEntrySet_Inactive          0x0U
#define _PtmSmtEntrySet_OFF               0x1U
#define _PtmSmtEntrySet_On_Mode_1         0x2U
#define _PtmSmtEntrySet_On_Mode_2         0x3U

/*BdcVehMod*/
#define _BdcVehMod_Normal_Mode       0x0U
#define _BdcVehMod_Transport_Mode    0x1U
#define _BdcVehMod_Exhibition_Mode   0x2U
#define _BdcVehMod_Factory_Mode      0x3U
#define _BdcVehMod_Crash_Mode        0x4U
#define _BdcVehMod_Test_Mode         0x5U

/*BlePtmOperCmd*/
#define _BlePtmOperCmd_Inactive      0x0U
#define _BlePtmOperCmd_Open          0x1U
#define _BlePtmOperCmd_close         0x2U
#define _BlePtmOperCmd_stop          0x3U

/*BleAuthentRes*/
#define _BleAuthentRes_initialing                    0x0U
#define _BleAuthentRes_No_anthentication_or_failure  0x1U
#define _BleAuthentRes_IAnthentication_success       0x2U
#define _BleAuthentRes_inactive                      0x3U

/*Tx*/
/*PtmLtchSts*/
#define _PtmLtchSts_Open          0x0U
#define _PtmLtchSts_Secondary     0x1U
#define _PtmLtchSts_Latched       0x2U
#define _PtmLtchSts_Initializing  0x3U

/*PtmPncEve*/
#define _PtmPncEve_Normal              0x0U
#define _PtmPncEve_Antipinch_event     0x1U

/*PtmOperSts*/
#define _PtmOperSts_Stop       0x0U
#define _PtmOperSts_Open       0x1U
#define _PtmOperSts_close      0x2U
#define _PtmOperSts_opening    0x3U
#define _PtmOperSts_Closing    0x4U

/*PtmMod*/
#define _PtmMod_Normal          0x0U
#define _PtmMod_delay_close     0x1U

/*PtmOperIndcnLi*/
#define _PtmOperIndcnLi_NO_Indication                          0x0U
#define _PtmOperIndcnLi_PTM_closing_light_indication           0x1U
#define _PtmOperIndcnLi_PTM_opening_light_indication           0x2U
#define _PtmOperIndcnLi_PTM_pinch_event_light_indication       0x3U
#define _PtmOperIndcnLi_PTM_delay_close_event_light_indication 0x4U
#define _PtmOperIndcnLi_PTM_position_reset_successful          0x5U

/*PtmOperIndcnSound*/
#define _PtmOperIndcnSound_NO_Sound                      0x0U
#define _PtmOperIndcnSound_PTM_closing_sound             0x1U
#define _PtmOperIndcnSound_PTM_opening_sound             0x2U
#define _PtmOperIndcnSound_PTM_PINCH_EVENT_sound         0x3U
#define _PtmOperIndcnSound_PTM_delay_close_event_sound   0x4U
#define _PtmOperIndcnSound_PTM_position_reset_successful 0x5U


/*PtmEcuFailSts*/
#define _PtmEcuFailSts_Normal            0x0U
#define _PtmEcuFailSts_PTM_ECU_FAIL      0x1U
 
/*PtmFotKicReq*/
#define _PtmFotKicReq_Inactive    0x0U
#define _PtmFotKicReq_active      0x1U

/*PtmPwrEnaSts*/
#define _PtmPwrEnaSts_Disable     0x0U
#define _PtmPwrEnaSts_Enable      0x1U

/*PtmFotKicEnaSts*/
#define _PtmFotKicEnaSts_Disable     0x0U
#define _PtmFotKicEnaSts_Enable      0x1U

/*PtmSoundEnaSts*/
#define _PtmSoundEnaSts_Disable     0x0U
#define _PtmSoundEnaSts_Enable      0x1U

/*PtmLiEnaSts*/
#define _PtmLiEnaSts_Disable     0x0U
#define _PtmLiEnaSts_Enable      0x1U

/*PtmWarnMsg*/
#define _PtmWarnMsg_off                    0x0U
#define _PtmWarnMsg_Please_shift_to_P      0x1U

/*PtmLrnSts*/
#define _PtmLrnSts_Failed           0x0U
#define _PtmLrnSts_Set_success      0x1U

/*InsidSwt*/
#define _InsidSwt_inactive             0x0U
#define _InsidSwt_active               0x1U
#define _InsidSwt_request_delay_close  0x2U

/*PLGM_TrInnrSwtSts*/
#define _PLGM_TrInnrSwtSts_Inactive               0x0U
#define _PLGM_TrInnrSwtSts_ShortPressed           0x1U
#define _PLGM_TrInnrSwtSts_LongPressed            0x2U
#define _PLGM_TrInnrSwtSts_request_delay_close    0x3U


/*TriggerSource*/
#define _OpenRes_InsidSwt             0x0AU
#define _OpenRes_TrExtSwt             0x01U
#define _OpenRes_TrIntSwt             0x02U
#define _OpenRes_RemKeyFctForLock     0x03U
#define _OpenRes_PtmOperSwt           0x04U
#define _OpenRes_TmPtmOperCmd         0x05U
#define _OpenRes_BlePtmOperCmd        0x06U
#define _OpenRes_SmtEntryFctCmd       0x07U
#define _OpenRes_Obstacle             0x08U
#define _OpenRes_Tiptorun             0x09U
#define _OpenRes_PtmOperSwt_Open      0x0BU

#define _CloseRes_InsidSwt            0x1AU
#define _CloseRes_TrExtSwt            0x11U
#define _CloseRes_TrIntSwt            0x12U
#define _CloseRes_RemKeyFctForLock    0x13U
#define _CloseRes_PtmOperSwt          0x14U
#define _CloseRes_TmPtmOperCmd        0x15U
#define _CloseRes_BlePtmOperCmd       0x16U
#define _CloseRes_SmtEntryFctCmd      0x17U
#define _CloseRes_Obstacle            0x18U
#define _CloseRes_Tiptorun            0x19U
#define _CloseRes_PtmOperSwt_Close    0x1BU

#define _StopRes_InsidSwt             0x2AU    
#define _StopRes_TrExtSwt             0x21U
#define _StopRes_TrIntSwt             0x22U
#define _StopRes_RemKeyFctForLock     0x23U
#define _StopRes_PtmOperSwt           0x24U
#define _StopRes_TmPtmOperCmd         0x25U
#define _StopRes_BlePtmOperCmd        0x26U
#define _StopRes_SmtEntryFctCmd       0x27U
#define _StopRes_Obstacle             0x28U
#define _StopRes_PtmOperSwt_Stop      0x2BU

#define _StopRes_VehSpd               0x30U
#define _StopRes_TcuActGear           0x31U
#define _StopRes_AirbDeploymtSts      0x32U
#define _StopRes_PtmEna               0x33U
#define _StopRes_Trouble              0x34U

/*BAIC_COM_C62X*/
/*VALID_ESPEED*/
#define _VALID_ESPEED_Value_OK             0x0U
#define _VALID_ESPEED_Value_unreliable     0x1U

/*BCM_SUNROOF_POS*/
#define _BCM_SUNROOF_POS_Position_unknwon     0x0U
#define _BCM_SUNROOF_POS_Completely_closed    0x1U
#define _BCM_SUNROOF_POS_Tilted_100Pecent     0x5U
#define _BCM_SUNROOF_POS_Open_10Percent       0x6U
#define _BCM_SUNROOF_POS_Open_20Percent       0x7U

/*TIP_IN_ACTUAL_GEAR */
#define _TIP_IN_ACTUAL_GEAR_Initial    0x0U
#define _TIP_IN_ACTUAL_GEAR_Reverse    0x2U
#define _TIP_IN_ACTUAL_GEAR_Neutral    0x3U
#define _TIP_IN_ACTUAL_GEAR_3rd        0x7U
#define _TIP_IN_ACTUAL_GEAR_4th        0x8U
#define _TIP_IN_ACTUAL_GEAR_5th        0x9U
#define _TIP_IN_ACTUAL_GEAR_6th        0xFU
#define _TIP_IN_ACTUAL_GEAR_S          0x10U
#define _TIP_IN_ACTUAL_GEAR_D          0x11U
#define _TIP_IN_ACTUAL_GEAR_P          0x12U
#define _TIP_IN_ACTUAL_GEAR_1st        0x15U
#define _TIP_IN_ACTUAL_GEAR_2nd        0x16U
#define _TIP_IN_ACTUAL_GEAR_7th        0x20U

/*VALID_ACTUAL_GEAR_TCU  */
#define _VALID_ACTUAL_GEAR_TCU_Value_OK                 0x0U
#define _VALID_ACTUAL_GEAR_TCU_Value_below_lower_limit  0x1U
#define _VALID_ACTUAL_GEAR_TCU_Value_above_upper_limit  0x2U
#define _VALID_ACTUAL_GEAR_TCU_Value_Value_unreliable   0x3U

/*LOCK_CMD*/
#define _LOCK_CMD_Inactive          0x0U
#define _LOCK_CMD_Lock_all_doors    0x1U
#define _LOCK_CMD_Unlock_all_doors  0x3U
#define _LOCK_CMD_TailgateRelease   0x4U

/*KEY_FUNCTION_COMMAND_CODE*/
#define _KEY_FUNCTION_COMMAND_CODE_Inactive             0x0U
#define _KEY_FUNCTION_COMMAND_CODE_wake_up_the_vehicle  0x1U
#define _KEY_FUNCTION_COMMAND_CODE_welcome_light_on     0x2U
#define _KEY_FUNCTION_COMMAND_CODE_Unlock_all_doors     0x3U
#define _KEY_FUNCTION_COMMAND_CODE_lock_all_doors       0x4U
#define _KEY_FUNCTION_COMMAND_CODE_Easy_trunk_light_on  0x5U
#define _KEY_FUNCTION_COMMAND_CODE_TailgateRelease      0x6U
#define _KEY_FUNCTION_COMMAND_CODE_Tailgatelock         0x7U
#define _KEY_FUNCTION_COMMAND_CODE_Unlock_driver_door   0x8U

#endif

#ifdef _NIU_COM
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x0U
#define _SPEED_VALID         0x1U
/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x0U
#define _ENGINE_VALID         0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x0U
#define _ODOMETER_VALID         0x1U
/*TimeInformation_Valid*/
#define _TIME_INVALID       0x0U
#define _TIME_VALID         0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_70       0xDCU
#define _BUS_TEMPERATURE_80       0xF0U


/*S_ESC5_VehSpdValid*/
#define _S_ESC5_VehSpdValid_Invalid	0x0U
#define _S_ESC5_VehSpdValid_Valid	0x1U

/*BDM1_CentLockSts*/
#define _BDM1_CentLockSts_Inactive	0x0U
#define _BDM1_CentLockSts_Active	0x1U

/*BDM1_CentUnlockSts*/
#define _BDM1_CentUnlockSts_Inactive	0x0U
#define _BDM1_CentUnlockSts_Active	0x1U

/*BDM1_AntiTheftSts*/
#define _BDM1_AntiTheftSts_Security_LED_Off		0x0U
#define _BDM1_AntiTheftSts_Security_LED_blinking	0x1U
#define _BDM1_AntiTheftSts_Security_LED_fault_blinking	0x2U
#define _BDM1_AntiTheftSts_Invalid			0x3U

/*BDM11_PowerMode*/
#define _BDM11_PowerMode_Off	      0x0U
#define _BDM11_PowerMode_Acc	      0x1U
#define _BDM11_PowerMode_On	      0x2U
#define _BDM11_PowerMode_Reserved     0x3U

/*BDM11_RkeLockCmd*/
#define _BDM11_RkeLockCmd_Default_value	  0x0U
#define _BDM11_RkeLockCmd_Short_Unlock	  0x1U
#define _BDM11_RkeLockCmd_Short_Lock	  0x2U
#define _BDM11_RkeLockCmd_Long_Lock	  0x3U
#define _BDM11_RkeLockCmd_Trunk_Unlock    0x4U
#define _BDM11_RkeLockCmd_Searching_Car	  0x5U
#define _BDM11_RkeLockCmd_Long_Unlock	  0x6U
#define _BDM11_RkeLockCmd_Trunk_lock	  0x7U

/*B_Tbox_RepeatMessageReq*/
#define _B_Tbox_RepeatMessageReq_RepeatMessageStateNotRequested	  0x0U
#define _B_Tbox_RepeatMessageReq_RepeatMessageStateRequested	  0x1U

/*B_Tbox_ActiveWakeupBit*/
#define _B_Tbox_ActiveWakeupBit_PassiveWakeup	0x0U
#define _B_Tbox_ActiveWakeupBit_ActiveWakeup    0x1U

/*MMI3_RDMAntiPinchAlarmSet*/
#define _MMI3_RDMAntiPinchAlarmSet_Off		0x0U
#define _MMI3_RDMAntiPinchAlarmSet_On		0x1U
#define _MMI3_RDMAntiPinchAlarmSet_Reserved	0x2U
#define _MMI3_RDMAntiPinchAlarmSet_Default	0x3U

/*MMI2_RearDoorPosSet*/
#define _MMI2_RearDoorPosSet_50_percent		0x00U
#define _MMI2_RearDoorPosSet_100_percent        0x32U

/*MMI5_RearDoorCtrlReq*/
#define _MMI5_RearDoorCtrlReq_Close		0x0U
#define _MMI5_RearDoorCtrlReq_Open		0x1U
#define _MMI5_RearDoorCtrlReq_Pause		0x2U
#define _MMI5_RearDoorCtrlReq_Default	        0x3U

/*RDM1_SystemFaultSts*/
#define _RDM1_SystemFaultSts_No_Fault      0x0U
#define _RDM1_SystemFaultSts_Fault         0x1U
/*RDM1_InitSt*/
#define _RDM1_InitSt_Uninitialized         0x0U
#define _RDM1_InitSt_Initialized           0x1U
/*RDM1_RearDoorTherProSts*/
#define _RDM1_RearDoorTherProSts_Inactive  0x0U
#define _RDM1_RearDoorTherProSts_Active    0x1U
/*RDM1_HalfLockSt*/
#define _RDM1_HalfLockSt_Unlock            0x0U
#define _RDM1_HalfLockSt_Lock              0x1U
/*RDM1_FullLockSt*/
#define _RDM1_FullLockSt_Unlock            0x0U
#define _RDM1_FullLockSt_Lock              0x1U
/*RDM1_InsideSwitchSts*/
#define _RDM1_InsideSwitchSts_Not_Press    0x0U
#define _RDM1_InsideSwitchSts_Press        0x1U
/*RDM1_RearDoorPos*/
/*RDM1_RearDoorSts*/
#define _RDM1_RearDoorSts_Closed               0x0U
#define _RDM1_RearDoorSts_Closing              0x1U
#define _RDM1_RearDoorSts_Opened               0x2U
#define _RDM1_RearDoorSts_Opening              0x3U
#define _RDM1_RearDoorSts_Pause                0x4U
/*RDM1_CentralLockingSwSts*/
#define _RDM1_CentralLockingSwSts_Not_Press    0x0U
#define _RDM1_CentralLockingSwSts_Press        0x1U
/*RDM1_RearDoorAntiPinchSts*/
#define _RDM1_RearDoorAntiPinchSts_Inactive    0x0U
#define _RDM1_RearDoorAntiPinchSts_Active      0x1U
/*RDM1_VechicleAlarmReq*/
#define _RDM1_VechicleAlarmReq_Not_Request     0x0U
#define _RDM1_VechicleAlarmReq_Request         0x1U
/*RDM1_AntiPinchAlarmSts*/
#define _RDM1_AntiPinchAlarmSts_Off    0x0U
#define _RDM1_AntiPinchAlarmSts_On     0x1U

#endif

#ifdef _DFMC_COM
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x0U
#define _SPEED_VALID         0x1U
/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x0U
#define _ENGINE_VALID         0x1U

/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x0U
#define _ODOMETER_VALID         0x1U
/*TimeInformation_Valid*/
#define _TIME_INVALID       0x0U
#define _TIME_VALID         0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_70       0xDCU
#define _BUS_TEMPERATURE_80       0xF0U

/*ble_rke_tailgateCtrlReq*/
#define _ble_rke_tailgateCtrlReq_No_Request   0x0U
#define _ble_rke_tailgateCtrlReq_Open         0x1U
#define _ble_rke_tailgateCtrlReq_Close        0x2U

/*tbox_remoteTailgateCtrlReq*/
#define _tbox_remoteTailgateCtrlReq_NO_REQUEST    0x0U
#define _tbox_remoteTailgateCtrlReq_OPEN          0x1U
#define _tbox_remoteTailgateCtrlReq_CLOSE         0x2U

/*EPBM_Sts*/
#define _EPBM_Sts_DEFAULT             0x0U
#define _EPBM_Sts_PARKED              0x1U
#define _EPBM_Sts_RELEASED            0x2U
#define _EPBM_Sts_PARKING             0x3U
#define _EPBM_Sts_RELEASING           0x4U
#define _EPBM_Sts_COMPLETELY_RELEASED 0x5U
#define _EPBM_Sts_UNKNOWN             0x6U

/*ivi_pot_SpeechCtrlOnOffSts*/
#define _ivi_pot_SpeechCtrlOnOffSts_NoInput      0x0U
#define _ivi_pot_SpeechCtrlOnOffSts_CLOSE        0x1U
#define _ivi_pot_SpeechCtrlOnOffSts_OPEN         0x2U
#define _ivi_pot_SpeechCtrlOnOffSts_STOP         0x3U

/*ivi_potOnOffSet*/
#define _ivi_potOnOffSet_NoInput      0x0U
#define _ivi_potOnOffSet_CLOSE        0x1U
#define _ivi_potOnOffSet_OPEN         0x2U
#define _ivi_potOnOffSet_STOP         0x3U

/*ivi_potPositionStsSet*/
#define _ivi_potPositionStsSet_No_request      0x0U
#define _ivi_potPositionStsSet_40_percent      0x1U
#define _ivi_potPositionStsSet_50_percent      0x2U
#define _ivi_potPositionStsSet_60_percent      0x3U
#define _ivi_potPositionStsSet_70_percent      0x4U
#define _ivi_potPositionStsSet_80_percent      0x5U
#define _ivi_potPositionStsSet_90_percent      0x6U
#define _ivi_potPositionStsSet_100_percent     0x7U

/*PDCM_SOC*/
#define _PDCM_SOC_init   0x7FEU
#define _PDCM_SOC_Fault  0x7FFU

/*bcm_antiTheftSts*/
#define _bcm_antiTheftSts_DISARMED    0x0U
#define _bcm_antiTheftSts_ARMED       0x1U
#define _bcm_antiTheftSts_ALARM       0x2U
#define _bcm_antiTheftSts_HALF_ARMED  0x3U

/*bcm_tailgateOpenSW*/
#define _bcm_tailgateOpenSW_No_ACTION   0x0U
#define _bcm_tailgateOpenSW_ACTION      0x1U

/*HVCM_ChargeState*/
#define _HVCM_ChargeState_OFF                         0x0U
#define _HVCM_ChargeState_Charing_Finished            0x1U
#define _HVCM_ChargeState_Battery_Pre-Heating_active  0x3U
#define _HVCM_ChargeState_Timer_Charging_active       0x4U
#define _HVCM_ChargeState_immeidately_Charging_active 0x5U

/*bcm_pepsPowerMode*/
#define _bcm_pepsPowerMode_DEFAULT_POWERMODE    0x0U
#define _bcm_pepsPowerMode_OFF_POWERMODE        0x1U
#define _bcm_pepsPowerMode_Local_ON_POWERMODE   0x2U
#define _bcm_pepsPowerMode_Remote_ON_POWERMODE  0x3U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE1   0x4U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE2   0x5U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE3   0x6U
#define _bcm_pepsPowerMode_INVALID_POWERMODE    0x7U

/*bcm_remoteMode*/
#define _bcm_remoteMode_INVALID     0x0U
#define _bcm_remoteMode_NORMAL      0x1U
#define _bcm_remoteMode_REMOTE      0x2U
#define _bcm_remoteMode_Reserved    0x3U

/*bcm_ble_response*/
#define _bcm_ble_response_default                             0x0U
#define _bcm_ble_response_Anti_theft_authentication_failed    0x1U
#define _bcm_ble_response_Anti_theft_authentication_success   0x2U
#define _bcm_ble_response_Reserved                            0x3U

/*bcm_tbox_response*/
#define _bcm_tbox_response_default                             0x0U
#define _bcm_tbox_response_Anti_theft_authentication_failed    0x1U
#define _bcm_tbox_response_Anti_theft_authentication_success   0x2U
#define _bcm_tbox_response_Reserved                            0x3U

/*PDCM_actualGear*/
#define _PDCM_actualGear_P         0x0U
#define _PDCM_actualGear_R         0x1U
#define _PDCM_actualGear_N         0x2U
#define _PDCM_actualGear_D         0x3U

/*PDCM_actualGearValid*/
#define _PDCM_actualGearValid_INVALID          0x0U
#define _PDCM_actualGearValid_VALID            0x1U

/*PDCM_DriveReady*/
#define _PDCM_DriveReady_Not_Ready          0x0U
#define _PDCM_DriveReady_Ready_Local        0x1U
#define _PDCM_DriveReady_Ready_Romote       0x2U
#define _PDCM_DriveReady_Fault              0x3U

/*bcm_delayClosingPotReq*/
#define _bcm_delayClosingPotReq_NoInput    0x0U
#define _bcm_delayClosingPotReq_Close      0x1U

/*bcm_delayTimingReq*/
#define _bcm_delayTimingReq_OFF     0x0U
#define _bcm_delayTimingReq_ON      0x1U

/*bcm_rkeTailgateCtrlCmd*/
#define _bcm_rkeTailgateCtrlCmd_NO_ACTION                  0x0U
#define _bcm_rkeTailgateCtrlCmd_Pressed_Once               0x1U
#define _bcm_rkeTailgateCtrlCmd_Pressed_TwiceIn2Second     0x2U
#define _bcm_rkeTailgateCtrlCmd_Pressed_LongerThan2Second  0x3U

/*bcm_kickActiveReq*/
#define _bcm_kickActiveReq_NO_ACTIVATION_DETECTED   0x0U
#define _bcm_kickActiveReq_KICK_MOVEMENT_DETECTED   0x1U
 
/*bcm_centerCtrlPotOnOffSet*/
#define _bcm_centerCtrlPotOnOffSet_NOT_PRESSED   0x0U
#define _bcm_centerCtrlPotOnOffSet_PRESSED       0x1U
#define _bcm_centerCtrlPotOnOffSet_RESERVED      0x2U
#define _bcm_centerCtrlPotOnOffSet_INVALID       0x3U

/*bcm_keyInPotRemind*/
#define _bcm_keyInPotRemind_No_Warning   0x0U
#define _bcm_keyInPotRemind_Warning      0x1U

/*srm_srMovement*/
#define _srm_srMovement_stopped              0x0U
#define _srm_srMovement_opening_tilt         0x1U
#define _srm_srMovement_closing_tilt         0x2U
#define _srm_srMovement_opening_slide        0x3U
#define _srm_srMovement_closing_slide        0x4U
#define _srm_srMovement_reversing            0x5U
#define _srm_srMovement_moving_uninitialized 0x6U
#define _srm_srMovement_reserved             0x7U

/*ebs_U_BATT*/
#define _ebs_U_BATT_Invalid              0x3FFFU

/*DCU_FL_doorFLSts*/
/*DCU_FR_doorFRSts*/
#define _DCU_doorSts_CLOSE        0x0U
#define _DCU_doorSts_OPEN         0x1U

/*DCU_FL_FLWindowStatus*/
/*DCU_FR_FRWindowStatus*/
/*DCU_RL_RLWindowStatus*/
/*DCU_RR_RRWindowStatus*/
#define _DCU_WindowStatus_stopped             0x0U
#define _DCU_WindowStatus_Window_opened       0x1U
#define _DCU_WindowStatus_Window_closed       0x2U
#define _DCU_WindowStatus_Auto_Up_moving      0x3U
#define _DCU_WindowStatus_Manual_Up_moving    0x4U
#define _DCU_WindowStatus_Auto_Down_moving    0x5U
#define _DCU_WindowStatus_Manual_Down_moving  0x6U
#define _DCU_WindowStatus_Pinch_Reversing     0x7U

/*PSD_L_RLDoor_St*/
/*PSD_R_RRDoor_St*/
#define _PSD_Door_St_Full_Latch         0x0U
#define _PSD_Door_St_Half_Latch         0x1U 
#define _PSD_Door_St_Latch_Open         0x2U 
#define _PSD_Door_St_Full_Open          0x3U 


/*tbox_vehicleMode*/
#define _tbox_vehicleMode_Initial_value          0x0U
#define _tbox_vehicleMode_Normal_mode            0x1U
#define _tbox_vehicleMode_Factory_mode           0x2U
#define _tbox_vehicleMode_Transportation_mode    0x3U
#define _tbox_vehicleMode_Collision_mode         0x4U
#define _tbox_vehicleMode_OTA_mode               0x5U

/*IPB_vehicleSpeedValid*/
#define _IPB_vehicleSpeedValid_INVALID          0x0U
#define _IPB_vehicleSpeedValid_VALID            0x1U

/*AC_FrblowerLv*/
/*AC_RrblowerLv*/
#define _AC_blowerLv_OFF             0x0U
#define _AC_blowerLv_SPEED_1         0x1U 
#define _AC_blowerLv_SPEED_2         0x2U 
#define _AC_blowerLv_SPEED_3         0x3U 
#define _AC_blowerLv_SPEED_4         0x4U 
#define _AC_blowerLv_SPEED_5         0x5U 
#define _AC_blowerLv_SPEED_6         0x6U 
#define _AC_blowerLv_SPEED_7         0x7U 
#define _AC_blowerLv_INVALID         0xF 

/*LgtAValSts*/
#define _Incline_Invaild     0x0U
#define _Incline_Valid       0x1U

/*TX*/
/*pot_CatchSWSts*/
#define _pot_CatchSWSts_OFF     0x0U
#define _pot_CatchSWSts_ON      0x1U

/*pot_PawlSWSts*/
#define _pot_PawlSWSts_OFF     0x0U
#define _pot_PawlSWSts_ON      0x1U

/*pot_tailgateOpenSwSts*/
#define _pot_tailgateOpenSwSts_Released     0x0U
#define _pot_tailgateOpenSwSts_Pressed      0x1U

/*pot_tailgateOpenFailWarning*/
#define _pot_tailgateOpenFailWarning_NO_WARNING    0x0U
#define _pot_tailgateOpenFailWarning_WARNING       0x1U

/*pot_tailgateCloseFailWarning*/
#define _pot_tailgateCloseFailWarning_NO_WARNING    0x0U
#define _pot_tailgateCloseFailWarning_WARNING       0x1U

/*pot_tailgateOpenSts*/
#define _pot_tailgateOpenSts_Fully_opened      0x0U
#define _pot_tailgateOpenSts_Fully_closed      0x1U
#define _pot_tailgateOpenSts_Opening           0x2U
#define _pot_tailgateOpenSts_Closing           0x3U
#define _pot_tailgateOpenSts_PLG_stopped       0x4U
#define _pot_tailgateOpenSts_Latch_releasing   0x5U
#define _pot_tailgateOpenSts_Latch_cinching    0x6U


/*pot_doorMemoryPosEnb*/
#define _pot_doorMemoryPosEnb_No_request    0x0U
#define _pot_doorMemoryPosEnb_Success       0x1U

/*pot_antiPlayWarning*/
#define _pot_antiPlayWarning_NO_WARNING    0x0U
#define _pot_antiPlayWarning_WARNING       0x1U

/*pot_tailgateCloseSwSts*/
#define _pot_tailgateCloseSwSts_Release       0x0U
#define _pot_tailgateCloseSwSts_Press         0x1U
#define _pot_tailgateCloseSwSts_Long_Press    0x2U
#define _pot_tailgateCloseSwSts_Stuck         0x3U

/*pot_workingSts*/
#define _pot_workingSts_Initializing   0x0U
#define _pot_workingSts_Normal         0x1U
#define _pot_workingSts_Abnormality    0x2U
#define _pot_workingSts_Reserved       0x3U

/*pot_OpenTurnIndicator*/
#define _pot_OpenTurnIndicator_Off                       0x0U
#define _pot_OpenTurnIndicator_UserOperationAcception    0x1U
#define _pot_OpenTurnIndicator_MemoryPosition            0x2U
#define _pot_OpenTurnIndicator_UserOperationDenid        0x3U
#define _pot_OpenTurnIndicator_AntiPinchReverse          0x4U
#define _pot_OpenTurnIndicator_ForceStop                 0x5U
#define _pot_OpenTurnIndicator_MemoryPositionFault       0x6U
#define _pot_OpenTurnIndicator_Warning                   0x7U


/*pot_NeutralSWSts*/
#define _pot_NeutralSWSts_OFF     0x0U
#define _pot_NeutralSWSts_ON      0x1U

/*pot_MotorOverTempProtection*/
#define _pot_MotorOverTempProtection_Normal_mode       0x0U
#define _pot_MotorOverTempProtection_Protecting_mode   0x1U

/*pot_delayClosingPotReq*/
#define _pot_delayClosingPotReq_No_Request    0x0U
#define _pot_delayClosingPotReq_Active        0x1U


/*TriggerSource*/
#define _OpenRes_HandleSW                     0x01U
#define _OpenRes_ivi_potOnOffSet              0x02U
#define _OpenRes_rkeTailgateCtrlCmd           0x03U
#define _OpenRes_tbox_remoteTailgateCtrlReq   0x04U
#define _OpenRes_ble_rke_tailgateCtrlReq      0x05U
#define _OpenRes_Obstacle                     0x06U
#define _OpenRes_InsidSwt                     0x07U
#define _OpenRes_Tiptorun                     0x08U
#define _OpenRes_bcm_keyInPotRemind           0x09U

#define _CloseRes_HandleSW                     0x11U
#define _CloseRes_ivi_potOnOffSet              0x12U
#define _CloseRes_rkeTailgateCtrlCmd           0x13U
#define _CloseRes_tbox_remoteTailgateCtrlReq   0x14U
#define _CloseRes_ble_rke_tailgateCtrlReq      0x15U
#define _CloseRes_Obstacle                     0x16U
#define _CloseRes_InsidSwt                     0x17U
#define _CloseRes_Tiptorun                     0x18U
   
#define _StopRes_HandleSW                     0x21U
#define _StopRes_ivi_potOnOffSet              0x22U
#define _StopRes_rkeTailgateCtrlCmd           0x23U
#define _StopRes_tbox_remoteTailgateCtrlReq   0x24U
#define _StopRes_ble_rke_tailgateCtrlReq      0x25U
#define _StopRes_Obstacle                     0x26U
#define _StopRes_InsidSwt                     0x27U
#define _StopRes_VehSpd                       0x2aU
#define _StopRes_Trouble                      0x2bU
#endif

#ifdef _MAXUS_COM
/*TlgtCtrlReq*/
#define _TlgtCtrlReq_No_Request   0x0U
#define _TlgtCtrlReq_Open         0x1U
#define _TlgtCtrlReq_Close        0x2U
#define _TlgtCtrlReq_Hold         0x3U

/*RKEKeyCtrlTlgtReq*/
#define _RKEKeyCtrlTlgtReq_Inactive   0x0U
#define _RKEKeyCtrlTlgtReq_Active     0x1U

/*RKELckCmd*/
#define _RKELckCmd_No_Action                        0x0U
#define _RKELckCmd_Lock                             0x1U
#define _RKELckCmd_Unlock                           0x2U
#define _RKELckCmd_Lock_Long_Pressed                0x3U
#define _RKELckCmd_Unlock_Long_Pressed              0x4U
#define _RKELckCmd_Sliding_Door_Left                0x5U
#define _RKELckCmd_Sliding_Door_Left_Long_Pressed   0x6U
#define _RKELckCmd_Sliding_Door_Right               0x7U
#define _RKELckCmd_Sliding_Door_Right_Long_Pressed  0x8U
#define _RKELckCmd_Tailgate                         0x9U
#define _RKELckCmd_Tailgate_Long_Pressed            0xAU

/*TlgtOprtReq*/
#define _TlgtOprtReq_No_Request       0x0U
#define _TlgtOprtReq_Manual_Release   0x1U
#define _TlgtOprtReq_Normal_Request   0x2U
#define _TlgtOprtReq_Open             0x3U
#define _TlgtOprtReq_Close            0x4U
#define _TlgtOprtReq_Hold             0x5U

/*TlgtOprtPosReq*/
#define _TlgtOprtPosReq_No_Request       0x7FU

/*Tramsmit Messages and Signal*/
/*PLGECUSts*/
#define _PLGECUSts_Init       0x0U
#define _PLGECUSts_Normal     0x1U

/*TlgtOprt*/
#define _TlgtOprt_Status_Unkown   0x0U
#define _TlgtOprt_Opening         0x1U
#define _TlgtOprt_Closing         0x2U
#define _TlgtOprt_Hold            0x3U

/*TlgtPosSts*/
#define _TlgtPosSts_Status_Unkown   0x0U
#define _TlgtPosSts_Open            0x1U
#define _TlgtPosSts_HalfLocked      0x2U
#define _TlgtPosSts_FullyClosed     0x3U

/*TlgtPinchRvsEvt*/
#define _TlgtPinchRvsEvt_Normal          0x0U
#define _TlgtPinchRvsEvt_Pinch_Occurred  0x1U

/*TlgtStlEvt*/
#define _TlgtStlEvt_Normal          0x0U
#define _TlgtStlEvt_Stall_Occurred  0x1U

/*TlgtLtchSts*/
#define _TlgtLtchSts_Status_Unkown                 0x0U
#define _TlgtLtchSts_Latch_UnLocked                0x1U
#define _TlgtLtchSts_Latch_HalfLocked              0x2U
#define _TlgtLtchSts_Latch_Cinching                0x3U
#define _TlgtLtchSts_Latch_Locked                  0x4U
#define _TlgtLtchSts_Latch_Releasing               0x5U
#define _TlgtLtchSts_LatchReseting_After_Cinching  0x6U
#define _TlgtLtchSts_LatchReseting_After_Releasing 0x7U

/*TlgtOprtMd*/
#define _TlgtOprtMd_Manual                  0x0U
#define _TlgtOprtMd_Park                    0x1U
#define _TlgtOprtMd_Norm                    0x2U
#define _TlgtOprtMd_SelfLearning_Unfinished 0x3U

/*TlgtSpdlOvht*/
/*TlgtLtchOvht*/
#define _Ovht_Normal             0x0U
#define _Ovht_In_Protection      0x1U

/*TlgtAPSSts_L*/
/*TlgtAPSSts_R*/
#define _TlgtAPSSts_Normal             0x0U
#define _TlgtAPSSts_Error_Open         0x1U
#define _TlgtAPSSts_Error_Short        0x2U
#define _TlgtAPSSts_Sampling_Error     0x3U

/*TlgtCnchMtrSts*/
/*TlgtSpdlMtrSts*/
#define _MtrSts_Normal        0x0U
#define _MtrSts_Error         0x1U

/*TlgtBuzReq*/
#define _TlgtBuzReq_No_Request                 0x0U
#define _TlgtBuzReq_LongBeep_1_Time            0x1U
#define _TlgtBuzReq_LongBeep_2_Times           0x2U
#define _TlgtBuzReq_ShortBeep_2_Times          0x3U
#define _TlgtBuzReq_ShortBeep_3_Times          0x4U
#define _TlgtBuzReq_ShortBeep_4_Times          0x5U
#define _TlgtBuzReq_ShortBeep_5_Times          0x6U
#define _TlgtBuzReq_ShortBeep_6_Times          0x7U

/*TlgtFlshReq*/
#define _TlgtFlshReq_No_Request           0x0U
#define _TlgtFlshReq_Flash_Once           0x1U
#define _TlgtFlshReq_Flash_Twice          0x2U

/*TlgtAbsAlrm*/
#define _TlgtAbsAlrm_No_Request           0x0U
#define _TlgtAbsAlrm_In_Abuse_Mode_1      0x1U
#define _TlgtAbsAlrm_In_Abuse_Mode_2      0x2U
#define _TlgtAbsAlrm_In_Abuse_Mode_3      0x3U


/*TrCrntShftLvrPos*/
#define _TrCrntShftLvrPos_Between_Ranges     0x0U
#define _TrCrntShftLvrPos_P                  0x1U
#define _TrCrntShftLvrPos_R                  0x2U
#define _TrCrntShftLvrPos_N                  0x3U
#define _TrCrntShftLvrPos_D                  0x4U
#define _TrCrntShftLvrPos_M                  0x5U
#define _TrCrntShftLvrPos_Invalid_Value      0x6U

/*TrCrntShftLvrPosV*/
#define _TrCrntShftLvrPosV_Invalid       0x0U
#define _TrCrntShftLvrPosV_Valid         0x1U

/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x0U
#define _SPEED_VALID         0x1U

/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x0U
#define _ENGINE_VALID         0x1U
/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x0U
#define _ODOMETER_VALID         0x1U
/*TimeInformation_Valid*/
#define _TIME_INVALID       0x0U
#define _TIME_VALID         0x1U

/*SysPwrMd*/
#define _SysPwrMd_OFF      0x0U
#define _SysPwrMd_ACC      0x1U
#define _SysPwrMd_RUN      0x2U
#define _SysPwrMd_CRANK    0x3U

/*SysPwrMdV*/
#define _SysPwrMdV_Invalid   0x0U
#define _SysPwrMdV_Valid     0x1U

/*CTDSts*/
#define _CTDSts_Disarmed          0x0U
#define _CTDSts_Prearm            0x1U
#define _CTDSts_Partially_Armed   0x2U
#define _CTDSts_FullyArmed        0x3U
#define _CTDSts_In_Alarm          0x4U

/*VehLckSts*/
#define _VehLckSts_Unlock                    0x0U
#define _VehLckSts_Lock                      0x1U
#define _VehLckSts_Driver_Door_Unlock_Only   0x2U
#define _VehLckSts_Lock_Invalid              0x3U

/*BrkPdlSW*/
#define _BrkPdlSW_Brake_Pedal_Switch_No_Pressed    0x0U
#define _BrkPdlSW_Pedal_Switch_Pressed             0x1U

/*BrkPdlSWV*/
#define _BrkPdlSWV_Invalid                    0x0U
#define _BrkPdlSWV_Valid                      0x1U

/*VehCrshTyp*/
#define _VehCrshTyp_No_Crash                   0x0U
#define _VehCrshTyp_Front                      0x1U
#define _VehCrshTyp_Left_Hand_Side             0x2U
#define _VehCrshTyp_Front_and_Left_Hand_Side   0x3U
#define _VehCrshTyp_Right_Hand_Side            0x4U
#define _VehCrshTyp_Front_and_Right_Hand_Side  0x5U

/*VehCrshTypV*/
#define _VehCrshTypV_Invalid                    0x0U
#define _VehCrshTypV_Valid                      0x1U

/*LongtSnsrSts*/
#define _LongtSnsrSts_Invalid                    0x0U
#define _LongtSnsrSts_Valid                      0x1U
#define _Incline_Valid                           0x1U

/*TlgtOprtMdSt*/
#define _TlgtOprtMdSt_No_Request          0x0U
#define _TlgtOprtMdSt_Manual              0x1U
#define _TlgtOprtMdSt_Park                0x2U
#define _TlgtOprtMdSt_Norm                0x3U

/*PLG_MCUDiagSession*/
#define _PLG_MCUDiagSession_Unknow                               0x0U
#define _PLG_MCUDiagSession_DefaultSessioninBoot                 0x1U
#define _PLG_MCUDiagSession_ProgrammingSessionin_Boot_Locked     0x2U
#define _PLG_MCUDiagSession_ProgrammingSessionin_Boot_Unlocked   0x3U
#define _PLG_MCUDiagSession_DefaultSessioninApp                  0x4U
#define _PLG_MCUDiagSession_ExtendedSessioninApp                 0x5U
#define _PLG_MCUDiagSession_ErrorSession                         0x6U
/*TlgtReqUID*/
#define _TlgtReqUID_Default            0x0U
#define _TlgtReqUID_Valid_UID_Found    0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*StallEventSpindle*/
#define _StallEventSpindle_Normal                 0x0U
#define _StallEventSpindle_EnhancedCurrentStall   0x1U
#define _StallEventSpindle_TopLimitCurrentStall   0x2U
#define _StallEventSpindle_HallStall              0x3U
#define _StallEventSpindle_LeftAPSTriggered       0x4U
#define _StallEventSpindle_RightAPSTriggered      0x5U

/*DrAjr_DR*/
/*DrAjr_PR*/
/*DrAjr_RL*/
/*DrAjr_RR*/
#define _DoorSts_Close   0x0U
#define _DoorSts_Open    0x1U

/*WdwDRPos*/
/*WdwPRPos*/
/*WdwRLPos*/
/*WdwRRPos*/
#define _WndwSts_12Percent    0xCU
#define _WndwSts_100Percent    0x64U
#define _WndwSts_Position_Unknown    0x7FU

/*DrAjr_DRV*/
/*DrAjr_PRV*/
/*DrAjr_RLV*/
/*DrAjr_RRV*/
#define _DoorSts_Invalid   0x0U
#define _DoorSts_Valid     0x1U

/*HVACFrontAirVolume*/
/*HVACRearAirVolume*/
#define _HVACAirVolume_0   0x0U
#define _HVACAirVolume_1   0x1U
#define _HVACAirVolume_2   0x2U
#define _HVACAirVolume_3   0x3U
#define _HVACAirVolume_4   0x4U
#define _HVACAirVolume_5   0x5U
#define _HVACAirVolume_6   0x6U
#define _HVACAirVolume_7   0x7U
#define _HVACAirVolume_8   0x8U

/*SRFPos*/
/*PSRPstn*/
#define _SRFSts_12Percent    0xCU
#define _SRFSts_100Percent    0x64U
#define _SRFSts_Position_Unknown    0x7FU

/*PLGDTCTyp*/
#define _PLGDTCTyp_Not_Used   0x0U
#define _PLGDTCTyp_Tpye_A     0x1U
#define _PLGDTCTyp_Tpye_B     0x2U
#define _PLGDTCTyp_Tpye_C     0x3U
#define _PLGDTCTyp_Tpye_D     0x4U
#define _PLGDTCTyp_Tpye_E     0x5U
#define _PLGDTCTyp_Tpye_F     0x6U

#ifdef _MAXUS_COM_PSD
/*SldDrCtrlReq_R*/
/*SldDrCtrlReq_L*/
#define _SldDrCtrlReq_No_request   0x0U
#define _SldDrCtrlReq_Open         0x1U
#define _SldDrCtrlReq_Close        0x2U
#define _SldDrCtrlReq_Hold         0x3U

/*SnsSldDrCtrlReq_R*/
/*SnsSldDrCtrlReq_L*/
#define _SldDrCtrlReq_Not_Active   0x0U
#define _SldDrCtrlReq_Active         0x1U

/*PSD_RInCarCtrlReq_iCGM*/
/*PSD_LInCarCtrlReq_iCGM*/
#define _InCarCtrlReq_iCGM_No_request   0x0U
#define _InCarCtrlReq_iCGM_Open         0x1U
#define _InCarCtrlReq_iCGM_Close        0x2U
#define _InCarCtrlReq_iCGM_Hold         0x3U

/*PSD_ROutsideCarCtrlReq_iCGM*/
/*PSD_LOutsideCarCtrlReq_iCGM*/
#define _OutsideCarCtrlReq_iCGM_No_request   0x0U
#define _OutsideCarCtrlReq_iCGM_Open         0x1U
#define _OutsideCarCtrlReq_iCGM_Close        0x2U
#define _OutsideCarCtrlReq_iCGM_Hold         0x3U

/*SldDrOprtMdSt*/
#define _SldDrOprtMdSt_No_Request   0x0U
#define _SldDrOprtMdSt_Auto         0x1U
#define _SldDrOprtMdSt_Manual       0x2U

/*PSD_LOprtMdCtrlReq_iCGM*/
/*PSD_ROprtMdCtrlReq_iCGM*/
#define _OprtMdCtrlReq_iCGM_No_Request   0x0U
#define _OprtMdCtrlReq_iCGM_Auto         0x1U
#define _OprtMdCtrlReq_iCGM_Manual       0x2U

/*EPBAppcnSts*/
#define _EPBAppcnSts_Undefined    0x0U
#define _EPBAppcnSts_Released     0x1U
#define _EPBAppcnSts_Closed       0x2U
#define _EPBAppcnSts_Releasing    0x3U
#define _EPBAppcnSts_Locking      0x4U

/*SldDrOprtSts_R*/
/*SldDrOprtSts_L*/
#define _SldDrOprtSts_Idle        0x0U
#define _SldDrOprtSts_Opening     0x1U
#define _SldDrOprtSts_Closing     0x2U

/*PSDErrSts_R*/
/*PSDErrSts_L*/
#define _PSDErrSts_Normal        0x0U
#define _PSDErrSts_Error         0x1U

/*SldDrOprtMd_R*/
/*SldDrOprtMd_L*/
#define _SldDrOprtMd_Auto        0x0U
#define _SldDrOprtMd_Manual      0x1U

/*SldDrPosSts_R*/
/*SldDrPosSts_L*/
#define _SldDrPosSts_Status_Unkown     0x0U
#define _SldDrPosSts_Fully_Closed      0x1U
#define _SldDrPosSts_Half_Locked       0x2U
#define _SldDrPosSts_Door_Open         0x3U

/*SldDrLtcSts_R*/
/*SldDrLtcSts_L*/
#define _SldDrLtcSts_Status_Unkown                  0x0U
#define _SldDrLtcSts_Latch_UnLocked                 0x1U
#define _SldDrLtcSts_Latch_HalfLocked               0x2U
#define _SldDrLtcSts_Latch_Cinching                 0x3U
#define _SldDrLtcSts_Latch_Locked                   0x4U
#define _SldDrLtcSts_Latch_Releasing                0x5U
#define _SldDrLtcSts_LatchReseting_After_Cinching   0x6U
#define _SldDrLtcSts_LatchReseting_After_Releasing  0x7U

/*SldDrTchPdSw_R*/
/*SldDrTchPdSw_L*/
#define _SldDrTchPdSw_No_Pressed              0x0U
#define _SldDrTchPdSw_Pressed                 0x1U

/*ChldLckSts_R*/
/*ChldLckSts_L*/
#define _ChldLckSts_Unlock               0x0U
#define _ChldLckSts_Lock                 0x1U

/*SldDrIntSw_R*/
/*SldDrIntSw_L*/
#define _SldDrIntSw_Not_Pressed          0x0U
#define _SldDrIntSw_Open                 0x1U
#define _SldDrIntSw_Close                0x2U

/*SldDrDrSw_R*/
/*SldDrDrSw_L*/
#define _SldDrDrSw_No_Pressed          0x0U
#define _SldDrDrSw_Pressed             0x1U

/*SldDrLckSts_R*/
/*SldDrLckSts_L*/
#define _SldDrLckSts_Status_Unknown         0x0U
#define _SldDrLckSts_Locked                 0x1U
#define _SldDrLckSts_Unlocked               0x2U

/*PSDObsSts_R*/
/*PSDObsSts_L*/
#define _PSDObsSts_Normal         0x0U
#define _PSDObsSts_Pinch          0x1U
#define _PSDObsSts_Stall          0x2U

/*SldDrAbsAlrm_R*/
/*SldDrAbsAlrm_L*/
#define _SldDrAbsAlrm_No_Abuse         0x0U
#define _SldDrAbsAlrm_Abuse_1          0x1U
#define _SldDrAbsAlrm_Abuse_2          0x2U
#define _SldDrAbsAlrm_Abuse_3          0x3U



#endif
#endif

#ifdef _FAW_COM
/*VehicleSpeed_Valid*/
#define _SPEED_INVALID       0x0U
#define _SPEED_VALID         0x1U
/*VehicleEngine_Valid*/
#define _ENGINE_INVALID       0x0U
#define _ENGINE_VALID         0x1U
/*Odometer_Valid*/
#define _ODOMETER_INVALID       0x0U
#define _ODOMETER_VALID         0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

/*VehicleLockUnlock*/
#define _DOOR_UNLOCK     0x0U
#define _DOOR_LOCK       0x1U

/*VehicleGearLever*/
#define _POSITION_P         0x0U
#define _POSITION_D         0x5U
#define _POSITION_N         0x6U
#define _POSITION_R         0x7U
#define _POSITION_M         0x8U

/*SystemPowerMode*/
#define _POWER_MODE_OFF            0x0U
#define _POWER_MODE_RECENTLY_OFF   0x1U
#define _POWER_MODE_IGNITION_ON    0x4U
#define _POWER_MODE_RUNNING        0x5U
#define _POWER_MODE_PAUSE_RUNNING  0x6U
#define _POWER_MODE_RESTARTING     0x7U
#define _POWER_MODE_CRANK          0x8U

/*LuggageDoorCtrCmd*/
#define _LuggageDoorCtrCmd_Inactive   0x0U
#define _LuggageDoorCtrCmd_Close      0x1U
#define _LuggageDoorCtrCmd_Open       0x2U
#define _LuggageDoorCtrCmd_Stop       0x3U

/*LuggageDoorPreviousMovement*/
#define _LuggageDoorPreviousMovement_Inactive    0x0U
#define _LuggageDoorPreviousMovement_Closing     0x1U
#define _LuggageDoorPreviousMovement_Opening     0x2U

/*LuggageLockSt*/
#define _LuggageLockSt_Lock     0x0U
#define _LuggageLockSt_Unlock   0x1U

/*LuggageDoorSt*/
#define _LuggageDoorSt_Close      0x0U
#define _LuggageDoorSt_Open       0x1U

/*LuggageSwitch_Inside*/
#define _LuggageSwitch_Inside_Not_Pressed   0x0U
#define _LuggageSwitch_Inside_Pressed       0x1U

/*LuggageDoorWorkingSt*/
#define _LuggageDoorWorkingSt_Unknown   0x0U
#define _LuggageDoorWorkingSt_Top       0x1U
#define _LuggageDoorWorkingSt_Hovering  0x2U
#define _LuggageDoorWorkingSt_Bottom    0x3U
#define _LuggageDoorWorkingSt_Upping    0x4U
#define _LuggageDoorWorkingSt_Downing   0x5U

/*DoorSt_FL*/
/*DoorSt_FR*/
/*DoorSt_RL*/
/*DoorSt_RR*/
#define _DoorSt_Close      0x0U
#define _DoorSt_Open       0x1U

/*DoorWindowSt_FL*/
/*DoorWindowSt_FR*/
/*DoorWindowSt_RL*/
/*DoorWindowSt_RR*/
#define _DoorWindowSt_Unknown       0x0U
#define _DoorWindowSt_Top           0x1U
#define _DoorWindowSt_Middle        0x2U
#define _DoorWindowSt_Bottom        0x3U
#define _DoorWindowSt_Ventilation   0x4U

/*SunroofSt*/
#define _SunroofSt_FullClosed                   0x0U
#define _SunroofSt_BetweenClosedAndTitle        0x1U
#endif



#ifdef _CHANGAN_COM
/*BCM_PowerStatusFeedback*/
#define _POWER_STATUS_OFF   0x0U
#define _POWER_STATUS_ACC   0x1U
#define _POWER_STATUS_ON    0x2U
#define _POWER_STATUS_START 0x3U

/*BCM_DriverDoorLockStatus*/
#define _DRIVER_DOOR_LOCK     0x0U
#define _DRIVER_DOOR_UNLOCK   0x1U
#define _DRIVER_DOOR_NOTUSED  0x2U
#define _DRIVER_DOOR_ERROR    0x3U

/*BCM_KeyAlarmStatus*/
#define _KEY_ALARM_DISARMED   0x0U
#define _KEY_ALARM_PREARMED   0x1U
#define _KEY_ALARM_ARMED      0x2U
#define _KEY_ALARM_ACTIVATED  0x3U

/*ESP_VehicleSpeed_1*/
#define _SPEED_VALID         0x0U
#define _SPEED_INVALID       0x1U

/*VehicleSpeed_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x0U
#define _ODOMETER_INVALID       0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U


/*AC_EnvironmentalTemp*/
#define _TEMP_VALID         0x0U
#define _TEMP_INVALID       0x1U

/*TCU_GearShiftPositon*/
#define _GEAR_SHIFT_PARKING    0x0U
#define _GEAR_SHIFT_REVERSE    0x1U
#define _GEAR_SHIFT_NEUTRAL    0x2U
#define _GEAR_SHIFT_D          0x3U
#define _GEAR_SHIFT_D3         0x4U
#define _GEAR_SHIFT_D2         0x5U
#define _GEAR_SHIFT_L          0x6U
#define _GEAR_SHIFT_MS         0x7U

/*TCU_ShiftPostionValid*/
#define _GEAR_SHIFT_VALID         0x0U
#define _GEAR_SHIFT_INVALID       0x1U

/*TBOX_RmoteTrunk*/
#define _TBOX_REMOTETRUNK_NO_REQUEST    0x0U
#define _TBOX_REMOTETRUNK_CLOSE         0x1U
#define _TBOX_REMOTETRUNK_OPEN          0x2U

/*HU_BackDoorSwitch*/
#define _HU_BACK_DOOR_SWITCH_INACTIVE    0x0U
#define _HU_BACK_DOOR_SWITCH_PRESS       0x1U

/*PEPS_Easy_open*/
#define _PEPS_EASY_OPEN_NO_COMMAND    0x0U
#define _PEPS_EASY_OPEN_ACTIVE        0x1U

/*PEPS_LuggageUnlockSignal*/
#define _PEPS_LUGGAGE_UNLOCK_SIGNAL_INACTIVE    0x0U
#define _PEPS_LUGGAGE_UNLOCK_SIGNAL_REMOTE_KEY  0x1U
#define _PEPS_LUGGAGE_UNLOCK_SIGNAL_PE          0x2U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

typedef enum
{
   BuzzerStatus_Silent = 0,      /*0U*/
   BuzzerStatus_Beep_1,          /*1U*/
   BuzzerStatus_Beep_2,          /*2U*/
   BuzzerStatus_Beep_3,          /*3U*/
   BuzzerStatus_Beep_4           /*4U*/
}tD_BuzzerStatus;

typedef enum
{
   ApsStatus_Normal = 0,      /*0U*/
   ApsStatus_Press,           /*1U*/
   ApsStatus_OpenCircuit,     /*2U*/
   ApsStatus_Adhesion,        /*3U*/
   ApsStatus_Abnormal         /*4U*/
}tD_ApsStatus;

typedef enum
{
   AbuseMode_NoAbuse = 0,               /*0U*/
   AbuseMode_Abuse1_SpeedPark = 0,      /*1U*/
   AbuseMode_Abuse2_BattVoltage,        /*2U*/
   AbuseMode_Abuse3_APS,                /*3U*/
   AbuseMode_Abuse4                     /*4U*/
}tD_AbuseMode;

typedef enum
{
   GarageLearn_NoAction = 0,        /*0U*/
   GarageLearn_Action               /*1U*/
}tD_GarageLearn;

typedef enum
{
   Unknown = 0,      /*0U*/
   FullyOpened,      /*1U*/
   FullyClosed,      /*2U*/
   Opening,          /*3U*/
   Closing,          /*4U*/
   Stop             /*5U*/
   
}tD_GateMotion;

typedef enum
{
   Default = 0,      /*0U*/
   Cinching,         /*1U*/
   Cinched,          /*2U*/
   Releasing,        /*3U*/
   Released          /*4U*/
   
}tD_LatchMotion;

/*TboxRemLgUnlckReq*/
#define _TboxRemLgUnlckReq_No_Request    0x0U
#define _TboxRemLgUnlckReq_Open          0x1U
#define _TboxRemLgUnlckReq_Close         0x2U

/*CdcTrDoorOpenReq*/
#define _CdcTrDoorOpenReq_inactive    0x0U
#define _CdcTrDoorOpenReq_On          0x1U
#define _CdcTrDoorOpenReq_Off         0x2U
#endif

#ifdef _DEARCC_COM
/*VehicleGearLever*/
#define _GEAR_LEVER_P         0x0U
#define _GEAR_LEVER_R         0x1U
#define _GEAR_LEVER_N         0x2U
#define _GEAR_LEVER_D         0x3U
#define _GEAR_LEVER_INVALID   0x7U

/*VehicleSpeed_Valid*/
#define _SPEED_VALID         0x0U
#define _SPEED_INVALID       0x1U

/*VehicleEngine_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x0U
#define _ODOMETER_INVALID       0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

 
/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*SystemPowerMode*/
#define _POWER_MODE_OFF   0x0U
#define _POWER_MODE_ACC   0x1U
#define _POWER_MODE_ON    0x2U
#define _POWER_MODE_START 0x3U

/*DoorSts*/
#define _DOOR_DEFAULT      0x0U
#define _DOOR_OPEN         0x1U
#define _DOOR_CLOSED       0x2U
#define _DOOR_INVALID      0x3U

/*RxPLGMode*/
#define _PLGMODE_REQUEST_DEFAULT     0x0U
#define _PLGMODE_REQUEST_NORMAL      0x1U
#define _PLGMODE_REQUEST_GARAGE      0x2U
#define _PLGMODE_REQUEST_MANUAL      0x3U
#define _PLGMODE_REQUEST_RESERVED    0x4U

/*RxPLGMode*/
#define _PLGMODE_NORMAL      0x0U
#define _PLGMODE_GARAGE      0x1U
#define _PLGMODE_MANUAL      0x2U
#define _PLGMODE_RESERVED    0x3U


/*VehicleLockUnlock*/
#define _DOOR_UNLOCK     0x1U
#define _DOOR_LOCK       0x2U
#define _DOOR_INVALID    0x3U

/*HU_PLGControl*/
#define _HU_PLG_NO_REQUEST          0x0U
#define _HU_PLG_OPEN_REQUEST        0x1U
#define _HU_PLG_CLOSE_REQUEST       0x2U
#define _HU_PLG_STOP_REQUEST        0x3U

/*TBOX_PLG_TrunkunLock*/
#define _TBOX_PLG_DEFAULT    0x0U
#define _TBOX_PLG_UNLOCK     0x1U
#define _TBOX_PLG_LOCK       0x2U
#define _TBOX_PLG_INVALID    0x3U

/*TBOX_PLG_OpenControl*/
#define _TBOX_PLG_DEFAULT    0x0U
#define _TBOX_PLG_OPEN       0x1U
#define _TBOX_PLG_CLOSE      0x2U


/*PEPS_RKECommand*/
#define _RKE_NO_COMMAND      0x0U
#define _RKE_DOOR_UNLOCK     0x2U
#define _RKE_DOOR_LOCK       0x3U
#define _RKE_TRUNK_UNLOCK    0x4U

/*PEPS_DoorUnlockReq*/
#define _PEPS_NO_REQUEST    0x0U
#define _PEPS_REQUEST_1     0x1U
#define _PEPS_REQUEST_2     0x2U
#define _PEPS_REQUEST_3     0x3U

/*PLG_OpenAngValid*/
#define _OPEN_ANG_VALID         0x0U
#define _OPEN_ANG_INVALID       0x1U

/*HU_PLGGaragePosition*/
#define _GARAGE_POSITION_30    0x1U
#define _GARAGE_POSITION_40    0x2U
#define _GARAGE_POSITION_50    0x3U
#define _GARAGE_POSITION_60    0x4U
#define _GARAGE_POSITION_70    0x5U
#define _GARAGE_POSITION_80    0x6U
#define _GARAGE_POSITION_90    0x7U
#define _GARAGE_POSITION_100    0x8U


typedef enum
{
   PLG_Unknown = 0,      /*0U*/
   Fully_Opened,         /*1U*/
   Fully_Closed,         /*2U*/
   Opening,              /*3U*/
   Closing,              /*4U*/
   PLG_Stopped,          /*5U*/
   Latch_Releasing,      /*6U*/
   Latch_Cinching        /*7U*/  
}tD_GateMotion;

/*Fault*/
#define _OK                0x0U
#define _SHORT_GROUND      0x1U
#define _SHORT_BATTERY     0x2U
#define _SIGNAL_INVALID    0x3U

/*BCM_AntiThelf_Sts*/
#define _ANTITHEFT_DISARMED   0x0U
#define _ANTITHEFT_ARM        0x1U
#define _ANTITHEFT_PREARM     0x2U
#define _ANTITHEFT_WARNING    0x3U

/*BCM_DriverLock_Sts*/
#define _DRIVERLOCK_DEFAULT     0x0U
#define _DRIVERLOCK_UNLOCK      0x1U
#define _DRIVERLOCK_LOCK        0x2U
#define _DRIVERLOCK_INVALID     0x3U

typedef enum
{
    No_Condition_Fault = 0,      /*0U*/
    PinchIsTriggered,            /*1U*/
    VehicleSpeedIsHigh,          /*2U*/
    VehicleIsLocked,             /*3U*/
    BatteryVoltageIsOutofRange,  /*4U*/
    PlayOffIsTriggered,          /*5U*/   
    PowerFunctionIsDisable,             /*6U*/
    EnvironmentTemperatureIsOutofRange  /*7U*/   
    
} tD_PLGConditionFault;	
#endif

#ifdef _XIAOPENG_COM
/*SRS_CrashOutputSt*/

/*iBCM_PowerMode*/
#define _POWER_MODE_OFF           0x0U
#define _POWER_MODE_ON            0x1U
#define _POWER_MODE_NOT_USED_2    0x2U
#define _POWER_MODE_NOT_USED_3    0x3U

/*iBCM_DriverDoorLockSt*/
#define _DOOR_UNLOCK     0x0U
#define _DOOR_LOCK       0x1U

/*iBCM_AlarmSt*/
#define _iBCM_AlarmSt_Armed       0x0U
#define _iBCM_AlarmSt_Prearmed    0x1U
#define _iBCM_AlarmSt_Disarmed    0x2U
#define _iBCM_AlarmSt_Alam        0x3U

/*iBCM_SCU_ForwardKeySt*/
/*iBCM_SCU_BackwardKeySt*/
#define _KEY_NOT_ACTIVE      0x0U
#define _KEY_SINGLE_CLICK    0x1U
#define _KEY_DOUBLE_CLICK    0x2U
#define _KEY_LONG_PRESS      0x3U

/*SDCL_CDU_KeyOpenModeCtrlCfgFB*/
/*SDCR_CDU_KeyOpenModeCtrlCfgFB*/
/*SDCL_CDU_KeyCloseModeCtrlCfgFB*/
/*SDCR_CDU_KeyCloseModeCtrlCfgFB*/
#define _KeyModeCtrlCfgFB_Driver_Door    0x0U
#define _KeyModeCtrlCfgFB_Front_Door     0x1U

/*SDCL_CloseRes*/
/*SDCR_CloseRes*/
#define _CloseRes_No_Command                0x0U
#define _CloseRes_Follow_down               0x1U
#define _CloseRes_outdoorSW_shortpress      0x3U
#define _CloseRes_IndoorcloseSW_longpress   0x4U
#define _CloseRes_IndoorcloseSW_shortpress  0x5U
#define _CloseRes_RKEclose_longpress        0x6U
#define _CloseRes_RKEclose_doublepress      0x7U
#define _CloseRes_CDU_AutocloseSW           0x8U
#define _CloseRes_CDU_ManualcloseSW         0x9U
#define _CloseRes_APP_4G_AutocloseSW        0xaU
#define _CloseRes_APP_4G_ManualcloseSW      0xbU
#define _CloseRes_APP_BLE_AutocloseSW       0xcU
#define _CloseRes_APP_BLE_ManualcloseSW     0xdU
#define _CloseRes_Brkpedal                  0xeU
#define _CloseRes_SCU                       0xfU

/*SDCL_OPenRes*/
/*SDCR_OPenRes*/
#define _OPenRes_No_Command                0x0U
#define _OPenRes_mechanical_handle         0x1U
#define _OPenRes_outdoorSW_longpress       0x2U
#define _OPenRes_outdoorSW_shortpress      0x3U
#define _OPenRes_IndooropenSW_longpress   0x4U
#define _OPenRes_IndooropenSW_shortpress  0x5U
#define _OPenRes_RKEopen_longpress        0x6U
#define _OPenRes_RKEopen_doublepress      0x7U
#define _OPenRes_CDU_AutoopenSW           0x8U
#define _OPenRes_CDU_ManualopenSW         0x9U
#define _OPenRes_APP_4G_AutoopenSW        0xaU
#define _OPenRes_APP_4G_ManualopenSW      0xbU
#define _OPenRes_APP_BLE_AutoopenSW       0xcU
#define _OPenRes_APP_BLE_ManualopenSW     0xdU
#define _OPenRes_Follow_up                0xeU
#define _OPenRes_SCU                      0xfU

/*DID 0x0320 TriggerSource*/
#define _TriggerSource_No_Command                 0x0U
#define _TriggerSource_mechanical_handle          0x1U
#define _TriggerSource_outdoorSW_longpress        0x2U
#define _TriggerSource_outdoorSW_shortpress_Open  0x3U
#define _TriggerSource_IndooropenSW_longpress     0x4U
#define _TriggerSource_IndooropenSW_shortpress    0x5U
#define _TriggerSource_RKEopen_longpress          0x6U
#define _TriggerSource_RKEopen_doublepress        0x7U
#define _TriggerSource_CDU_AutoopenSW             0x8U
#define _TriggerSource_CDU_ManualopenSW           0x9U
#define _TriggerSource_APP_4G_AutoopenSW          0xaU
#define _TriggerSource_APP_4G_ManualopenSW        0xbU
#define _TriggerSource_APP_BLE_AutoopenSW         0xcU
#define _TriggerSource_APP_BLE_ManualopenSW       0xdU

#define _TriggerSource_outdoorSW_shortpress_Close 0xeU
#define _TriggerSource_IndoorcloseSW_longpress    0xfU
#define _TriggerSource_IndoorcloseSW_shortpress   0x10U
#define _TriggerSource_RKEclose_longpress         0x11U
#define _TriggerSource_RKEclose_doublepress       0x12U
#define _TriggerSource_CDU_AutocloseSW            0x13U
#define _TriggerSource_CDU_ManualcloseSW          0x14U
#define _TriggerSource_APP_4G_AutocloseSW         0x15U
#define _TriggerSource_APP_4G_ManualcloseSW       0x16U
#define _TriggerSource_APP_BLE_AutocloseSW        0x17U
#define _TriggerSource_APP_BLE_ManualcloseSW      0x18U
#define _TriggerSource_Brkpedal                   0x19U

#define _TriggerSource_Follow_up                  0x1aU
#define _TriggerSource_Follow_down                0x1bU

#define _TriggerSource_SCU_AutoopenSW             0x1cU
#define _TriggerSource_SCU_ManualopenSW           0x1dU
#define _TriggerSource_SCU_AutocloseSW            0x1eU
#define _TriggerSource_SCU_ManualcloseSW          0x1fU

/*ESP_VehSpdVD*/
#define _VehSpdVD_Not_Initialized      0x0U
#define _SPEED_VALID                   0x1U
#define _SPEED_INVALID                 0x2U

/*VCU_EVSysReadySt*/
#define _EVSysReadySt_Not_ready         0x0U
#define _EVSysReadySt_High_Voltage_On   0x1U
#define _EVSysReadySt_Ready             0x2U

/*VCU_GearLev*/
#define _GearLev_Invalid        0x0U
#define _GearLev_D_gear         0x1U
#define _GearLev_N_gear         0x2U
#define _GearLev_R_gear         0x3U
#define _GearLev_P_gear         0x4U

/*SCU_iBCM_CurMode*/
#define _iBCM_CurMode_Invalid                         0x0U
#define _iBCM_CurMode_auto_drive_mode_enter_success   0x1U
#define _iBCM_CurMode_auto_drive_mode_enter_fail      0x2U

/*SCU_SDC_LDoorOpreration*/
/*SCU_SDC_RDoorOpreration*/
#define _DoorOpreration_NO_COMMAND   0x0U
#define _DoorOpreration_STOP         0x1U
#define _DoorOpreration_MOVE         0x2U

/*SCU_SDC_LDoorDetection*/
/*SCU_SDC_RDoorDetection*/
#define _DoorDetection_No_Command     0x0U
#define _DoorDetection_Danger         0x1U
#define _DoorDetection_Safety         0x2U


/*SCU_SDC_LRadarSts*/
/*SCU_SDC_RRadarSts*/
#define _RadarSts_normal   0x0U
#define _RadarSts_fault    0x1U

/*CDU_SDCL_Sw*/
/*CDU_SDCR_Sw*/
/*TBOX_SDCLSw*/
/*TBOX_SDCRSw*/
/*TBOX_BLESDCLSw*/
/*TBOX_BLESDCRSw*/
#define _Sw_No_command    0x0U
#define _Sw_Auto_Close    0x1U
#define _Sw_Auto_Open     0x2U
#define _Sw_Stop          0x3U
#define _Sw_Manual_Close  0x4U
#define _Sw_Manual_Open   0x5U

/*CDU_SDC_KeyOpenModeCtrlCfg*/
/*CDU_SDC_KeyCloseModeCtrlCfg*/
#define _KeyModeCtrlCfg_No_Command    0x0U
#define _KeyModeCtrlCfg_Driver_Door   0x1U
#define _KeyModeCtrlCfg_Front_Door    0x2U

/*VCU_BrkPedalSt*/
#define _VCU_BrkPedalSt_Not_Pressed    0x0U
#define _VCU_BrkPedalSt_Pressed        0x1U

/*VCU_BrkPedalStVD*/
#define _VCU_BrkPedalStVD_Not_Valid    0x0U
#define _VCU_BrkPedalStVD_Valid        0x1U

/*ICM_TotalOdometerVD*/
#define _TotalOdometerVD_Not_Valid    0x0U
#define _TotalOdometerVD_Valid        0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*ESP_VehSpdVD*/
#define _VehSpdVD_Not_Initialized      0x0U
#define _SPEED_VALID                   0x1U
#define _SPEED_INVALID                 0x2U
/*VehicleEngine_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x1U
#define _ODOMETER_INVALID       0x0U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

/*iBCM_DriverDoorAjarSt*/
/*iBCM_PsngrDoorAjarSt*/
/*iBCM_RLDoorAjarSt*/
/*iBCM_RRDoorAjarSt*/
/*iBCM_TrunkAjarSt*/
#define _Door_Closed     0x0U
#define _Door_Open       0x1U

/*iBCM_FLWinPosStFB*/
/*iBCM_FRWinPosStFB*/
/*iBCM_RLWinPosStFB*/
/*iBCM_RRWinPosStFB*/
#define _WinPosStFB_10Percent     0x14U
#define _WinPosStFB_30Percent     0x3CU
#define _WinPosStFB_40Percent     0x50U
#define _WinPosStFB_100Percent    0xC8U
#define _WinPosStFB_Invalid       0xFFU

/*CDU_SDCCloseSpdCfg*/
#define _SDCCloseSpdCfg_No_command    0x0U
#define _SDCCloseSpdCfg_Spd_1         0x1U
#define _SDCCloseSpdCfg_Spd_2         0x2U
#define _SDCCloseSpdCfg_Spd_3         0x3U
#define _SDCCloseSpdCfg_Spd_4         0x4U
#define _SDCCloseSpdCfg_Spd_5         0x5U
#define _SDCCloseSpdCfg_Spd_6         0x6U

/*SDCL_PSDMotorSt*/
/*SDCR_PSDMotorSt*/
#define _PSDMotorSt_Not_Move        0x0U
#define _PSDMotorSt_Opening         0x1U
#define _PSDMotorSt_Closing         0x2U
#define _PSDMotorSt_Hovering        0x3U

/*SDCL_DoorStatus*/
/*SDCR_DoorStatus*/
#define _DoorStatus_Closed        0x0U
#define _DoorStatus_Opened        0x1U

/*SDCL_CloserMotorSt*/
/*SDCR_CloserMotorSt*/
#define _CloserMotorSt_Not_Move      0x0U
#define _CloserMotorSt_Opening        0x1U
#define _CloserMotorSt_Closing        0x2U

/*SDCL_ReleaseLockMotorSt*/
/*SDCR_ReleaseLockMotorSt*/
#define _ReleaseLockMotorSt_Not_Move        0x0U
#define _ReleaseLockMotorSt_Releasing       0x1U
#define _ReleaseLockMotorSt_Closing         0x2U

/*SDCL_HazzardReq*/
/*SDCR_HazzardReq*/
#define _HazzardReq_No_Command       0x0U
#define _HazzardReq_Request_1        0x1U
#define _HazzardReq_Request_2        0x2U
#define _HazzardReq_Request_3        0x3U

#define _GARAGE_HEIGHT_0_DEGREE      0x00
#define _GARAGE_HEIGHT_100_DEGREE    0x64

/*SDCL_SysRuningSt*/
/*SDCR_SysRuningSt*/
#define _SysRuningSt_Initial               0x0U
#define _SysRuningSt_Closed                0x1U
#define _SysRuningSt_Opening               0x2U
#define _SysRuningSt_Closing               0x3U
#define _SysRuningSt_Pause                 0x4U
#define _SysRuningSt_Open_finished         0x5U
#define _SysRuningSt_Prevent_playing_mode  0x6U
#define _SysRuningSt_Lock_status_error     0x7U

/*SDCL_PSDMotorFR*/
/*SDCR_PSDMotorFR*/
#define _PSDMotorFR_No_Error               0x0U
#define _PSDMotorFR_Hall_Error             0x1U
#define _PSDMotorFR_Overtime_Error         0x2U
#define _PSDMotorFR_Stall_Error            0x3U
#define _PSDMotorFR_PSDMotor_Error         0x4U
#define _PSDMotorFR_Overheating_Error      0x5U
#define _PSDMotorFR_CloseMotor_Error       0x6U
#define _PSDMotorFR_AntipintchSt_Error     0x7U

/*SDCL_CloserMotorFR*/
/*SDCR_CloserMotorFR*/
#define _CloserMotorFR_No_Error               0x0U
#define _CloserMotorFR_Abnormal_Open_Error    0x1U
#define _CloserMotorFR_Overtime_Error         0x2U
#define _CloserMotorFR_Stall_Error            0x3U
#define _CloserMotorFR_CloserMotor_Error      0x4U

/*SDCL_ReleaseLockMotorFR*/
/*SDCR_ReleaseLockMotorFR*/
#define _ReleaseLockMotorFR_No_Error               0x0U
#define _ReleaseLockMotorFR_ReleaseLockMotor_Error    0x1U
#define _ReleaseLockMotorFR_Overtime_Error         0x2U
#define _ReleaseLockMotorFR_Stall_Error            0x3U
#endif



#ifdef _AUDI_COM
#ifdef _AUDI_COM_PD
/*CAN*/
/*Rx*/
/*REDS_SysState*/
#define REDS_SysState_STANDBY             0x00U
#define REDS_SysState_FAST_MEASUREMENT    0x01U
#define REDS_SysState_SLOW_MEASUREMENT    0x02U
#define REDS_SysState_DEGRADED            0x03U
#define REDS_SysState_FAULT               0x04U
#define REDS_SysState_DIAGNOSE_MODE       0x05U

/*REDS_WarningOvertemp*/
#define REDS_WarningOvertemp_NO_WARNING   0x00U
#define REDS_WarningOvertemp_WARNING      0x01U

/*REDS_WarningVoltage*/
#define REDS_WarningVoltage_NO_WARNING   0x00U
#define REDS_WarningVoltage_WARNING      0x01U

/*REDS_FaultOvervoltage*/
#define REDS_FaultOvervoltage_NO_FAULT   0x00U
#define REDS_FaultOvervoltage_FAULT      0x01U

/*REDS_FaultUndervoltage*/
#define REDS_FaultUndervoltage_NO_FAULT   0x00U
#define REDS_FaultUndervoltage_FAULT      0x01U

/*REDS_FaultRamFault*/
#define REDS_FaultRamFault_NO_FAULT   0x00U
#define REDS_FaultRamFault_FAULT      0x01U

/*REDS_FaultOvertemp*/
#define REDS_FaultOvertemp_NO_FAULT   0x00U
#define REDS_FaultOvertemp_FAULT      0x01U

/*REDS_FaultCalibData*/
#define REDS_FaultCalibData_NO_FAULT   0x00U
#define REDS_FaultCalibData_FAULT      0x01U

/*REDS_FaultFunctionDegrad*/
#define REDS_FaultFunctionDegrad_NO_FAULT   0x00U
#define REDS_FaultFunctionDegrad_FAULT      0x01U

/*REDS_FaultIndicator7*/
#define REDS_FaultIndicator7_NO_FAULT   0x00U
#define REDS_FaultIndicator7_FAULT      0x01U

/*REDS_FaultIndicator8*/
#define REDS_FaultIndicator8_NO_FAULT   0x00U
#define REDS_FaultIndicator8_FAULT      0x01U


/*Tx*/
/*SDD_DoorMovement*/
#define SDD_DoorMovement_STANDSTILL_CLOSED       0x00U
#define SDD_DoorMovement_STANDSTILL_NOT_CLOSED   0x01U
#define SDD_DoorMovement_MOVE_ELEC_OPEN          0x02U
#define SDD_DoorMovement_MOVE_ELEC_CLOSE         0x03U
#define SDD_DoorMovement_MOVE_MAN_OPEN           0x04U
#define SDD_DoorMovement_MOVE_MAN_CLOSE          0x05U

/*SDD_ReqREDSMode*/
#define SDD_ReqREDSMode_STANDBY                0x00U
#define SDD_ReqREDSMode_FAST_MEASUREMENT       0x01U
#define SDD_ReqREDSMode_SLOW_MEASUREMENT       0x02U
#define SDD_ReqREDSMode_SLEEP                  0x03U

/*SDD_DoorAddress*/
#define SDD_DoorAddress_FL     0x00U
#define SDD_DoorAddress_FR     0x01U
#define SDD_DoorAddress_RL     0x02U
#define SDD_DoorAddress_RR     0x03U

/*LIN*/
/*Rx*/
/*MasterCmd_TargetPosOpening*/
#define MasterCmd_TargetPosOpening_100Pecent  0xC8U
#define MasterCmd_TargetPosOpening_Invalid    0xFFU

/*MasterCmd_LimitPosition*/
/*MasterCmd_MovingSpeed*/
/*MasterCmd_ServoSupportLevel*/
/*MasterCmd_CurrentLimit*/

/*MasterCmd_ElecMvmntRelease*/
#define MasterCmd_ElecMvmntRelease_disable  0x00U
#define MasterCmd_ElecMvmntRelease_enable   0x01U

/*MasterCmd_ServoRelease*/
#define MasterCmd_ServoRelease_disable  0x00U
#define MasterCmd_ServoRelease_enable   0x01U

/*MasterCmd_HoldRelease*/
#define MasterCmd_HoldRelease_disable  0x00U
#define MasterCmd_HoldRelease_enable   0x01U

/*MasterCmd_AntitrapRequest*/
/*MasterCmd_AnticollisionRequest*/

/*MasterCmd_LatchPrerest*/
#define MasterCmd_LatchPrerest_Inactive  0x00U
#define MasterCmd_LatchPrerest_Active    0x01U
/*MasterCmd_LatchMainrest*/
#define MasterCmd_LatchMainrest_Inactive  0x00U
#define MasterCmd_LatchMainrest_Active    0x01U

/*MasterCmd_LatchLockState*/
#define MasterCmd_LatchLockState_unlocked            0x00U
#define MasterCmd_LatchLockState_locked              0x01U
#define MasterCmd_LatchLockState_doublelocked_safed  0x02U
/*MasterCmd_ChildLockState*/
#define MasterCmd_ChildLockState_childlock_inactive  0x00U
#define MasterCmd_ChildLockState_childlock_active    0x01U

/*MasterCmd_DoorCmd*/
#define MasterCmd_DoorCmd_no_cmd                   0x00U
#define MasterCmd_DoorCmd_SupervisedOpenCmd        0x01U
#define MasterCmd_DoorCmd_SupervisedCloseCmd       0x02U
#define MasterCmd_DoorCmd_AutoOpenCmd              0x03U
#define MasterCmd_DoorCmd_AutoCloseCmd             0x04U
#define MasterCmd_DoorCmd_HardHoldActivationCmd    0x05U
#define MasterCmd_DoorCmd_HardHoldDeactivationCmd  0x06U
#define MasterCmd_DoorCmd_StopMoveElecCmd          0x07U
#define MasterCmd_DoorCmd_UnlatchCmd               0x08U
#define MasterCmd_DoorCmd_ShortStrokeCmd           0x09U
#define MasterCmd_DoorCmd_EnterServoOpenCmd        0x0aU
#define MasterCmd_DoorCmd_EnterServoCloseCmd       0x0bU
#define MasterCmd_DoorCmd_tbd12                    0x0cU
#define MasterCmd_DoorCmd_tbd13                    0x0dU
#define MasterCmd_DoorCmd_tbd14                    0x0eU
#define MasterCmd_DoorCmd_EmergencyStopCmd         0x0fU

/*MasterCmd_TargetPosClosing*/
#define MasterCmd_TargetPosClosing_100Pecent  0xC8U
#define MasterCmd_TargetPosClosing_Invalid    0xFFU

/*VehStatus_VehRollAngle*/
/*VehStatus_VehPitchAngle*/

/*VehStatus_VehAbsSpeed*/
#define VehStatus_VehAbsSpeed_Invalid     0xFFU
/*VehStatus_VehAmbientTemp*/
#define VehStatus_VehAmbientTemp_Invalid  0xFFU

/*VehStatus_VehCrankState*/
/*VehStatus_CrashState*/
/*VehStatus_IllumIntensity*/

/*InclInfoFromGWtoSDD_RollAngleValidF*/
#define InclInfoFromGWtoSDD_RollAngleValidF_Valid    0x00U
#define InclInfoFromGWtoSDD_RollAngleValidF_Invalid  0x01U
/*InclInfoFromGWtoSDD_RollAngle*/
/*InclInfoFromGWtoSDD_PitchAngleValidF*/
#define InclInfoFromGWtoSDD_PitchAngleValidF_Valid    0x00U
#define InclInfoFromGWtoSDD_PitchAngleValidF_Invalid  0x01U
/*InclInfoFromGWtoSDD_PitchAngle*/


/*Tx*/
/*DduStatus_StopNotif*/
#define DduStatus_StopNotif_NoStop             0U             
#define DduStatus_StopNotif_StopCmd            1U         
#define DduStatus_StopNotif_FuncReleaseOff     2U  
#define DduStatus_StopNotif_MotionProhibited   3U  
#define DduStatus_StopNotif_VehSpeedAboveLim   4U  
#define DduStatus_StopNotif_Crash              5U
#define DduStatus_StopNotif_ChildLock          6U      
#define DduStatus_StopNotif_LatchLocked        7U      
#define DduStatus_StopNotif_PosRangeMismatch   8U   
#define DduStatus_StopNotif_CrankTimeout       9U  
#define DduStatus_StopNotif_UserInteraction    10U   
#define DduStatus_StopNotif_AntiCollision      11U   
#define DduStatus_StopNotif_AntiTrap           12U 
#define DduStatus_StopNotif_ThermoProt         13U      
#define DduStatus_StopNotif_DoorMotStall       14U   
#define DduStatus_StopNotif_DoorMotTimeout     15U  
#define DduStatus_StopNotif_PosSensorFault     16U 
#define DduStatus_StopNotif_DoorMotHallFault   17U   
#define DduStatus_StopNotif_DoorMotFault       18U   
#define DduStatus_StopNotif_LatchFault         19U 
#define DduStatus_StopNotif_LatchNotReached    20U 
#define DduStatus_StopNotif_DenormPosInvalid   21U     
#define DduStatus_StopNotif_BusFault           22U  
#define DduStatus_StopNotif_FuncDisabled       23U 
#define DduStatus_StopNotif_ParamSetInvalid    24U
#define DduStatus_StopNotif_MemFault           25U  
#define DduStatus_StopNotif_TargetPosReached   26U 
#define DduStatus_StopNotif_TargetPosInvalid   27U  
#define DduStatus_StopNotif_DiagMode           28U 
#define DduStatus_StopNotif_RadarFault         29U
#define DduStatus_StopNotif_VehSpeedUnknown    30U
#define DduStatus_StopNotif_VehInclUnknown     31U
#define DduStatus_StopNotif_AmbTempUnknown     32U
#define DduStatus_StopNotif_LatchOpenFault     33U
#define DduStatus_StopNotif_EolDataInvalid     34U
#define DduStatus_StopNotif_DenormLatchFault   35U
#define DduStatus_StopNotif_DenormSensorVoltageRange   36U
#define DduStatus_StopNotif_DenormSensorDir            37U
#define DduStatus_StopNotif_DenormHallSbcSupply        38U
#define DduStatus_StopNotif_DenormFctCall              39U
#define DduStatus_StopNotif_DenormPowerLoss            40U
#define DduStatus_StopNotif_DenormClutchSlip           41U
#define DduStatus_StopNotif_DenormZoneInvalid          42U
#define DduStatus_AppRejectedCommand                   43U
#define DduStatus_DenormHallRangeFault                 44U
#define DduStatus_Unknown                              45U

/*DduStatus_DoorState*/
#define DduStatus_DoorState_Closed     0x00U
#define DduStatus_DoorState_ManOpen    0x01U
#define DduStatus_DoorState_ManClose   0x02U
#define DduStatus_DoorState_ElecOpen   0x03U
#define DduStatus_DoorState_ElecClose  0x04U
#define DduStatus_DoorState_Reversing  0x05U
#define DduStatus_DoorState_HoldEl     0x06U
#define DduStatus_DoorState_HoldMech   0x07U
#define DduStatus_DoorState_PrepMovent 0x08U
#define DduStatus_DoorState_Diag       0x09U

/*DduStatus_OperationState*/
#define DduStatus_OperationState_NORMAL                           0x00U
#define DduStatus_OperationState_DERATED_VOLTAGE                  0x01U
#define DduStatus_OperationState_DERATED_TEMPERATURE              0x02U
#define DduStatus_OperationState_DERATED_INCLINATION              0x03U
#define DduStatus_OperationState_VEHICLE_DRIVING                  0x04U
#define DduStatus_OperationState_PROHIBITED_VOLTAGE               0x05U
#define DduStatus_OperationState_PROHIBITED_TEMPERATURE           0x06U
#define DduStatus_OperationState_PROHIBITED_INCLINATION           0x07U
#define DduStatus_OperationState_PROHIBITED_SEVERAL_DERATED_COND  0x08U

/*DduStatus_HardHoldFuncState*/
#define DduStatus_HardHoldFuncState_inactive           0x00U
#define DduStatus_HardHoldFuncState_enabled            0x01U
#define DduStatus_HardHoldFuncState_active             0x02U

/*DduStatus_EmergCloseFuncState*/
#define DduStatus_EmergCloseFuncState_inactive           0x00U
#define DduStatus_EmergCloseFuncState_prep_movement      0x01U
#define DduStatus_EmergCloseFuncState_movement_ongoing   0x02U


/*DduStatus_PosRange*/
#define DduStatus_PosRange_Unknown           0x00U
#define DduStatus_PosRange_Closed            0x01U
#define DduStatus_PosRange_OpenOnly          0x02U
#define DduStatus_PosRange_Intermediate      0x03U
#define DduStatus_PosRange_CloseOnly         0x04U
#define DduStatus_PosRange_FullOpen          0x05U

/*DduStatus_LatchState*/
#define DduStatus_LatchState_Closed            0x0U
#define DduStatus_LatchState_HalfClosed        0x1U
#define DduStatus_LatchState_Open              0x2U
#define DduStatus_LatchState_Unknown           0x3U

/*DduStatus_ServoDisReason*/	
#define DduStatus_ServoDisReason_StopNotif_NoStop               0U      
#define DduStatus_ServoDisReason_StopNotif_StopCmd              1U  
#define DduStatus_ServoDisReason_StopNotif_FuncReleaseOff       2U 
#define DduStatus_ServoDisReason_StopNotif_MotionProhibited     3U 
#define DduStatus_ServoDisReason_StopNotif_VehSpeedAboveLim     4U 
#define DduStatus_ServoDisReason_StopNotif_Crash                5U 
#define DduStatus_ServoDisReason_StopNotif_ChildLock            6U           
#define DduStatus_ServoDisReason_StopNotif_LatchLocked          7U  
#define DduStatus_ServoDisReason_StopNotif_PosRangeMismatch     8U 
#define DduStatus_ServoDisReason_StopNotif_CrankTimeout         9U 
#define DduStatus_ServoDisReason_StopNotif_UserInteraction      10U 
#define DduStatus_ServoDisReason_StopNotif_AntiCollision        11U 
#define DduStatus_ServoDisReason_StopNotif_AntiTrap             12U 
#define DduStatus_ServoDisReason_StopNotif_ThermoProt           13U 
#define DduStatus_ServoDisReason_StopNotif_DoorMotStall         14U 
#define DduStatus_ServoDisReason_StopNotif_DoorMotTimeout       15U 
#define DduStatus_ServoDisReason_StopNotif_PosSensorFault       16U 
#define DduStatus_ServoDisReason_StopNotif_DoorMotHallFault     17U 
#define DduStatus_ServoDisReason_StopNotif_DoorMotFault         18U 
#define DduStatus_ServoDisReason_StopNotif_LatchFault           19U 
#define DduStatus_ServoDisReason_StopNotif_LatchNotReached      20U 
#define DduStatus_ServoDisReason_StopNotif_DenormPosInvalid     21U   
#define DduStatus_ServoDisReason_StopNotif_BusFault             22U 
#define DduStatus_ServoDisReason_StopNotif_FuncDisabled         23U 
#define DduStatus_ServoDisReason_StopNotif_ParamSetInvalid      24U 
#define DduStatus_ServoDisReason_StopNotif_MemFault             25U 
#define DduStatus_ServoDisReason_StopNotif_TargetPosReached     26U 
#define DduStatus_ServoDisReason_StopNotif_TargetPosInvalid     27U 
#define DduStatus_ServoDisReason_StopNotif_DiagMode             28U  
#define DduStatus_ServoDisReason_StopNotif_RadarFault           29U 
#define DduStatus_ServoDisReason_StopNotif_VehSpeedUnknown      30U 
#define DduStatus_ServoDisReason_StopNotif_VehInclUnknown       31U 
#define DduStatus_ServoDisReason_StopNotif_AmbTempUnknown       32U 
#define DduStatus_ServoDisReason_StopNotif_LatchOpenFault       33U 
#define DduStatus_ServoDisReason_StopNotif_EolDataInvalid       34U 
#define DduStatus_ServoDisReason_StopNotif_DenormLatchFault     35U 
#define DduStatus_ServoDisReason_StopNotif_DenormSensorOV       36U
#define DduStatus_ServoDisReason_StopNotif_DenormSensorDir      37U
#define DduStatus_ServoDisReason_StopNotif_DenormSensorSupply   38U
#define DduStatus_ServoDisReason_StopNotif_DenormFctCall        39U
#define DduStatus_ServoDisReason_StopNotif_DenormPowerLoss      40U
#define DduStatus_ServoDisReason_StopNotif_DenormClutchSlip     41U
#define DduStatus_ServoDisReason_StopNotif_DenormZoneInvalid    42U

/*RedsStat_ActFuncMode*/
#define RedsStat_ActFuncMode_collision_detection_mode_1           0x00U
#define RedsStat_ActFuncMode_collision_detection_mode_2           0x01U
#define RedsStat_ActFuncMode_approach_distance_mode               0x02U

/*RedsStat_SysState*/
#define RedsStat_SysState_STANDBY              0x00U
#define RedsStat_SysState_FAST_MEASUREMENT     0x01U
#define RedsStat_SysState_SLOW_MEASUREMENT     0x02U
#define RedsStat_SysState_DEGRADED             0x03U
#define RedsStat_SysState_FAULT                0x04U
#define RedsStat_SysState_DIAGNOSE_MODE        0x05U


/*InclInfoFromSDDtoGW_RollAngleValidF*/
#define InclInfoFromSDDtoGW_RollAngleValidF_Valid    0x00U
#define InclInfoFromSDDtoGW_RollAngleValidF_Invalid  0x01U
/*InclInfoFromSDDtoGW_RollAngle*/
/*InclInfoFromSDDtoGW_PitchAngleValidF*/
#define InclInfoFromSDDtoGW_PitchAngleValidF_Valid    0x00U
#define InclInfoFromSDDtoGW_PitchAngleValidF_Invalid  0x01U
/*InclInfoFromSDDtoGW_PitchAngle*/


#define _DoorPowerMode_NormalMode           0x01U
#define _DoorPowerMode_SmallOpenMode        0x02U
#define _DoorPowerMode_PowerOpenDisable     0x03U

/*VehicleSpeed_Valid*/
#define _SPEED_VALID        0x0U
#define _SPEED_INVALID      0x1U
/*EngineEngine_Valid*/
#define _ENGINE_VALID       0x0U
#define _ENGINE_INVALID     0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID     0x0U
#define _ODOMETER_INVALID   0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U
/*Incline_Valid*/
#define _Incline_Valid      0x0U
#define _Incline_Invalid    0x2U

/*Incline_Valid*/
#define _Function_Enable    0x0U
#define _Function_Disable   0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x1EU
#define _BUS_TEMPERATURE_80       0x10EU

#endif
#endif



#ifdef _VOYAH_COM
#ifdef _VOYAH_COM_PD
/*Rx*/
/*ble_rke_PODFLReq*/
/*ble_rke_PODFRReq*/
/*ble_rke_PODRLReq*/
/*ble_rke_PODRRReq*/
#define _ble_rke_PODReq_No_Request    0x0U
#define _ble_rke_PODReq_Open          0x1U
#define _ble_rke_PODReq_Close         0x2U

/*ble_rke_ClosedAllDoorReq*/
#define _ble_rke_ClosedAllDoorReq_No_Request    0x0U
#define _ble_rke_ClosedAllDoorReq_Open          0x1U
#define _ble_rke_ClosedAllDoorReq_Close         0x2U

/*IPB_vehicleSpeedValid*/
#define _IPB_vehicleSpeedValid_INVALID    0x0U
#define _IPB_vehicleSpeedValid_VALID      0x1U

/*BCM_DoorFLCtrlReq*/
/*BCM_DoorFRCtrlReq*/
/*BCM_DoorRLCtrlReq*/
/*BCM_DoorRRCtrlReq*/
#define _BCM_DoorCtrlReq_No_Request    0x0U
#define _BCM_DoorCtrlReq_Open          0x1U
#define _BCM_DoorCtrlReq_Close         0x2U
#define _BCM_DoorCtrlReq_Stop          0x3U
#define _BCM_DoorCtrlReq_Relese        0x4U

/*BCM_FL_ElectricRelseCtlSet*/
/*BCM_FR_ElectricRelseCtlSet*/
/*BCM_RL_ElectricRelseCtlSet*/
/*BCM_RR_ElectricRelseCtlSet*/
#define _BCM_ElectricRelseCtlSet_no_command    0x0U
#define _BCM_ElectricRelseCtlSet_OFF           0x1U
#define _BCM_ElectricRelseCtlSet_ON            0x2U

/*ODRC_SnsErrFlagFL1*/
/*ODRC_SnsErrFlagFR1*/
/*ODRC_SnsErrFlagRL1*/
/*ODRC_SnsErrFlagRR1*/
#define _ODRC_SnsErrFlag1_No_Error               0x0U
#define _ODRC_SnsErrFlag1_Sensor_short_circuit   0x1U
#define _ODRC_SnsErrFlag1_Sensor_open_circuit    0x2U
#define _ODRC_SnsErrFlag1_Sensor_ringtime_error  0x3U	

/*ODRC_SnsErrFlagFL2*/
/*ODRC_SnsErrFlagFR2*/
/*ODRC_SnsErrFlagRL2*/
/*ODRC_SnsErrFlagRR2*/
#define _ODRC_SnsErrFlag2_No_Error               0x0U
#define _ODRC_SnsErrFlag2_Sensor_short_circuit   0x1U
#define _ODRC_SnsErrFlag2_Sensor_open_circuit    0x2U
#define _ODRC_SnsErrFlag2_Sensor_ringtime_error  0x3U	

/*ODRC_WorkStFL*/
/*ODRC_WorkStFR*/
/*ODRC_WorkStRL*/
/*ODRC_WorkStRR*/
#define _ODRC_WorkSt_Off         0x0U
#define _ODRC_WorkSt_Standby     0x1U
#define _ODRC_WorkSt_Active      0x2U
#define _ODRC_WorkSt_Failure     0x3U

/*ODRC_EmergencyStopFL*/
/*ODRC_EmergencyStopFR*/
/*ODRC_EmergencyStopRL*/
/*ODRC_EmergencyStopRR*/
#define _ODRC_EmergencyStop_Non-Emergency_stop   0x0U
#define _ODRC_EmergencyStop_Emergency_stop       0x1U

/*ODRC_ValidFL*/
/*ODRC_ValidFR*/
/*ODRC_ValidRL*/
/*ODRC_ValidRR*/
#define _ODRC_Valid_Invalid   0x0U
#define _ODRC_Valid_Valid     0x1U

/*ODRC_ObstacleDisFL*/
/*ODRC_ObstacleDisFR*/
/*ODRC_ObstacleDisRL*/
/*ODRC_ObstacleDisRR*/
#define ODRC_ObstacleDis_No_obstacle_detected   0xFFU

/*ODRC_OpenablePercentFL*/
/*ODRC_OpenablePercentFR*/
/*ODRC_OpenablePercentRL*/
/*ODRC_OpenablePercentRR*/
#define ODRC_OpenablePercent_To_be_detected   0x7FU

/*ODRC_RawDisFL1*/
/*ODRC_RawDisFR1*/
/*ODRC_RawDisRL1*/
/*ODRC_RawDisRR1*/
#define ODRC_RawDis1_No_obstacle_detected   0xFFU

/*ODRC_RawDisFL2*/
/*ODRC_RawDisFR2*/
/*ODRC_RawDisRL2*/
/*ODRC_RawDisRR2*/
#define ODRC_RawDis2_No_obstacle_detected   0xFFU

/*ipb_brakePedalStatus*/
#define _ipb_brakePedalStatus_NOT_PRESSED_INIT_DEFAULT    0x0U
#define _ipb_brakePedalStatus_PRESSED                     0x1U
#define _ipb_brakePedalStatus_RESERVED                    0x2U
#define _ipb_brakePedalStatus_ERROR                       0x3U

/*ipb_InputRodStrokeStatus*/
#define _ipb_InputRodStrokeStatus_Invalid_default    0x0U
#define _ipb_InputRodStrokeStatus_valid_init         0x1U

/*ipb_InputRodStrokeStatus*/
#define _ipb_InputRodStrokeStatus_Invalid_default    0x0U
#define _ipb_InputRodStrokeStatus_valid_init         0x1U

/*ADS_LeFrntDowNoOpenCmd*/
/*ADS_RiFrntDowNoOpenCmd*/
/*ADS_LeReDowNoOpenCmd*/
/*ADS_RiReDowNoOpenCmd*/
#define _ADS_DowNoOpenCmd_No_Request    0x0U
#define _ADS_DowNoOpenCmd_Request       0x1U

/*POD_FL_DoorPositionStsSet*/
/*POD_FR_DoorPositionStsSet*/
/*POD_RL_DoorPositionStsSet*/
/*POD_RR_DoorPositionStsSet*/
#define _POD_DoorPositionStsSet_DOORPosSetS_Default    0x0U
#define _POD_DoorPositionStsSet_DOORPosSetS_60p        0x1U
#define _POD_DoorPositionStsSet_DOORPosSetS_80p        0x2U
#define _POD_DoorPositionStsSet_DOORPosSetS_100p       0x3U
#define _POD_DoorPositionStsSet_DOORPosSetS_invalid    0xFU

/*POD_FL_ElectricDoorCtlSet*/
/*POD_FR_ElectricDoorCtlSet*/
/*POD_RL_ElectricDoorCtlSet*/
/*POD_RR_ElectricDoorCtlSet*/
#define _POD_ElectricDoorCtlSet_no_command    0x0U
#define _POD_ElectricDoorCtlSet_OFF           0x1U
#define _POD_ElectricDoorCtlSet_ON            0x2U	

/*POD_FL_DoorOpenSpdSet*/
/*POD_FR_DoorOpenSpdSet*/
/*POD_RL_DoorOpenSpdSet*/
/*POD_RR_DoorOpenSpdSet*/
#define _POD_DoorOpenSpdSet_no_command    0x0U
#define _POD_DoorOpenSpdSet_OFF           0x1U
#define _POD_DoorOpenSpdSet_ON            0x2U	
	
/*POD_FL_DoorOpenSpdSet*/
/*POD_FR_DoorOpenSpdSet*/
/*POD_RL_DoorOpenSpdSet*/
/*POD_RR_DoorOpenSpdSet*/
#define _POD_DoorOpenSpdSet_Default    0x0U
#define _POD_DoorOpenSpdSet_normal     0x1U
#define _POD_DoorOpenSpdSet_fast       0x2U	
	
/*POD_FL_PowerDoorSetingAntiWind*/
/*POD_FR_PowerDoorSetingAntiWind*/
/*POD_RL_PowerDoorSetingAntiWind*/
/*POD_RR_PowerDoorSetingAntiWind*/
#define _POD_PowerDoorSetingAntiWind_no_command    0x0U
#define _POD_PowerDoorSetingAntiWind_OFF           0x1U
#define _POD_PowerDoorSetingAntiWind_ON            0x2U
	
/*POD_FL_PowerDoorSetingSafeBelt*/
/*POD_FR_PowerDoorSetingSafeBelt*/
/*POD_RL_PowerDoorSetingSafeBelt*/
/*POD_RR_PowerDoorSetingSafeBelt*/
#define _POD_PowerDoorSetingSafeBelt_no_command    0x0U
#define _POD_PowerDoorSetingSafeBelt_OFF           0x1U
#define _POD_PowerDoorSetingSafeBelt_ON            0x2U

/*bcm_pepsPowerMode*/
#define _bcm_pepsPowerMode_DEFAULT_POWERMODE    0x0U
#define _bcm_pepsPowerMode_OFF_POWERMODE        0x1U
#define _bcm_pepsPowerMode_Local_ON_POWERMODE   0x2U
#define _bcm_pepsPowerMode_Remote_ON_POWERMODE  0x3U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE1   0x4U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE2   0x5U
#define _bcm_pepsPowerMode_RESERVE_POWERMODE3   0x6U
#define _bcm_pepsPowerMode_INVALID_POWERMODE    0x7U

/*PDCM_actualGear*/
#define _PDCM_actualGear_P    0x0U
#define _PDCM_actualGear_R    0x1U
#define _PDCM_actualGear_N    0x2U
#define _PDCM_actualGear_D    0x3U

/*PDCM_actualGearValid*/
#define _PDCM_actualGearValid_INVALID   0x0U
#define _PDCM_actualGearValid_VALID     0x1U

/*ic_totalMileage*/
#define _ic_totalMileage_Invalid   0xFFFFFF

/*ic_totalMileageValid*/
#define _ic_totalMileageValid_INVALID   0x0U
#define _ic_totalMileageValid_VALID     0x1U


/*VMM_Carmode*/
#define _VMM_Carmode_Factory       0x0U
#define _VMM_Carmode_Normal        0x1U
#define _VMM_Carmode_Exihibition   0x2U
#define _VMM_Carmode_Crash         0x3U
#define _VMM_Carmode_Transport     0x4U

/*AC_ambientTempValid*/
#define _AC_ambientTempValid_INVALID      0x0U
#define _AC_ambientTempValid_VALID        0x1U

/*BCM_CentralLockSts*/
#define _BCM_CentralLockSts_LOCK      0x0U
#define _BCM_CentralLockSts_UNLOCK    0x1U

/*DCU_FL_DoorPWLSwSts*/
/*DCU_FR_DoorPWLSwSts*/
/*DCU_RL_DoorPWLSwSts*/
/*DCU_RR_DoorPWLSwSts*/
#define _DCU_DoorPWLSwSts_OFF      0x0U
#define _DCU_DoorPWLSwSts_ON       0x1U


/*POD_FL_OpenValueSts*/
/*POD_FR_OpenValueSts*/
/*POD_RL_OpenValueSts*/
/*POD_RR_OpenValueSts*/
#define _POD_OpenValueSts_0_Percent   0x00U

/*pot_OpenValueSts*/
#define _pot_OpenValueSts_0_Percent   0x00U

/*DCU_FL_FLWindowHorizontalSts*/
/*DCU_FR_FRWindowHorizontalSts*/
/*DCU_RL_RLWindowHorizontalSts*/
/*DCU_RR_RRWindowHorizontalSts*/
#define _DCU_WindowHorizontalSts_0_Percent    0x00U
#define _DCU_WindowHorizontalSts_5_Percent    0x05U
#define _DCU_WindowHorizontalSts_Not_Learned  0x7FU
	

/*DCU_FL_DoorHomePosSwSts*/
/*DCU_FR_DoorHomePosSwSts*/
/*DCU_RL_DoorHomePosSwSts*/
/*DCU_RR_DoorHomePosSwSts*/
#define _DCU_DoorHomePosSwSts_OFF      0x0U
#define _DCU_DoorHomePosSwSts_ON       0x1U

/*DCU_FL_RelsedoorFLSts*/
/*DCU_FR_RelsedoorFRSts*/
/*DCU_RL_RelsedoorRLSts*/
/*DCU_RR_RelsedoorRRSts*/
#define _DCU_RelsedoorSts_CLOSE      0x0U
#define _DCU_RelsedoorSts_OPEN       0x1U

/*DCU_FL_DoorOenSwSts*/
/*DCU_FR_DoorOenSwSts*/
/*DCU_RL_DoorOenSwSts*/
/*DCU_RR_DoorOenSwSts*/
#define _DCU_DoorOenSwSts_OFF      0x0U
#define _DCU_DoorOenSwSts_ON       0x1U

/*DCU_FL_DoorAjarSwSts*/
/*DCU_FR_DoorAjarSwSts*/
/*DCU_RL_DoorAjarSwSts*/
/*DCU_RR_DoorAjarSwSts*/
#define _DCU_DoorAjarSwSts_OFF      0x0U
#define _DCU_DoorAjarSwSts_ON       0x1U

/*RLS_RainfallLevel*/
#define _RLS_RainfallLevel_No_Rain   0x0U
#define _RLS_RainfallLevel_Level1    0x1U
#define _RLS_RainfallLevel_Level2    0x2U
#define _RLS_RainfallLevel_Level3    0x3U
#define _RLS_RainfallLevel_Level4    0x4U
#define _RLS_RainfallLevel_Level5    0x5U
#define _RLS_RainfallLevel_Level6    0x6U
#define _RLS_RainfallLevel_Level7    0x7U
#define _RLS_RainfallLevel_Level8    0x8U
#define _RLS_RainfallLevel_Level9    0x9U
#define _RLS_RainfallLevel_Level10   0xAU
#define _RLS_RainfallLevel_Level11   0xBU
#define _RLS_RainfallLevel_Level12   0xCU
#define _RLS_RainfallLevel_Level13   0xDU
#define _RLS_RainfallLevel_Invaild   0xFU







/*Tx*/
/*POD_FL_DoorAssistantSts*/
/*POD_FR_DoorAssistantSts*/
/*POD_RL_DoorAssistantSts*/
/*POD_RR_DoorAssistantSts*/
#define _POD_DoorAssistantSts_NoInput    0x0U
#define _POD_DoorAssistantSts_Open       0x1U
#define _POD_DoorAssistantSts_Close      0x2U

/*POD_FL_DoorPositionSts*/
/*POD_FR_DoorPositionSts*/
/*POD_RL_DoorPositionSts*/
/*POD_RR_DoorPositionSts*/
#define _POD_DoorPositionSts_DOORPosSetS_Default    0x0U
#define _POD_DoorPositionSts_DOORPosSetS_60p        0x1U
#define _POD_DoorPositionSts_DOORPosSetS_80p        0x2U
#define _POD_DoorPositionSts_DOORPosSetS_100p       0x3U
#define _POD_DoorPositionSts_DOORPosSetS_invalid    0xFU	

/*POD_FL_ElectricDoorCtlSts*/
/*POD_FR_ElectricDoorCtlSts*/
/*POD_RL_ElectricDoorCtlSts*/
/*POD_RR_ElectricDoorCtlSts*/
#define _POD_ElectricDoorCtlSts_Default    0x0U
#define _POD_ElectricDoorCtlSts_OFF        0x1U
#define _POD_ElectricDoorCtlSts_ON         0x2U


/*POD_FL_DoorOpenSpdSts*/
/*POD_FR_DoorOpenSpdSts*/
/*POD_RL_DoorOpenSpdSts*/
/*POD_RR_DoorOpenSpdSts*/
#define _POD_DoorOpenSpdSts_Default    0x0U
#define _POD_DoorOpenSpdSts_normal     0x1U
#define _POD_DoorOpenSpdSts_fast       0x2U

/*POD_FL_PowerDoorAntiWindSts*/
/*POD_FR_PowerDoorAntiWindSts*/
/*POD_RL_PowerDoorAntiWindSts*/
/*POD_RR_PowerDoorAntiWindSts*/
#define _POD_PowerDoorAntiWindSts_Default    0x0U
#define _POD_PowerDoorAntiWindSts_OFF        0x1U
#define _POD_PowerDoorAntiWindSts_ON         0x2U

/*POD_FL_PowerDoorSafeBeltSts*/
/*POD_FR_PowerDoorSafeBeltSts*/
/*POD_RL_PowerDoorSafeBeltSts*/
/*POD_RR_PowerDoorSafeBeltSts*/
#define _POD_PowerDoorSafeBeltSts_Default    0x0U
#define _POD_PowerDoorSafeBeltSts_OFF        0x1U
#define _POD_PowerDoorSafeBeltSts_ON         0x2U

/*POD_FL_DoorFLSts*/
/*POD_FR_DoorFRSts*/
/*POD_RL_DoorRLSts*/
/*POD_RR_DoorRRSts*/
#define _POD_DoorSts_Fully_closed     0x0U
#define _POD_DoorSts_Fully_opened     0x1U
#define _POD_DoorSts_Opening          0x2U
#define _POD_DoorSts_Closing          0x3U
#define _POD_DoorSts_POD_stopped      0x4U
#define _POD_DoorSts_Latch_releasing  0x5U
#define _POD_DoorSts_Latch_cinching   0x6U

/*POD_FL_DoorReleaseLatch*/
/*POD_FR_DoorFRSts*/
/*POD_RL_DoorRLSts*/
/*POD_RR_DoorRRSts*/
#define _POD_DoorReleaseLatch_No_Request  0x0U
#define _POD_DoorReleaseLatch_Request     0x1U

/*POD_FL_FaultStatus*/
/*POD_FR_FaultStatus*/
/*POD_RL_FaultStatus*/
/*POD_RR_FaultStatus*/
#define _POD_FaultStatus_No_Fault               0x0U
#define _POD_FaultStatus_Actuator_Motor_Fault   0x1U
#define _POD_FaultStatus_Over_Voltage           0x2U
#define _POD_FaultStatus_Under_Voltage          0x3U
#define _POD_FaultStatus_Lost_Hall_A1           0x4U
#define _POD_FaultStatus_Lost_Hall_A2           0x5U

/*POD_FL_ODRCDetectRequirement*/
/*POD_FR_ODRCDetectRequirement*/
/*POD_RL_ODRCDetectRequirement*/
/*POD_RR_ODRCDetectRequirement*/
#define _POD_ODRCDetectRequirement_Not_Active   0x0U
#define _POD_ODRCDetectRequirement_Active       0x1U	

/*POD_FL_DoorProtectResult*/
/*POD_FR_DoorProtectResult*/
/*POD_RL_DoorProtectResult*/
/*POD_RR_DoorProtectResult*/
#define _POD_DoorProtectResult_Normal           0x0U
#define _POD_DoorProtectResult_Anti_Pinch       0x1U
#define _POD_DoorProtectResult_Outer_Obstacle   0x2U
#define _POD_DoorProtectResult_OverHeat         0x3U

/*POD_FL_PowerDoorBrakeSts*/
/*POD_FR_PowerDoorBrakeSts*/
/*POD_RL_PowerDoorBrakeSts*/
/*POD_RR_PowerDoorBrakeSts*/
#define _POD_PowerDoorBrakeSts_Default   0x0U
#define _POD_PowerDoorBrakeSts_OFF       0x1U
#define _POD_PowerDoorBrakeSts_ON        0x2U

/*POD_FL_DoorInhibition*/
/*POD_FR_DoorInhibition*/
/*POD_RL_DoorInhibition*/
/*POD_RR_DoorInhibition*/
#define _POD_DoorInhibition_No_Inhibition               0x0U
#define _POD_DoorInhibition_Vehicle_Mode_Inhibit        0x1U
#define _POD_DoorInhibition_Crash_Inhibit               0x2U
#define _POD_DoorInhibition_Anti_Play_Inhibit           0x3U
#define _POD_DoorInhibition_Thermal_Protection_Inhibit  0x4U


	
	
/*VehicleSpeed_Valid*/
#define _SPEED_VALID        0x0U
#define _SPEED_INVALID      0x1U
/*EngineEngine_Valid*/
#define _ENGINE_VALID       0x0U
#define _ENGINE_INVALID     0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID     0x0U
#define _ODOMETER_INVALID   0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U
/*Incline_Valid*/
#define _Incline_Valid      0x0U
#define _Incline_Invalid    0x2U

/*Incline_Valid*/
#define _Function_Enable    0x0U
#define _Function_Disable   0x1U

/*SpeedMode*/
#define _SpeedMode_Normal    0x0U
#define _SpeedMode_Fast      0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x00U
#define _BUS_TEMPERATURE_80       0xFAU



#endif
#endif



#ifdef _CHERY_COM
#ifdef _CHERY_COM_PD
/*Rx*/
/*ACU_3_CrashOutputSts*/
#define _ACU_3_CrashOutputSts_No_crash           0x00U
#define _ACU_3_CrashOutputSts_Belt_Crash         0x01U
#define _ACU_3_CrashOutputSts_Front_Crash        0x02U
#define _ACU_3_CrashOutputSts_Left_Side_Crash    0x04U
#define _ACU_3_CrashOutputSts_Right_Side_Crash   0x08U
#define _ACU_3_CrashOutputSts_Rear_Crash         0x10U
#define _ACU_3_CrashOutputSts_Roll_Crash         0x20U

/*BNCM_1_UIRUnLockRequest*/
#define _BNCM_1_UIRUnLockRequest_No_request      0x00U
#define _BNCM_1_UIRUnLockRequest_Request         0x01U

/*BNCM_1_DriDoorReq*/
#define _BNCM_1_DriDoorReq_No_request      0x00U
#define _BNCM_1_DriDoorReq_Request         0x01U

/*PEPS_SingleSidePolling*/
#define _PEPS_SingleSidePolling_Not_Active      0x00U
#define _PEPS_SingleSidePolling_Left_Polling    0x01U
#define _PEPS_SingleSidePolling_Right_Polling   0x02U


/*BNCM_6_RemoteControl*/
#define _BNCM_6_RemoteControl_No_Command         0x00U
#define _BNCM_6_RemoteControl_Lock               0x01U
#define _BNCM_6_RemoteControl_Unlock             0x02U
#define _BNCM_6_RemoteControl_Trunk_unlock       0x03U
#define _BNCM_6_RemoteControl_Trunk_lock         0x04U

/*BNCM_14_LockButtAct*/
#define _BNCM_14_LockButtAct_None                    0x00U
#define _BNCM_14_LockButtAct_LockButt_SinglePress    0x01U
#define _BNCM_14_LockButtAct_LockButt_DoublePress    0x02U
#define _BNCM_14_LockButtAct_LockButt_LongPress      0x03U

/*BNCM_14_UnLockButtAct*/
#define _BNCM_14_UnLockButtAct_None                      0x00U
#define _BNCM_14_UnLockButtAct_UnLockButt_SinglePress    0x01U
#define _BNCM_14_UnLockButtAct_UnLockButt_DoublePress    0x02U
#define _BNCM_14_UnLockButtAct_UnLockButt_LongPress      0x03U

/*PEPS_LockButtAct*/
#define _PEPS_LockButtAct_None                    0x00U
#define _PEPS_LockButtAct_LockButt_SinglePress    0x01U
#define _PEPS_LockButtAct_LockButt_DoublePress    0x02U
#define _PEPS_LockButtAct_LockButt_LongPress      0x03U

/*PEPS_UnLockButtAct*/
#define _PEPS_UnLockButtAct_None                      0x00U
#define _PEPS_UnLockButtAct_UnLockButt_SinglePress    0x01U
#define _PEPS_UnLockButtAct_UnLockButt_DoublePress    0x02U
#define _PEPS_UnLockButtAct_UnLockButt_LongPress      0x03U

/*BNCM_FL_BLEControlDoor*/
#define _BNCM_FL_BLEControlDoor_Inactive     0x00U
#define _BNCM_FL_BLEControlDoor_active       0x01U

/*BNCM_BLE_CloseAllDoors*/
#define _BNCM_BLE_CloseAllDoors_Inactive     0x00U
#define _BNCM_BLE_CloseAllDoors_active       0x01U

/*RLCR_1_SysSt*/
/*RRCR_1_SysSt*/
#define _CR_1_SysSt_Off                  0x00U
#define _CR_1_SysSt_On                   0x01U
#define _CR_1_SysSt_Temporary_Error      0x02U
#define _CR_1_SysSt_System_Error         0x03U


/*RLCR_1_DOWWarn*/
/*RRCR_1_DOWWarn*/
#define _CR_1_DOWWarn_No_Warning       0x00U
#define _CR_1_DOWWarn_Level1_Warning   0x01U
#define _CR_1_DOWWarn_Level2_Warning   0x02U
#define _CR_1_DOWWarn_Not_Used         0x03U

/*RLCR_1_DowLock*/
/*RRCR_1_DowLock*/
#define _CR_1_DowLock_No_Warning       0x00U
#define _CR_1_DowLock_Dow_lock         0x01U
#define _CR_1_DowLock_Dow_unlock       0x02U
#define _CR_1_DowLock_Not_Used         0x03U

/*RLCR_2_DOWONOFFSts*/
#define _RLCR_2_DOWONOFFSts_Not_active     0x00U
#define _RLCR_2_DOWONOFFSts_OFF            0x01U
#define _RLCR_2_DOWONOFFSts_ON             0x02U


/*RCM_1_FLRadarStatus*/
/*RCM_2_FRRadarStatus*/
/*RCM_3_RLRadarStatus*/
/*RCM_4_RRRadarStatus*/
#define _RCM_RadarStatus_normal                              0x00U
#define _RCM_RadarStatus_Radar1Fault                         0x01U
#define _RCM_RadarStatus_Radar2Fault                         0x02U
#define _RCM_RadarStatus_Radar1Fault_Radar2Fault             0x03U
#define _RCM_RadarStatus_Radar3Fault                         0x04U
#define _RCM_RadarStatus_Radar1Fault_Radar3Fault             0x05U
#define _RCM_RadarStatus_Radar2Fault_Radar3Fault             0x06U
#define _RCM_RadarStatus_Radar1Fault_Radar2Fault_Radar3Fault 0x07U


/*RCM_1_LRadarVoltageStatus*/
/*RCM_1_RRadarVoltageStatus*/
/*RCM_1_VoltageStatus*/
#define _RCM_VoltageStatus_normal                  0x00U
#define _RCM_VoltageStatus_over_voltage            0x01U
#define _RCM_VoltageStatus_under_voltage           0x02U


/*RCM_1_FLDoorTemperatureStatus*/
/*RCM_2_FRDoorTemperatureStatus*/
/*RCM_3_RLDoorTemperatureStatus*/
/*RCM_4_RRDoorTemperatureStatus*/
#define _RCM_DoorTemperatureStatus_normal                   0x00U
#define _RCM_DoorTemperatureStatus_Overtemperature_value    0x01U



/*FLDRM_1_StsDRMToDCM*/
/*FRDRM_1_StsDRMToDCM*/
/*RRDRM_1_StsDRMToDCM*/
/*RLDRM_1_StsDRMToDCM*/
#define _StsDRMToDCM_Reset              0x00U
#define _StsDRMToDCM_Init               0x01U
#define _StsDRMToDCM_Standby            0x02U
#define _StsDRMToDCM_Active             0x03U
#define _StsDRMToDCM_PreSleep           0x04U
#define _StsDRMToDCM_ThermalProtected   0x05U
#define _StsDRMToDCM_Invalid            0x06U
#define _StsDRMToDCM_Reserved           0x07U

/*ICC_FLDoorButton*/
/*ICC_FRDoorButton*/
/*ICC_RLDoorButton*/
/*ICC_RRDoorButton*/
#define _DoorButton_Init         0x00U
#define _DoorButton_Inactive     0x01U
#define _DoorButton_Active       0x02U

/*ICC_CloseAllDoors*/
#define _ICC_CloseAllDoors_Init         0x00U
#define _ICC_CloseAllDoors_Inactive     0x01U
#define _ICC_CloseAllDoors_Active       0x02U

/*ICC_FLVoiceControl*/
/*ICC_FRVoiceControl*/
/*ICC_RLVoiceControl*/
/*ICC_RRVoiceControl*/
#define _VoiceControl_No_Action       0x00U
#define _VoiceControl_Door_Close      0x01U
#define _VoiceControl_Door_Open       0x02U
#define _VoiceControl_Door_Stop       0x03U


/*ICC_CleanMode*/
#define _ICC_CleanMode_NotActive        0x00U
#define _ICC_CleanMode_OFF              0x01U
#define _ICC_CleanMode_ON               0x02U
#define _ICC_CleanMode_Reserved         0x03U



/*RR_Door_RearScreen_Control*/
/*RL_Door_RearScreen_Control*/
#define _Door_RearScreen_Control_No_Request   0x00U
#define _Door_RearScreen_Control_Inactive     0x01U
#define _Door_RearScreen_Control_active       0x02U


/*ICC_SetOpenAngle*/
#define _ICC_SetOpenAngle_No_Request      0x00U
#define _ICC_SetOpenAngle_50_Percent      0x01U
#define _ICC_SetOpenAngle_75_Percent      0x02U
#define _ICC_SetOpenAngle_100_Percent     0x03U

/*ICC_DoorRemoteKeyControlEnable*/
#define _ICC_DoorRemoteKeyControlEnable_No_Request    0x00U
#define _ICC_DoorRemoteKeyControlEnable_Enable        0x01U
#define _ICC_DoorRemoteKeyControlEnable_Disable       0x02U

/*ICC_BLEOpenDriverDoorEnable*/
#define _ICC_BLEOpenDriverDoorEnable_No_Request    0x00U
#define _ICC_BLEOpenDriverDoorEnable_Enable        0x01U
#define _ICC_BLEOpenDriverDoorEnable_Disable       0x02U

/*FLZCU_9_BLEOpenDriverDoorSts*/
#define _FLZCU_9_BLEOpenDriverDoorSts_No_Request    0x00U
#define _FLZCU_9_BLEOpenDriverDoorSts_Enable        0x01U
#define _FLZCU_9_BLEOpenDriverDoorSts_Disable       0x02U

/*ICC_PedalCloseDriverDoorEnable*/
#define _ICC_PedalCloseDriverDoorEnable_No_Request    0x00U
#define _ICC_PedalCloseDriverDoorEnable_Enable        0x01U
#define _ICC_PedalCloseDriverDoorEnable_Disable       0x02U

/*ICC_FrontDoorPowerMode*/
/*ICC_RearDoorPowerMode*/
#define _ICC_DoorPowerMode_No_Request       0x00U
#define _ICC_DoorPowerMode_PowerMode        0x01U
#define _ICC_DoorPowerMode_ManualMode       0x02U
#define _ICC_DoorPowerMode_SemiAutoMode     0x03U

#define _DoorPowerMode_NormalMode           0x01U
#define _DoorPowerMode_SmallOpenMode        0x02U
#define _DoorPowerMode_PowerOpenDisable     0x03U

/*VCC_2_ConfigurationMessageTrg*/
#define _VCC_2_ConfigurationMessageTrg_not_active     0x00U
#define _VCC_2_ConfigurationMessageTrg_active         0x01U


/*ICC_FrontDoorVoiceControlEnable*/
/*ICC_RearDoorVoiceControlEnable*/
#define _ICC_DoorVoiceControlEnable_No_Request    0x00U
#define _ICC_DoorVoiceControlEnable_Enable        0x01U
#define _ICC_DoorVoiceControlEnable_Disable       0x02U

/*ICC_PedalCloseDriverDoorEnable*/
#define _ICC_PedalCloseDriverDoorEnable_No_Request    0x00U
#define _ICC_PedalCloseDriverDoorEnable_Enable        0x01U
#define _ICC_PedalCloseDriverDoorEnable_Disable       0x02U

/*VCU_BrakePedalStsValidData*/
#define _VCU_BrakePedalStsValidData_Valid          0x00U
#define _VCU_BrakePedalStsValidData_Not_Valid      0x01U

/*VCU_BrakePedalSts*/
#define _VCU_BrakePedalSts_Not_applied     0x00U
#define _VCU_BrakePedalSts_Applied         0x01U

/*FLDCM_3_BLEOpenDriverDoorFB*/
#define _FLDCM_3_BLEOpenDriverDoorFB_Enable       0x00U
#define _FLDCM_3_BLEOpenDriverDoorFB_Disable      0x01U

/*FLDCM_3_PedalCloseDriverDoorFB*/
#define _FLDCM_3_PedalCloseDriverDoorFB_Enable       0x00U
#define _FLDCM_3_PedalCloseDriverDoorFB_Disable      0x01U

/*FLDCM_3_DoorRemoteKeyControlFB*/
#define _FLDCM_3_DoorRemoteKeyControlFB_Enable       0x00U
#define _FLDCM_3_DoorRemoteKeyControlFB_Disable      0x01U

/*FLDCM_3_FrontDoorVoiceControlFB*/
#define _FLDCM_3_FrontDoorVoiceControlFB_Enable       0x00U
#define _FLDCM_3_FrontDoorVoiceControlFB_Disable      0x01U

/*FLDoorMotionDirection*/
/*FRDoorMotionDirection*/
/*RLDoorMotionDirection*/
/*RRDoorMotionDirection*/
#define _DoorMotionDirection_Init       0x00U
#define _DoorMotionDirection_open       0x01U
#define _DoorMotionDirection_close      0x02U


/*FLLockReleaseInsdSW*/
/*FRLockReleaseInsdSW*/
/*RLLockReleaseInsdSW*/
/*RRLockReleaseInsdSW*/
#define _LockReleaseInsdSW_Not_Active       0x00U
#define _LockReleaseInsdSW_Active           0x01U

/*FLLockReleaseOutsdSW*/
/*FRLockReleaseOutsdSW*/
/*RLLockReleaseOutsdSW*/
/*RRLockReleaseOutsdSW*/
#define _LockReleaseOutsdSW_Not_Active       0x00U
#define _LockReleaseOutsdSW_Active           0x01U

/*FL_SeatOccupiedSts*/
#define _SeatOccupiedSts_Not_Active       0x00U
#define _SeatOccupiedSts_Active           0x01U

/*ACU_1_PsngrSeatOccupiedSts*/
/*ACU_1_SecRowLSeatOccupiedSts*/
/*ACU_1_SecRowRSeatOccupiedSts*/
#define _SeatOccupiedSts_Not_Occupied       0x00U
#define _SeatOccupiedSts_Occupied           0x01U
#define _SeatOccupiedSts_Open_Circuit       0x02U
#define _SeatOccupiedSts_Short_Circuit      0x03U


/*LHFSeatBeltSW*/
#define _SeatBeltSW_Not_Active       0x00U
#define _SeatBeltSW_Active           0x01U

/*ACU_1_PsngrSeatBeltWarning*/
#define _PsngrSeatBeltWarning_Not_warning     0x00U
#define _PsngrSeatBeltWarning_Reserve         0x01U
#define _PsngrSeatBeltWarning_Warning         0x02U

/*ACU_1_SecRowLBeltWarning*/
/*ACU_1_SecRowRBeltWarning*/
#define _SecRowSeatBeltWarning_No_Warning       0x00U
#define _SecRowSeatBeltWarning_Warning          0x01U


/*HandleSwitchStsFL*/
/*HandleSwitchStsFR*/
/*HandleSwitchStsRL*/
/*HandleSwitchStsRR*/
#define _HandleSwitchSts_Not_Active       0x00U
#define _HandleSwitchSts_Outside          0x01U
#define _HandleSwitchSts_Inside           0x02U
#define _HandleSwitchSts_Bothside         0x03U



/*FLZCU_9_PowerMode*/
#define _FLZCU_9_PowerMode_Off           0x00U
#define _FLZCU_9_PowerMode_Comfortable   0x01U
#define _FLZCU_9_PowerMode_ON            0x02U

/*VCU_PRNDGearAct*/
#define _VCU_PRNDGearAct_Init         0x00U
#define _VCU_PRNDGearAct_P            0x01U
#define _VCU_PRNDGearAct_R            0x02U
#define _VCU_PRNDGearAct_N            0x03U
#define _VCU_PRNDGearAct_D            0x04U

/*FLZCU_9_ArmingSts*/
#define _FLZCU_9_ArmingSts_Not_active            0x00U
#define _FLZCU_9_ArmingSts_Arming_successful     0x01U
#define _FLZCU_9_ArmingSts_Disarming_successful  0x02U
#define _FLZCU_9_ArmingSts_Invalid               0x03U

/*DVD_Set_PLGPositionSts*/
#define _DVD_Set_PLGPositionSts_50_Pecent   0x32U
#define _DVD_Set_PLGPositionSts_70_Pecent   0x46U
#define _DVD_Set_PLGPositionSts_100_Pecent  0x64U

/*VCC_1_CarMode*/
#define _VCC_1_CarMode_Normal_Mode            0x00U
#define _VCC_1_CarMode_Factory_Mode           0x01U
#define _VCC_1_CarMode_Transport_Mode         0x02U


/*VehicleSpeed_Valid*/
#define _SPEED_VALID        0x0U
#define _SPEED_INVALID      0x1U
/*EngineEngine_Valid*/
#define _ENGINE_VALID       0x0U
#define _ENGINE_INVALID     0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID     0x0U
#define _ODOMETER_INVALID   0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U
/*Incline_Valid*/
#define _Incline_Valid      0x0U
#define _Incline_Invalid    0x2U

/*Incline_Valid*/
#define _Function_Enable    0x0U
#define _Function_Disable   0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x1EU
#define _BUS_TEMPERATURE_80       0x10EU

/*FL_ReleaseLatchStatus*/
/*FR_ReleaseLatchStatus*/
/*RL_ReleaseLatchStatus*/
/*RR_ReleaseLatchStatus*/
#define _ReleaseLatchStatus_unknow          0x0U
#define _ReleaseLatchStatus_releasing       0x1U
#define _ReleaseLatchStatus_released        0x2U
#define _ReleaseLatchStatus_reverse         0x3U
#define _ReleaseLatchStatus_revsersed       0x4U

/*FL_CentralLockSwitch*/
#define _CentralLockSwitch_Locked          0x0U
#define _CentralLockSwitch_Unlocked        0x1U
#define _CentralLockSwitch_Superlocked     0x2U

/*RR_ChildrenProtectSwitch*/
/*RL_ChildrenProtectSwitch*/
#define _ChildrenProtectSwitch_Locked          0x0U
#define _ChildrenProtectSwitch_Unlocked        0x1U
#define _ChildrenProtectSwitch_Superlocked     0x2U

/*PLG_OperateSts*/
#define _PLG_OperateSts_0_Percent        0x0U
#define _PLG_OperateSts_1_Percent        0x1U
#define _PLG_OperateSts_100_Percent      0x64U

/*InformationSource*/
#define _InformationSource_Not_Used            0x0U
#define _InformationSource_SMART_Information   0x1U
#define _InformationSource_RKE_Information     0x2U
#define _InformationSource_Near_Access         0x3U

/*OrderInformation*/
#define _OrderInformation_OFF                      0x0U
#define _OrderInformation_Lock                     0x1U
#define _OrderInformation_Unlock                   0x2U
#define _OrderInformation_Trunk                    0x4U
#define _OrderInformation_Welcome                  0x5U
#define _OrderInformation_Welcome_off              0x6U
#define _OrderInformation_Power_slide_door_right   0xdU
#define _OrderInformation_Power_slide_door_left    0xeU

/*BrakePedalSts*/
#define _BrakePedalSts_Valid                       0x0U
#define _BrakePedalSts_Not_Valid                   0x1U

/*BrakePedalStsValidData*/
#define _BrakePedalStsValidData_Not_applied        0x0U
#define _BrakePedalStsValidData_Applied            0x1U

/*ExternalTemperatureFailSts*/
#define _ExternalTemperatureFailSts_Fail_Not_Present              0x0U
#define _ExternalTemperatureFailSts_Fail_Present                  0x1U


/*DoorCtrl_FL*/
/*DoorCtrl_FR*/
/*DoorCtrl_RL*/
/*DoorCtrl_RR*/
#define _DoorCtrl_NoAction        0x0U
#define _DoorCtrl_Action          0x1U

/*ModeSwitch_FL*/
/*ModeSwitch_FR*/
#define _ModeSwitch_Initial         0x0U
#define _ModeSwitch_ScissorDoor     0x1U
#define _ModeSwitch_SideDoor        0x2U
#define _ModeSwitch_Reserve         0x3U

/*AutoOpen_FL_FR*/
#define _AutoOpen_FL_FR_NoAction     0x0U
#define _AutoOpen_FL_FR_AutoOpen     0x1U

/*AutoClose_FL_FR*/
#define _AutoClose_FL_FR_NoAction     0x0U
#define _AutoClose_FL_FR_AutoClose    0x1U

/*AllDoorOpen*/
#define _AllDoorOpen_NoAction    0x0U
#define _AllDoorOpen_AutoOpen    0x1U

/*AllDoorClose*/
#define _AllDoorClose_NoAction    0x0U
#define _AllDoorClose_AutoClose   0x1U

/*Reset*/
#define _Reset_No_Command    0x0U
#define _Reset_Reset         0x1U

/*Enable*/
#define _Enable_Disable    0x0U
#define _Enable_Enable     0x1U

/*Stop*/
#define _Stop_No_Command    0x0U
#define _Stop_Stop          0x1U

/*Demo_Mode*/
#define _Demo_Mode_Normal      0x0U
#define _Demo_Mode_Demo_Mode   0x1U





/*Tx*/
/*FL_LearnedStatus*/
/*FR_LearnedStatus*/
/*RL_LearnedStatus*/
/*RR_LearnedStatus*/
#define _LearnedStatus_Unlearn          0x0U
#define _LearnedStatus_Learn            0x1U

/*FL_SystemMotionStatus*/
/*FR_SystemMotionStatus*/
/*RL_SystemMotionStatus*/
/*RR_SystemMotionStatus*/
#define _SystemMotionStatus_Unknown          0x0U
#define _SystemMotionStatus_Full_Open        0x1U
#define _SystemMotionStatus_Full_Close       0x2U
#define _SystemMotionStatus_Opening          0x3U
#define _SystemMotionStatus_Closing          0x4U
#define _SystemMotionStatus_Stopped          0x5U

/*FL_LatchMotionStatus*/
/*FR_LatchMotionStatus*/
/*RL_LatchMotionStatus*/
/*RR_LatchMotionStatus*/
#define _LatchMotionStatus_unknow          0x0U
#define _LatchMotionStatus_cinching        0x1U
#define _LatchMotionStatus_cinched         0x2U
#define _LatchMotionStatus_releasing       0x3U
#define _LatchMotionStatus_released        0x4U
#define _LatchMotionStatus_IceBreak        0x5U

/*FL_SetOpenAngleFb*/
/*FR_SetOpenAngleFb*/
/*RL_SetOpenAngleFb*/
/*RR_SetOpenAngleFb*/
#define _SetOpenAngleFb_No_Request        0x0U
#define _SetOpenAngleFb_50_Percent        0x1U
#define _SetOpenAngleFb_75_Percent        0x2U
#define _SetOpenAngleFb_100_Percent       0x3U


/*FL_ResetSwitch*/
/*FR_ResetSwitch*/
/*RL_ResetSwitch*/
/*RR_ResetSwitch*/
#define _ResetSwitch_Not_Active          0x0U
#define _ResetSwitch_Active              0x1U

/*FL_DoorCloseStatus*/
/*FR_DoorCloseStatus*/
/*RL_DoorCloseStatus*/
/*RR_DoorCloseStatus*/
#define _DoorCloseStatus_Close          0x0U
#define _DoorCloseStatus_Ajar           0x1U
#define _DoorCloseStatus_full_open      0x2U

/*FLWinPosn*/
/*FRWinPosn*/
/*RLWinPosn*/
/*RRWinPosn*/
#define _WinPosn_0_Percent            0x0U
#define _WinPosn_5_Percent            0x5U
#define _WinPosn_10_Percent           0xAU
#define _WinPosn_100_Percent          0x64U
#define _WinPosn_Invalid              0x7FU

/*BlowSpeedLevelDisplaySts*/
#define _BlowSpeedLevelDisplaySts_Not_Active  0x0U
#define _BlowSpeedLevelDisplaySts_Level_1     0x1U
#define _BlowSpeedLevelDisplaySts_Level_2     0x2U
#define _BlowSpeedLevelDisplaySts_Level_3     0x3U
#define _BlowSpeedLevelDisplaySts_Level_4     0x4U
#define _BlowSpeedLevelDisplaySts_Level_5     0x5U
#define _BlowSpeedLevelDisplaySts_Level_6     0x6U
#define _BlowSpeedLevelDisplaySts_Level_7     0x7U
#define _BlowSpeedLevelDisplaySts_Level_8     0x8U
#define _BlowSpeedLevelDisplaySts_Level_9     0x9U
#define _BlowSpeedLevelDisplaySts_Level_10    0xAU

/*CirculationModeDisplaySts*/
#define _CirculationModeDisplaySts_Recirculation_mode     0x0U
#define _CirculationModeDisplaySts_Air_circulation_mode   0x1U


/*FL_MotorFaultStatus*/
/*FR_MotorFaultStatus*/
/*RL_MotorFaultStatus*/
/*RR_MotorFaultStatus*/
#define _MotorFaultStatus_No_Fault             0x0U
#define _MotorFaultStatus_ActuatorMotorFault   0x1U
#define _MotorFaultStatus_CinchMotorFault      0x2U
#define _MotorFaultStatus_ReleaseMotorFault    0x3U
#define _MotorFaultStatus_ClutchFault          0x4U

/*FL_AntipinchEvent*/
/*FR_AntipinchEvent*/
/*RL_AntipinchEvent*/
/*RR_AntipinchEvent*/
#define _AntipinchEvent_Not_Active          0x0U
#define _AntipinchEvent_Active              0x1U

/*FL_PSDModeControlFb*/
/*FR_PSDModeControlFb*/
/*RL_PSDModeControlFb*/
/*RR_PSDModeControlFb*/
#define _PSDModeControlFb_Normal          0x0U
#define _PSDModeControlFb_Manual          0x1U
#define _PSDModeControlFb_SemiAutoMode    0x2U

/*FL_Reminder*/
/*FR_Reminder*/
/*RL_Reminder*/
/*RR_Reminder*/
#define _Reminder_No_hint                           0x0U
#define _Reminder_Door_opening_and_closing_prompt   0x1U
#define _Reminder_Obstacle_tips                     0x2U
#define _Reminder_Set_height_prompt                 0x3U

/*FL_RadarDetectRequirement*/
/*FR_RadarDetectRequirement*/
/*RL_RadarDetectRequirement*/
/*RR_RadarDetectRequirement*/
#define _RadarDetectRequirement_Not_Active     0x0U
#define _RadarDetectRequirement_Active         0x1U

/*FL_ADASDetectRequirement*/
/*FR_ADASDetectRequirement*/
/*RL_ADASDetectRequirement*/
/*RR_ADASDetectRequirement*/
#define _ADASDetectRequirement_Not_Active     0x0U
#define _ADASDetectRequirement_Active         0x1U

/*FL_ClutchStatus*/
/*FR_ClutchStatus*/
/*RL_ClutchStatus*/
/*RR_ClutchStatus*/
#define _ClutchStatus_Not_Active     0x0U
#define _ClutchStatus_Active         0x1U

/*FL_Inhibition*/
/*FR_Inhibition*/
/*RL_Inhibition*/
/*RR_Inhibition*/
#define _Inhibition_No_Fault                                0x0U
#define _Inhibition_MotorFault                              0x1U
#define _Inhibition_BatteryVoltageFault_ControlSupplyFault  0x2U
#define _Inhibition_PlayProtectionStatus                    0x3U
#define _Inhibition_MotorThermalProtectionStatus            0x4U
#define _Inhibition_PowerSupplyFault                        0x5U


/*FL_ReleaseLatch*/
/*FR_ReleaseLatch*/
/*RL_ReleaseLatch*/
/*RR_ReleaseLatch*/
#define _ReleaseLatch_No_Request     0x0U
#define _ReleaseLatch_Request        0x1U

/*FL_Warning*/
/*FR_Warning*/
/*RL_Warning*/
/*RR_Warning*/
#define _Warning_No_Warning     0x0U
#define _Warning_Warning        0x1U

/*FLDCM_2_DRMDetectRequirement*/
/*FRDCM_2_DRMDetectRequirement*/
/*RLDCM_2_DRMDetectRequirement*/
/*RRDCM_2_DRMDetectRequirement*/
#define _DCM_2_DRMDetectRequirement_DCMUnkownDefault     0x0U
#define _DCM_2_DRMDetectRequirement_DCMNormal            0x1U
#define _DCM_2_DRMDetectRequirement_ReqActive            0x2U
#define _DCM_2_DRMDetectRequirement_ReqSleep             0x3U

/*FLDCM_2_RCMDetectRequirement*/
/*FRDCM_2_RCMDetectRequirement*/
/*RLDCM_2_RCMDetectRequirement*/
/*RRDCM_2_RCMDetectRequirement*/
#define _DCM_2_RCMDetectRequirement_Not_Active     0x0U
#define _DCM_2_RCMDetectRequirement_Active         0x1U

/*FLDoorCurrentoperation*/
/*FRDoorCurrentoperation*/
/*RLDoorCurrentoperation*/
/*RRDoorCurrentoperation*/
#define _DoorCurrentoperation_No_Action       0x0U
#define _DoorCurrentoperation_Door_Close      0x1U
#define _DoorCurrentoperation_Door_Open       0x2U
#define _DoorCurrentoperation_Door_stopped    0x3U

/*FLDoorFunctionInhibit*/
/*FRDoorFunctionInhibit*/
/*RLDoorFunctionInhibit*/
/*RRDoorFunctionInhibit*/
#define _DoorFunctionInhibit_No_Inhibit     0x0U
#define _DoorFunctionInhibit_Inhibit        0x1U
#endif


#ifdef _CHERY_COM_PLG
/*ArmingSts*/
#define _ArmingSts_Not_active           0x0U
#define _ArmingSts_Arming_successful    0x1U
#define _ArmingSts_Disarming_successful 0x2U
#define _ArmingSts_Invalid              0x3U

/*BCM_4_KeySts*/
#define _BCM_4_KeySts_OFF        0x0U
#define _BCM_4_KeySts_ACC        0x1U
#define _BCM_4_KeySts_ON         0x2U
#define _BCM_4_KeySts_CRANK_ON   0x3U

/*BCM_4_DriverDoorLockSts*/
#define _BCM_4_DriverDoorLockSts_Lock        0x0U
#define _BCM_4_DriverDoorLockSts_Unlock      0x1U

/*RKE_TrunkSts*/
#define _RKE_TrunkSts_Not_active      0x0U
#define _RKE_TrunkSts_Long_Press      0x1U
#define _RKE_TrunkSts_Short_Press     0x2U
#define _RKE_TrunkSts_Not_used        0x3U

/*DrvrSidePLGSwt*/
#define _DrvrSidePLGSwt_Not_active   0x0U
#define _DrvrSidePLGSwt_active       0x1U

/*RVSMode*/
#define _RVSMode_Not_active      0x0U
#define _RVSMode_Active          0x1U

/*InformationSource*/
#define _InformationSource_Not_Used            0x0U
#define _InformationSource_SMART_Information   0x1U
#define _InformationSource_RKE_Information     0x2U
#define _InformationSource_Near_Access         0x3U

/*OrderInformation*/
#define _OrderInformation_OFF                      0x0U
#define _OrderInformation_Lock                     0x1U
#define _OrderInformation_Unlock                   0x2U
#define _OrderInformation_Trunk                    0x4U
#define _OrderInformation_Welcome                  0x5U
#define _OrderInformation_Welcome_off              0x6U
#define _OrderInformation_Power_slide_door_right   0xdU
#define _OrderInformation_Power_slide_door_left    0xeU

/*HandBrakeSystemSts*/
#define _HandBrakeSystemSts_Released                 0x0U
#define _HandBrakeSystemSts_Applied                  0x1U
#define _HandBrakeSystemSts_Releasing                0x2U
#define _HandBrakeSystemSts_Applying                 0x3U
#define _HandBrakeSystemSts_Unknown                  0x4U
#define _HandBrakeSystemSts_ErrorApplied             0x5U

/*ExternalTemperatureFailSts*/
#define _ExternalTemperatureFailSts_Fail_Not_Present              0x0U
#define _ExternalTemperatureFailSts_Fail_Present                  0x1U

/*NeutralGearSts*/
#define _NeutralGearSts_Not_in_Neutral           0x0U
#define _NeutralGearSts_Neutral                  0x1U

/*SSMStatus*/
#define _SSMStatus_Reset_Not_implemented    0x0U
#define _SSMStatus_Standby                  0x1U
#define _SSMStatus_Stopped                  0x2U
#define _SSMStatus_Starter_Restart          0x3U
#define _SSMStatus_Engine_Restart           0x4U
#define _SSMStatus_Operation                0x5U
#define _SSMStatus_Auto_Stopping            0x6U

/*GBPositoionDisplay*/
#define _GBPositoionDisplay_NO_Display  0x0U
#define _GBPositoionDisplay_Display_P   0x1U
#define _GBPositoionDisplay_Display_R   0x2U
#define _GBPositoionDisplay_Display_N   0x3U
#define _GBPositoionDisplay_Display_D   0x4U
#define _GBPositoionDisplay_Display_M1  0x5U
#define _GBPositoionDisplay_Display_M2  0x6U

/*CrashOutputSts*/
#define _CrashOutputSts_No_crash          0x00U
#define _CrashOutputSts_Belt_Crash        0x01U
#define _CrashOutputSts_Front_Crash       0x02U
#define _CrashOutputSts_Left_Side_Crash   0x04U
#define _CrashOutputSts_Right_Side_Crash  0x08U
#define _CrashOutputSts_Rear_Crash        0x10U

/*DVD_TrunkCmd*/
#define _DVD_TrunkCmd_Not_Active  0x0U
#define _DVD_TrunkCmd_Open        0x1U
#define _DVD_TrunkCmd_Close       0x2U
#define _DVD_TrunkCmd_Not_used    0x3U

/*DVD_Set_PLGPositionSts*/
#define _DVD_Set_PLGPositionSts_50_Pecent   0x32U
#define _DVD_Set_PLGPositionSts_70_Pecent   0x46U
#define _DVD_Set_PLGPositionSts_100_Pecent  0x64U

/*TBOX_TrunkCmd*/
#define _TBOX_TrunkCmd_Not_Active  0x0U
#define _TBOX_TrunkCmd_Open        0x1U
#define _TBOX_TrunkCmd_Close       0x2U
#define _TBOX_TrunkCmd_Not_used    0x3U

/*PEPS_PLGUnlockReq*/
#define _PEPS_PLGUnlockReq_Not_request  0x0U
#define _PEPS_PLGUnlockReq_UnLock       0x1U

/*PLG_LatchSts*/
#define _PLG_LatchSts_Open           0x0U
#define _PLG_LatchSts_Secondary      0x1U
#define _PLG_LatchSts_Latched        0x2U
#define _PLG_LatchSts_Initializing   0x3U

/*PLG_PinchEvent*/
#define _PLG_PinchEvent_Normal             0x0U
#define _PLG_PinchEvent_Antipinch_event    0x1U

/*PLG_OperateSts*/
#define _PLG_OperateSts_Stop      0x0U
#define _PLG_OperateSts_Open      0x1U
#define _PLG_OperateSts_Close     0x2U
#define _PLG_OperateSts_Opening   0x3U
#define _PLG_OperateSts_Closing   0x4U


/*PLG_GlobalSW*/
#define _PLG_GlobalSW_Not_active   0x0U
#define _PLG_GlobalSW_Open         0x1U
#define _PLG_GlobalSW_Close        0x2U
#define _PLG_GlobalSW_Reserved     0x3U

/*PLG_ECUFailSts*/
#define _PLG_ECUFailSts_Normal         0x0U
#define _PLG_ECUFailSts_PLG_ECU_Fail   0x1U

/*PLG_OperateInd*/
#define _PLG_OperateInd_Case1     0x0U
#define _PLG_OperateInd_Case2     0x1U
#define _PLG_OperateInd_Case3     0x2U
#define _PLG_OperateInd_Case4     0x3U

/*PLG_UnLockInformation*/
#define _PLG_UnLockInformation_Not_Active      0x0U
#define _PLG_UnLockInformation_KnickUnlock     0x1U
#define _PLG_UnLockInformation_PEUnlock        0x2U
#define _PLG_UnLockInformation_Reserved        0x3U

/*PLG_OperateStsValidData*/
#define _PLG_OperateStsValidData_Valid         0x0U
#define _PLG_OperateStsValidData_Not_Valid     0x1U

/*VehicleSpeed_Valid*/
#define _SPEED_VALID        0x0U
#define _SPEED_INVALID      0x1U
/*EngineEngine_Valid*/
#define _ENGINE_VALID       0x0U
#define _ENGINE_INVALID     0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID     0x0U
#define _ODOMETER_INVALID   0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

#define _Incline_Invalid    0x0U
#define _Incline_Valid      0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x1EU
#define _BUS_TEMPERATURE_80       0x10EU

#endif
#endif

#ifdef _SGM_COM
/*VehSpdAvgDrvnV*/
#define _SPEED_VALID         0x0U
#define _SPEED_INVALID       0x1U
/*EngineEngine_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x0U
#define _ODOMETER_INVALID       0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

/*SysPwrMd*/
#define _SysPwrMd_Off           0x0U
#define _SysPwrMd_Accessory     0x1U
#define _SysPwrMd_Run           0x2U
#define _SysPwrMd_Crank_Request 0x3U
/*SysPwrMdV*/
#define _SysPwrMdV_Valid       0x0U
#define _SysPwrMdV_Invalid     0x1U

/*TrnsShftLvrPos*/
#define _TrnsShftLvrPos_Park      0x1U
#define _TrnsShftLvrPos_Reverse   0x2U
#define _TrnsShftLvrPos_Neutral   0x3U
#define _TrnsShftLvrPos_Forward   0x4U

/*TrnsShftLvrPosV*/
#define _TrnsShftLvrPosV_Valid       0x0U
#define _TrnsShftLvrPosV_Invalid     0x1U

/*AlrmStat*/
#define _AlrmStat_Off            0x0U
#define _AlrmStat_Armed          0x1U
#define _AlrmStat_Disarmed       0x2U
#define _AlrmStat_Alarm_Active   0x3U
#define _AlrmStat_Arming_Delay   0x4U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*CLRAF_Unl_Lk*/
#define _CLRAF_Unl_Lk_No_Command      0x0U
#define _CLRAF_Unl_Lk_Unlock          0x1U
#define _CLRAF_Unl_Lk_Lock            0x2U

/*PwrLftgtMotStat*/
#define _PwrLftgtMotStat_Unknown      0x0U
#define _PwrLftgtMotStat_Full_Open    0x1U
#define _PwrLftgtMotStat_Closed       0x2U
#define _PwrLftgtMotStat_Opening      0x3U
#define _PwrLftgtMotStat_Closing      0x4U
#define _PwrLftgtMotStat_Stopped      0x5U

/*EnhSrvRClsRlsRq*/
#define _EnhSrvRClsRlsRq_No_Action     0x0U
#define _EnhSrvRClsRlsRq_Release       0x1U

/*RFRmtCntFobNm*/
#define _PwrLftgtMotStat_No_Fob      0x0U
#define _PwrLftgtMotStat_Fob_1       0x1U
#define _PwrLftgtMotStat_Fob_2       0x2U

/*RFRmtCntrlFobFnc*/
#define _RFRmtCntrlFobFnc_No_Activation                           0x0U
#define _RFRmtCntrlFobFnc_All_Door_Unlock                         0x3U          
#define _RFRmtCntrlFobFnc_Engine_Run                              0xBU
#define _RFRmtCntrlFobFnc_Engine_Stop                             0xCU
#define _RFRmtCntrlFobFnc_Pwr_Rr_Closure_Stop_Motion_Control      0x14U
#define _RFRmtCntrlFobFnc_Pwr_Rr_Closure_Start_Motion_Control     0x15U    
#define _RFRmtCntrlFobFnc_Comfort_Open                            0x18U
#define _RFRmtCntrlFobFnc_Comfort_Close                           0x19U

/*LRWndPosStat*/
/*DrvWndPosStat*/
/*RRWndPosStat*/
/*PsWndPosStat*/
#define _WndPosStat_Fully_Closed        0x0U
#define _WndPosStat_Open_Less_Than_A    0x1U
#define _WndPosStat_Position_A          0x2U
#define _WndPosStat_Position_B          0x3U
#define _WndPosStat_Position_C          0x4U
#define _WndPosStat_Open_More_Than_C    0x5U
#define _WndPosStat_Fully_Opened        0x6U

/*Chime_Command_PLG*/
#define _Chime_Comand_PLG_1     0x1U 
#define _Chime_Comand_PLG_2     0x2U 
#define _Chime_Comand_PLG_3     0x3U 
#define _Chime_Comand_PLG_4     0x4U 

#endif

#ifdef _SGMW_COM
/*PEPS_Door_Lock_Command*/
/*DoorLockCmdIn*/
#define _DOOR_NO_COMMAND        0x0U
#define _DOOR_ALL_DOOR_LOCK     0x1U
#define _DOOR_ALL_DOOR_UNLOCK   0x3U
#define _DOOR_TRUNK_UNLOCK      0x4U
#define _DOOR_PEPS_KICKSNS      0x6U

/*FobCmdIn*/
#define _FOB_NO_COMMAND               0x0U
#define _FOB_ALL_DOOR_LOCK            0x1U
#define _FOB_ALL_DOOR_UNLOCK          0x3U
#define _FOB_TRUNK_OPEN_LONG_PRESS    0x4U
#define _FOB_TRUNK_OPEN_SHORT_PRESS   0xAU

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*SystemPowerMode*/
#define _POWER_MODE_OFF   0x0U
#define _POWER_MODE_ACC   0x1U
#define _POWER_MODE_ON    0x2U
#define _POWER_MODE_START 0x3U

/*VehicleGearLever*/
#define _GEAR_LEVER_PARK      0xFU
#define _GEAR_LEVER_REVERSE   0xEU
#define _GEAR_LEVER_NEUTRAL   0xDU
#define _GEAR_LEVER_FIRST     0x1U
#define _GEAR_LEVER_SECOND    0x2U
#define _GEAR_LEVER_THIRD     0x3U
#define _GEAR_LEVER_FOURTH    0x4U
#define _GEAR_LEVER_FIFTH     0x5U
#define _GEAR_LEVER_SIXTH     0x6U
#define _GEAR_LEVER_SEVEN     0x7U
#define _GEAR_LEVER_EIGHT     0x8U

/*VehicleSpeed_Valid*/
#define _SPEED_VALID         0x0U
#define _SPEED_INVALID       0x1U
/*EngineSpeed_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x0U
#define _ODOMETER_INVALID       0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

/*AppAuthorize_Valid*/
#define _AUTHORIZE_VALID         0x0U
#define _AUTHORIZE_INVALID       0x1U

/*_GEAR_INVALID*/
#define _GEAR_VALID         0x0U
#define _GEAR_INVALID       0x1U

/*VehicleLockUnlock*/
#define _DOOR_LOCKED     0x1U
#define _DOOR_UNLOCKED   0x3U

/*AntiTheft*/
#define _ANTITHEFT_PREDISARM   0x0U
#define _ANTITHEFT_DISARM      0x1U
#define _ANTITHEFT_PREARM      0x2U
#define _ANTITHEFT_HALFARM     0x3U
#define _ANTITHEFT_FULLARM     0x4U
#define _ANTITHEFT_FULLALARM   0x5U
#define _ANTITHEFT_TRIGGER     0x6U

/*PowerOperationCommandActive*/
#define _NO_COMMAND               0x00U
#define _COCKPIT_SWITCH_ACTIVE    0x01U
#define _HANDLE_SWITCH_ACTIVE     0x02U
#define _SHUTFACE_SWITCH_ACTIVE   0x03U
#define _KICK_SENSOR_ACTIVE       0x04U
#define _REMOTE_KEY_ACTIVE        0x05U
#define _PEPS_SENSORLESS_AUTOMATIC_TRUNK_OPEN        0x05U

/*PLGGaragePositionSetReqSta*/
#define _NO_CHANGE     0x0U
#define _CHANGE        0x1U

/*MessageTx_GateOpenAngle_Valid*/
#define _ANGLE_VALID         0x0U
#define _ANGLE_INVALID       0x1U

/*PLGGaragePositionSetReqSta*/
#define _VALID         0x0U
#define _INVALID       0x1U

/*Initiative Enter Command*/
#define _NO_COMMAND               0x00U
#define _PEPS_WALREQ              0x01U
#define _PEPS_APUREQ              0x02U
#define _PEPS_SATO_TRUNK_UNLOCK   0x03U

/*PLGDspMsgReq*/
#define _NO_DISPLAY               0x00U
#define _VEHICLE_IS_NOT_IN_PARK   0x01U


typedef enum
{
   Unknown = 0,      /*0U*/
   FullOpen,         /*1U*/
   Closed,           /*2U*/
   Opening,          /*3U*/
   Closing,          /*4U*/
   Stopped,          /*5U*/
   
}tD_GateMotion;

typedef enum
{
   Default = 0,      /*0U*/
   Cinching,         /*1U*/
   Cinched,          /*2U*/
   Releasing,        /*3U*/
   Released          /*4U*/
   
}tD_LatchMotion;

#endif



#ifdef _CTCS_COM
/*SystemPowerMode*/
#define _STAT_TERMINAL_OFF     0x00U
#define _STAT_TERMINAL_ACC     0x01U
#define _STAT_TERMINAL_ON      0x02U
#define _STAT_TERMINAL_START   0x03U
#define _STAT_TERMINAL_INVALID 0x07U

/*EngineState*/
#define _ENGINE_INIT                           0x00U
#define _ENGINE_STOPPED                        0x01U
#define _ENGINE_ACTIVATION_STARTER_POWERSTAGE  0x02U
#define _ENGINE_RUNNING                        0x03U
#define _ENGINE_RUN_IN_LIMP_HOME_MODE          0x04U

/*VehicleGearLever*/
#define _STAT_LEVER_P               0x01U
#define _STAT_LEVER_R               0x02U
#define _STAT_LEVER_N               0x03U
#define _STAT_LEVER_D               0x04U
#define _STAT_LEVER_M               0x05U
#define _STAT_LEVER_FAIILURE_VALUE  0x06U
#define _STAT_LEVER_INVALID         0x07U

/*VehicleSpeed_Valid*/
#define _SPEED_VALID         0x0U
#define _SPEED_INVALID       0x1U
/*EngineSpeed_Valid*/
#define _ENGINE_VALID         0x0U
#define _ENGINE_INVALID       0x1U
/*Odometer_Valid*/
#define _ODOMETER_VALID         0x0U
#define _ODOMETER_INVALID       0x1U
/*TimeInformation_Valid*/
#define _TIME_VALID         0x0U
#define _TIME_INVALID       0x1U

/*BusTemperature*/
#define _BUS_TEMPERATURE_N40      0x0U
#define _BUS_TEMPERATURE_80       0xF0U

/*VR_PLG*/
#define _PLG_NO_REQUEST           0x0U
#define _PLG_CLOSE_REQUEST        0x1U
#define _PLG_OPEN_REQUEST        0x2U
#define _PLG_STOP_REQUEST        0x3U

/*TGW_Tailgate_Request*/
#define _NO_COMMAND           0x0U
#define _TAILGATE_OPEN        0x1U
#define _TAILGATE_CLOSE        0x2U
#define _TAILGATE_STOP        0x3U

/*PLGGaragePositionSetReqSta*/
#define _VALID         0x0U
#define _INVALID       0x1U

 /*PLG_AutoOperation*/
#define _NO_OPERATION                       0x0U
#define _PLG_OPEN_OPERATION                 0x1U
#define _PLG_HEIGHT_MEMORY_SET_SUCCESSFUL   0x2U
#define _PLG_OPERATION_INHIBITION           0x3U
#define _PLG_CLOSE_OPERATION                0x4U
#define _PLG_RUNNINING_OPERATION            0x1U

/*PLG_RemoteCtrlFailReason*/
#define _NO_FAIL_REASON                     0x0U
#define _FAIL_BY_TEMPERATURE                0x1U
#define _FAIL_BY_VOLTAGE                    0x2U
#define _FAIL_BY_PLAY_PROTECTION            0x3U
#define _FAIL_BY_OBSTRUCTER                 0x4U
#define _FAIL_BY_SYSTEM_ERROR               0x5U
#define _FAIL_BY_LOCAL_OPERATION            0x6U

/*RKECmd*/
#define _RKE_NO_COMMAND         0x0U
#define _RKE_ALL_DOOR_LOCK      0x1U
#define _RKE_ALL_DOOR_UNLOCK    0x3U
#define _RKE_TRUNK_UNLOCK       0x4U
#define _RKE_TRUNK_STOP         0x8U
#define _RKE_VEHICLE_SEACH      0x9U

/*SATOReminder*/
#define _SATO_REMIND_NO_COMMAND   0x0U
#define _SATO_REMIND_STOP         0x1U
#define _SATO_REMIND_START        0x2U

/*SATOReq*/
#define _SATO_NO_REQUEST   0x0U
#define _SATO_REQUEST      0x1U

/*TrunkCockpitSwitch*/
#define _COCKPIT_NO_ACTION    0x0U
#define _COCKPIT_ACTION       0x1U
#define _COCKPIT_STOP         0x2U

/*STAT_WindowPosition*/
#define _WINDOW_CLOSE          0x0U
#define _WINDOW_CLOSE_VENT     0x1U
#define _WINDOW_VENT           0x2U
#define _WINDOW_VENT_OPEN_1_4  0x3U
#define _WINDOW_OPEN_1_4       0x4U
#define _WINDOW_OPEN_1_4_1_2   0x5U
#define _WINDOW_OPEN_1_2       0x6U
#define _WINDOW_OPEN_1_2_3_4   0x7U
#define _WINDOW_OPEN_3_4       0x8U
#define _WINDOW_OPEN_3_4_FULLY 0x9U
#define _WINDOW_OPEN           0xaU
#define _WINDOW_INITIAL_VALUE  0xbU

/*STAT_DoorAjar*/
#define _DOOR_CLOSED     0x0U
#define _DOOR_OPENED     0x1U

/*STAT_BlowerSpeed*/
#define _BLOWERSPEED_LEVEL0     0x0U
#define _BLOWERSPEED_LEVEL1     0x1U
#define _BLOWERSPEED_LEVEL2     0x2U
#define _BLOWERSPEED_LEVEL3     0x3U
#define _BLOWERSPEED_LEVEL4     0x4U
#define _BLOWERSPEED_LEVEL5     0x5U
#define _BLOWERSPEED_LEVEL6     0x6U
#define _BLOWERSPEED_LEVEL7     0x7U
#define _BLOWERSPEED_DEFAULT    0xFU

/*SunroofPosition*/
#define _SUNROOF_UNINITIALIZED     0x0U
#define _SUNROOF_FULLY_CLOSED      0x1U
#define _SUNROOF_VENTAREA          0x2U
#define _SUNROOF_TILT_UP           0x3U
#define _SUNROOF_COMFORTABLE_TILT  0x4U
#define _SUNROOF_COMFORTABLE_OPEN  0x5U
#define _SUNROOF_COMFORTABLE_FULLY 0x6U
#define _SUNROOF_FULLY_OPEN        0x7U

/*WarningMessageID*/
#define _WARNING_INIT            0x0U
#define _WARNING_FAILURE         0x1U
#define _WARNING_INHIBITION      0x2U


/*BitStatus*/
#define _BITSTATUS_SET      0x0U
#define _BITSTATUS_RESET    0x1U

/*Set_ToDefault*/
#define _SET_VEHICLE_TO_DEFAULT           0x0U
#define _SET_PERSONALIZATION_TO_DEFAULT   0x1U
#define _SET_TELEMATICS_TO_DEFAULT        0x2U
#define _SET_SYSTEM_TO_DEFAULT            0x3U
#define _SET_ALL_TO_DEFAULT               0x4U
#define _SET_IGNORE                       0x7U

#define _GARAGE_HEIGHT_70_DEGREE     0xB1
#define _GARAGE_HEIGHT_100_DEGREE    0xFF

typedef enum
{
   FullyOpened = 0,    /*0U*/
   FullyClosed,        /*1U*/
   Opening,            /*2U*/
   Closing,            /*3U*/
   PLGStopped,         /*4U*/
   LatchReleasing,     /*5U*/
   LatchCinching,      /*6U*/  
   MovingByManual      /*7U*/ 
}tD_GateMotion;

#ifdef _CONFIG_LIN_Slave
/*Cmd_OpenTrunkFOBKey*/
#define _FOB_NO_ACTION        0x0U
#define _FOB_ACTION           0x1U
#define _FOB_STOP             0x2U
#define _FOB_INVALID_SIGNAL   0x3U

/*Cmd_OpenTrunkCockpitSW*/
#define _FOB_NO_ACTION        0x0U
#define _FOB_ACTION           0x1U
#define _FOB_STOP             0x2U
#define _FOB_INVALID_SIGNAL   0x3U


/*STAT_PLGMalfunction*/
#define _PLGMalfunction_NO_ERROR   0x0U
#define _PLGMalfunction_ERROR      0x1U

/*PLG_RspError*/
#define _PLG_RspError_NO_ERROR   0x0U
#define _PLG_RspError_ERROR      0x1U
#endif

/*STAT_PLG_Cal*/
#define _PLG_CAL_NOTUSED      0x0U
#define _PLG_CAL_LEARNED      0x1U
#define _PLG_CAL_UNLEARNED    0x2U
#define _PLG_CAL_INVALID      0x3U

/*STAT_PawlLatchSwitch, STAT_StrikerLatchSwitch*/
#define _SWITCH_NOTUSED        0x0U
#define _SWITCH_OPEN           0x1U
#define _SWITCH_CLOSED         0x2U
#define _SWITCH_INVALID        0x3U

#endif

typedef enum
{
   PowerMode_OFF = 0,    /*0U*/
   PowerMode_ACC,        /*1U*/
   PowerMode_ON,         /*2U*/
   PowerMode_CRANK,      /*3U*/
   PowerMode_START,      /*4U*/ 
   PowerMode_RemoteON    /*5U*/ 
}tD_PowerMode;

typedef enum
{
   AntiTheft_Predisarm = 0, /*0U*/
   AntiTheft_Disarm,        /*1U*/
   AntiTheft_Prearm,        /*2U*/
   AntiTheft_Halfarm,       /*3U*/
   AntiTheft_Arm,       /*4U*/ 
   AntiTheft_Alarm      /*5U*/
}tD_AntiTheft;

typedef enum
{
   GearLever_P = 0,    /*0U*/
   GearLever_R,        /*1U*/
   GearLever_N,        /*2U*/
   GearLever_D,        /*3U*/
   GearLever_M         /*4U*/ 
}tD_GearLever;

typedef enum
{
   VehicleMode_Normal = 0,    /*0U*/
   VehicleMode_Transport,     /*1U*/
   VehicleMode_Exhibition,    /*2U*/
   VehicleMode_Factory,       /*3U*/
   VehicleMode_Crash,         /*4U*/
   VehicleMode_TestMode       /*5U*/
}tD_VehicleMode;


typedef enum
{
   LatchSignal_Close = 0,    /*0U*/
   LatchSignal_Ajar,         /*1U*/
   LatchSignal_Open,         /*2U*/
   LatchSignal_Error,        /*3U*/
   
}tD_LatchSignal;


/*********************************************************************************************
** MACROS
**********************************************************************************************/


#include "typedefs.h"
#include "S32K144Types.h"
//#include "pinout_manage.h"

/*********************************************************************************************
** Global Variables Declarations
**********************************************************************************************/
/*Transmit message*/ 

#ifdef _SGMW_COM
extern tD_LatchMotion MessageTx_LatchMotion;
extern tD_GateMotion MessageTx_GateMotion;
#endif

#ifdef _CONFIG_MessageTx_Information
extern uint8_t MessageTx_MessageCounter;
extern uint8_t MessageTx_Reserved;
#endif


#ifdef _VOYAH_COM
#ifdef _VOYAH_COM_PD
extern uint8_t MessageTx_POD_DoorReleaseLatch;
extern uint8_t MessageTx_POD_DoorSts;
extern uint8_t MessageTx_POD_DoorAssistantSts;
extern uint8_t MessageTx_POD_ElectricDoorCtlSts;
extern uint8_t MessageTx_POD_DoorOpenSpdSts;
extern uint8_t MessageTx_POD_PowerDoorAntiWindSts;
extern uint8_t MessageTx_POD_PowerDoorSafeBeltSts;
extern uint8_t MessageTx_POD_DoorPositionSts;
extern uint8_t MessageTx_POD_OpenValueSts;

extern uint8_t MessageTx_POD_FaultStatus;
extern uint8_t MessageTx_POD_ODRCDetectRequirement;
extern uint8_t MessageTx_POD_PowerDoorBrakeSts;
extern uint8_t MessageTx_POD_DoorProtectResult;
extern uint16_t MessageTx_POD_DoorCurrentValue;
extern uint16_t MessageTx_POD_DoorHallValue;
extern uint8_t MessageTx_POD_DoorVoltageValue;
extern uint8_t MessageTx_POD_DoorInhibition;
#endif
#endif


#ifdef _CHERY_COM
#ifdef _CHERY_COM_PLG
extern uint8_t MessageTx_PLG_PositionSts;
extern uint8_t MessageTx_PLG_Set_MaxPosition;
extern uint8_t MessageTx_PLG_LatchSts;
extern uint8_t MessageTx_PLG_PinchEvent;
extern uint8_t MessageTx_PLG_OperateSts;
extern uint8_t MessageTx_PLG_GlobalSW;
extern uint8_t MessageTx_PLG_ECUtemp;            
extern uint8_t MessageTx_PLG_OperateStsValidData;  
extern uint8_t MessageTx_PLG_UnLockInformation;
extern uint8_t MessageTx_PLG_OperateInd;
extern uint8_t MessageTx_PLG_ECUFailSts; 

#ifdef _CONFIG_LIN_Master
extern uint8_t MessageTx_TowHookEnd_position; 
extern uint8_t MessageTx_KSEnable;
extern uint8_t MessageTx_TailgatePosition;
extern uint8_t MessageTx_VehicleType;
extern uint8_t MessageTx_TailgateMovementCloseState;
extern uint8_t MessageTx_TailgateMovementOpenState;
extern uint8_t MessageTx_CatchBoltStatus;
extern uint8_t MessageTx_PawlStatus;

extern uint16_t MessageRx_KS_Dummy;
extern uint8_t MessageRx_KS_SignalizesApproaching;     
extern uint8_t MessageRx_KS_VehicleTypeUnknown; 
extern uint8_t MessageRx_KS_Wake_UpProtected; 
extern uint8_t MessageRx_KS_Over_VoltageDetected; 
extern uint8_t MessageRx_KS_Under_VoltageDetected; 
extern uint8_t MessageRx_KS_ElectrodeDetected; 
extern uint8_t MessageRx_KS_ECUROMErrorCheck; 
extern uint8_t MessageRx_KS_SensorErrorDetected; 
extern uint8_t MessageRx_KS_ResponseError; 
extern uint8_t MessageRx_KS_SensorStatus;
#endif
#endif
#ifdef _CHERY_COM_PD
extern uint8_t MessageTx_LearnedStatus;
extern uint8_t MessageTx_CurrentOpenPosition;
extern uint8_t MessageTx_SetOpenAngleFb;
extern uint8_t MessageTx_SystemMotionStatus;
extern uint8_t MessageTx_LatchMotionStatus;
extern uint8_t MessageTx_ResetSwitch;
extern uint8_t MessageTx_DoorCloseStatus;
extern uint8_t MessageTx_MotorFaultStatus;
extern uint8_t MessageTx_AntipinchEvent;
extern uint8_t MessageTx_PSDModeControlFb;
extern uint8_t MessageTx_Reminder;
extern uint8_t MessageTx_RadarDetectRequirement;
extern uint8_t MessageTx_ADASDetectRequirement;
extern uint8_t MessageTx_ClutchStatus;
extern uint8_t MessageTx_Inhibition;
extern uint8_t MessageTx_ReleaseLatch;
extern uint8_t MessageTx_Warning;
	
extern uint8_t MessageTx_DCM_2_DRMDetectRequirement;
extern uint8_t MessageTx_DCM_2_RCMDetectRequirement;
extern uint8_t MessageTx_DCM_2_SystemMotionStatus;
extern uint8_t MessageTx_DCM_2_CurrentOpenPosition;
extern uint8_t MessageTx_DCM_2_SetOpenAngleFb;
extern uint8_t MessageTx_DCM_2_DCMAngularSpeed;
extern uint8_t MessageTx_DoorCurrentoperation;
extern uint8_t MessageTx_DoorFunctionInhibit;

extern uint8_t MessageTx_DCM_3_BLEOpenDriverDoorFB;
extern uint8_t MessageTx_DCM_3_PedalCloseDriverDoorFB;
extern uint8_t MessageTx_DCM_3_DoorRemoteKeyControlFB;
extern uint8_t MessageTx_DCM_3_DoorVoiceControlFB;
extern uint8_t MessageTx_DCM_3_ParkDoorControlNotice;
extern uint8_t MessageTx_DoorMotionDirection;

extern uint8_t MessageTx_DCM_TotalFaultNum;	
extern uint8_t MessageTx_DCM_FrameIndex;
extern uint8_t MessageTx_DCM_SupplierNum;	
extern uint16_t MessageTx_DCM_FaultNum1;
extern uint16_t MessageTx_DCM_FaultNum2;
extern uint16_t MessageTx_DCM_FaultNum3;
extern uint16_t MessageTx_DCM_FaultNum4;

extern uint8_t MessageTx_DCM_1_RollgCntr1;
extern uint8_t MessageTx_DCM_2_RollgCntr1;
extern uint8_t MessageTx_DCM_3_RollgCntr1;
#endif
#endif



#ifdef _AUDI_COM
#ifdef _AUDI_COM_PLG
#endif   

#ifdef _AUDI_COM_PD
extern uint16_t MessageTx_SDD_DoorPos;
extern uint16_t MessageTx_SDD_DoorAngSpd;
extern uint8_t MessageTx_SDD_ReqREDSMode;
extern uint8_t MessageTx_SDD_DoorMovement;
extern uint8_t MessageTx_SDD_DoorAddress;
extern uint8_t MessageTx_SDD_VehSpeed;
extern uint8_t MessageTx_SDD_VehPitchAngle;
extern uint8_t MessageTx_SDD_VehRollAngle;

extern uint8_t MessageTx_DduStatus_DoorPos;
extern uint8_t MessageTx_DduStatus_StopNotif;
extern uint8_t MessageTx_DduStatus_DriveCurrent;
extern uint8_t MessageTx_DduStatus_DriveSpeed;
extern uint8_t MessageTx_DduStatus_DoorState;
extern uint8_t MessageTx_DduStatus_ObwRequest;
extern uint8_t MessageTx_DduStatus_OperationState;
extern uint8_t MessageTx_DduStatus_HardHoldFuncState;
extern uint8_t MessageTx_DduStatus_EmergCloseFuncState;
extern uint8_t MessageTx_DduStatus_PosRange;
extern uint8_t MessageTx_DduStatus_LatchState;
extern uint8_t MessageTx_DduStatus_ServoDisReason;

extern uint8_t MessageTx_DtcStat_ResponseError;
extern uint8_t MessageTx_DtcStat_Normalization;
extern uint8_t MessageTx_DtcStat_ThermoProtWarn;
extern uint8_t MessageTx_DtcStat_ThermoProtHot;
extern uint8_t MessageTx_DtcStat_VoltageErrOV;
extern uint8_t MessageTx_DtcStat_VoltageErrUV;
extern uint8_t MessageTx_DtcStat_HallErr;
extern uint8_t MessageTx_DtcStat_LatchErr;
extern uint8_t MessageTx_DtcStat_SensorFault;
extern uint8_t MessageTx_DtcStat_CurrMeasFault;
extern uint8_t MessageTx_DtcStat_DoorMotFaultOC;
extern uint8_t MessageTx_DtcStat_DoorMotFaultOL;
extern uint8_t MessageTx_DtcStat_DoorMotFaultSC;
extern uint8_t MessageTx_DtcStat_WrongDirErr;
extern uint8_t MessageTx_DtcStat_ParaFault;
extern uint8_t MessageTx_DtcStat_ParaMismatch;
extern uint8_t MessageTx_DtcStat_MemErr;
extern uint8_t MessageTx_DtcStat_RadarCommErr;

extern uint8_t MessageTx_RedsStat_FaultOvervoltage;
extern uint8_t MessageTx_RedsStat_FaultUndervoltage;
extern uint8_t MessageTx_RedsStat_FaultRamFault;
extern uint8_t MessageTx_RedsStat_FaultOvertemp;
extern uint8_t MessageTx_RedsStat_FaultCalibData;
extern uint8_t MessageTx_RedsStat_FaultFunctionDegrad;
extern uint8_t MessageTx_RedsStat_StopAngle;
extern uint8_t MessageTx_RedsStat_ActFuncMode;
extern uint8_t MessageTx_RedsStat_SysState;

extern uint8_t MessageTx_Reds_ObjectPosX;
extern uint8_t MessageTx_Reds_ObjectPosY;
extern uint8_t MessageTx_Reds_ObjectPosZ;
extern uint8_t MessageTx_Reds_ObjectDoorDstnc;

extern uint8_t MessageTx_InclInfoFromSDDtoGW_RollAngleValidF;
extern uint16_t MessageTx_InclInfoFromSDDtoGW_RollAngle;
extern uint8_t MessageTx_InclInfoFromSDDtoGW_PitchAngleValidF;
extern uint16_t MessageTx_InclInfoFromSDDtoGW_PitchAngle;
#endif
#endif


#ifdef _CTCS_COM 
extern uint8_t MessageTx_PLG_AutoOperation;
extern tD_GateMotion MessageTx_GateMotion;
#ifdef _CONFIG_CAN_Bus
extern uint8_t MessageTx_WarningMessageID_PLG;
extern uint8_t MessageTx_BitStatus_PLG;
extern uint8_t MessageTx_PLG_RemoteCtrlFailReason;
#endif
#ifdef _CONFIG_LIN_Slave
extern uint8_t MessageTx_PLGMalfunction;
extern uint8_t MessageTx_PLG_RspError;
#endif
#endif

#ifdef _DEARCC_COM 
extern tD_PLGConditionFault MessageTx_PLGConditionFault;
extern uint8_t MessageTx_PLGConditionFault_Status;
extern tD_GateMotion MessageTx_GateMotion;
#endif

#ifdef _MAXUS_COM
#ifdef _MAXUS_COM_PLG
extern uint8_t MessageTx_PLGECUSts;
extern uint8_t MessageTx_TlgtOprt;
extern uint8_t MessageTx_TlgtPosSts;
extern uint8_t MessageTx_TlgtPinchRvsEvt;
extern uint8_t MessageTx_TlgtStlEvt;
extern uint8_t MessageTx_TlgtLtchSts;
extern uint8_t MessageTx_TlgtOprtMd;
extern uint8_t MessageTx_TlgtLtchOvht;
extern uint8_t MessageTx_TlgtSpdlOvht;
extern uint8_t MessageTx_TlgtAPSSts_L;
extern uint8_t MessageTx_TlgtAPSSts_R;
extern uint8_t MessageTx_TlgtCnchMtrSts;
extern uint8_t MessageTx_TlgtSpdlMtrSts;
extern uint8_t MessageTx_TlgtBuzReq;
extern uint8_t MessageTx_TlgtFlshReq;
extern uint8_t MessageTx_TlgtAbsAlrm;
extern uint8_t MessageTx_TlgtOpnPos;
extern uint8_t MessageTx_DiagSession;

/*Debug_Msg*/
extern uint8_t MessageTx_BATT1;
extern uint8_t MessageTx_BATT2;
extern uint16_t MessageTx_LatchCurrent;
extern uint16_t MessageTx_SpindleCurrent;
extern uint16_t MessageTx_SpindleCurrentOffset;
extern uint8_t MessageTx_LatchPWM;
extern uint8_t MessageTx_SpindlePWM;

extern uint8_t MessageTx_SpindleMovingSection;
extern uint16_t MessageTx_HallSpeedReal;
extern uint16_t MessageTx_HallSpeedSet;
extern uint16_t MessageTx_HallReal;
extern uint16_t MessageTx_HallMaxSet;
extern uint8_t MessageTx_StallEventSpindle;

extern uint16_t MessageTx_HallParkSet;
extern uint16_t MessageTx_HallMaxAngle;
extern uint8_t KickSensor_OnlyVehicleNotPark_Status;
#endif
#ifdef _MAXUS_COM_PSD
extern uint8_t MessageTx_SldDrPos;
extern uint8_t MessageTx_SldDrOhpSts;
extern uint8_t MessageTx_SldDrOprtSts;
extern uint8_t MessageTx_PSDErrSts;
extern uint8_t MessageTx_SldDrOprtMd;
extern uint8_t MessageTx_Ajr_FulBx;
extern uint8_t MessageTx_SldDrPosSts;
extern uint8_t MessageTx_SldDrTchPdSw;	
extern uint8_t MessageTx_ChldLckSts;
extern uint8_t MessageTx_SldDrIntSw;
extern uint8_t MessageTx_SldDrDrSw;
extern uint8_t MessageTx_SldDrLckSts;
extern uint8_t MessageTx_PSDObsSts;
extern uint8_t MessageTx_SldDrLtcSts;
extern uint8_t MessageTx_SldDrAbsAlrm;
#endif	
#endif

#ifdef _DFMC_COM
extern uint8_t MessageTx_pot_CatchSWSts;
extern uint8_t MessageTx_pot_PawlSWSts;
extern uint8_t MessageTx_pot_tailgateOpenSwSts;
extern uint8_t MessageTx_pot_tailgateOpenFailWarning;
extern uint8_t MessageTx_pot_tailgateCloseFailWarning;
extern uint8_t MessageTx_pot_tailgateOpenSts;
extern uint8_t MessageTx_pot_tailgateLearnedPosition;    
extern uint8_t MessageTx_pot_doorMemoryPosEnb;
extern uint8_t MessageTx_pot_antiPlayWarning;
extern uint8_t MessageTx_pot_tailgateCloseSwSts;
extern uint8_t MessageTx_pot_workingSts;
extern uint8_t MessageTx_pot_OpenTurnIndicator;
extern uint8_t MessageTx_pot_OpenValue;
extern uint8_t MessageTx_pot_NeutralSWSts;
extern uint8_t MessageTx_pot_MotorOverTempProtection;
extern uint8_t MessageTx_pot_delayClosingPotReq; 
#endif

#ifdef _BAIC_COM
extern uint8_t MessageTx_PtmPosnSts;	
extern uint8_t MessageTx_PtmSetMaxPosn;
extern uint8_t MessageTx_PtmLtchSts;
extern uint8_t MessageTx_PtmOperSts;
extern uint8_t MessageTx_PtmOperIndcnLi;
extern uint8_t MessageTx_PtmEcuFailSts;	
extern uint8_t MessageTx_PtmFotKicReq;	
extern uint8_t MessageTx_PtmPwrEnaSts;
extern uint8_t MessageTx_PtmFotKicEnaSts;	
extern uint8_t MessageTx_PtmWarnMsg;	
extern uint8_t MessageTx_PtmMod;
extern uint8_t MessageTx_PtmPncEve;	
extern uint8_t MessageTx_PtmOperIndcnSound;
extern uint8_t MessageTx_PtmSoundEnaSts;
extern uint8_t MessageTx_PtmLiEnaSts;	
extern uint8_t MessageTx_PtmLiEnaSts;
extern uint8_t MessageTx_PtmLrnSts;
extern uint8_t MessageTx_InsidSwt;
extern uint8_t MessageTx_PtmMaxPosnSts;
extern uint8_t MessageTx_SecSwt;
extern uint8_t MessageTx_LtchSwt;
  #ifdef _BAIC_COM_C46DB
extern uint8_t MessageTx_PLGM_TrActnHandCmd;
extern uint8_t MessageTx_PLGM_OperMod;
  #endif
#endif

#ifdef _DFLZM_COM
extern uint8_t MessageTx_PLG1_RQ_HazardRemind_Mode;
extern uint8_t MessageTx_PLG1_Status_CurrentState_Mode;
extern uint8_t MessageTx_PLG1_Fdbk_PLGSystemMotion ;	
extern uint8_t MessageTx_PLG1_Status_PLGLearing;
extern uint8_t MessageTx_PLG1_Fdbk_PLGOpen_Lvl;
extern uint8_t MessageTx_PLG1_Status_Secondary_Pos;	
extern uint8_t MessageTx_PLG1_Status_LatchReset;
extern uint8_t MessageTx_PLG1_Status_LatchPawl;
extern uint8_t MessageTx_PLG1_Status_MotorStall;	
extern uint8_t MessageTx_PLG1_Status_DoorOpenRatio_Value;
extern uint8_t MessageTx_PLG1_Status_BackDoorMicSW;
extern uint8_t MessageTx_PLG1_Status_PLGClosingSW;
extern uint8_t MessageTx_PLG1_Status_DriverSideSW;
#endif

#ifdef _NIU_COM
extern uint8_t MessageTx_RDM1_SystemFaultSts;
extern uint8_t MessageTx_RDM1_InitSt;
extern uint8_t MessageTx_RDM1_RearDoorTherProSts;
extern uint8_t MessageTx_RDM1_HalfLockSt;
extern uint8_t MessageTx_RDM1_FullLockSt;
extern uint8_t MessageTx_RDM1_InsideSwitchSts;
extern uint8_t MessageTx_RDM1_RearDoorPos;
extern uint8_t MessageTx_RDM1_RearDoorSts;
extern uint8_t MessageTx_RDM1_CentralLockingSwSts;
extern uint8_t MessageTx_RDM1_RearDoorAntiPinchSts;
extern uint8_t MessageTx_RDM1_VechicleAlarmReq;
extern uint8_t MessageTx_RDM1_AntiPinchAlarmSts;
#endif

#ifdef _FAW_COM 
extern uint8_t MessageTx_LuggageDoorPreviousMovement;
extern uint8_t MessageTx_LuggageDoorWorkingSt;
extern uint8_t MessageTx_LuggageDoorSt;
extern uint8_t MessageTx_LuggageLockSt;
extern uint8_t MessageTx_LuggageSwitch_Inside;
#endif

#ifdef _CHANGAN_COM
extern tD_LatchMotion MessageTx_LatchMotion;
extern tD_GateMotion MessageTx_GateMotion;
#endif

#ifdef _XIAOPENG_COM
extern uint8_t MessageTx_SCU_MoveReq;
extern uint16_t MessageTx_LPoleHALLCounter;
extern uint16_t MessageTx_LPoleHALLCounter_raw;
extern uint8_t MessageTx_OPenRes;
extern uint8_t MessageTx_AA;
extern uint8_t MessageTx_PWMSt;

extern uint8_t MessageTx_PSDMotorSt;        
extern uint8_t MessageTx_DoorHandleSW;
extern uint8_t MessageTx_FulLockSt;
extern uint8_t MessageTx_HafLockSt;
extern uint8_t MessageTx_SysErr;
extern uint8_t MessageTx_KeyOpenModeCtrlCfgFB;
extern uint8_t MessageTx_KeyCloseModeCtrlCfgFB;
extern uint8_t MessageTx_DoorStatus;
extern uint8_t MessageTx_CloserMotorSt;
extern uint8_t MessageTx_ReleaseLockMotorSt;
extern uint8_t MessageTx_PawlSWSt;
extern uint8_t MessageTx_DenormalizeSt;	
extern uint8_t MessageTx_LVRSt;
extern uint8_t MessageTx_InDoorCloseSWSt;
extern uint8_t MessageTx_InDoorOpenSWSt;
extern uint8_t MessageTx_AntipintchSt;
extern uint8_t MessageTx_CloseRes;

extern uint8_t MessageTx_SysRuningSt;
extern uint8_t MessageTx_PSDMotorFR;
extern uint8_t MessageTx_CloserMotorFR;
extern uint8_t MessageTx_ReleaseLockMotorFR;
extern uint8_t MessageTx_DataUpload_St;
#endif

#ifdef _SGM_COM
extern uint8_t MessageTx_PwrLftgtMotStat;
extern uint8_t MessageTx_RrClsrObstclDtctd;
extern uint8_t MessageTx_RrClosOpenSwAct;
extern uint8_t MessageTx_RrClsrInMtn;

extern uint8_t MessageTx_RrClosRelSwAct;
extern uint8_t MessageTx_RrClosAjarSwActPLG;
extern uint8_t MessageTx_RrClsrSnwLdIO;
#endif

extern uint8_t MessageTx_GateOpenAngle_Valid;

extern uint8_t MessageRx_TimeInformation_Ind;
extern uint8_t MessageRx_TimeInformation_Valid;
extern uint8_t MessageRx_TimeMode;
extern uint8_t MessageRx_Week;
extern uint8_t MessageRx_TimeMode;
extern uint8_t MessageRx_Week;
extern uint8_t MessageRx_Year;
extern uint8_t MessageRx_Month;
extern uint8_t MessageRx_Day;
extern uint8_t MessageRx_Hour;
extern uint8_t MessageRx_Minute;
extern uint8_t MessageRx_Second;
extern uint8_t TimeInformation_Real_Status;

extern uint8_t MessageRx_Odometer_Ind;
extern uint8_t MessageRx_Odometer_Valid;
extern uint32_t MessageRx_Odometer;

extern uint8_t MessageTx_ChimeRemind;
extern uint8_t MessageTx_FlashRemind;
extern uint8_t MessageTx_DisplayRemind;

#ifdef _CONFIG_VehicleSOC
extern uint8_t MessageRx_VehicleSOC_Ind;
extern uint8_t MessageRx_VehicleSOC_Valid;
extern uint16_t MessageRx_VehicleSOC;
extern uint8_t VehicleSOC_Real_Status;
#endif

#ifdef _CONFIG_VehicleVoltage
extern uint8_t MessageRx_VehicleVoltage_Ind;
extern uint8_t MessageRx_VehicleVoltage_Valid;
extern uint16_t MessageRx_VehicleVoltage;
extern uint8_t VehicleVoltage_Real_Status;
#endif

#ifdef _CONFIG_VehicleChargeState
extern uint16_t VehicleChargeState_DataStream;
extern uint8_t VehicleChargeState_Status;
extern uint8_t VehicleChargeState_LastStatus;
extern uint8_t VehicleChargeState_FallEdge_Active;
extern uint8_t VehicleChargeState_RiseEdge_Active;
extern uint8_t VehicleChargeState_Real_Status;
extern uint8_t VehicleChargeState_SingleEvent_Enable;
extern uint8_t MessageRx_VehicleChargeState;
extern uint8_t MessageRx_VehicleChargeState_Valid;
extern uint8_t MessageRx_VehicleChargeState_Ind;
#endif

extern tD_PowerMode BusPowerMode;
extern tD_PowerMode VehiclePowerMode;
extern tD_AntiTheft VehicleAntiTheft;
extern tD_GearLever VehicleGearLever;

#ifdef _CONFIG_VehicleMode
extern tD_VehicleMode VehicleMode;
#endif

#ifdef _CONFIG_LatchSignal
extern tD_LatchSignal LatchSignal;
#endif


extern uint8_t VehiclePowerMode_ON_Status;
extern uint8_t VehiclePowerMode_ON_LastStatus;
extern uint8_t VehiclePowerMode_ON_FallEdge_Active;
extern uint8_t VehiclePowerMode_ON_RiseEdge_Active;

extern uint8_t MessageTx_PawlSwitch;
extern uint8_t MessageTx_SecondarySwitch;
extern uint8_t MessageTx_PositonSwitch;
extern uint8_t MessageTx_PrimarySwitch;

extern uint8_t MessageTx_SnowLoadSignal;

extern uint16_t MessageTx_GateOpenAngle;

extern uint16_t MessageTx_GaragePosition;
extern uint8_t MessageTx_SystemLearnedStatus;
extern uint8_t MessageTx_SystemLearnFailure;
extern uint8_t MessageTx_GarageLearnedStatus;
extern uint8_t MessageTx_GarageLearnAction;
extern uint8_t MessageTx_CurrentPLGMode;

extern uint16_t MessageTx_GaragePosition_Remainder;

extern uint8_t MessageTx_CommandActive;
extern uint8_t MessageTx_VehicleGearLever;

extern uint8_t MessageTx_GearMotorFault;
extern uint8_t MessageTx_Motor1Fault;
extern uint8_t MessageTx_Motor2Fault;
extern uint8_t MessageTx_LatchMotorFault;
extern uint8_t MessageTx_TapeSwitchFault;
extern uint8_t MessageTx_HallFault;

/*Condition Failure*/
extern uint8_t MessageTx_ObstacleDetected;
extern uint8_t MessageTx_AntiPinch;
extern uint8_t MessageTx_VoltageFailure;
extern uint8_t MessageTx_TemperatureFailure;
extern uint8_t MessageTx_SpeedFailure;
extern uint8_t MessageTx_ParkFailure;
extern uint8_t MessageTx_CrankFailure;
extern uint8_t MessageTx_LockFailure;

extern uint8_t MessageTx_TimeoutFailure;
extern uint8_t MessageTx_PlayoffFailure;
extern uint8_t MessageTx_GateMotorStallFailure;
extern uint8_t MessageTx_LatchMotorStallFailure;
extern uint8_t MessageTx_GateThermalProtectionFailure;
extern uint8_t MessageTx_LatchThermalProtectionFailure;

/*Tx Command Signal to Bus*/
extern uint8_t MessageTx_RemoteKey;
extern uint8_t MessageTx_KickSensor;
extern uint8_t MessageTx_PKETrunkButton;

extern uint8_t MessageTx_OpenCloseSwitch;
extern uint8_t MessageTx_OutsideHandleSwitch;
extern uint8_t MessageTx_ShutFaceSwitch;
extern uint8_t MessageTx_ShutFaceLockSwitch;
extern uint8_t MessageTx_HandFreeSwitch;


/*Receive message*/
extern uint8_t MessageRx_VehiclePowerMode;
extern uint8_t MessageRx_VehiclePowerMode_Engine;
extern uint8_t MessageRx_VehicleGearLever;
extern uint8_t MessageRx_VehicleLock;
extern uint8_t MessageRx_VehicleLock_Valid;
extern uint8_t MessageRx_VehicleAntiTheft;
extern uint8_t MessageRx_VehicleAntiTheft_Valid;
extern uint8_t MessageRx_RestoreRequest;
extern uint8_t MessageRx_RestoreRequestStatus;
extern uint8_t MessageRx_GateLockUnlock;

extern uint8_t MessageRx_DriverWindow;
extern uint8_t MessageRx_PassengerWindow;
extern uint8_t MessageRx_RearLeftWindow;
extern uint8_t MessageRx_RearRightWindow;

extern uint8_t MessageRx_FrontBlowerSpeed;
extern uint8_t MessageRx_FrontBlowerSpeed_Direction;
extern uint8_t MessageRx_RearBlowerSpeed;
extern uint8_t MessageRx_SunRoofPosition;

extern uint16_t MessageRx_EngineSpeed;
extern uint16_t MessageRx_VehicleSpeed;

extern uint8_t MessageRx_RearWiper;

extern uint8_t MessageRx_RemoteKey;
extern uint8_t MessageRx_FobLongPress;
extern uint8_t MessageRx_FobShortPress;
extern uint8_t MessageRx_KickSensor;
extern uint8_t MessageRx_AutoOpen;
extern uint8_t MessageRx_AutoClose;
extern uint8_t MessageRx_RemindStart;
extern uint8_t MessageRx_RemindStop;

extern uint8_t MessageRx_ComfortClose;
extern uint8_t MessageRx_TouchPad;
extern uint8_t MessageRx_PKETrunkButton;
extern uint8_t MessageRx_VirtualButton;

extern uint8_t MessageRx_GarageHeight;
extern uint8_t MessageRx_SlidePosition;
extern uint8_t MessageRx_BusTemperature;

extern uint8_t MessageRx_VehiclePowerMode_Ind;
extern uint8_t MessageRx_VehicleGearLever_Ind;
extern uint8_t MessageRx_VehicleLock_Ind;
extern uint8_t MessageRx_VehicleAntiTheft_Ind;
extern uint8_t MessageRx_RestoreRequest_Ind;
extern uint8_t MessageRx_GateLockUnlock_Ind;

extern uint8_t MessageRx_DriverWindow_Ind;
extern uint8_t MessageRx_PassengerWindow_Ind;
extern uint8_t MessageRx_RearLeftWindow_Ind;
extern uint8_t MessageRx_RearRightWindow_Ind;

extern uint8_t MessageRx_FrontBlowerSpeed_Ind;
extern uint8_t MessageRx_RearBlowerSpeed_Ind;
extern uint8_t MessageRx_SunRoofPosition_Ind;

extern uint8_t MessageRx_VehicleSpeed_Ind;
extern uint8_t VehicleSpeed_E2E_Status;
extern uint8_t MessageRx_VehicleSpeed_E2E;


extern uint8_t MessageRx_EngineSpeed_Ind;
extern uint8_t MessageRx_Odometer_Ind;

extern uint8_t MessageRx_RearWiper_Ind;

extern uint8_t MessageRx_FobLongPress_Ind;
extern uint8_t MessageRx_FobShortPress_Ind;
extern uint8_t MessageRx_KickSensor_Ind;
extern uint8_t MessageRx_AutoOpen_Ind;
extern uint8_t MessageRx_AutoClose_Ind;
extern uint8_t MessageRx_RemindStart_Ind;
extern uint8_t MessageRx_RemindStop_Ind;

extern uint8_t MessageRx_ComfortClose_Ind;
extern uint8_t MessageRx_TouchPad_Ind;
extern uint8_t MessageRx_PKETrunkButton_Ind;
extern uint8_t MessageRx_VirtualButton_Ind;

extern uint8_t MessageRx_AppOpen_Ind;
extern uint8_t MessageRx_AppClose_Ind;
extern uint8_t MessageRx_AppStop_Ind;

extern uint8_t MessageRx_VROpen_Ind;
extern uint8_t MessageRx_VRClose_Ind;
extern uint8_t MessageRx_VRStop_Ind;

extern uint8_t MessageRx_GarageHeight_Ind;
extern uint8_t MessageRx_SlidePosition_Ind;
extern uint8_t MessageRx_BusTemperature_Ind;

extern uint8_t MessageRx_VehicleGearLever_Valid;
extern uint8_t MessageRx_FobLongPress_Valid;
extern uint8_t MessageRx_FobShortPress_Valid;
extern uint8_t MessageRx_KickSensor_Valid;
extern uint8_t MessageRx_ComfortClose_Valid;
extern uint8_t MessageRx_AutoOpen_Valid;
extern uint8_t MessageRx_AutoClose_Valid;
extern uint8_t MessageRx_RemindStart_Valid;
extern uint8_t MessageRx_RemindStop_Valid;
extern uint8_t MessageRx_TouchPad_Valid;
extern uint8_t MessageRx_VirtualButton_Valid;

extern uint8_t MessageRx_AppOpen_Valid;
extern uint8_t MessageRx_AppClose_Valid;
extern uint8_t MessageRx_AppStop_Valid;

extern uint8_t MessageRx_VROpen_Valid;
extern uint8_t MessageRx_VRClose_Valid;
extern uint8_t MessageRx_VRStop_Valid;

extern uint8_t MessageRx_GarageHeight_Valid;
extern uint8_t MessageRx_FrontBlowerSpeed_Valid; 
extern uint8_t MessageRx_RearBlowerSpeed_Valid;  

extern uint8_t MessageRx_VehiclePowerMode_Valid;  
extern uint8_t MessageRx_BusTemperature_Valid;

extern uint8_t MessageRx_VehicleSpeed_Valid; 
extern uint8_t MessageRx_EngineSpeed_Valid;

extern uint8_t TouchPad_SingleEvent_Enable;
extern uint8_t RemoteKey_SingleEvent_Enable;
extern uint8_t FobLongPress_SingleEvent_Enable;
extern uint8_t FobShortPress_SingleEvent_Enable;
extern uint8_t KickSensor_SingleEvent_Enable;
extern uint8_t AutoOpen_SingleEvent_Enable;
extern uint8_t AutoClose_SingleEvent_Enable;
extern uint8_t RemindStart_SingleEvent_Enable;
extern uint8_t RemindStop_SingleEvent_Enable;
extern uint8_t ComfortClose_SingleEvent_Enable;
extern uint8_t PKETrunkButton_SingleEvent_Enable;
extern uint8_t VirtualButton_SingleEvent_Enable;
extern uint8_t AppOpen_SingleEvent_Enable;
extern uint8_t AppClose_SingleEvent_Enable;
extern uint8_t AppStop_SingleEvent_Enable;
extern uint8_t VROpen_SingleEvent_Enable;
extern uint8_t VRClose_SingleEvent_Enable;
extern uint8_t VRStop_SingleEvent_Enable;
extern uint8_t RestoreRequest_SingleEvent_Enable;

extern uint16_t MessageRx_GarageHeight_Counter;
extern uint16_t MessageRx_SlidePosition_Counter;

extern uint16_t MessageRx_GarageHeight_Value;
extern uint16_t MessageRx_GarageHeight_LastValue;

extern uint16_t MessageRx_SlidePosition_Value;
extern uint16_t MessageRx_SlidePosition_LastValue;
    
extern uint16_t VehicleSpeedLimit_DataStream;
extern uint8_t VehicleSpeedLimit_Status;  
extern uint8_t VehicleSpeedLimit_LastStatus;
extern uint8_t VehicleSpeedLimit_RiseEdge_Active;  
extern uint8_t VehicleSpeedLimit_FallEdge_Active;

#ifdef _CONFIG_VehicleSpeedLearn
extern uint16_t VehicleSpeedLearnLimit_DataStream;
extern uint8_t VehicleSpeedLearnLimit_Status;  
extern uint8_t VehicleSpeedLearnLimit_LastStatus;
extern uint8_t VehicleSpeedLearnLimit_RiseEdge_Active;  
extern uint8_t VehicleSpeedLearnLimit_FallEdge_Active;
#endif

extern uint16_t VehicleSpeedStop_DataStream;
extern uint8_t VehicleSpeedStop_Status;  
extern uint8_t VehicleSpeedStop_LastStatus;
extern uint8_t VehicleSpeedStop_RiseEdge_Active;  
extern uint8_t VehicleSpeedStop_FallEdge_Active;

extern uint16_t VehicleCrank_DataStream;    
extern uint8_t VehicleCrank_Status; 
extern uint8_t VehicleCrank_LastStatus;
extern uint8_t VehicleCrank_RiseEdge_Active;
extern uint8_t VehicleCrank_FallEdge_Active;

extern uint16_t RearWiper_DataStream;
extern uint8_t RearWiper_Status;  
extern uint8_t RearWiper_LastStatus;
extern uint8_t RearWiper_RiseEdge_Active;  
extern uint8_t RearWiper_FallEdge_Active;

extern uint16_t FrontBlowerSpeedHigh_DataStream;
extern uint16_t RearBlowerSpeedHigh_DataStream;
extern uint16_t FrontBlowerSpeedLow_DataStream;
extern uint16_t RearBlowerSpeedLow_DataStream;

extern uint16_t BusTemperatureOutOfRange_DataStream;
extern uint16_t SunRoofPosition_DataStream;
extern uint16_t DriverDoor_DataStream;
extern uint16_t PassengerDoor_DataStream;
extern uint16_t RearLeftDoor_DataStream;
extern uint16_t RearRightDoor_DataStream;

extern uint16_t DriverWindow_DataStream;
extern uint16_t PassengerWindow_DataStream;
extern uint16_t RearLeftWindow_DataStream;
extern uint16_t RearRightWindow_DataStream;

#ifdef _CONFIG_CommandDelay_Cancel_ByFobLock
extern uint16_t FobLock_DataStream;
extern uint8_t FobLock_Status;
extern uint8_t FobLock_LastStatus;
extern uint8_t FobLock_RiseEdge_Active;
extern uint8_t FobLock_FallEdge_Active;
extern uint8_t FobLock_Real_Status;
extern uint8_t MessageRx_FobLock;
extern uint8_t MessageRx_FobLock_Valid;
extern uint8_t MessageRx_FobLock_Ind;
#endif

#ifdef _CONFIG_ModeStatus_NormalMode
extern uint16_t NormalMode_DataStream;
extern uint8_t NormalMode_Status;
extern uint8_t NormalMode_LastStatus;
extern uint8_t NormalMode_FallEdge_Active;
extern uint8_t NormalMode_RiseEdge_Active;
extern uint8_t NormalMode_Real_Status;
extern uint8_t NormalMode_SingleEvent_Enable;
extern uint8_t MessageRx_NormalMode;
extern uint8_t MessageRx_NormalMode_Valid;
extern uint8_t MessageRx_NormalMode_Ind;
#endif

#ifdef _CONFIG_ModeStatus_GarageMode
extern uint16_t GarageMode_DataStream;
extern uint8_t GarageMode_Status;
extern uint8_t GarageMode_LastStatus;
extern uint8_t GarageMode_FallEdge_Active;
extern uint8_t GarageMode_RiseEdge_Active;
extern uint8_t GarageMode_Real_Status;
extern uint8_t GarageMode_SingleEvent_Enable;
extern uint8_t MessageRx_GarageMode;
extern uint8_t MessageRx_GarageMode_Valid;
extern uint8_t MessageRx_GarageMode_Ind;
#endif

#ifdef _CONFIG_ModeStatus_ManualMode
extern uint16_t ManualMode_DataStream;
extern uint8_t ManualMode_Status;
extern uint8_t ManualMode_LastStatus;
extern uint8_t ManualMode_FallEdge_Active;
extern uint8_t ManualMode_RiseEdge_Active;
extern uint8_t ManualMode_Real_Status;
extern uint8_t ManualMode_SingleEvent_Enable;
extern uint8_t MessageRx_ManualMode;
extern uint8_t MessageRx_ManualMode_Valid;
extern uint8_t MessageRx_ManualMode_Ind;
#endif

#ifdef _CONFIG_KickSensorEnable
extern uint16_t KickSensorEnable_DataStream;
extern uint8_t KickSensorEnable_Status;
extern uint8_t KickSensorEnable_Real_Status;
extern uint8_t KickSensorEnable_SingleEvent_Enable;
extern uint8_t MessageRx_KickSensorEnable;
extern uint8_t MessageRx_KickSensorEnable_Valid;
extern uint8_t MessageRx_KickSensorEnable_Ind;
#endif

#ifdef _CONFIG_FlasherEnable
extern uint16_t FlasherEnable_DataStream;
extern uint8_t FlasherEnable_Status;
extern uint8_t FlasherEnable_Real_Status;
extern uint8_t FlasherEnable_SingleEvent_Enable;
extern uint8_t MessageRx_FlasherEnable;
extern uint8_t MessageRx_FlasherEnable_Valid;
extern uint8_t MessageRx_FlasherEnable_Ind;
#endif

#ifdef _CONFIG_BuzzerEnable
extern uint16_t BuzzerEnable_DataStream;
extern uint8_t BuzzerEnable_Status;
extern uint8_t BuzzerEnable_Real_Status;
extern uint8_t BuzzerEnable_SingleEvent_Enable;
extern uint8_t MessageRx_BuzzerEnable;
extern uint8_t MessageRx_BuzzerEnable_Valid;
extern uint8_t MessageRx_BuzzerEnable_Ind;
#endif

#ifdef _CONFIG_AutoOpenEnable
extern uint16_t AutoOpenEnable_DataStream;
extern uint8_t AutoOpenEnable_Status;
extern uint8_t AutoOpenEnable_Real_Status;
extern uint8_t AutoOpenEnable_SingleEvent_Enable;
extern uint8_t MessageRx_AutoOpenEnable;
extern uint8_t MessageRx_AutoOpenEnable_Valid;
extern uint8_t MessageRx_AutoOpenEnable_Ind;
#endif

#ifdef _CONFIG_ObstcalAlarmEnable
extern uint16_t ObstcalAlarmEnable_DataStream;
extern uint8_t ObstcalAlarmEnable_Status;
extern uint8_t ObstcalAlarmEnable_Real_Status;
extern uint8_t ObstcalAlarmEnable_SingleEvent_Enable;
extern uint8_t MessageRx_ObstcalAlarmEnable;
extern uint8_t MessageRx_ObstcalAlarmEnable_Valid;
extern uint8_t MessageRx_ObstcalAlarmEnable_Ind;
#endif

#ifdef _CONFIG_BLEEnable
extern uint16_t BLEEnable_DataStream;
extern uint8_t BLEEnable_Status;
extern uint8_t BLEEnable_Real_Status;
extern uint8_t BLEEnable_SingleEvent_Enable;
extern uint8_t MessageRx_BLEEnable;
extern uint8_t MessageRx_BLEEnable_Valid;
extern uint8_t MessageRx_BLEEnable_Ind;
#endif

#ifdef _CONFIG_VoiceEnable
extern uint16_t VoiceEnable_DataStream;
extern uint8_t VoiceEnable_Status;
extern uint8_t VoiceEnable_Real_Status;
extern uint8_t VoiceEnable_SingleEvent_Enable;
extern uint8_t MessageRx_VoiceEnable;
extern uint8_t MessageRx_VoiceEnable_Valid;
extern uint8_t MessageRx_VoiceEnable_Ind;
#endif

#ifdef _CONFIG_BrakeEnable
extern uint16_t BrakeEnable_DataStream;
extern uint8_t BrakeEnable_Status;
extern uint8_t BrakeEnable_Real_Status;
extern uint8_t BrakeEnable_SingleEvent_Enable;
extern uint8_t MessageRx_BrakeEnable;
extern uint8_t MessageRx_BrakeEnable_Valid;
extern uint8_t MessageRx_BrakeEnable_Ind;
#endif

#ifdef _CONFIG_RKEEnable
extern uint16_t RKEEnable_DataStream;
extern uint8_t RKEEnable_Status;
extern uint8_t RKEEnable_Real_Status;
extern uint8_t RKEEnable_SingleEvent_Enable;
extern uint8_t MessageRx_RKEEnable;
extern uint8_t MessageRx_RKEEnable_Valid;
extern uint8_t MessageRx_RKEEnable_Ind;
#endif

#ifdef _CONFIG_DoorPowerMode
extern uint16_t DoorPowerMode_DataStream;
extern uint8_t DoorPowerMode_Status;
extern uint8_t DoorPowerMode_Real_Status;
extern uint8_t DoorPowerMode_SingleEvent_Enable;
extern uint8_t MessageRx_DoorPowerMode;
extern uint8_t MessageRx_DoorPowerMode_Valid;
extern uint8_t MessageRx_DoorPowerMode_Ind;
#endif


#ifdef _CONFIG_CinchEnable
extern uint16_t CinchEnable_DataStream;
extern uint8_t CinchEnable_Status;
extern uint8_t CinchEnable_Real_Status;
extern uint8_t CinchEnable_SingleEvent_Enable;
extern uint8_t MessageRx_CinchEnable;
extern uint8_t MessageRx_CinchEnable_Valid;
extern uint8_t MessageRx_CinchEnable_Ind;
#endif

#ifdef _CONFIG_BeltEnable
extern uint16_t BeltEnable_DataStream;
extern uint8_t BeltEnable_Status;
extern uint8_t BeltEnable_Real_Status;
extern uint8_t BeltEnable_SingleEvent_Enable;
extern uint8_t MessageRx_BeltEnable;
extern uint8_t MessageRx_BeltEnable_Valid;
extern uint8_t MessageRx_BeltEnable_Ind;
#endif

#ifdef _CONFIG_WindEnable
extern uint16_t WindEnable_DataStream;
extern uint8_t WindEnable_Status;
extern uint8_t WindEnable_Real_Status;
extern uint8_t WindEnable_SingleEvent_Enable;
extern uint8_t MessageRx_WindEnable;
extern uint8_t MessageRx_WindEnable_Valid;
extern uint8_t MessageRx_WindEnable_Ind;
#endif

#ifdef _CONFIG_SpeedMode
extern uint16_t SpeedMode_DataStream;
extern uint8_t SpeedMode_Status;
extern uint8_t SpeedMode_Real_Status;
extern uint8_t SpeedMode_SingleEvent_Enable;
extern uint8_t MessageRx_SpeedMode;
extern uint8_t MessageRx_SpeedMode_Valid;
extern uint8_t MessageRx_SpeedMode_Ind;
#endif

#ifdef _CONFIG_ManualOperateEnable
extern uint16_t ManualOperateEnable_DataStream;
extern uint8_t ManualOperateEnable_Status;
extern uint8_t ManualOperateEnable_Real_Status;
extern uint8_t ManualOperateEnable_SingleEvent_Enable;
extern uint8_t MessageRx_ManualOperateEnable;
extern uint8_t MessageRx_ManualOperateEnable_Valid;
extern uint8_t MessageRx_ManualOperateEnable_Ind;
#endif

#ifdef _CONFIG_MotorHoldEnable
extern uint16_t MotorHoldEnable_DataStream;
extern uint8_t MotorHoldEnable_Status;
extern uint8_t MotorHoldEnable_Real_Status;
extern uint8_t MotorHoldEnable_SingleEvent_Enable;
extern uint8_t MessageRx_MotorHoldEnable;
extern uint8_t MessageRx_MotorHoldEnable_Valid;
extern uint8_t MessageRx_MotorHoldEnable_Ind;
#endif


#ifdef _CONFIG_ConfigurationTrigger
extern uint16_t ConfigurationTrigger_DataStream;
extern uint8_t ConfigurationTrigger_Status;
extern uint8_t ConfigurationTrigger_LastStatus;
extern uint8_t ConfigurationTrigger_RiseEdge_Active;  
extern uint8_t ConfigurationTrigger_FallEdge_Active;
extern uint8_t ConfigurationTrigger_Real_Status;
extern uint8_t ConfigurationTrigger_SingleEvent_Enable;
extern uint8_t MessageRx_ConfigurationTrigger;
extern uint8_t MessageRx_ConfigurationTrigger_Valid;
extern uint8_t MessageRx_ConfigurationTrigger_Ind;

extern uint8_t ConfigurationTrigger_E2E_Status;
extern uint8_t MessageRx_ConfigurationTrigger_E2E;
#endif
#ifdef _CONFIG_SideDoorOpeningMode
extern uint16_t SideDoorOpeningMode_DataStream;
extern uint8_t SideDoorOpeningMode_Status;
extern uint8_t SideDoorOpeningMode_Real_Status;
extern uint8_t SideDoorOpeningMode_SingleEvent_Enable;
extern uint8_t MessageRx_SideDoorOpeningMode;
extern uint8_t MessageRx_SideDoorOpeningMode_Valid;
extern uint8_t MessageRx_SideDoorOpeningMode_Ind;

extern uint8_t SideDoorOpeningMode_E2E_Status;
extern uint8_t MessageRx_SideDoorOpeningMode_E2E;
#endif
#ifdef _CONFIG_LeftAndRightRudder
extern uint16_t LeftAndRightRudder_DataStream;
extern uint8_t LeftAndRightRudder_Status;
extern uint8_t LeftAndRightRudder_Real_Status;
extern uint8_t LeftAndRightRudder_SingleEvent_Enable;
extern uint8_t MessageRx_LeftAndRightRudder;
extern uint8_t MessageRx_LeftAndRightRudder_Valid;
extern uint8_t MessageRx_LeftAndRightRudder_Ind;

extern uint8_t LeftAndRightRudder_E2E_Status;
extern uint8_t MessageRx_LeftAndRightRudder_E2E;
#endif
#ifdef _CONFIG_BNCM
extern uint16_t BNCM_DataStream;
extern uint8_t BNCM_Status;
extern uint8_t BNCM_Real_Status;
extern uint8_t BNCM_SingleEvent_Enable;
extern uint8_t MessageRx_BNCM;
extern uint8_t MessageRx_BNCM_Valid;
extern uint8_t MessageRx_BNCM_Ind;

extern uint8_t BNCM_E2E_Status;
extern uint8_t MessageRx_BNCM_E2E;
#endif


extern uint8_t SupportControl_Status;
extern uint8_t StepControl_Request;

extern uint16_t VehicleCrank_DataStream;    
extern uint8_t VehicleCrank_Status; 
extern uint8_t VehicleCrank_LastStatus;
extern uint8_t VehicleCrank_RiseEdge_Active;
extern uint8_t VehicleCrank_FallEdge_Active;

extern uint16_t VehicleAntiTheft_DataStream;
extern uint16_t VehicleAntiTheft_Status;

extern uint16_t VehicleLock_DataStream;
extern uint8_t VehicleLock_Status;
extern uint8_t VehicleLock_LastStatus;
extern uint8_t VehicleLock_RiseEdge_Active;
extern uint8_t VehicleLock_FallEdge_Active;

#ifdef _CONFIG_VehicleChildLock
extern uint16_t VehicleChildLock_DataStream;
extern uint8_t VehicleChildLock_Status;
extern uint8_t VehicleChildLock_LastStatus;
extern uint8_t VehicleChildLock_RiseEdge_Active;
extern uint8_t VehicleChildLock_FallEdge_Active;
extern uint8_t VehicleChildLock_Real_Status;
extern uint8_t MessageRx_VehicleChildLock;
extern uint8_t MessageRx_VehicleChildLock_Valid;
extern uint8_t MessageRx_VehicleChildLock_Ind;
#endif

#ifdef _CONFIG_VehicleBrake
extern uint16_t VehicleBrake_DataStream;
extern uint8_t VehicleBrake_Status;
extern uint8_t VehicleBrake_LastStatus;
extern uint8_t VehicleBrake_RiseEdge_Active;
extern uint8_t VehicleBrake_FallEdge_Active;
extern uint8_t VehicleBrake_Real_Status;
extern uint8_t MessageRx_VehicleBrake;
extern uint8_t MessageRx_VehicleBrake_Valid;
extern uint8_t MessageRx_VehicleBrake_Ind;

extern uint8_t VehicleBrake_E2E_Status;
extern uint8_t MessageRx_VehicleBrake_E2E;

#ifdef _CONFIG_VehicleBrake_ShortPress
extern uint8_t VehicleBrake_ShortPress_Status;
extern uint8_t VehicleBrake_ShortPress_LastStatus;
extern uint8_t VehicleBrake_ShortPress_Active;
#endif
#ifdef _CONFIG_VehicleBrake_LongPress
extern uint8_t VehicleBrake_LongPress_Status;
extern uint8_t VehicleBrake_LongPress_LastStatus;
extern uint8_t VehicleBrake_LongPress_Active;
#endif
#endif

#ifdef _CONFIG_VehicleCrash
extern uint16_t VehicleCrash_DataStream;
extern uint8_t VehicleCrash_Status;
extern uint8_t VehicleCrash_LastStatus;
extern uint8_t VehicleCrash_RiseEdge_Active;
extern uint8_t VehicleCrash_FallEdge_Active;
extern uint8_t VehicleCrash_Real_Status;
extern uint8_t VehicleCrash_SingleEvent_Enable;
extern uint8_t MessageRx_VehicleCrash;
extern uint8_t MessageRx_VehicleCrash_Valid;
extern uint8_t MessageRx_VehicleCrash_Ind;

extern uint8_t VehicleCrash_E2E_Status;
extern uint8_t MessageRx_VehicleCrash_E2E;
#endif
#ifdef _CONFIG_VehicleRain
extern uint16_t VehicleRain_DataStream;
extern uint8_t VehicleRain_Status;
extern uint8_t VehicleRain_LastStatus;
extern uint8_t VehicleRain_RiseEdge_Active;
extern uint8_t VehicleRain_FallEdge_Active;
extern uint8_t VehicleRain_Real_Status;
extern uint8_t VehicleRain_SingleEvent_Enable;
extern uint8_t MessageRx_VehicleRain;
extern uint8_t MessageRx_VehicleRain_Valid;
extern uint8_t MessageRx_VehicleRain_Ind;

extern uint8_t VehicleRain_E2E_Status;
extern uint8_t MessageRx_VehicleRain_E2E;
#endif
#ifdef _CONFIG_VehicleClean
extern uint16_t VehicleClean_DataStream;
extern uint8_t VehicleClean_Status;
extern uint8_t VehicleClean_LastStatus;
extern uint8_t VehicleClean_RiseEdge_Active;
extern uint8_t VehicleClean_FallEdge_Active;
extern uint8_t VehicleClean_Real_Status;
extern uint8_t VehicleClean_SingleEvent_Enable;
extern uint8_t MessageRx_VehicleClean;
extern uint8_t MessageRx_VehicleClean_Valid;
extern uint8_t MessageRx_VehicleClean_Ind;

extern uint8_t VehicleClean_E2E_Status;
extern uint8_t MessageRx_VehicleClean_E2E;
#endif



#ifdef _CONFIG_BusIncline
#ifdef _CONFIG_InclineX_Direction
extern uint16_t BusInclineX_DataStream;
extern uint8_t BusInclineX_Status;
extern uint8_t BusInclineX_Real_Status;
extern uint8_t BusInclineX_SingleEvent_Enable;
extern uint8_t BusInclineX_E2E_Status;
extern uint16_t MessageRx_BusInclineX;
extern uint8_t MessageRx_BusInclineX_Valid;
extern uint8_t MessageRx_BusInclineX_Ind;

extern uint8_t BusInclineX_E2E_Status;
extern uint8_t MessageRx_BusInclineX_E2E;
#endif
#ifdef _CONFIG_InclineY_Direction
extern uint16_t BusInclineY_DataStream;
extern uint8_t BusInclineY_Status;
extern uint8_t BusInclineY_Real_Status;
extern uint8_t BusInclineY_SingleEvent_Enable;
extern uint16_t MessageRx_BusInclineY;
extern uint8_t MessageRx_BusInclineY_Valid;
extern uint8_t MessageRx_BusInclineY_Ind;

extern uint8_t BusInclineY_E2E_Status;
extern uint8_t MessageRx_BusInclineY_E2E;
#endif
#ifdef _CONFIG_InclineZ_Direction
extern uint16_t BusInclineZ_DataStream;
extern uint8_t BusInclineZ_Status;
extern uint8_t BusInclineZ_Real_Status;
extern uint8_t BusInclineZ_SingleEvent_Enable;
extern uint16_t MessageRx_BusInclineZ;
extern uint8_t MessageRx_BusInclineZ_Valid;
extern uint8_t MessageRx_BusInclineZ_Ind;

extern uint8_t BusInclineZ_E2E_Status;
extern uint8_t MessageRx_BusInclineZ_E2E;
#endif
#endif



#ifdef _CONFIG_SonicRadar
#ifdef _CONFIG_SonicRadar_Error
extern uint8_t SonicRadar_Error_Real_Status;
extern uint8_t MessageRx_SonicRadar_Error;
extern uint8_t MessageRx_SonicRadar_Error1;
extern uint8_t MessageRx_SonicRadar_Error2;
extern uint8_t MessageRx_SonicRadar_Error3;
extern uint8_t MessageRx_SonicRadar_Error4;
extern uint8_t MessageRx_SonicRadar_Error_Valid;
extern uint8_t MessageRx_SonicRadar_Error_Ind;
#endif
#ifdef _CONFIG_SonicRadar_Obstacle
extern uint8_t SonicRadar_Obstacle_Real_Status;
extern uint8_t MessageRx_SonicRadar_Obstacle;
extern uint8_t MessageRx_SonicRadar_Obstacle_Valid;
extern uint8_t MessageRx_SonicRadar_Obstacle_Ind;
#endif
#ifdef _CONFIG_SonicRadar_Angle
extern uint8_t SonicRadar_Angle_Real_Status;
extern uint16_t MessageRx_SonicRadar_Angle;
extern uint8_t MessageRx_SonicRadar_Angle_Valid;
extern uint8_t MessageRx_SonicRadar_Angle_Ind;
#endif
#ifdef _CONFIG_SonicRadar1_Distance
extern uint8_t SonicRadar1_Distance_Real_Status;
extern uint16_t MessageRx_SonicRadar1_Distance;
extern uint8_t MessageRx_SonicRadar1_Distance_Valid;
extern uint8_t MessageRx_SonicRadar1_Distance_Ind;
#endif
#ifdef _CONFIG_SonicRadar2_Distance
extern uint8_t SonicRadar2_Distance_Real_Status;
extern uint16_t MessageRx_SonicRadar2_Distance;
extern uint8_t MessageRx_SonicRadar2_Distance_Valid;
extern uint8_t MessageRx_SonicRadar2_Distance_Ind;
#endif
#ifdef _CONFIG_SonicRadar3_Distance
extern uint8_t SonicRadar3_Distance_Real_Status;
extern uint16_t MessageRx_SonicRadar3_Distance;
extern uint8_t MessageRx_SonicRadar3_Distance_Valid;
extern uint8_t MessageRx_SonicRadar3_Distance_Ind;
#endif
#endif

#ifdef _CONFIG_MmwRadar
#ifdef _CONFIG_MmwRadar_Error
extern uint8_t MmwRadar_Error_Real_Status;
extern uint8_t MessageRx_MmwRadar_Error;
extern uint8_t MessageRx_MmwRadar_Error1;
extern uint8_t MessageRx_MmwRadar_Error2;
extern uint8_t MessageRx_MmwRadar_Error3;
extern uint8_t MessageRx_MmwRadar_Error4;
extern uint8_t MessageRx_MmwRadar_Error5;
extern uint8_t MessageRx_MmwRadar_Error6;
extern uint8_t MessageRx_MmwRadar_Error_Valid;
extern uint8_t MessageRx_MmwRadar_Error_Ind;
#endif
#ifdef _CONFIG_MmwRadar_Obstacle
extern uint8_t MmwRadar_Obstacle_Real_Status;
extern uint8_t MessageRx_MmwRadar_Obstacle;
extern uint8_t MessageRx_MmwRadar_Obstacle_Valid;
extern uint8_t MessageRx_MmwRadar_Obstacle_Ind;
#endif
#ifdef _CONFIG_MmwRadar_Angle
extern uint8_t MmwRadar_Angle_Real_Status;
extern uint16_t MessageRx_MmwRadar_Angle;
extern uint8_t MessageRx_MmwRadar_Angle_Valid;
extern uint8_t MessageRx_MmwRadar_Angle_Ind;
#endif
#ifdef _CONFIG_MmwRadarX_Distance
extern uint8_t MmwRadarX_Distance_Real_Status;
extern uint16_t MessageRx_MmwRadarX_Distance;
extern uint8_t MessageRx_MmwRadarX_Distance_Valid;
extern uint8_t MessageRx_MmwRadarX_Distance_Ind;
#endif
#ifdef _CONFIG_MmwRadarY_Distance
extern uint8_t MmwRadarY_Distance_Real_Status;
extern uint16_t MessageRx_MmwRadarY_Distance;
extern uint8_t MessageRx_MmwRadarY_Distance_Valid;
extern uint8_t MessageRx_MmwRadarY_Distance_Ind;
#endif
#ifdef _CONFIG_MmwRadarZ_Distance
extern uint8_t MmwRadarZ_Distance_Real_Status;
extern uint16_t MessageRx_MmwRadarZ_Distance;
extern uint8_t MessageRx_MmwRadarZ_Distance_Valid;
extern uint8_t MessageRx_MmwRadarZ_Distance_Ind;
#endif
#ifdef _CONFIG_MmwRadarD_Distance
extern uint8_t MmwRadarD_Distance_Real_Status;
extern uint16_t MessageRx_MmwRadarD_Distance;
extern uint8_t MessageRx_MmwRadarD_Distance_Valid;
extern uint8_t MessageRx_MmwRadarD_Distance_Ind;
#endif
#endif

#ifdef _CONFIG_AdasRadar
#ifdef _CONFIG_AdasRadar_RearCorner_Error
extern uint8_t AdasRadar_RearCorner_Error_Real_Status;
extern uint8_t MessageRx_AdasRadar_RearCorner_Error;
extern uint8_t MessageRx_AdasRadar_RearCorner_Error_Valid;
extern uint8_t MessageRx_AdasRadar_RearCorner_Error_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Obstacle
extern uint8_t AdasRadar_RearCorner_Obstacle_Real_Status;
extern uint8_t MessageRx_AdasRadar_RearCorner_Obstacle;
extern uint8_t MessageRx_AdasRadar_RearCorner_Obstacle_Valid;
extern uint8_t MessageRx_AdasRadar_RearCorner_Obstacle_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Angle
extern uint8_t AdasRadar_RearCorner_Angle_Real_Status;
extern uint16_t MessageRx_AdasRadar_RearCorner_Angle;
extern uint8_t MessageRx_AdasRadar_RearCorner_Angle_Valid;
extern uint8_t MessageRx_AdasRadar_RearCorner_Angle_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCorner_Enable
extern uint8_t AdasRadar_RearCorner_Enable_Real_Status;
extern uint8_t MessageRx_AdasRadar_RearCorner_Enable;
extern uint8_t MessageRx_AdasRadar_RearCorner_Enable_Valid;
extern uint8_t MessageRx_AdasRadar_RearCorner_Enable_Ind;
#endif

#ifdef _CONFIG_AdasRadar_RearCornerX_Distance
extern uint8_t AdasRadar_RearCornerX_Distance_Real_Status;
extern uint16_t MessageRx_AdasRadar_RearCornerX_Distance;
extern uint8_t MessageRx_AdasRadar_RearCornerX_Distance_Valid;
extern uint8_t MessageRx_AdasRadar_RearCornerX_Distance_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCornerY_Distance
extern uint8_t AdasRadar_RearCornerY_Distance_Real_Status;
extern uint16_t MessageRx_AdasRadar_RearCornerY_Distance;
extern uint8_t MessageRx_AdasRadar_RearCornerY_Distance_Valid;
extern uint8_t MessageRx_AdasRadar_RearCornerY_Distance_Ind;
#endif
#ifdef _CONFIG_AdasRadar_RearCornerZ_Distance
extern uint8_t AdasRadar_RearCornerZ_Distance_Real_Status;
extern uint16_t MessageRx_AdasRadar_RearCornerZ_Distance;
extern uint8_t MessageRx_AdasRadar_RearCornerZ_Distance_Valid;
extern uint8_t MessageRx_AdasRadar_RearCornerZ_Distance_Ind;
#endif
#endif






#ifdef _CONFIG_VehicleDriveMode
extern uint16_t VehicleDriveMode_DataStream;
extern uint8_t VehicleDriveMode_Status;
extern uint8_t VehicleDriveMode_LastStatus;
extern uint8_t VehicleDriveMode_RiseEdge_Active;
extern uint8_t VehicleDriveMode_FallEdge_Active;
extern uint8_t VehicleDriveMode_Real_Status;
extern uint8_t VehicleDriveMode_SingleEvent_Enable;
extern uint8_t MessageRx_VehicleDriveMode;
extern uint8_t MessageRx_VehicleDriveMode_Valid;
extern uint8_t MessageRx_VehicleDriveMode_Ind;
extern uint8_t MessageTx_VehicleDriveMode_Status;
#endif
#ifdef _CONFIG_KeyOpenMode
extern uint16_t KeyOpenMode_DataStream;
extern uint8_t KeyOpenMode_Status;
extern uint8_t KeyOpenMode_LastStatus;
extern uint8_t KeyOpenMode_RiseEdge_Active;
extern uint8_t KeyOpenMode_FallEdge_Active;
extern uint8_t KeyOpenMode_Real_Status;
extern uint8_t KeyOpenMode_SingleEvent_Enable;
extern uint8_t MessageRx_KeyOpenMode;
extern uint8_t MessageRx_KeyOpenMode_Valid;
extern uint8_t MessageRx_KeyOpenMode_Ind;
extern uint8_t MessageTx_KeyOpenMode_Status;

extern uint8_t Vehicle_KeyOpenMode;
#endif
#ifdef _CONFIG_KeyCloseMode
extern uint16_t KeyCloseMode_DataStream;
extern uint8_t KeyCloseMode_Status;
extern uint8_t KeyCloseMode_LastStatus;
extern uint8_t KeyCloseMode_RiseEdge_Active;
extern uint8_t KeyCloseMode_FallEdge_Active;
extern uint8_t KeyCloseMode_Real_Status;
extern uint8_t KeyCloseMode_SingleEvent_Enable;
extern uint8_t MessageRx_KeyCloseMode;
extern uint8_t MessageRx_KeyCloseMode_Valid;
extern uint8_t MessageRx_KeyCloseMode_Ind;
extern uint8_t MessageTx_KeyCloseMode_Status;

extern uint8_t Vehicle_KeyCloseMode;
#endif

#ifdef _CONFIG_AppAuthorize
extern uint16_t AppAuthorize_DataStream;
extern uint8_t AppAuthorize_Status;
extern uint8_t AppAuthorize_LastStatus;
extern uint8_t AppAuthorize_RiseEdge_Active;
extern uint8_t AppAuthorize_FallEdge_Active;
extern uint8_t AppAuthorize_Real_Status;
extern uint8_t MessageRx_AppAuthorize;
extern uint8_t MessageRx_AppAuthorize_Valid;
extern uint8_t MessageRx_AppAuthorize_Ind;
extern uint8_t MessageTx_AppAuthorize_Status;
#endif

#ifdef _CONFIG_BLEAuthorize
extern uint16_t BLEAuthorize_DataStream;
extern uint8_t BLEAuthorize_Status;
extern uint8_t BLEAuthorize_LastStatus;
extern uint8_t BLEAuthorize_RiseEdge_Active;
extern uint8_t BLEAuthorize_FallEdge_Active;
extern uint8_t BLEAuthorize_Real_Status;
extern uint8_t MessageRx_BLEAuthorize;
extern uint8_t MessageRx_BLEAuthorize_Valid;
extern uint8_t MessageRx_BLEAuthorize_Ind;
extern uint8_t MessageTx_BLEAuthorize_Status;
#endif

#ifdef _CONFIG_PKEAuthorize
extern uint16_t PKEAuthorize_DataStream;
extern uint8_t PKEAuthorize_Status;
extern uint8_t PKEAuthorize_LastStatus;
extern uint8_t PKEAuthorize_RiseEdge_Active;
extern uint8_t PKEAuthorize_FallEdge_Active;
extern uint8_t PKEAuthorize_Real_Status;
extern uint8_t MessageRx_PKEAuthorize;
extern uint8_t MessageRx_PKEAuthorize_Valid;
extern uint8_t MessageRx_PKEAuthorize_Ind;
extern uint8_t MessageTx_PKEAuthorize_Status;
#endif

#ifdef _CONFIG_FobAuthorize
extern uint16_t FobAuthorize_DataStream;
extern uint8_t FobAuthorize_Status;
extern uint8_t FobAuthorize_LastStatus;
extern uint8_t FobAuthorize_RiseEdge_Active;
extern uint8_t FobAuthorize_FallEdge_Active;
extern uint8_t FobAuthorize_Real_Status;
extern uint8_t MessageRx_FobAuthorize;
extern uint8_t MessageRx_FobAuthorize_Valid;
extern uint8_t MessageRx_FobAuthorize_Ind;
extern uint8_t MessageTx_FobAuthorize_Status;
#endif

#ifdef _CONFIG_AntiLockAuthorize
extern uint16_t AntiLockAuthorize_DataStream;
extern uint8_t AntiLockAuthorize_Status;
extern uint8_t AntiLockAuthorize_LastStatus;
extern uint8_t AntiLockAuthorize_RiseEdge_Active;
extern uint8_t AntiLockAuthorize_FallEdge_Active;
extern uint8_t AntiLockAuthorize_Real_Status;
extern uint8_t MessageRx_AntiLockAuthorize;
extern uint8_t MessageRx_AntiLockAuthorize_Valid;
extern uint8_t MessageRx_AntiLockAuthorize_Ind;
extern uint8_t MessageTx_AntiLockAuthorize_Status;
#endif

#ifdef _CONFIG_CloseSpeedLevel
extern uint8_t MessageRx_CloseSpeedLevel;
extern uint8_t MessageRx_CloseSpeedLevel_Ind;
extern uint8_t CloseSpeedLevel_Real_Status;
extern uint16_t CloseSpeedLevel_DataStream;
extern uint8_t CloseSpeedLevel_Status;  
extern uint8_t CloseSpeedLevel_LastStatus;
extern uint8_t CloseSpeedLevel_RiseEdge_Active;  
extern uint8_t CloseSpeedLevel_FallEdge_Active;
#endif

#ifdef _CONFIG_OpenSpeedLevel
extern uint8_t MessageRx_OpenSpeedLevel;
extern uint8_t MessageRx_OpenSpeedLevel_Ind;
extern uint8_t OpenSpeedLevel_Real_Status;
extern uint16_t OpenSpeedLevel_DataStream;
extern uint8_t OpenSpeedLevel_Status;  
extern uint8_t OpenSpeedLevel_LastStatus;
extern uint8_t OpenSpeedLevel_RiseEdge_Active;  
extern uint8_t OpenSpeedLevel_FallEdge_Active;
#endif

#ifdef _CONFIG_VehicleHandBrake
extern uint8_t VehicleHandBrake_Valid_Status;
extern uint16_t VehicleHandBrake_DataStream;
extern uint8_t VehicleHandBrake_Status;
extern uint8_t VehicleHandBrake_LastStatus;
extern uint8_t VehicleHandBrake_RiseEdge_Active;
extern uint8_t VehicleHandBrake_FallEdge_Active;
extern uint8_t VehicleHandBrake_Real_Status;
extern uint8_t MessageRx_VehicleHandBrake;
extern uint8_t MessageRx_VehicleHandBrake_Valid;
extern uint8_t MessageRx_VehicleHandBrake_Ind;
#endif

#ifdef _CONFIG_VehicleMode
extern uint8_t VehicleMode_Valid_Status;
extern uint16_t VehicleMode_DataStream;
extern uint8_t VehicleMode_Status;
extern uint8_t VehicleMode_LastStatus;
extern uint8_t VehicleMode_RiseEdge_Active;
extern uint8_t VehicleMode_FallEdge_Active;
extern uint8_t VehicleMode_Real_Status;
extern uint8_t MessageRx_VehicleMode;
extern uint8_t MessageRx_VehicleMode_Valid;
extern uint8_t MessageRx_VehicleMode_Ind;
#endif

#ifdef _CONFIG_VehicleRemoteMode
extern uint8_t VehicleRemoteMode_Valid_Status;
extern uint16_t VehicleRemoteMode_DataStream;
extern uint8_t VehicleRemoteMode_Status;
extern uint8_t VehicleRemoteMode_LastStatus;
extern uint8_t VehicleRemoteMode_RiseEdge_Active;
extern uint8_t VehicleRemoteMode_FallEdge_Active;
extern uint8_t VehicleRemoteMode_Real_Status;
extern uint8_t MessageRx_VehicleRemoteMode;
extern uint8_t MessageRx_VehicleRemoteMode_Valid;
extern uint8_t MessageRx_VehicleRemoteMode_Ind;
#endif

extern uint16_t VehicleGearLever_DataStream;
extern uint8_t VehicleGearLever_Status;
extern uint8_t VehicleGearLever_LastStatus;
extern uint8_t VehicleGearLever_RiseEdge_Active;
extern uint8_t VehicleGearLever_FallEdge_Active;

extern uint8_t VehicleSpeed_Valid_Status;
extern uint8_t VehicleGearLever_Valid_Status;

extern uint8_t FrontBlowerSpeedHigh_Status;
extern uint8_t RearBlowerSpeedHigh_Status;
extern uint8_t FrontBlowerSpeedLow_Status;
extern uint8_t RearBlowerSpeedLow_Status;

extern uint8_t BusTemperatureOutOfRange_Status;
extern uint8_t SunRoofPosition_Status;
extern uint8_t DriverDoor_Status;
extern uint8_t PassengerDoor_Status;
extern uint8_t RearLeftDoor_Status;
extern uint8_t RearRightDoor_Status;

extern uint8_t DriverWindow_Status;
extern uint8_t PassengerWindow_Status;
extern uint8_t RearLeftWindow_Status;
extern uint8_t RearRightWindow_Status;

extern uint8_t VehicleAntiTheft_Real_Status;
extern uint8_t VehicleSpeed_Real_Status;
extern uint8_t EngineSpeed_Real_Status;
extern uint8_t Odometer_Real_Status;

extern uint8_t RearWiper_Real_Status;

extern uint8_t VehicleCrank_Real_Status;
extern uint8_t VehicleLock_Real_Status;
extern uint8_t RestoreRequest_Real_Status;
extern uint8_t VehicleGearLever_Real_Status;
extern uint8_t BusPowerMode_Real_Status;

extern uint8_t VehicleGearLever_E2E_Status;
extern uint8_t MessageRx_VehicleGearLever_E2E;

extern uint8_t FrontBlowerSpeed_Real_Status;
extern uint8_t RearBlowerSpeed_Real_Status;
extern uint8_t Bus_Temperature_Real_Status;
extern uint8_t Bus_Temperature_Valid;

extern uint8_t BusTemperatureOutOfRange_Real_Status;
extern uint8_t SunRoofPosition_Real_Status;
extern uint8_t DriverDoor_Real_Status;
extern uint8_t PassengerDoor_Real_Status;
extern uint8_t RearLeftDoor_Real_Status;
extern uint8_t RearRightDoor_Real_Status;

extern uint8_t DriverWindow_Real_Status;
extern uint8_t PassengerWindow_Real_Status;
extern uint8_t RearLeftWindow_Real_Status;
extern uint8_t RearRightWindow_Real_Status;

extern uint8_t TouchPad_Real_Status;
extern uint8_t RemoteKey_Real_Status;
extern uint8_t FobLongPress_Real_Status;
extern uint8_t FobShortPress_Real_Status;
extern uint8_t KickSensor_Real_Status;
extern uint8_t AutoOpen_Real_Status;
extern uint8_t AutoClose_Real_Status;
extern uint8_t RemindStart_Real_Status;
extern uint8_t RemindStop_Real_Status;
extern uint8_t ComfortClose_Real_Status;
extern uint8_t PKETrunkButton_Real_Status;
extern uint8_t VirtualButton_Real_Status;
extern uint8_t AppOpen_Real_Status;
extern uint8_t AppClose_Real_Status;
extern uint8_t AppStop_Real_Status;
extern uint8_t VROpen_Real_Status;
extern uint8_t VRClose_Real_Status;
extern uint8_t VRStop_Real_Status;

#ifdef _CONFIG_FOBMode
extern uint8_t Vehicle_FOBModeA;
extern uint8_t FOBModeA_Status;
extern uint8_t MessageRx_FOBModeA_1_Signal;
extern uint8_t MessageRx_FOBModeA_2_Signal;
extern uint8_t MessageRx_FOBModeA_1_Signal_Valid;
extern uint8_t MessageRx_FOBModeA_2_Signal_Valid;
extern uint8_t MessageRx_FOBModeA_1_Signal_Ind;
extern uint8_t MessageRx_FOBModeA_2_Signal_Ind;
extern uint8_t Vehicle_FOBModeB;
extern uint8_t FOBModeB_Status;
extern uint8_t MessageRx_FOBModeB_1_Signal;
extern uint8_t MessageRx_FOBModeB_2_Signal;
extern uint8_t MessageRx_FOBModeB_1_Signal_Valid;
extern uint8_t MessageRx_FOBModeB_2_Signal_Valid;
extern uint8_t MessageRx_FOBModeB_1_Signal_Ind;
extern uint8_t MessageRx_FOBModeB_2_Signal_Ind;
extern uint8_t Vehicle_FOBModeC;
extern uint8_t FOBModeC_Status;
extern uint8_t MessageRx_FOBModeC_1_Signal;
extern uint8_t MessageRx_FOBModeC_2_Signal;
extern uint8_t MessageRx_FOBModeC_1_Signal_Valid;
extern uint8_t MessageRx_FOBModeC_2_Signal_Valid;
extern uint8_t MessageRx_FOBModeC_1_Signal_Ind;
extern uint8_t MessageRx_FOBModeC_2_Signal_Ind;
#endif

#ifdef _CONFIG_TouchPad
extern uint32_t TouchPad_DataStream;
extern uint8_t TouchPad_Status;
extern uint8_t TouchPad_LastStatus;
extern uint8_t TouchPad_RiseEdge_Active;
extern uint8_t TouchPad_FallEdge_Active;
extern uint8_t TouchPad_ShortPress_Active;
extern uint8_t TouchPad_LongPress_Active;
extern uint8_t TouchPad_ShortPress_Status;
extern uint8_t TouchPad_ShortPress_LastStatus;
extern uint8_t TouchPad_Real_Status;
extern uint8_t TouchPad_SingleEvent_Enable;
extern uint8_t MessageRx_TouchPad;
extern uint8_t MessageRx_TouchPad_Valid;
extern uint8_t MessageRx_TouchPad_Ind;
#endif

#ifdef _CONFIG_TouchPad_2nd
extern uint32_t TouchPad_2nd_DataStream;
extern uint8_t TouchPad_2nd_Status;
extern uint8_t TouchPad_2nd_LastStatus;
extern uint8_t TouchPad_2nd_RiseEdge_Active;
extern uint8_t TouchPad_2nd_FallEdge_Active;
extern uint8_t TouchPad_2nd_Real_Status;
extern uint8_t TouchPad_2nd_SingleEvent_Enable;
extern uint8_t MessageRx_TouchPad_2nd;
extern uint8_t MessageRx_TouchPad_2nd_Valid;
extern uint8_t MessageRx_TouchPad_2nd_Ind;
#endif

#ifdef _CONFIG_RemoteKey
extern uint32_t RemoteKey_DataStream;
extern uint8_t RemoteKey_Status;
extern uint8_t RemoteKey_LastStatus;
extern uint8_t RemoteKey_RiseEdge_Active;
extern uint8_t RemoteKey_FallEdge_Active;
extern uint8_t RemoteKey_ShortPress_Active;
extern uint8_t RemoteKey_LongPress_Active;
extern uint8_t RemoteKey_ShortPress_Status;
extern uint8_t RemoteKey_ShortPress_LastStatus;
extern uint8_t RemoteKey_Real_Status;
extern uint8_t RemoteKey_SingleEvent_Enable;
extern uint8_t MessageRx_RemoteKey;
extern uint8_t MessageRx_RemoteKey_Valid;
extern uint8_t MessageRx_RemoteKey_Ind;
#endif

#ifdef _CONFIG_FobLongPress
extern uint32_t FobLongPress_DataStream;
extern uint8_t FobLongPress_Status;
extern uint8_t FobLongPress_LastStatus;
extern uint8_t FobLongPress_RiseEdge_Active;
extern uint8_t FobLongPress_FallEdge_Active;
extern uint8_t FobLongPress_Real_Status;
extern uint8_t FobLongPress_SingleEvent_Enable;
extern uint8_t MessageRx_FobLongPress;
extern uint8_t MessageRx_FobLongPress_Valid;
extern uint8_t MessageRx_FobLongPress_Ind;
#endif

#ifdef _CONFIG_FobShortPress
extern uint32_t FobShortPress_DataStream;
extern uint8_t FobShortPress_Status;
extern uint8_t FobShortPress_LastStatus;
extern uint8_t FobShortPress_RiseEdge_Active;
extern uint8_t FobShortPress_FallEdge_Active;
extern uint8_t FobShortPress_Real_Status;
extern uint8_t FobShortPress_SingleEvent_Enable;
extern uint8_t MessageRx_FobShortPress;
extern uint8_t MessageRx_FobShortPress_Valid;
extern uint8_t MessageRx_FobShortPress_Ind;
#endif

#ifdef _CONFIG_KickSensor
extern uint32_t KickSensor_DataStream;
extern uint8_t KickSensor_Status;
extern uint8_t KickSensor_LastStatus;
extern uint8_t KickSensor_RiseEdge_Active;
extern uint8_t KickSensor_FallEdge_Active;
extern uint8_t KickSensor_Real_Status;
extern uint8_t KickSensor_SingleEvent_Enable;
extern uint8_t MessageRx_KickSensor;
extern uint8_t MessageRx_KickSensor_Valid;
extern uint8_t MessageRx_KickSensor_Ind;
#endif

#ifdef _CONFIG_RemindStart
extern uint32_t RemindStart_DataStream;
extern uint8_t RemindStart_Status;
extern uint8_t RemindStart_LastStatus;
extern uint8_t RemindStart_RiseEdge_Active;
extern uint8_t RemindStart_FallEdge_Active;
extern uint8_t RemindStart_Real_Status;
extern uint8_t RemindStart_SingleEvent_Enable;
extern uint8_t MessageRx_RemindStart;
extern uint8_t MessageRx_RemindStart_Valid;
extern uint8_t MessageRx_RemindStart_Ind;
#endif

#ifdef _CONFIG_RemindStop
extern uint32_t RemindStop_DataStream;
extern uint8_t RemindStop_Status;
extern uint8_t RemindStop_LastStatus;
extern uint8_t RemindStop_RiseEdge_Active;
extern uint8_t RemindStop_FallEdge_Active;
extern uint8_t RemindStop_Real_Status;
extern uint8_t RemindStop_SingleEvent_Enable;
extern uint8_t MessageRx_RemindStop;
extern uint8_t MessageRx_RemindStop_Valid;
extern uint8_t MessageRx_RemindStop_Ind;
#endif

#ifdef _CONFIG_ComfortClose
extern uint32_t ComfortClose_DataStream;
extern uint8_t ComfortClose_Status;
extern uint8_t ComfortClose_LastStatus;
extern uint8_t ComfortClose_RiseEdge_Active;
extern uint8_t ComfortClose_FallEdge_Active;
extern uint8_t ComfortClose_Real_Status;
extern uint8_t ComfortClose_SingleEvent_Enable;
extern uint8_t MessageRx_ComfortClose;
extern uint8_t MessageRx_ComfortClose_Valid;
extern uint8_t MessageRx_ComfortClose_Ind;
#endif

#ifdef _CONFIG_PKETrunkButton
extern uint32_t PKETrunkButton_DataStream;
extern uint8_t PKETrunkButton_Status;
extern uint8_t PKETrunkButton_LastStatus;
extern uint8_t PKETrunkButton_RiseEdge_Active;
extern uint8_t PKETrunkButton_FallEdge_Active;
extern uint8_t PKETrunkButton_Real_Status;
extern uint8_t PKETrunkButton_SingleEvent_Enable;
extern uint8_t MessageRx_PKETrunkButton;
extern uint8_t MessageRx_PKETrunkButton_Valid;
extern uint8_t MessageRx_PKETrunkButton_Ind;
#endif

#ifdef _CONFIG_VirtualButton
extern uint32_t VirtualButton_DataStream;
extern uint8_t VirtualButton_Status;
extern uint8_t VirtualButton_LastStatus;
extern uint8_t VirtualButton_RiseEdge_Active;
extern uint8_t VirtualButton_FallEdge_Active;
extern uint8_t VirtualButton_Real_Status;
extern uint8_t VirtualButton_SingleEvent_Enable;
extern uint8_t MessageRx_VirtualButton;
extern uint8_t MessageRx_VirtualButton_Valid;
extern uint8_t MessageRx_VirtualButton_Ind;
#endif

#ifdef _CONFIG_VoiceOpen
extern uint32_t VoiceOpen_DataStream;
extern uint8_t VoiceOpen_Status;
extern uint8_t VoiceOpen_LastStatus;
extern uint8_t VoiceOpen_RiseEdge_Active;
extern uint8_t VoiceOpen_FallEdge_Active;
extern uint8_t VoiceOpen_Real_Status;
extern uint8_t VoiceOpen_SingleEvent_Enable;
extern uint8_t MessageRx_VoiceOpen;
extern uint8_t MessageRx_VoiceOpen_Valid;
extern uint8_t MessageRx_VoiceOpen_Ind;
#endif

#ifdef _CONFIG_VoiceClose
extern uint32_t VoiceClose_DataStream;
extern uint8_t VoiceClose_Status;
extern uint8_t VoiceClose_LastStatus;
extern uint8_t VoiceClose_RiseEdge_Active;
extern uint8_t VoiceClose_FallEdge_Active;
extern uint8_t VoiceClose_Real_Status;
extern uint8_t VoiceClose_SingleEvent_Enable;
extern uint8_t MessageRx_VoiceClose;
extern uint8_t MessageRx_VoiceClose_Valid;
extern uint8_t MessageRx_VoiceClose_Ind;
#endif

#ifdef _CONFIG_VoiceStop
extern uint32_t VoiceStop_DataStream;
extern uint8_t VoiceStop_Status;
extern uint8_t VoiceStop_LastStatus;
extern uint8_t VoiceStop_RiseEdge_Active;
extern uint8_t VoiceStop_FallEdge_Active;
extern uint8_t VoiceStop_Real_Status;
extern uint8_t VoiceStop_SingleEvent_Enable;
extern uint8_t MessageRx_VoiceStop;
extern uint8_t MessageRx_VoiceStop_Valid;
extern uint8_t MessageRx_VoiceStop_Ind;
#endif

//#ifdef _CONFIG_AppOpen
extern uint32_t AppOpen_DataStream;
extern uint8_t AppOpen_Status;
extern uint8_t AppOpen_LastStatus;
extern uint8_t AppOpen_RiseEdge_Active;
extern uint8_t AppOpen_FallEdge_Active;
extern uint8_t AppOpen_Real_Status;
extern uint8_t AppOpen_SingleEvent_Enable;
extern uint8_t MessageRx_AppOpen;
extern uint8_t MessageRx_AppOpen_Valid;
extern uint8_t MessageRx_AppOpen_Ind;
//#endif

//#ifdef _CONFIG_AppClose
extern uint32_t AppClose_DataStream;
extern uint8_t AppClose_Status;
extern uint8_t AppClose_LastStatus;
extern uint8_t AppClose_RiseEdge_Active;
extern uint8_t AppClose_FallEdge_Active;
extern uint8_t AppClose_Real_Status;
extern uint8_t AppClose_SingleEvent_Enable;
extern uint8_t MessageRx_AppClose;
extern uint8_t MessageRx_AppClose_Valid;
extern uint8_t MessageRx_AppClose_Ind;
//#endif

//#ifdef _CONFIG_AppStop
extern uint32_t AppStop_DataStream;
extern uint8_t AppStop_Status;
extern uint8_t AppStop_LastStatus;
extern uint8_t AppStop_RiseEdge_Active;
extern uint8_t AppStop_FallEdge_Active;
extern uint8_t AppStop_Real_Status;
extern uint8_t AppStop_SingleEvent_Enable;
extern uint8_t MessageRx_AppStop;
extern uint8_t MessageRx_AppStop_Valid;
extern uint8_t MessageRx_AppStop_Ind;
//#endif

//#ifdef _CONFIG_AppButton
extern uint32_t AppButton_DataStream;
extern uint8_t AppButton_Status;
extern uint8_t AppButton_LastStatus;
extern uint8_t AppButton_RiseEdge_Active;
extern uint8_t AppButton_FallEdge_Active;
extern uint8_t AppButton_Real_Status;
extern uint8_t AppButton_SingleEvent_Enable;
extern uint8_t MessageRx_AppButton;
extern uint8_t MessageRx_AppButton_Valid;
extern uint8_t MessageRx_AppButton_Ind;
//#endif

//#ifdef _CONFIG_AppEnable
extern uint32_t AppEnable_DataStream;
extern uint8_t AppEnable_Status;
extern uint8_t AppEnable_LastStatus;
extern uint8_t AppEnable_RiseEdge_Active;
extern uint8_t AppEnable_FallEdge_Active;
extern uint8_t AppEnable_Real_Status;
extern uint8_t AppEnable_SingleEvent_Enable;
extern uint8_t MessageRx_AppEnable;
extern uint8_t MessageRx_AppEnable_Valid;
extern uint8_t MessageRx_AppEnable_Ind;
//#endif

//#ifdef _CONFIG_AppReset
extern uint32_t AppReset_DataStream;
extern uint8_t AppReset_Status;
extern uint8_t AppReset_LastStatus;
extern uint8_t AppReset_RiseEdge_Active;
extern uint8_t AppReset_FallEdge_Active;
extern uint8_t AppReset_Real_Status;
extern uint8_t AppReset_SingleEvent_Enable;
extern uint8_t MessageRx_AppReset;
extern uint8_t MessageRx_AppReset_Valid;
extern uint8_t MessageRx_AppReset_Ind;
//#endif

//#ifdef _CONFIG_AppDemoMode
extern uint32_t AppDemoMode_DataStream;
extern uint8_t AppDemoMode_Status;
extern uint8_t AppDemoMode_LastStatus;
extern uint8_t AppDemoMode_RiseEdge_Active;
extern uint8_t AppDemoMode_FallEdge_Active;
extern uint8_t AppDemoMode_Real_Status;
extern uint8_t AppDemoMode_SingleEvent_Enable;
extern uint8_t MessageRx_AppDemoMode;
extern uint8_t MessageRx_AppDemoMode_Valid;
extern uint8_t MessageRx_AppDemoMode_Ind;
//#endif

#ifdef _CONFIG_VROpen
extern uint32_t VROpen_DataStream;
extern uint8_t VROpen_Status;
extern uint8_t VROpen_LastStatus;
extern uint8_t VROpen_RiseEdge_Active;
extern uint8_t VROpen_FallEdge_Active;
extern uint8_t VROpen_Real_Status;
extern uint8_t VROpen_SingleEvent_Enable;
extern uint8_t MessageRx_VROpen;
extern uint8_t MessageRx_VROpen_Valid;
extern uint8_t MessageRx_VROpen_Ind;
#endif

#ifdef _CONFIG_VRClose
extern uint32_t VRClose_DataStream;
extern uint8_t VRClose_Status;
extern uint8_t VRClose_LastStatus;
extern uint8_t VRClose_RiseEdge_Active;
extern uint8_t VRClose_FallEdge_Active;
extern uint8_t VRClose_Real_Status;
extern uint8_t VRClose_SingleEvent_Enable;
extern uint8_t MessageRx_VRClose;
extern uint8_t MessageRx_VRClose_Valid;
extern uint8_t MessageRx_VRClose_Ind;
#endif

#ifdef _CONFIG_VRStop
extern uint32_t VRStop_DataStream;
extern uint8_t VRStop_Status;
extern uint8_t VRStop_LastStatus;
extern uint8_t VRStop_RiseEdge_Active;
extern uint8_t VRStop_FallEdge_Active;
extern uint8_t VRStop_Real_Status;
extern uint8_t VRStop_SingleEvent_Enable;
extern uint8_t MessageRx_VRStop;
extern uint8_t MessageRx_VRStop_Valid;
extern uint8_t MessageRx_VRStop_Ind;
#endif

#ifdef _CONFIG_VRStopDirectly
extern uint32_t VRStopDirectly_DataStream;
extern uint8_t VRStopDirectly_Status;
extern uint8_t VRStopDirectly_LastStatus;
extern uint8_t VRStopDirectly_RiseEdge_Active;
extern uint8_t VRStopDirectly_FallEdge_Active;
extern uint8_t VRStopDirectly_Real_Status;
extern uint8_t VRStopDirectly_SingleEvent_Enable;
extern uint8_t MessageRx_VRStopDirectly;
extern uint8_t MessageRx_VRStopDirectly_Valid;
extern uint8_t MessageRx_VRStopDirectly_Ind;
#endif

#ifdef _CONFIG_VRSmallOpen
extern uint32_t VRSmallOpen_DataStream;
extern uint8_t VRSmallOpen_Status;
extern uint8_t VRSmallOpen_LastStatus;
extern uint8_t VRSmallOpen_RiseEdge_Active;
extern uint8_t VRSmallOpen_FallEdge_Active;
extern uint8_t VRSmallOpen_Real_Status;
extern uint8_t VRSmallOpen_SingleEvent_Enable;
extern uint8_t MessageRx_VRSmallOpen;
extern uint8_t MessageRx_VRSmallOpen_Valid;
extern uint8_t MessageRx_VRSmallOpen_Ind;
#endif

#ifdef _CONFIG_AppStepOpen
extern uint32_t AppStepOpen_DataStream;
extern uint8_t AppStepOpen_Status;
extern uint8_t AppStepOpen_LastStatus;
extern uint8_t AppStepOpen_RiseEdge_Active;
extern uint8_t AppStepOpen_FallEdge_Active;
extern uint8_t AppStepOpen_Real_Status;
extern uint8_t AppStepOpen_SingleEvent_Enable;
extern uint8_t MessageRx_AppStepOpen;
extern uint8_t MessageRx_AppStepOpen_Valid;
extern uint8_t MessageRx_AppStepOpen_Ind;
#endif
#ifdef _CONFIG_AppStepClose
extern uint32_t AppStepClose_DataStream;
extern uint8_t AppStepClose_Status;
extern uint8_t AppStepClose_LastStatus;
extern uint8_t AppStepClose_RiseEdge_Active;
extern uint8_t AppStepClose_FallEdge_Active;
extern uint8_t AppStepClose_Real_Status;
extern uint8_t AppStepClose_SingleEvent_Enable;
extern uint8_t MessageRx_AppStepClose;
extern uint8_t MessageRx_AppStepClose_Valid;
extern uint8_t MessageRx_AppStepClose_Ind;
#endif
#ifdef _CONFIG_VRStepOpen
extern uint32_t VRStepOpen_DataStream;
extern uint8_t VRStepOpen_Status;
extern uint8_t VRStepOpen_LastStatus;
extern uint8_t VRStepOpen_RiseEdge_Active;
extern uint8_t VRStepOpen_FallEdge_Active;
extern uint8_t VRStepOpen_Real_Status;
extern uint8_t VRStepOpen_SingleEvent_Enable;
extern uint8_t MessageRx_VRStepOpen;
extern uint8_t MessageRx_VRStepOpen_Valid;
extern uint8_t MessageRx_VRStepOpen_Ind;
#endif
#ifdef _CONFIG_VRStepClose
extern uint32_t VRStepClose_DataStream;
extern uint8_t VRStepClose_Status;
extern uint8_t VRStepClose_LastStatus;
extern uint8_t VRStepClose_RiseEdge_Active;
extern uint8_t VRStepClose_FallEdge_Active;
extern uint8_t VRStepClose_Real_Status;
extern uint8_t VRStepClose_SingleEvent_Enable;
extern uint8_t MessageRx_VRStepClose;
extern uint8_t MessageRx_VRStepClose_Valid;
extern uint8_t MessageRx_VRStepClose_Ind;
#endif

#ifdef _CONFIG_AutoOpen
extern uint32_t AutoOpen_DataStream;
extern uint8_t AutoOpen_Status;
extern uint8_t AutoOpen_LastStatus;
extern uint8_t AutoOpen_RiseEdge_Active;
extern uint8_t AutoOpen_FallEdge_Active;
extern uint8_t AutoOpen_Real_Status;
extern uint8_t AutoOpen_SingleEvent_Enable;
extern uint8_t MessageRx_AutoOpen;
extern uint8_t MessageRx_AutoOpen_Valid;
extern uint8_t MessageRx_AutoOpen_Ind;
#endif

#ifdef _CONFIG_AutoClose
extern uint32_t AutoClose_DataStream;
extern uint8_t AutoClose_Status;
extern uint8_t AutoClose_LastStatus;
extern uint8_t AutoClose_RiseEdge_Active;
extern uint8_t AutoClose_FallEdge_Active;
extern uint8_t AutoClose_Real_Status;
extern uint8_t AutoClose_SingleEvent_Enable;
extern uint8_t MessageRx_AutoClose;
extern uint8_t MessageRx_AutoClose_Valid;
extern uint8_t MessageRx_AutoClose_Ind;
#endif
#ifdef _CONFIG_AutoStop
extern uint32_t AutoStop_DataStream;
extern uint8_t AutoStop_Status;
extern uint8_t AutoStop_LastStatus;
extern uint8_t AutoStop_RiseEdge_Active;
extern uint8_t AutoStop_FallEdge_Active;
extern uint8_t AutoStop_Real_Status;
extern uint8_t AutoStop_SingleEvent_Enable;
extern uint8_t MessageRx_AutoStop;
extern uint8_t MessageRx_AutoStop_Valid;
extern uint8_t MessageRx_AutoStop_Ind;
#endif
#ifdef _CONFIG_AutoStepOpen
extern uint32_t AutoStepOpen_DataStream;
extern uint8_t AutoStepOpen_Status;
extern uint8_t AutoStepOpen_LastStatus;
extern uint8_t AutoStepOpen_RiseEdge_Active;
extern uint8_t AutoStepOpen_FallEdge_Active;
extern uint8_t AutoStepOpen_Real_Status;
extern uint8_t AutoStepOpen_SingleEvent_Enable;
extern uint8_t MessageRx_AutoStepOpen;
extern uint8_t MessageRx_AutoStepOpen_Valid;
extern uint8_t MessageRx_AutoStepOpen_Ind;
#endif
#ifdef _CONFIG_AutoStepClose
extern uint32_t AutoStepClose_DataStream;
extern uint8_t AutoStepClose_Status;
extern uint8_t AutoStepClose_LastStatus;
extern uint8_t AutoStepClose_RiseEdge_Active;
extern uint8_t AutoStepClose_FallEdge_Active;
extern uint8_t AutoStepClose_Real_Status;
extern uint8_t AutoStepClose_SingleEvent_Enable;
extern uint8_t MessageRx_AutoStepClose;
extern uint8_t MessageRx_AutoStepClose_Valid;
extern uint8_t MessageRx_AutoStepClose_Ind;
#endif
      
#ifdef _CONFIG_BLEOpen
extern uint32_t BLEOpen_DataStream;
extern uint8_t BLEOpen_Status;
extern uint8_t BLEOpen_LastStatus;
extern uint8_t BLEOpen_RiseEdge_Active;
extern uint8_t BLEOpen_FallEdge_Active;
extern uint8_t BLEOpen_Real_Status;
extern uint8_t BLEOpen_SingleEvent_Enable;
extern uint8_t MessageRx_BLEOpen;
extern uint8_t MessageRx_BLEOpen_Valid;
extern uint8_t MessageRx_BLEOpen_Ind;
#endif
#ifdef _CONFIG_BLEClose
extern uint32_t BLEClose_DataStream;
extern uint8_t BLEClose_Status;
extern uint8_t BLEClose_LastStatus;
extern uint8_t BLEClose_RiseEdge_Active;
extern uint8_t BLEClose_FallEdge_Active;
extern uint8_t BLEClose_Real_Status;
extern uint8_t BLEClose_SingleEvent_Enable;
extern uint8_t MessageRx_BLEClose;
extern uint8_t MessageRx_BLEClose_Valid;
extern uint8_t MessageRx_BLEClose_Ind;
#endif
#ifdef _CONFIG_BLEStop
extern uint32_t BLEStop_DataStream;
extern uint8_t BLEStop_Status;
extern uint8_t BLEStop_LastStatus;
extern uint8_t BLEStop_RiseEdge_Active;
extern uint8_t BLEStop_FallEdge_Active;
extern uint8_t BLEStop_Real_Status;
extern uint8_t BLEStop_SingleEvent_Enable;
extern uint8_t MessageRx_BLEStop;
extern uint8_t MessageRx_BLEStop_Valid;
extern uint8_t MessageRx_BLEStop_Ind;
#endif
#ifdef _CONFIG_BLEStepOpen
extern uint32_t BLEStepOpen_DataStream;
extern uint8_t BLEStepOpen_Status;
extern uint8_t BLEStepOpen_LastStatus;
extern uint8_t BLEStepOpen_RiseEdge_Active;
extern uint8_t BLEStepOpen_FallEdge_Active;
extern uint8_t BLEStepOpen_Real_Status;
extern uint8_t BLEStepOpen_SingleEvent_Enable;
extern uint8_t MessageRx_BLEStepOpen;
extern uint8_t MessageRx_BLEStepOpen_Valid;
extern uint8_t MessageRx_BLEStepOpen_Ind;
#endif
#ifdef _CONFIG_BLEStepClose
extern uint32_t BLEStepClose_DataStream;
extern uint8_t BLEStepClose_Status;
extern uint8_t BLEStepClose_LastStatus;
extern uint8_t BLEStepClose_RiseEdge_Active;
extern uint8_t BLEStepClose_FallEdge_Active;
extern uint8_t BLEStepClose_Real_Status;
extern uint8_t BLEStepClose_SingleEvent_Enable;
extern uint8_t MessageRx_BLEStepClose;
extern uint8_t MessageRx_BLEStepClose_Valid;
extern uint8_t MessageRx_BLEStepClose_Ind;
#endif

#ifdef _CONFIG_BLEButton
extern uint32_t BLEButton_DataStream;
extern uint8_t BLEButton_Status;
extern uint8_t BLEButton_LastStatus;
extern uint8_t BLEButton_RiseEdge_Active;
extern uint8_t BLEButton_FallEdge_Active;
extern uint8_t BLEButton_Real_Status;
extern uint8_t BLEButton_SingleEvent_Enable;
extern uint8_t MessageRx_BLEButton;
extern uint8_t MessageRx_BLEButton_Valid;
extern uint8_t MessageRx_BLEButton_Ind;
#endif

#ifdef _CONFIG_RKEOpen
extern uint32_t RKEOpen_DataStream;
extern uint8_t RKEOpen_Status;
extern uint8_t RKEOpen_LastStatus;
extern uint8_t RKEOpen_RiseEdge_Active;
extern uint8_t RKEOpen_FallEdge_Active;
extern uint8_t RKEOpen_Real_Status;
extern uint8_t RKEOpen_SingleEvent_Enable;
extern uint8_t MessageRx_RKEOpen;
extern uint8_t MessageRx_RKEOpen_Valid;
extern uint8_t MessageRx_RKEOpen_Ind;
#endif
#ifdef _CONFIG_RKEClose
extern uint32_t RKEClose_DataStream;
extern uint8_t RKEClose_Status;
extern uint8_t RKEClose_LastStatus;
extern uint8_t RKEClose_RiseEdge_Active;
extern uint8_t RKEClose_FallEdge_Active;
extern uint8_t RKEClose_Real_Status;
extern uint8_t RKEClose_SingleEvent_Enable;
extern uint8_t MessageRx_RKEClose;
extern uint8_t MessageRx_RKEClose_Valid;
extern uint8_t MessageRx_RKEClose_Ind;
#endif
#ifdef _CONFIG_RKEStopOpen
extern uint32_t RKEStopOpen_DataStream;
extern uint8_t RKEStopOpen_Status;
extern uint8_t RKEStopOpen_LastStatus;
extern uint8_t RKEStopOpen_RiseEdge_Active;
extern uint8_t RKEStopOpen_FallEdge_Active;
extern uint8_t RKEStopOpen_Real_Status;
extern uint8_t RKEStopOpen_SingleEvent_Enable;
extern uint8_t MessageRx_RKEStopOpen;
extern uint8_t MessageRx_RKEStopOpen_Valid;
extern uint8_t MessageRx_RKEStopOpen_Ind;
#endif
#ifdef _CONFIG_RKEStopClose
extern uint32_t RKEStopClose_DataStream;
extern uint8_t RKEStopClose_Status;
extern uint8_t RKEStopClose_LastStatus;
extern uint8_t RKEStopClose_RiseEdge_Active;
extern uint8_t RKEStopClose_FallEdge_Active;
extern uint8_t RKEStopClose_Real_Status;
extern uint8_t RKEStopClose_SingleEvent_Enable;
extern uint8_t MessageRx_RKEStopClose;
extern uint8_t MessageRx_RKEStopClose_Valid;
extern uint8_t MessageRx_RKEStopClose_Ind;
#endif
#ifdef _CONFIG_RKEStepOpen
extern uint32_t RKEStepOpen_DataStream;
extern uint8_t RKEStepOpen_Status;
extern uint8_t RKEStepOpen_LastStatus;
extern uint8_t RKEStepOpen_RiseEdge_Active;
extern uint8_t RKEStepOpen_FallEdge_Active;
extern uint8_t RKEStepOpen_Real_Status;
extern uint8_t RKEStepOpen_SingleEvent_Enable;
extern uint8_t MessageRx_RKEStepOpen;
extern uint8_t MessageRx_RKEStepOpen_Valid;
extern uint8_t MessageRx_RKEStepOpen_Ind;
#endif
#ifdef _CONFIG_RKEStepClose
extern uint32_t RKEStepClose_DataStream;
extern uint8_t RKEStepClose_Status;
extern uint8_t RKEStepClose_LastStatus;
extern uint8_t RKEStepClose_RiseEdge_Active;
extern uint8_t RKEStepClose_FallEdge_Active;
extern uint8_t RKEStepClose_Real_Status;
extern uint8_t RKEStepClose_SingleEvent_Enable;
extern uint8_t MessageRx_RKEStepClose;
extern uint8_t MessageRx_RKEStepClose_Valid;
extern uint8_t MessageRx_RKEStepClose_Ind;
#endif

#ifdef _CONFIG_RestoreRequest
extern uint32_t RestoreRequest_DataStream;
extern uint8_t RestoreRequest_Status;
extern uint8_t RestoreRequest_LastStatus;
extern uint8_t RestoreRequest_RiseEdge_Active;
extern uint8_t RestoreRequest_FallEdge_Active;
extern uint8_t RestoreRequest_Real_Status;
extern uint8_t RestoreRequest_SingleEvent_Enable;
extern uint8_t MessageRx_RestoreRequest;
extern uint8_t MessageRx_RestoreRequest_Valid;
extern uint8_t MessageRx_RestoreRequest_Ind;
#endif

#ifdef _CONFIG_InsideButton
extern uint32_t InsideButton_DataStream;
extern uint8_t InsideButton_Status;
extern uint8_t InsideButton_LastStatus;
extern uint8_t InsideButton_RiseEdge_Active;
extern uint8_t InsideButton_FallEdge_Active;
extern uint8_t InsideButton_Real_Status;
extern uint8_t InsideButton_SingleEvent_Enable;
extern uint8_t MessageRx_InsideButton;
extern uint8_t MessageRx_InsideButton_Valid;
extern uint8_t MessageRx_InsideButton_Ind;

#ifdef _CONFIG_InsideButton_ShortPress
extern uint8_t InsideButton_ShortPress_Status;
extern uint8_t InsideButton_ShortPress_LastStatus;
extern uint8_t InsideButton_ShortPress_Active;
#endif
#ifdef _CONFIG_InsideButton_LongPress
extern uint8_t InsideButton_LongPress_Status;
extern uint8_t InsideButton_LongPress_LastStatus;
extern uint8_t InsideButton_LongPress_Active;
#endif
#endif

#ifdef _CONFIG_DriverButton
extern uint32_t DriverButton_DataStream;
extern uint8_t DriverButton_Status;
extern uint8_t DriverButton_LastStatus;
extern uint8_t DriverButton_RiseEdge_Active;
extern uint8_t DriverButton_FallEdge_Active;
extern uint8_t DriverButton_Real_Status;
extern uint8_t DriverButton_SingleEvent_Enable;
extern uint8_t MessageRx_DriverButton;
extern uint8_t MessageRx_DriverButton_Valid;
extern uint8_t MessageRx_DriverButton_Ind;

#ifdef _CONFIG_DriverButton_ShortPress
extern uint8_t DriverButton_ShortPress_Status;
extern uint8_t DriverButton_ShortPress_LastStatus;
extern uint8_t DriverButton_ShortPress_Active;
#endif
#ifdef _CONFIG_DriverButton_LongPress
extern uint8_t DriverButton_LongPress_Status;
extern uint8_t DriverButton_LongPress_LastStatus;
extern uint8_t DriverButton_LongPress_Active;
#endif
#endif

#ifdef _CONFIG_DriverButtonStop
extern uint32_t DriverButtonStop_DataStream;
extern uint8_t DriverButtonStop_Status;
extern uint8_t DriverButtonStop_LastStatus;
extern uint8_t DriverButtonStop_RiseEdge_Active;
extern uint8_t DriverButtonStop_FallEdge_Active;
extern uint8_t DriverButtonStop_Real_Status;
extern uint8_t DriverButtonStop_SingleEvent_Enable;
extern uint8_t MessageRx_DriverButtonStop;
extern uint8_t MessageRx_DriverButtonStop_Valid;
extern uint8_t MessageRx_DriverButtonStop_Ind;
#endif

#ifdef _CONFIG_SeatOccupied
extern uint32_t SeatOccupied_DataStream;
extern uint8_t SeatOccupied_Status;
extern uint8_t SeatOccupied_LastStatus;
extern uint8_t SeatOccupied_RiseEdge_Active;
extern uint8_t SeatOccupied_FallEdge_Active;
extern uint8_t SeatOccupied_Real_Status;
extern uint8_t SeatOccupied_SingleEvent_Enable;
extern uint8_t MessageRx_SeatOccupied;
extern uint8_t MessageRx_SeatOccupied_Valid;
extern uint8_t MessageRx_SeatOccupied_Ind;
#endif
#ifdef _CONFIG_SeatBelt
extern uint32_t SeatBelt_DataStream;
extern uint8_t SeatBelt_Status;
extern uint8_t SeatBelt_LastStatus;
extern uint8_t SeatBelt_RiseEdge_Active;
extern uint8_t SeatBelt_FallEdge_Active;
extern uint8_t SeatBelt_Real_Status;
extern uint8_t SeatBelt_SingleEvent_Enable;
extern uint8_t MessageRx_SeatBelt;
extern uint8_t MessageRx_SeatBelt_Valid;
extern uint8_t MessageRx_SeatBelt_Ind;
#endif

#ifdef _CONFIG_DelayClose
extern uint32_t DelayClose_DataStream;
extern uint8_t DelayClose_Status;
extern uint8_t DelayClose_LastStatus;
extern uint8_t DelayClose_RiseEdge_Active;
extern uint8_t DelayClose_FallEdge_Active;
extern uint8_t DelayClose_Real_Status;
extern uint8_t DelayClose_SingleEvent_Enable;
extern uint8_t MessageRx_DelayClose;
extern uint8_t MessageRx_DelayClose_Valid;
extern uint8_t MessageRx_DelayClose_Ind;

extern uint8_t DelayCloseMode_Status;
#endif

#ifdef _CONFIG_ManualRelease
extern uint32_t ManualRelease_DataStream;
extern uint8_t ManualRelease_Status;
extern uint8_t ManualRelease_LastStatus;
extern uint8_t ManualRelease_RiseEdge_Active;
extern uint8_t ManualRelease_FallEdge_Active;
extern uint8_t ManualRelease_Real_Status;
extern uint8_t ManualRelease_SingleEvent_Enable;
extern uint8_t MessageRx_ManualRelease;
extern uint8_t MessageRx_ManualRelease_Valid;
extern uint8_t MessageRx_ManualRelease_Ind;
#endif

#ifdef _CONFIG_GarageHeightRequest
extern uint16_t GarageHeightRequest_DataStream;
extern uint8_t GarageHeightRequest_Status;
extern uint8_t GarageHeightRequest_LastStatus;
extern uint8_t GarageHeightRequest_RiseEdge_Active;
extern uint8_t GarageHeightRequest_FallEdge_Active;
extern uint8_t GarageHeightRequest_Real_Status;
extern uint8_t MessageRx_GarageHeightRequest;
extern uint8_t MessageRx_GarageHeightRequest_Ind;
#endif
extern uint8_t GarageHeightRequest_Process_Status;


#ifdef _CONFIG_TargetPositionOpen
extern uint16_t TargetPositionOpen_DataStream;
extern uint8_t TargetPositionOpen_Status;
extern uint8_t TargetPositionOpen_LastStatus;
extern uint8_t TargetPositionOpen_RiseEdge_Active;
extern uint8_t TargetPositionOpen_FallEdge_Active;
extern uint8_t TargetPositionOpen_SingleEvent_Enable;
extern uint8_t TargetPositionOpen_Real_Status;
extern uint16_t TargetPositionOpen_StopPosition;
extern uint8_t MessageRx_TargetPositionOpen;
extern uint8_t MessageRx_TargetPositionOpen_Valid;
extern uint8_t MessageRx_TargetPositionOpen_Ind;
#endif
#ifdef _CONFIG_TargetPositionClose
extern uint16_t TargetPositionClose_DataStream;
extern uint8_t TargetPositionClose_Status;
extern uint8_t TargetPositionClose_LastStatus;
extern uint8_t TargetPositionClose_RiseEdge_Active;
extern uint8_t TargetPositionClose_FallEdge_Active;
extern uint8_t TargetPositionClose_SingleEvent_Enable;
extern uint8_t TargetPositionClose_Real_Status;
extern uint16_t TargetPositionClose_StopPosition;
extern uint8_t MessageRx_TargetPositionClose;
extern uint8_t MessageRx_TargetPositionClose_Valid;
extern uint8_t MessageRx_TargetPositionClose_Ind;
#endif

#ifdef _CONFIG_SlidePosition
extern uint16_t SlidePosition_DataStream;
extern uint8_t SlidePosition_Status;
extern uint8_t SlidePosition_LastStatus;
extern uint8_t SlidePosition_RiseEdge_Active;
extern uint8_t SlidePosition_FallEdge_Active;
extern uint8_t SlidePosition_SingleEvent_Enable;
extern uint8_t SlidePosition_Real_Status;
extern uint16_t SlidePosition_StartPosition;
extern uint16_t SlidePosition_StopPosition;
extern uint16_t SlidePosition_DeltaPosition;
#endif

#ifdef _CONFIG_AntiFalseLock
extern uint16_t AntiFalseLock_DataStream;
extern uint8_t AntiFalseLock_Status;
extern uint8_t AntiFalseLock_LastStatus;
extern uint8_t AntiFalseLock_RiseEdge_Active;
extern uint8_t AntiFalseLock_FallEdge_Active;
extern uint8_t AntiFalseLock_Real_Status;
extern uint8_t AntiFalseLock_SingleEvent_Enable;
extern uint8_t MessageRx_AntiFalseLock;
extern uint8_t MessageRx_AntiFalseLock_Valid;
extern uint8_t MessageRx_AntiFalseLock_Ind;
#endif

#ifdef _CONFIG_MusicControl
extern uint16_t MusicControl_DataStream;
extern uint8_t MusicControl_Status;
extern uint8_t MusicControl_LastStatus;
extern uint8_t MusicControl_RiseEdge_Active;
extern uint8_t MusicControl_FallEdge_Active;
extern uint8_t MusicControl_Real_Status;
extern uint8_t MusicControl_SingleEvent_Enable;
extern uint8_t MessageRx_MusicControl;
extern uint8_t MessageRx_MusicControl_Valid;
extern uint8_t MessageRx_MusicControl_Ind;
#endif

#ifdef _CONFIG_ReleaseState
extern uint16_t ReleaseState_DataStream;
extern uint8_t ReleaseState_Status;
extern uint8_t ReleaseState_LastStatus;
extern uint8_t ReleaseState_RiseEdge_Active;
extern uint8_t ReleaseState_FallEdge_Active;
extern uint8_t ReleaseState_Real_Status;
extern uint8_t ReleaseState_SingleEvent_Enable;
extern uint8_t MessageRx_ReleaseState;
extern uint8_t MessageRx_ReleaseState_Valid;
extern uint8_t MessageRx_ReleaseState_Ind;
#endif
#ifdef _CONFIG_LatchSignal
extern uint16_t LatchSignal_DataStream;
extern uint8_t LatchSignal_Status;
extern uint8_t LatchSignal_LastStatus;
extern uint8_t LatchSignal_RiseEdge_Active;
extern uint8_t LatchSignal_FallEdge_Active;
extern uint8_t LatchSignal_Real_Status;
extern uint8_t LatchSignal_SingleEvent_Enable;
extern uint8_t MessageRx_LatchSignal;
extern uint8_t MessageRx_LatchSignal_Valid;
extern uint8_t MessageRx_LatchSignal_Ind;
#endif
//#ifdef _CONFIG_PawlSignal
extern uint16_t PawlSignal_DataStream;
extern uint8_t PawlSignal_Status;
extern uint8_t PawlSignal_LastStatus;
extern uint8_t PawlSignal_RiseEdge_Active;
extern uint8_t PawlSignal_FallEdge_Active;
extern uint8_t PawlSignal_Real_Status;
extern uint8_t PawlSignal_SingleEvent_Enable;
extern uint8_t MessageRx_PawlSignal;
extern uint8_t MessageRx_PawlSignal_Valid;
extern uint8_t MessageRx_PawlSignal_Ind;
//#endif
//#ifdef _CONFIG_SecondarySignal
extern uint16_t SecondarySignal_DataStream;
extern uint8_t SecondarySignal_Status;
extern uint8_t SecondarySignal_LastStatus;
extern uint8_t SecondarySignal_RiseEdge_Active;
extern uint8_t SecondarySignal_FallEdge_Active;
extern uint8_t SecondarySignal_Real_Status;
extern uint8_t SecondarySignal_SingleEvent_Enable;
extern uint8_t MessageRx_SecondarySignal;
extern uint8_t MessageRx_SecondarySignal_Valid;
extern uint8_t MessageRx_SecondarySignal_Ind;
//#endif

//#ifdef _CONFIG_AjarSignal
extern uint16_t AjarSignal_DataStream;
extern uint8_t AjarSignal_Status;
extern uint8_t AjarSignal_LastStatus;
extern uint8_t AjarSignal_RiseEdge_Active;
extern uint8_t AjarSignal_FallEdge_Active;
extern uint8_t AjarSignal_Real_Status;
extern uint8_t AjarSignal_SingleEvent_Enable;
extern uint8_t MessageRx_AjarSignal;
extern uint8_t MessageRx_AjarSignal_Valid;
extern uint8_t MessageRx_AjarSignal_Ind;
//#endif
//#ifdef _CONFIG_PositionSignal
extern uint16_t PositionSignal_DataStream;
extern uint8_t PositionSignal_Status;
extern uint8_t PositionSignal_LastStatus;
extern uint8_t PositionSignal_RiseEdge_Active;
extern uint8_t PositionSignal_FallEdge_Active;
extern uint8_t PositionSignal_Real_Status;
extern uint8_t PositionSignal_SingleEvent_Enable;
extern uint8_t MessageRx_PositionSignal;
extern uint8_t MessageRx_PositionSignal_Valid;
extern uint8_t MessageRx_PositionSignal_Ind;
//#endif
#ifdef _CONFIG_LatchReleaseState
extern uint8_t LatchReleaseState_Valid_Status;
extern uint16_t LatchReleaseState_DataStream;
extern uint8_t LatchReleaseState_Status;
extern uint8_t LatchReleaseState_LastStatus;
extern uint8_t LatchReleaseState_RiseEdge_Active;
extern uint8_t LatchReleaseState_FallEdge_Active;
extern uint8_t LatchReleaseState_Real_Status;
extern uint8_t MessageRx_LatchReleaseState;
extern uint8_t MessageRx_LatchReleaseState_Valid;
extern uint8_t MessageRx_LatchReleaseState_Ind;
#endif
#ifdef _CONFIG_CentralLockSignal
extern uint16_t CentralLockSignal_DataStream;
extern uint8_t CentralLockSignal_Status;
extern uint8_t CentralLockSignal_LastStatus;
extern uint8_t CentralLockSignal_RiseEdge_Active;
extern uint8_t CentralLockSignal_FallEdge_Active;
extern uint8_t CentralLockSignal_Real_Status;
extern uint8_t CentralLockSignal_SingleEvent_Enable;
extern uint8_t MessageRx_CentralLockSignal;
extern uint8_t MessageRx_CentralLockSignal_Valid;
extern uint8_t MessageRx_CentralLockSignal_Ind;
#endif
#ifdef _CONFIG_ChildLockSignal
extern uint16_t ChildLockSignal_DataStream;
extern uint8_t ChildLockSignal_Status;
extern uint8_t ChildLockSignal_LastStatus;
extern uint8_t ChildLockSignal_RiseEdge_Active;
extern uint8_t ChildLockSignal_FallEdge_Active;
extern uint8_t ChildLockSignal_Real_Status;
extern uint8_t ChildLockSignal_SingleEvent_Enable;
extern uint8_t MessageRx_ChildLockSignal;
extern uint8_t MessageRx_ChildLockSignal_Valid;
extern uint8_t MessageRx_ChildLockSignal_Ind;
#endif

#ifdef _CONFIG_SunRoofPosition
extern uint8_t MessageRx_SunRoofPosition;
extern uint8_t MessageRx_SunRoofPosition_Ind;
extern uint8_t SunRoofPosition_Real_Status;
extern uint16_t SunRoofPosition_DataStream;
extern uint8_t SunRoofPosition_Status;
#endif

#ifdef _CONFIG_DoorStatus
extern uint8_t MessageRx_DriverDoor;
extern uint8_t MessageRx_DriverDoor_Valid;
extern uint8_t MessageRx_DriverDoor_Ind;
extern uint8_t DriverDoor_Real_Status;
extern uint16_t DriverDoor_DataStream;
extern uint8_t DriverDoor_Status;  

extern uint8_t MessageRx_PassengerDoor;
extern uint8_t MessageRx_PassengerDoor_Valid;
extern uint8_t MessageRx_PassengerDoor_Ind;
extern uint8_t PassengerDoor_Real_Status;
extern uint16_t PassengerDoor_DataStream;
extern uint8_t PassengerDoor_Status;  

extern uint8_t MessageRx_RearLeftDoor;
extern uint8_t MessageRx_RearLeftDoor_Valid;
extern uint8_t MessageRx_RearLeftDoor_Ind;
extern uint8_t RearLeftDoor_Real_Status;
extern uint16_t RearLeftDoor_DataStream;
extern uint8_t RearLeftDoor_Status;  

extern uint8_t MessageRx_RearRightDoor;
extern uint8_t MessageRx_RearRightDoor_Valid;
extern uint8_t MessageRx_RearRightDoor_Ind;
extern uint8_t RearRightDoor_Real_Status;
extern uint16_t RearRightDoor_DataStream;
extern uint8_t RearRightDoor_Status;  

#ifdef _CONFIG_DoorStatus_HoodDoor
extern uint8_t MessageRx_HoodDoor;
extern uint8_t MessageRx_HoodDoor_Valid;
extern uint8_t MessageRx_HoodDoor_Ind;
extern uint8_t HoodDoor_Real_Status;
extern uint16_t HoodDoor_DataStream;
extern uint8_t HoodDoor_Status; 
#endif

#ifdef _CONFIG_DoorStatus_TrunkDoor
extern uint8_t MessageRx_TrunkDoor;
extern uint8_t MessageRx_TrunkDoor_Valid;
extern uint8_t MessageRx_TrunkDoor_Ind;
extern uint8_t TrunkDoor_Real_Status;
extern uint16_t TrunkDoor_DataStream;
extern uint8_t TrunkDoor_Status; 
#endif



#endif

/*Save data before sleep*/


/*Mem_System_Information*/
#define Message_Information_BuffLen       10
typedef struct
{
     uint8_t MessageRx_VehiclePowerMode;
     uint8_t MessageRx_VehicleGearLever;
     uint8_t MessageRx_VehicleLock;
     uint8_t MessageRx_VehicleAntiTheft;
     uint8_t MessageRx_VehiclePowerMode_Valid;
     uint8_t MessageRx_VehicleGearLever_Valid;
     uint8_t MessageRx_VehicleLock_Valid;
     uint8_t MessageRx_VehicleAntiTheft_Valid;
     uint8_t MessageRx_VehicleHandBrake;
     uint8_t MessageRx_VehicleHandBrake_Valid;
           
}tD_Message_Information_Struct;

typedef union 
{
    tD_Message_Information_Struct element;
    uint8_t array[Message_Information_BuffLen];
}tD_Message_Information;

extern tD_Message_Information Mem_Message_Information;

#define Mem_MessageRx_VehiclePowerMode       Mem_Message_Information.element.MessageRx_VehiclePowerMode
#define Mem_MessageRx_VehicleGearLever      Mem_Message_Information.element.MessageRx_VehicleGearLever
#define Mem_MessageRx_VehicleLock         Mem_Message_Information.element.MessageRx_VehicleLock
#define Mem_MessageRx_VehicleAntiTheft              Mem_Message_Information.element.MessageRx_VehicleAntiTheft
#define Mem_MessageRx_VehiclePowerMode_Valid       Mem_Message_Information.element.MessageRx_VehiclePowerMode_Valid
#define Mem_MessageRx_VehicleGearLever_Valid      Mem_Message_Information.element.MessageRx_VehicleGearLever_Valid
#define Mem_MessageRx_VehicleLock_Valid         Mem_Message_Information.element.MessageRx_VehicleLock_Valid
#define Mem_MessageRx_VehicleAntiTheft_Valid              Mem_Message_Information.element.MessageRx_VehicleAntiTheft_Valid
#define Mem_MessageRx_VehicleHandBrake        Mem_Message_Information.element.MessageRx_VehicleHandBrake
#define Mem_MessageRx_VehicleHandBrake_Valid              Mem_Message_Information.element.MessageRx_VehicleHandBrake_Valid


#ifdef _CONFIG_MessageTx_Information
#define MessageTx_Information_BuffLen       2
typedef struct
{
     uint8_t MessageTx_MessageCounter;
     uint8_t MessageTx_Reserved;
           
}tD_MessageTx_Information_Struct;

typedef union 
{
    tD_MessageTx_Information_Struct element;
    uint8_t array[MessageTx_Information_BuffLen];
}tD_MessageTx_Information;

extern tD_MessageTx_Information Mem_MessageTx_Information;

#define Mem_MessageTx_MessageCounter       Mem_MessageTx_Information.element.MessageTx_MessageCounter
#define Mem_MessageTx_Reserved             Mem_MessageTx_Information.element.MessageTx_Reserved
#endif


#ifdef _CONFIG_FunctionEnable_KeepAfterWakeup
/*Mem_FunctionEnable*/
#define FunctionEnable_BuffLen    16
typedef struct
{
     uint8_t SpindleModeRequest;    
     uint8_t CinchEnable_Status;
     uint8_t BeltEnable_Status;
     uint8_t WindEnable_Status;
     uint8_t AutoOpenEnable_Status;
     uint8_t SpeedMode_Status;
     
     uint8_t BLEEnable_Status;
     uint8_t VoiceEnable_Status;
     uint8_t BrakeEnable_Status;
     uint8_t RKEEnable_Status;
     uint8_t DoorPowerMode_Status;
     uint8_t SmallOpenMode_Status;
     uint8_t PowerOpenDisable_Status;
     uint8_t DriveUnitDisable_Status;
     uint8_t LeftRightHandDrive_Status;
     uint8_t BNCMPresent_Status;
           
}tD_FunctionEnable_Struct;

typedef union 
{
    tD_FunctionEnable_Struct element;
    uint8_t array[FunctionEnable_BuffLen];
}tD_FunctionEnable;

extern tD_FunctionEnable Mem_FunctionEnable;

#define Mem_SpindleModeRequest       Mem_FunctionEnable.element.SpindleModeRequest
#define Mem_CinchEnable_Status       Mem_FunctionEnable.element.CinchEnable_Status
#define Mem_BeltEnable_Status        Mem_FunctionEnable.element.BeltEnable_Status
#define Mem_WindEnable_Status        Mem_FunctionEnable.element.WindEnable_Status
#define Mem_AutoOpenEnable_Status    Mem_FunctionEnable.element.AutoOpenEnable_Status
#define Mem_SpeedMode_Status         Mem_FunctionEnable.element.SpeedMode_Status

#define Mem_BLEEnable_Status         Mem_FunctionEnable.element.BLEEnable_Status
#define Mem_VoiceEnable_Status       Mem_FunctionEnable.element.VoiceEnable_Status
#define Mem_BrakeEnable_Status       Mem_FunctionEnable.element.BrakeEnable_Status
#define Mem_RKEEnable_Status         Mem_FunctionEnable.element.RKEEnable_Status
#define Mem_DoorPowerMode_Status     Mem_FunctionEnable.element.DoorPowerMode_Status
#define Mem_SmallOpenMode_Status     Mem_FunctionEnable.element.SmallOpenMode_Status
#define Mem_PowerOpenDisable_Status     Mem_FunctionEnable.element.PowerOpenDisable_Status
#define Mem_DriveUnitDisable_Status     Mem_FunctionEnable.element.DriveUnitDisable_Status
#define Mem_LeftRightHandDrive_Status   Mem_FunctionEnable.element.LeftRightHandDrive_Status
#define Mem_BNCMPresent_Status          Mem_FunctionEnable.element.BNCMPresent_Status
#endif


#ifdef _CONFIG_Vehicle_KeyMode
/*Mem_Vehicle_KeyMode*/
#define Vehicle_KeyMode_BuffLen       2
typedef struct
{
    uint8_t Vehicle_KeyOpenMode;    		        
    uint8_t Vehicle_KeyCloseMode;                  
}tD_Vehicle_KeyMode_Struct;

typedef union 
{
    tD_Vehicle_KeyMode_Struct element;
    uint8_t array[Vehicle_KeyMode_BuffLen];
}tD_Vehicle_KeyMode;

extern tD_Vehicle_KeyMode Mem_Vehicle_KeyMode;

#define Mem_Vehicle_KeyOpenMode        Mem_Vehicle_KeyMode.element.Vehicle_KeyOpenMode
#define Mem_Vehicle_KeyCloseMode       Mem_Vehicle_KeyMode.element.Vehicle_KeyCloseMode
#endif

#ifdef _CONFIG_FOBMode
/*Mem_Vehicle_FOBMode*/
#define Vehicle_FOBMode_BuffLen       3
typedef struct
{
    uint8_t Vehicle_FOBModeA;    		        
    uint8_t Vehicle_FOBModeB; 
    uint8_t Vehicle_FOBModeC;
}tD_Vehicle_FOBMode_Struct;

typedef union 
{
    tD_Vehicle_FOBMode_Struct element;
    uint8_t array[Vehicle_FOBMode_BuffLen];
}tD_Vehicle_FOBMode;

extern tD_Vehicle_FOBMode Mem_Vehicle_FOBMode;

#define Mem_Vehicle_FOBModeA       Mem_Vehicle_FOBMode.element.Vehicle_FOBModeA
#define Mem_Vehicle_FOBModeB       Mem_Vehicle_FOBMode.element.Vehicle_FOBModeB
#define Mem_Vehicle_FOBModeC       Mem_Vehicle_FOBMode.element.Vehicle_FOBModeC
#endif


/*********************************************************************************************
** Function Prototypes with Global Scope
*********************************************************************************************/

extern void PE10ms_MessageDebounce_Master(void);

 

#endif /*__MESSAGE_PROCESS_H*/
/*********************************************************************************************
** EOF
*********************************************************************************************/
