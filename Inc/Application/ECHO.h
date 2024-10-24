#ifndef ECHO_H_
#define ECHO_H_

#include "stm32f4xx.h"
#include "arm_math.h"
#include "Drivers/LED.h"
#include "Drivers/CLOCK.h"
#include "Drivers/UART.h"
#include "Libraries/W25Qxx.h"

#define SAMPLE_RATE 	16000
#define DELAY_MS 		300
#define BUFFER_SIZE 	128
#define FEEDBACK 		0.7f

#define DELAY_SAMPLES (SAMPLE_RATE * DELAY_MS / 1000)

void Processor_Init(void);
void ApplyEcho(float32_t *input, float32_t *output, uint32_t blockSize);

#endif
