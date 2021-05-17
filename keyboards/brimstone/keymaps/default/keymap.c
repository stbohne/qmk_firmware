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
#define KC_LOWR MO(_LOWER)
#define KC_LSBS MT(MOD_LSFT, KC_BSPC)
#define KC_RSQU MT(MOD_RSFT, KC_QUOT)
#define KC_LCES MT(MOD_LCTL, KC_ESC)
#define KC_RCBS MT(MOD_RCTL, KC_BSLS)
#define KC_LARI MT(MOD_LALT, KC_RGHT)
#define KC_LOSP LT(_LOWER, KC_SPC)
#define KC_LOEN LT(_LOWER, KC_ENT)
#define KC_RADN MT(MOD_RALT, KC_DOWN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc(
        GRV , 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,MINS,
        TAB , Q  , W  , E  , R  , T  ,                          Y  , U  , I  , O  , P  ,EQL ,
        LSBS, A  , S  , D  , F  , G  ,           ,    ,         H  , J  , K  , L  ,SCLN,RSQU,
        LCES, Z  , X  , C  , V  , B  ,HOME,END ,     PGUP,INS , N  , M  ,COMM,DOT ,SLSH,RCBS, 
                       LGUI,LEFT,LARI,LOSP,DEL ,     PGDN,LOEN,RADN, UP ,APP
    ),
    [_LOWER] = LAYOUT_kc(
        F11 , F1 , F2 , F3 , F4 , F5 ,                             ,PSCR,SLCK,PAUS,    ,    ,
        F12 , F6 , F7 , F8 , F9 ,F10 ,                         PGUP,HOME, UP ,END ,    ,    ,
        LSFT,    ,    ,    ,    ,VOLU,           ,    ,        PGDN,LEFT,DOWN,RGHT,    ,RSFT,
        LCTL,    ,    ,    ,    ,VOLD,    ,    ,         ,    ,    ,LCBR,RCBR,LBRC,RBRC,RCTL, 
                       LGUI,    ,LALT,SPC ,    ,         ,ENT ,RALT,    ,APP
    )
};
