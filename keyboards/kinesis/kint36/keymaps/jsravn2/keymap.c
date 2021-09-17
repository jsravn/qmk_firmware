/* Copyright 2021 Dave Vandyke <kzar@kzar.co.uk>,
 *   Based upon Xyverz's Kinesis keymap Copyright 2017-2020.
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

#include QMK_KEYBOARD_H
#include "version.h"

enum my_keycodes {
  QWERTY = SAFE_RANGE,
  STATUS,
  PROGRAM
};

#define LAYER_BASE 0
#define LAYER_CODE 1
#define LAYER_MEDIA 2
#define LAYER_WORD 3

#define MY_KC_FN1 TT(1)
#define MY_KC_FN2 TT(2)
#define MY_KC_FN3 TT(3)

#define LED_1 C7
#define LED_2 A14
#define LED_3 A5
#define LED_4 E26

#define MY_KC_LCTL MT(MOD_LCTL, KC_S)
#define MY_KC_LGUI MT(MOD_LGUI, KC_D)
#define MY_KC_LALT MT(MOD_LALT, KC_F)
#define MY_KC_RALT MT(MOD_RCTL, KC_J)
#define MY_KC_RGUI MT(MOD_RGUI, KC_K)
#define MY_KC_RCTL MT(MOD_RALT, KC_L)

enum my_tapdance_codes {
  TD_CBR,
  TD_BRC,
  TD_PRN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
};


// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER_BASE] = LAYOUT (
           // Left Hand
           KC_NO,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,  KC_F8,
           KC_EQL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
           KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
           KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                    KC_GRV,  KC_INS, KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LGUI,  KC_LCTL,
                              KC_LALT,
           KC_SPC,  KC_BSPC,  KC_DEL,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_NO,
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
                    KC_DOWN, KC_UP,    KC_NO,  KC_NO,

           // Right Thumb
           RCTL_T(KC_HOME), RGUI_T(KC_END),
           KC_PGUP,
           KC_PGDN, MY_KC_FN1, KC_ENT
    ),

[LAYER_CODE] = LAYOUT (
           // Left Hand
           STATUS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, TD(TD_BRC), TD(TD_CBR), TD(TD_PRN), KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_INS,  KC_TRNS, KC_TRNS,
           // Left Thumb
                    DYN_REC_START1, DYN_REC_START2,
                                    DYN_MACRO_PLAY1,
           DYN_REC_STOP,   KC_CAPS, DYN_MACRO_PLAY2,

           // Right Hand
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
           KC_TRNS, KC_RPRN, KC_RCBR, KC_RBRC, KC_TRNS,  KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           // Right Thumb
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
    ),

[LAYER_MEDIA] = LAYOUT (
           // Left Hand
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS,
           // Left Thumb
                    KC_TRNS, KC_TRNS,
                             KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS,

           // Right Hand
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           // Right Thumb
           KC_MRWD, KC_MFFD,
           KC_MPRV,
           KC_MNXT, KC_TRNS, KC_MPLY
    ),

[LAYER_WORD] = LAYOUT (
           // Left Hand
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           // Left Thumb
                    KC_TRNS, KC_TRNS,
                             KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS,

           // Right Hand
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
           KC_TRNS, KC_TRNS, KC_EQL, KC_SLSH , KC_ASTR, KC_TRNS,
           KC_TRNS, KC_7, KC_8, KC_9, KC_MINS, KC_TRNS,
           KC_TRNS, KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS,
           KC_TRNS, KC_1, KC_2, KC_3, KC_ENT, KC_TRNS,
                    KC_0, KC_TRNS, KC_DOT, KC_ENT,
           // Right Thumb
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
    )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case STATUS:
                SEND_STRING("Firmware> QMK " QMK_VERSION ", " QMK_BUILDDATE "\n");
                SEND_STRING("Keyboard> " QMK_KEYBOARD "\n");
                SEND_STRING("Keymap> " QMK_KEYMAP "\n");

                if (keymap_config.nkro)
                    SEND_STRING("NKRO> Enabled\n");
                else
                    SEND_STRING("NKRO> Disabled\n");

                if (debug_enable)
                    SEND_STRING("Debug> Enabled\n");
                else
                    SEND_STRING("Debug> Disabled\n");

                return false;
        }
    }

    return true;
}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  writePin(LED_1, 1);
  writePin(LED_2, 1);
  writePin(LED_3, 1);
  writePin(LED_4, 1);

  switch (layer) {
    case 1:
        writePin(LED_1, 0);
        break;
    case 2:
        writePin(LED_2, 0);
        break;
    case 3:
        writePin(LED_3, 0);
        break;
    case 4:
        writePin(LED_4, 0);
        break;
    default:
        break;
  }
}
