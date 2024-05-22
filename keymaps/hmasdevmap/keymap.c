// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

/* layer name */
enum keymap_layer {
    KL_QWERTY = 0,
    KL_NORMAN,
    KL_OPE,
    KL_FUN,
    KL_SYMNUM,
};
/* layer end */


/* macro start */
enum cutom_keycodes {
    CKC_BE=SAFE_RANGE,
    CKC_FU,
    CKC_HA,
    CKC_IR,
    CKC_KI,
    CKC_NN,
    CKC_NNN,
    CKC_NU,
    CKC_NYU,
    CKC_RO,
    CKC_RYA,
    CKC_RYU,
    CKC_RYO,
    CKC_WA,
    CKC_WO,
    CKC_YOU,
    CKC_ZA,
    CKC_L_ARROW,
    CKC_R_ARROW,
    /* PYTHON */
    CKC_PYTHON,
    /* PYTHON COMMENT */
    CKC_PY_NOQA,
    CKC_PY_TYPE_IGNORE,
    /* SAFE RANGE */
    HM_SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_BE: if (record->event.pressed) { SEND_STRING("be"); } return false; break;
        case CKC_FU: if (record->event.pressed) { SEND_STRING("fu"); } return false; break;
        case CKC_HA: if (record->event.pressed) { SEND_STRING("ha"); } return false; break;
        case CKC_IR: if (record->event.pressed) { SEND_STRING("ir"); } return false; break;
        case CKC_KI: if (record->event.pressed) { SEND_STRING("ki"); } return false; break;
        case CKC_NN: if (record->event.pressed) { SEND_STRING("nn"); } return false; break;
        case CKC_NNN: if (record->event.pressed) { SEND_STRING("nnn"); } return false; break;
        case CKC_NU: if (record->event.pressed) { SEND_STRING("nu"); } return false; break;
        case CKC_NYU: if (record->event.pressed) { SEND_STRING("nyu"); } return false; break;
        case CKC_RO: if (record->event.pressed) { SEND_STRING("ro"); } return false; break;
        case CKC_RYA: if (record->event.pressed) { SEND_STRING("rya"); } return false; break;
        case CKC_RYU: if (record->event.pressed) { SEND_STRING("ryu"); } return false; break;
        case CKC_RYO: if (record->event.pressed) { SEND_STRING("ryo"); } return false; break;
        case CKC_WA: if (record->event.pressed) { SEND_STRING("wa"); } return false; break;
        case CKC_WO: if (record->event.pressed) { SEND_STRING("wo"); } return false; break;
        case CKC_YOU: if (record->event.pressed) { SEND_STRING("you"); } return false; break;
        case CKC_ZA: if (record->event.pressed) { SEND_STRING("za"); } return false; break;
        case CKC_L_ARROW: if (record->event.pressed) { SEND_STRING("<- "); } return false; break;
        case CKC_R_ARROW: if (record->event.pressed) { SEND_STRING("-> "); } return false; break;
        // PYTHON
        case CKC_PYTHON: if (record->event.pressed) { SEND_STRING("python "); } return false; break;
        // PYTHON COMMENT
        case CKC_PY_NOQA: if (record->event.pressed) { SEND_STRING("  # noqa"); } return false; break;
        case CKC_PY_TYPE_IGNORE: if (record->event.pressed) { SEND_STRING("  # type' ignore"); } return false; break;
        default: return true; break;
    };
    return true;
};
/* macro end */


/* tap dance start */
enum {
    TD_BRACKET_L = 0,
    TD_BRACKET_R,
    TD_QUOTE,
    TD_3_QUOTE,
};

void BRACKET_DANCE_L(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("*");}
    else if(state->count == 2){SEND_STRING("]");}
    else if(state->count == 3){SEND_STRING("}");}
};
void BRACKET_DANCE_R(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("(");}
    else if(state->count == 2){SEND_STRING("\\");}
    else if(state->count == 3){SEND_STRING("|");}
};
void QUOTE_DANCE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("&");}
    else if(state->count == 2){SEND_STRING("@");}
    else if(state->count == 3){SEND_STRING("{");}
};
void THREE_QUOTE_DANCE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("&&&");}
    else if(state->count == 2){SEND_STRING("@@@");}
    else if(state->count == 3){SEND_STRING("{{{");}
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACKET_L] = ACTION_TAP_DANCE_FN (BRACKET_DANCE_L),
    [TD_BRACKET_R] = ACTION_TAP_DANCE_FN (BRACKET_DANCE_R),
    [TD_QUOTE]     = ACTION_TAP_DANCE_FN (QUOTE_DANCE),
    [TD_3_QUOTE]   = ACTION_TAP_DANCE_FN (THREE_QUOTE_DANCE),
};
/* tap dance end */


/* combo start */
const uint16_t PROGMEM KC_COMM_K[] = {LT(KL_OPE, KC_COMM), KC_K, COMBO_END};
const uint16_t PROGMEM KC_COMM_B [] = {LT(KL_OPE, KC_COMM), KC_B, COMBO_END};
const uint16_t PROGMEM KC_HJ[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM KC_YN[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM KC_NM[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM KC_HM[] = {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM KC_ZX[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM KC_XC[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM KC_XCV[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM KC_QW[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM KC_HOME_LEFT[] = {KC_HOME, KC_LEFT, COMBO_END};
const uint16_t PROGMEM KC_L_BRACKET_R_BRACKET[] = {TD(TD_BRACKET_L), TD(TD_BRACKET_R), COMBO_END};
const uint16_t PROGMEM KC_BSPC_DOT[] = {KC_BSPC, KC_DOT, COMBO_END};

const uint16_t PROGMEM KC_QWER[] = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM KC_QWDF[] = {KC_Q, KC_W, KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(KC_COMM_B, KC_MINS),  // qwerty
    COMBO(KC_COMM_K, KC_MINS),  // mod norman
    COMBO(KC_HJ, KC_SPACE),     // qwerty
    COMBO(KC_YN, KC_SPACE),     // mod norman
    COMBO(KC_NM, KC_BSPC),      // qwerty
    COMBO(KC_HM, KC_BSPC),      // mod norman
    COMBO(KC_ZX, KC_TAB),
    COMBO(KC_XC, KC_EQL),
    COMBO(KC_XCV, KC_INT3),
    COMBO(KC_QW, KC_ESC),
    COMBO(KC_HOME_LEFT, KC_ENT),
    COMBO(KC_BSPC_DOT, KC_ENT),
    COMBO(KC_L_BRACKET_R_BRACKET, KC_DEL),

    COMBO(KC_QWER, DF(KL_NORMAN)),     // qwerty
    COMBO(KC_QWDF, DF(KL_QWERTY)),     // mod norman
};
/* combo end */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // QWERTY
    [KL_QWERTY] = LAYOUT(
        KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                KC_Y,                KC_U,                KC_I,                KC_O,                LGUI_T(KC_P),
        KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                KC_H,                KC_J,                KC_K,                KC_L,                KC_SCLN,
        KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,                KC_N,                KC_M,                CKC_KI,              CKC_NN,              LCTL_T(KC_SLSH),
        LSFT_T(KC_BSPC),     XXXXXXX,             XXXXXXX,             XXXXXXX,             LT(KL_OPE, KC_COMM), LT(KL_FUN, KC_DOT),  XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_SPACE)
    ),

    // mod norman
    [KL_NORMAN] = LAYOUT(
        KC_Q,                KC_W,                KC_D,                KC_F,                KC_B,                KC_J,                KC_U,                KC_R,                KC_P,                KC_SCLN,
        KC_A,                KC_S,                KC_E,                KC_T,                KC_G,                KC_Y,                KC_N,                KC_I,                KC_O,                KC_L,
        KC_Z,                KC_X,                KC_C,                KC_V,                KC_K,                KC_H,                KC_M,                CKC_IR,              CKC_NN,              LCTL_T(KC_SLSH),
        LSFT_T(KC_BSPC),     XXXXXXX,             XXXXXXX,             XXXXXXX,             LT(KL_OPE, KC_COMM), LT(KL_FUN, KC_DOT),  XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_SPACE)
    ),

    // Ope
    [KL_OPE] = LAYOUT(
        CKC_WO,              CKC_WA,              KC_MS_UP,            CKC_FU,              CKC_BE,              CKC_YOU,             CKC_NU,              KC_UP,               CKC_RO,              LGUI_T(KC_LBRC),
        CKC_ZA,              KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_RIGHT,         KC_BTN1,             KC_HOME,             KC_LEFT,             KC_DOWN,             KC_RIGHT,            KC_END,
        KC_LGUI,             KC_WH_U,             KC_BTN3,             KC_WH_D,             KC_BTN2,             TD(TD_BRACKET_L),    TD(TD_BRACKET_R),    TD(TD_QUOTE),        CKC_NNN,             LCTL_T(KC_INT1),
        LSFT_T(KC_TAB),      XXXXXXX,             XXXXXXX,             XXXXXXX,             _______,             KC_ENT,              XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_GRV)
    ),

    // Fun
    [KL_FUN] = LAYOUT(
        LCTL(KC_0),          LCTL(KC_1),          LCTL(KC_2),          LCTL(KC_3),          LCTL(KC_4),          CKC_NYU,             CKC_RYA,             CKC_RYU,             CKC_RYO,             LGUI_T(KC_F10),
        KC_F1,               KC_F2,               KC_F3,               KC_F4,               KC_F5,               KC_F6,               KC_F7,               KC_F8,               KC_F9,               KC_F11,
        RCS(KC_E),           CKC_PYTHON,          CKC_PY_TYPE_IGNORE,  CKC_PY_NOQA,         RCS(KC_LBRC),        LCA(KC_DOWN),        LCA(KC_UP),          LCA(KC_LEFT),        LCA(KC_RGHT),        LCTL_T(KC_F12),
        LCTL(KC_SLSH),       XXXXXXX,             XXXXXXX,             XXXXXXX,             RCS(KC_P),           _______,             XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_GRV)
    ),

    // Symbol and Number
    [KL_SYMNUM] = LAYOUT(
        LCTL(KC_MINS),       RCS(KC_SCLN),        RCS(KC_ESC),         LSG(KC_LEFT),        LSG(KC_RGHT),        LSFT(KC_MINS),       KC_7,                KC_8,                KC_9,                LSFT(KC_QUOT),
        LSFT(KC_1),          LSFT(KC_SLSH),       LSFT(KC_EQL),        LSFT(KC_6),          LSFT(KC_INT3),       KC_DOT,              KC_4,                KC_5,                KC_6,                KC_SLSH,
        LSFT(KC_LBRC),       CKC_L_ARROW,         CKC_R_ARROW,         LSFT(KC_5),          LSFT(KC_4),          KC_0,                KC_1,                KC_2,                KC_3,                LSFT(KC_SCLN),
        LSFT(KC_3),          XXXXXXX,             XXXXXXX,             XXXXXXX,             TD(TD_3_QUOTE),      KC_BSPC,             XXXXXXX,             XXXXXXX,             XXXXXXX,             KC_MINS
    )
};
