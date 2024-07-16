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





void keyboard_pre_init_kb(void){
    // Workaround for reversible pcb/mcu
   // palSetLineMode(C13, PAL_MODE_OUTPUT_OPENDRAIN);
  //  palSetLineMode(B9, PAL_MODE_OUTPUT_OPENDRAIN);
   // palSetLineMode(B8, PAL_MODE_OUTPUT_OPENDRAIN);

   // keyboard_pre_init_user();
}

void board_init(void) {
    AFIO->MAPR |= AFIO_MAPR_USART1_REMAP | AFIO_MAPR_TIM3_REMAP_PARTIALREMAP;
}

#ifdef RGB_MATRIX_ENABLE

//void suspend_power_down_kb(void) {
//    rgb_matrix_set_suspend_state(true);
//    suspend_power_down_user();
//}
//
//void suspend_wakeup_init_kb(void) {
//    rgb_matrix_set_suspend_state(false);
//    suspend_wakeup_init_user();
//}

#endif