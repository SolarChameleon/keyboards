#include "process_sequences.h"

void leader_end_user(void) {
    #ifdef FEATURE_FLAG_DYNAMIC_MACRO_OVERRIDE
    if (leader_sequence_dynamic_macro()) {
        log_event(LOG_LEVEL_INFO, "leader_sequence_dynamic_macro");
        return;
    }
    #endif
}

bool leader_sequence_dynamic_macro(void) {
    // Dynamic Macro
    // Start Recording
    if (leader_sequence_one_key(LD_2, A_)) {
        keyrecord_t record = {0};
        record.event.pressed = true;
        record.event.key.row = 0;
        record.event.key.col = 0;
        keypos_t key = {0};
        key.row = 0;
        key.col = 0;
        record.event.key = key;

        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_START_1, &record);
        log_event(LOG_LEVEL_INFO, "leader_sequence_dynamic_macro: start");
        return true;
    }

    // Stop Recording
    if (leader_sequence_one_key(LD_2, B_)) {
        keyrecord_t record = {0};
        record.event.pressed = true;
        record.event.key.row = 0;
        record.event.key.col = 0;
        keypos_t key = {0};
        key.row = 0;
        key.col = 0;
        record.event.key = key;

        process_dynamic_macro(QK_DYNAMIC_MACRO_RECORD_STOP, &record);
        log_event(LOG_LEVEL_INFO, "leader_sequence_dynamic_macro: stop");
        return true;
    }

    // Play Recording
    if (leader_sequence_one_key(LD_2, C_)) {
        keyrecord_t record = {0};
        record.event.pressed = true;
        record.event.key.row = 0;
        record.event.key.col = 0;
        keypos_t key = {0};
        key.row = 0;
        key.col = 0;
        record.event.key = key;

        process_dynamic_macro(QK_DYNAMIC_MACRO_PLAY_1, &record);
        log_event(LOG_LEVEL_INFO, "leader_sequence_dynamic_macro: play");
        return true;
    }

    return false;
}
