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
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

/**
  @Summary
    This struct is used to control the LEDs of the system

  @Description
    This struct is used to control the LEDs of the system
*/
typedef struct led_adapter
{
  void (*turn_off)(void);
  void (*turn_on)(void);
  void (*high)(void);
  void (*set_red)(int pwm);
  void (*set_green)(int pwm);
  void (*set_blue)(int pwm);

} led_adapter;

/**
  @Summary
    This functions turns on the led on high bright 

  @Description
    This functions turns on the led on high bright by changing the duty cycle of the PWM

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void high(void);

/**
  @Summary
    This functions turns off the led

  @Description
    This functions turns off the led by changing the duty cycle of the PWM

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void turn_off(void);

/**
  @Summary
    This functions turns on the led to the maximum brightness

  @Description
    This functions turns on the led by changing the duty cycle of the PWM

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
static void turn_on(void);

/**
  @Summary
    Initializes the led adapter

  @Description
    This function assigns the static functions to the led adapter

  @Preconditions
    None

  @Param
    led_adapter *led

  @Returns
    None
*/
void LED_Initialize(led_adapter *led);

static void set_red(int pwm);
static void set_green(int pwm);
static void set_blue(int pwm);
static void set_pwm(int pwm);
static void turn_selectors(bool selector1, bool selector2);