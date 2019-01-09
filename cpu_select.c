#include "common.h"

//make pauses for specific time
void
cpu_pause(int usecs)
{
    //enable dma timer3
    UC_DTIM3_DTRR = (vuint32)(usecs - 1);
    UC_DTIM3_DTER = UC_DTIM_DTER_REF;
    UC_DTIM3_DTMR = 0
        | UC_DTIM_DTMR_PS(SYSTEM_CLOCK)
        | UC_DTIM_DTMR_FRR
        | UC_DTIM_DTMR_CLK_DIV1
        | UC_DTIM_DTMR_RST;

    while ((UC_DTIM3_DTER & UC_DTIM_DTER_REF) == 0) 
    {};
    
    //disable
    UC_DTIM3_DTMR = 0;
}
void
board_handle_interrupt (int vector)
{
    switch (vector)
    {
        case 65: //interrupt 1
            UC_EPORT_EPFR = UC_EPORT_EPFR_EPF1;
            break;
        case 69: //interrupt 5
            UC_EPORT_EPFR = UC_EPORT_EPFR_EPF5;
            break;
        case 71: //interrupt 7
            UC_EPORT_EPFR = UC_EPORT_EPFR_EPF7;
            break;
        case 66: //interrupt 2
        case 67: //interrupt 3
        case 68: //interrupt 4
        case 70://interrupt 6
        default:
            UC_EPORT_EPFR = (uint8)(0x01 << (vector - 64));
            break;
    }
}
void
cpu_handle_interrupt (int vector)
{
    if (vector < 64 || vector > 192)
        return;
    
    if (vector >= 64 && vector <= 71)
        board_handle_interrupt(vector);
    else
        printf("User Defined Vector #%d\n",vector);
}
