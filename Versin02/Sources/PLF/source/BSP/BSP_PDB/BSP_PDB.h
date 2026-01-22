#ifndef BSP_AD_H_
#define BSP_AD_H_

void BSPPdbTriggerSoftware(PDB_Type * base);		/* 软件触发一次 */
void BSPPdbModuleInit(PDB_Type * base);					/* pdb初始化 */
void BSPPdbChnInit(PDB_Type * base, uint8_t chn);
void BSPPdbLoadValues(PDB_Type * base);
uint16_t BSPPdb0GetErrStatus(void);
uint16_t BSPPdb1GetErrStatus(void);
uint8_t BSPPdb0GetIfStatus(void);
uint8_t BSPPdb1GetIfStatus(void);
#endif
