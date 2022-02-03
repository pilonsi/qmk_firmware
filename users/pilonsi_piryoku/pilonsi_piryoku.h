// Copyright 2019 Manna Harbour, Pilonsi
// My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include QMK_KEYBOARD_H

enum layers { BASE, MESH, NAV, CAT, SYM, NUM, FUN };

/* Keycodes */

// Miryoku unused keycodes
#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

// Miryoku clipboard options (Swapped default)
#if defined PILONSI_CLIPBOARD_FUN
#define U_RDO KC_AGIN
#define U_PST KC_PSTE
#define U_CPY KC_COPY
#define U_CUT KC_CUT
#define U_UND KC_UNDO
#elif defined PILONSI_CLIPBOARD_MAC
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)
#elif defined PILONSI_CLIPBOARD_CUA
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#else
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)
#endif

// Catalan keycodes (Require US-Intl. layout)
#define CA_LCLL ALGR(KC_LBRC) // « (Cometes llatines obertes)
#define CA_ENYA ALGR(KC_N)    // Ñ (Enya)
#define CA_OEXL ALGR(KC_1)    // ¡ (Exclamació oberta)
#define CA_OINT ALGR(KC_SLSH) // ¿ (Interrogació oberta)
#define CA_RCLL ALGR(KC_RBRC) // » (Cometes llatines tancades)
#define CA_PVOL KC_NO         // · (Punt volat) [Not present on US-Intl. layout, looking for the less painful workaround)
#define CA_CETR ALGR(KC_COMM) // Ç (Ce trencada)
#define CA_ACTA KC_QUOT       // ´ (Accent tancat)
#define CA_ACOB KC_GRV        // ` (Accent obert)
#define CA_DIER S(KC_QUOT)    // ¨ (Dièresi)
#define CA_LLAE KC_NO         // Æ (Lligadura d'a i e) [Not present on US-Intl. layout, looking for the less painful workaround)
#define CA_LLOE KC_NO         // Œ (Lligadura d'o i e) [Not present on US-Intl. layout, looking for the less painful workaround)
#define CA_ACCF S(KC_6)       // ^ (Accent circumflex)
