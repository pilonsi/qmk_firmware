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

#include "pilonsi.c"

/*
// Master
#define LAYER_LED_RIGHT_0 g_led_config.matrix_co[0][0]
#define LAYER_LED_RIGHT_1 g_led_config.matrix_co[1][0]
#define LAYER_LED_RIGHT_2 g_led_config.matrix_co[2][0]
#define LAYER_LED_SYM     g_led_config.matrix_co[3][5]
#define LAYER_LED_NUM     g_led_config.matrix_co[3][4]
#define LAYER_LED_FUN     g_led_config.matrix_co[3][3]
#define CAPS_LED          g_led_config.matrix_co[1][1]

// Slave
#define LAYER_LED_LEFT_0  21
#define LAYER_LED_LEFT_1  g_led_config.matrix_co[4][5]
#define LAYER_LED_LEFT_2  g_led_config.matrix_co[4][6]
#define LAYER_LED_MEDIA   g_led_config.matrix_co[5][7]
#define LAYER_LED_NAV     g_led_config.matrix_co[4][7]
#define LAYER_LED_CAT     g_led_config.matrix_co[3][7]

void pilonsi_set_layer_indicators(uint8_t layer, uint8_t r, uint8_t g, uint8_t b) {
	//rgb_matrix_set_color(layer, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_LEFT_0, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_LEFT_1, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_LEFT_2, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_RIGHT_0, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_RIGHT_1, r, g, b);
	//rgb_matrix_set_color(LAYER_LED_RIGHT_2, r, g, b);
}

// Dynamic layer status reporting using the per-key RGB
bool rgb_matrix_indicators_user(void) {
	uint8_t layer = get_highest_layer(layer_state);

	if (host_keyboard_led_state().caps_lock) {
		rgb_matrix_set_color(CAPS_LED, RGB_PURPLE);
	}

	switch (layer) {
		case MEDIA:
			pilonsi_set_layer_indicators(LAYER_LED_MEDIA, RGB_MAGENTA);
			break;
		case NAV:
			pilonsi_set_layer_indicators(LAYER_LED_NAV, RGB_CYAN);
			break;
		case CAT:
			pilonsi_set_layer_indicators(LAYER_LED_CAT, RGB_ORANGE);
			break;
		case SYM:
			pilonsi_set_layer_indicators(LAYER_LED_SYM, RGB_GREEN);
			break;
		case NUM:
			pilonsi_set_layer_indicators(LAYER_LED_NUM, RGB_BLUE);
			break;
		case FUN:
			pilonsi_set_layer_indicators(LAYER_LED_FUN, RGB_RED);
			break;
	}

	return true;
}
*/
