/* Copyright 2024 Juho T. (@Squalius-cephalus)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define LAYER_LOCK_IDLE_TIMEOUT 60000

#define ORBITAL_MOUSE_SPEED_CURVE {18, 19, 21, 24, 28, 33, 40, 46, 54, 60, 60, 60, 60, 60, 60, 60}
//                                 |               |               |               |           |
//                           t = 0.000           1.024           2.048           3.072       3.840 s