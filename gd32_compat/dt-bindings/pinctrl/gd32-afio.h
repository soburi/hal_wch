/*
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GD32_COMPAT_DT_BINDINGS_PINCTRL_GD32_AFIO_H_
#define GD32_COMPAT_DT_BINDINGS_PINCTRL_GD32_AFIO_H_

#include <dt-bindings/pinctrl/ch32-afio.h>

#define GD32_MODE_ANALOG CH32_MODE_ANALOG
#define GD32_MODE_GPIO_IN CH32_MODE_GPIO_IN
#define GD32_MODE_ALTERNATE CH32_MODE_ALTERNATE

#define GD32_NORMP CH32_NORMP

#define GD32_PORT_GET CH32_PORT_GET
#define GD32_PIN_GET CH32_PIN_GET
#define GD32_MODE_GET CH32_MODE_GET
#define GD32_REMAP_GET CH32_REMAP_GET
#define GD32_REMAP_REG_GET CH32_REMAP_REG_GET
#define GD32_REMAP_POS_GET CH32_REMAP_POS_GET
#define GD32_REMAP_MSK_GET CH32_REMAP_MSK_GET
#define GD32_REMAP_VAL_GET CH32_REMAP_VAL_GET

#endif /* GD32_COMPAT_DT_BINDINGS_PINCTRL_GD32_AFIO_H_ */