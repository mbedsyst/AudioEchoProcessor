#ifndef ECHO_H_
#define ECHO_H_

#include "stm32f4xx.h"
#include "arm_math.h"

#define SAMPLE_RATE 	16000
#define DELAY_MS 		100
#define BUFFER_SIZE 	128
#define FEEDBACK 		0.5f

#define DELAY_SAMPLES (SAMPLE_RATE * DELAY_MS / 1000)

void FPU_Enable(void);
void ApplyEcho(float32_t *input, float32_t *output, uint32_t blockSize);

#endif
