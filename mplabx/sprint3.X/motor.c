/*
 * File:   motor.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:45 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include "motor.h"

/*
  These are the combinations needed to make the motor do a step
  If you go from 0 to 3, it is Clockwise (CW) rotation
  If you go from 3 to 0, it is Counter Clockwise (CCW) rotation
*/
#define STEP_0 0 // 0 0 1 1
#define STEP_1 1 // 0 1 1 0
#define STEP_2 2 // 1 1 0 0
#define STEP_3 3 // 1 0 0 1

static int motor_state = STEP_0;
static bool motor_direction = true;

// 0 0 1 1
static void motor_state_0()
{
  MOTOR_A_SetLow();
  MOTOR_B_SetLow();
  MOTOR_C_SetHigh();
  MOTOR_D_SetHigh();
}

// 0 1 1 0
static void motor_state_1()
{
  MOTOR_A_SetLow();
  MOTOR_B_SetHigh();
  MOTOR_C_SetHigh();
  MOTOR_D_SetLow();
}

// 1 1 0 0
static void motor_state_2()
{
  MOTOR_A_SetHigh();
  MOTOR_B_SetHigh();
  MOTOR_C_SetLow();
  MOTOR_D_SetLow();
}

// 1 0 0 1
static void motor_state_3()
{
  MOTOR_A_SetHigh();
  MOTOR_B_SetLow();
  MOTOR_C_SetLow();
  MOTOR_D_SetHigh();
}

static void cw()
{
  motor_state = (motor_state + 1) % 4;
}

static void ccw()
{
  if (--motor_state < STEP_0)
    motor_state = STEP_3;
}

static void set_direction(bool direction)
{
  motor_direction = direction;
}

static void swap_direction()
{
  motor_direction = !motor_direction;
}

static void step()
{
  // Check direction to update the state
  if (motor_direction)
  {
    cw();
  }
  else
  {
    ccw();
  }

  /* This could've been optimized using an array but
    we were very short on memory.
  */
  switch (motor_state)
  {
  case STEP_0:
    motor_state_0();
    break;
  case STEP_1:
    motor_state_1();
    break;
  case STEP_2:
    motor_state_2();
    break;
  case STEP_3:
    motor_state_3();
    break;
  default:
    break;
  }
}

void MOTOR_Initialize(motor_adapter *motor)
{
  motor->step = step;
  motor->set_direction = set_direction;
  motor->swap_direction = swap_direction;
}