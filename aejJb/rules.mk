CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no

# Custom QMK: selective automouse, emoji, and Shift+Backspace behavior.
KEY_OVERRIDE_ENABLE = yes
UNICODE_COMMON = yes
# Include the custom file alongside the generated keymap so QMK can inspect
# its key override table without modifying Oryx's generated keymap.c.
INTROSPECTION_KEYMAP_C = custom_qmk.c
