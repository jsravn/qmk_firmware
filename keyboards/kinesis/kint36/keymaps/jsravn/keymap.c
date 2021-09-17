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

enum layer_names {_QWERTY, _DVORAK, _MAC, _PC, _KEYPAD, _PROGRAM};
enum my_keycodes {QWERTY = SAFE_RANGE, DVORAK, WIN, MAC, PC, STATUS, PROGRAM};

#define LED_KEYPAD E26

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT (
           // Left Hand
           KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,        KC_F8,
           KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
           KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
           KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                    KC_GRV,  KC_NUBS, KC_LEFT, KC_RGHT,
           // Left Thumb
                    KC_LGUI, KC_LALT,
                             KC_HOME,
           KC_LCTL, KC_BSPC,  KC_END,

           // Right Hand
           KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, TG(_KEYPAD),  MO(_PROGRAM),
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
                    KC_DOWN, KC_UP,   KC_LBRC, KC_RBRC,
           // Right Thumb
           MO(_KEYPAD), KC_RGUI,
           KC_PGUP,
           KC_PGDN, KC_ENT, KC_SPC
    ),

[_KEYPAD] = LAYOUT (
           // Left Hand
           _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, KC_LBRC, KC_RBRC, _______,
           _______, _______, _______, S(KC_LBRC), S(KC_RBRC), _______,
           _______, _______, _______, S(KC_9), S(KC_0), _______,
                    _______, KC_INS,  _______, _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           _______,    _______, _______, _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______,
           _______, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST,  _______,
           _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,  _______,
           _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,  _______,
           _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT,  _______,
                    _______, _______, KC_PDOT, KC_PENT,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, KC_P0
    ),

[_PROGRAM] = LAYOUT (
           // Left Hand
           STATUS,  _______, _______, _______, _______,  _______,  _______,   _______,  _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
           _______, _______, _______, _______ , _______, _______,
                    _______, _______, _______ , _______,
           // Left Thumb
                    _______, _______,
                             _______,
           _______, _______, _______,

           // Right Hand
           RESET,   _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,
           // Right Thumb
           _______, _______,
           _______,
           _______, _______, _______
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(LED_KEYPAD, !layer_state_cmp(state, _KEYPAD));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case STATUS:
                SEND_STRING("Firmware> QMK " QMK_VERSION ", " QMK_BUILDDATE "\n");
                SEND_STRING("Keyboard> " QMK_KEYBOARD "\n");
                SEND_STRING("Keymap> " QMK_KEYMAP "\n");

                if (layer_state_cmp(default_layer_state, _QWERTY))
                    SEND_STRING("Layout> QWERTY\n");
                else
                    SEND_STRING("Layout> DVORAK\n");

                if (layer_state_is(_MAC))
                    SEND_STRING("Thumb keys mode> MAC\n");
                else if (layer_state_is(_PC))
                    SEND_STRING("Thumb keys mode> PC\n");
                else
                    SEND_STRING("Thumb keys mode> WIN\n");

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
