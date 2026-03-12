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
#include "oneshot.h"
#include "hostos.h"
#include "catalan.h"

#define PILONSI_VERSION_STRING "15.0pre2"

enum layers { BASE, NUM, NAV, SYM, CAT, FUN };

enum combos { 
  QW_ALTSUPER,
  ER_CTRLSHFT,
  AS_ALT,
  DF_SHFT,
  ZX_GUI,
  CV_CTRL,
  OP_ALTSUPER,
  UI_CTRLSHFT,
  LQUOT_ALT,
  JK_SHFT,
  DOTSLSH_SUPER,
  MCOMM_CTRL,

  COMB_SYM,
  COMB_CAT
};

enum my_keycodes {
  // Custom settings
  P_MODE = SAFE_RANGE, // Cycle operating system mode
  P_SAVE,  // Save operating system mode
  P_OLED, // Toggle OLED
  P_VER,  // Show version string

  // OS dependent shortcuts
  P_RDO,
  P_PST,
  P_CPY,
  P_CUT,
  P_UND,

  // Callum oneshot implementation
  OS_SFT,
  OS_CTL,
  OS_ALT,
  OS_GUI,
  OS_AGUI,
  OS_CSFT,

  // Catalan characters
  CA_CC,  // Ç
  CA_AT,  // ´
  CA_AO,  // `
  CA_DI,  // ¨
  CA_PV,  // ·
  CA_EX,  // ¡
  CA_IN,  // ¿

  // Universal characters
  CA_NY,  // Ñ

  // Dummy keycodes to trigger layer switch combos
  CL_SYM1,
  CL_SYM2,
  CL_CAT1,
  CL_CAT2
};

#define LA_NAV MO(NAV)
#define LA_NUM MO(NUM)
#define LA_SYM MO(SYM)
#define LA_CAT MO(CAT)

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used
