#ifndef FEATURE_KEYCODES_H
#define FEATURE_KEYCODES_H

#include "keycodes.h"

enum feature_keycodes {
    FEATURE_KEYCODES = QK_PROGRAMMABLE_BUTTON_1,
    FT_LEADER_HASH,
    FT_RAW_MOD,
    FT_SCAN_MOD,
    COUNTER_TARE,
    COUNTER_INCR,
    COUNTER_DECR,
    COUNTER_VALUE,
};

enum feature_aliases {
    LHASH = FT_LEADER_HASH,
    
    MDRAW = FT_RAW_MOD,
    
    MDSCN = FT_SCAN_MOD,

    XTARE = COUNTER_TARE,
    XINCR = COUNTER_INCR,
    XDECR = COUNTER_DECR,
    XVALU = COUNTER_VALUE
};

#endif