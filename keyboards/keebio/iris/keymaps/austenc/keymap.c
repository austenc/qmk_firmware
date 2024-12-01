#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3
#define _ADJUST 7


// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, LT4, RT4, R30, R31, R32, R33, R34, R35, \
                        LT1, LT2, LT3, RT3, RT2, RT1 \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##LT4, KC_##RT4, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
                                                KC_##LT1, KC_##LT2, KC_##LT3, KC_##RT3, KC_##RT2, KC_##RT1 \
    )

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
  CODE_IF,
  REFLASH,
};

// Shortcuts and some mod tap keys
#define KC_ KC_TRNS
#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_LBSP LT(_LOWER, KC_BSPC)
#define KC_LDEL LT(_LOWER, KC_DEL)
#define KC_RENT LT(_RAISE, KC_ENT)
#define KC_GSPC LGUI_T(KC_SPC)
#define KC_GAME TG(_GAME)
#define KC_EARR EQL_ARROW
#define KC_DARR DASH_ARROW
#define KC_THIS PHP_THIS
#define KC_CSSC CSS_CLASS
#define KC_PHPF PHP_FUNC
#define KC_JSFN JS_FUNC
#define KC_CDIF CODE_IF
#define KC_REFL REFLASH

// Remap a few keys to be prefixed with KC_ so our layout / KC_ aliasing works
#define KC_BOOT QK_BOOT

// Space cadet -- we have to remap the space cadet keys to KC_ prefixed keys
#define KC_LSPO SC_LSPO
#define KC_RSPC SC_RSPC

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
     LITE,    ,    ,    ,    ,REFL,                   ,    ,    ,    ,    ,GAME,
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

    // Web Dev Shortcuts
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
    case REFLASH:
      if (record->event.pressed) {
        // First we want to send the command to compile qmk firmware
        SEND_STRING(SS_LALT("`")" qmk compile -kb keebio/iris/rev8 -km austenc && qmk flash -kb keebio/iris/rev8 -km austenc\n");
        // Add a delay before resetting
        wait_ms(500);
        reset_keyboard();  // More reliable than tap_code16(QK_BOOT)
      }
      break;
  }
  return true;
}
