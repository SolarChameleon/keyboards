# feature.mk
FEATURE_DIR = features
PROCESS_FEATURE_DIR = $(FEATURE_DIR)/process_features
LIBRARY_DIR = lib

# LEADER_ENABLE = yes
LEADER_HASH_ENABLE = yes
SCAN_MOD_ENABLE = yes
RAW_ENABLE = yes
RAWHID_MOD_ENABLE = yes
COUNTER_KEYS_ENABLE = yes

SRC += $(FEATURE_DIR)/features.c

ifeq ($(LEADER_ENABLE), yes)
SRC += def/leader_end.c
endif

ifeq ($(LEADER_HASH_ENABLE),yes)
SRC += $(FEATURE_DIR)/leader_hash.c
SRC += $(PROCESS_FEATURE_DIR)/process_leader_hash.c
SRC += def/leader_hash_end.c
endif

ifeq ($(SCAN_MOD_ENABLE),yes)
SRC += $(FEATURE_DIR)/scan_mod.c
SRC += $(PROCESS_FEATURE_DIR)/process_scan_mod.c
endif

ifeq ($(RAWHID_MOD_ENABLE),yes)
SRC += $(FEATURE_DIR)/rawhid_mod.c
SRC += $(PROCESS_FEATURE_DIR)/process_rawhid_mod.c
endif

ifeq ($(COUNTER_KEYS_ENABLE),yes)
SRC += $(FEATURE_DIR)/counter_keys.c
SRC += $(PROCESS_FEATURE_DIR)/process_counter_keys.c
SRC += $(LIBRARY_DIR)/keymap_ascii.c
endif