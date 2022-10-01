/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ch32v30x_rcc.h>
#include <gd32_usart.h>

/* USART OverSampling-8 Mask */
#define CTLR1_OVER8_Set ((uint16_t)0x8000) /* USART OVER8 mode Enable Mask */
#define CTLR1_OVER8_Reset                                                      \
	((uint16_t)0x7FFF) /* USART OVER8 mode Disable Mask                    \
			    */

void usart_baudrate_set(uint32_t usart_periph, uint32_t baudval)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;
	RCC_ClocksTypeDef RCC_ClocksStatus;
	uint32_t fractionaldivider;
	uint32_t integerdivider;
	uint32_t apbclock;
	uint32_t tmpreg;

	RCC_GetClocksFreq(&RCC_ClocksStatus);

	if (usart_periph == USART1_BASE) {
		apbclock = RCC_ClocksStatus.PCLK2_Frequency;
	} else {
		apbclock = RCC_ClocksStatus.PCLK1_Frequency;
	}

	if ((USARTx->CTLR1 & CTLR1_OVER8_Set) != 0) {
		integerdivider = ((25 * apbclock) / (2 * baudval));
	} else {
		integerdivider = ((25 * apbclock) / (4 * baudval));
	}
	tmpreg = (integerdivider / 100) << 4;

	fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

	if ((USARTx->CTLR1 & CTLR1_OVER8_Set) != 0) {
		tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) &
			  ((uint8_t)0x07);
	} else {
		tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) &
			  ((uint8_t)0x0F);
	}

	USARTx->BRR = (uint16_t)tmpreg;
}
