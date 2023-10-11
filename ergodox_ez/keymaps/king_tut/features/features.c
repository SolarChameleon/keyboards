#include "features.h"

#ifdef LEADER_HASH_ENABLE
#    include "process_features/process_leader_hash.h"
#endif

#ifdef SCAN_MOD_ENABLE
#    include "process_features/process_scan_mod.h"
#endif

#ifdef RAWHID_MOD_ENABLE
#    include "process_features/process_rawhid_mod.h"
#endif

#ifdef COUNTER_KEYS_ENABLE
#    include "process_features/process_counter_keys.h"
#endif

bool process_record_features(keyrecord_t *record) {
    uint16_t keycode = get_record_keycode(record, true);
    if (!(
#ifdef LEADER_HASH_ENABLE
    process_leader_hash(keycode, record) &&
#endif
#ifdef SCAN_MOD_ENABLE
    process_scan_mod(keycode, record) &&
#endif
#ifdef RAWHID_MOD_ENABLE
    process_rawhid_mod(keycode, record) &&
#endif
#ifdef COUNTER_KEYS_ENABLE
    process_counter_keys(keycode, record) &&
#endif
            true)) {
        return false;
    }

    switch (keycode) {
    default:
        break;
    }

    return true;
}

void feature_task(void) {
#ifdef LEADER_HASH_ENABLE
    leader_hash_task();
#endif
}