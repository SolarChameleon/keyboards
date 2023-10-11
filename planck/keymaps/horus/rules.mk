DEFERRED_EXEC_ENABLE = yes
CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes
NKRO_ENABLE = yes

MOUSE_SHARED_EP = no

EEPROM_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes

LEADER_ENABLE = yes

COMBO_ENABLE = yes

RAW_ENABLE = yes

CONSOLE_ENABLE = yes

ENCODER_ENABLE = yes


# RGB_MATRIX_SUPPORTED = yes
# BACKLIGHT_ENABLE = yes


SRC += util/log/log.c
SRC += feature/leader/process_sequences.c
# SRC += util/
# SRC += feature/
# SRC += override/


# EXTRAFLAGS  = -Wno-error=unused-variable
