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
// handedness for thumbs (try one-handed 1)
// - RGB matrix
// - lighting switch on language change

#include QMK_KEYBOARD_H

// base home row
#define KE_LCKS LCTL_T(KC_S)
#define KE_LAKD LALT_T(KC_D)
#define KE_LGKF LGUI_T(KC_F)
#define KE_RGKJ RGUI_T(KC_J)
#define KE_LAKK LALT_T(KC_K)
#define KE_LCKL LCTL_T(KC_L)

// symbol home row
#define KE_LCBS LCTL_T(KC_BSLS)
#define KE_LASC LALT_T(KC_SCLN)
#define KE_LGCM LGUI_T(KC_COMM)
#define KE_RGDT RGUI_T(KC_DOT)
#define KE_LAMN LALT_T(KC_MINS)
#define KE_LCSL LCTL_T(KC_SLSH)

// nav/num home row
#define KE_LCK7 LCTL_T(KC_7)
#define KE_LAK8 LALT_T(KC_8)
#define KE_LGK9 LGUI_T(KC_9)
#define KE_RGDN RGUI_T(KC_DOWN)
#define KE_LAUP LALT_T(KC_UP)
#define KE_LCRT LCTL_T(KC_RGHT)

// function home row
#define KE_LCIN LCTL_T(KC_INS)
#define KE_LASL LALT_T(KC_SCRL)
#define KE_LGPS LGUI_T(KC_PSCR)
#define KE_RGF6 RGUI_T(KC_F6)
#define KE_LAF7 LALT_T(KC_F7)
#define KE_LCF8 LCTL_T(KC_F8)

// function rctl (rcmd on mac via karabiner)
#define KE_RCA RCTL(KC_A)
#define KE_RCC RCTL(KC_C)
#define KE_RCF RCTL(KC_F)
#define KE_RCQ RCTL(KC_Q)
#define KE_RCR RCTL(KC_R)
#define KE_RCV RCTL(KC_V)
#define KE_RCW RCTL(KC_W)
#define KE_RCX RCTL(KC_X)
#define KE_RCZ RCTL(KC_Z)

// thumbs
#define KE_LSYM OSL(SYM)
#define KE_LNSP LT(NUM, KC_SPC)
#define KE_LFTA LT(FUN, KC_TAB)
#define KE_LFEN LT(FUN, KC_ENT)
#define KE_LNBS LT(NUM, KC_BSPC)
#define KE_SHFT OSM(MOD_LSFT)

// keys with mods
#define KE_STAB S(KC_TAB)
#define KE_SENT S(KC_ENT)
#define KE_LGEN G(KC_ENT)
#define KE_LGTB G(KC_TAB)
#define KE_NDSH A(KC_MINS)
#define KE_MDSH LSA(KC_MINS)
#define KE_BULL A(KC_8)
#define KE_FLSQ A(KC_RBRC)
#define KE_FLDQ A(KC_LBRC)
#define KE_FRDQ LSA(KC_LBRC)
#define KE_FRSQ LSA(KC_RBRC)
#define KE_LCGQ LCG(KC_Q)
#define KE_LCSS LCS(KC_SPC)
#define KE_LGAE LAG(KC_ESC)

enum custom_keycodes {
    KE_MAC1 = SAFE_RANGE,
    KE_MAC2
};

enum {
  BSE = 0, // base
  SYM, // symbols
  NUM, // numbers / navigation
  FUN, // function
  KBD, // keyboard
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

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3_ex2(
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
                      '*', '*', '*', '*', '*', '*'
);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_split_3x6_3_ex2(
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_MEH,     KC_MEH,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
         KC_GRV,    KC_A, KE_LCKS, KE_LAKD, KE_LGKF,    KC_G,  KC_HYPR,    KC_HYPR,    KC_H, KE_RGKJ, KE_LAKK, KE_LCKL, KC_SCLN, KC_QUOT,
        SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RPRN,
                                            KE_LSYM, KE_LNSP,  KE_LFEN,    KE_LFTA, KE_LNBS, KE_SHFT
    ),
    [SYM] = LAYOUT_split_3x6_3_ex2(
        KE_NDSH, KC_EXLM,   KC_AT, KC_HASH, KC_AMPR, KC_DQUO, KE_FLDQ,    KE_FRDQ, KC_PERC, KC_CIRC, KC_ASTR,  KC_DLR, KC_LCBR, KC_RCBR,
        KE_MDSH, KC_UNDS, KE_LCBS, KE_LASC, KE_LGCM, KC_QUOT, KE_FLSQ,    KE_FRSQ, KC_QUES, KE_RGDT, KE_LAMN, KE_LCSL, KC_LBRC, KC_RBRC,
        KE_BULL, KC_PIPE, KC_COLN,  KC_EQL,  KC_APP,  KC_GRV,                      KC_TILD, KC_PLUS,   KC_LT,   KC_GT, KC_LPRN, KC_RPRN,
                                            _______,OSL(KBD), _______,     KC_ENT,  KC_SPC, OSL(NUM)
    ),
    [NUM] = LAYOUT_split_3x6_3_ex2(
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KE_LGAE,    KE_LCSS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_WFWD, _______,
        _______,    KC_6, KE_LCK7, KE_LAK8, KE_LGK9,    KC_0, _______,    _______, KC_LEFT, KE_RGDN, KE_LAUP, KE_LCRT, KC_WBAK, _______,
        _______, KC_PLUS, KC_COMM,  KC_DOT, KC_MINS, KC_COLN,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______, _______,
                                            KC_BSPC,  KC_ESC, KE_SENT,    KE_STAB,  KC_DEL, _______
    ),
    [FUN] = LAYOUT_split_3x6_3_ex2(
        KC_MPLY,  KE_RCQ,  KE_RCW,  KC_INS,  KE_RCR, KC_BRIU, KC_SLEP,    KE_LCGQ,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F15, KC_VOLU,
        KC_MRWD,  KE_RCA, KE_LCIN, KE_LASL, KE_LGPS,  KE_RCF, QK_BOOT,    QK_BOOT,   KC_F5, KE_RGF6, KE_LAF7, KE_LCF8,  KC_F14, KC_VOLD,
        KC_MFFD,  KE_RCZ,  KE_RCX,  KE_RCC,  KE_RCV, KC_BRID,                        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_F13, KC_MUTE,
                                           _______,  TG(KBD), KE_LGEN,    KE_LGTB, TG(KBD), _______
    ),
    [KBD] = LAYOUT_split_3x6_3_ex2(
        QK_BOOT, XXXXXXX, XXXXXXX, KE_MAC1, KE_MAC2, XXXXXXX, RGB_M_P,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        _______, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX, RM_TOGG,    XXXXXXX, RGB_M_R, RGB_M_B,RGB_M_SW, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_NEXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            TO(BSE), TO(BSE), TO(BSE),    TO(BSE), TO(BSE), TO(BSE)
    )
};
