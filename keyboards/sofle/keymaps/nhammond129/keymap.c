#include QMK_KEYBOARD_H
#include <stdio.h>

struct {
	uint8_t selector;
} gSTATE;

inline void clamp(uint8_t* var, const uint8_t min, const uint8_t max) {
	if		(*var > max) { *var = max; }
	else if (*var < min) { *var = min; }
}
inline void inc(uint8_t* var, const uint8_t min, const uint8_t max) { (*var)++; clamp(var, min, max); }
inline void dec(uint8_t* var, const uint8_t min, const uint8_t max) { (*var)--; clamp(var, min, max); }

enum sofle_layers {
	_QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | del  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |LOWER | / Space /       \Enter \  |RAISE | RAlt | RGUI | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           `-----------------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS, \
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_DELETE, \
                 KC_LCTRL,KC_LGUI,KC_LALT, KC_LOWER, KC_SPC,      KC_ENT,  KC_RAISE, KC_RALT, KC_RGUI, KC_RCTRL \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |-------.    ,-------| LEFT |  DN  |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |      |      | HOME | END  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /       /       \      \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,\
   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,     KC_0,  KC_F12, \
   KC_TAB, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, _______, _______, KC_HOME, KC_END, \
                     _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |   /  |   *  |   -  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PGUP |   7  |   8  |   9  |   +  |   ]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| PGDN |   4  |   5  |   6  |      | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /       /       \      \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______, _______, KC_PSLS,  KC_PAST,  KC_MINUS,  KC_EQUAL, \
  _______, _______, _______, _______, _______, _______,                       KC_PGUP, KC_7,    KC_8,     KC_9,     KC_PLUS,   KC_RBRC, \
  _______, _______, _______, _______, _______, _______,                       KC_PGDN, KC_4,    KC_5,     KC_6,     _______,   KC_BSPC, \
  _______, _______, _______, _______, _______, _______, _______,     _______, KC_0,    KC_1,    KC_2,     KC_3,     XXXXXXX,   _______, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET   , XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______,  _______,   _______, _______, _______, _______, _______ \
  )
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM rgblayer_lower[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 55, HSV_GREEN  } );
const rgblight_segment_t PROGMEM rgblayer_raise[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 55, HSV_PURPLE } );
const rgblight_segment_t PROGMEM rgblayer_adj[]   = RGBLIGHT_LAYER_SEGMENTS( { 0, 55, HSV_GOLD   } );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	rgblayer_lower, rgblayer_raise, rgblayer_adj
);
void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
	rgblight_mode(6);
}
layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(2, layer_state_cmp(state, _ADJUST));
	return state;
}	
#endif

#ifdef OLED_DRIVER_ENABLE
void oled_printu8(char* tag, uint8_t val, bool highlight_tag) {
	char buf[16];

	sprintf(buf, "%s ", tag);
	oled_write(buf, highlight_tag);

	sprintf(buf, "%d\n", val);
	oled_write(buf, false);
}

static void right_oled(void) {
	oled_write_ln_P(PSTR("_dab_"), false);
}

static void left_oled(void) {
	layer_state_t toplayer = get_highest_layer(layer_state);
	bool rtx_on = rgblight_is_enabled();
	if (toplayer == _ADJUST) {
		oled_write_P(PSTR("RTX"), false); 
		if (rtx_on) { oled_write_ln_P(PSTR("  "), true ); }
		else		{ oled_write_ln_P(PSTR("  "), false); }

		oled_printu8("spd", rgblight_get_speed(), false);
		oled_printu8("mod", rgblight_get_mode(),  false);


	} else {  /*	base layer		*/
		oled_write_P(PSTR(""), false);

		// Print current layer
		oled_write_ln_P(PSTR("LAYER"), false);
		switch (get_highest_layer(layer_state)) {
			case _RAISE:  oled_write_P(PSTR("raise"), false); break;
			case _LOWER:  oled_write_P(PSTR("lower"), false); break;
			case _ADJUST: oled_write_P(PSTR("adjst"), false); break;
			default:	  oled_write_P(PSTR("     "), false);
		}
	}
	oled_write_P(PSTR("\n\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
    // if (is_keyboard_master()) { }
    // return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {	left_oled(); }
    else { right_oled(); }
}
#endif

#ifdef ENCODER_ENABLE

void encoder_layered_none(uint8_t idx, bool cw) {
	if (idx == 0) {			/* left */
		if (cw) { tap_code(KC_VOLU); }
		else	{ tap_code(KC_VOLD); }
	} else if (idx == 1) {	/* right */
		if (cw) { tap_code(KC_UP); }
		else	{ tap_code(KC_DOWN); }
	}
}

void encoder_layered_raise(uint8_t idx, bool cw) {
	if (idx == 0) {			/* left */
		if (cw) { tap_code(KC_VOLU); }
		else	{ tap_code(KC_VOLD); }
	} else if (idx == 1) {	/* right */
		if (cw) { tap_code(KC_UP); }
		else	{ tap_code(KC_DOWN); }
	}
}

void encoder_layered_lower(uint8_t idx, bool cw) {
	if (idx == 0) {			/* left */
		if (cw) { tap_code(KC_VOLU); }
		else	{ tap_code(KC_VOLD); }
	} else if (idx == 1) {	/* right */
		if (cw) { tap_code(KC_UP); }
		else	{ tap_code(KC_DOWN); }
	}
}

void encoder_layered_adjst(uint8_t idx, bool cw) {
	if (idx == 0) {			/* left */
		if (cw) { rgblight_step(); }
		else	{ rgblight_step_reverse(); }
	} else if (idx == 1) {	/* right */
		if (cw) { rgblight_increase_speed(); }
		else	{ rgblight_decrease_speed(); }
	}
}
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:  encoder_layered_raise(index, clockwise);  break;
        case _LOWER:  encoder_layered_lower(index, clockwise);  break;
        case _ADJUST: encoder_layered_adjst(index, clockwise); break;
        default:	  encoder_layered_none(index, clockwise);
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool keydown = record->event.pressed;
    switch (keycode) {
        case KC_LOWER:  keydown ? layer_on(_LOWER)  : layer_off(_LOWER);	break;
        case KC_RAISE:  keydown ? layer_on(_RAISE)  : layer_off(_RAISE);	break;
        case KC_ADJUST: keydown ? layer_on(_ADJUST) : layer_off(_ADJUST);	break;
		default: return true;
    }
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
	return false;
}
