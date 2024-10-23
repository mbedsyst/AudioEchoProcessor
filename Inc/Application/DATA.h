#ifndef DATA_H_
#define DATA_H_

#include "arm_math.h"
#include "Libraries/W25Qxx.h"

void ReadDataFromFlash(uint16_t page, float32_t *data, uint16_t len);
void WriteDataToFlash(uint16_t page, float32_t *data, uint16_t len);

#endif /* DATA_H_ */
