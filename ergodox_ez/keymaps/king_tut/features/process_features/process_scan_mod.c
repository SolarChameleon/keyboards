#include "process_scan_mod.h"

bool scan_modifying = false;

bool process_scan_mod(uint16_t keycode, keyrecord_t *record) {
    if (keycode == FT_SCAN_MOD) {
        // FT_SCAN_MOD key pressed
        if (record->event.pressed) {
            scan_modifying = true;
            uprintf("scan_modifying: start\n");
        } else {
            uprintf("scan_modifying: end\n");
            scan_modifying = false;
        }
        return false;
    } else if (scan_modifying) {
        // FT_SCAN_MOD key is held down
        uint16_t custom_code = transform_to_custom_scancode(keycode);
        if (record->event.pressed) {
            uprintf("Registering keycode: %u, custom scancode: %u\n", keycode, custom_code);
            register_code(custom_code);
        } else {
            uprintf("Unregistering keycode: %u, custom scancode: %u\n", keycode, custom_code);
            unregister_code(custom_code);
        }
        return false;
    }
    return true;
}
