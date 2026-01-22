

/*********************************************************************************************
** Header Files
*********************************************************************************************/

#include "typedefs.h"
#include "os_timer.h"


/*********************************************************************************************
** Global Variables Definitions
*********************************************************************************************/

volatile tD_TickFlag TickFlag;	
uint16_t DecreaseTimer01ms[Timer_01ms];
uint16_t DecreaseTimer10ms[Timer_10ms];

/*********************************************************************************************
** Variables at File Scope
*********************************************************************************************/

uint16_t Counter_Tick = 0;
uint16_t Counter_1ms = 0;
uint16_t Counter_2ms = 0;
uint16_t Counter_5ms = 0;
uint16_t Counter_10ms_A = 0;			
uint16_t Counter_10ms_B = 0;
uint16_t Counter_10ms_C = 0;
uint16_t Counter_20ms = 0;		
uint16_t Counter_50ms = 0;		
uint16_t Counter_100ms = 0;		
uint16_t Counter_1s = 0;

/*********************************************************************************************
** Functions with Global Scope
*********************************************************************************************/

void Tick_Init(void);
void RTI_Function(void);

/*********************************************************************************************
** Name:	  Tick_Init
** Function:	  Tick_Init
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        Initialization, place in Kernal.c
*********************************************************************************************/
void Tick_Init(void)
{
   uint8_t loop = 0;

   /* Initialize all schedule vale */
    
    TickFlag.TF1ms = 0; 
    TickFlag.TF2ms = 0; 
    TickFlag.TF5ms = 0; 
    TickFlag.TF10msA = 0; 
    TickFlag.TF10msB = 0;  
    TickFlag.TF10msC = 0;   
    TickFlag.TF20ms = 0;   
    TickFlag.TF50ms = 0;   
    TickFlag.TF100ms = 0;  
    TickFlag.TF1s = 0;  

 /* Initialize all schedule value */
    
    Counter_Tick = 0;
    Counter_1ms = 0;
    Counter_2ms = 3;
    Counter_5ms = 7;
    Counter_10ms_A = 8;			
    Counter_10ms_B = 10;
    Counter_10ms_C = 14;
    Counter_20ms = 16;		
    Counter_50ms = 51;		
    Counter_100ms = 103;		
    Counter_1s = 999;
    
/* Initialize all application software counters */

    for(loop = 0; loop < Timer_01ms; loop++)
    {
      DecreaseTimer01ms[loop] = 0;
    }
    
    for(loop = 0; loop < Timer_10ms; loop++)
    {
      DecreaseTimer10ms[loop] = 0;
    }
}

/*********************************************************************************************
** Name:	  RTI_Function
** Function:	  RTI Interrupt Sevice Routine
** Scope:         Global
** Parameters:    void
** Return:	  void
** Remark:        Interrupt
*********************************************************************************************/
void RTI_Function(void)
{
   uint8_t loop = 0;
   
/* Decrease Timer 1ms */
   for(loop = 0; loop < Timer_10ms; loop++)
   {
      if(DecreaseTimer10ms[loop] > 0)
      {
    	 DecreaseTimer10ms[loop]--;
      }
   }

}

/*********************************************************************************************
** End of file
*********************************************************************************************/
