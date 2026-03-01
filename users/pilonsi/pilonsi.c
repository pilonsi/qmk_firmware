// Copyright 2019 Manna Harbour
// Copyright 2023-2026 Pilonsi
// My personal 36-key layout based off a modified version of the wonderful
// Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

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

static enum dead_key_states dead_key_state = DK_NONE;

// Switch unicode mode without saving to EEPROM
// We se the unicode settings saved to the EEPROM by QMK to restore our OS
// state and save unnecessary EEPROM writes.
void pilonsi_cycle_os_mode(void) {
  switch (unicode_config.input_mode) {
    case UNICODE_MODE_MACOS:    
      unicode_config.input_mode = UNICODE_MODE_WINCOMPOSE;
      break;
    case UNICODE_MODE_WINCOMPOSE: 
      unicode_config.input_mode = UNICODE_MODE_LINUX;
      break;
    case UNICODE_MODE_LINUX:    
      unicode_config.input_mode = UNICODE_MODE_MACOS;
      break;
    default: unicode_config.input_mode = UNICODE_MODE_LINUX;
  }

  unicode_input_mode_set_kb(unicode_config.input_mode);
}

bool pilonsi_handle_os_shortcuts(uint16_t keycode) {
  bool is_mac = (unicode_config.input_mode == UNICODE_MODE_MACOS);

  switch (keycode) {
    case P_CPY:
      tap_code16(is_mac ? LCMD(KC_C) : C(KC_C));
      return true;
    case P_PST:
      tap_code16(is_mac ? LCMD(KC_V) : C(KC_V));
      return true;
    case P_CUT:
      tap_code16(is_mac ? LCMD(KC_X) : C(KC_X));
      return true;
    case P_UND:
      tap_code16(is_mac ? LCMD(KC_Z) : C(KC_Z));
      return true;
    case P_RDO:
      tap_code16(is_mac ? S(LCMD(KC_Z)) : C(KC_Y));
      return true;
  }

  return false;
}

bool pilonsi_handle_dead_keys(uint16_t keycode, bool is_shifted) {
  bool handled = false;

	// Strip mod-tap and other wrappers from keys
	uint16_t basic_keycode = keycode & 0x00FF;

  if (dead_key_state == DK_ACUTE) {
    switch (basic_keycode) {
      case KC_A:
        send_unicode_string(is_shifted ? "Á" : "á");
        handled = true;
        break;
      case KC_E:
        send_unicode_string(is_shifted ? "É" : "é");
        handled = true;
        break;
      case KC_I:
        send_unicode_string(is_shifted ? "Í" : "í");
        handled = true;
        break;
      case KC_O:
        send_unicode_string(is_shifted ? "Ó" : "ó");
        handled = true;
        break;
      case KC_U:
        send_unicode_string(is_shifted ? "Ú" : "ú");
        handled = true;
        break;
    }
  } else if (dead_key_state == DK_GRAVE) {
    switch (keycode) {
      case KC_A:
        send_unicode_string(is_shifted ? "À" : "à");
        handled = true;
        break;
      case KC_E:
        send_unicode_string(is_shifted ? "È" : "è");
        handled = true;
        break;
      case KC_O:
        send_unicode_string(is_shifted ? "Ò" : "ò");
        handled = true;
        break;
    }
  } else if (dead_key_state == DK_DIERESIS) {
    switch (keycode) {
      case KC_U:
        send_unicode_string(is_shifted ? "Ü" : "ü");
        handled = true;
        break;
      case KC_I:
        send_unicode_string(is_shifted ? "Ï" : "ï");
        handled = true;
        break;
    }
  }

  dead_key_state = DK_NONE;
  return handled;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) { return true; }

  bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  // Handle OS shortcuts if present
  if (pilonsi_handle_os_shortcuts(keycode)) {
    return false;
  }

  // Intercept dead keys for catalan characters
  if (dead_key_state != DK_NONE) {
    if (pilonsi_handle_dead_keys(keycode, is_shifted)) {
      return false;
    }
  }

  // Otherwise continue processing the rest of the custom keycodes
  switch (keycode) {
    // Catalan: Dead keys
    case CA_AT:
      dead_key_state = DK_ACUTE;
      return false;  

    case CA_AO:
      dead_key_state = DK_GRAVE;
      return false;  

    case CA_DI:
      dead_key_state = DK_DIERESIS;
      return false;  

    // Catalan: Direct keys
    case CA_CC:
      send_unicode_string(is_shifted ? "Ç" : "ç");
      return false;  

    case CA_NY:
      send_unicode_string(is_shifted ? "Ñ" : "ñ");
      return false;  

    case CA_PV:
      send_unicode_string("·");
      return false;  

    // OS Mode switching logic
    case P_SAVE:
      // This calls a routine to save mode to eeprom. Mode setting below
      // modifies the unicode_config struct directly, so this just sets it 
      // to the already configured value to store it.
      set_unicode_input_mode(unicode_config.input_mode);
      return false;

    case P_MODE:
      pilonsi_cycle_os_mode();
      return false;

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

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_pilonsi(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', '*', '*', '*',  '*', '*', '*', 'R', 'R'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_pilonsi(
    KC_Q,         KC_W,         KC_E,              KC_R,            KC_T,            KC_Y,            KC_U,             KC_I,            KC_O,           KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),      LSFT_T(KC_F),    KC_G,            KC_H,            LSFT_T(KC_J),     LCTL_T(KC_K),    LALT_T(KC_L),   LGUI_T(KC_QUOT),
    KC_Z,         ALGR_T(KC_X), KC_C,              KC_V,            KC_B,            KC_N,            KC_M,             KC_COMM,         ALGR_T(KC_DOT), KC_SLSH,
    U_NP,         U_NP,         LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(CAT, KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FUN, KC_DEL), U_NP,           U_NP
  ),
  [NAV] = LAYOUT_pilonsi(
    P_UND,   P_CUT,   P_CPY,   P_PST,   P_RDO,   P_RDO,   P_PST,   P_CPY,   P_CUT,   P_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    KC_ESC,  KC_ALGR, KC_BSPC, KC_DEL,  U_NA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [CAT] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    CA_DI,   CA_AT,   CA_AO,   CA_PV,   CA_NY,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    CA_CC,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [MEDIA] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, CW_TOGG,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    KC_BRID, KC_BRIU, U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MUTE, KC_MPLY, KC_MSTP, U_NP,    U_NP
  ),
  [NUM] = LAYOUT_pilonsi(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [SYM] = LAYOUT_pilonsi(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, RM_HUEU, RM_SATU, RM_VALU, RM_TOGG, RM_NEXT,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, P_OLED,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, RM_HUED, RM_SATD, RM_VALD, KC_ALGR, RM_PREV,
    U_NP,    U_NP,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [FUN] = LAYOUT_pilonsi(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, P_SAVE,  P_MODE,  P_VER,   QK_RBT,  QK_BOOT,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
};

