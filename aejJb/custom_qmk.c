// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "automouse.h"

#define THUMBS_UP_CODE_POINT 0x1F44D

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &delete_key_override,
    NULL,
};

static bool keeps_automouse_layer_active(uint16_t keycode) {
    switch (keycode) {
        case KC_MS_BTN1:
        case KC_MS_BTN2:
        case TOGGLE_SCROLL:
        case DRAG_SCROLL:
        case KC_LGUI:
        case KC_RGUI:
        case TG(AUTOMOUSE_LAYER):
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
    // automouse_disable() only removes a layer owned by Automouse. The layer
    // may also have been enabled directly by TG(AUTOMOUSE_LAYER).
    layer_off(AUTOMOUSE_LAYER);

    if (trackball_enabled) {
        automouse_set_device_enabled(AUTOMOUSE_DEVICE_TRACKBALL, true);
    }
    if (trackpad_enabled) {
        automouse_set_device_enabled(AUTOMOUSE_DEVICE_TRACKPAD, true);
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool automouse_layer_engaged = automouse_is_active() || layer_state_is(AUTOMOUSE_LAYER);

    if (record->event.pressed && automouse_layer_engaged && !keeps_automouse_layer_active(keycode)) {
        dismiss_automouse_preserving_enabled_devices();

        // Automouse normally records a press only after its layer is inactive.
        // Record it now so incidental motion cannot immediately reactivate it.
        if (!is_automouse_toggle_key(keycode)) {
            process_record_automouse(keycode, record);
        }
    }

    // Keep KC_F13 in Oryx as a durable placeholder, but emit 👍 from QMK.
    if (keycode == KC_F13) {
        if (record->event.pressed) {
            register_unicode(THUMBS_UP_CODE_POINT);
        }
        return false;
    }

    return true;
}
