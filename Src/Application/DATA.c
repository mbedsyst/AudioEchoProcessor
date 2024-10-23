#include "Application/DATA.h"

#include <stdlib.h>  // For malloc and free

void ReadDataFromFlash(uint16_t page, float32_t *data, uint16_t len)
{
    uint8_t *pcmData = (uint8_t *)malloc(len * 2);
    if (pcmData == NULL)
    {
        return;
    }

    W25Q_ReadData(page, 0, pcmData, len * 2);
    for (int i = 0; i < len; i++)
    {
    	uint16_t audioSample = (uint16_t)(pcmData[2 * i]) | ((uint16_t)(pcmData[2 * i + 1]) << 8);
        data[i] = (float32_t)(audioSample - 32768) / 32768.0f;
    }
    free(pcmData);
}


void WriteDataToFlash(uint16_t page, float32_t *data, uint16_t len)
{
    uint8_t *pcmData = (uint8_t *)malloc(len * 2);
    if (pcmData == NULL)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        uint16_t audioSample = (uint16_t)(data[i] * 65535.0f);
        if (audioSample > 65535)
            audioSample = 65535;
        if (audioSample < 0)
            audioSample = 0;
        pcmData[2 * i] = (uint8_t)(audioSample & 0xFF);
        pcmData[2 * i + 1] = (uint8_t)((audioSample >> 8) & 0xFF);
    }

    W25Q_WriteData(page, 0, pcmData, len * 2);
    free(pcmData);
}
