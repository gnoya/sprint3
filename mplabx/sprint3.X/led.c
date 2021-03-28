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

static void set_pwm(int pwm)
{
  PWM4_LoadDutyValue((uint16_t)(255 - pwm));
}

static void set_red(int pwm)
{
  turn_selectors(1, 0);
  // 0 to 255
  set_pwm(pwm);
}

static void set_green(int pwm)
{
  turn_selectors(0, 1);
  // 0 to 255
  set_pwm(pwm);
}

static void set_blue(int pwm)
{
  turn_selectors(1, 1);
  // 0 to 255
  set_pwm(pwm);
}

static void high(void)
{
  set_red(255);
}

static void turn_off(void)
{
  turn_selectors(0, 0);
  set_pwm(0);
}

// ----------------------- Public functions ----------------------- //
void LED_Initialize(led_adapter *led)
{
  led->high = high;
  led->turn_off = turn_off;
  led->set_red = set_red;
  led->set_green = set_green;
  led->set_blue = set_blue;
}