/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_WPU                  WPUAbits.WPUA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_AN0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set FB_SELECTOR_1 aliases
#define FB_SELECTOR_1_TRIS                 TRISAbits.TRISA4
#define FB_SELECTOR_1_LAT                  LATAbits.LATA4
#define FB_SELECTOR_1_PORT                 PORTAbits.RA4
#define FB_SELECTOR_1_WPU                  WPUAbits.WPUA4
#define FB_SELECTOR_1_ANS                  ANSELAbits.ANSA4
#define FB_SELECTOR_1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define FB_SELECTOR_1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define FB_SELECTOR_1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define FB_SELECTOR_1_GetValue()           PORTAbits.RA4
#define FB_SELECTOR_1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define FB_SELECTOR_1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define FB_SELECTOR_1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define FB_SELECTOR_1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define FB_SELECTOR_1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define FB_SELECTOR_1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS                 TRISAbits.TRISA5
#define IO_RA5_LAT                  LATAbits.LATA5
#define IO_RA5_PORT                 PORTAbits.RA5
#define IO_RA5_WPU                  WPUAbits.WPUA5
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)

// get/set LED_SELECTOR_1 aliases
#define LED_SELECTOR_1_TRIS                 TRISCbits.TRISC0
#define LED_SELECTOR_1_LAT                  LATCbits.LATC0
#define LED_SELECTOR_1_PORT                 PORTCbits.RC0
#define LED_SELECTOR_1_ANS                  ANSELCbits.ANSC0
#define LED_SELECTOR_1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_SELECTOR_1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_SELECTOR_1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED_SELECTOR_1_GetValue()           PORTCbits.RC0
#define LED_SELECTOR_1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_SELECTOR_1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED_SELECTOR_1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define LED_SELECTOR_1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LED_SELECTOR_2 aliases
#define LED_SELECTOR_2_TRIS                 TRISCbits.TRISC2
#define LED_SELECTOR_2_LAT                  LATCbits.LATC2
#define LED_SELECTOR_2_PORT                 PORTCbits.RC2
#define LED_SELECTOR_2_ANS                  ANSELCbits.ANSC2
#define LED_SELECTOR_2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_SELECTOR_2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_SELECTOR_2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_SELECTOR_2_GetValue()           PORTCbits.RC2
#define LED_SELECTOR_2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_SELECTOR_2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_SELECTOR_2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_SELECTOR_2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set MOTOR_A aliases
#define MOTOR_A_TRIS                 TRISCbits.TRISC3
#define MOTOR_A_LAT                  LATCbits.LATC3
#define MOTOR_A_PORT                 PORTCbits.RC3
#define MOTOR_A_ANS                  ANSELCbits.ANSC3
#define MOTOR_A_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define MOTOR_A_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define MOTOR_A_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define MOTOR_A_GetValue()           PORTCbits.RC3
#define MOTOR_A_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define MOTOR_A_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define MOTOR_A_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define MOTOR_A_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set MOTOR_B aliases
#define MOTOR_B_TRIS                 TRISCbits.TRISC4
#define MOTOR_B_LAT                  LATCbits.LATC4
#define MOTOR_B_PORT                 PORTCbits.RC4
#define MOTOR_B_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define MOTOR_B_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define MOTOR_B_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define MOTOR_B_GetValue()           PORTCbits.RC4
#define MOTOR_B_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define MOTOR_B_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set MOTOR_C aliases
#define MOTOR_C_TRIS                 TRISCbits.TRISC5
#define MOTOR_C_LAT                  LATCbits.LATC5
#define MOTOR_C_PORT                 PORTCbits.RC5
#define MOTOR_C_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define MOTOR_C_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define MOTOR_C_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define MOTOR_C_GetValue()           PORTCbits.RC5
#define MOTOR_C_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define MOTOR_C_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set MOTOR_D aliases
#define MOTOR_D_TRIS                 TRISCbits.TRISC6
#define MOTOR_D_LAT                  LATCbits.LATC6
#define MOTOR_D_PORT                 PORTCbits.RC6
#define MOTOR_D_ANS                  ANSELCbits.ANSC6
#define MOTOR_D_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define MOTOR_D_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define MOTOR_D_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define MOTOR_D_GetValue()           PORTCbits.RC6
#define MOTOR_D_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define MOTOR_D_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define MOTOR_D_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define MOTOR_D_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set FB_SELECTOR_2 aliases
#define FB_SELECTOR_2_TRIS                 TRISCbits.TRISC7
#define FB_SELECTOR_2_LAT                  LATCbits.LATC7
#define FB_SELECTOR_2_PORT                 PORTCbits.RC7
#define FB_SELECTOR_2_ANS                  ANSELCbits.ANSC7
#define FB_SELECTOR_2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define FB_SELECTOR_2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define FB_SELECTOR_2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define FB_SELECTOR_2_GetValue()           PORTCbits.RC7
#define FB_SELECTOR_2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define FB_SELECTOR_2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define FB_SELECTOR_2_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define FB_SELECTOR_2_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/