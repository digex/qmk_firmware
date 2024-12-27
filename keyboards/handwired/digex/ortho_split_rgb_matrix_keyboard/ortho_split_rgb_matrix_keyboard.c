/* Copyright 2021 qmk 
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


#include "quantum.h"


void keyboard_pre_init_kb(void){

//disable onboard led
	gpio_set_pin_output(GP23);
	gpio_write_pin_low(GP23);
//
    keyboard_pre_init_user();
}


#ifdef RGB_MATRIX_ENABLE
HSV color_my;
HSV color1 = {HSV_TURQUOISE}; 
HSV color2 = {HSV_YELLOW};
HSV color3 = {HSV_PINK};
HSV color4 = {HSV_GREEN};
HSV color5 = {HSV_RED};
HSV hsv_Orang = {HSV_ORANGE};
RGB color_my_rgb;

#endif

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {

#ifdef RGB_MATRIX_ENABLE
	uint8_t layer = get_highest_layer(layer_state);	
	
	// определчем цвета

	// получаем яркость
	color1.v = rgb_matrix_get_val();
	color2.v = rgb_matrix_get_val();
	color3.v = rgb_matrix_get_val();
	color4.v = rgb_matrix_get_val();
	color_my.v= rgb_matrix_get_val();
	hsv_Orang.v = rgb_matrix_get_val();
	// переводим в rgb
	//RGB color1_rgb = hsv_to_rgb(color1);
	//RGB color2_rgb = hsv_to_rgb(color2);
	//RGB color3_rgb = hsv_to_rgb(color3);
	//RGB color4_rgb = hsv_to_rgb(color4);

	
	 if (get_highest_layer(layer_state) > 0) {

 			
    	switch (get_highest_layer(layer_state)) {
        	case 1:
        		color_my_rgb   = hsv_to_rgb(color1);
        		break;
        	case 2:
        		color_my_rgb   = hsv_to_rgb(color2);
        		break;
        	case 3:
        		color_my_rgb   = hsv_to_rgb(color3);
        		break;
        	case 4:
        		color_my_rgb   = hsv_to_rgb(color4);
        		break;
        	case 5:
        		color_my_rgb   = hsv_to_rgb(color5);
        		break;
        }
    	

		
		if (get_highest_layer(layer_state) == 5)  {
		
			for (uint8_t i = led_min; i <= 34; i++) 
			{
			        rgb_matrix_set_color(i, RGB_OFF);
			}
		}
		else
		{
			for (uint8_t i = led_min; i <= led_max; i++) 
			{
			        rgb_matrix_set_color(i, RGB_OFF);
			}
		}
    	
    	
        
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) 
        {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) 
            {
                uint8_t index = g_led_config.matrix_co[row][col];

				switch (layer) {
					case 5:
                		if (index >= led_min && index <= 34 && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS ) 
                		{
        					rgb_matrix_set_color(index, color_my_rgb.r, color_my_rgb.g, color_my_rgb.b);
            			}
					break;
					default:
                		if (index >= led_min && index <= led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS ) 
                		{
        					rgb_matrix_set_color(index, color_my_rgb.r, color_my_rgb.g, color_my_rgb.b);

            			}
            		}
            }
        
        }
    }
    
        if (host_keyboard_led_state().caps_lock) 
        {
        	RGB orange_1 = hsv_to_rgb(hsv_Orang);
        	rgb_matrix_set_color(14, orange_1.r, orange_1.g, orange_1.b);
    	}
    	
        if (host_keyboard_led_state().num_lock) // Num Lock status
        {
            
            if (layer == 4)  { // is layer arrow
            
            RGB orange_1 = hsv_to_rgb(hsv_Orang);
            rgb_matrix_set_color(48 , orange_1.r, orange_1.g, orange_1.b);
            }
        }



    	#endif
   return true;
}


void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    //suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    //suspend_wakeup_init_user();
}
