/*
 * File:   filter.c
 * Author: Group 2
 *
 * Created on April 10, 2021, 8:51 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include "filter.h"

/* We tried to initialize the size of the filter in the 
  FILTER_Initialize function, but the XC8 compiler doesn't support malloc.
  Our code was like this:
  // --------- globally:
  unsigned int *values = NULL;

  // --------- inside FILTER_Initialize(filter *audio_filter, int filter_size):
  values = malloc(sizeof(int) * filter_size);
*/

#define size 10
unsigned int values[size];
int head_index = 0;

/* This is not a real push and shift.
  This functions replaces the value that the head_index
  is pointing to. This index will always go from 0 to size.
*/
void push_and_shift(unsigned int value)
{
  // Replace the value at head_index
  values[head_index] = value;

  // Increase the head_index
  head_index = (head_index + 1) % size;
}

unsigned int average()
{
  unsigned int sum = 0;

  // Sum every value of the array
  for (int i = 0; i < size; i++)
  {
    sum += values[i];
  }

  // Return the average
  return (unsigned int)sum / size;
}

void FILTER_Initialize(filter *audio_filter)
{
  audio_filter->push_and_shift = push_and_shift;
  audio_filter->average = average;
}