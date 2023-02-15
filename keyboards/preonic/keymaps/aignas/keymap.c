#include QMK_KEYBOARD_H

// Layer names
#define _DVORAK 0
#define _GAME 1
#define _RAISE 2
#define _QWERTY 3
#define _LOWER 4

enum preonic_keycodes {
  DVORAK = SAFE_RANGE,
  GAME,
  RAISE,
  QWERTY,
  LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   '  |   ,  |   .  |   p  |   y  |   f  |   g  |   c  |   r  |   l  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |   a  |   o  |   e  |   u  |   i  |   d  |   h  |   t  |   n  |   s  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|   ;  |   q  |   j  |   k  |   x  |   b  |   m  |   w  |   v  |   z  | SHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   =  | GUI  | ALT  | CTRL | RAISE| ENTER| SPACE| RAISE| CTRL |   \  |   [  |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid( \
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC, \
  KC_TAB ,KC_QUOT,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,KC_F   ,KC_G   ,KC_C   ,KC_R   ,KC_L   ,KC_SLSH, \
  KC_ESC ,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS, \
  KC_LSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_K   ,KC_X   ,KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,KC_RSFT,  \
  KC_EQL ,KC_LGUI,KC_LALT,KC_LCTL,RAISE  ,KC_ENT ,KC_SPC ,RAISE  ,KC_RCTL,KC_BSLS,KC_LBRC,KC_RBRC  \
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |NUM LK|   ÷  |   ×  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   1  |   2  |   3  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | CTRL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   4  |   5  |   6  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * | SHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   7  |   8  |   9  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      | ALT  | GUI  | SPACE| CTRL | BSPC | SPACE| RAISE|   ,  |   0  |   .  | TAB  |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid( \
  KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,XXXXXXX,KC_PSLS,KC_PAST,KC_PMNS, \
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_P1  ,KC_P2  ,KC_P3  ,KC_PPLS, \
  KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_P4  ,KC_P5  ,KC_P6  ,KC_PEQL, \
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PENT, \
  XXXXXXX,KC_LALT,KC_LGUI,KC_SPC ,KC_LCTL,KC_BSPC,KC_SPC ,RAISE  ,KC_PCMM,KC_P0  ,KC_PDOT,KC_TAB   \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | SLEEP|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |PRTSCR|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      | VOL+ |      |DVORAK| GAME |QWERTY| MENU |SCRLCK|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS | PREV | STOP | PLAY | NEXT | VOL- |      |      |      |      |      | PAUSE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BACK | STOP | RFRSH| FRWRD| MUTE |      |      | HOME | PGDN | PGUP | END  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      | DEL  |      |      | LEFT | DOWN |  UP  | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_SLEP,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_PSCR, \
  _______,KC_F11 ,KC_F12 ,_______,_______,KC_VOLU,_______,DVORAK ,GAME   ,QWERTY ,KC_MENU,XXXXXXX, \
  _______,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT,KC_VOLD,_______,_______,_______,_______,_______,KC_PAUS, \
  _______,KC_WBAK,KC_WSTP,KC_WREF,KC_WFWD,KC_MUTE,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,  \
  RESET  ,_______,_______,_______,_______,KC_DEL ,_______,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT  \
),

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | LOWER| GUI  | ALT  | `    | ENTER| SPACE| LOWER| left | down |  up  |right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC, \
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_EQL,  \
  KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT, \
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_MINS, \
  KC_LCTL,LOWER  ,KC_LGUI,KC_LALT,KC_ENT ,KC_ENT ,KC_SPC ,KC_SPC ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT  \
),

[_LOWER] = LAYOUT_preonic_grid( \
  KC_SLEP,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_LBRC,KC_RBRC,KC_PSCR, \
  _______,KC_F11 ,KC_F12 ,_______,_______,KC_VOLU,_______,DVORAK ,GAME   ,QWERTY ,XXXXXXX,XXXXXXX, \
  _______,KC_MPRV,KC_MSTP,KC_MPLY,KC_MNXT,KC_VOLD,_______,_______,_______,_______,_______,KC_PAUS, \
  _______,KC_WBAK,KC_WSTP,KC_WREF,KC_WFWD,KC_MUTE,_______,_______,_______,_______,_______,_______, \
  RESET  ,_______,_______,_______,_______,KC_DEL ,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END \
)

};



#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};
float tone_dvorak[][2] = SONG(DVORAK_SOUND);
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_game[][2]    = {
  {NOTE_E6, 10}   ,{NOTE_E6, 10}  ,{NOTE_REST, 10} ,{NOTE_E6, 10}   ,
  {NOTE_REST, 10} ,{NOTE_C6, 10}  ,{NOTE_E6, 10}   ,{NOTE_REST, 10} ,
  {NOTE_G6, 10}   ,{NOTE_REST, 30},
  {NOTE_G5, 10}   ,{NOTE_REST, 30}
};
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

void startup_user() {
  //_delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}
void shutdown_user() {
  PLAY_SONG(tone_goodbye);
  //_delay_ms(150);
  stop_all_notes();
}

#endif



void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
  startup_user();
  #endif
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_game);
        #endif
        persistent_default_layer_set(1UL<<_GAME);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      break;
    default:
      return true;
      break;
  }

  return false;
};
