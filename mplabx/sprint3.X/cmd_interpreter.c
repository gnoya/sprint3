/*
 * File:   cmd_interpreter.c
 * Author: Grupo 2
 *
 * Created on March 15, 2021, 5:47 PM
 */

#include "mcc_generated_files/mcc.h"
#include "led.h"
#include "motor.h"

#define LED_BLUE 0
#define LED_GREEN 1
#define LED_RED 2

#define LED_TURN_OFF 3
#define LED_TURN_ON 4

#define LED_BRIGHT_LOW 5
#define LED_BRIGHT_MEDIUM 6
#define LED_BRIGHT_HIGH 7

#define MOTOR_DIRECTION_CCW 8
#define MOTOR_DIRECTION_CW 9

#define MOTOR_SPEED_SET 10

extern led_adapter led;
extern motor_adapter motor;

static int temp_state = 0;
static int temp_counter = 0;

static void led_commands()
{
  switch (temp_state)
  {
  case LED_BLUE:
    printf("LED command: set blue\r\n");
    led.turn_blue();
    break;

  case LED_GREEN:
    printf("LED command: set green\r\n");
    led.turn_green();
    break;

  case LED_RED:
    printf("LED command: set red\r\n");
    led.turn_red();
    break;

  case LED_TURN_OFF:
    printf("LED command: turn down\r\n");
    led.turn_off();
    break;

  case LED_TURN_ON:
    printf("LED command: turn on\r\n");
    led.turn_on();
    break;

  case LED_BRIGHT_LOW:
    printf("LED command: set low brightness\r\n");
    led.set_brightness(55);
    break;

  case LED_BRIGHT_MEDIUM:
    printf("LED command: set medium brightness\r\n");
    led.set_brightness(155);
    break;
  case LED_BRIGHT_HIGH:
    printf("LED command: set high brightness\r\n");
    led.set_brightness(255);
    break;

  default:
    break;
  }
}

static void motor_commands()
{
  switch (temp_state)
  {

  case MOTOR_DIRECTION_CCW:
    printf("MOTOR command: CCW direction\r\n");
    motor.set_direction(false);
    break;

  case MOTOR_DIRECTION_CW:
    printf("MOTOR command: CW direction\r\n");
    motor.set_direction(true);
    break;

  case MOTOR_SPEED_SET:
    // Aqui hay que modificar el tiempo de interrupción del TMR2.
    // Cuidado porque este mismo timer se utiliza para los PWM
    // Y no se si afecte su funcionamiento.
    break;
  default:
    break;
  }
}

void command()
{
  // Added this counter so the states last longer
  if (temp_counter++ >= 3)
  {
    temp_counter = 0;
    led_commands();
    motor_commands();
    temp_state = (temp_state + 1) % 11;
  }
}