
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
};

#define KC_ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_DBUG DEBUG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     EQL , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT,SCLN, Q  , J  , K  , X  ,                B  , M  , W  , V  , Z  ,RSFT,
  //|----+----+----+--+-+----+----+----.    ,----|----+----+----+----+----+----|
     ESC ,LGUI,GRV ,RASE,LBRC,LALT,BSPC,     SPC ,RALT,RBRC,RASE,BSLS,RGUI,ENT ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LOWR,LCTL,BSPC,         SPC ,RCTL,LOWR
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,PLUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM,LABK,EQL ,RABK,LCBR,               RCBR, 4  , 5  , 6  ,COMM,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,PIPE,    ,LBRC,    ,         ,RBRC, 1  , 2  , 3  ,RALT,RCTL,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST ,    ,BTN1,MS_U,BTN2,WH_U,               LEFT,DOWN, UP ,RGHT,    ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,MS_L,MS_D,MS_R,WH_D,               HOME,PGDN,PGUP,END ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _DVORAK);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _DVORAK);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _DVORAK);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _DVORAK);
      }
      return false;
      break;
  }
  return true;
}
