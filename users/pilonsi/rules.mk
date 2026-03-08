# Copyright 2023-2026 Pilonsi
# My personal 36-key layout

# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 2 of the License, or (at your option)
# any later version. This program is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
# Public License for more details. You should have received a copy of the GNU
# General Public License along with this program. If not, see
# <http://www.gnu.org/licenses/>.

SRC += oneshot.c
SRC += hostos.c
SRC += catalan.c

MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = no
CAPS_WORD_ENABLE = yes
SEND_STRING_ENABLE = yes
UNICODE_ENABLE = yes

# Optimizations
LTO_ENABLE = yes
VIA_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
