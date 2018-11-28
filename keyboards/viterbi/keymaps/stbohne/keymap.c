#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN1 1

#define KC_ KC_NO
#define KC_FN1 (TT(_FN1))
#define KC_FN1X (MO(_FN1))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC , GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,TAB , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,LBRC,RBRC,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     DEL ,BSPC, A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,BSLS,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSFT,LEAD,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     HYPR,LCTL,FN1 ,LGUI,LALT,SPC ,SPC ,     ENT ,ENT ,RALT,APP ,FN1 ,RCTL,HYPR
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_FN1] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     PWR ,SLEP, F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     END ,    ,    ,MUTE,VOLU,VOLD,    ,     PGUP,HOME, UP ,END ,    ,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     HOME,    ,MPRV,MNXT,MSTP,MPLY,    ,     PGDN,LEFT,DOWN,RGHT,INS ,CALC,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LSFT,    ,    ,    ,    ,    ,         ,WBAK,WREF,WSTP,WSCH,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     HYPR,LCTL,FN1X,LGUI,LALT,    ,    ,         ,    ,RALT,APP ,FN1X,RCTL,HYPR
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_FIVE_KEYS(KC_U, KC_C, KC_W, KC_I, KC_N) {
      set_unicode_input_mode(UC_WIN);
    }
    SEQ_FIVE_KEYS(KC_U, KC_C, KC_L, KC_N, KC_X) {
      set_unicode_input_mode(UC_WIN);
    }
    SEQ_TWO_KEYS(KC_M, KC_U) {
      send_unicode_hex_string("03BC");
    }
    SEQ_FIVE_KEYS(KC_A, KC_L, KC_P, KC_H, KC_A) {
      send_unicode_hex_string("03B1");
    }
  }
}