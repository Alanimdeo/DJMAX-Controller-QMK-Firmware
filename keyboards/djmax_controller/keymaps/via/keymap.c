// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

enum custom_keycodes {
    TG_INS = QK_KB_0,
    TG_HOME,
};

const uint8_t LED_GPIOS[] = {
    1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 27,
};

const uint8_t LED_MATRIX[][2] = {
    {2, 0}, {2, 1},
    {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7},
    {0, 0}, {0, 1},
};

void matrix_init_user(void) {
    setPinOutput(25);
    writePinHigh(25);
    for (int i = 0; i < 12; i++) {
        setPinOutput(LED_GPIOS[i]);
        writePinLow(LED_GPIOS[i]);
    }
}

void matrix_scan_user(void) {
    for (int i = 0; i < 12; i++) {
        if (matrix_is_on(LED_MATRIX[i][0], LED_MATRIX[i][1])) {
            writePinHigh(LED_GPIOS[i]);
        } else {
            writePinLow(LED_GPIOS[i]);
        }
    }
}

bool insert = false;
bool home   = false;

void toggle_key(bool *state, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        *state = !*state;
        if (*state) {
            register_code(keycode);
        } else {
            unregister_code(keycode);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_INS:
            toggle_key(&insert, KC_INS, record);
            return false;
        case TG_HOME:
            toggle_key(&home, KC_HOME, record);
            return false;
    }
    return true;
}

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
