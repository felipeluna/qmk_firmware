/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2023 Elliot Powell

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

<<<<<<< HEAD:keyboards/lily58/keymaps/mb_via/config.h
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

=======
// row-driven
#define MATRIX_ROW_PINS { GP20, GP19, GP18, GP17, GP16 }
#define MATRIX_COL_PINS { GP9, GP10, GP11, GP12, GP13, GP14 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
>>>>>>> a6cfd7f221 (error):keyboards/handwired/dactyl_manuform/4x6_5/config.h
