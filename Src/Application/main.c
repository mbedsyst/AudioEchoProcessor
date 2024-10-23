#include "Application/main.h"

#define AUDIO_SIZE	2500000		// To Change

int main()
{
	float32_t AudioInput[128];
	float32_t AudioOutput[128];

	FPU_Enable();
	ConfigClock_84M();
	UART2_Init();
	LED_Init();

	for(uint32_t i= 0; i < AUDIO_SIZE; i++)
	{
		ReadDataFromFlash(i, AudioInput, 128);
		ApplyEcho(AudioInput, AudioOutput, 128);
		WriteDataToFlash(i, AudioOutput, 128);
	}

	while(1)
	{

	}
}

