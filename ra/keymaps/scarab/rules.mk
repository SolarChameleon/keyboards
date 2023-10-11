#rules.mk
DEFERRED_EXEC_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
NKRO_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes
COMBO_ENABLE = yes
LEADER_ENABLE = yes
SWAP_HANDS_ENABLE = yes
TAP_DANCE_ENABLE = no

OS_DETECTION_ENABLE = yes
CONSOLE_ENABLE = yes
RAW_ENABLE = yes

#FEATURES
LOGGING_ENABLE = yes
HID_CONTROLLER_ENABLE = yes
MOD_KEYS_ENABLE = yes

LEADER_MULTIKEY_ENABLE = yes
LEADER_SCANMOD_ENABLE = yes
#LEADER_HASH_ENABLE = yes

FEATURE_KEYS_ENABLE = yes
COUNTER_KEYS_ENABLE = yes

KEYBOARD_DIR = keyboards/ra
KEYMAP_DIR = $(KEYBOARD_DIR)/keymaps/scarab
FEATURE_DIR = $(KEYMAP_DIR)/feature
include $(KEYMAP_DIR)/feature/feature.mk