// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 	0
#define _F_TRPT 	1
#define _SYMB   	2
#define _MOUSE 		3
#define _ADJUST 	5
#define _ARROW 		4



#define KC_ARR LT(_ARROW, KC_SPC)
#define SYM_L   LT(_SYMB, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
 ///
     */
    [_QWERTY] = LAYOUT(
    KC_ESC,  	KC_F1, 		KC_F2,   	KC_F3,   	KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,   	KC_F9,   	KC_F10,  	KC_F11,  	KC_F12,  	KC_NO, 	 		KC_NO,
    KC_GRV,  	KC_1,	    KC_2,    	KC_3,    	KC_4,   	KC_5,   	KC_6,  		KC_7,   	KC_8,    	KC_9,    	KC_0,    	KC_MINS, 	KC_EQL,  	KC_BSPC, 		KC_NO,
    KC_TAB,  	KC_Q,	    KC_W,    	KC_E,    	KC_R,   	KC_T,   	KC_PGUP,   	KC_HOME, 	KC_Y, 		KC_U,   	KC_I,    	KC_O,    	KC_P,    	KC_LBRC, 		KC_RBRC,
    SYM_L,   	KC_A,  		KC_S,    	KC_D,    	KC_F,   	KC_G,   	KC_PGDN,   	KC_END,		KC_H,		KC_J,   	KC_K,    	KC_L,    	KC_SCLN, 	KC_QUOT, 		KC_BSLS, 
    KC_LSFT, 	KC_Z,    	KC_X,    	KC_C,    	KC_V,   	KC_B,   	KC_DEL,   	KC_UP, 		KC_N, 		KC_M,   	KC_COMM, 	KC_DOT,  	KC_SLSH, 	RSFT_T(KC_ENT), KC_NO, 	
    KC_LCTL, 	KC_LGUI, 	KC_LALT, 	KC_LALT, 	KC_ARR, 	KC_SPC, 	KC_BSPC,	KC_LEFT, 	KC_DOWN,  	KC_RIGHT, 	KC_RCTL, 	KC_SPC,   	KC_PDOT, 	KC_ENT, 		KC_NO
  ), 	
    
    [_ARROW] = LAYOUT(
    RSFT(KC_A), XXXXXXX,  	XXXXXXX,   	XXXXXXX,   	XXXXXXX,  	XXXXXXX,  	XXXXXXX,  	XXXXXXX, 	XXXXXXX,   	XXXXXXX,   	XXXXXXX,	XXXXXXX, 	XXXXXXX,  	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 			XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX,    XXXXXXX,    XXXXXXX,	XXXXXXX, 	XXXXXXX,	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 			XXXXXXX,   	KC_UP,   	XXXXXXX,   	KC_WH_U,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,   	KC_7,	 	KC_8, 		KC_9,		XXXXXXX, 	XXXXXXX,
    KC_TRNS, 			KC_LEFT, 	KC_DOWN, 	KC_RIGHT,	KC_WH_D,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX,	XXXXXXX,   	KC_4,	 	KC_5, 		KC_6,	 	XXXXXXX, 	XXXXXXX,
    KC_TRNS, 			XXXXXXX,   	KC_X,    	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,   	KC_1,		KC_2, 		KC_3,	 	KC_TRNS, 	XXXXXXX,
    KC_TRNS, 			XXXXXXX, 	KC_LALT, 	KC_TRNS,  	KC_SPC, 	KC_SPC, 	KC_SPC, 	XXXXXXX, 	XXXXXXX,  	XXXXXXX, 	XXXXXXX,	KC_P0,  	KC_PDOT, 	KC_TRNS,	XXXXXXX
  ),
    
    [_SYMB] = LAYOUT(
    QK_BOOT, 	XXXXXXX,  	XXXXXXX,   	XXXXXXX,   	XXXXXXX,  	XXXXXXX,  	XXXXXXX,  	XXXXXXX, 	XXXXXXX,   	XXXXXXX,   	XXXXXXX,	XXXXXXX, 	XXXXXXX,  	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX,    XXXXXXX,    XXXXXXX,	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX,   	XXXXXXX,	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,
    KC_TRNS, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX,	XXXXXXX,   	XXXXXXX,	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX,   	XXXXXXX, 	XXXXXXX, 	XXXXXXX,   	XXXXXXX,	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,
    XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	KC_TRNS,  	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX, 	XXXXXXX,  	XXXXXXX, 	XXXXXXX,	XXXXXXX, 	XXXXXXX, 	XXXXXXX,	XXXXXXX
  )
};


