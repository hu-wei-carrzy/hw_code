#ifndef I_DAT_PAN_CFG_H
#define I_DAT_PAN_CFG_H


#define cDATPanpAnaDIFilterPar         ((U8)6U)//总滤波次数，在ANACfg.xlsm表格中配置
#define cU8PanpDIStChgCounter           ((U8)4U)//6U次AD取值中连续4U次为高或为低则更改状态，在ANACfg.xlsm表格中配置
#define cDATPanpAnaDIUpperFactor         ((U8)10)
#define cDATPanpAnaDILowerFactor         ((U8)0)
#define cDATPanpAnaDIBorderValue         (((U8)(cDATPanpAnaDIFilterPar/2))*cDATPanpAnaDIUpperFactor)




#define cDATPanpAnaDICount             ((U8)0U)

#define mDATPanpAnaDIUpperLimitArray()           \
{}


#define mDATPanpAnaDILowerLimitArray()        \
{}


#define mDATPanpAnaDIPos()               \
{}




#endif

