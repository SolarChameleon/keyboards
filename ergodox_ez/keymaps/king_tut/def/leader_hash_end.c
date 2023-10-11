#include "leader_hash_end.h"

// Define leader sequences with associated labels
LeaderSequence leader_sequences[] = {
    { (uint16_t[]){A_, V_, S_}, 3, "send_name" },
    { (uint16_t[]){C_}, 1, "click" },
    { (uint16_t[]){C_, C_}, 2, "double_click" },
    { (uint16_t[]){C_, C_, C_}, 3, "double_click" },
    { (uint16_t[]){C_, C_, C_}, 3, "copy" },
    { (uint16_t[]){C_, C_, P_}, 3, "double_click" },
    { (uint16_t[]){C_, C_, P_}, 3, "paste" },
    { (uint16_t[]){R_, B_}, 2, "reboot" },
};

const char* current_label;

// Result function to handle different actions
void result_generic(void) {
    uprintf("Current Label: %s\n", current_label);
    if (strcmp(current_label, "send_name") == 0) {
        SEND_STRING("Alexander von Stuelpnagel");
    }
    if (strcmp(current_label, "click") == 0) {
        tap_code16(KC_BTN1);
    }
    if (strcmp(current_label, "double_click") == 0) {
        tap_code16(KC_BTN1);
        _delay_ms(100);
        tap_code16(KC_BTN1);
    }
    if (strcmp(current_label, "copy") == 0) {
        tap_code16(RCTL(C_));
    }
    if (strcmp(current_label, "paste") == 0) {
        tap_code16(RCTL(V_));
    }
    if (strcmp(current_label, "paste") == 0) {
        soft_reset_keyboard();
    }
}

void leader_hash_end_user(void) {
    uprint("Hash end\n");
    for (size_t i = 0; i < sizeof(leader_sequences) / sizeof(leader_sequences[0]); i++) {
        current_label = leader_sequences[i].result_label;
        if (leader_hash_is(leader_sequences[i].sequence, leader_sequences[i].size)) {
            result_generic();
        }
    }
}
