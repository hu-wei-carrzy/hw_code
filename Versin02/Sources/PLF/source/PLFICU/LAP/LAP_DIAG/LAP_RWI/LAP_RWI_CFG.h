#ifndef I_LAP_RWI_CFG_H
#define I_LAP_RWI_CFG_H

//2017年11月23日 15:29:45
//zjb
//添加此文件，用于定义数据有效范围

//位掩码，
#define cU8MaskPos0                  ((U8)0x01)
#define cU8MaskPos1                  ((U8)0x04)
#define cU8MaskPos2                  ((U8)0x10)
#define cU8MaskPos4                  ((U8)0x40)

//音量
#define cU8VolumDegLng      ((U8)0x01)
#define cU8VolumDegVUpper   ((U8)0X05)
#define cU8VolumDegVLower   ((U8)0X01)

//能耗计算单位
//1表示100米
#define cU8EngCsmDistLng      ((U8)0x01)
#define cU8EngCsmDistVUpper   ((U8)0X0A)
#define cU8EngCsmDistVLower   ((U8)0X01)


//时间调整模式：0自动，1手动
#define cU8TimAdjModLng   ((U8)0x01)
#define cU8TimAdjModVUpper   ((U8)0X01)
#define cU8TimAdjModVLower   ((U8)0X00)


//15=b00_01_01_01，3个1分别表示3个有效果的交换位置
#define cU8MaskForUserPrefSet  ((U8)21U)



//操作提醒
//0：关闭，1：打开
#define cU8OpTipLng   ((U8)0x01)
#define cU8OpTipVUpper   ((U8)0X01)
#define cU8OpTipVLower   ((U8)0X00)

//语言
//0:中文化
//1：英语
//2：西班牙
#define cU8LangLng   ((U8)0x01)	
#define cU8LangVUpper   ((U8)0X02)	
#define cU8LangVLower   ((U8)0X00)	

//背光调整模式
//0:自动
//1:手动
#define cU8LightAdjModLng   ((U8)0x01)
#define cU8LightAdjModVUpper   ((U8)0X01)
#define cU8LightAdjModVLower   ((U8)0X00)

//主题颜色
//只有3个颜色，0，1，2
#define cU8ThemeClrLng   ((U8)0x01)
#define cU8ThemeClrVUpper   ((U8)0X02)
#define cU8ThemeClrVLower   ((U8)0X00)

//车辆类型
//在功能上车辆类型，0：纯电动，1：燃油，2：混合动力，3：燃料电池，其它无效
#define cU8FunVehTypeLng   ((U8)0x01)
#define cU8FunVehTypeVUpper   ((U8)0X03)
#define cU8FunVehTypeVLower   ((U8)0X00)


//门的数量
//有效值0~5，
//表示对应门数量1~6
#define cU8DoorNumLng   ((U8)0x01)
#define cU8DoorNumVUpper   ((U8)0X05)
#define cU8DoorNumVLower   ((U8)0X00)


//车辆类型，用于在屏幕中间显示
//0：公交，1：客运
#define cU8ShowVehTypeLng   ((U8)0x01)
#define cU8ShowVehTypeVUpper   ((U8)0X01)
#define cU8ShowVehTypeVLower   ((U8)0X00)

//雾灯辅助照明
//0:关闭，1：打开
#define cU8FogAstLightLng   ((U8)0x01)
#define cU8FogAstLightVUpper   ((U8)0X01)
#define cU8FogAstLightVLower   ((U8)0X00)


//85=b01_01_01_01，3个1分别表示3个有效果的交换位置
#define cU8MaskForVideoCfg           ((U8)0x55U)

//刹车类型，
//0：油刹
//1：气刹
#define cU8BrakeTypeLng   ((U8)0x01)
#define cU8BrakeTypeVUpper   ((U8)0X01)
#define cU8BrakeTypeVLower   ((U8)0X00)



#endif