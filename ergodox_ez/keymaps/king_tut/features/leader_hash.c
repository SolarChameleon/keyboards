#include "leader_hash.h"

#ifndef HASHING_TIMEOUT
#    define HASHING_TIMEOUT 500
#endif

//Leader combo key:
//  any key pressed with the leader combo key starts a leader sequence
//  using the combined key as the start of the sequence

// Leader hash stuff
bool     leader_hashing                = false;
uint16_t leader_hashing_time           = 0;
uint32_t leader_hash            = 0;
uint8_t  leader_hash_index      = 0;

// callbacks
__attribute__((weak)) void leader_hash_start_user(void) {}
__attribute__((weak)) void leader_hash_end_user(void) {}

void leader_hash_start(void) {
    uprint("Leader Hash start\n");
    if (leader_hashing) {
        return;
    }
    leader_hash_start_user();
    leader_hashing              = true;
    leader_hashing_time         = timer_read();
    leader_hash_index    = 0;
    leader_hash          = 0;
}

void leader_hash_end(void) {
    leader_hashing = false;
    uprintf("Final Hash: %u\n", leader_hash);
    leader_hash_end_user();
}

bool leader_hash_active(void) {
    return leader_hashing;
}

void leader_hash_task(void) {
    if (leader_hash_active() && leader_hash_timed_out()) {
        leader_hash_end();
    }
}

uint32_t leader_hashing_function(uint16_t keycode, uint8_t index, uint32_t hash) {
    hash = ((hash << 5) | (hash >> 27)) ^ keycode;
    return hash;
}

void leader_hash_reset_timer(void) {
    leader_hashing_time = timer_read();
}

bool leader_hash_add(uint16_t keycode) {

#if defined(LEADER_HASH_NO_TIMEOUT)
    if (leader_hash_index == 0) {
        leader_hash_reset_timer();
    }
#endif

    // Add the keycode and index to the hash
    leader_hash = leader_hashing_function(keycode, leader_hash_index, leader_hash);
    leader_hash_index++;

    return true;
}

bool leader_hash_timed_out(void) {
#if defined(LEADER_HASH_NO_TIMEOUT)
    return leader_hash_index > 0 && timer_elapsed(leader_hashing_time) > HASHING_TIMEOUT;
#else
    return timer_elapsed(leader_hashing_time) > HASHING_TIMEOUT;
#endif
}


uint32_t generate_hash(uint16_t keycodes[], uint8_t size) {
    uint32_t hash = 0;

    for (uint8_t i = 0; i < size; i++) {
        // Call the hashing function for each keycode in the array
        hash = leader_hashing_function(keycodes[i], i, hash);
    }

    return hash;
}

bool leader_hash_is(uint16_t keycodes[], uint8_t size) {
    if (leader_hash_index != size) {
        return false;
    }
    uint32_t hash = generate_hash(keycodes, size);
    return leader_hash == hash;
}