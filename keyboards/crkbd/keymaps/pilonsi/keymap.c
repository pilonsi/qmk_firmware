// Copyright 2019 Manna Harbour
// Copyright 2021 HellSingCoder
// Copyright 2023 Pilonsi
// My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "pilonsi.c"

// OLED Configuration
#ifdef OLED_ENABLE
static void render_oled_primary(void) {
}

static void render_oled_secondary(void) {
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_270;
  }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_oled_primary();
  } else {
    render_oled_secondary();
  }

  return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
#include "process_record_user_common.c"
  }
  return true;
}
