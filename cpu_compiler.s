#define cpu_exception_handler   _cpu_exception_handler

    .extern uc_exception_handler

    .global asm_exception_handler
    .global _asm_exception_handler
    .global asm_set_ipl
    .global _asm_set_ipl
    .global uc_exe_wdebug
    .global _uc_exe_wdebug
   .global uc_move_line   
   .global _uc_move_line   

    .text

/*low-level exception handler.*/
 
asm_exception_handler:
_asm_exception_handler:
    lea     -16(SP),SP
    movem.l D0-D1/A0-A1,(SP)
    lea     16(SP),A1
    move.l  A1,-(SP)
    jsr     uc_exception_handler
    lea     4(SP),SP
    movem.l (SP),D0-D1/A0-A1
    lea     16(SP),SP
    rte

/********************************************************************/
    .end
