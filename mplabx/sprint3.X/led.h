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
  void (*turn_red)(void);
  void (*turn_green)(void);
  void (*turn_blue)(void);
  void (*set_brightness)(int pwm);
  void (*next_color)(void);
} led_adapter;

/**
  @Summary
    This functions turns off the led by changing the duty cycle of the PWM

  @Param
    None

  @Returns
    None
*/
static void turn_off(void);

/**
  @Summary
    This functions turns on the led using the color and brightness stored values

  @Param
    None

  @Returns
    None
*/
static void turn_on(void);

/**
  @Summary
    This functions changes the color of the LEDs to red

  @Param
    None

  @Returns
    None
*/
static void turn_red(void);

/**
  @Summary
    This functions changes the color of the LEDs to green

  @Param
    None

  @Returns
    None
*/
static void turn_green(void);

/**
  @Summary
    This functions changes the color of the LEDs to blue

  @Param
    None

  @Returns
    None
*/
static void turn_blue(void);

/**
  @Summary
    This functions changes the brightness of the LED given a PWM

  @Param
    int pwm: value from 0 (minimum bright) to 255 (maximum bright)

  @Returns
    None
*/
static void set_brightness(int pwm);

/**
  @Summary
    This functions changes the selectos of the LED demux

  @Param
    bool selector1: changes the value of the selector 1
    bool selector2: changes the value of the selector 2
    
  @Returns
    None
*/
static void turn_selectors(bool selector1, bool selector2);

/**
  @Summary
    This functions changes the color to the next (Order: RED -> GREEN -> BLUE)

  @Param
    None

  @Returns
    None
*/
static void next_color(void);

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
