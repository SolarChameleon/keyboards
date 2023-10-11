#include "leader_end.h"

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_H)){
        tap_code16(KC_0);
    }
}