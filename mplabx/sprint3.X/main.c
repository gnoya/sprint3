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
        Device            :  PIC16F1769
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
#include "feedback.h"

#define LOW_LIGHT_STATE 0
#define HIGH_LIGHT_STATE 1
#define MUSIC_STATE 2
#define DMX_STATE 3

int state = 0;
bool feedback = true;
led_adapter led;

/*
                         Main application
 */
void main(void)
{
  // initialize the device
  SYSTEM_Initialize();
  LED_Initialize(&led);

  // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
  // Use the following macros to:

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  // Disable the Global Interrupts
  //INTERRUPT_GlobalInterruptDisable();

  // Disable the Peripheral Interrupts
  //INTERRUPT_PeripheralInterruptDisable();

  //Set the ISR handlers
  IOCCF7_SetInterruptHandler(button_ISR);
  TMR5_SetInterruptHandler(debouncing_ISR);
  
  while (1)
  {
    __delay_ms(1000);
    switch (state)
    {
    case LOW_LIGHT_STATE:
      led.low();
      if(feedback)
        {
            IO_RC4_SetLow();
            IO_RC5_SetLow();
            IO_RC6_SetHigh();
            feedback = false;
        }
      break;
    case HIGH_LIGHT_STATE:
      led.high();
      if(feedback)
      {
          IO_RC4_SetLow();
          IO_RC5_SetHigh();
          IO_RC6_SetLow();
          feedback = false;
      }
      break;
    case MUSIC_STATE:
        printf("MUSIC State \n\r");
        if(feedback)
        {
            IO_RC4_SetHigh();
            IO_RC5_SetLow();
            IO_RC6_SetLow();
            feedback = false;
        }
      break;
    case DMX_STATE:
      printf("DMX State \n\r");
      if(feedback)
        {
            IO_RC4_SetHigh();
            IO_RC5_SetHigh();
            IO_RC6_SetHigh();
            feedback = false;
        }
      break;
    default:
      break;
    }
    // Add your application code
  }
}
/**
 End of File
*/