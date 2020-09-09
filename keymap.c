#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define ______ KC_TRNS
#define XXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | DEL |
 * |-----------------------------------------------------------------------------------------+
 * | CTRL |  GUI  |  ALT  |               Space                | FN2 | FN1 |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, XXXXXX, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPSLOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI,KC_LALT , KC_SPC, KC_SPC, KC_SPC, MO(2), MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

/* FN Layer
 * ,-----------------------------------------------------------------------------------------.
 * | `~ | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   RBGTOG   |
 * |-----------------------------------------------------------------------------------------+
 * |        |RBGM |RBGRM|     |     |     |     |     |     |     |     | Val+ | Val- |      |
 * |-----------------------------------------------------------------------------------------+
 * |  RESET  |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |    |     |      |     | vol+|MUTE |
 * |-----------------------------------------------------------------------------------------+
 * |SLEEP |       |       |                                   |     |      |     | vol-|     |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_GRV, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, XXXXXX, RGB_TOG,
      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
      RESET, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,	
      ______, ______, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_VOLU, KC_MUTE,
      KC_SLEP, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_VOLD, XXXXXX 
      ),

  /* FN2 Layer
 * ,-----------------------------------------------------------------------------------------.
 * |    | BL  | BL_S| BL- | BL+ |     |     |RESET|     |     |     |     |     |   RBGTOG   |
 * |-----------------------------------------------------------------------------------------+
 * |       |RGB_For|RGB_Bac|    |    |    |     |     |     |     |     | Val+ | Val- |      |
 * |------------------------------------- ---------------------------------------------------+
 * |         | Hue+| Hue-| Sat+| Sat-|     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |BREATH|RNBOW|GRAD|SWIRL|STAT|KNIGHT|SNAKE|     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                   |     |PG_UP|PG_DN |     |     |
 * `------------------------------------------------------------------------------------------
 */

  LAYOUT_directional(
      XXXXXX, BL_TOGG, BL_STEP, BL_DEC, BL_INC, XXXXXX, XXXXXX, RESET, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, RGB_TOG,
      XXXXXX, RGB_MOD, RGB_RMOD, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, RGB_VAI, RGB_VAD, XXXXXX,
      XXXXXX, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, 
      ______, XXXXXX, RGB_M_B, RGB_M_R, RGB_M_G, RGB_M_SW, RGB_M_P, RGB_M_K, RGB_M_SN, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, KC_PGUP, KC_PGDOWN, XXXXXX, XXXXXX 
      ),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}