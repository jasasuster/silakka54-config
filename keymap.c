// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_slovenian.h"
#include "print.h"

// Custom Shift Keys
const custom_shift_key_t custom_shift_keys[] = {
    {SI_DOT , SI_RABK}, // Shift . is >
    {SI_COMM, SI_LABK}, // Shift , is <
    {SI_SCLN, SI_COLN}, // Shift ; is  :
    {SI_SLSH, SI_QUES}, // Shift / is  ?
    {SI_MINS, SI_UNDS}, // Shift - is  _
    {SI_QUOT, SI_DQUO}, // Shift ' is  "
    {SI_TILD, SI_HASH}, // Shift ~ is  #
    {SI_ASTR, SI_PERC}, // Shift * is  %
    {SI_CIRC, SI_GRV},  // Shift ^ is  `
    {SI_PLUS, SI_MINS}, // Shift + is  -
    {SI_DLR, SI_EURO},  // Shift $ is  €
    {SI_GRV, SI_TILD},  // Shift ` is  ~
};

// Tap Dance declarations
enum {
    TD_SHIFT_CAPS,
    TD_LGUI_ALT
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS), // Tap once for Shift, twice for Caps Lock
    [TD_LGUI_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT), // Tap once for Shift, twice for Caps Lock
};

// Combos
const uint16_t PROGMEM combo_mo3[] = {MO(1), MO(2), COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_mo3, MO(3)),
};

// Macros
enum custom_keycodes {
    BRACES = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case BRACES:  // Types (), [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {
                clear_oneshot_mods();  // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);
                if (((mods | oneshot_mods) & MOD_MASK_SHIFT) && ((mods | oneshot_mods) & MOD_MASK_CTRL)) {
                    // <>
                    tap_code16(KC_NUBS);
                    tap_code16(S(KC_NUBS));
                } else if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    // {}
                    tap_code16(SI_LCBR);
                    tap_code16(SI_RCBR);
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    // []
                    tap_code16(SI_LBRC);
                    tap_code16(SI_RBRC);
                } else {
                    // ()
                    tap_code16(SI_LPRN);
                    tap_code16(SI_RPRN);
                }
                tap_code(KC_LEFT);  // Move cursor between braces.
                register_mods(mods);  // Restore mods.
            }
        }
    return true;
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,            SI_1,   SI_2,    SI_3,    SI_4,    SI_5,                               SI_6,    SI_7,    SI_8,    SI_9,    SI_0,    SI_GRV,
        KC_TAB,            SI_Q,   SI_W,    SI_E,    SI_R,    SI_T,                               SI_Z,    SI_U,    SI_I,    SI_O,    SI_P,    SI_MINS,
        TD(TD_SHIFT_CAPS), SI_A,   SI_S,    SI_D,    SI_F,    SI_G,                               SI_H,    SI_J,    SI_K,    SI_L,    SI_SCLN, SI_QUOT,
        KC_LCTL,           SI_Y,   SI_X,    SI_C,    SI_V,    SI_B,                               SI_N,    SI_M,    SI_COMM, SI_DOT,  SI_SLSH, KC_ALGR,
                                            TD(TD_LGUI_ALT), MO(1), KC_SPC,           KC_ENT,  MO(2),  KC_BSPC
    ),
    [1] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_NO,   SI_7,    SI_8,    SI_9,    KC_NO,                              KC_NO,   KC_BSPC, KC_UP,   KC_DEL,  KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   SI_4,    SI_5,    SI_6,    KC_NO,                              KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
        KC_TRNS, SI_0,    SI_1,    SI_2,    SI_3,    KC_NO,                              KC_NO,   KC_PGUP, KC_PGDN, KC_HOME, KC_END,   KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS, SI_SCAR, SI_AT,   KC_PGUP, KC_NO,   KC_NO,                              SI_ASTR, SI_PIPE, SI_LPRN, SI_RPRN, SI_EXLM,  SI_UNDS,
        KC_TRNS, SI_CCAR, KC_HOME, KC_PGDN, KC_END,  KC_NO,                              SI_EQL, SI_LABK, SI_LBRC, SI_RBRC, SI_RABK, SI_TILD,
        KC_TRNS, SI_ZCAR, KC_NO,   KC_NO,   BRACES,   KC_NO,                              SI_CIRC, SI_AMPR, SI_LCBR, SI_RCBR, SI_PLUS, SI_DLR,
                                            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [3] = LAYOUT(
        QK_LLCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_SLEP,
        KC_NO,   KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,                                      OM_W_U, OM_BTNS, OM_U, OM_DBLS,  KC_NO,  KC_NO,
        KC_NO,   KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,                                      OM_W_D, OM_L, OM_D, OM_R, OM_SLOW, KC_NO,
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                      OM_RELS, OM_HLDS, OM_SEL1, OM_SEL2, OM_SEL3, KC_NO,
                                            KC_NO, KC_NO, KC_NO,              KC_NO,  KC_NO,  KC_NO
    )
};