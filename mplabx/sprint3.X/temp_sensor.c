/*
 * File:   temp_sensor.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */
#include "mcc_generated_files/mcc.h"

extern int state;
unsigned int tempLimit = 38592;

void temp_ISR(void){
    unsigned int  temp = (unsigned int)ADC_GetTemp();
    if (temp >= tempLimit)
    {
        printf("Caliente\r\n");
        state = 3;
    }
}