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

#ifdef USE_I2C
    #include "i2c.h"
#endif

//#define USE_I2C  // For OLED only, but still required :-/ Meh
#ifdef SSD1306OLED
    #include "LUFA/Drivers/Peripheral/TWI.h"
    #include "ssd1306.h"
#endif

// Temporarily turn on _ALT when held, KC_APP when tapped
#define TMP_L LT(_KPD, ___X___)

// todo: write intelligent code for layer swapping
// todo: sa for unittests

// Left hand layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = KEYMAP( /* Base layer */
      KC_ESC,		KC_1,		KC_2,       KC_3,		KC_4,		  KC_5,	   KC_KP_PLUS,
      KC_TAB,		KC_Q,		KC_W,       KC_E,		KC_R,		  KC_T,	   KC_KP_MINUS,
	  KC_GRAVE,		KC_A,		KC_S,		KC_D,		KC_F,		  KC_G,	   KC_HOME,
	  KC_LSFT,		KC_Z,		KC_X,		KC_C,		KC_V,		  KC_B,    KC_END,
	  KC_LCTL,		KC_LALT,	KC_MINS,    KC_EQL,	    KC_SPC,	      TMP_L,   KC_BSPC
    ),

    [_KPD] = KEYMAP ( /* keypad */
      _______,    KC_F1,      KC_F2,      KC_F3,       KC_F4,      KC_F5,      ___X___,
      _______,    ___X___,    ___X___,    ___X___,     ___X___,    ___X___,    ___X___,
      _______,    ___X___,    ___X___,    ___X___,     ___X___,    ___X___,    KC_VOLD,
      _______,    ___X___,    ___X___,    ___X___,     ___X___,    ___X___,    KC_VOLU,
      _______,    _______,    ___X___,    ___X___,     _______,    _______,    KC_MUTE
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



//[csc] stole dis
//SSD1306 OLED init and update loop, make sure to add #define SSD1306OLED in config.h
//#ifdef SSD1306OLED
void matrix_master_OLED_init (void) {
    #ifdef USE_I2C
        i2c_master_init();
    #ifdef SSD1306OLED
    // calls code for the SSD1306 OLED
      _delay_ms(400);
      TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
      iota_gfx_init();   // turns on the display
    #endif
    #endif
}
//#endif

void matrix_init_user(void) {

}

void matrix_setup(void) {
  matrix_master_OLED_init();
}

void matrix_scan_user(void) {
    // iota_gfx_task();  // this is what updates the display continuously
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
