/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GD32_COMPAT_GD32_USART_H_
#define GD32_COMPAT_GD32_USART_H_

#include <ch32_usart.h>
#include <gd32_compat_common.h>

#define USART_STAT0(usartx) REG32((usartx) + offsetof(USART_TypeDef, STATR))

/* USART flags */
#define USART_FLAG_RBNE	 USART_FLAG_RXNE
#define USART_FLAG_TBE	 USART_FLAG_TXE
#define USART_FLAG_ORERR USART_FLAG_ORE
#define USART_FLAG_NERR	 USART_FLAG_NE
#define USART_FLAG_FERR	 USART_FLAG_FE
#define USART_FLAG_PERR	 USART_FLAG_PE

/* USART_Interrupt_definition */
#define USART_INT_FLAG_PERR       USART_IT_PE
#define USART_INT_FLAG_TBE        USART_IT_TXE
#define USART_INT_FLAG_TC         USART_IT_TC
#define USART_INT_FLAG_RBNE       USART_IT_RXNE
#define USART_INT_FLAG_RBNE_ORERR USART_IT_ORE_RX
#define USART_INT_FLAG_IDLE       USART_IT_IDLE
#define USART_INT_FLAG_LBD        USART_IT_LBD
#define USART_INT_FLAG_CTS        USART_IT_CTS
#define USART_INT_FLAG_ERR        USART_IT_ERR
#define USART_INT_FLAG_ERR_ORERR  USART_IT_ORE_ER
#define USART_INT_FLAG_ERR_NERR   USART_IT_NE
#define USART_INT_FLAG_ERR_FERR   USART_IT_FE

/* USART interrupt enable or disable */
#define USART_INT_PERR       USART_IT_PE
#define USART_INT_TBE        USART_IT_TXE
#define USART_INT_TC         USART_IT_TC
#define USART_INT_RBNE       USART_IT_RXNE
#define USART_INT_IDLE       USART_IT_IDLE
#define USART_INT_LBD        USART_IT_LBD
#define USART_INT_CTS        USART_IT_CTS
#define USART_INT_ERR        USART_IT_ERR

/* USART receiver configure */
#define USART_RECEIVE_ENABLE  USART_Mode_Rx /*!< enable receiver */
#define USART_RECEIVE_DISABLE 0		    /*!< disable receiver */

/* USART transmitter configure */
#define USART_TRANSMIT_ENABLE  USART_Mode_Tx /*!< enable transmitter */
#define USART_TRANSMIT_DISABLE 0	     /*!< disable transmitter */

/* USART parity bits definitions */
#define USART_PM_NONE USART_Parity_No	/*!< no parity */
#define USART_PM_EVEN USART_Parity_Even /*!< even parity */
#define USART_PM_ODD  USART_Parity_Odd	/*!< odd parity */

/* USART wakeup method in mute mode */
#define USART_WM_IDLE USART_WakeUp_IdleLine    /*!< idle line */
#define USART_WM_ADDR USART_WakeUp_AddressMark /*!< address match */

/* USART word length definitions */
#define USART_WL_8BIT USART_WordLength_8b /*!< 8 bits */
#define USART_WL_9BIT USART_WordLength_9b /*!< 9 bits */

/* USART stop bits definitions */
#define USART_STB_1BIT	 USART_StopBits_1   /*!< 1 bit */
#define USART_STB_0_5BIT USART_StopBits_0_5 /*!< 0.5 bit */
#define USART_STB_2BIT	 USART_StopBits_2   /*!< 2 bits */
#define USART_STB_1_5BIT USART_StopBits_1_5 /*!< 1.5 bits */

/* USART LIN break frame length */
#define USART_LBLEN_10B USART_LINBreakDetectLength_10b /*!< 10 bits */
#define USART_LBLEN_11B USART_LINBreakDetectLength_11b /*!< 11 bits */

#define USART_CTL0_REN	USART_RECEIVE_ENABLE
#define USART_CTL0_TEN	USART_TRANSMIT_ENABLE
#define USART_CTL0_PCEN (USART_PM_EVEN | USART_PM_EVEN)
#define USART_CTL1_WL	USART_WL_9BIT
#define USART_CTL1_STB	(USART_STB_0_5BIT | USART_STB_2BIT | USART_STB_1_5BIT)

#define USART_WRITE_REG_MASK(reg, val, mask) ((reg) = ((reg) & ~(mask)) | (val))

/* configure USART baud rate value */
void usart_baudrate_set(uint32_t usart_periph, uint32_t baudval);
/* configure USART parity function */
static inline void usart_parity_config(uint32_t usart_periph, uint16_t paritycfg)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;

	USART_WRITE_REG_MASK(USARTx->CTLR1, paritycfg, USART_CTL0_PCEN);
}
/* configure USART word length */
static inline void usart_word_length_set(uint32_t usart_periph, uint16_t wlen)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;

	USART_WRITE_REG_MASK(USARTx->CTLR1, wlen, USART_CTL1_WL);
}
/* configure USART stop bit length */
static inline void usart_stop_bit_set(uint32_t usart_periph, uint16_t stblen)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;

	USART_WRITE_REG_MASK(USARTx->CTLR2, stblen, USART_CTL1_STB);
}

/* USART normal mode communication */
/* enable USART */
static inline void usart_enable(uint32_t usart_periph)
{
	USART_Cmd((USART_TypeDef *)usart_periph, ENABLE);
}
/* configure USART transmitter */
static inline void usart_transmit_config(uint32_t usart_periph, uint16_t txconfig)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;

	USART_WRITE_REG_MASK(USARTx->CTLR1, txconfig, USART_CTL0_REN);
}
/* configure USART receiver */
static inline void usart_receive_config(uint32_t usart_periph, uint16_t rxconfig)
{
	USART_TypeDef *USARTx = (USART_TypeDef *)usart_periph;

	USART_WRITE_REG_MASK(USARTx->CTLR1, rxconfig, USART_CTL0_TEN);
}
/* USART transmit data function */
static inline void usart_data_transmit(uint32_t usart_periph, uint16_t data)
{
	USART_SendData((USART_TypeDef *)usart_periph, data);
}
/* USART receive data function */
static inline uint16_t usart_data_receive(uint32_t usart_periph)
{
	return USART_ReceiveData((USART_TypeDef *)usart_periph);
}
/* flag functions */
/* get flag in STAT register */
static inline FlagStatus usart_flag_get(uint32_t usart_periph, uint32_t flag)
{
	return USART_GetFlagStatus((USART_TypeDef *)usart_periph, flag);
}
/* clear flag in STAT register */
static inline void usart_flag_clear(uint32_t usart_periph, uint32_t flag)
{
	USART_ClearFlag((USART_TypeDef *)usart_periph, flag);
}

/* interrupt functions */
/* enable USART interrupt */
static inline void usart_interrupt_enable(uint32_t usart_periph, uint32_t interrupt)
{
	USART_ITConfig((USART_TypeDef *)usart_periph, interrupt, ENABLE);
}
/* disable USART interrupt */
static inline void usart_interrupt_disable(uint32_t usart_periph, uint32_t interrupt)
{
	USART_ITConfig((USART_TypeDef *)usart_periph, interrupt, DISABLE);
}
/* get USART interrupt and flag status */
static inline ITStatus usart_interrupt_flag_get(uint32_t usart_periph, uint32_t int_flag)
{
	return USART_GetITStatus((USART_TypeDef *)usart_periph, int_flag);
}


#endif /* GD32_COMPAT_GD32_USART_H_ */
