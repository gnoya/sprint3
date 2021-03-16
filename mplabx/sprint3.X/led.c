/*
 * File:   led.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:45 PM
 */

#include <stdio.h>
#include <stdbool.h>
#include "led.h"

static void low(void)
{
  // PWM3_LoadDutyValue(50);
  printf("Low\r\n");
}

static void high(void)
{
  // PWM3_LoadDutyValue(0);
  printf("High\r\n");
}

static void turn_off(void)
{
  // PWM3_LoadDutyValue(255);
  printf("Off\r\n");
}

static void turn_on(void)
{
  // PWM3_LoadDutyValue(0);
  printf("On\r\n");
}

// ----------------------- Public functions ----------------------- //
void LED_Initialize(led_adapter *led)
{
  led->low = low;
  led->high = high;
  led->turn_off = turn_off;
  led->turn_on = turn_on;
}