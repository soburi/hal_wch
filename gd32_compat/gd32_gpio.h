/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GD32_COMPAT_GD32_GPIO_H_
#define GD32_COMPAT_GD32_GPIO_H_

#include <ch32_gpio.h>
#include <gd32_compat_common.h>

#undef GPIOA
#define GPIOA GPIOA_BASE
#undef GPIOB
#define GPIOB GPIOB_BASE
#undef GPIOC
#define GPIOC GPIOC_BASE
#undef GPIOD
#define GPIOD GPIOD_BASE
#undef GPIOE
#define GPIOE GPIOE_BASE
#undef GPIOF
#define GPIOF GPIOF_BASE
#undef GPIOG
#define GPIOG GPIOG_BASE

/* GPIO registers definitions */
#define GPIO_CTL0(gpiox)  REG32((gpiox) + offsetof(GPIO_TypeDef, CFGLR))
#define GPIO_CTL1(gpiox)  REG32((gpiox) + offsetof(GPIO_TypeDef, CFGHR))
#define GPIO_ISTAT(gpiox) REG32((gpiox) + offsetof(GPIO_TypeDef, INDR))
#define GPIO_OCTL(gpiox)  REG32((gpiox) + offsetof(GPIO_TypeDef, OUTDR))
#define GPIO_BOP(gpiox)	  REG32((gpiox) + offsetof(GPIO_TypeDef, BSHR))
#define GPIO_BC(gpiox)	  REG32((gpiox) + offsetof(GPIO_TypeDef, BCR))
#define GPIO_LOCK(gpiox)  REG32((gpiox) + offsetof(GPIO_TypeDef, LCKR))

/* AFIO registers definitions */
#define AFIO_EC	     REG32(AFIO + offsetof(AFIO_TypeDef, ECR))
#define AFIO_PCF0    REG32(AFIO + offsetof(AFIO_TypeDef, PCFR1))
#define AFIO_EXTISS0 REG32(AFIO + offsetof(AFIO_TypeDef, EXTICR[0]))
#define AFIO_EXTISS1 REG32(AFIO + offsetof(AFIO_TypeDef, EXTICR[1]))
#define AFIO_EXTISS2 REG32(AFIO + offsetof(AFIO_TypeDef, EXTICR[2]))
#define AFIO_EXTISS3 REG32(AFIO + offsetof(AFIO_TypeDef, EXTICR[3]))
#define AFIO_PCF1    REG32(AFIO + offsetof(AFIO_TypeDef, PCFR2))

/* GPIO mode values set */
#define GPIO_MODE_SET(n, mode) ((uint32_t)((uint32_t)(mode) << (4U * (n))))
#define GPIO_MODE_MASK(n)      (0xFU << (4U * (n)))

#endif /* GD32_COMPAT_GD32_GPIO_H_ */
