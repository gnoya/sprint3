/*
 * File:   feedback.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */

#include "mcc_generated_files/mcc.h"
#include "feedback.h"

static bool debouncing = false;
int state = 0;

void give_feedback(void)
{
}


void debouncing_ISR(void)
{
  TMR5_InterruptDisable();
  debouncing = false;
}

void button_ISR(void)
{
  if (debouncing)
      return;
  
  debouncing = true;
  feedback = true;
  TMR5_InterruptEnable();
  
  state = (state + 1) % 4;
  
}