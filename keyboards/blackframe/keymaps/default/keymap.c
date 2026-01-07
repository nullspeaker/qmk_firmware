// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Layer 0: Default Layer
      *
      * ┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
      * │ `  │  1 │  2 │  3 │  4 │  5 │             │  6 │  7 │  8 │  9 │  0 │Bksp│
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │Tab │  Q │  W │  E │  R │  T │             │  Y │  U │  I │  O │  P │ \  │
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │Esc │  A │  S │  D │  F │  G │             │  H │  J │  K │  L │ ;  │ '  │
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │Shft│  Z │  X │  C │  V │  B │             │  N │  M │ ,  │ .  │ /  │Del │
      * ├────┼────┼────┼────┼────┴────┘             └────┴────┼────┼────┼────┼────┤
      * │LCtl│Supr│Meta│Hypr│  ┌─────┐                ┌─────┐ │Hypr│Meta│Gui │RCtl│
      * └────┴────┴────┴────┘  │Layer│                │Layer│ └────┴────┴────┴────┘
      *                        └┬────┴┬─────┐  ┌─────┬┴────┬┘
      *                         │Space│Enter│  │Enter│Space│
      *                         └─────┴─────┘  └─────┴─────┘
      */
    [0] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4  , KC_5   ,        KC_6   , KC_7   , KC_8   , KC_9   , KC_0  , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R  , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P  , KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F  , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V  , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_DEL ,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, TT(1) , KC_SPC ,        KC_SPC , TT(1) , KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_ENT ,        KC_ENT , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO ,
    ),
     /* Layer 1: Function Layer
      *
      * ┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
      * │ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │             │ F7 │ F8 │ F9 │F10 │F11 │F12 │
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │    │    │    │    │    │    │             │    │    │    │    │    │    │
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │    │    │    │    │    │    │             │LEFT│DOWN│ UP │RIGT│    │    │
      * ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
      * │    │    │    │    │ {  │  } │             │ [  │  ] │    │    │HOME│ END│
      * ├────┼────┼────┼────┼────┴────┘             └────┴────┼────┼────┼────┼────┤
      * │RCtl│Supr│Meta│Hypr│  ┌─────┐                ┌─────┐ │Hypr│Meta│Gui │RCtl│
      * └────┴────┴────┴────┘  │Layer│                │Layer│ └────┴────┴────┴────┘
      *                        └┬────┴┬─────┐  ┌─────┬┴────┬┘
      *                         │Space│Enter│  │Enter│Space│
      *                         └─────┴─────┘  └─────┴─────┘
      */
    [1] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,        KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_HOME, KC_END ,
        KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT, TT(0)  , KC_SPC ,        KC_SPC , TT(0)  , KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ENT ,        KC_ENT , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
    ),
};
