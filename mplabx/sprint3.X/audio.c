/*
 * File:   sound.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:43 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include "audio.h"
#include "led.h"
#include "filter.h"

#define AVERAGE_THRESHOLD 2500

extern led_adapter led;
static filter audio_filter;

static void measure(void)
{
  // Measure the value using the ADC
  unsigned int measured_value = (unsigned int)ADC_GetConversion(0x02);

  // Push the value to the filter
  audio_filter.push_and_shift(measured_value);

  // Calculate the average of the values in the filter
  unsigned int filter_average = audio_filter.average();

  printf("Average: %d\r\n", filter_average);

  // If the average is greater than a threshold, change the color of the LED
  if (filter_average >= AVERAGE_THRESHOLD)
  {
    led.next_color();
  }
}

void AUDIO_Initialize(audio_adapter *audio)
{
  audio->measure = measure;
  FILTER_Initialize(&audio_filter);
}
