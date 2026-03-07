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
#include "catalan.h"

static enum dead_key_states dead_key_state = DK_NONE;

bool catalan_handle_dead_keys(uint16_t keycode, bool is_shifted) {
  bool handled = false;

	// Strip wrappers from keys
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

// Process unicode catalan keycodes and handle dead keys
// Returns true if a keycode was handled, false if not
bool catalan_process_record(uint16_t keycode, bool is_shifted) {
  // 2st pass checks for any pending dead key
  if (dead_key_state != DK_NONE) {
    if (catalan_handle_dead_keys(keycode, is_shifted)) {
      return true;
    }
  }

	// 1nd pass sends direct chars and sets the dead key var.
  switch (keycode) {
    case CA_AT:
      dead_key_state = DK_ACUTE;
      return true;  

    case CA_AO:
      dead_key_state = DK_GRAVE;
      return true;  

    case CA_DI:
      dead_key_state = DK_DIERESIS;
      return true;  

    // Catalan: Direct keys
    case CA_CC:
      send_unicode_string(is_shifted ? "Ç" : "ç");
      return true;  

    case CA_NY:
      send_unicode_string(is_shifted ? "Ñ" : "ñ");
      return true;  

    case CA_PV:
      send_unicode_string("·");
      return true;

		case CA_EX:
			send_unicode_string("¡");
			return true;

		case CA_IN:
			send_unicode_string("¿");
			return true;
  }

	return false;
}
