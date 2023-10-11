#include "process_rawhid_mod.h"

bool raw_modifying = false;

bool process_rawhid_mod(uint16_t keycode, keyrecord_t *record) {
    if (keycode == FT_RAW_MOD) {
        // FT_SCAN_MOD key pressed
        if (record->event.pressed) {
            raw_modifying = true;
            uprintf("raw_modifying: start\n");
        } else {
            uprintf("raw_modifying: end\n");
            raw_modifying = false;
        }
        return false;
    } else if (raw_modifying) {
        // FT_SCAN_MOD key is held down
        uint8_t data[3];
        // Convert the keycode and press status to Raw HID data
        if (record->event.pressed) {
            convert_keycode_to_raw_hid(keycode, true, data);
        } else {
            convert_keycode_to_raw_hid(keycode, false, data);
        }
        uprintf("Raw HID Data: [%02X %02X %02X]\n", data[0], data[1], data[2]);
        raw_hid_send(data, sizeof(data));
        return false;
    }
    return true;
}