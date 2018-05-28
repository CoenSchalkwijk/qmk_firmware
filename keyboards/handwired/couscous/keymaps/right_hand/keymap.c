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
#include "couscous.h"

// Temporarily turn on _ALT when held, KC_APP when tapped
#define TMP_R LT(_KPD, ___X___)

// RIGHT HAND
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
          [_DEF] = KEYMAP( /* Base layer*/
              TO(_KPD),   KC_6,		KC_7,       KC_8,	    KC_9,	  KC_0,     KC_LBRC,
    	      TO(_KPD),   KC_Y,		KC_U,       KC_I,	    KC_O,	  KC_P,     KC_RBRC,
        	  KC_PGDN,	  KC_H,		KC_J,		KC_K,	    KC_L,	  KC_SCLN,  KC_QUOT,
        	  KC_PGUP,	  KC_N,		KC_M,		KC_COMM,    KC_DOT,   KC_SLSH,  KC_BSLS,
        	  KC_DEL,     TMP_R,    KC_ENT,	    KC_LEFT,	KC_UP,    KC_DOWN,  KC_RIGHT
            ),

          [_KPD] = KEYMAP ( /* Keypad */
              TO(_DEF),   KC_F6,      KC_F7,      KC_F8,    KC_F9,    KC_F10,     ___X___,
              TO(_DEF),   KC_F,       ___X___,    KC_HOME,  KC_UP,    KC_PGUP,    ___X___,
              ___X___,    KC_G,       ___X___,    KC_LEFT,  KC_5,     KC_RIGHT,   ___X___,
              ___X___,    ___X___,    ___X___,    KC_END,   KC_DOWN,  KC_PGDN,    KC_ENT,
              ___X___,    _______,    _______,    KC_INS,   ___X___,  ___X___,    ___X___
            )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
