/*
 * File:   temp_sensor.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */
#include "mcc_generated_files/mcc.h"

#define SLEEP_STATE 3

extern int state;
extern bool state_changed;
static unsigned int temp_limit = 38592;

void temp_ISR(void)
{
  unsigned int temp = (unsigned int)ADC_GetTemp();
  if (temp >= temp_limit)
  {
    printf("System temperature is too high, setting SLEEP STATE\r\n");
    state_changed = true;
    state = SLEEP_STATE;
  }
}