 #include "ergodox_ez.h"
 #include "debug.h"
 #include "action_layer.h"
 #include "version.h"
 
 
 #include "keymap_german.h"
 
 #include "keymap_nordic.h"
 
 
 
 enum custom_keycodes {
   PLACEHOLDER = SAFE_RANGE, // can always be here
   EPRM,
   VRSN,
   RGB_SLD,
   M_LOCK,
   M_CTAB,
   M_ATAB,
   M_CWIN,
   M_NWIN,
   M_KLANG,
   M_PMAIL,
   M_SA,
   M_NTAB,
   M_PTAB
 };
 
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (record->event.pressed) {
         switch(keycode) {
             case M_LOCK:
                 SEND_STRING(SS_LGUI(SS_TAP(X_L)));
                 return false;break;
             case M_CTAB: /* Close tab */
                 SEND_STRING(SS_LCTRL("w"));
                 return false;break;
             case M_ATAB: /* Add tab */
                 SEND_STRING(SS_LCTRL("t"));
                 return false;break;
             case M_CWIN: /* Close window */
                 SEND_STRING(SS_LALT(SS_TAP(X_F4)));
                 return false;break;
             case M_NWIN: /* New window */
                 SEND_STRING(SS_LCTRL("n"));
                 return false;break;
             case M_KLANG:
                 SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
                 return false;break;
             case M_PMAIL:
                 SEND_STRING("frederik_kok@icloud.com");
                 return false;break;
             case M_SA:
                 SEND_STRING(SS_LCTRL(SS_LALT("s")));
                 return false;break;
             case M_NTAB:
                 SEND_STRING(SS_LCTRL(SS_TAP(X_TAB)));
                 return false;break;
             case M_PTAB:
                 SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_TAB))));
                 return false;break;
         }

     }
     return true;
 };
 
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
   /* Layer 0: Base
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | M_lock |   1  |   2  |   3  |   4  |   5  |  -   |           |   +  |   6  |   7  |   8  |   9  |   0  |   =    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |  www |   Y  |   U  |   I  |   O  |   P  |   Å    |
    * |--------+------+------+------+------+------|      |           |  fwd |------+------+------+------+------+--------|
    * | Del    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Æ  |   Ø    |
    * |--------+------+------+------+------+------|  L1  |           |  www |------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |  bck |   N  |   M  |   ,  |   .  |  ~ 1 |    -   |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |LCTRL |M_KLANG| AltGr| Win | Alt |                                        |  Up  | Down | Left | Right|   /  |
    *   `---------------------------------'                                        `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |   [  |   ]  |       | RCTRL| Esc  |
    *                                 ,------|------|------|       |------+------|------.
    *                                 |      | Back | Home |       | PgUp |      |      |
    *                                 | Space|space |------|       |------|  Tab |Enter |
    *                                 |      |      | End  |       | PgDn |      |      |
    *                                 `--------------------'       `--------------------'
    */
 
 
 
   [0] = KEYMAP(
     M_LOCK,KC_1,KC_2,KC_3,KC_4,KC_5,KC_KP_MINUS,
     KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,
     KC_DELETE,KC_A,KC_S,KC_D,KC_F,KC_G,
     KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,TG(1),
 
     CTL_T(KC_NO),M_KLANG,ALGR_T(KC_NO),KC_RGUI,ALT_T(KC_NO),
 
           KC_LBRACKET,KC_RBRACKET,KC_HOME,
           KC_SPACE,KC_BSPACE,KC_END,
 
 
     KC_PLUS,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,
     KC_WWW_FORWARD,KC_Y,KC_U,KC_I,KC_O,KC_P,NO_AM,
     KC_H,KC_J,KC_K,KC_L,NO_AE,NO_OSLH,
     KC_WWW_BACK,KC_N,KC_M,KC_COMMA,KC_DOT,MO(1),KC_MINUS,
 
     KC_UP,KC_DOWN,KC_LEFT,KC_RIGHT,KC_SLASH,
 
           KC_RCTRL,KC_ESCAPE,KC_PGUP,
           KC_PGDOWN,KC_TAB,KC_ENTER),
 
   /* Layer 1: Navigation x R
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | M_lock |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | M_SA |Accl 0|Accl 2|Accl 3|      |M_PMAIL|   =   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |M_CWIN|      | WhUp |M_ATAB|M_CTAB|      |           |  www |M_PTAB|M_NTAB| MsUp |   O  |      |   `    |
   * |--------+------+------+------+------+------|      |           |  fwd |------+------+------+------+------+--------|
   * | Del    |   A  |WhLFT |WhDwn |WhRGHT|      |------|           |------|      | MsLft|MsDwn |MsRght|  \ | |   '    |
   * |--------+------+------+------+------+------|  L1  |           |  www |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |      |      |           |  bck |   N  |VolUp |VolDwn| MUTE |      |  ~ 2   |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |LCTRL |M_KLANG| AltGr|  Win | Alt |                                       |  Up  | Down | Left | Right|  /   |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |   [  |   ]  |       |      | Esc  |
   *                                 ,------|------|------|       |------+-------+------.
   *                                 |      | Back | Home |       | PgUp |       |      |
   *                                 |Lclck |space |------|       |------| Rclck |Enter |
   *                                 |      |      | End  |       | PgDn |       |      |
   *                                 `--------------------'       `---------------------'
   */
 


   [1] = KEYMAP(
     M_LOCK,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
     KC_TAB,M_CWIN,KC_TRANSPARENT,KC_MS_WH_UP,M_ATAB,M_CTAB,KC_TRANSPARENT,
     KC_DELETE,KC_A,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,KC_TRANSPARENT,
     KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_TRANSPARENT,KC_TRANSPARENT,
 
     CTL_T(KC_NO),M_KLANG,ALGR_T(KC_NO),GUI_T(KC_NO),ALT_T(KC_NO),
 
           KC_LBRACKET,KC_RBRACKET,KC_HOME,
           KC_MS_BTN1,KC_BSPACE,KC_END,
 
 
     M_SA,KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,KC_TRANSPARENT,M_PMAIL,KC_EQUAL,
     KC_WWW_FORWARD,M_PTAB,M_NTAB,KC_MS_UP,KC_O,KC_TRANSPARENT,KC_GRAVE,
     KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_BSLASH,KC_QUOTE,
     KC_WWW_BACK,KC_N,KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRANSPARENT,MO(2),
 
     KC_UP,KC_DOWN,KC_LEFT,KC_RIGHT,KC_SLASH,
 
           KC_TRANSPARENT,KC_ESCAPE,KC_PGUP,
           KC_PGDOWN,KC_MS_BTN2,KC_ENTER),

   /* Layer 2: F keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | M_lock |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |     |                                        |      |      |      |      |      |
   *   `---------------------------------'                                        `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      |      |       |      |        |      |
   *                                 |      |      |------|       |------|        |      |
   *                                 |      |      |      |       |      |        |      |
   *                                 `--------------------'       `----------------------'
   */
 
 
   [2] = KEYMAP(
     M_LOCK,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
 
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
 
           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
 
 
     KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
 
     KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
 
           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
 
 
 };
 
 const uint16_t PROGMEM fn_actions[] = {
   [1] = ACTION_LAYER_TAP_TOGGLE(1)
 };
 
 // leaving this in place for compatibilty with old keymaps cloned and re-compiled.
 const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
 {
       switch(id) {
         case 0:
         if (record->event.pressed) {
           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
         }
         break;
       }
     return MACRO_NONE;
 };
 
 void matrix_init_user(void) {
 #ifdef RGBLIGHT_COLOR_LAYER_0
   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
 #endif
 };



uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
