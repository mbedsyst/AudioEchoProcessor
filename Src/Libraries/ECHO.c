#include "Libraries/ECHO.h"

// Circular buffer for the delay
float32_t delayBuffer[DELAY_SAMPLES] = {0};
uint32_t delayIndex = 0;

void FPU_Enable(void)
{
	/*Enable Floating Point Unit : Enable CP10 and CP11 full access*/
	SCB->CPACR |= (0x0FU<<20);
}


void ApplyEcho(float32_t *input, float32_t *output, uint32_t blockSize)
{
    for (uint32_t i = 0; i < blockSize; i++)
    {
        // Get the delayed sample from the circular buffer
        float32_t delayedSample = delayBuffer[delayIndex];

        // Mix the delayed sample with the current input and store it in the output
        output[i] = input[i] + (FEEDBACK * delayedSample);

        // Update the circular buffer with the current input sample
        delayBuffer[delayIndex] = input[i];

        // Increment the delay index and wrap around if needed
        delayIndex++;
        if (delayIndex >= DELAY_SAMPLES)
        {
            delayIndex = 0;
        }
    }
}
