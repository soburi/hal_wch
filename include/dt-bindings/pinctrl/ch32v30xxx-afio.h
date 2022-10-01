/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CH32V30XXX_AFIO_H_
#define CH32V30XXX_AFIO_H_

#include "ch32-afio.h"

/** USART0 (no remap) */
#define CH32_USART0_NORMP	CH32_REMAP(0U, 2U, 0x1U, 0U)
/** USART0 (remap) */
#define CH32_USART0_RMP		CH32_REMAP(0U, 2U, 0x1U, 1U)

/** USART1 (no remap) */
#define CH32_USART1_NORMP	CH32_REMAP(0U, 3U, 0x1U, 0U)
/** USART1 (remap) */
#define CH32_USART1_RMP		CH32_REMAP(0U, 3U, 0x1U, 1U)

#endif /* CH32V30XXX_AFIO_H_ */
