#ifndef ALIASES_H
#define ALIASES_H
#pragma once

#include "quantum.h"

enum planck_keycodes {
    EBTN = QK_USER_1,
};

enum leader_keys {
    LD_1 = QK_LEADER,
    LD_2 = PB_1,
    LD_3 = PB_2,
};

enum shorthand_letter {
    A_ = KC_A,
    B_,
    C_,
    D_,
    E_,
    F_,
    G_,
    H_,
    I_,
    J_,
    K_,
    L_,
    M_,
    N_,
    O_,
    P_,
    Q_,
    R_,
    S_,
    T_,
    U_,
    V_,
    W_,
    X_,
    Y_,
    Z_,
};

enum shorthand_number {
    _1 = KC_1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _0,
};

enum shorthand_function {
    _F1 = KC_F1,
    _F2,
    _F3,
    _F4,
    _F5,
    _F6,
    _F7,
    _F8,
    _F9,
    _F10,
    _F11,
    _F12,
};

#define CLN_ KC_COLN
#define SCLN_ KC_SCLN
#define CM_ KC_COMM
#define DQ_ KC_DQUO
#define DT_ KC_DOT
#define QT_ KC_DOT
#define AO_ LALT_T(KC_O)
#define GE_ LGUI_T(KC_E)
#define CU_ LCTL_T(KC_U)
#define LS_ KC_LSFT
#define BSPC KC_BSPC
#define ENT KC_ENT
#define SPC KC_SPC

#define ArL  KC_LEFT
#define ArD  KC_DOWN
#define ArU  KC_UP
#define ArR  KC_RIGHT
#define HOME KC_HOME
#define END  KC_END
#define P_UP  KC_PGUP
#define P_DN  KC_PGDN
#define NTAB RCTL(KC_TAB)
#define PTAB RCTL(RSFT(KC_TAB))
#define WFwd    KC_WFWD
#define WBk     KC_WBAK

#define XXX KC_NO
#define ___ KC_TRNS
#define FROM KC_TRNS

#define STAB LSFT_T(KC_TAB)
#define NMBR MO(2)
#define NV_SPC LT(1,KC_SPC)
#define MACRO MO(4)
#define LEAD KC_LEAD
#define MEDIA MO(5)
#define PLAY KC_MPLY
#define STOP KC_MSTP
#define NXT KC_MNXT
#define PRV KC_MPRV
#define VDN KC_VOLD
#define VUP KC_VOLU

#endif /* ALIASES_H */
