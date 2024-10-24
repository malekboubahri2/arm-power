/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>

// Define the ITM base address
#define ITM_BASE_ADDR   (0xE0000000UL)

// Define the ITM Port structure (for ITM_STIMx registers)
typedef struct {
    volatile uint32_t STIM[256];  // ITM Stimulus Port registers (ITM_STIM0 to ITM_STIM255)
} ITM_TypeDef;

// Define the ITM registers using the correct addresses
#define ITM            ((ITM_TypeDef *)ITM_BASE_ADDR)
#define ITM_TCR        (*(volatile uint32_t *)(0xE0000E80UL))  // ITM Trace Control Register
#define ITM_TER        (*(volatile uint32_t *)(0xE0000E00UL))  // ITM Trace Enable Register

// Define the mask for enabling ITM
#define ITM_TCR_ITMENA_Msk   (0x00000001UL)  // ITM enable bit in TCR


// Function to send a character to ITM
uint32_t ITM_SendChar1(uint32_t ch) {
    // Check if ITM is enabled
    if ((ITM_TCR & ITM_TCR_ITMENA_Msk) != 0UL) {
        // Check if ITM Port #0 is enabled
        if ((ITM_TER & 1UL) != 0UL) {
            // Wait until the ITM Port #0 is ready
            while (ITM->STIM[0] == 0UL) {
//                __NOP(); // No Operation, allows other operations to proceed
            }
            // Write the character to ITM Port #0
            ITM->STIM[0] = ch;
        }
    }
    return ch;
}


// Function to redirect printf to ITM
int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        ITM_SendChar1(*ptr++);  // Send each character to the ITM port
    }
    return len;
}

/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	//enable IRQ3 interrupt
	*pISER0 |= ( 1 << 2);

	//generate an interrupt from software for IRQ3
	*pSTIR = (2 & 0x1FF);

}

void change_access_level_unpriv(void)
{

	//read
	__asm volatile ("MRS R0,CONTROL");
	//modify
	__asm volatile ("ORR R0,R0,#0x01");
	//write
	__asm volatile ("MSR CONTROL,R0");

}

/* This function executes in THREAD MODE of the processor */
int main(void)
{
	printf("In thread mode : before interrupt\n");

	generate_interrupt();

	change_access_level_unpriv();

	generate_interrupt();

	printf("In thread mode : after interrupt\n");

	for(;;);
}

/* This function(ISR) executes in HANDLER MODE of the processor */
void RTC_IRQHandler(void)
{
	printf("In handler mode : ISR\n");
}

void HardFault_Handler(void)
{
	printf("Hard fault detected\n");
	while(1);
}
