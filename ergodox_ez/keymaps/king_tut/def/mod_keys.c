#include "mod_keys.h"

custom_mod_key_t custom_mod_keys[] = {
    {KC_COLN,      KC_SCLN,         KC_LSFT},
    {KC_DQUO,      KC_QUOT,         KC_LSFT},
    {KC_DOT,       KC_EXCLAIM,      KC_LSFT},
    {KC_COMM,      KC_QUES,         KC_LSFT},
    {MO(4),        RGUI(KC_TAB),    KC_LGUI},
    {MO(4),        RALT(KC_TAB),    KC_LALT},
    {MO(4),        RCTL(KC_TAB),    KC_LCTL},
};

uint8_t NUM_CUSTOM_MOD_KEYS = sizeof(custom_mod_keys) / sizeof(custom_mod_key_t);
