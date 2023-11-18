#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define RESET QK_BOOT

#define XXXX KC_NONE

#define LA_SYM LT(_SYM, KC_BSPC)
#define LA_NAV LT(_NAV, KC_TAB)
#define LE_NAV LT(_NAV, KC_ESC)
#define LE_TAB LT(_NAV, KC_TAB)
#define LD_SYM LT(_SYM, KC_DEL)
#define SF_TAB RSFT_T(KC_TAB)
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
    _ACC
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WIN,  // Switch to next window         (alt-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
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

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TABR A(KC_TAB)
#define TABL A(S(KC_TAB))
#define SPCL A(G(KC_LEFT))
#define SPC_R A(G(KC_RGHT))

#define LT_NAV MO(_NAV)
#define LT_SYM MO(_SYM)

// ACCENT LAYER
enum unicode_names {
    AR_LOWER,
};

const uint32_t PROGMEM unicode_map[] = {
    [AR_LOWER] = 0x00E5,  // aring
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,           KC_Y,    KC_U,     KC_I,    KC_O,      KC_P,
        KC_A,    KC_S,    KC_D,     KC_F,    KC_G,           KC_H,    KC_J,     KC_K,    KC_L,    KC_QUOT,
        KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,           KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,
			             LT_SYM,   KC_SPC,  KC_LSFT,        KC_ENT,  KC_BSPC,  LT_NAV
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,          KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,           KC_HASH, KC_AMPR, KC_SCLN, KC_COLN, KC_EXLM,
        KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC,          KC_QUES, OS_SHFT,  OS_CTRL,  OS_ALT, OS_GUI,
			             _______   , _______    , _______ ,      _______   , KC_QUES  , _______
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_TAB,  SW_WIN,  TABL,    TABR,        KC_VOLU,         QK_BOOT, KC_HOME, KC_CAPS,  KC_END, KC_DEL,
        SPCL,    SPC_R,   BACK,    FWD,         KC_VOLD,         KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, KC_BSPC,
        OS_GUI, OS_ALT, OS_CTRL,  OS_SHFT,      KC_MPLY,         KC_QUES, KC_PGDN, KC_PGUP,  SW_LANG, KC_ENT,
                             _______ , KC_ESC,  KC_TAB,      _______ , _______ , _______
    ),

    [_NUM] = LAYOUT_split_3x5_3(
            KC_1,    KC_2,     KC_3,    KC_4,   KC_5,   KC_6,    KC_7,    KC_8,     KC_9,    KC_0,
            KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,
            OS_GUI, OS_ALT, OS_CTRL,  OS_SHFT, KC_F11,  KC_F12,  OS_SHFT,  OS_CTRL,  OS_ALT, OS_GUI,
                           _______ , _______ , _______ ,      _______ , _______ , _______
    )
};

 bool is_oneshot_cancel_key(uint16_t keycode) {
     switch (keycode) {
     case LT_SYM:
     case LT_NAV:
         return true;
     default:
         return false;
     }
 }

 bool is_oneshot_ignored_key(uint16_t keycode) {
     switch (keycode) {
     case LT_SYM:
     case LT_NAV:
     case KC_LSFT:
     case OS_SHFT:
     case OS_CTRL:
     case OS_ALT:
     case OS_GUI:
         return true;
     default:
         return false;
     }
 }

 bool sw_win_active = false;
 bool sw_tab_active = false;

 oneshot_state os_shft_state = os_up_unqueued;
 oneshot_state os_ctrl_state = os_up_unqueued;
 oneshot_state os_alt_state = os_up_unqueued;
 oneshot_state os_cmd_state = os_up_unqueued;

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     update_swapper(
         &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
         keycode, record
     );
    //  update_swapper(
    //      &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
    //      keycode, record
    //  );

     update_oneshot(
         &os_shft_state, KC_LSFT, OS_SHFT,
         keycode, record
     );
     update_oneshot(
         &os_ctrl_state, KC_LCTL, OS_CTRL,
         keycode, record
     );
     update_oneshot(
         &os_alt_state, KC_LALT, OS_ALT,
         keycode, record
     );
     update_oneshot(
         &os_cmd_state, KC_LGUI, OS_GUI,
         keycode, record
     );

     return true;
 }

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
