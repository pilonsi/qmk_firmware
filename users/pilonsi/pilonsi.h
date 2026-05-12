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

#pragma once

#include QMK_KEYBOARD_H
#include "hostos.h"
#include "catalan.h"

#define PILONSI_VERSION_STRING "14.2"

enum layers { BASE, MEDIA, NAV, CAT, SYM, NUM, FUN, CFG };

enum my_keycodes {
  // Custom keycodes
  P_OLED = SAFE_RANGE, // Toggle OLED
  P_VER,               // Show version string

  // Host OS related keycodes
  HO_MODE, // Cycle OS mode
  HO_SAVE, // Save OS mode
  HO_RDO,
  HO_PST,
  HO_CPY,
  HO_CUT,
  HO_UND,

  // Catalan characters
  CA_CC,   // Ç
  CA_AT,   // ´
  CA_AO,   // `
  CA_DI,   // ¨
  CA_PV,   // ·
  CA_EX,   // ¡
  CA_IN,   // ¿

  // Universal characters
  CA_NY,   // Ñ
};

// Shorten the verbose mod-tap and layer-tap keys
#define M_AGUI  LGUI_T(KC_A)
#define M_SALT  LALT_T(KC_S)
#define M_DCTL  LCTL_T(KC_D)
#define M_FSFT  LSFT_T(KC_F)
#define M_JSFT  LSFT_T(KC_J)
#define M_KCTL  LCTL_T(KC_K)
#define M_LALT  LALT_T(KC_L)
#define M_QTGUI LGUI_T(KC_QUOT)
#define M_XAGR  ALGR_T(KC_X)
#define M_DTAGR ALGR_T(KC_DOT)

#define M_ESCM  LT(MEDIA, KC_ESC)
#define M_SPCN  LT(NAV,   KC_SPC)
#define M_TABC  LT(CAT,   KC_TAB)
#define M_ENTS  LT(SYM,   KC_ENT)
#define M_BSPU  LT(NUM,   KC_BSPC)
#define M_DELF  LT(FUN,   KC_DEL)

#define M_CFG   MO(CFG)

#define U_NP    KC_NO // key is not present
#define U_NA    KC_NO // present but not available for use
#define U_NU    KC_NO // available but not used
#define U______ KC_NO // this is the key held to activate this layer
