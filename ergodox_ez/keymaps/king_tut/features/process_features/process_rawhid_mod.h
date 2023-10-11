#ifndef PROCESS_RAWHID_MOD_H
#define PROCESS_RAWHID_MOD_H

#include "quantum.h"
#include "../feature_keycodes.h"
#include "../rawhid_mod.h"
#include "stdbool.h"

bool process_rawhid_mod(uint16_t keycode, keyrecord_t *record);

#endif //PROCESS_RAWHID_MOD_H