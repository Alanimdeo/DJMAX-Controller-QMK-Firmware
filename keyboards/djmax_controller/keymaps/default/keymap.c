// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LT(1, KC_ESC), KC_ENT,
        KC_LSFT, KC_A, KC_S, KC_D, KC_L, KC_SCLN, KC_QUOT, KC_RSFT,
        KC_C, KC_M
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_ESC,
        KC_1, KC_PGUP, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_PGDN, KC_2,
        KC_TAB, KC_SPC
    )
};
