#ifndef LEADER_HASH_END_H
#define LEADER_HASH_END_H

#include <string.h>
#include "../features/leader_hash.h"
#include "../aliases.h"
#include "../features/feature_keycodes.h"
#include "quantum.h"

typedef struct {
    uint16_t* sequence;
    uint8_t size;
    const char* result_label;
} LeaderSequence;

void leader_hash_end_user(uint16_t leader_key);

#endif //LEADER_HASH_END_H