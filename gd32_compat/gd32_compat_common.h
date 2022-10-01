/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GD32_COMPAT_GD32_COMPAT_COMMON_H_
#define GD32_COMPAT_GD32_COMPAT_COMMON_H_

#include <stddef.h>
#include <stdint.h>

/* bit operations */
#define REG32(addr) (*(volatile uint32_t *)(uint32_t)(addr))
#define REG16(addr) (*(volatile uint16_t *)(uint32_t)(addr))
#define REG8(addr)  (*(volatile uint8_t *)(uint32_t)(addr))
#ifndef BIT
#define BIT(x) ((uint32_t)((uint32_t)0x01U << (x)))
#endif
#define BITS(start, end)                                                       \
	((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31U - (uint32_t)(end))))
#define GET_BITS(regval, start, end)                                           \
	(((regval)&BITS((start), (end))) >> (start))

#endif /* GD32_COMPAT_GD32_COMPAT_COMMON_H_ */
