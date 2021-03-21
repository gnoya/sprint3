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
//int state = 0;                                  //Extern Variable

void give_feedback(void)
{
    printf("feedback  \n\r");
    switch (state)
    {
    case LOW_LIGHT_STATE:
        IO_RC0_SetHigh();
        IO_RC1_SetLow();
        IO_RC2_SetLow();
        IO_RC4_SetLow();
        feedback = false;
      break;
    case HIGH_LIGHT_STATE:
        IO_RC0_SetLow();
        IO_RC1_SetHigh();
        IO_RC2_SetLow();
        IO_RC4_SetLow();
        feedback = false;
      break;
    case MUSIC_STATE:
        IO_RC0_SetLow();
        IO_RC1_SetLow();
        IO_RC2_SetHigh();
        IO_RC4_SetLow();
        feedback = false;
      break;
    case DMX_STATE:
        IO_RC0_SetLow();
        IO_RC1_SetLow();
        IO_RC2_SetLow();
        IO_RC4_SetHigh();
        feedback = false;
      break;
    default:
      break;
    }
}


void debouncing_ISR(void)
{
  printf("debouncing ISR \n\r");
  TMR1_InterruptDisable();
  debouncing = false;
}

void button_ISR(void)
{
  if (debouncing)
      return;
  
  debouncing = true;
  feedback = true;
  TMR1_InterruptEnable();
  
  state = (state + 1) % 4;
  
}