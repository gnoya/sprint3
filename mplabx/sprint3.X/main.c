/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "led.h"
#include "eeprom.h"
#include "feedback.h"
#include "temp_sensor.h"
#include "motor.h"
#include <stdbool.h>

#define HIGH_LIGHT_STATE 0
#define MUSIC_STATE 1
#define DMX_STATE 2
#define SLEEP_STATE 3

led_adapter led;
eeprom_adapter eeprom;
motor_adapter motor;
int state = HIGH_LIGHT_STATE;
bool main_interrupt = false;
bool state_changed;

void main_ISR();

void main_ISR()
{
  main_interrupt = true;
}

void main(void)
{
  // ---------------- Initializing led and menu ---------------- //
  SYSTEM_Initialize();
  LED_Initialize(&led);
  EEPROM_Initialize(&eeprom);
  FEEDBACK_Initialize();
  MOTOR_Initialize(&motor);

  // ------------------ Enabling Interrupts --------------------- //
  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  // ------------ Setting button's Interrupt Handler ------------ //
  IOCAF5_SetInterruptHandler(button_ISR);

  //------------- Setting Timer Interrupt Handlers --------------//
  TMR0_SetInterruptHandler(temp_ISR);
  TMR1_SetInterruptHandler(debouncing_ISR);
  TMR2_SetInterruptHandler(main_ISR);

  // --------------------- Reading EEPROM --------------------- //
  printf("Turning on the MCU\r\n");
  eeprom.read_state(&state);
  __delay_ms(200);

  // ----------------------- Feedback ------------------------ //
  feedback(state);

  while (1)
  {
    if (main_interrupt)
    {
      if (state != SLEEP_STATE && state_changed)
        eeprom.write_state(state);

      if (state_changed)
        feedback(state);

      switch (state)
      {
      case HIGH_LIGHT_STATE:
        led.set_red(255);
        break;
      case MUSIC_STATE:
        led.set_green(255);
        break;
      case DMX_STATE:
        led.set_blue(255);
        motor.step(true);
        break;
      case SLEEP_STATE:
        printf("SLEEP State \n\r");
        led.turn_off();
        // TMR0_InterruptDisable();
        // __delay_ms(500);
        // SLEEP();
        // eeprom.read_state(&state);
        // TMR0_InterruptEnable();
        break;
      default:
        break;
      }

      main_interrupt = false;
    }
    else
    {
    }
  }
}
/**
 End of File
*/