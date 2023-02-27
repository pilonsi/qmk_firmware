// Copyright 2019 Manna Harbour
// Copyright 2023 Pilonsi
// My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "pilonsi.h"

#include "clipboard_override.c"
#ifdef TAPPING_TERM_PER_KEY
#include "tap_hold_per_key.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_pilonsi(
    KC_Q,         KC_W,         KC_E,              KC_R,            KC_T,            KC_Y,            KC_U,             KC_I,            KC_O,           KC_P,
    LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),      LSFT_T(KC_F),    KC_G,            KC_H,            LSFT_T(KC_J),     LCTL_T(KC_K),    LALT_T(KC_L),   LGUI_T(KC_QUOT),
    KC_Z,         ALGR_T(KC_X), KC_C,              KC_V,            KC_B,            KC_N,            KC_M,             KC_COMM,         ALGR_T(KC_DOT), KC_SLSH,
    U_NP,         U_NP,         LT(MEDIA, KC_ESC), LT(NAV, KC_SPC), LT(EXT, KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FUN, KC_DEL), U_NP,           U_NP
  ),
  [NAV] = LAYOUT_pilonsi(
    U_NA,          U_NA,           U_NA,          U_NA,        U_NU,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    LGUI_T(U_UND), LALT_T(U_CUT),  LCTL_T(U_CPY), LSFT(U_PST), U_RDO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
    KC_ESC,        ALGR_T(KC_ENT), KC_BSPC,       KC_DEL,      U_NU,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    U_NP,          U_NP,           U_NA,          U_NA,        U_NU,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [EXT] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    U_NU,    KC_ESC,  KC_DEL,  U_NU,    KC_CAPS,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_ENT,  KC_BSPC, KC_DEL,  U_NP,    U_NP
  ),
  [MEDIA] = LAYOUT_pilonsi(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MUTE, KC_MPLY, KC_MSTP, U_NP,    U_NP
  ),
  [NUM] = LAYOUT_pilonsi(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_DOT,  KC_0,    KC_MINS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [SYM] = LAYOUT_pilonsi(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, U_CBM,   U_NA,    U_NA,    QK_RBT,  QK_BOOT,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_LPRN, KC_RPRN, KC_UNDS, U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
  [FUN] = LAYOUT_pilonsi(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,
    U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP
  ),
};

