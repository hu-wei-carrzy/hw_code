/*
** ###################################################################
**     Processor:           S32K144 with 28+32 KB SRAM
**     Compiler:            GNU C Compiler
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright (c) 2015-2016 Freescale Semiconductor, Inc.
**     Copyright 2017 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
** ###################################################################
*/

/* Entry Point */
ENTRY(Reset_Handler)

HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00000400;
STACK_SIZE = DEFINED(__stack_size__) ? __stack_size__ : 0x00002000;

/* If symbol __flash_vector_table__=1 is defined at link time
 * the interrupt vector will not be copied to RAM.
 * Warning: Using the interrupt vector from Flash will not allow
 * INT_SYS_InstallHandler because the section is Read Only.
 */
M_VECTOR_RAM_SIZE = DEFINED(__flash_vector_table__) ? 0x0 : 0x0400;

/* Specify the memory areas */
MEMORY
{
  /*
    S32K144的Flash是512KB，FlexNVM不准备使用。512KB可以这样划分。
    其中要考虑到Flash的基本操作单元。
  按照顺序细分：中断向量表1KB-->FlashFlag16字节-->Loader(120K-1K-16B)
  -->AppHeader(128B)-->APP_interrupts(1K)-->App_Body(512K-之前的大小)，

  另外，在App的开头区域，留下128个字节做为信息区，依次存储：
 App有效性标志8字节，版本号16字节，校验和信息：4*3字节，其它说明信息128-8-16-12=92字节。

  另外，注意一点：要将应用程序有效性标志位写在App的最后地址处。这样
  最大程度上可以保证完整性。

  芯片手册803页提到，512KB共细分为32个部分，可分别保护。则一个基本单位是16KB。
  可以考虑将最后的64KB留给Loader，其它的都给应用。
   */

	  /* Flash */
	  m_interrupts            	(RX)  : ORIGIN = 0x00000000, LENGTH = 0x00000400 
      m_flash_config           (RX)  : ORIGIN = 0x00000400, LENGTH = 0x00000010
	  Loader_Flash           	(RX)  : ORIGIN = 0x00000410, LENGTH = 0x0001E000-0x00000410 
	  
	  /*  特别注意：0x1E000开始的16个字节是不能用的，它是留给Loader来写的，所以这 里不能使用 */
	  App_Header_Flash      (RX)  : ORIGIN = 0x0001E000 + 0x10, LENGTH = 128 - 0x10
	  APP_interrupts			(RX)  : ORIGIN = 0x0001E080, LENGTH = 0x00000400   
	  App_Body_Flash       	(RX)  : ORIGIN = 0x0001E480, LENGTH = 0x00080000 - 0x0001E480  

  /*
    S32K144共有3个内存区域：SRAM_L,SRAM_U,FlexRAM(本项目中不使用).
    SRAM_L和SRAM_U是以0X2000_0000为分界线的。其中SRAM_L大小是32KB，
    SRAM_U是28KB。这时将其分为三个部分：RAM_1(32K)，RAM_2(28KB-1KB), InterRAM(1KB).
    InterRAM是用于App和Loader进行交互的
   */
  
  /* SRAM_L */
  RAM_1             (RW)  : ORIGIN = 0x1FFF8000, LENGTH = 0x00008000

  /* SRAM_U */
  RAM_2             (RW)  : ORIGIN = 0x20000000, LENGTH = 0x00007000 - 0x00000400
  InterRAM              (RW)  : ORIGIN = 0x20006C00, LENGTH = 0x00000400
}

/* Define output sections */
SECTIONS
{
  /* The startup code goes first into internal flash */
  .interrupts :
  {
    __VECTOR_TABLE = .;
    . = ALIGN(4);
    KEEP(*(.isr_vector))     /* Startup code */
    . = ALIGN(4);
  } > m_interrupts
  
 
    .interrupts_App :
  {
    __VECTOR_TABLE = .;
    . = ALIGN(4);
    KEEP(*(.isr_vector_App))     /* Startup code */
    . = ALIGN(4);
  } > APP_interrupts
  
  
  
  .flash_config :
  {
    . = ALIGN(4);
    KEEP(*(.FlashConfig))    /* Flash Configuration Field (FCF) */
    . = ALIGN(4);
  } > m_flash_config


  .App_Info :
  {
  	. = ALIGN(4);
  	KEEP(*(.Sec_App_Header))
  } > App_Header_Flash


  /* The program code and other data goes into internal flash */
  .text :
  {
    . = ALIGN(4);

    *(.text)                 /* .text sections (code) */
    *(.text*)                /* .text* sections (code) */
    *(.rodata)               /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)              /* .rodata* sections (constants, strings, etc.) */
    *(.glue_7)               /* glue arm to thumb code */
    *(.glue_7t)              /* glue thumb to arm code */
    *(.eh_frame)
    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
  } > App_Body_Flash

	

  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > App_Body_Flash

  .ARM :
  {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } > App_Body_Flash

 .ctors :
  {
    __CTOR_LIST__ = .;
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       from the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    __CTOR_END__ = .;
  } > App_Body_Flash

  .dtors :
  {
    __DTOR_LIST__ = .;
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    __DTOR_END__ = .;
  } > App_Body_Flash

  .preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > App_Body_Flash

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > App_Body_Flash

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > App_Body_Flash

  __etext = .;    /* Define a global symbol at end of code. */
  __DATA_ROM = .; /* Symbol is used by startup for data initialization. */
  .interrupts_ram :
  {
    . = ALIGN(4);
    __VECTOR_RAM__ = .;
    __interrupts_ram_start__ = .; /* Create a global symbol at data start. */
    *(.m_interrupts_ram)          /* This is a user defined section. */
    . += M_VECTOR_RAM_SIZE;
    . = ALIGN(4);
    __interrupts_ram_end__ = .;   /* Define a global symbol at data end. */
  } > RAM_1

  __VECTOR_RAM = DEFINED(__flash_vector_table__) ? ORIGIN(m_interrupts) : __VECTOR_RAM__ ;
  
  __RAM_VECTOR_TABLE_SIZE = DEFINED(__flash_vector_table__) ? 0x0 : (__interrupts_ram_end__ - __interrupts_ram_start__) ;

  .data : AT(__DATA_ROM)
  {
    . = ALIGN(4);
    __DATA_RAM = .;
    __data_start__ = .;      /* Create a global symbol at data start. */
    *(.data)                 /* .data sections */
    *(.data*)                /* .data* sections */
    KEEP(*(.jcr*))
    . = ALIGN(4);
    __data_end__ = .;        /* Define a global symbol at data end. */
  } > RAM_1

  __DATA_END = __DATA_ROM + (__data_end__ - __data_start__);
  __CODE_ROM = __DATA_END; /* Symbol is used by code initialization. */
  .code : AT(__CODE_ROM)
  {
    . = ALIGN(4);
    __CODE_RAM = .;
    __code_start__ = .;      /* Create a global symbol at code start. */
    *(.code_ram)             /* Custom section for storing code in RAM */
    . = ALIGN(4);
    __code_end__ = .;        /* Define a global symbol at code end. */
  } > RAM_1

  __CODE_END = __CODE_ROM + (__code_end__ - __code_start__);
  __CUSTOM_ROM = __CODE_END;

  /* Custom Section Block that can be used to place data at absolute address. */
  /* Use __attribute__((section (".customSection"))) to place data here. */
  .customSectionBlock  ORIGIN(RAM_2) :
  {
    __customSection_start__ = .;
    KEEP(*(.customSection))  /* Keep section even if not referenced. */
    __customSection_end__ = .;
  } > RAM_2
  __CUSTOM_END = __CUSTOM_ROM + (__customSection_end__ - __customSection_start__);

  /* Uninitialized data section. */
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section. */
    . = ALIGN(4);
    __BSS_START = .;
    __bss_start__ = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    __bss_end__ = .;
    __BSS_END = .;
  } > RAM_2
  
  
   .InterRAM_config :
  {
   . = ALIGN(4);
   _RAM_INTER_START = .;
   _ram_inter_start_ = .;
   *(.InterRAM_config)
   *(.InterRAM_config*)
   *(COMMON)
    . = ALIGN(4);  
   _RAM_INTER_END = .;
   _ram_inter_end_ = .;
  } > InterRAM   /* 将该RAM区域置零。暂时没找到好办法，先以这种方式实现。 20190225 jy 
                          20190225 赵工讲解完后按照bss段的方式，将InterRAM初始化置0,。
    */

  .heap :
  {
    . = ALIGN(8);
    __end__ = .;
    PROVIDE(end = .);
    PROVIDE(_end = .);
    PROVIDE(__end = .);
    __HeapBase = .;
    . += HEAP_SIZE;
    __HeapLimit = .;
    __heap_limit = .;
  } > RAM_2

  .stack :
  {
    . = ALIGN(8);
    . += STACK_SIZE;
  } > RAM_2

  /* Initializes stack on the end of block */
  __StackTop   = ORIGIN(RAM_2) + LENGTH(RAM_2);
  __StackLimit = __StackTop - STACK_SIZE;
  PROVIDE(__stack = __StackTop);

  .ARM.attributes 0 : { *(.ARM.attributes) }

  ASSERT(__StackLimit >= __HeapLimit, "region RAM_2 overflowed with stack and heap")
}

