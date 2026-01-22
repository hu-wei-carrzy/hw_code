

#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

/*********************************************************************************************
** File Definition
*********************************************************************************************/


typedef unsigned char  BOOL;
//typedef unsigned char  bool;
typedef signed char    schar;

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

//typedef signed int int32_t;
//typedef unsigned int uint32_t;
typedef volatile signed int vint32_t;
typedef volatile unsigned int vuint32_t;

#define success        ((int8_t)1)
#define failure        ((int8_t)-1)
#define pending        ((int8_t)0)

#define TRUE  1
#define FALSE 0

#define OUTPUT 1
#define INPUT 0

#define ENABLE 	1
#define DISABLE 0

#define RISING_EDGE  1
#define FALLING_EDGE 0

#define PASS 0
#define FAIL 0xFF

#define ON   1
#define OFF  0

#define SET   1
#define RESET 0

#define INVALID  0
#define VALID 1

#define NULL            ((void *)0)

#endif /*__TYPEDEFS_H */

/*********************************************************************************************
** EOF
*********************************************************************************************/
