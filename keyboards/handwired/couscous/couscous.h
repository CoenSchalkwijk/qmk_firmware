/* Copyright 2018 C. Schalkwijk (CSC) coen@navelpluis.nl
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

#ifndef COUSCOUS_H
#define COUSCOUS_H

#include "quantum.h"

#define USE_I2C
#define SSD1306OLED
#define SSD1306_ADDRESS 0x3C

#define _DEF 0  // Default
#define _KPD 1  // Keypad
#define _TECH 2 // Technical
#define _DWARF 3 // Dwarf Fortress

// Temporarily turn on _ALT when held, KC_NO when tapped
#define TMP_L LT(_KPD, ___X___)

#define _______ KC_TRNS
#define ___X___ KC_NO // hmmm todo?

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
			k00, k01, k02, k03, k04, k05, k06, \
			k10, k11, k12, k13, k14, k15, k16, \
			k20, k21, k22, k23, k24, k25, k26, \
			k30, k31, k32, k33, k34, k35, k36, \
			k40, k41, k42, k43, k44, k45, k46 \
	 ) \
	 { \
			 { k00, k01, k02, k03, k04, k05, k06 }, \
			 { k10, k11, k12, k13, k14, k15, k16 }, \
			 { k20, k21, k22, k23, k24, k25, k26 }, \
			 { k30, k31, k32, k33, k34, k35, k36 }, \
			 { k40, k41, k42, k43, k44, k45, k46 } \
	 }


#endif
