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

static void set_red(int pwm);
static void set_green(int pwm);
static void set_blue(int pwm);

static void set_red(int pwm)
{
  // 0 to 255
  PWM3_LoadDutyValue((uint16_t)pwm);
}

static void set_green(int pwm)
{
  // 0 to 255
  PWM2_LoadDutyValue((uint16_t)pwm);
}

static void set_blue(int pwm)
{
  // 0 to 255
  PWM1_LoadDutyValue((uint16_t)pwm);
}

static void low(void)
{
  set_red(80);
  set_green(0);
  set_blue(0);
}

static void high(void)
{
  set_red(255);
  set_green(0);
  set_blue(0);
}

static void turn_off(void)
{
  set_red(0);
  set_green(0);
  set_blue(0);
}
/*
static void turn_on(void)
{
  set_red(0);
  set_green(255);
  set_blue(0);
}
*/

// ----------------------- Public functions ----------------------- //
void LED_Initialize(led_adapter *led)
{
  led->low = low;
  led->high = high;
  led->turn_off = turn_off;
  // led->turn_on = turn_on;
}