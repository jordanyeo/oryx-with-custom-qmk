// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "automouse.h"

static bool keeps_automouse_layer_active(uint16_t keycode) {
    switch (keycode) {
        case KC_MS_BTN1:
        case KC_MS_BTN2:
        case TOGGLE_SCROLL:
        case DRAG_SCROLL:
        case KC_LGUI:
        case KC_RGUI:
            return true;
        default:
            return false;
    }
}

static bool is_automouse_toggle_key(uint16_t keycode) {
    switch (keycode) {
        case KC_AUTOMOUSE_TOGGLE:
        case KC_AUTOMOUSE_TOGGLE_TRACKBALL:
        case KC_AUTOMOUSE_TOGGLE_TRACKPAD:
            return true;
        default:
            return false;
    }
}

static void dismiss_automouse_preserving_enabled_devices(void) {
    bool trackball_enabled = automouse_get_device_enabled(AUTOMOUSE_DEVICE_TRACKBALL);
    bool trackpad_enabled  = automouse_get_device_enabled(AUTOMOUSE_DEVICE_TRACKPAD);

    automouse_disable();

    if (trackball_enabled) {
        automouse_set_device_enabled(AUTOMOUSE_DEVICE_TRACKBALL, true);
    }
    if (trackpad_enabled) {
        automouse_set_device_enabled(AUTOMOUSE_DEVICE_TRACKPAD, true);
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && automouse_is_active() && !keeps_automouse_layer_active(keycode)) {
        dismiss_automouse_preserving_enabled_devices();

        // Automouse normally records a press only after its layer is inactive.
        // Record it now so incidental motion cannot immediately reactivate it.
        if (!is_automouse_toggle_key(keycode)) {
            process_record_automouse(keycode, record);
        }
    }

    return true;
}
