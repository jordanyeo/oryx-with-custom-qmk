#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 26

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 95

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1

#define SERIAL_NUMBER "aejJb/AzmmLE"
#define LAYER_STATE_8BIT

#define NAVIGATOR_SCROLL_DIVIDER 50

#define NAVIGATOR_SCROLL_INVERT_X
#define NAVIGATOR_SCROLL_INVERT_Y
#define AUTOMOUSE_LAYER 2
#define AUTOMOUSE_TIMEOUT 180
#define AUTOMOUSE_THRESHOLD 21
#define AUTOMOUSE_ONESHOT
#define AUTOMOUSE_SCROLL_THRESHOLD AUTOMOUSE_THRESHOLD / NAVIGATOR_SCROLL_DIVIDER
#define RGB_MATRIX_STARTUP_SPD 60

// Custom QMK: selective automouse dismissal is handled in custom_qmk.c,
// so disable the module's unfiltered post-key timeout.
#undef AUTOMOUSE_TIMEOUT
#define AUTOMOUSE_TIMEOUT 65535

// Use ZSA's stock Navigator scrolling, including simultaneous X/Y movement
// for diagonal gestures. High-resolution wheel mode is broken on this Mac.
#undef POINTING_DEVICE_HIRES_SCROLL_ENABLE
#define WHEEL_EXTENDED_REPORT

// QMK's Unicode sender should always emit macOS Unicode Hex Input sequences.
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
