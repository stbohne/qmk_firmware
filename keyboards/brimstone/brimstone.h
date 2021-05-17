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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_all( \
    SW1 , SW9 , SW17, SW25, SW33, SW41,                         SW45, SW37, SW29, SW21, SW13, SW5 , \
    SW2 , SW10, SW18, SW26, SW34, SW42,                         SW46, SW38, SW30, SW22, SW14, SW6 , \
    SW3 , SW11, SW19, SW27, SW35, SW43,       DIP1, DIP2,       SW47, SW39, SW31, SW23, SW15, SW7 , \
    SW4 , SW12, SW20, SW28, SW36, SW44, SW54, SW56, SW63, SW62, SW48, SW40, SW32, SW24, SW16, SW8 , \
                      SW50, SW51, SW52, SW53, SW55, SW64, SW61, SW60, SW59, SW58 \
) { \
    { SW1 , SW9 , SW17, SW25, SW33, SW41, DIP2, DIP1 }, \
    { SW2 , SW10, SW18, SW26, SW34, SW42, SW50, SW58 }, \
    { SW3 , SW11, SW19, SW27, SW35, SW43, SW51, SW59 }, \
    { SW4 , SW12, SW20, SW28, SW36, SW44, SW52, SW60 }, \
    { SW5 , SW13, SW21, SW29, SW37, SW45, SW53, SW61 }, \
    { SW6 , SW14, SW22, SW30, SW38, SW46, SW54, SW62 }, \
    { SW7 , SW15, SW23, SW31, SW39, SW47, SW55, SW63 }, \
    { SW8 , SW16, SW24, SW32, SW40, SW48, SW56, SW64 }, \
}

#define LAYOUT_kc( \
    SW1 , SW9 , SW17, SW25, SW33, SW41,                         SW45, SW37, SW29, SW21, SW13, SW5 , \
    SW2 , SW10, SW18, SW26, SW34, SW42,                         SW46, SW38, SW30, SW22, SW14, SW6 , \
    SW3 , SW11, SW19, SW27, SW35, SW43,       DIP1, DIP2,       SW47, SW39, SW31, SW23, SW15, SW7 , \
    SW4 , SW12, SW20, SW28, SW36, SW44, SW54, SW56, SW63, SW62, SW48, SW40, SW32, SW24, SW16, SW8 , \
                      SW50, SW51, SW52, SW53, SW55, SW64, SW61, SW60, SW59, SW58 \
) { \
    { KC_##SW1 , KC_##SW9 , KC_##SW17, KC_##SW25, KC_##SW33, KC_##SW41, KC_##DIP2, KC_##DIP1 }, \
    { KC_##SW2 , KC_##SW10, KC_##SW18, KC_##SW26, KC_##SW34, KC_##SW42, KC_##SW50, KC_##SW58 }, \
    { KC_##SW3 , KC_##SW11, KC_##SW19, KC_##SW27, KC_##SW35, KC_##SW43, KC_##SW51, KC_##SW59 }, \
    { KC_##SW4 , KC_##SW12, KC_##SW20, KC_##SW28, KC_##SW36, KC_##SW44, KC_##SW52, KC_##SW60 }, \
    { KC_##SW5 , KC_##SW13, KC_##SW21, KC_##SW29, KC_##SW37, KC_##SW45, KC_##SW53, KC_##SW61 }, \
    { KC_##SW6 , KC_##SW14, KC_##SW22, KC_##SW30, KC_##SW38, KC_##SW46, KC_##SW54, KC_##SW62 }, \
    { KC_##SW7 , KC_##SW15, KC_##SW23, KC_##SW31, KC_##SW39, KC_##SW47, KC_##SW55, KC_##SW63 }, \
    { KC_##SW8 , KC_##SW16, KC_##SW24, KC_##SW32, KC_##SW40, KC_##SW48, KC_##SW56, KC_##SW64 }, \
}
