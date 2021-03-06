/*
 * File:   feedback.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include "feedback.h"
#include "eeprom.h"
#include "led.h"

#define HIGH_LIGHT_STATE 0 // selectors: 1 0
#define MUSIC_STATE 1      // selectors: 0 1
#define DMX_STATE 2        // selectors: 1 1
#define SLEEP_STATE 3      // selectors: 0 0

extern int state;
static bool debouncing = false;
bool state_changed = true;
static led_adapter leds[4];

static void turn_selectors(bool selector1, bool selector2)
{
  if (selector1)
  {
    FB_SELECTOR_1_SetHigh();
  }
  else
  {
    FB_SELECTOR_1_SetLow();
  }

  if (selector2)
  {
    FB_SELECTOR_2_SetHigh();
  }
  else
  {
    FB_SELECTOR_2_SetLow();
  }
}

static void high_light_feedback(void)
{
  turn_selectors(1, 0);
}

static void music_feedback(void)
{
  turn_selectors(0, 1);
}

static void dmx_feedback(void)
{
  turn_selectors(1, 1);
}

static void sleep_feedback(void)
{
  turn_selectors(0, 0);
}

void feedback(int state)
{
  printf("State: %d \r\n", state);
  state_changed = false;
  leds[state].turn_on();
}

void debouncing_ISR(void)
{
  TMR1_InterruptDisable();
  debouncing = false;
}

void button_ISR(void)
{
  if (debouncing)
    return;

  // Preventing bouncing effect
  debouncing = true;
  TMR1_InterruptEnable();

  // State changed
  state_changed = true;

  // Updating state
  state = (state + 1) % 4;
}

void FEEDBACK_Initialize()
{
  /* Is this a bad practice ?
   * Using the turn_on function to also
   * turn down the other LEDs
  */
  leds[0].turn_on = high_light_feedback;
  leds[1].turn_on = music_feedback;
  leds[2].turn_on = dmx_feedback;
  leds[3].turn_on = sleep_feedback;
}