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

#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "led.h"
#include "eeprom.h"
#include "feedback.h"
#include "temp_sensor.h"
#include "motor.h"
#include "cmd_interpreter.h"
#include "audio.h"

#define HIGH_LIGHT_STATE 0
#define MUSIC_STATE 1
#define DMX_STATE 2
#define SLEEP_STATE 3

led_adapter led;
eeprom_adapter eeprom;
motor_adapter motor;
audio_adapter audio;

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
  AUDIO_Initialize(&audio);

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

  // ----------------------- Feedback ------------------------- //
  feedback(state);

  // ----------------------- LEDs on ------------------------- //
  led.set_brightness(255);
  led.turn_on();

  while (1)
  {
    // This variable will change to true at 3 Hz
    if (main_interrupt)
    {

      // This will change by pressing the mode button
      if (state_changed)
      {
        // Feedback the new state
        feedback(state);

        // Save to EEPROM except for SLEEP STATE
        if (state != SLEEP_STATE)
          eeprom.write_state(state);
      }

      switch (state)
      {
      // This mode turns the LEDs to Red and maximum brightness
      case HIGH_LIGHT_STATE:
        led.set_brightness(255);
        led.turn_red();
        led.turn_on();
        break;

      /* This mode samples the .wav audio signal after an analog filter.
        If the average of a sliding window is greater than a threshold
        it changes the light of the LEDs
      */
      case MUSIC_STATE:
        led.turn_on();
        audio.measure();
        audio.act();
        motor.step();
        break;

      /* This mode will listen to the UART to get commands using DMX.
        We couldn't read the DMX protocol, so we made this command() mock function
        in order to test it.
      */
      case DMX_STATE:
        command();
        motor.step();
        break;

      /* This mode will put the MCU to Sleep to save energy
        Also, this is the default state when the temperature is too high
      */
      case SLEEP_STATE:
        printf("SLEEP STATE \n\r");
        led.turn_off();
        TMR0_InterruptDisable();
        SLEEP();
        state = HIGH_LIGHT_STATE;
        TMR0_InterruptEnable();
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