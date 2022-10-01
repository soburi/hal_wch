/*
 * Copyright (c) 2021 Teslabs Engineering S.L.
 * Copyright (c) 2022 TOKITA Hiroshi <tokita.hiroshi@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef DT_BINDINGS_PINCTRL_CH32_AFIO_H_
#define DT_BINDINGS_PINCTRL_CH32_AFIO_H_

/* This header is based on gd32-afio.h. Only renaming GD32->CH32. */

/**
 * @name CH32 pin modes
 * @{
 */

/** Analog mode */
#define CH32_MODE_ANALOG 0U
/** GPIO input */
#define CH32_MODE_GPIO_IN 1U
/** Alternate function */
#define CH32_MODE_ALTERNATE 2U

/** @} */

/**
 * @name CH32 pinmux bit field mask and positions.
 * @{
 */

/** Port field mask. */
#define CH32_PORT_MSK 0xFU
/** Port field position. */
#define CH32_PORT_POS 0U
/** Pin field mask. */
#define CH32_PIN_MSK 0xFU
/** Pin field position. */
#define CH32_PIN_POS 4U
/** Mode field mask. */
#define CH32_MODE_MSK 0x3U
/** Mode field position. */
#define CH32_MODE_POS 8U
/** Remap field mask. */
#define CH32_REMAP_MSK 0x3FFU
/** Remap field position. */
#define CH32_REMAP_POS 10U

/** @} */

/** No remap available */
#define CH32_NORMP 0U

/**
 * Obtain port field from pinmux configuration.
 *
 * @param pinmux Pinmux bit field value.
 */
#define CH32_PORT_GET(pinmux) \
	(((pinmux) >> CH32_PORT_POS) & CH32_PORT_MSK)

/**
 * Obtain pin field from pinmux configuration.
 *
 * @param pinmux Pinmux bit field value.
 */
#define CH32_PIN_GET(pinmux) \
	(((pinmux) >> CH32_PIN_POS) & CH32_PIN_MSK)

/**
 * Obtain mode field from pinmux configuration.
 *
 * @param pinmux Pinmux bit field value.
 */
#define CH32_MODE_GET(pinmux) \
	(((pinmux) >> CH32_MODE_POS) & CH32_MODE_MSK)

/**
 * Obtain pinmux field from pinmux configuration.
 *
 * @param pinmux Pinmux bit field value.
 */
#define CH32_REMAP_GET(pinmux) \
	(((pinmux) >> CH32_REMAP_POS) & CH32_REMAP_MSK)

/**
 * @brief Remap configuration bit field.
 *
 * Fields:
 *
 * - 0..3: port
 * - 4..7: pin
 * - 8..9: mode
 * - 10..19: remap
 *
 * @param port Port ('A'..'P')
 * @param pin Pin (0..15)
 * @param mode Mode (ANALOG, GPIO_IN, ALTERNATE).
 * @param remap Remap value, see #CH32_REMAP.
 */
#define CH32_PINMUX_AFIO(port, pin, mode, remap)			\
	(((((port) - 'A') & CH32_PORT_MSK) << CH32_PORT_POS) |		\
	 (((pin) & CH32_PIN_MSK) << CH32_PIN_POS) |			\
	 (((CH32_MODE_ ## mode) & CH32_MODE_MSK) << CH32_MODE_POS) |	\
	 (((CH32_ ## remap) & CH32_REMAP_MSK) << CH32_REMAP_POS))

/**
 * @name Remap bit field mask and positions.
 * @{
 */

/** Register field mask. */
#define CH32_REMAP_REG_MSK 0x1U
/** Register field position. */
#define CH32_REMAP_REG_POS 0U
/** Position field mask. */
#define CH32_REMAP_POS_MSK 0x1FU
/** Position field position. */
#define CH32_REMAP_POS_POS 1U
/** Mask field mask. */
#define CH32_REMAP_MSK_MSK 0x3U
/** Mask field position. */
#define CH32_REMAP_MSK_POS 6U
/** Value field mask. */
#define CH32_REMAP_VAL_MSK 0x3U
/** Value field position. */
#define CH32_REMAP_VAL_POS 8U

/** @} */

/**
 * Obtain register field from remap configuration.
 *
 * @param remap Remap bit field value.
 */
#define CH32_REMAP_REG_GET(remap) \
	(((remap) >> CH32_REMAP_REG_POS) & CH32_REMAP_REG_MSK)

/**
 * Obtain position field from remap configuration.
 *
 * @param remap Remap bit field value.
 */
#define CH32_REMAP_POS_GET(remap) \
	(((remap) >> CH32_REMAP_POS_POS) & CH32_REMAP_POS_MSK)

/**
 * Obtain mask field from remap configuration.
 *
 * @param remap Remap bit field value.
 */
#define CH32_REMAP_MSK_GET(remap) \
	(((remap) >> CH32_REMAP_MSK_POS) & CH32_REMAP_MSK_MSK)

/**
 * Obtain value field from remap configuration.
 *
 * @param remap Remap bit field value.
 */
#define CH32_REMAP_VAL_GET(remap) \
	(((remap) >> CH32_REMAP_VAL_POS) & CH32_REMAP_VAL_MSK)

/**
 * @brief Remap configuration bit field.
 *
 * - 0:    reg (0 or 1).
 * - 1..5: pos (0..31).
 * - 6..7: msk (0x1, 0x3).
 * - 8..9: val (0..3).
 *
 * @param reg AFIO_PCFx register (0, 1).
 * @param pos Position within AFIO_PCx.
 * @param msk Mask for the AFIO_PCx field.
 * @param val Remap value (0, 1, 2 or 3).
 */
#define CH32_REMAP(reg, pos, msk, val)					\
	((((reg) & CH32_REMAP_REG_MSK) << CH32_REMAP_REG_POS) |		\
	 (((pos) & CH32_REMAP_POS_MSK) << CH32_REMAP_POS_POS) |		\
	 (((msk) & CH32_REMAP_MSK_MSK) << CH32_REMAP_MSK_POS) |		\
	 (((val) & CH32_REMAP_VAL_MSK) << CH32_REMAP_VAL_POS))

#endif /* DT_BINDINGS_PINCTRL_CH32_AFIO_H_ */
