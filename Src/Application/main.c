#include "Application/main.h"

#define AUDIO_FILE_SIZE		(960512)	// File size in Kilobytes
#define AUDIO_SIZE			(AUDIO_FILE_SIZE/W25Q_PageSize)

int main()
{
	float32_t AudioInput[128];
	float32_t AudioOutput[128];

	Processor_Init();

	for(uint32_t i= 0; i < AUDIO_SIZE; i++)
	{
		LED_Toggle();
		ReadDataFromFlash(i, AudioInput, 128);
		ApplyEcho(AudioInput, AudioOutput, 128);
		WriteDataToFlash(i, AudioOutput, 128);
		LED_Toggle();
	}

	while(1);
}

