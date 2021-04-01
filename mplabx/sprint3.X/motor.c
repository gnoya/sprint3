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

#define STEP_0 0 // 0 0 1 1
#define STEP_1 1 // 0 1 1 0
#define STEP_2 2 // 1 1 0 0
#define STEP_3 3 // 1 0 0 1

static int motor_state = STEP_0;

static void motor_state_0()
{
  MOTOR_A_SetLow();
  MOTOR_B_SetLow();
  MOTOR_C_SetHigh();
  MOTOR_D_SetHigh();
}

static void motor_state_1()
{
  MOTOR_A_SetLow();
  MOTOR_B_SetHigh();
  MOTOR_C_SetHigh();
  MOTOR_D_SetLow();
}

static void motor_state_2()
{
  MOTOR_A_SetHigh();
  MOTOR_B_SetHigh();
  MOTOR_C_SetLow();
  MOTOR_D_SetLow();
}

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

static void step(bool direction)
{
  if (direction)
  {
    cw();
  }
  else
  {
    ccw();
  }

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
}