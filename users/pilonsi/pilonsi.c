// Copyright 2023-2026 Pilonsi
// My personal 36-key layout

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 2 of the License, or (at your option)
// any later version. This program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details. You should have received a copy of the GNU
// General Public License along with this program. If not, see
// <http://www.gnu.org/licenses/>.

#include "pilonsi.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_pilonsi(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    U_NP,    U_NP,    LA_LAL,  KC_SPC,  KC_TAB,  KC_ENT,  KC_BSPC, LA_LAR,  U_NP,    U_NP
  ),
  [LAR] = LAYOUT_pilonsi(
    _______, _______, _______, _______, _______, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    _______, _______, _______, _______, _______, U_NA,    OS_SFT,  OS_CTL,  OS_GUI,  OS_ALT,
    _______, _______, _______, _______, _______, U_NA,    LA_NUM,  LA_SYM,  U_NA,    U_NA,
    U_NP,    U_NP,    _______, KC_ESC,  U_NU,    U_NA,    U_NA,    _______, U_NP,    U_NP
  ),
  [NUM] = LAYOUT_pilonsi(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    OS_SFT,  OS_CTL,  OS_GUI,  OS_ALT,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,    _______, U_NA,    U_NA,    U_NA,
    U_NP,    U_NP,    KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    _______, U_NP,    U_NP
  ),
  [SYM] = LAYOUT_pilonsi(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,    OS_SFT,  OS_CTL,  OS_GUI,  OS_ALT,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,    U_NA,    _______, U_NA,    U_NA,
    U_NP,    U_NP,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    _______, U_NP,    U_NP
  ),
  [LAL] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    _______, _______, _______, _______, _______,
    OS_ALT,  OS_GUI,  OS_CTL,  OS_SFT,  U_NA,    _______, _______, _______, _______, _______,
    U_NA,    U_NA,    LA_CAT,  LA_NAV,  U_NA,    _______, _______, _______, _______, _______,
    U_NP,    U_NP,    _______, U_NA,    U_NA,    U_NU,    KC_DEL,  _______, U_NP,    U_NP
  ),
  [NAV] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    OS_ALT,  OS_GUI,  OS_CTL,  OS_SFT,  U_NA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
    U_NA,    U_NA,    U_NA,    _______, U_NA,    U_NU,    KC_VOLD, KC_VOLU, KC_MUTE, U_NU,
    U_NP,    U_NP,    _______, U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NP,    U_NP
  ),
  [CAT] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    OS_ALT,  OS_GUI,  OS_CTL,  OS_SFT,  U_NA,    CA_DI,   CA_AT,   CA_AO,   CA_PV,   KC_CAPS,
    U_NA,    U_NA,    _______, U_NA,    U_NA,    CA_NY,   U_NU,    CA_CC,   CA_EX,   CA_IN,
    U_NP,    U_NP,    _______, U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NP,    U_NP
  ),
  [FUN] = LAYOUT_pilonsi(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, RM_HUEU, RM_SATU, RM_VALU, P_OLED,  RM_NEXT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, P_VER,   U_NU,    U_NU,    QK_RBT,  QK_BOOT,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, RM_HUED, RM_SATD, RM_VALD, RM_TOGG, RM_PREV,
    U_NP,    U_NP,    _______, U_NU,    U_NU,    U_NU,    U_NU,    _______, U_NP,    U_NP
  ),
};

bool is_oneshot_cancel_press(uint16_t keycode) {
  return false;
}

bool is_oneshot_cancel_press_permissive(uint16_t keycode) {
  return false;
}

bool is_oneshot_cancel_release(uint16_t keycode) {
  switch (keycode) {
    case LA_LAL:
    case LA_LAR:
      return true;
  }
  return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
    case LA_NAV:
    case LA_NUM:
    case LA_SYM:
    case LA_CAT:
    case OS_SFT:
    case OS_CTL:
    case OS_ALT:
    case OS_GUI:
      return true;
  }
  return false;
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Callum oneshot modifiers
  update_oneshot(
    &os_shft_state, KC_LSFT, OS_SFT,
    keycode, record
  );

  update_oneshot(
    &os_ctrl_state, KC_LCTL, OS_CTL,
    keycode, record
  );

  update_oneshot(
    &os_alt_state, KC_LALT, OS_ALT,
    keycode, record
  );

  update_oneshot(
    &os_gui_state, KC_LGUI, OS_GUI,
    keycode, record
  );

  // From here on we ignore keyups
  if (!record->event.pressed) { return true; }

  bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  // Handle os shortcuts
  if (hostos_process_record(keycode)) {
    return false;
  }

  // Process catalan keycodes
  if (catalan_process_record(keycode, is_shifted)) {
    return false;
  }

  switch (keycode) {
    // OLED toggle
    #ifdef OLED_ENABLE
    case P_OLED:
      if (is_oled_on()) {
        oled_off();
      } else {
        oled_on();
      }  
      return false;
    #endif

    // Show version string
    case P_VER:
      SEND_STRING(PILONSI_VERSION_STRING);
      return false;

    default:
      return true;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, LAL, LAR, FUN);
  return state;
}
