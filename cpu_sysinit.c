//reset config
#include "common.h"

void uc_init(void);
void uc_watchdog_init(void);
void uc_pll_init(void);
void uc_uart_init(void);
void uc_scm_init(void);
void uc_gpio_init(void);

void
uc_init(void)
{
	register uint32 n;
	register uint8 *dp, *sp;
       
    // enable interrupt on interrupt controller
    UC_INTC0_IMRL &= ~(0| UC_INTC_IMRL_INT_MASK1| UC_INTC_IMRL_INT_MASK2| UC_INTC_IMRL_INT_MASK5 
                        | UC_INTC_IMRL_INT_MASK6| UC_INTC_IMRL_INT_MASK7| UC_INTC_IMRL_MASKALL);

  	// debug enable
	UC_GPIO_PDDPAR = 0x0F;
	
	//set time
	UC_CLOCK_RTCCR = 48000000;

	uc_watchdog_init();
	uc_pll_init();
	uc_scm_init();
	uc_uart_init();
}

void
uc_watchdog_init(void)
{
	UC_SCM_CWCR = 0;
}
void
uc_pll_init(void)
{
	//when booting with internal crystal from PLL
#ifndef OMIT_OCLR_CONFIG
	UC_CLOCK_OCLR = 0xC0;   //turn on crystal
	UC_CLOCK_CCLR = 0x00;    //switch to crystal 
#endif

	//PLL pre divider - 48MHz / 6 = 8MHz
	UC_CLOCK_CCHR =0x05;
	 	 
	//remember multiply 48Mhz reference crystal /CCHR by 10 to acheive system clock of 80Mhz
	UC_CLOCK_SYNCR &= ~(UC_CLOCK_SYNCR_PLLEN);
    UC_CLOCK_SYNCR |= UC_CLOCK_SYNCR_CLKSRC | UC_CLOCK_SYNCR_PLLMODE;
	
	//80
	UC_CLOCK_SYNCR |= UC_CLOCK_SYNCR_MFD(3) | UC_CLOCK_SYNCR_RFD(0);
	UC_CLOCK_SYNCR |= UC_CLOCK_SYNCR_PLLEN;

	
	while (!(UC_CLOCK_SYNSR & UC_CLOCK_SYNSR_LOCK))
	{
	}
}

void
uc_uart_init(void)
{
	//init uart 

	// reset transmitter
	UC_UART0_UCR = UC_UART_UCR_RESET_TX;
	UC_UART1_UCR = UC_UART_UCR_RESET_TX;
	UC_UART2_UCR = UC_UART_UCR_RESET_TX;

	// reset receiver
	UC_UART0_UCR = UC_UART_UCR_RESET_RX;
	UC_UART1_UCR = UC_UART_UCR_RESET_RX;
	UC_UART2_UCR = UC_UART_UCR_RESET_RX;

	// reset mode register
	UC_UART0_UCR = UC_UART_UCR_RESET_MR;
	UC_UART1_UCR = UC_UART_UCR_RESET_MR;
	UC_UART2_UCR = UC_UART_UCR_RESET_MR;

	//enable receiver and transmitter
	UC_UART0_UCR = (0| UC_UART_UCR_TX_ENABLED| UC_UART_UCR_RX_ENABLED);
	UC_UART1_UCR = (0| UC_UART_UCR_TX_ENABLED| UC_UART_UCR_RX_ENABLED);
	UC_UART2_UCR = (0| UC_UART_UCR_TX_ENABLED| UC_UART_UCR_RX_ENABLED);

}
