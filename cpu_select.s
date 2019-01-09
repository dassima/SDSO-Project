#define uc_init   _uc_init
#define common_startup  _common_startup
#define cpu_startup     _cpu_startup
#define main	    	_main
#define __SRAM          ___SRAM     
#define __FLASH         ___FLASH    
#define __SP_INIT       ___SP_INIT  
 
	.extern __SRAM
	.extern __FLASH
	.extern __SP_INIT
	.extern uc_init
    .extern common_startup
    .extern cpu_startup
	.extern main

	.global asm_startmeup
	.global _asm_startmeup
	.global d0_reset
	.global _d0_reset
	.global d1_reset
	.global _d1_reset

    .data
    
d0_reset:
_d0_reset:  .long   0
d1_reset:
_d1_reset:  .long   0

	.text

/*hardware reset -  memory setup - system initialized*/
asm_startmeup:
_asm_startmeup:

    move.w	#0x2700,sr
    
    /* Initialize RAMBAR1: locate SRAM and validate it */
	move.l	#__SRAM,d0
	andi.l	#0xFFFF0000,d0
    add.l   #0x21,d0
    movec   d0,RAMBAR1

	/* Locate Stack Pointer */ 
	move.l	#__SP_INIT,sp
	
    /* Initialize FLASHBAR */
    move.l  #__FLASH,d0
    cmp.l   #0x00000000,d0
    bne     change_flashbar
    add.l   #0x61,d0
    movec   d0,RAMBAR0

_continue_startup:

	/* Initialize the system */
	jsr		uc_init

    /* Common startup code */
    //jsr     common_startup
    
    /* CPU specific startup code */
	//jsr     cpu_startup

	/* Jump to the main process */
	jsr		main
	
	bra		.
	nop
	nop
	halt

	.end
