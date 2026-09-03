/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
// TODO
// - RGB matrix
// - japanese mode

#include QMK_KEYBOARD_H

#define KE_MEGV MEH_T(KC_GRV)
#define KE_LGLB LGUI_T(KC_LBRC)
#define KE_LATA LALT_T(KC_TAB)
#define KE_LSEN LSFT_T(KC_ENT)
#define KE_RGRB RGUI_T(KC_RBRC)
#define KE_HYQU ALL_T(KC_QUOT)
#define KE_LADL LALT_T(KC_DEL)
#define KE_L2SP LT(2, KC_SPC)
#define KE_L1BS LT(1, KC_BSPC)
#define KE_LCGQ LCG(KC_Q)

enum custom_keycodes {
    KE_MAC1 = SAFE_RANGE,
    KE_MAC2
};

enum {
  BASE = 0,
  NMBA,
  MDIA,
  KYBD,
  NLYRS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KE_MAC1:
        if (record->event.pressed) {
          SEND_STRING("Checked for data exfiltration.");
        } else {}
        break;
    case KE_MAC2:
        if (record->event.pressed) {
          SEND_STRING("Revert and reapply.");
        } else {}
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        KE_MEGV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_BSLS,     KC_EQL,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KE_HYQU,
        SC_LCPO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_ESC,      KC_MINS,   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SC_RCPC,
        KE_LGLB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KE_RGRB,
                                          KE_LATA,  KE_L2SP,  KE_LSEN,   KC_RSFT, KE_L1BS, KE_LADL
    ),
    [NMBA] = LAYOUT_split_3x6_3_ex2(
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_SLEP,    QK_BOOT, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LCBR, KC_RCBR,
       _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_COLN,    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, _______,
       _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DOT,                      KC_PLUS,  KC_EQL,   KC_LT,   KC_GT, KC_LBRC, _______,
                                           _______,   TG(3), _______,    _______, _______,  KC_APP
    ),
    [MDIA] = LAYOUT_split_3x6_3_ex2(
       _______, KC_MPLY, KC_MRWD, KC_MFFD, KC_MUTE, KC_VOLU, QK_BOOT,    KE_LCGQ, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_BRIU,  KC_F15,
       _______,  KC_INS, KC_PAUS,  KC_DEL, KC_PSCR, KC_VOLD,   KC_F6,      KC_F7, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BRID,  KC_F14,
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F13,
                                           _______, _______, _______,    _______,  OSL(3),  KC_APP
    ),
    [KYBD] = LAYOUT_split_3x6_3_ex2(
         TO(0), XXXXXXX, XXXXXXX, KE_MAC1, KE_MAC2, XXXXXXX, RGB_M_P,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
       _______, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, RM_TOGG,    XXXXXXX, RGB_M_R, RGB_M_B,RGB_M_SW, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_NEXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                           _______, _______, _______,    _______, _______, _______
    )
};