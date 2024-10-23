#include "Drivers/UART.h"

#define UART_BAUDRATE	115200
#define SYS_FREQ		84000000
#define APB1_CLK		SYS_FREQ/2

static void UART2_SetBaudRate(uint32_t periph_clk, uint32_t baudrate);

void UART2_Write(int ch);

int __io_putchar(int ch)
{
	UART2_Write(ch);
	return ch;
}

void UART2_Init(void)
{
	/*****Configure UART GPIO Pin******/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/*Set PA2 mode to alternate function mode */
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |=(1U<<5);
	/*Set PA2 alternate function type to UART_TX(AF07)*/
	GPIOA->AFR[0] |=(1U<<8);
	GPIOA->AFR[0] |=(1U<<9);
	GPIOA->AFR[0] |=(1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);

	/*****Configure UART  ******/
	/*Enable clock access to UART2*/
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	/*Configure Baud Rate*/
	UART2_SetBaudRate(APB1_CLK,UART_BAUDRATE);
	/*Configure the transfer direction*/
	USART2->CR1 = USART_CR1_TE;
	/*Enable UART module*/
	USART2->CR1 |= USART_CR1_UE;
}

void UART2_Write(int ch)
{
	/*Make sure transmit data register is empty*/
	   while(!(USART2->SR & USART_SR_TXE))
	   {}
	/*Write to the transmit data register*/
	   USART2->DR = (ch &0xFF);
}

static uint16_t Compute_UART_Baud( uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
}

static void UART2_SetBaudRate(uint32_t periph_clk, uint32_t baudrate)
{
	USART2->BRR = Compute_UART_Baud(periph_clk,baudrate);
}

