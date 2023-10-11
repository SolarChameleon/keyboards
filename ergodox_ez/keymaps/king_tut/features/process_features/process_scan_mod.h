#ifndef PROCESS_SCAN_MOD_H
#define PROCESS_SCAN_MOD_H

#include "../scan_mod.h"
#include "../feature_keycodes.h"
#include "quantum.h"
#include "stdbool.h"

bool process_scan_mod(uint16_t keycode, keyrecord_t *record);

#endif //PROCESS_SCAN_MOD_H