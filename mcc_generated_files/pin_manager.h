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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F67K22
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set FAN4 aliases
#define FAN4_TRIS                 TRISAbits.TRISA0
#define FAN4_LAT                  LATAbits.LATA0
#define FAN4_PORT                 PORTAbits.RA0
#define FAN4_ANS                  ANCON0bits.ANSEL0
#define FAN4_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define FAN4_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define FAN4_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define FAN4_GetValue()           PORTAbits.RA0
#define FAN4_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define FAN4_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define FAN4_SetAnalogMode()      do { ANCON0bits.ANSEL0 = 1; } while(0)
#define FAN4_SetDigitalMode()     do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set FAN3 aliases
#define FAN3_TRIS                 TRISAbits.TRISA1
#define FAN3_LAT                  LATAbits.LATA1
#define FAN3_PORT                 PORTAbits.RA1
#define FAN3_ANS                  ANCON0bits.ANSEL1
#define FAN3_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define FAN3_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define FAN3_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define FAN3_GetValue()           PORTAbits.RA1
#define FAN3_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define FAN3_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define FAN3_SetAnalogMode()      do { ANCON0bits.ANSEL1 = 1; } while(0)
#define FAN3_SetDigitalMode()     do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set FAN2 aliases
#define FAN2_TRIS                 TRISAbits.TRISA2
#define FAN2_LAT                  LATAbits.LATA2
#define FAN2_PORT                 PORTAbits.RA2
#define FAN2_ANS                  ANCON0bits.ANSEL2
#define FAN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define FAN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define FAN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define FAN2_GetValue()           PORTAbits.RA2
#define FAN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define FAN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define FAN2_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define FAN2_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set FAN1 aliases
#define FAN1_TRIS                 TRISAbits.TRISA3
#define FAN1_LAT                  LATAbits.LATA3
#define FAN1_PORT                 PORTAbits.RA3
#define FAN1_ANS                  ANCON0bits.ANSEL3
#define FAN1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define FAN1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define FAN1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define FAN1_GetValue()           PORTAbits.RA3
#define FAN1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define FAN1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define FAN1_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define FAN1_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set F5_LED aliases
#define F5_LED_TRIS                 TRISAbits.TRISA4
#define F5_LED_LAT                  LATAbits.LATA4
#define F5_LED_PORT                 PORTAbits.RA4
#define F5_LED_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define F5_LED_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define F5_LED_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define F5_LED_GetValue()           PORTAbits.RA4
#define F5_LED_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define F5_LED_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set F6_LED aliases
#define F6_LED_TRIS                 TRISAbits.TRISA5
#define F6_LED_LAT                  LATAbits.LATA5
#define F6_LED_PORT                 PORTAbits.RA5
#define F6_LED_ANS                  ANCON0bits.ANSEL4
#define F6_LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define F6_LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define F6_LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define F6_LED_GetValue()           PORTAbits.RA5
#define F6_LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define F6_LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define F6_LED_SetAnalogMode()      do { ANCON0bits.ANSEL4 = 1; } while(0)
#define F6_LED_SetDigitalMode()     do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISAbits.TRISA6
#define CS_LAT                  LATAbits.LATA6
#define CS_PORT                 PORTAbits.RA6
#define CS_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define CS_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define CS_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define CS_GetValue()           PORTAbits.RA6
#define CS_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set BLK aliases
#define BLK_TRIS                 TRISAbits.TRISA7
#define BLK_LAT                  LATAbits.LATA7
#define BLK_PORT                 PORTAbits.RA7
#define BLK_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BLK_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BLK_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BLK_GetValue()           PORTAbits.RA7
#define BLK_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BLK_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)

// get/set F3_LED aliases
#define F3_LED_TRIS                 TRISCbits.TRISC0
#define F3_LED_LAT                  LATCbits.LATC0
#define F3_LED_PORT                 PORTCbits.RC0
#define F3_LED_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define F3_LED_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define F3_LED_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define F3_LED_GetValue()           PORTCbits.RC0
#define F3_LED_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define F3_LED_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set F4_LED aliases
#define F4_LED_TRIS                 TRISCbits.TRISC1
#define F4_LED_LAT                  LATCbits.LATC1
#define F4_LED_PORT                 PORTCbits.RC1
#define F4_LED_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define F4_LED_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define F4_LED_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define F4_LED_GetValue()           PORTCbits.RC1
#define F4_LED_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define F4_LED_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RES aliases
#define RES_TRIS                 TRISCbits.TRISC2
#define RES_LAT                  LATCbits.LATC2
#define RES_PORT                 PORTCbits.RC2
#define RES_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RES_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RES_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RES_GetValue()           PORTCbits.RC2
#define RES_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RES_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set DC aliases
#define DC_TRIS                 TRISCbits.TRISC3
#define DC_LAT                  LATCbits.LATC3
#define DC_PORT                 PORTCbits.RC3
#define DC_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DC_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DC_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DC_GetValue()           PORTCbits.RC3
#define DC_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DC_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set WR aliases
#define WR_TRIS                 TRISCbits.TRISC4
#define WR_LAT                  LATCbits.LATC4
#define WR_PORT                 PORTCbits.RC4
#define WR_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define WR_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define WR_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define WR_GetValue()           PORTCbits.RC4
#define WR_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define WR_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RD aliases
#define RD_TRIS                 TRISCbits.TRISC5
#define RD_LAT                  LATCbits.LATC5
#define RD_PORT                 PORTCbits.RC5
#define RD_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RD_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RD_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RD_GetValue()           PORTCbits.RC5
#define RD_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RD_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set F2_LED aliases
#define F2_LED_TRIS                 TRISCbits.TRISC6
#define F2_LED_LAT                  LATCbits.LATC6
#define F2_LED_PORT                 PORTCbits.RC6
#define F2_LED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define F2_LED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define F2_LED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define F2_LED_GetValue()           PORTCbits.RC6
#define F2_LED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define F2_LED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set F1_LED aliases
#define F1_LED_TRIS                 TRISCbits.TRISC7
#define F1_LED_LAT                  LATCbits.LATC7
#define F1_LED_PORT                 PORTCbits.RC7
#define F1_LED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define F1_LED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define F1_LED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define F1_LED_GetValue()           PORTCbits.RC7
#define F1_LED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define F1_LED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

// get/set KEY_RESET aliases
#define KEY_RESET_TRIS                 TRISDbits.TRISD3
#define KEY_RESET_LAT                  LATDbits.LATD3
#define KEY_RESET_PORT                 PORTDbits.RD3
#define KEY_RESET_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define KEY_RESET_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define KEY_RESET_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define KEY_RESET_GetValue()           PORTDbits.RD3
#define KEY_RESET_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define KEY_RESET_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

// get/set KEY_DOWN aliases
#define KEY_DOWN_TRIS                 TRISDbits.TRISD4
#define KEY_DOWN_LAT                  LATDbits.LATD4
#define KEY_DOWN_PORT                 PORTDbits.RD4
#define KEY_DOWN_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define KEY_DOWN_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define KEY_DOWN_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define KEY_DOWN_GetValue()           PORTDbits.RD4
#define KEY_DOWN_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define KEY_DOWN_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set KEY_ENTER aliases
#define KEY_ENTER_TRIS                 TRISDbits.TRISD5
#define KEY_ENTER_LAT                  LATDbits.LATD5
#define KEY_ENTER_PORT                 PORTDbits.RD5
#define KEY_ENTER_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define KEY_ENTER_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define KEY_ENTER_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define KEY_ENTER_GetValue()           PORTDbits.RD5
#define KEY_ENTER_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define KEY_ENTER_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set KEY_UP aliases
#define KEY_UP_TRIS                 TRISDbits.TRISD6
#define KEY_UP_LAT                  LATDbits.LATD6
#define KEY_UP_PORT                 PORTDbits.RD6
#define KEY_UP_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define KEY_UP_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define KEY_UP_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define KEY_UP_GetValue()           PORTDbits.RD6
#define KEY_UP_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define KEY_UP_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set KEY_CANCEL aliases
#define KEY_CANCEL_TRIS                 TRISDbits.TRISD7
#define KEY_CANCEL_LAT                  LATDbits.LATD7
#define KEY_CANCEL_PORT                 PORTDbits.RD7
#define KEY_CANCEL_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define KEY_CANCEL_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define KEY_CANCEL_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define KEY_CANCEL_GetValue()           PORTDbits.RD7
#define KEY_CANCEL_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define KEY_CANCEL_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

// get/set AUTO_IN aliases
#define AUTO_IN_TRIS                 TRISEbits.TRISE0
#define AUTO_IN_LAT                  LATEbits.LATE0
#define AUTO_IN_PORT                 PORTEbits.RE0
#define AUTO_IN_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define AUTO_IN_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define AUTO_IN_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define AUTO_IN_GetValue()           PORTEbits.RE0
#define AUTO_IN_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define AUTO_IN_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)

// get/set SELF_ALARM aliases
#define SELF_ALARM_TRIS                 TRISEbits.TRISE1
#define SELF_ALARM_LAT                  LATEbits.LATE1
#define SELF_ALARM_PORT                 PORTEbits.RE1
#define SELF_ALARM_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define SELF_ALARM_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define SELF_ALARM_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define SELF_ALARM_GetValue()           PORTEbits.RE1
#define SELF_ALARM_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define SELF_ALARM_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)

// get/set RST_IN aliases
#define RST_IN_TRIS                 TRISEbits.TRISE2
#define RST_IN_LAT                  LATEbits.LATE2
#define RST_IN_PORT                 PORTEbits.RE2
#define RST_IN_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RST_IN_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RST_IN_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RST_IN_GetValue()           PORTEbits.RE2
#define RST_IN_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RST_IN_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)

// get/set FORCE_IN aliases
#define FORCE_IN_TRIS                 TRISEbits.TRISE3
#define FORCE_IN_LAT                  LATEbits.LATE3
#define FORCE_IN_PORT                 PORTEbits.RE3
#define FORCE_IN_SetHigh()            do { LATEbits.LATE3 = 1; } while(0)
#define FORCE_IN_SetLow()             do { LATEbits.LATE3 = 0; } while(0)
#define FORCE_IN_Toggle()             do { LATEbits.LATE3 = ~LATEbits.LATE3; } while(0)
#define FORCE_IN_GetValue()           PORTEbits.RE3
#define FORCE_IN_SetDigitalInput()    do { TRISEbits.TRISE3 = 1; } while(0)
#define FORCE_IN_SetDigitalOutput()   do { TRISEbits.TRISE3 = 0; } while(0)

// get/set RLY_ALARM aliases
#define RLY_ALARM_TRIS                 TRISEbits.TRISE4
#define RLY_ALARM_LAT                  LATEbits.LATE4
#define RLY_ALARM_PORT                 PORTEbits.RE4
#define RLY_ALARM_SetHigh()            do { LATEbits.LATE4 = 1; } while(0)
#define RLY_ALARM_SetLow()             do { LATEbits.LATE4 = 0; } while(0)
#define RLY_ALARM_Toggle()             do { LATEbits.LATE4 = ~LATEbits.LATE4; } while(0)
#define RLY_ALARM_GetValue()           PORTEbits.RE4
#define RLY_ALARM_SetDigitalInput()    do { TRISEbits.TRISE4 = 1; } while(0)
#define RLY_ALARM_SetDigitalOutput()   do { TRISEbits.TRISE4 = 0; } while(0)

// get/set FAN5 aliases
#define FAN5_TRIS                 TRISEbits.TRISE5
#define FAN5_LAT                  LATEbits.LATE5
#define FAN5_PORT                 PORTEbits.RE5
#define FAN5_SetHigh()            do { LATEbits.LATE5 = 1; } while(0)
#define FAN5_SetLow()             do { LATEbits.LATE5 = 0; } while(0)
#define FAN5_Toggle()             do { LATEbits.LATE5 = ~LATEbits.LATE5; } while(0)
#define FAN5_GetValue()           PORTEbits.RE5
#define FAN5_SetDigitalInput()    do { TRISEbits.TRISE5 = 1; } while(0)
#define FAN5_SetDigitalOutput()   do { TRISEbits.TRISE5 = 0; } while(0)

// get/set FAN6 aliases
#define FAN6_TRIS                 TRISEbits.TRISE6
#define FAN6_LAT                  LATEbits.LATE6
#define FAN6_PORT                 PORTEbits.RE6
#define FAN6_SetHigh()            do { LATEbits.LATE6 = 1; } while(0)
#define FAN6_SetLow()             do { LATEbits.LATE6 = 0; } while(0)
#define FAN6_Toggle()             do { LATEbits.LATE6 = ~LATEbits.LATE6; } while(0)
#define FAN6_GetValue()           PORTEbits.RE6
#define FAN6_SetDigitalInput()    do { TRISEbits.TRISE6 = 1; } while(0)
#define FAN6_SetDigitalOutput()   do { TRISEbits.TRISE6 = 0; } while(0)

// get/set IO_RE7 aliases
#define IO_RE7_TRIS                 TRISEbits.TRISE7
#define IO_RE7_LAT                  LATEbits.LATE7
#define IO_RE7_PORT                 PORTEbits.RE7
#define IO_RE7_SetHigh()            do { LATEbits.LATE7 = 1; } while(0)
#define IO_RE7_SetLow()             do { LATEbits.LATE7 = 0; } while(0)
#define IO_RE7_Toggle()             do { LATEbits.LATE7 = ~LATEbits.LATE7; } while(0)
#define IO_RE7_GetValue()           PORTEbits.RE7
#define IO_RE7_SetDigitalInput()    do { TRISEbits.TRISE7 = 1; } while(0)
#define IO_RE7_SetDigitalOutput()   do { TRISEbits.TRISE7 = 0; } while(0)

// get/set F6_AD aliases
#define F6_AD_TRIS                 TRISFbits.TRISF1
#define F6_AD_LAT                  LATFbits.LATF1
#define F6_AD_PORT                 PORTFbits.RF1
#define F6_AD_ANS                  ANCON0bits.ANSEL6
#define F6_AD_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define F6_AD_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define F6_AD_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define F6_AD_GetValue()           PORTFbits.RF1
#define F6_AD_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define F6_AD_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define F6_AD_SetAnalogMode()      do { ANCON0bits.ANSEL6 = 1; } while(0)
#define F6_AD_SetDigitalMode()     do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set F5_AD aliases
#define F5_AD_TRIS                 TRISFbits.TRISF2
#define F5_AD_LAT                  LATFbits.LATF2
#define F5_AD_PORT                 PORTFbits.RF2
#define F5_AD_ANS                  ANCON0bits.ANSEL7
#define F5_AD_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define F5_AD_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define F5_AD_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define F5_AD_GetValue()           PORTFbits.RF2
#define F5_AD_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define F5_AD_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define F5_AD_SetAnalogMode()      do { ANCON0bits.ANSEL7 = 1; } while(0)
#define F5_AD_SetDigitalMode()     do { ANCON0bits.ANSEL7 = 0; } while(0)

// get/set F4_AD aliases
#define F4_AD_TRIS                 TRISFbits.TRISF3
#define F4_AD_LAT                  LATFbits.LATF3
#define F4_AD_PORT                 PORTFbits.RF3
#define F4_AD_ANS                  ANCON1bits.ANSEL8
#define F4_AD_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define F4_AD_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define F4_AD_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define F4_AD_GetValue()           PORTFbits.RF3
#define F4_AD_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define F4_AD_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define F4_AD_SetAnalogMode()      do { ANCON1bits.ANSEL8 = 1; } while(0)
#define F4_AD_SetDigitalMode()     do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set F3_AD aliases
#define F3_AD_TRIS                 TRISFbits.TRISF4
#define F3_AD_LAT                  LATFbits.LATF4
#define F3_AD_PORT                 PORTFbits.RF4
#define F3_AD_ANS                  ANCON1bits.ANSEL9
#define F3_AD_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define F3_AD_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define F3_AD_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define F3_AD_GetValue()           PORTFbits.RF4
#define F3_AD_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define F3_AD_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define F3_AD_SetAnalogMode()      do { ANCON1bits.ANSEL9 = 1; } while(0)
#define F3_AD_SetDigitalMode()     do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set F2_AD aliases
#define F2_AD_TRIS                 TRISFbits.TRISF5
#define F2_AD_LAT                  LATFbits.LATF5
#define F2_AD_PORT                 PORTFbits.RF5
#define F2_AD_ANS                  ANCON1bits.ANSEL10
#define F2_AD_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define F2_AD_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define F2_AD_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define F2_AD_GetValue()           PORTFbits.RF5
#define F2_AD_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define F2_AD_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define F2_AD_SetAnalogMode()      do { ANCON1bits.ANSEL10 = 1; } while(0)
#define F2_AD_SetDigitalMode()     do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set F1_AD aliases
#define F1_AD_TRIS                 TRISFbits.TRISF6
#define F1_AD_LAT                  LATFbits.LATF6
#define F1_AD_PORT                 PORTFbits.RF6
#define F1_AD_ANS                  ANCON1bits.ANSEL11
#define F1_AD_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define F1_AD_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define F1_AD_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define F1_AD_GetValue()           PORTFbits.RF6
#define F1_AD_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define F1_AD_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define F1_AD_SetAnalogMode()      do { ANCON1bits.ANSEL11 = 1; } while(0)
#define F1_AD_SetDigitalMode()     do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set CT_AD aliases
#define CT_AD_TRIS                 TRISFbits.TRISF7
#define CT_AD_LAT                  LATFbits.LATF7
#define CT_AD_PORT                 PORTFbits.RF7
#define CT_AD_ANS                  ANCON0bits.ANSEL5
#define CT_AD_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define CT_AD_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define CT_AD_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define CT_AD_GetValue()           PORTFbits.RF7
#define CT_AD_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define CT_AD_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define CT_AD_SetAnalogMode()      do { ANCON0bits.ANSEL5 = 1; } while(0)
#define CT_AD_SetDigitalMode()     do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set STOP_IN aliases
#define STOP_IN_TRIS                 TRISGbits.TRISG0
#define STOP_IN_LAT                  LATGbits.LATG0
#define STOP_IN_PORT                 PORTGbits.RG0
#define STOP_IN_SetHigh()            do { LATGbits.LATG0 = 1; } while(0)
#define STOP_IN_SetLow()             do { LATGbits.LATG0 = 0; } while(0)
#define STOP_IN_Toggle()             do { LATGbits.LATG0 = ~LATGbits.LATG0; } while(0)
#define STOP_IN_GetValue()           PORTGbits.RG0
#define STOP_IN_SetDigitalInput()    do { TRISGbits.TRISG0 = 1; } while(0)
#define STOP_IN_SetDigitalOutput()   do { TRISGbits.TRISG0 = 0; } while(0)

// get/set RG1 procedures
#define RG1_SetHigh()               do { LATGbits.LATG1 = 1; } while(0)
#define RG1_SetLow()                do { LATGbits.LATG1 = 0; } while(0)
#define RG1_Toggle()                do { LATGbits.LATG1 = ~LATGbits.LATG1; } while(0)
#define RG1_GetValue()              PORTGbits.RG1
#define RG1_SetDigitalInput()       do { TRISGbits.TRISG1 = 1; } while(0)
#define RG1_SetDigitalOutput()      do { TRISGbits.TRISG1 = 0; } while(0)
#define RG1_SetAnalogMode()         do { ANCON2bits.ANSEL19 = 1; } while(0)
#define RG1_SetDigitalMode()        do { ANCON2bits.ANSEL19 = 0; } while(0)

// get/set RG2 procedures
#define RG2_SetHigh()               do { LATGbits.LATG2 = 1; } while(0)
#define RG2_SetLow()                do { LATGbits.LATG2 = 0; } while(0)
#define RG2_Toggle()                do { LATGbits.LATG2 = ~LATGbits.LATG2; } while(0)
#define RG2_GetValue()              PORTGbits.RG2
#define RG2_SetDigitalInput()       do { TRISGbits.TRISG2 = 1; } while(0)
#define RG2_SetDigitalOutput()      do { TRISGbits.TRISG2 = 0; } while(0)
#define RG2_SetAnalogMode()         do { ANCON2bits.ANSEL18 = 1; } while(0)
#define RG2_SetDigitalMode()        do { ANCON2bits.ANSEL18 = 0; } while(0)

// get/set TEMP_IN aliases
#define TEMP_IN_TRIS                 TRISGbits.TRISG3
#define TEMP_IN_LAT                  LATGbits.LATG3
#define TEMP_IN_PORT                 PORTGbits.RG3
#define TEMP_IN_ANS                  ANCON2bits.ANSEL17
#define TEMP_IN_SetHigh()            do { LATGbits.LATG3 = 1; } while(0)
#define TEMP_IN_SetLow()             do { LATGbits.LATG3 = 0; } while(0)
#define TEMP_IN_Toggle()             do { LATGbits.LATG3 = ~LATGbits.LATG3; } while(0)
#define TEMP_IN_GetValue()           PORTGbits.RG3
#define TEMP_IN_SetDigitalInput()    do { TRISGbits.TRISG3 = 1; } while(0)
#define TEMP_IN_SetDigitalOutput()   do { TRISGbits.TRISG3 = 0; } while(0)
#define TEMP_IN_SetAnalogMode()      do { ANCON2bits.ANSEL17 = 1; } while(0)
#define TEMP_IN_SetDigitalMode()     do { ANCON2bits.ANSEL17 = 0; } while(0)
#define	T1			PORTGbits.RG3			//T1温度传感器数据输入口
#define	T1_HIGH()	TRISGbits.TRISG3 = 1
#define	T1_LOW()	TRISGbits.TRISG3 = 0; LATGbits.LATG3 = 0
// get/set IO_RG4 aliases
#define IO_RG4_TRIS                 TRISGbits.TRISG4
#define IO_RG4_LAT                  LATGbits.LATG4
#define IO_RG4_PORT                 PORTGbits.RG4
#define IO_RG4_ANS                  ANCON2bits.ANSEL16
#define IO_RG4_SetHigh()            do { LATGbits.LATG4 = 1; } while(0)
#define IO_RG4_SetLow()             do { LATGbits.LATG4 = 0; } while(0)
#define IO_RG4_Toggle()             do { LATGbits.LATG4 = ~LATGbits.LATG4; } while(0)
#define IO_RG4_GetValue()           PORTGbits.RG4
#define IO_RG4_SetDigitalInput()    do { TRISGbits.TRISG4 = 1; } while(0)
#define IO_RG4_SetDigitalOutput()   do { TRISGbits.TRISG4 = 0; } while(0)
#define IO_RG4_SetAnalogMode()      do { ANCON2bits.ANSEL16 = 1; } while(0)
#define IO_RG4_SetDigitalMode()     do { ANCON2bits.ANSEL16 = 0; } while(0)


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



#endif // PIN_MANAGER_H
/**
 End of File
*/