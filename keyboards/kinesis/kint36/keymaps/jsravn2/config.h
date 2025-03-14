/* Copyright 2021 Dave Vandyke <kzar@kzar.co.uk>
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

// Undefine all the LEDs so we can use them as layer indicators.
#undef LED_COMPOSE_PIN
#undef LED_NUM_LOCK_PIN
#undef LED_CAPS_LOCK_PIN
#undef LED_SCROLL_LOCK_PIN

// Five presses to hold a layer.
#define TAPPING_TOGGLE 5

// Improve tap and hold behavior.
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 175

// Salt key
#define FORCE_NKRO
