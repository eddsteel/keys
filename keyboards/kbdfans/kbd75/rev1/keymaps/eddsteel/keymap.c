#include QMK_KEYBOARD_H
extern rgblight_config_t rgblight_config;

// layer taps
#define LT_1S LT(1, KC_SPC)
#define LT_2A LT(2, KC_APP)
#define LT_2E LT(2, KC_ESC)
#define LT_3V LT(3, KC_V)
#define LT_2B LT(2, KC_B)

#define MT_ENT MEH_T(KC_ENTER)
#define GT_BSP RGUI_T(KC_BACKSPACE)

#define KILL LGUI(LALT(KC_ESC))

/* home mods
#define HM_A LGUI_T(KC_A)  // A acts as GUI (Cmd/Win) when held
#define HM_S LALT_T(KC_S)  // S acts as Alt when held
#define HM_D LSFT_T(KC_D)  // D acts as Shift when held
#define HM_F LCTL_T(KC_F)  // F acts as Ctrl when held
#define HM_G HYPR_T(KC_G)  // G acts as Hypr when held

#define HM_H MEH_T(KC_H)   // H acts as Meh when held
#define HM_J RCTL_T(KC_J)  // J acts as Ctrl when held
#define HM_K RSFT_T(KC_K)  // K acts as Shift when held
#define HM_L LALT_T(KC_L)  // L acts as Alt when held
#define HM_SCLN RGUI_T(KC_SCLN)  // ; acts as GUI (Cmd/Win) when held
*/

// my space cadet
#define SC_LCBO LCTL_T(KC_LBRC)
#define SC_RCBC LCTL_T(KC_RBRC)
#define SC_LABS LALT_T(KC_BSLS)
#define SC_RAFS RALT_T(KC_SLSH)

// layernames
enum {
      _BASE = 0,
      _FUNC,
      _NUM,
      _SYM,
      NLYRS
};

enum custom_keycodes {
    KC_MR = SAFE_RANGE,
    KC_IM,
    KC_EX
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_MR:
    if (record->event.pressed) {
      SEND_STRING("Revert and reapply.");
    } else {}
    return false;
  case KC_EX:
    if (record->event.pressed) {
      SEND_STRING("Reviewed for data exfiltration.");
    } else {}
    return false;
  case KC_IM:
    if (record->event.pressed) {
      tap_code16(HYPR(KC_SPC));
      rgblight_set_layer_state(NLYRS, !rgblight_get_layer_state(NLYRS));
    } else {}
    return false;
  case KC_SLEP:
    if (detected_host_os() == OS_MACOS && record->event.pressed) {
      tap_code16(LGUI(LALT(KC_SLEP)));
      return false;
    }
    return true;
  default:
    return true;
  }
}

// light 10-13 white when input method is changed
const rgblight_segment_t PROGMEM inputmethod_layer[] = RGBLIGHT_LAYER_SEGMENTS({10,4,HSV_WHITE});

const rgblight_segment_t PROGMEM rgblayer0[] = RGBLIGHT_LAYER_SEGMENTS({0,16,2,247,255});
const rgblight_segment_t PROGMEM rgblayer1[] = RGBLIGHT_LAYER_SEGMENTS({0,16,132,246,255});
const rgblight_segment_t PROGMEM rgblayer2[] = RGBLIGHT_LAYER_SEGMENTS({0,16,220,246,255});
const rgblight_segment_t PROGMEM rgblayer3[] = RGBLIGHT_LAYER_SEGMENTS({0,16,50,246,255});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] =
  RGBLIGHT_LAYERS_LIST(rgblayer0, rgblayer1, rgblayer2, rgblayer3, inputmethod_layer);

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, 1));
  rgblight_set_layer_state(2, layer_state_cmp(state, 2));
  rgblight_set_layer_state(3, layer_state_cmp(state, 3));

   return state;
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(2, 247, 255);
  rgblight_layers = my_rgb_layers;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
    KC_SLEP, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_MUTE,
    KILL,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS, KC_EQL,  KC_NO,   KC_MPLY, KC_HOME,
    KC_BSPC, KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_QUOT, KC_DEL,           KC_TAB,  KC_PGUP,
    SC_LCBO, KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    SC_RCBC,                   KC_ESC,  KC_PGDN,
    SC_LSPO, SC_LABS,    KC_Z,       KC_X,       KC_C,       LT_3V,      LT_2B,      KC_N,       KC_M,       KC_COMM,    KC_DOT,     SC_RAFS, SC_RSPC,          KC_UP,   KC_END,
    KC_GRV,  CW_TOGG,    LT_2A,                              KC_LGUI,    LT_1S,      MT_ENT,                 KC_PSCR,    KC_SCRL,    KC_PAUS, KC_LEFT,          KC_DOWN, KC_RGHT
  ),

  LAYOUT(
    OSL(2),  HYPR(KC_E), HYPR(KC_F), HYPR(KC_M), HYPR(KC_X), HYPR(KC_W), HYPR(KC_Z), KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,  KC_F24,  KC_INS,  KC_SCRL, KILL,
    KC_SLEP, UG_TOGG,    RGB_M_P,    RGB_M_B,    RGB_M_SW,   RGB_M_K,    RGB_M_G,    UG_HUEU,    UG_HUED,    UG_SATU,    UG_SATD,    UG_VALU, UG_VALD, QK_BOOT, QK_BOOT, DB_TOGG,
    QK_BOOT, HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P), UG_SPDU, UG_SPDD, QK_BOOT,          KC_BRIU,
    KC_NO,   HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), KC_NO,      KC_NO,                     KC_NO,   KC_BRID,
    KC_MUTE, KC_NO,      HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), KC_NO,      KC_NO,      KC_NO,   KC_MPLY,          KC_VOLU, NK_TOGG,
    OSL(2),  KC_NO,      KC_NO,                              KC_IM,      KC_IM,      KC_SLEP,                            KC_NO,      KC_NO,   KC_TRNS, KC_MRWD, KC_VOLD, KC_MFFD
  ),

  LAYOUT(
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PSLS,    KC_PAST,    KC_PEQL,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_EX,      KC_MR,      KC_NO,      KC_NO,      KC_7,       KC_8,       KC_9,       KC_PMNS,    KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_4,       KC_5,       KC_6,       KC_PPLS,    KC_NO,                     KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_LLCK,    KC_NO,      KC_NO,      KC_1,       KC_2,       KC_3,       KC_ENT,  KC_NO,            KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,                              KC_NO,      KC_NO,      KC_0,                               KC_DOT,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
   ),

  LAYOUT(
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_INS,     KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,   KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_NO,      KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,      KC_NO,                     KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_LLCK,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,            KC_NO,   KC_NO,
    KC_NO,   KC_NO,      KC_NO,                              KC_NO,      KC_NO,      KC_NO,                              KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
   )
};
