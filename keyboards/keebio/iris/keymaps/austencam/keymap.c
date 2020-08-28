#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  EQL_ARROW,
  DASH_ARROW,
  PHP_THIS,
  CSS_CLASS,
  PHP_FUNC,
  JS_FUNC,
  CODE_IF
};

// Shortcuts and some mod tap keys
#define KC_ KC_TRNS
#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_LBSP LT(_LOWER, KC_BSPC)
#define KC_LDEL LT(_LOWER, KC_DEL)
#define KC_RENT LT(_RAISE, KC_ENT)
#define KC_RST RESET
#define KC_DBG DEBUG
#define KC_GSPC LGUI_T(KC_SPC)
#define KC_GAME TG(_GAME)
#define KC_EARR EQL_ARROW 
#define KC_DARR DASH_ARROW
#define KC_THIS PHP_THIS
#define KC_CSSC CSS_CLASS
#define KC_PHPF PHP_FUNC
#define KC_JSFN JS_FUNC
#define KC_CDIF CODE_IF

// RGB Underglow and Key Backlight
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_LITE BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESCC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,LGUI,     SPC , N  , M  ,COMM,DOT ,SLSH,RSPC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LBSP, LGUI,        SPC ,RENT,LOWR 
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAME] = LAYOUT_kc(
  // Same as QWERTY except these keym
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    , SPC,     GSPC,   ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    , SPC ,        GSPC,   ,  
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, EQL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,JSFN,PHPF,LPRN,               RPRN, P7 , P8 , P9 ,    ,VOLU,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,CDIF,THIS,DARR,EARR,LBRC,               RBRC, P4 , P5 , P6 ,    ,VOLD,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,CSSC,    ,LCBR,    ,      SPC,RCBR, P1 , P2 , P3 , P0 ,MUTE,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,          SPC,RASE, 
  //                  `----+----+----'        `----+----+----'
  ),
  
  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                F7 , F8 , F9 ,F10 ,F11 , EQL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,LPRN,               HOME,PGDN,PGUP, END,    , F12,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,JSFN,PHPF,LBRC,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,LCBR,    ,     GSPC,    ,    ,    ,    ,     ,   ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,LDEL,    ,         GSPC,    , 
  //                  `----+----+----'        `----+----+----'  
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LITE,    ,    ,    ,    , RST,                DBG,    ,    ,    ,    ,GAME,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    , 
  //                  `----+----+----'        `----+----+----'  
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case EQL_ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
    case DASH_ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case PHP_THIS:
      if (record->event.pressed) {
        SEND_STRING("$this->");
      }
      break;
    case CSS_CLASS:
      if (record->event.pressed) {
        SEND_STRING("class="SS_LSFT("'")SS_LSFT("'")SS_TAP(X_LEFT));
      }
      break;
    case PHP_FUNC:
      if (record->event.pressed) {
        SEND_STRING("function() {}"SS_TAP(X_LEFT));
      }
      break;
    case JS_FUNC:
      if (record->event.pressed) {
        SEND_STRING("() => {}"SS_TAP(X_LEFT));
      }
      break;
    case CODE_IF:
      if (record->event.pressed) {
        SEND_STRING("if () {}"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
      }
      break;
  }
  return true;
}