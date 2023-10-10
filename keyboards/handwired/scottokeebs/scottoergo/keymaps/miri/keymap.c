#include QMK_KEYBOARD_H

/* #include "oneshot.h" */
/* #include "swapper.h" */

#define RESET QK_BOOT

#define XXXX KC_NONE

#define LA_SYM LT(_SYM, KC_BSPC)
#define LA_NAV LT(_NAV, KC_TAB)
#define LE_NAV LT(_NAV, KC_ESC)
#define LD_SYM LT(_SYM, KC_DEL)
#define LA_GFN MO(_GFN)
#define WARPD LAG(KC_X)
#define QUOT S(KC_GRV)
#define PIPE S(KC_BSLS)
#define DPIPE S(RALT(KC_BSLS))
#define SCLN S(KC_LBRC)
#define CLN S(KC_RBRC)
#define GRV RALT(KC_GRV)
#define BSL RALT(KC_BSLS)

#define SPACE_L C(G(KC_LEFT))
#define SPACE_R C(G(KC_RGHT))

#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
enum layers {
    _DEF,
    _GAM,
    _GFN,
    _SYM,
    _NAV,
    _NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_TAB,  // Switch to next browser tab    (ctrl-tab)
};

#define LT_TAB LT(_FUN, KC_TAB)
#define LT_BSPC LT(_SYM, KC_BSPC)


// BASE LAYER MOD

#define MT_Z LGUI_T(KC_Z)
#define MT_X LALT_T(KC_X)
#define MT_C LCTL_T(KC_C)
#define MT_V LSFT_T(KC_V)
#define MT_B LCTL_T(KC_B)

#define MT_M RSFT_T(KC_M)
#define MT_COMM RCTL_T(KC_COMM)
#define MT_DOT RALT_T(KC_DOT)
#define MT_SLSH RGUI_T(KC_SLSH)

// SYM LAYER
#define MT_GRV LGUI_T(KC_GRV)
#define MT_1 LALT_T(KC_1)
#define MT_2 LCTL_T(KC_2)
#define MT_3 LSFT_T(KC_3)

#define MT_ESC RCTL_T(KC_ESC)
#define MT_DEL RALT_T(KC_DEL)

// FUN LAYER
#define MT_F1 LALT_T(KC_F1)
#define MT_F2 LCTL_T(KC_F2)
#define MT_F3 LSFT_T(KC_F3)

#define MT_MRWD RSFT_T(KC_MRWD)
#define MT_MPLY RCTL_T(KC_MPLY)
#define MT_MFFD RALT_T(KC_MFFD)
#define MT_MUTE RGUI_T(KC_MUTE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,           KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,     KC_F,    KC_G,           KC_H,    KC_J,     KC_K,    KC_L,    KC_QUOT,
        MT_Z,    MT_X,    MT_C,     MT_V,    MT_B,           KC_N,    MT_M,     MT_COMM, MT_DOT,  MT_SLSH,
			              LE_NAV,   KC_SPC,  KC_TAB,         KC_ENT,  KC_BSPC,  LD_SYM
    ),

    [_SYM] = LAYOUT_split_3x5_3(
       KC_LBRC , KC_7    , KC_8    , KC_9    , KC_RBRC ,      KC_PGUP , KC_HOME  , KC_CAPS , KC_END  , KC_PSCR ,     \
       KC_SCLN , KC_4    , KC_5    , KC_6    , KC_EQL  ,      KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT , KC_INS  ,     \
       MT_GRV  , MT_1    , MT_2    , MT_3    , KC_BSLS ,      KC_PGDN , KC_RSFT  , MT_ESC   , MT_DEL  , KC_RGUI ,     \
			             KC_LPRN   , KC_0    , KC_MINS ,      KC_NO   , KC_TRNS  , _______
    ),

    [_NAV] = LAYOUT_split_3x5_3(
       KC_NO   , KC_F7   , KC_F8   , KC_F9   , KC_F12  ,      KC_WH_U , KC_WH_L , KC_MS_U , KC_WH_R , KC_VOLU ,     \
       KC_ESC  , KC_F4   , KC_F5   , KC_F6   , KC_F11  ,      KC_BTN3 , KC_MS_L , KC_MS_D , KC_MS_R , KC_VOLD ,     \
       KC_LGUI , MT_F1   , MT_F2   , MT_F3   , KC_F10  ,      KC_WH_D , MT_MRWD , MT_MPLY , MT_MFFD , MT_MUTE ,     \
                              _______, _______, _______,      KC_TRNS , KC_BTN1 , KC_QUES
    )

    //    [_NUM] = LAYOUT_split_3x5_3(
    //        KC_1,   KC_2,   KC_3,      KC_4,      KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    //        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_F11,         KC_F12,  KC_LSFT, KC_RCTL, KC_RALT, KC_RGUI,
    //        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    //                          _______, _______, _______,        _______, _______, _______
    //    )
};

/* bool is_oneshot_cancel_key(uint16_t keycode) { */
/*     switch (keycode) { */
/*     case LA_SYM: */
/*     case LA_NAV: */
/*         return true; */
/*     default: */
/*         return false; */
/*     } */
/* } */

/* bool is_oneshot_ignored_key(uint16_t keycode) { */
/*     switch (keycode) { */
/*     case LA_SYM: */
/*     case LA_NAV: */
/*     case KC_LSFT: */
/*     case OS_SHFT: */
/*     case OS_CTRL: */
/*     case OS_ALT: */
/*     case OS_CMD: */
/*         return true; */
/*     default: */
/*         return false; */
/*     } */
/* } */

/* bool sw_win_active = false; */
/* bool sw_tab_active = false; */

/* oneshot_state os_shft_state = os_up_unqueued; */
/* oneshot_state os_ctrl_state = os_up_unqueued; */
/* oneshot_state os_alt_state = os_up_unqueued; */
/* oneshot_state os_cmd_state = os_up_unqueued; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     update_swapper( */
/*         &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT, */
/*         keycode, record */
/*     ); */
/*     update_swapper( */
/*         &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT, */
/*         keycode, record */
/*     ); */

/*     update_oneshot( */
/*         &os_shft_state, KC_LSFT, OS_SHFT, */
/*         keycode, record */
/*     ); */
/*     update_oneshot( */
/*         &os_ctrl_state, KC_LCTL, OS_CTRL, */
/*         keycode, record */
/*     ); */
/*     update_oneshot( */
/*         &os_alt_state, KC_LALT, OS_ALT, */
/*         keycode, record */
/*     ); */
/*     update_oneshot( */
/*         &os_cmd_state, KC_LCMD, OS_CMD, */
/*         keycode, record */
/*     ); */

/*     return true; */
/* } */

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYM, _NAV, _NUM);
// }
