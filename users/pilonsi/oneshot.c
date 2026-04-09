#include "oneshot.h"

static inline void cancel_oneshot(oneshot_state *state, uint16_t mod) {
  *state = os_up_unqueued;
  unregister_code16(mod);
}

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code16(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code16(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_press(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                cancel_oneshot(state, mod);
            } else if (is_oneshot_cancel_press_permissive(keycode) && *state == os_up_queued) {
                // Cancel oneshot on designated cancel keydown only if the 
                // modifier was released. Hold + cancel key still yields
                // the modded cancel key.
                cancel_oneshot(state, mod);
            }
        } else {
            if (is_oneshot_cancel_release(keycode) && *state != os_up_unqueued) {
              // Cancel oneshot on designated cancel keyup.
              cancel_oneshot(state, mod);
            } else if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code16(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
