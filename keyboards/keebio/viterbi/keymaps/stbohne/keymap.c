#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "analog.h"
#include "pointing_device.h"
#include "print.h"
#include "split_util.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 1
#define _QWERTY 0
#define _KYRIA 2
#define _FN1 3
#define _FN1K 4
#define _FN2 5

#define KC_ KC_NO
#define KC_FN1 (TT(_FN1))
#define KC_FN1X (MO(_FN1))
#define KC_FN1K (TT(_FN1K))
#define KC_FN1L (MO(_FN1K))
#define KC_FN2 (TT(_FN2))
#define KC_FN2X (MO(_FN2))
#define KC_COLE (DF(_COLEMAK))
#define KC_QWER (DF(_QWERTY))
#define KC_KYRI (DF(_KYRIA))
#define KC_SH SH_TT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC ,GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,TAB , Q  , W  , F  , P  , B  ,      J  , L  , U  , Y  ,SCLN,LBRC,RBRC,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     DEL ,BSPC, A  , R  , S  , T  , G  ,      K  , N  , E  , I  , O  ,QUOT,BSLS,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LSFT, Z  , X  , C  , D  , V  ,      M  , H  ,COMM,DOT ,SLSH,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LCTL,FN1 ,LGUI,LALT,FN2 ,SPC ,     ENT ,FN2 ,RALT,APP ,FN1 ,RCTL,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC ,GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,TAB , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,LBRC,RBRC,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     DEL ,BSPC, A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,BSLS,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LCTL,FN1 ,LGUI,LALT,FN2 ,SPC ,     ENT ,FN2 ,RALT,APP ,FN1 ,RCTL,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_KYRIA] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,GRV , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,EQL ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     BSPC,LSPO, A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,RSPC,DEL ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LCPO, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RCPC,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,FN1K,LGUI,LALT,FN2 ,SPC ,     ENT ,FN2 ,RALT,APP ,FN1K,    ,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_FN1] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     PWR ,SLEP, F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     COLE,    ,    ,BTN2,MS_U,BTN1,WH_U,     PGUP,HOME, UP ,END ,WSCH,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     QWER,    ,BTN3,MS_L,MS_D,MS_R,WH_D,     PGDN,LEFT,DOWN,RGHT,INS ,CALC,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     KYRI,LSFT,    ,MUTE,VOLD,VOLU,    ,         ,ACL2,ACL1,ACL0,    ,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,FN1X,LGUI,LALT,FN2X,    ,         ,FN2X,RALT,APP ,FN1X,RCTL,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_FN1K] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     PWR ,SLEP, F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     COLE,    ,    ,BTN2,MS_U,BTN1,WH_U,     PGUP,HOME, UP ,END ,WSCH,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     QWER,LSFT,BTN3,MS_L,MS_D,MS_R,WH_D,     PGDN,LEFT,DOWN,RGHT,INS ,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     KYRI,LCTL,    ,MUTE,VOLD,VOLU,    ,         ,ACL2,ACL1,ACL0,    ,RCTL,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,FN1L,LGUI,LALT,FN2X,    ,         ,FN2X,RALT,APP ,FN1L,RCTL,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_FN2] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,HASH,LBRC,RBRC,CIRC,         , 7  , 8  , 9  ,UNDS,    ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LSFT,TAB , AT ,LPRN,RPRN,PERC,     ASTR, 4  , 5  , 6  ,MINS,RSFT,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,LCTL,    ,DLR ,LCBR,RCBR,AMPR,      0  , 1  , 2  , 3  ,EXLM,RCTL,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,FN1X,LGUI,LALT,FN2X,    ,         ,FN2X,RALT,APP ,FN1X,    ,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),
};

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
  {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
  {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
};

static uint16_t alt_tab_timer = 0;

void matrix_scan_user() {
  if (alt_tab_timer != 0 && timer_elapsed(alt_tab_timer) > 1000) {
    alt_tab_timer = 0;
    unregister_code(KC_LALT);
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (IS_LAYER_ON(_FN2))
      tap_code((clockwise) ? KC_WH_U : KC_WH_D);
    else if (IS_LAYER_ON(_FN1))
      tap_code((clockwise) ? KC_LEFT : KC_RIGHT);
    else
      tap_code((clockwise) ? KC_PGUP : KC_PGDN);
  } else if (index == 1) { /* Second encoder */
    if (IS_LAYER_ON(_FN2))
      tap_code((clockwise) ? KC_VOLU : KC_VOLD);
    else if (IS_LAYER_ON(_FN1))
      tap_code((clockwise) ? KC_UP : KC_DOWN);
    else {
      if (alt_tab_timer == 0)
        register_code(KC_LALT);
      alt_tab_timer = timer_read();
      tap_code16((clockwise) ? KC_TAB : S(KC_TAB));
    }
  }
}
