/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File: motor.c
 * Author: Grupo 2
 * Comments:
 * Revision history: 
 */

typedef struct motor_adapter
{
  void (*step)(void);
  void (*set_direction)(bool direction);
  void (*swap_direction)(void);
} motor_adapter;

/**
  @Summary
    This functions changes the motor_state to the next one in CCW order

  @Param
    None

  @Returns
    None
*/
static void ccw();

/**
  @Summary
    This functions changes the motor_state to the next one in CW order

  @Param
    None

  @Returns
    None
*/
static void cw();

/**
  @Summary
    This functions changes the direction of the motor

  @Param
    bool direction: true for CW, false for CCW

  @Returns
    None
*/
static void set_direction(bool direction);

/**
  @Summary
    This functions make the motor do a step in a previously set direction

  @Param
    None

  @Returns
    None
*/
static void step();

/**
  @Summary
    This functions changes the direction of the motor

  @Param
    None

  @Returns
    None
*/
static void swap_direction();

/**
  @Summary
    This functions initialize the motor adapter

  @Param
    motor_adapter *motor: the motor object

  @Returns
    None
*/
void MOTOR_Initialize(motor_adapter *motor);