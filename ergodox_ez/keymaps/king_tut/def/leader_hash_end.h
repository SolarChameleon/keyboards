#ifndef LEADER_HASH_END_H
#define LEADER_HASH_END_H

#include "../features/leader_hash.h"
#include "quantum.h"
#include <string.h>
#include "../aliases.h"

typedef struct {
    uint16_t* sequence;
    uint8_t size;
    const char* result_label;
} LeaderSequence;

void leader_hash_end_user(void);

#endif //LEADER_HASH_END_H