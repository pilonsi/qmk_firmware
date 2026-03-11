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

// Switch unicode mode without saving to EEPROM
// We se the unicode settings saved to the EEPROM by QMK to restore our OS
// state and save unnecessary EEPROM writes.
void hostos_cycle(void) {
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

bool hostos_process_record(uint16_t keycode) {
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
    // OS Mode switching logic
    case P_SAVE:
      // This calls a routine to save mode to eeprom. Mode setting below
      // modifies the unicode_config struct directly, so this just sets it 
      // to the already configured value to store it.
      set_unicode_input_mode(unicode_config.input_mode);
      return false;
    case P_MODE:
      hostos_cycle();
      return false;
  }

  return false;
}
