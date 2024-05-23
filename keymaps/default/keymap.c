// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // QWERTY
    /*
     * │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │
     * │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │
     * │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │
     * │ Tab │     │     │     │ BSpc│ Spc │     │     │     │ Esc │
    */
    [0] = LAYOUT(
        LALT_T(KC_Q),    KC_W,            KC_E,            KC_R,            KC_T,            KC_Y,            KC_U,            KC_I,            KC_O,            LGUI_T(KC_P),
        KC_A,            KC_S,            KC_D,            KC_F,            KC_G,            KC_H,            KC_J,            KC_K,            KC_L,            KC_SCLN,
        KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,            KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,
        LSFT_T(KC_TAB),  XXXXXXX,         XXXXXXX,         XXXXXXX,         LT(1, KC_BSPC),  LT(2, KC_SPC),   XXXXXXX,         XXXXXXX,         XXXXXXX,         LCTL_T(KC_ESC)
    ),

    // Raise
    /*
     * │ ALT │     │MS_UP│     │ BTN2│     │     │  UP │     │ GUI │
     * │     │MSLFT│MSDWN│MSRGT│ BTN1│ HOME│ LEFT│ DOWN│RIGHT│ END │
     * │  \  │  [  │  ]  │  '  |  =  │  =  │  '  │  [  │  ]  │  \  │
     * │ SFT │     │     │     │     │ ENT │     │     │     │ GRV │
    */
    [1] = LAYOUT(
        KC_LALT,         XXXXXXX,         KC_MS_UP,        XXXXXXX,         KC_BTN2,         XXXXXXX,         XXXXXXX,         KC_UP,           XXXXXXX,         KC_LGUI,
        XXXXXXX,         KC_MS_LEFT,      KC_MS_DOWN,      KC_MS_RIGHT,     KC_BTN1,         KC_HOME,         KC_LEFT,         KC_DOWN,         KC_RIGHT,        KC_END,
        KC_BSLS,         KC_LBRC,         KC_RBRC,         KC_QUOT,         KC_EQL,          KC_EQL,          KC_QUOT,         KC_LBRC,         KC_RBRC,         KC_BSLS,
        KC_LSFT,         XXXXXXX,         XXXXXXX,         XXXXXXX,         _______,         KC_ENT,          XXXXXXX,         XXXXXXX,         XXXXXXX,         LCTL_T(KC_GRV)
    ),

    // Lower
    /*
     * │  F1 │  F2 │  F3 │  F4 │  F5 │  F6 │  F7 │  F8 │  F9 │ F10 │
     * │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │
     * │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │
     * │ F11 │     │     │     │ DEL │     │     │     │     │ F12 │
    */
    [2] = LAYOUT(
        LALT_T(KC_F1),   KC_F2,           KC_F3,           KC_F4,           KC_F5,           KC_F6,           KC_F7,           KC_F8,           KC_F9,           LGUI_T(KC_F10),
        KC_1,            KC_2,            KC_3,            KC_4,            KC_5,            KC_6,            KC_7,            KC_8,            KC_9,            KC_0,
        LSFT(KC_1),      LSFT(KC_2),      LSFT(KC_3),      LSFT(KC_4),      LSFT(KC_5),      LSFT(KC_6),      LSFT(KC_7),      LSFT(KC_8),      LSFT(KC_9),      LSFT(KC_0),
        LSFT_T(KC_F11),  XXXXXXX,         XXXXXXX,         XXXXXXX,         KC_DEL,          _______,         XXXXXXX,         XXXXXXX,         XXXXXXX,         LCTL_T(KC_F12)
    ),
};
