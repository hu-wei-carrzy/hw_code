#include "BSP_RST.h"


uint32_t BSPRstGetResetCause(void)
{

    return 0;
}


void BSPRstRriggerSWReset(void)
{
	SystemSoftwareReset();
}


