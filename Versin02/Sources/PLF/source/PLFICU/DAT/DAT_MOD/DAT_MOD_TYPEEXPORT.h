#ifndef I_DAT_MOD_EXPORTTYPE_H
#define I_DAT_MOD_EXPORTTYPE_H



//------------------------------------------------------------------------------
// Constant data
//
// #define cu16LAYCmpConstantName   ((U16) ConstantValueUL)
//------------------------------------------------------------------------------

enum
{
	eSysMod_Run				,/* 正常工作  */
	eSysMod_Sleep			,/* 休眠	*/
	eSysMod_Reset			,/* 复位	*/
	eSysMod_Study			,/* 学习模式	*/
	cSysMod_Diag			,/* 诊断	*/
	cSysMod_Max
};


#endif
