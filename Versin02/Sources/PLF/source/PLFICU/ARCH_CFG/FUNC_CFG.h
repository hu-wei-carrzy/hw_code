#ifndef FUNC_CFG_H
#define FUNC_CFG_H

//此文件用于配置各个功能禁止与打开，
//功能选择
//定义转速来源于硬线
//#define cCfg_SpdTacho_From_Hardware

///////////////////////////////////////////////////////////////////////////////
//是否使用直接数字输出（通过mSERControl方式实现的不归入此类）
//#define     cCfg_Diroutput

//是否使用59X
//#define     cCfg_SerialoutputByHC59X




#ifdef cCfg_SerialoutputByHC59X
#define cCfg_SimIOFor59X
#define cCfg_UARTFor59X
#endif

//对于ICU511，没有59X，也没有通过DAT_DOU_CFG.jil输出的内容，
//所以这里两个都不会出现。对于普通仪表，则至少要出现一个。
#if 0
#if defined(cCfg_UARTFor59X) && defined(cCfg_SimIOFor59X)
#error "You can not define the two macros at the same time,because there is only one driving way for HC59X"
#endif

#if !defined(cCfg_UARTFor59X) && !defined(cCfg_SimIOFor59X)
#error "You should define at least one of cCfg_UARTFor59X and cCfg_SimIOFor59X,which is used for driving HC59X"
#endif
#endif

/////////////////////////////////////////////////////////////////////////////////
#define GUI_ELECTROCAR   /*是否为新能源产品*/
#define BCM_TWO_CFG_EN  /*产品是否配置两个模块*/






#endif
