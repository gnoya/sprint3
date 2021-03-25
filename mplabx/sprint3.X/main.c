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
        Device            :  PIC16F1508
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

#define LOW_LIGHT_STATE 0
#define HIGH_LIGHT_STATE 1
#define MUSIC_STATE 2
#define DMX_STATE 3

led_adapter led;
eeprom_adapter eeprom;
int state = LOW_LIGHT_STATE;
extern bool state_changed;

void main(void)
{
  // ---------------- Initializing led and menu ---------------- //
  SYSTEM_Initialize();
  LED_Initialize(&led);
  EEPROM_Initialize(&eeprom);
  FEEDBACK_Initialize();

  // ------------------ Enabling Interrupts --------------------- //
  INTERRUPT_GlobalInterruptEnable();
  INTERRUPT_PeripheralInterruptEnable();

  // ------------ Setting button's Interrupt Handler ------------ //
  IOCAF5_SetInterruptHandler(button_ISR);

  //------------- Setting Timer Interrupt Handlers --------------//
  TMR1_SetInterruptHandler(debouncing_ISR);

  // --------------------- Opening sensors -------------------- //

  // --------------------- Reading EEPROM --------------------- //
  // printf("state %d \r\n", state);
  // eeprom.write_state(1);
  __delay_ms(200);
  eeprom.read_state(&state);

  __delay_ms(200);
  printf("state 2 %d\r\n", state);

  // ----------------------- Feedback ------------------------ //
  feedback(state);

  while (1)
  {
    __delay_ms(100);  // TODO: This is only NOPs! this still consumes current.
                      // Optimize later, but don't forget to try to make as SLEEP
    if (state_changed)
    {
      feedback(state);
      eeprom.write_state(state);
    }

    switch (state)
    {
    case LOW_LIGHT_STATE:
      led.low();
      break;
    case HIGH_LIGHT_STATE:
      led.high();
      break;
    case MUSIC_STATE:
      printf("MUSIC State \n\r");
      break;
    case DMX_STATE:
      printf("DMX State \n\r");
      break;
    default:
      break;
    }
  }
}
/**
 End of File
*/