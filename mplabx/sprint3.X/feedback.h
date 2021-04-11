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
    This functions will set the demux selectors to do feedback of the
    HIGH_LIGHT_STATE

  @Param
    None

  @Returns
    None
*/
static void high_light_feedback(void);

/**
  @Summary
    This functions will set the demux selectors to do feedback of the
    MUSIC_STATE

  @Param
    None

  @Returns
    None
*/
static void music_feedback(void);

/**
  @Summary
    This functions will set the demux selectors to do feedback of the
    DMX_STATE

  @Param
    None

  @Returns
    None
*/
static void dmx_feedback(void);

/**
  @Summary
    This functions will set the demux selectors to do feedback of the
    SLEEP_STATE

  @Param
    None

  @Returns
    None
*/
static void sleep_feedback(void);

/**
  @Summary
    This functions turns the demux selectors given two booleans

  @Param
    bool selector1: changes the value of the selector 1
    bool selector2: changes the value of the selector 2

  @Returns
    None
*/
static void turn_selectors(bool selector1, bool selector2);

/**
  @Summary
    This functions changes the feedback LED values given a state

  @Param
    int state: state of the system

  @Returns
    None
*/
void feedback(int state);

/**
  @Summary
    This functions handles the deboucing effect

  @Param
    None

  @Returns
    None
*/
void debouncing_ISR(void);

/**
  @Summary
    This functions handles the button press interrupt and changes
    the state of the system to the next one

  @Param
    None

  @Returns
    None
*/
void button_ISR(void);

/**
  @Summary
    This functions initializes the feedback module

  @Param
    None

  @Returns
    None
*/
void FEEDBACK_Initialize(void);