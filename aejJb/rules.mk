CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no

# Custom QMK: keep automouse active for click, scroll, and Command controls.
SRC += selective_automouse.c
