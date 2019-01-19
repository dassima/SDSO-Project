# SDSO-Project
This is a project for university class.

It creates tasks before starting the RTOS scheduler (including the idle task), then repeatedly dynamically creates and deletes a further two tasks when the RTOS kernel is running.
It is configured with the RTOS kernel using interrupt priority 1 and the UART using interrupt priority 3 so UART interrupts can nest within kernel interrupts.
The RTOS kernel uses the PIT0 timer to generate the RTOS tick.
