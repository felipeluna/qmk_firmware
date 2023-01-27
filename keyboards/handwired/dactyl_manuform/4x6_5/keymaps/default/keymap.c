// Copyright 2021 Andrzej Kotulski (@akotulski)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KK_ESC LT(_NUMBER, KC_ESC)
#define KK_SPC LT(_MOVE, KC_SPC)
#define KK_TAB LT(_MOUSE, KC_TAB)
#define KK_DEL LT(_SYMBOL, KC_DEL)
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

enum layer_names {
    _BASE, //ok
    _MOVE, //ok
    _MOUSE, //ok
    _NUMBER, //ok
    _SYMBOL //ok
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                       KC_LGUI, KC_LALT,                                                KC_RALT, KC_LGUI,
                                       KK_ESC,  KK_SPC,   KK_TAB,   KC_ENT,  KC_BSPC,  KK_DEL,
                                            KC_LSFT, KC_LCTL,            KC_RCTL,  KC_RSFT
    ),


    [_MOVE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, U_RDO,   U_CPY,   U_CUT,    KC_UNDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_CAPS, _______,
        _______, _______, _______, KC_ALGR, _______, _______,             KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS,  _______,
                          _______, _______,                                                 _______, KC_P0,
                                   _______, _______,  _______,            KC_ENT,  KC_BSPC,  KC_DEL,
                                            _______, _______,             _______, _______
    ),

    [_SYMBOL] = LAYOUT(
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,             _______, _______, _______, _______, _______, _______,
        _______, KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,             _______, KC_LSFT ,KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,             _______, _______, _______, KC_ALGR, _______, _______,
                          _______, KC_PSCR,                                                 _______, _______,
                                  KC_LPRN, KC_RPRN,  KC_UNDS,             _______, _______, _______,
                                            KC_QUES, _______,             _______, _______
    ),

    [_NUMBER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______ ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_LBRC, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,             KC_EQL  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_SCLN, KC_LGUI,
        _______, _______, _______, KC_ALGR, _______, _______,             KC_BSLS ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_GRV,  _______,
                          _______, _______,                                                _______, _______,
                                   _______, _______, _______,             KC_MINS,  KC_0,  KC_DOT,
                                            _______, _______,             _______, _______
    ),

   [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             KC_RBRC, U_RDO,   U_CPY,   U_CUT,    _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,             KC_MS_L ,KC_MS_D, KC_MS_U, KC_MS_R,  _______, _______,
        _______, _______, _______, KC_ALGR, _______, _______,             KC_WH_L ,KC_WH_D, KC_WH_U, KC_WH_R,  _______, _______,
                          _______, _______,                                                 _______, QK_BOOT,
                                   _______, _______, _______,             KC_BTN1, KC_BTN2, KC_BTN3,
                                            _______, _______,             _______, _______
    ),


};
