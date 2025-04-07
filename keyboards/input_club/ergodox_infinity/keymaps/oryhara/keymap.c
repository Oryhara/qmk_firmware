#include QMK_KEYBOARD_H
#include "version.h"

#define DVORAK 0 // dvorak layer
#define HALFDVORAK 1 // mirrored dvorak layer
#define QWERTY 2 // qwerty layer
#define HALFQWERTY 3 // mirrored qwerty layer
//#define WORKMAN 2
//#define HALFWORKMAN 5
#define SYMB 6 // symbols
#define HALFSYMB 7 // media keys
#define SHORTCUTS 8 //layer with shortcut keys and other layer nav
#define FUNCTION 9 //all F-keys, all day

//LED Stuff

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | \    |           |  `   |   6  |   7  |   8  |   9  |   0  |  BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   '  |   ,  |   .  |   P  |   Y  |  [   |           |  ]   |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |  Z   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| SHORTCUTS|                               |SHORTCUTS| LEFT |RIGHT |  ALT | RCTRL  |
*   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  |      |       |      |Alt   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Up   |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | Down |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DVORAK] = LAYOUT_ergodox(  // layer 0 : dvorak
        // left hand
        KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_BSLS,
        KC_TAB,   KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   KC_MINUS,
        KC_BSPC,  KC_A,   KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,  KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_EQL,
        KC_LCTL, KC_LALT,LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),MO(SHORTCUTS),
                                                  KC_LGUI,KC_BTN1,

                                                          KC_UP,
                          LT(HALFDVORAK,KC_SPACE),KC_DEL,KC_DOWN,
        // right hand
        KC_TILD,  KC_6,   KC_7,  KC_8,   KC_9,   KC_0,     KC_BSPC,
        KC_LBRC,  KC_F,   KC_G,  KC_C,   KC_R,   KC_L,     KC_SLASH,
                  KC_D,   KC_H,  KC_T,   KC_N,   KC_S,		 KC_ENT,
        KC_RBRC,  KC_B,   KC_M,  KC_W,	 KC_V,	 KC_Z,		 KC_RSFT,
        MO(SHORTCUTS),KC_LEFT,KC_RIGHT,KC_RALT,KC_RCTL,
        KC_BTN1,        KC_RGUI,
        KC_PGUP,

        KC_PGDN,KC_TAB, LT(HALFDVORAK, KC_ENT)
    ),

/* Keymap 1: qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                |      |      |      |      |      |
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|      |------|       |------|        |Enter |
 *                                 |      |      |      |       |      |        |mirror|
 *                                 `--------------------'       `----------------------'
 */                                //no mirror on space for gaming
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand

        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, _______, _______, _______, _______,
                                      _______,  _______,
                                                _______,
                            KC_SPACE, _______,  _______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,         _______,
                 KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,		  _______,
        _______, KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLASH,   	_______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, LT(HALFQWERTY , KC_ENT)
    ),

/* Keymap 3: mirrored dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BSPC  |   0  |   9  |   8  |   7  |   6  | \    |           | `    |   5  |   4  |   3  |   2  |   1  |  ESC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   	/   |   L  |   R  |   C  |   G  |   F  |  [   |           |   -  |   Y  |   P  |   .  |   ,  |   '  |   TAB  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ENTER  |   S  |   N  |   T  |   H  |   D  |------|           |------|   I  |   U  |   E  |   O  |   A  |BSPC    |
 * |--------+------+------+------+------+------|  ]   |           |   =  |------+------+------+------+------+--------|
 * | LShift |   Z  |   V  |   W  |   M  |   B  |      |           |      |   X  |   K  |   J  |   Q  |   ;  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       | MOUSE| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  |      |       |      |Alt   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[HALFDVORAK] = LAYOUT_ergodox(  // layer 1 : mirrored Dvorak
        // left hand
      KC_BSPC, KC_0,    KC_9,    KC_8,    KC_7,   KC_6,   KC_TILD,
      KC_SLASH,KC_L,    KC_R,    KC_C,    KC_G,   KC_F,   KC_LBRC,
      KC_ENT,  KC_S,    KC_N,    KC_T,    KC_H,   KC_D,
      KC_RSFT, KC_Z,  	KC_V,    KC_W,    KC_M,   KC_B,   KC_RBRC,
      _______, _______, _______, _______, _______,
                                                  _______,_______,
                                                          _______,
                                            KC_NO, KC_ENT,_______,
        // right hand
      KC_BSLS,   KC_5,    KC_4,    KC_3,   KC_2,   KC_5,   KC_ESC,
      KC_MINUS,  KC_Y,    KC_P,    KC_DOT, KC_COMM,KC_QUOT,KC_TAB,
                 KC_I,    KC_U,    KC_E,   KC_O,   KC_A,	KC_BSPC,
      KC_EQL,    KC_X,    KC_K,    KC_J,	  KC_Q,   KC_SCLN,KC_RSFT,
                          _______, _______, _______, _______, _______,
      _______,_______,
      _______,
      _______,KC_TAB, KC_NO
    ),
    /* Keymap 3: mirrored qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BSPC  |   0  |   9  |   8  |   7  |   6  | \    |           |   `  |   5  |   4  |   3  |   2  |   1  |  ESC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  '     |   P  |   O  |   I  |   U  |   Y  |  ]   |           |  [   |   T  |   R  |   E  |   W  |   Q  |   TAB  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ENTER  |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  | BSPC   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   /  |   .  |   ,  |   M  |   N  |      |           |      |   B  |   V  |   C  |   X  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[HALFQWERTY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, _______, _______, _______, _______,
                                                      _______,_______,
                                                              _______,
                                                KC_NO, KC_ENT,_______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,         _______,
                 KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,		  _______,
        _______, KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLASH,   	_______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______,KC_TAB, KC_NO
    ),

/* Keymap 6: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |   F6 |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   /  |   \  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   /    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   '  |   ;  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   -  | ENTER  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   -  |   =  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   +  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |mirror|      |------|       |------|      |mirror|
 *                                 |space |      |      |       |      |      |enter |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_NO,KC_SLASH,KC_BSLS,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_NO,KC_QUOT,KC_SCLN, KC_LPRN,KC_RPRN,KC_GRV,
       KC_NO,KC_MINUS,KC_EQL,KC_LBRC,KC_RBRC,KC_TILD,KC_NO,
          EPRM,KC_NO,KC_NO,KC_NO,KC_TRNS,
                                         KC_TRNS,KC_NO,
                                               KC_NO,
                          LT(HALFSYMB, KC_SPACE),KC_NO,KC_NO,
       // right hand
       KC_F7, KC_F8,   KC_F9,  KC_F10,   KC_F11,   KC_F12,  KC_BSPC,
       KC_NO, KC_UP, KC_KP_7, KC_KP_8,  KC_KP_9,KC_KP_ASTERISK, KC_KP_SLASH,
            KC_DOWN, KC_KP_4, KC_KP_5,  KC_KP_6,  KC_KP_MINUS, KC_KP_ENTER,
       KC_NO,KC_AMPR,KC_KP_1, KC_KP_2,  KC_KP_3,   KC_KP_PLUS, KC_NO,
                         KC_TRNS,KC_DOT,  KC_0,    KC_KP_EQUAL,  KC_NO,
       BL_OFF, KC_TRNS,
       BL_ON,
       KC_NO, KC_NO, LT(HALFSYMB, KC_ENT)
),
/* Keymap 7: Mirrored Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |delete   |  F12 |  F11 |  F10 |  F9  |  F8  |   F7 |           |  F6  |  F5  |  F4  |  F3  |  F2  |  F1  |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   7  |   8  |   9  |   *  |   /  |           |      |   |  |   {  |   }  |   /  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |   4  |   5  |   6  |   -  |------|           |------|   `  |   (  |   )  |   ;  |   '  |        |
 * |---------+------+------+------+------+------|enter |           |      |------+------+------+------+------+--------|
 * |         |      |   1  |   2  |   3  |   +  |      |           |      |   ~  |   [  |   ]  |   =  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |   0  |  .   |  =   |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[HALFSYMB] = LAYOUT_ergodox(
       // left hand
       KC_BSPC,   KC_F13,    KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
       KC_NO,KC_NO,KC_KP_7, KC_KP_8, KC_KP_9,KC_KP_ASTERISK,KC_KP_SLASH,
       KC_ENTER,KC_NO,KC_KP_4, KC_KP_5, KC_KP_6,KC_KP_MINUS,
       KC_NO,KC_NO,KC_KP_1, KC_KP_2, KC_KP_3,KC_KP_PLUS,KC_KP_ENTER,
          EPRM,KC_NO,KC_KP_0,KC_KP_DOT,KC_KP_EQUAL,
                                         KC_TRNS,KC_NO,
                                               KC_TRNS,
                          KC_TRANSPARENT,KC_NO,KC_NO,
       // right hand
       KC_F19, KC_F20,   KC_F21,  KC_F22,   KC_F23,   KC_F24,  KC_BSPC,
       KC_NO,KC_PIPE,KC_LCBR,KC_RCBR, KC_SLASH, KC_BSLS, KC_NO,
             KC_GRV,KC_LPRN,KC_RPRN,  KC_SCLN, KC_QUOT, KC_NO,
       KC_NO, KC_TILD,KC_LBRC,KC_RBRC, KC_EQL,  KC_MINUS, KC_NO,
                         KC_TRNS,KC_NO,  KC_NO,    KC_NO,  KC_NO,
       KC_NO, KC_TRNS,
       KC_TRNS,
       KC_NO, KC_NO, KC_TRANSPARENT
),


/* Keymap 8: shortcuts
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   F1 |   F2 |  F3  |  F4  |  F5  | F6   |           | F7   |   F8 |  F9  |  F10 | F11  |  F12 |  BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB|     |                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |SYMBOLS|Dvorak|       |Steno |Plover|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[SHORTCUTS] = LAYOUT_ergodox(  // layer 8= : default
        // left hand
        QK_BACKLIGHT_STEP,         KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        KC_TAB,   LCTL(KC_Q),   LCTL(KC_W),LCTL(KC_E),LCTL(KC_R),LCTL(KC_T),   KC_NO,
        KC_BSPC,  LCTL(KC_A),   LCTL(KC_S),LCTL(KC_D),LCTL(KC_F),LCTL(KC_G),
        KC_LSFT,  LCTL(KC_Z),  	LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B),   KC_MINUS,
        QK_BOOT, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRANSPARENT,
                                              TG(SYMB),  TG(QWERTY),

                                                              TG(FUNCTION),
                                         KC_NO,KC_NO,KC_NO,
// right hand
             KC_F7, KC_F8,   KC_F9,  KC_F10,   KC_F11,   KC_F12,              KC_BSPC,
             KC_NO,KC_MS_WH_UP,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_MS_BTN4,KC_BSLS,
					  KC_MS_WH_DOWN,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_BTN3,KC_ENT,
             KC_EQL,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,LCTL(KC_COMM),LCTL(KC_DOT),KC_MS_BTN5,KC_RSFT,
								KC_TRNS, KC_UP,KC_DOWN,KC_RALT,           Q_RESET,
             TG(QWERTY),KC_NO,
             TG(SYMB),
             KC_NO,KC_MS_BTN1, KC_MS_BTN2
    ),

/*              KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_NO,LCTL(KC_Y),LCTL(KC_U),LCTL(KC_I),LCTL(KC_O),LCTL(KC_P),KC_BSLS,
                          LCTL(KC_H),LCTL(KC_J),LCTL(KC_K),LCTL(KC_L),LCTL(KC_SCLN),KC_ENT,
             KC_EQL,LCTL(KC_N),LCTL(KC_M),LCTL(KC_COMM),LCTL(KC_DOT),LCTL(KC_SLASH),KC_RSFT,
                                  KC_TRNS, KC_UP,KC_DOWN,KC_RALT,           RESET,
             TG(PROPERSTENO),KC_TRNS,
             TG(SYMB),
             KC_NO,KC_NO, KC_NO
    ), */

    /* Keymap 9: Functions
 *                                              LedMatrix
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    F1  |  F2  |  F3  |  F4  |  F5  |   F6 |LMTogg|           |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F7    |  F8  |  F9  |  F10 |  F11 |  F12 |LM+   |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F13   |  F14 |  F15 |  F16 |  F17 |  F18 |------|           |------|  F13 |  F14 |  F15 |  F16 |  F17 |  F18   |
 * |--------+------+------+------+------+------|LM-   |           |      |------+------+------+------+------+--------|
 * |  F19   |  F20 |  F21 |  F22 |  F23 |  F24 |      |           |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[FUNCTION] = LAYOUT_ergodox(  // layout: layer 9
        // left hand
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  LM_TOGG,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LM_BRIU,
        KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
        KC_F19,  KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,   LM_BRID,
        LM_NEXT,  LM_PREV,  LM_SPDU,  LM_SPDD,  KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                           KC_TRNS,
                                 KC_NO,   KC_NO,   KC_NO,
        // right hand
        LM_TOGG, KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,
        LM_NEXT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                 KC_F13,KC_F14,KC_F15,KC_F16, KC_F17, KC_F18,
        LM_PREV, KC_F19,KC_F20,KC_F21,KC_F22, KC_F23, KC_F24,
                              KC_TRNS, KC_TRNS,  KC_NO,   KC_NO,     KC_NO,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_NO,  KC_NO,   KC_NO
),

};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
}; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case KC_LCTL:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
/* void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}; */


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
