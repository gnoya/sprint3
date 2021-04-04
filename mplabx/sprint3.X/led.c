/*
 * File:   led.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:45 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include "led.h"

static void turn_selectors(bool selector1, bool selector2)
{
  if (selector1)
  {
    LED_SELECTOR_1_SetHigh();
  }
  else
  {
    LED_SELECTOR_1_SetLow();
  }

  if (selector2)
  {
    LED_SELECTOR_2_SetHigh();
  }
  else
  {
    LED_SELECTOR_2_SetLow();
  }
}

static void set_brightness(int pwm)
{
  PWM4_LoadDutyValue((uint16_t)(255 - pwm));
}

static void turn_red(void)
{
  turn_selectors(1, 0);
}

static void turn_green(void)
{
  turn_selectors(0, 1);
}

static void turn_blue(void)
{
  turn_selectors(1, 1);
}

static void high(void)
{
  turn_red();
  set_brightness(255);
}

static void turn_off(void)
{
  turn_selectors(0, 0);
  set_brightness(0);
}

// ----------------------- Public functions ----------------------- //
void LED_Initialize(led_adapter *led)
{
  led->high = high;
  led->turn_off = turn_off;
  led->turn_red = turn_red;
  led->turn_green = turn_green;
  led->turn_blue = turn_blue;
  led->set_brightness = set_brightness;
}