// Copyright 2021 Andrzej Kotulski (@akotulski)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define MT_V LSFT_T(KC_V)
#define MT_M RSFT_T(KC_M)
#define MT_F1 LALT_T(KC_F1)
#define MT_F2 LCTL_T(KC_F2)
#define MT_F3 LSFT_T(KC_F3)
#define MT_GRV LGUI_T(KC_GRV)
#define MT_1 LALT_T(KC_1)
#define MT_2 LCTL_T(KC_2)
#define MT_3 LSFT_T(KC_3)

#define MT_ESC RCTL_T(KC_ESC)
#define MT_DEL RALT_T(KC_DEL)
#define LE_NAV LT(_RAISE, KC_ESC)
#define LD_SYM LT(_LOWER, KC_DEL)

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
    _ACC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_NO,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_MINS,
        KC_NO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,      KC_QUOT, KC_SCLN,
        KC_LGUI, KC_Z,    KC_X,    KC_C,    MT_V,    KC_B,               KC_N,    MT_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI,
                          KC_LALT, KC_LCTL,                                                KC_RCTL, KC_RALT,
                                       LE_NAV,  KC_SPC,   KC_TAB,   KC_ENT, KC_BSPC,  LD_SYM,
                                            OSM(MOD_LSFT), KC_ESC,         OSM(MOD_LSFT),  KC_DEL
    ),

    [_LOWER] = LAYOUT(
       _______,  KC_LBRC , KC_7    , KC_8    , KC_9    , KC_RBRC ,     KC_PGUP , KC_HOME         , KC_CAPS , KC_END             , KC_PSCR ,  _______,
       _______, KC_SCLN , KC_4    , KC_5    , KC_6    , KC_EQL  ,      KC_LEFT , KC_DOWN         , KC_UP   , KC_RGHT            , KC_INS  ,  _______,
       _______, MT_GRV  , MT_1    , MT_2    , MT_3    , KC_BSLS ,      KC_PGDN , OSM(MOD_RSFT)   , OSM(MOD_RCTL), OSM(MOD_LALT) , KC_RGUI ,  _______,
                          KC_LPRN, KC_RPRN,                                                 KC_LPRN, KC_RPRN,
                                  _______,   KC_0  , KC_MINS,             _______, _______, _______,
                                            _______, _______,             _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, KC_NO  , KC_F7  , KC_F8  , KC_F9   , KC_F12,            _______, _______, _______, _______,  _______, _______,
        _______, KC_LEFT, KC_F4  , KC_F5   , KC_F6  , KC_F11,            _______, _______, _______, _______,  _______, _______,
        _______, KC_LGUI, MT_F1   , MT_F2   , MT_F3 , KC_F10  ,          _______, _______, _______, _______,  _______, _______,
                          _______, _______,                                                _______, _______,
                                  _______, _______,  _______,            KC_TRNS , _______ , KC_QUES,
                                            _______, _______,            _______, MO(_ACC)
    ),

    [_ACC] = LAYOUT(
        _______, QK_BOOT, _______, _______, _______, _______,            _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______, _______,
                          _______, _______,                                                _______, _______,
                                  _______, _______,  _______,            KC_TRNS , _______ , KC_QUES,
                                            _______, _______,            _______, _______
    )
};

