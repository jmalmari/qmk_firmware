#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    JmTilde,
    JmCirc,
    JmPin,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | §      |   1  |   2  |   3  |   4  |   5  | LEFT |           |  DEL |   6  |   7  |   8  |   9  |   0  |   +    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |   '  |   Y  |   U  |   I  |   O  |   P  |  RET   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
     * |--------+------+------+------+------+------|   B  |           |   B  |------+------+------+------+------+--------|
     * | LShift |102ND |   Z  |   X  |   C  |   V  |      |           |      |   N  |   M  |   ,  |   .  |   -  |   /    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ^¨~  |      |      | LGui |  Alt |                                       | Alt  | App  |   [  |   ]  |PrntScr |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        |      |      |       |      |Ctrl/Esc|
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      | Home |       | PgUp |        |      |
     *                                 |Space | LCTL |------|       |------| SYMB   |Backsp|
     *                                 |      |      | End  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    [BASE] = LAYOUT_ergodox_pretty(
        SE_SECT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           SE_ACUT,                                        KC_DELETE,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           SE_BSLS,                                        SE_QUOT,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_ENTER,
        KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
        KC_LSHIFT,      SE_LABK,        KC_Z,           KC_X,           KC_C,           KC_V,           SE_SLSH,                                        KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RSHIFT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        KC_LALT,                                                                                                        KC_RALT,        KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,
                                                                                                        LSFT(SE_QUOT),  RALT(SE_QUOT),  KC_TRANSPARENT, SE_BSLS,
                                                                                                                        KC_HOME,        SE_ACUT,
                                                                                        KC_SPACE,       MO(1),          KC_END,         SE_GRV,         MO(1),          KC_BSPACE),
    /* Keymap 1: Symbol Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | KC_ESC |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |NUMLCK|  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  <-  | PgDn | PgUp |  ->  |   *  |   F12  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   #  |   $  |   #  |   )  |   `  |------|           |------| Home | Down |  Up  |  End |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        | 102ND|   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   *  |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |    |   .  |   =  |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |  <-  |  ->  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |  up  |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       | down |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [SYMB] = LAYOUT_ergodox_pretty(
        KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        KC_TRANSPARENT, KC_EXLM,        KC_AT,          SE_LCBR,        SE_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_TRANSPARENT, KC_F12,
        KC_TRANSPARENT, KC_HASH,        SE_LBRC,        SE_LPRN,        SE_RPRN,        SE_RBRC,                                                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_PERC,        KC_CIRC,        SE_TILD,        SE_SLSH,        SE_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, SE_TILD,        SE_CIRC,        KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                        SE_SLSH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case JmTilde:
                SEND_STRING("~");
                //MACRO(D(RALT), TYPE(FI_UMLAUT), U(RALT), T(SPC), END);
                return false;
            case JmCirc:
                SEND_STRING("^");
                //MACRO(D(LSFT), T(RBRC), U(LSFT), T(SPC), END);
                return false;
            case JmPin:
                SEND_STRING("55150306");
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
