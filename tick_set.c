#include "FreeRTOS.h"
#include "task.h"

__declspec(interrupt:0) void vPIT0InterruptHandler( void );

// constants for interrupts.
#define portPRESCALE_VALUE			64
#define portPRESCALE_REG_SETTING	( 5 << 8 )
#define portPIT_INTERRUPT_ENABLED	( 0x08 )
#define configPIT0_INTERRUPT_VECTOR	( 55 )

void vApplicationSetupInterrupts( void )
{
const unsigned short usCompareMatchValue = ( ( configCPU_CLOCK_HZ / portPRESCALE_VALUE ) / configTICK_RATE_HZ );

    //config interrupt priority and level and unmask interrupt for PIT0
    UC_INTC0_ICR55 = ( 1 | ( configKERNEL_INTERRUPT_PRIORITY << 3 ) );
    UC_INTC0_IMRH &= ~( UC_INTC_IMRH_INT_MASK55 );

    //config PIT0 to generate the RTOS tick
    UC_PIT0_PCSR |= UC_PIT_PCSR_PIF;
    UC_PIT0_PCSR = ( portPRESCALE_REG_SETTING | UC_PIT_PCSR_PIE | UC_PIT_PCSR_RLD | UC_PIT_PCSR_EN );
	UC_PIT0_PMR = usCompareMatchValue;
}
 

__declspec(interrupt:0) void vPIT0InterruptHandler( void )
{
unsigned long ulSavedInterruptMask;

	//clear
	UC_PIT0_PCSR |= UC_PIT_PCSR_PIF;

	// ++tick
	ulSavedInterruptMask = portSET_INTERRUPT_MASK_FROM_ISR();
		if( xTaskIncrementTick() != pdFALSE )
		{
			taskYIELD();
		}
	portCLEAR_INTERRUPT_MASK_FROM_ISR( ulSavedInterruptMask );
}
