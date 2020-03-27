/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "split_util.h"

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define KC_ KC_NO
#define KC_PULA MT(MOD_LALT, KC_PGUP)
#define KC_PDRA MT(MOD_RALT, KC_PGDN)
#define KC_LSBS MT(MOD_LSFT, KC_BSPC)
#define KC_RSQU MT(MOD_RSFT, KC_QUOT)
#define KC_LCES MT(MOD_LCTL, KC_ESC)
#define KC_RCBS MT(MOD_RCTL, KC_BSLS)
#define KC_SHTA SH_T(KC_TAB)
#define KC_SHEQ SH_T(KC_EQL)

#define KC_LSGR MT(MOD_LSFT, KC_GRV)
#define KC_RSMI MT(MOD_RSFT, KC_MINS)

#define KC_RALE LT(_RAISE, KC_LEFT)
#define KC_LARI MT(MOD_LALT, KC_RGHT)
#define KC_LOSP LT(_LOWER, KC_SPC)
#define KC_CAPU MT(MOD_LCTL | MOD_LALT, KC_PGUP)
#define KC_SCIN MT(MOD_LSFT | MOD_LCTL, KC_INS)
#define KC_MEHO MT(MOD_LSFT | MOD_LCTL | MOD_LALT, KC_HOME)

#define KC_MEEN MT(MOD_RSFT | MOD_RCTL | MOD_RALT, KC_END)
#define KC_SCDE MT(MOD_RSFT | MOD_RCTL, KC_DEL)
#define KC_CAPD MT(MOD_RCTL | MOD_RALT, KC_PGDN)
#define KC_LOEN LT(_LOWER, KC_ENT)
#define KC_RAUP MT(MOD_RALT, KC_UP)
#define KC_RADN LT(_RAISE, KC_DOWN)

#define KC_LWR MO(_LOWER)
#define KC_RAIS MO(_RAISE)
#define KC_LSC MT(MOD_LSFT | MOD_LCTL, KC_NO)
#define KC_LCA MT(MOD_LCTL | MOD_LALT, KC_NO)
#define KC_LSA MT(MOD_LSFT | MOD_LALT, KC_NO)
#define KC_LSCA MT(MOD_LSFT | MOD_LCTL | MOD_LALT, KC_NO)
#define KC_RSC MT(MOD_RSFT | MOD_RCTL, KC_NO)
#define KC_RCA MT(MOD_RCTL | MOD_RALT, KC_NO)
#define KC_RSA MT(MOD_RSFT | MOD_RALT, KC_NO)
#define KC_RSCA MT(MOD_RSFT | MOD_RCTL | MOD_RALT, KC_NO)
#define KC_LCDE MT(MOD_LCTL, KC_DEL)

#define KC_RTOG RGB_TOG
#define KC_RSAI RGB_SAI
#define KC_RHUI RGB_HUI
#define KC_RVAI RGB_VAI
#define KC_RSAD RGB_SAD
#define KC_RHUD RGB_HUD
#define KC_RVAD RGB_VAD
#define KC_RMD  RGB_MOD
#define KC_RRMD RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     SHTA, Q  , W  , E  , R  , T  ,                          Y  , U  , I  , O  , P  ,SHEQ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LSBS, A  , S  , D  , F  , G  ,                          H  , J  , K  , L  ,SCLN,RSQU,
  //|----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----|
     LCES, Z  , X  , C  , V  , B  ,SCIN,MEHO,     MEEN,SCDE, N  , M  ,COMM,DOT ,SLSH,RCBS,
  //`----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----'
                    LGUI,RALE,LARI,LOSP,CAPU,     CAPD,LOEN,RAUP,RADN,APP
  //               `----+----+----+----+----'    `----+----+----+----+----'
    ),
    [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TILD, 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,UNDS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LSGR,EXLM, AT ,HASH,DLR ,PERC,                         CIRC,AMPR,ASTR,LPRN,RPRN,RSMI,
  //|----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,LSC ,LSCA,     RSCA,RSC ,    ,LCBR,RCBR,LBRC,RBRC,RCTL,
  //`----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----'
                    LGUI,RAIS,LALT,    ,LCA ,     RCA ,    ,RALT,RAIS,APP
  //               `----+----+----+----+----'    `----+----+----+----+----'
    ),
    [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
         ,    ,BTN2,MS_U,BTN1,WH_U,                         PGUP,HOME, UP ,END ,    ,    ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LSFT,BTN3,MS_L,MS_D,MS_R,WH_D,                         PGDN,LEFT,DOWN,RGHT,    ,RSFT,
  //|----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,LSC ,LSCA,     RSCA,RSC ,    ,ACL2,ACL1,ACL0,    ,RCTL,
  //`----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----'
                    LGUI,    ,LALT,LWR ,LCA ,     RCA ,LWR ,RALT,    ,APP
  //               `----+----+----+----+----'    `----+----+----+----+----'
    ),
    [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                          F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LSFT,RTOG,RSAI,RHUI,RVAI,RMD ,                             ,    ,    ,    ,    ,RSFT,
  //|----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----|
     LCTL,    ,RSAD,RHUD,RVAD,RRMD,LSC ,LSCA,     RSCA,RSC ,    ,    ,    ,    ,    ,RCTL,
  //`----+----+----+----+----+----+----+----|    |----+----+----+----+----+----+----+----'
                    LGUI,    ,LALT,    ,LCA ,     RCA ,    ,RAIS,    ,APP
  //               `----+----+----+----+----'    `----+----+----+----+----'
    ),
};

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}, {7, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {7, 7}},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}},
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_layout_left(void) {
    // QMK Logo and version information
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("TabQ W E R T \n"), false);
            oled_write_P(PSTR("BspA S D F G \n"), false);
            oled_write_P(PSTR("EscZ X C V B InPU\n"), false);
            oled_write_P(PSTR("       WiLeRiSpHo"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("~  1 2 3 4 5 \n"), false);
            oled_write_P(PSTR("`  ! @ # $ % \n"), false);
            oled_write_P(PSTR("Del              \n"), false);
            oled_write_P(PSTR("       Wi        "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("     M2MUM1WU\n"), false);
            oled_write_P(PSTR("   M3MLMDMRWD\n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("       Wi        "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("F1 F2F3F4F5F6\n"), false);
            oled_write_P(PSTR("   TgSaHuVaMd\n"), false);
            oled_write_P(PSTR("     SaHuVaMd    \n"), false);
            oled_write_P(PSTR("       Wi        "), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

static void render_layout_right(void) {
    // QMK Logo and version information
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("    Y U I O P +  \n"), false);
            oled_write_P(PSTR("    H J K L ;:'\" \n"), false);
            oled_write_P(PSTR("PDDeN M ,<.>/?\\| \n"), false);
            oled_write_P(PSTR("EdEtUpDnWi"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("    6 7 8 9 0 _  \n"), false);
            oled_write_P(PSTR("    ^ & * ( ) -  \n"), false);
            oled_write_P(PSTR("      { } [ ]    \n"), false);
            oled_write_P(PSTR("        Wi"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("    PUHoUpEd     \n"), false);
            oled_write_P(PSTR("    PDLeDnRi     \n"), false);
            oled_write_P(PSTR("      A2A1A0     \n"), false);
            oled_write_P(PSTR("        Wi"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("    F7F8F9F0F1F12\n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("                 \n"), false);
            oled_write_P(PSTR("        Wi"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

void oled_task_user(void) {
    if (isLeftHand) {
        render_layout_left();
    } else {
        render_layout_right();
    }
}
#endif
