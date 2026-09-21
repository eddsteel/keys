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
// - lighting switch on language change

#include QMK_KEYBOARD_H

// pinky mods
#define KE_LAGV LALT_T(KC_GRV)
#define KE_LAQT LALT_T(KC_QUOT)
#define KE_LGLB LGUI_T(KC_LBRC)
#define KE_RGRB RGUI_T(KC_RBRC)

// base home row
#define KE_LCKS LCTL_T(KC_S)
#define KE_LAKD LALT_T(KC_D)
#define KE_LGKF LGUI_T(KC_F)
#define KE_MEKG MEH_T(KC_G)
#define KE_HYKH ALL_T(KC_H)
#define KE_RGKJ RGUI_T(KC_J)
#define KE_LAKK LALT_T(KC_K)
#define KE_RCKL RCTL_T(KC_L)

// nav/num home row
#define KE_LCK7 LCTL_T(KC_7)
#define KE_LAK8 LALT_T(KC_8)
#define KE_LGK9 LGUI_T(KC_9)
#define KE_RGDN RGUI_T(KC_UP)
#define KE_LAUP LALT_T(KC_DOWN)
#define KE_RCRT RCTL_T(KC_RGHT)

// function home row
#define KE_LCMT LCTL_T(KC_MUTE)
#define KE_LADL LALT_T(KC_DEL)
#define KE_LGPS LGUI_T(KC_PSCR)
#define KE_RGF6 RGUI_T(KC_F6)
#define KE_LAF7 LALT_T(KC_F7)
#define KE_RCF8 RCTL_T(KC_F8)

// symbol home row
#define KE_LCBS LCTL_T(KC_BSLS)
#define KE_LAPD LALT_T(KC_DOT)
#define KE_LGSL LGUI_T(KC_SLSH)
// symbols are out of range

// thumbs
#define KE_LAY3 OSL(3)
#define KE_L1SP LT(1, KC_SPC)
#define KE_L2TA LT(2, KC_TAB)
#define KE_L2EN LT(2, KC_ENT)
#define KE_L1BS LT(1, KC_BSPC)
#define KE_SHFT OSM(MOD_LSFT)

// keys with mods
#define KE_STAB S(KC_TAB)
#define KE_LGEN G(KC_ENT)
#define KE_NDSH LSA(KC_MINS)
#define KE_MDSH A(KC_MINS)
#define KE_ELPS A(KC_SCLN)
#define KE_DEGR LSA(KC_8)
#define KE_BULL A(KC_8)
#define KE_FLSQ A(KC_RBRC)
#define KE_FLDQ A(KC_LBRC)
#define KE_FRDQ LSA(KC_LBRC)
#define KE_FRSQ LSA(KC_RBRC)
#define KE_LCGQ LCG(KC_Q)

enum custom_keycodes {
    KE_MAC1 = SAFE_RANGE,
    KE_MAC2
};

enum {
  BASE = 0,
  NNUM,
  FUNN,
  SYMB,
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
        KE_LAGV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_BSLS,     KC_EQL,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KE_LAQT,
        SC_LCPO,  KC_A, KE_LCKS, KE_LAKD, KE_LGKF, KE_MEKG,   KC_ESC,    KC_MINS, KE_HYKH, KE_RGKJ, KE_LAKK, KE_RCKL, KC_SCLN, SC_RCPC,
        KE_LGLB,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KE_RGRB,
                                          KE_LAY3, KE_L1SP,  KE_L2TA,    KE_L2EN, KE_L1BS, KE_SHFT
    ),
    [NNUM] = LAYOUT_split_3x6_3_ex2(
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_SLEP,    _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_WBAK, QK_BOOT,
       _______,    KC_6, KE_LCK7, KE_LAK8, KE_LGK9,    KC_0, _______,    _______, KC_LEFT, KE_RGDN, KE_LAUP, KE_RCRT, KC_WFWD, _______,
       _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DOT,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_PLUS, _______,
                                           KC_BSPC, _______, KE_STAB,    _______,  KC_DEL, _______
    ),
    [FUNN] = LAYOUT_split_3x6_3_ex2(
       QK_BOOT, KC_MFFD, KC_VOLU,  KC_INS, KC_BRIU, _______, _______,    KE_LCGQ,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F15, QK_BOOT,
       _______, KC_MPLY, KE_LCMT, KE_LADL, KE_LGPS, _______, _______,    _______,   KC_F5, KE_RGF6, KE_LAF7, KE_RCF8,  KC_F14, _______,
       _______, KC_MRWD, KC_VOLD, KC_PAUS, KC_BRID, _______,                        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F13, _______,
                                           _______,   TG(4), _______,    KE_LGEN,   TG(4), _______
    ),
    [SYMB] = LAYOUT_split_3x6_3_ex2(
       KC_TILD, KC_MINS, KE_NDSH, KE_MDSH, KC_UNDS,  KC_GRV, KE_ELPS,    KC_QUES, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LCBR, KC_RCBR,
       KE_DEGR, KC_PIPE, KE_LCBS, KE_LAPD, KE_LGSL, KC_QUOT, KC_COLN,    KC_SCLN, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, _______,
       KE_BULL, KE_FLSQ, KE_FLDQ, KE_FRDQ, KE_FRSQ, KC_DQUO,                      KC_PLUS,  KC_EQL,   KC_LT,   KC_GT, KC_LBRC, _______,
                                           _______, _______, _______,    KC_ENT,  KC_SPC,   KC_APP
    ),
    [KYBD] = LAYOUT_split_3x6_3_ex2(
       QK_BOOT, XXXXXXX, XXXXXXX, KE_MAC1, KE_MAC2, XXXXXXX, RGB_M_P,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
       _______, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, RM_TOGG,    XXXXXXX, RGB_M_R, RGB_M_B,RGB_M_SW, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_NEXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                             _______, TO(0), _______,    _______,   TO(0), _______
    )
};
