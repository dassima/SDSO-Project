#include <stdio.h>
#include "FreeRTOS.h"

/* The time between cycles of the 'check' functionality - as described at the
top of this file. */
#define mainNO_ERROR_PERIOD					( ( TickType_t ) 5000 / portTICK_PERIOD_MS )

/* The rate at which the LED controlled by the 'check' task will flash should an
error have been detected. */
#define mainERROR_PERIOD 					( ( TickType_t ) 500 / portTICK_PERIOD_MS )

/* The LED controlled by the 'check' task. */
#define mainCHECK_LED						( 3 )

/* ComTest constants - there is no free LED for the comtest tasks. */
#define mainCOM_TEST_BAUD_RATE				( ( unsigned long ) 19200 )
#define mainCOM_TEST_LED					( 5 )

/*
 * Configure the hardware for the demo.
 */
static void prvSetupHardware( void );

/*
 * Implements the 'check' task functionality as described at the top of this
 * file.
 */
static void prvCheckTask( void *pvParameters );

/*
 * Implement the 'Reg test' functionality as described at the top of this file.
 */
static void vRegTest1Task( void *pvParameters );
static void vRegTest2Task( void *pvParameters );

/*-----------------------------------------------------------*/

/* Counters used to detect errors within the reg test tasks. */
static volatile unsigned long ulRegTest1Counter = 0x11111111, ulRegTest2Counter = 0x22222222;

/*-----------------------------------------------------------*/

int main( void )
{

static void prvCheckTask( void *pvParameters )
{
unsigned ulTicksToWait = mainNO_ERROR_PERIOD, ulError = 0, ulLastRegTest1Count = 0, ulLastRegTest2Count = 0;
TickType_t xLastExecutionTime;

	( void ) pvParameters;

	/* Initialise the variable used to control our iteration rate prior to
	its first use. */
	xLastExecutionTime = xTaskGetTickCount();

	for( ;; )
	{
		/* Wait until it is time to run the tests again. */
		vTaskDelayUntil( &xLastExecutionTime, ulTicksToWait );

		/* Has an error been found in any task? */
		if( xAreGenericQueueTasksStillRunning() != pdTRUE )
		{
			ulError |= 0x01UL;
		}

		if( xAreQueuePeekTasksStillRunning() != pdTRUE )
		{
			ulError |= 0x02UL;
		}

		if( xAreBlockingQueuesStillRunning() != pdTRUE )
		{
			ulError |= 0x04UL;
		}

		if( xAreSemaphoreTasksStillRunning() != pdTRUE )
	    {
	    	ulError |= 0x20UL;
	    }

		if( xArePollingQueuesStillRunning() != pdTRUE )
	    {
	    	ulError |= 0x40UL;
	    }

		if( xIsCreateTaskStillRunning() != pdTRUE )
	    {
	    	ulError |= 0x80UL;
	    }

		if( xAreRecursiveMutexTasksStillRunning() != pdTRUE )
	    {
	    	ulError |= 0x200UL;
	    }

		if( ulLastRegTest1Count == ulRegTest1Counter )
		{
			ulError |= 0x1000UL;
		}

		if( ulLastRegTest2Count == ulRegTest2Counter )
		{
			ulError |= 0x1000UL;
		}

		ulLastRegTest1Count = ulRegTest1Counter;
		ulLastRegTest2Count = ulRegTest2Counter;

		/* If an error has been found then increase our cycle rate, and in so
		going increase the rate at which the check task LED toggles. */
		if( ulError != 0 )
		{
	    	ulTicksToWait = mainERROR_PERIOD;
		}

		/* Toggle the LED each iteration. */
		vParTestToggleLED( mainCHECK_LED );
	}
}
/*-----------------------------------------------------------*/

void prvSetupHardware( void )
{
	portDISABLE_INTERRUPTS();

	/* Setup the port used to toggle LEDs. */
	vParTestInitialise();
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t *pxTask, signed char *pcTaskName )
{
	/* This will get called if a stack overflow is detected during the context
	switch.  Set configCHECK_FOR_STACK_OVERFLOWS to 2 to also check for stack
	problems within nested interrupts, but only do this for debug purposes as
	it will increase the context switch time. */

	( void ) pxTask;
	( void ) pcTaskName;

	for( ;; )
	{
	}
}