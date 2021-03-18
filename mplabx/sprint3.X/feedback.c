/*
 * File:   feedback.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */

#include "mcc_generated_files/mcc.h"
#include "feedback.h"

#define LOW_LIGHT_STATE 0
#define HIGH_LIGHT_STATE 1
#define MUSIC_STATE 2
#define DMX_STATE 3

static bool debouncing = false;
int state = 0;

void give_feedback(void)
{
    switch (state)
    {
    case LOW_LIGHT_STATE:
        IO_RC4_SetLow();
        IO_RC5_SetLow();
        IO_RC6_SetHigh();
        feedback = false;
      break;
    case HIGH_LIGHT_STATE:
        IO_RC4_SetLow();
        IO_RC5_SetHigh();
        IO_RC6_SetLow();
        feedback = false;
      break;
    case MUSIC_STATE:
        IO_RC4_SetHigh();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        feedback = false;
      break;
    case DMX_STATE:
        IO_RC4_SetHigh();
        IO_RC5_SetHigh();
        IO_RC6_SetHigh();
        feedback = false;
      break;
    default:
      break;
    }
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