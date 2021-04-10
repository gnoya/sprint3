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

#define RED 0
#define GREEN 1
#define BLUE 2

static int current_color = RED;
static int current_brightness = 0;

static int music_counter = 0;
static unsigned int music_sample_limit = 20;
static unsigned int music_color_limit = 2500;
static unsigned int measures = 0; 

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
  current_brightness = pwm;
  PWM4_LoadDutyValue((uint16_t)(pwm));
}

static void turn_red(void)
{
  current_color = RED;
  turn_selectors(1, 0);
}

static void turn_green(void)
{
  current_color = GREEN;
  turn_selectors(0, 1);
}

static void music(void)
{
    measures += (unsigned int)ADC_GetConversion(0x02);
    music_counter++;
    
    if (music_counter > music_sample_limit){
        music_counter = 0;
        printf("%u \r\n",(measures/music_sample_limit));
        if ((measures/music_sample_limit) > music_color_limit){
            printf("cambio\r\n");
        }
       
    }
    
}
static void turn_blue(void)
{
  current_color = BLUE;
  turn_selectors(1, 1);
}

static void turn_on(void)
{
  // Turns on using the current color
  switch (current_color)
  {
  case RED:
    turn_red();
    break;
  case GREEN:
    turn_green();
    break;
  case BLUE:
    turn_blue();
    break;
  default:
    break;
  }

  // Turns on using the current brightness
  set_brightness(current_brightness);
}

static void turn_off(void)
{
  turn_selectors(0, 0);
  set_brightness(0);
}

// ----------------------- Public functions ----------------------- //
void LED_Initialize(led_adapter *led)
{
  led->turn_on = turn_on;
  led->turn_off = turn_off;
  led->turn_red = turn_red;
  led->turn_green = turn_green;
  led->turn_blue = turn_blue;
  led->set_brightness = set_brightness;
  led->music = music;
}