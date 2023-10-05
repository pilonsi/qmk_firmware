// Copyright 2023 Pilonsi
// My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

    case U_CBM:
      if (record->event.pressed) {
        if (pilonsi_clipboard_mode == PILONSI_CB_MODE_MAC){
          pilonsi_clipboard_mode = PILONSI_CB_MODE_WIN;
        } else {
          pilonsi_clipboard_mode = PILONSI_CB_MODE_MAC;
        }
      }
      break;

    case KC_AGIN:
      if (record->event.pressed) {
        unregister_code16(KC_AGIN);
        switch (pilonsi_clipboard_mode) {
          case PILONSI_CB_MODE_WIN:
           tap_code16(C(KC_Y));
            break;
          
          case PILONSI_CB_MODE_MAC:
          default:
           tap_code16(SCMD(KC_Z));
        }
      } 
      break;


    case KC_PSTE:
      if (record->event.pressed) {
        unregister_code16(KC_PSTE);
        switch (pilonsi_clipboard_mode) {
          case PILONSI_CB_MODE_WIN:
           tap_code16(C(KC_V));
            break;
          
          case PILONSI_CB_MODE_MAC:
          default:
           tap_code16(LCMD(KC_V));
        }
      } 
      break;


    case KC_COPY:
      if (record->event.pressed) {
        unregister_code16(KC_COPY);
        switch (pilonsi_clipboard_mode) {
          case PILONSI_CB_MODE_WIN:
           tap_code16(C(KC_C));
            break;
          
          case PILONSI_CB_MODE_MAC:
          default:
           tap_code16(LCMD(KC_C));
        }
      } 
      break;


    case KC_CUT:
      if (record->event.pressed) {
        unregister_code16(KC_CUT);
        switch (pilonsi_clipboard_mode) {
          case PILONSI_CB_MODE_WIN:
           tap_code16(C(KC_X));
            break;
          
          case PILONSI_CB_MODE_MAC:
          default:
           tap_code16(LCMD(KC_X));
        }
      } 
      break;


    case KC_UNDO:
      if (record->event.pressed) {
        unregister_code16(KC_UNDO);
        switch (pilonsi_clipboard_mode) {
          case PILONSI_CB_MODE_WIN:
           tap_code16(C(KC_Z));
            break;
          
          case PILONSI_CB_MODE_MAC:
          default:
           tap_code16(LCMD(KC_Z));
        }
      } 
      break;

    case U_VER:
      if (record->event.pressed) {
        SEND_STRING(PILONSI_VERSION_STRING);
      }
      break;  

#ifdef OLED_ENABLE
    case U_OLED:
      if (record->event.pressed) {
        if (is_oled_on()) {
          oled_off();
        } else {
          oled_on();
        }
      }
      break;
#endif
