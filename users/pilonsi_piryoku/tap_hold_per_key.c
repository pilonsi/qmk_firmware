// Copyright 2021, Pilonsi
// My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Home row mods
    case LGUI_T(KC_A):
    case LGUI_T(KC_QUOT):
      return TAPPING_TERM + 50;
    case LALT_T(KC_S):
    case LALT_T(KC_L):
      return TAPPING_TERM + 40;
    case LCTL_T(KC_D):
    case LCTL_T(KC_K):
      return TAPPING_TERM;
    case LSFT_T(KC_F):
    case LSFT_T(KC_J):
      return TAPPING_TERM - 20;

    // Thumb keys
    case LT(MESH, KC_ESC):
    case LT(FUN, KC_DEL):
      return TAPPING_TERM;
    case LT(NAV, KC_SPC):
    case LT(NUM, KC_BSPC):
      return TAPPING_TERM - 20;
    case LT(CAT, KC_TAB):
    case LT(SYM, KC_ENT):
      return TAPPING_TERM - 20;

    default:
      return TAPPING_TERM;
  }
}

