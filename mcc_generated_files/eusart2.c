/**
  EUSART2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart2.c

  @Summary
    This is the generated driver implementation file for the EUSART2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for EUSART2.
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

/**
  Section: Included Files
*/
#include "mcc.h"
#include "head.h"

/**
  Section: Macro Declarations
*/

#define EUSART2_TX_BUFFER_SIZE 32
#define EUSART2_RX_BUFFER_SIZE 8
#define	nop		asm("nop")
/**
  Section: Global Variables
*/
volatile uint8_t eusart2TxHead = 0;
volatile uint8_t eusart2TxTail = 0;
volatile uint8_t eusart2TxBuffer[EUSART2_TX_BUFFER_SIZE];
volatile uint8_t eusart2TxBufferRemaining;

volatile uint8_t eusart2RxHead = 0;
volatile uint8_t eusart2RxTail = 0;
volatile uint8_t eusart2RxBuffer[EUSART2_RX_BUFFER_SIZE];
volatile uint8_t eusart2RxCount;

/**
  Section: EUSART2 APIs
*/
void EUSART2_Initialize(void)
{
    // disable interrupts before changing states
    PIE3bits.RC2IE = 0;
    EUSART2_SetRxInterruptHandler(EUSART2_Receive_ISR);
    PIE3bits.TX2IE = 0;
    EUSART2_SetTxInterruptHandler(EUSART2_Transmit_ISR);
    // Set the EUSART2 module to the options selected in the user interface.

    // ABDOVF no_overflow; TXCKP async_noninverted_sync_fallingedge; RCIDL idle; BRG16 16bit_generator; WUE disabled; ABDEN disabled; RXDTP not_inverted; 
    BAUDCON2 = 0x48;

    // SPEN enabled; OERR no_error; RX9 8-bit; RX9D 0; CREN enabled; ADDEN disabled; SREN disabled; FERR no_error; 
    RCSTA2 = 0x90;

    // TRMT TSR_empty; TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave_mode; 
    TXSTA2 = 0x26;

    // SPBRG2 160; 
    SPBRG2 = 0xA0;

    // SPBRGH2 1; 
    SPBRGH2 = 0x01;


    // initializing the driver state
    eusart2TxHead = 0;
    eusart2TxTail = 0;
    eusart2TxBufferRemaining = sizeof(eusart2TxBuffer);

    eusart2RxHead = 0;
    eusart2RxTail = 0;
    eusart2RxCount = 0;

    // enable receive interrupt
    PIE3bits.RC2IE = 1;
}

uint8_t EUSART2_is_tx_ready(void)
{
    return eusart2TxBufferRemaining;
}

uint8_t EUSART2_is_rx_ready(void)
{
    return eusart2RxCount;
}

bool EUSART2_is_tx_done(void)
{
    return TXSTA2bits.TRMT;
}

uint8_t EUSART2_Read(void)
{
    uint8_t readValue  = 0;
    
    while(0 == eusart2RxCount)
    {
    }

    readValue = eusart2RxBuffer[eusart2RxTail++];
    if(sizeof(eusart2RxBuffer) <= eusart2RxTail)
    {
        eusart2RxTail = 0;
    }
    PIE3bits.RC2IE = 0;
    eusart2RxCount--;
    PIE3bits.RC2IE = 1;

    return readValue;
}

void EUSART2_Write(uint8_t txData)
{
    while(0 == eusart2TxBufferRemaining)
    {
    }

    if(0 == PIE3bits.TX2IE)
    {
        TXREG2 = txData;
    }
    else
    {
        PIE3bits.TX2IE = 0;
        eusart2TxBuffer[eusart2TxHead++] = txData;
        if(sizeof(eusart2TxBuffer) <= eusart2TxHead)
        {
            eusart2TxHead = 0;
        }
        eusart2TxBufferRemaining--;
    }
    PIE3bits.TX2IE = 1;
}


void EUSART2_Transmit_ISR(void)
{
    
    // add your EUSART2 interrupt custom code
    if(sizeof(eusart2TxBuffer) > eusart2TxBufferRemaining)
    {
        TXREG2 = eusart2TxBuffer[eusart2TxTail++];
        if(sizeof(eusart2TxBuffer) <= eusart2TxTail)
        {
            eusart2TxTail = 0;
        }
        eusart2TxBufferRemaining++;
    }
    else
    {
        PIE3bits.TX2IE = 0;
    }
}

void EUSART2_Receive_ISR(void)
{
    static uint16_t i1,j1,num;
    PIE3bits.RC2IE = 0;
    eusart2RxHead=0;	

//     buffer overruns are ignored
    eusart2RxBuffer[eusart2RxHead] = RCREG2;
    
    if((eusart2RxBuffer[0]==addr)||(eusart2RxBuffer[0]==0x00))          //?????
    {                    	
//        LED_CONN_LAT=~LED_CONN_LAT;
                    for(i1=0;i1<7;i1++)		//?????????
                    {
                        num=0;
                        eusart2RxHead++;	
                        for(j1=25000;j1>0;j1--)
                        {
                            num++;
                            if(PIR3bits.RC2IF == 1)
                            {
                                eusart2RxBuffer[eusart2RxHead]=RCREG2;
                                num=0;
                                break;
                            }
                        }
                        if(num>20000)		//??????? 
                        {                         
                                RCSTA2bits.CREN = 0;
                                nop;
                                RCSTA2bits.CREN = 1;
                            eusart2RxHead=0;
                            eusart2RxCount=0;
                            break;
                        }
                        if (7 == eusart2RxHead)  //?????????????????
                        {
                            if((eusart2RxBuffer[1]==0x04)||(eusart2RxBuffer[1]==0x06))
                            {
                                flag_ok1=1;
                                RX_LEN1=8;
                                eusart2RxCount = 0;
                                eusart2RxHead = 0;
                                break;
                            }
                        }                             
                    }  
    }   
    else     //??????????
    {
            flag_ok1=0;
            flag_ook1=0;
            eusart2RxCount = 0;
            eusart2RxHead = 0;
    }
    PIE3bits.RC2IE = 1;        
}
void EUSART2_RxDataHandler(void){
    

    /**************************MODBUS_VERY_GOOD********************/
   
}
//void EUSART2_Receive_ISR(void)
//{
//    uint16_t i1,j1,num;
//
//    /**************************MODBUS_VERY_GOOD********************/
//    PIE3bits.RC2IE = 0;
//    eusart2RxHead=0;	
//
////     buffer overruns are ignored
//    eusart2RxBuffer[eusart2RxHead] = RCREG2;
//    F6_LED_LAT = ~F6_LED_LAT;
//    if((eusart2RxBuffer[0]==addr)||(eusart2RxBuffer[0]==0x00))          //?????
//    {                    	
////        LED_CONN_LAT=~LED_CONN_LAT;
//                    for(i1=0;i1<40;i1++)		//?????????
//                    {
//                        num=0;
//                        eusart2RxHead++;	
//                        for(j1=25000;j1>0;j1--)
//                        {
//                            num++;
//                            if(PIR3bits.RC2IF == 1)
//                            {
//                                eusart2RxBuffer[eusart2RxHead]=RCREG2;
//                                num=0;
//                                break;
//                            }
//                        }
//                        if(num>20000)		//??????? 
//                        {
//                            if((eusart2RxHead >7)&&(eusart2RxBuffer[1]==0x10))
//                            {
//                                flag_ok1=1;
//                                RX_LEN1=eusart2RxHead;
//                            }
//                            else
//                            {                            
//                                RCSTA2bits.CREN = 0;
//                                nop;
//                                RCSTA2bits.CREN = 1;
//                            }
//                            eusart2RxHead=0;
//                            eusart2RxCount=0;
//                            break;
//                        }
//                        if (7 == eusart2RxHead)  //?????????????????
//                        {
//                            if((eusart2RxBuffer[1]==0x04)||(eusart2RxBuffer[1]==0x06))
//                            {
//                                flag_ok1=1;
//                                RX_LEN1=8;
//                                eusart2RxCount = 0;
//                                eusart2RxHead = 0;
//                                break;
//                            }
//                        }                             
//                    }  
//    }   
//    else     //??????????
//    {
//            flag_ok1=0;
//            flag_ook1=0;
//            eusart2RxCount = 0;
//            eusart2RxHead = 0;
//    }
//    PIE3bits.RC2IE = 1;        
//}

void EUSART2_SetTxInterruptHandler(void (* interruptHandler)(void)){
    EUSART2_TxDefaultInterruptHandler = interruptHandler;
}

void EUSART2_SetRxInterruptHandler(void (* interruptHandler)(void)){
    EUSART2_RxDefaultInterruptHandler = interruptHandler;
}
/**
  End of File
*/
