# Copyright 2019 Manna Harbour, Pilonsi
# My personal 36-key layout based off a modified version of the wonderful Miryoku layout, by Manna Harbour
# https://github.com/manna-harbour/miryoku

MOUSEKEY_ENABLE = no # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = no # Auto Shift

SRC += pilonsi_piryoku.c # keymap

# alternative layouts:

# clipboard
ifneq ($(strip $(PIRYOKU_CLIPBOARD)),)
  OPT_DEFS += -DPIRYOKU_CLIPBOARD_$(PIRYOKU_CLIPBOARD)
endif

# subset mappings
ifneq ($(strip $(MIRYOKU_MAPPING)),)
  OPT_DEFS += -DMIRYOKU_MAPPING_$(MIRYOKU_MAPPING)
endif
