/* Copyright 2021 Stefan Bohne
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _GAMING,
    _LOWER
};

#define KC_ KC_NO
#define KC_GAMI MO(_GAMING)
#define KC_LOWR MO(_LOWER)
#define KC_LSBS MT(MOD_LSFT, KC_BSPC)
#define KC_RSQU MT(MOD_RSFT, KC_QUOT)
#define KC_LCES MT(MOD_LCTL, KC_ESC)
#define KC_RCBS MT(MOD_RCTL, KC_BSLS)
#define KC_LARI MT(MOD_LALT, KC_RGHT)
#define KC_LOSP LT(_LOWER, KC_SPC)
#define KC_LOEN LT(_LOWER, KC_ENT)
#define KC_RADN MT(MOD_RALT, KC_DOWN)
#define KC_SHTA SH_T(KC_TAB)
#define KC_SHEQ SH_T(KC_EQL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc(
        GRV , 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,MINS,
        SHTA, Q  , W  , E  , R  , T  ,                          Y  , U  , I  , O  , P  ,SHEQ,
        LSBS, A  , S  , D  , F  , G  ,       GAMI,GAMI,         H  , J  , K  , L  ,SCLN,RSQU,
        LCES, Z  , X  , C  , V  , B  ,HOME,END ,     PGUP,INS , N  , M  ,COMM,DOT ,SLSH,RCBS, 
                       LGUI,LEFT,LARI,LOSP,DEL ,     PGDN,LOEN,RADN, UP ,APP
    ),
    [_GAMING] = LAYOUT_kc(
        GRV , 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,MINS,
         B  ,TAB , Q  , W  , E  , R  ,                          Y  , U  , I  , O  , P  ,EQL ,
        ENT ,LSFT, A  , S  , D  , F  ,       GAMI,GAMI,         H  , J  , K  , L  ,SCLN,RSQU,
        ESC ,LCTL, Z  , X  , C  , V  , T  , G  ,     PGUP,INS , N  , M  ,COMM,DOT ,SLSH,RCBS, 
                       LGUI,    ,LALT,SPC ,LOWR,     PGDN,LOEN,RADN, UP ,APP
    ),
    [_LOWER] = LAYOUT_kc(
        F11 , F1 , F2 , F3 , F4 , F5 ,                             ,PSCR,SLCK,PAUS,    ,    ,
        F12 , F6 , F7 , F8 , F9 ,F10 ,                         PGUP,HOME, UP ,END ,    ,    ,
        LSFT,    ,    ,    ,    ,VOLU,       GAMI,GAMI,        PGDN,LEFT,DOWN,RGHT,    ,RSFT,
        LCTL,    ,    ,    ,    ,VOLD,    ,    ,         ,    ,    ,LCBR,RCBR,LBRC,RBRC,RCTL, 
                       LGUI,    ,LALT,SPC ,    ,         ,ENT ,RALT,    ,APP
    )
};

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 0}, {7, 0}},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {7, 1}, {6, 1}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {7, 2}, {6, 2}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {7, 3}, {6, 3}},
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {7, 4}, {6, 4}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {7, 5}, {6, 5}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {7, 7}, {6, 7}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {7, 6}, {6, 6}},
};
