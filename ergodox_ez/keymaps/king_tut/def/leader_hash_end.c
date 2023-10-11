#include "leader_hash_end.h"

// Define leader sequences with associated labels
LeaderSequence leader_sequences_1[] = {
    { (uint16_t[]){A_, V_}, 2, "send_name" },
    { (uint16_t[]){E_, M_}, 2, "send_email" },
};

LeaderSequence leader_sequences_2[] = {
    { (uint16_t[]){R_, B_}, 2, "reboot" }
};

LeaderSequence leader_sequences_3[] = {
    { (uint16_t[]){R_, B_}, 2, "reboot" }
};

const char* current_label;

// Result function to handle different actions
void result_generic(void) {
    uprintf("Current Label: %s\n", current_label);
    if (strcmp(current_label, "send_name") == 0) {
        SEND_STRING("Alexander von Stuelpnagel");
    }
    if (strcmp(current_label, "send_email") == 0) {
        SEND_STRING("a.solar.lizard@gmail.com");
    }
    if (strcmp(current_label, "reboot") == 0) {
        reset_keyboard();
    }
}

void leader_hash_end_user(uint16_t leader_key) {
    switch (leader_key) {
        case FT_LEADER_HASH_1:
            for (size_t i = 0; i < sizeof(leader_sequences_1) / sizeof(leader_sequences_1[0]); i++) {
                current_label = leader_sequences_1[i].result_label;
                if (leader_hash_is(leader_sequences_1[i].sequence, leader_sequences_1[i].size)) {
                    result_generic();
                }
            }
            break;
        case FT_LEADER_HASH_2:
            for (size_t i = 0; i < sizeof(leader_sequences_2) / sizeof(leader_sequences_2[0]); i++) {
                current_label = leader_sequences_2[i].result_label;
                if (leader_hash_is(leader_sequences_2[i].sequence, leader_sequences_2[i].size)) {
                    result_generic();
                }
            }
            break;
        case FT_LEADER_HASH_3:
            for (size_t i = 0; i < sizeof(leader_sequences_3) / sizeof(leader_sequences_3[0]); i++) {
                current_label = leader_sequences_3[i].result_label;
                if (leader_hash_is(leader_sequences_3[i].sequence, leader_sequences_3[i].size)) {
                    result_generic();
                }
            }
            break;
    }
}