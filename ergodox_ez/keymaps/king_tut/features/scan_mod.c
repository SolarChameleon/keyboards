#include "scan_mod.h"

#ifndef CUSTOM_SCANCODE_BASE
#define CUSTOM_SCANCODE_BASE 0xA5
#endif

// Function to transform a regular keycode to a custom scancode
uint16_t transform_to_custom_scancode(uint16_t keycode) {
    uint16_t custom_scancode = CUSTOM_SCANCODE_BASE + (keycode % (0xDF - CUSTOM_SCANCODE_BASE + 1));

    return custom_scancode;
}

