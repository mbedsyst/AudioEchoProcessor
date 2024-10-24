#include "Application/ECHO.h"

// Circular buffer for the delay
float32_t delayBuffer[DELAY_SAMPLES] = {0};
uint32_t delayIndex = 0;

static void FPU_Enable(void)
{
	/*Enable Floating Point Unit : Enable CP10 and CP11 full access*/
	SCB->CPACR |= (0x0FU<<20);
}

void Processor_Init(void)
{
	ConfigClock_84M();
	FPU_Enable();
	W25Q_Init();
	UART2_Init();
	LED_Init();
}

void ApplyEcho(float32_t *input, float32_t *output, uint32_t blockSize)
{
	for (uint32_t i = 0; i < blockSize; i++)
	{
		float32_t delayedSample = delayBuffer[delayIndex];
		output[i] = input[i] + (FEEDBACK * delayedSample);
		delayBuffer[delayIndex] = input[i];

		delayIndex++;
		if (delayIndex >= DELAY_SAMPLES)
		{
			delayIndex = 0;
		}
	}
}


