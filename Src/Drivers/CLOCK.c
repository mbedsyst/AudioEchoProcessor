#include "Drivers/CLOCK.h"

/*
 * System clock source =  HSE
 * SYSCLK			   =  100MHz
 * HCLK				   =  100MHz
 * AHB Prescaler	   =  1
 * APB1 Prescaler      =  2
 * APB2 Prescaler      =  1
 * HSE				   =  8MHz
 */

#define PLL_M	4
#define PLL_N	84
#define PLL_P	4
#define PLL_Q	9

void ConfigClock_84M(void)
{
	// Configures flash latency.
	MODIFY_REG(FLASH->ACR,
		FLASH_ACR_LATENCY,
		_VAL2FLD(FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_2WS) //FLASH_ACR_LATENCY_2WS << FLASH_ACR_LATENCY_Pos
	);

	// Enables HSE.
	SET_BIT(RCC->CR, RCC_CR_HSEON);

	// Waits until HSE is stable.
	while (!READ_BIT(RCC->CR, RCC_CR_HSERDY));

	// Configures PLL: source = HSE, PLLCLK = 72MHz.
	MODIFY_REG(RCC->PLLCFGR,
		RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLP,
		_VAL2FLD(RCC_PLLCFGR_PLLM, 4) | _VAL2FLD(RCC_PLLCFGR_PLLN, 84) | _VAL2FLD(RCC_PLLCFGR_PLLQ, 3) | RCC_PLLCFGR_PLLSRC_HSE
	);

	// Enables PLL module.
	SET_BIT(RCC->CR, RCC_CR_PLLON);

	// Waits until PLL is stable.
	while (!READ_BIT(RCC->CR, RCC_CR_PLLRDY));

	// Switches system clock to PLL.
	MODIFY_REG(RCC->CFGR,
		RCC_CFGR_SW,
		_VAL2FLD(RCC_CFGR_SW, RCC_CFGR_SW_PLL)
	);

	// Configures PPRE1 = 2, (PPRE2 = 1, HPRE = 1 by default).
	MODIFY_REG(RCC->CFGR,
		RCC_CFGR_PPRE1,
		_VAL2FLD(RCC_CFGR_PPRE1, 4)
	);

	// Waits until PLL is used.
	while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

	// Disables HSI.
	CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

void delay_ms(uint32_t ms)
{
	uint32_t i;

	SysTick->CTRL |= (1<<0) | (1<<2) ;
	SysTick->LOAD  = (84000000/1000) - 1;
	for(i=0; i<ms; i++)
	{
		while(!(SysTick->CTRL & (1<<16)));
	}
	SysTick->CTRL &=~(1U<<0) ;
}
