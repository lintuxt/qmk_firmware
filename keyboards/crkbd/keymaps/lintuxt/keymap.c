/* @lintuxt - January 2024 - NO WARRANTY - ISC License */

// #define OLED_LAYER_DEBUG_ENABLE

#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_BASE 0
#define L_LEFT 4
#define L_RIGHT 8
#define L_ADJUST 16
#define L_LINTUXT 32
#define L_XCODE 64

/* Combined Layer Status */

#define L_ADJUST_LEFT 20
#define L_ADJUST_RIGHT 24
#define L_LINTUXT_RIGHT 40
#define L_XCODE_LEFT 192
#define L_XCODE_RIGHT 320

/* Keyboard Distributions */

#define QWERTY_DEFAULT 0
#define QWERTY 1
#define COLEMAK 2

enum custom_keycodes {
    RGB_RST = SAFE_RANGE,
    MAG_HL,
    MAG_HR,
    MAG_UP,
    MAG_DOWN,
    MAG_TL,
    MAG_TR,
    MAG_BL,
    MAG_BR,
    MAG_L13,
    MAG_L23,
    MAG_C3,
    MAG_R23,
    MAG_R13,
    MAG_ND,
    MAG_PD,
    MAG_MAX,
    MAG_C,
    MAG_RST,
    ONEPSAF
};

void mag(uint16_t code) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RALT));
    switch (code) {
        case MAG_HL:
            SEND_STRING(SS_TAP(X_LEFT));
            break;
        case MAG_HR:
            SEND_STRING(SS_TAP(X_RIGHT));
            break;
        case MAG_UP:
            SEND_STRING(SS_TAP(X_UP));
            break;
        case MAG_DOWN:
            SEND_STRING(SS_TAP(X_DOWN));
            break;
        case MAG_TL:
            SEND_STRING(SS_TAP(X_U));
            break;
        case MAG_TR:
            SEND_STRING(SS_TAP(X_I));
            break;
        case MAG_BL:
            SEND_STRING(SS_TAP(X_J));
            break;
        case MAG_BR:
            SEND_STRING(SS_TAP(X_K));
            break;
        case MAG_L13:
            SEND_STRING(SS_TAP(X_D));
            break;
        case MAG_L23:
            SEND_STRING(SS_TAP(X_E));
            break;
        case MAG_C3:
            SEND_STRING(SS_TAP(X_F));
            break;
        case MAG_R23:
            SEND_STRING(SS_TAP(X_T));
            break;
        case MAG_R13:
            SEND_STRING(SS_TAP(X_G));
            break;
        case MAG_ND:
            SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_RIGHT) SS_DELAY(50) SS_UP(X_LCMD));
            break;
        case MAG_PD:
            SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_LEFT) SS_DELAY(50) SS_UP(X_LCMD));
            break;
        case MAG_MAX:
            SEND_STRING(SS_TAP(X_ENTER));
            break;
        case MAG_C:
            SEND_STRING(SS_TAP(X_C));
            break;
        case MAG_RST:
            SEND_STRING(SS_TAP(X_BACKSPACE));
            break;
    }
    SEND_STRING(SS_DELAY(100) SS_UP(X_LCTL) SS_UP(X_RALT));
}

enum {
    XCODE_LAYER
};

tap_dance_action_t tap_dance_actions[] = {
    [XCODE_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, 6)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    TD(XCODE_LAYER),   MO(2),  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                               //`-----------------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    TD(XCODE_LAYER),   MO(2),  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                               //`-----------------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC, KC_EXLM,   KC_AT, KC_HASH, KC_LPRN, KC_RPRN,                      KC_UNDS, KC_PLUS, KC_TILD, XXXXXXX, XXXXXXX,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,  KC_DLR, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC,                      KC_MINS,  KC_EQL,  KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_AMPR, KC_ASTR, KC_PIPE, KC_LCBR, KC_RCBR,                      KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_0, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_4,    KC_5,    KC_6,   TG(5), XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,   MO(4),  KC_SPC,     KC_ENT, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [4] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGB_RST, RGB_HUD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F7,  KC_F10,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_SAD, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F8,  KC_F11,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F9,  KC_F12,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, _______, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [5] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          TG(5), ONEPSAF, MAG_L23, XXXXXXX, MAG_R23, XXXXXXX,                      XXXXXXX,  MAG_TL,  MAG_UP,  MAG_TR, XXXXXXX, MAG_RST,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          DF(0), XXXXXXX, MAG_L13,  MAG_C3, MAG_R13, XXXXXXX,                      XXXXXXX,  MAG_HL,   MAG_C,  MAG_HR, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          DF(1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MAG_PD,                       MAG_ND,  MAG_BL,MAG_DOWN,  MAG_BR, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX,   MAG_C,    MAG_MAX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [6] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, KC_LALT, _______,    _______,   MO(8),    MO(7)
                                        //`--------------------------'  `--------------------------'
    ),

    [7] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC, KC_EXLM,   KC_AT, KC_HASH, KC_LPRN, KC_RPRN,                      KC_UNDS, KC_PLUS, KC_TILD, XXXXXXX, XXXXXXX,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,  KC_DLR, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC,                      KC_MINS,  KC_EQL,  KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_AMPR, KC_ASTR, KC_PIPE, KC_LCBR, KC_RCBR,                      KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT, XXXXXXX, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [8] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_0, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, KC_LALT,  KC_SPC,     KC_ENT, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

void oled_dist_kb(void) {
    if (default_layer_state == QWERTY_DEFAULT || default_layer_state == QWERTY) {
        oled_write_ln_P(PSTR("QWERTY"), false);
    } else if (default_layer_state == COLEMAK) {
        oled_write_ln_P(PSTR("Colemak"), false);
    } else {
        oled_write_ln_P(PSTR("Unknown"), false);
    }
}

void oled_render_layer_state(void) {
    #ifdef OLED_LAYER_DEBUG_ENABLE
        char buff[32] = {};
        oled_clear();
        snprintf(buff, sizeof(buff), "LAYER: %d", layer_state);
        oled_write_ln(buff, false);
    #else
        oled_write_P(PSTR("L: "), false);
        switch (layer_state) {
            case L_BASE:
                oled_dist_kb();
                break;
            case L_LEFT:
                oled_write_ln_P(PSTR("Left"), false);
                break;
            case L_RIGHT:
                oled_write_ln_P(PSTR("Right"), false);
                break;
            case L_ADJUST:
            case L_ADJUST_LEFT:
            case L_ADJUST_RIGHT:
                oled_write_ln_P(PSTR("L+R"), false);
                break;
            case L_LINTUXT:
            case L_LINTUXT_RIGHT:
                oled_clear();
                oled_write_P(PSTR("@lintuxt | "), false);
                oled_dist_kb();
                break;
            case L_XCODE:
                oled_clear();
                oled_write_P(PSTR("@Xcode | "), false);
                oled_dist_kb();
                break;
            case L_XCODE_LEFT:
                oled_write_ln_P(PSTR("Xcode | Left"), false);
                break;
            case L_XCODE_RIGHT:
                oled_write_ln_P(PSTR("Xcode | Right"), false);
                break;
        }
    #endif
}

char keylog_str[32] = {};

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  snprintf(keylog_str, sizeof(keylog_str), "K: %c", name);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_ENABLE
        set_keylog(keycode, record);
        #endif
    }
    switch (keycode) {
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
            }
            break;
        case MAG_HL:
        case MAG_HR:
        case MAG_UP:
        case MAG_DOWN:
        case MAG_TL:
        case MAG_TR:
        case MAG_BL:
        case MAG_BR:
        case MAG_L13:
        case MAG_L23:
        case MAG_C3:
        case MAG_R23:
        case MAG_R13:
        case MAG_ND:
        case MAG_PD:
        case MAG_MAX:
        case MAG_C:
        case MAG_RST:
            if(record->event.pressed) {
                mag(keycode);
            }
            break;
        case ONEPSAF:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_RALT) SS_TAP(X_BSLS) SS_DELAY(100) SS_UP(X_RALT) SS_UP(X_LGUI));
            }

    }
    return true;
}
