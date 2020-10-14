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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18877
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
#include "mcc_generated_files/head.h"

extern bit FLAG_CT_RUN,FLAG_CT_STOP,FLAG_RUN,FLAG_STOP_RUN;

unsigned char lcd_page=1,set=10, CRC_LOW, CRC_HIG; 
uchar dht11_order;
unsigned int  i,j,num,refresh_time,refresh_LED_time=0;

uchar *ptr;
uchar DATA_RX[5];
unsigned char qian, bai, shi, ge;
uchar temp1,RH1,counter1;
uchar DATA_RECEIVE_ERR=0;
//STATE_FLAG flag1;
bit flag_minus,flag_minus_t1,flag_t1_err;
uint MOTORA_run_time,MOTORB_run_time,MOTORC_run_time;
uint counter_timerA,counter_timerB,counter_timerC;
uint counter_timerAA[20]={0};
uint counter_timerBB[20]={0};
uint counter_timerCC[20]={0};
uchar flag_24H;
uint run_6s,run_6s1,run_6s2,run_6s3;

uint RUN_CT_time,STOP_CT_time;

uint test_time,refresh_time_temp;
uchar DHT11_ReadChar1(void);
void DHT11_GetRH1(void);  
void Eusart_Err_Restart(void);
//unsigned int refresh_time=0,refresh_LED_time=0;
__EEPROM_DATA(0x3F,0x3F,10,1,1,40,45,50);
//__EEPROM_DATA(0,0,0,0,0,0,0,0);
void main(void)
{
    dht11_order=0;
    // initialize the device
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();    
    data_init(); 
    T1_HIGH();
    SELF_ALARM_LAT = 1;             //自身故障上电断开
    TFT_Disp128160(gImage_Peaks_logo);     
    delay(10);
    TEMP_SET1 = DATAEE_ReadByte(0X05);
    delay(10);
    TEMP_SET2 = DATAEE_ReadByte(0X06);
    delay(10);
    TEMP_SET3 = DATAEE_ReadByte(0X07);
    delay(10);    
    FAN_ONOFF_BYTE = 0x3F;
    delay(10);
    if((FAN_ONOFF_BYTE&0x01)==0x01)
    {
        FLAG_F1_ON=1;
    }
    else
    {
        FLAG_F1_ON=0;
    }
    if((FAN_ONOFF_BYTE&0x02)==0x02)
    {
        FLAG_F2_ON=1;
    }
    else
    {
        FLAG_F2_ON=0;
    }
        if((FAN_ONOFF_BYTE&0x04)==0x04)
    {
        FLAG_F3_ON=1;
    }
    else
    {
        FLAG_F3_ON=0;
    }
    if((FAN_ONOFF_BYTE&0x08)==0x08)
    {
        FLAG_F4_ON=1;
    }
    else
    {
        FLAG_F4_ON=0;
    }
    if((FAN_ONOFF_BYTE&0x10)==0x10)
    {
        FLAG_F5_ON=1;
    }
    else
    {
        FLAG_F5_ON=0;
    }
    if((FAN_ONOFF_BYTE&0x20)==0x20)
    {
        FLAG_F6_ON=1;
    }
    else
    {
        FLAG_F6_ON=0;
    }    

    start_current = DATAEE_ReadByte(0X01); 
    delay(10);
    keep_time = DATAEE_ReadByte(0X02); 
    delay(10);
    CT_CURRENT = DATAEE_ReadByte(0X03); 
    delay(10);
    addr = DATAEE_ReadByte(0X04);  

    while(1)
    {
        clrwdt;
        if(INTCONbits.TMR0IF) //10ms心跳基准
        {
            INTCONbits.TMR0IF=0;
            TMR0_Reload();
            refresh_time++;
            /**********************1秒刷新一次TFT屏和采集电机运行电流*********************************/ 
            if(refresh_time>20)		//1S刷新一次LCD
            {
                refresh_time=0;   
                DHT11_GetRH1(); 
                page0_fixed();      //默认页面1
                break;
            }                              
        }    
    }
    while (1)
    {
        clrwdt;
        //Eusart_Err_Restart();
      //  RS485_Transmit1();
///////////////////////////////////////////////////////////////////////////////////////////////////        
        if(INTCONbits.TMR0IF) //10ms心跳基准
        {
            INTCONbits.TMR0IF=0;
            TMR0_Reload();
//            TMR0_Initialize();
            refresh_time++;
            refresh_LED_time++;
            refresh_time_temp++;
            test_time++;

            if(FLAG_RUN1)
            {
                run_6s1++;
                if(run_6s1>=600)
                {
                    run_6s1=666;
                    FLAG_TEST_YES1=1;
                }
                else
                {
                    FLAG_TEST_YES1=0;
                }
            }
            else
            {
                run_6s1=0;
                FLAG_TEST_YES1=0;            
            }
            if(FLAG_RUN2||FLAG_RUN2_1)
            {
                run_6s2++;
                if(run_6s2>=600)
                {
                    run_6s2=666;
                    FLAG_TEST_YES2=1;
                }
                else
                {
                    FLAG_TEST_YES2=0;
                }
            }
            else
            {
                run_6s2=0;
                FLAG_TEST_YES2=0;            
            }
            if(FLAG_RUN3||FLAG_RUN3_1)
            {
                run_6s3++;
                if(run_6s3>=600)
                {
                    run_6s3=666;
                    FLAG_TEST_YES3=1;
                }
                else
                {
                    FLAG_TEST_YES3=0;
                }
            }
            else
            {
                run_6s3=0;
                FLAG_TEST_YES3=0;            
            }            
            /**********************200mS刷新一次TFT屏和采集电机运行电流*********************************/
            if(refresh_time_temp>=2)
            {
                refresh_time_temp=0;
                
            }
            if(refresh_time>=20)		//200mS刷新一次LCD
            {
                refresh_time=0;    
                DHT11_GetRH1(); 
                lcd_page_display();  
//                F1_LED_LAT = ~F1_LED_LAT;
            }            
            if(refresh_LED_time>=1)      //10ms采集一次按键
            {
               refresh_LED_time=0; 
               key_test_AD();    
               INPUT_COLLECT();
            }          
            if(test_time>=10)   //100ms
            {
                test_time=0;   
                ALARM_OUT();      
                FAN_CTRL();                
                FAN_CURRENT_COLLECT();               
                LED_CTRL();
            }
        }
    }
}
/******************************************************************************************/
void Eusart_Err_Restart(void)
{
    if (1 == RCSTA2bits.OERR) 
    {
        // EUSART1 error - restart
        RCSTA2bits.CREN = 0;
        nop;
        RCSTA2bits.CREN = 1;
        eusart2RxHead=0;	
    }
    if (1 == RCSTA2bits.FERR) 
    {
        // EUSART1 error - restart
        RCSTA2bits.SPEN = 0;
        nop;
        RCSTA2bits.SPEN = 1;
        eusart2RxHead=0;	
    }  
}
/******************************************************************************************/
uchar DHT11_ReadChar1(void)
{
   uchar dat=0;
   uchar count1=2;
   uchar count2=2;    
   static uchar i;
	T1_HIGH();
   for(i=0;i<8;i++)	
   {
      count1=2;
      while((!T1)&&count1++);    //50us 
      count1=2;
      while((!T1)&&count1++);    //50us 
      delayus(47); 
      dat<<=1;        //50us+28us
      if(T1)    //50us+70us
      {
            if(T1)    //50us+70us
            {
                dat|=1;
            }
      }
      else
      {
         //delayus(20);          
      }
      
      count2=2;
      while((T1)&&count2++);		         
   }
    count2=100;
    while((T1)&&count2++);
   return dat;
}
// void DHT11_GetRH1(void)     //????????
//{
//   uchar i;           
//   uchar checktemp=0;
//   uint count;
//  
//   T1_LOW(); 			
//    delay(250);     //>18ms
//   T1_HIGH();
//   delayus(65);    //47---ok,65---ok,
//   if(!T1)
//   {
//      	count=2;
//      //?? 80us 
//      	while((!T1)&&count++);
//      	count=2;
//      	while((!T1)&&count++);        
//      	count=2;
//      	while((T1)&&count++);
//      	count=2;
//      	while((T1)&&count++);        
////		T1_HIGH();
//		for(i=0;i<5;i++)
//	 	{
//			DATA_RX[i]=DHT11_ReadChar1();
////			if(i!=4)
////			{
////				checktemp+=DATA_RX[i];
////			}            
//		}
//		checktemp=(DATA_RX[0]+DATA_RX[1]+DATA_RX[2]+DATA_RX[3]);			
//	     if (checktemp==DATA_RX[4]) //??
//	     {
//			RH1=DATA_RX[0];	
//            temp1=DATA_RX[2];
//            if(temp1>99)
//            {
//                temp1=99;
//            }
////                LED_ALM1_Toggle();
//                //RH=DATA_RX[0];
////            DATA_RX[3]=0x80;
//                if(((DATA_RX[3]&0X80)==0X80))
//                {
//                    flag_minus_t1=1;
//                }
//                else
//                {
//                    flag_minus_t1=0;
//                }
//                T1_HIGH();
//                flag_t1_err=0;
//                counter1=0;
//         }
//	     else
//	 	{
//			RH1=DATA_RX[0];	
////            temp1=88; 
//		}
//
//   }
//	else
// 	{
//		counter1++;
//        if(counter1>5)
//        {
//           flag_t1_err=1; 
//        }
////        temp1=99; 
//	}
//
//}
void DHT11_GetRH1(void)     //????????
{
  static uchar i;           
   uchar checktemp=0;
   uint count;
    switch(dht11_order)
    {
        case 0:
        {
            T1_LOW(); 
            dht11_order=1;
        }break;
        case 1:
        {
            T1_HIGH();
            delayus(65);    //47---ok,65---ok,
            if(!T1)
            {
                 count=2;
               //?? 80us 
                 while((!T1)&&count++);
                 count=2;
                 while((!T1)&&count++);        
                 count=2;
                 while((T1)&&count++);
                 count=2;
                 while((T1)&&count++);        
         //		T1_HIGH();
                 for(i=0;i<5;i++)
                 {
                     DATA_RX[i]=DHT11_ReadChar1();
         //			if(i!=4)
         //			{
         //				checktemp+=DATA_RX[i];
         //			}            
                 }
                 checktemp=(DATA_RX[0]+DATA_RX[1]+DATA_RX[2]+DATA_RX[3]);			
                  if (checktemp==DATA_RX[4])  //??
                  {
                     RH1=DATA_RX[0];	
                     temp1=DATA_RX[2]; 
                     if(temp1>99)
                     {
                         temp1=99;
                     }
         //                LED_ALM1_Toggle();
                         //RH=DATA_RX[0];
         //            DATA_RX[3]=0x80;
                         if(((DATA_RX[3]&0X80)==0X80))
                         {
                             flag_minus_t1=1;
                         }
                         else
                         {
                             flag_minus_t1=0;
                         }
                         T1_HIGH();
                         flag_t1_err=0;
                         counter1=0;
                  }
                  else
                 {
         //			RH1=DATA_RX[0];	
         //            temp1=DATA_RX[2]; 
                 }

            }
             else
             {
                 counter1++;
                 if(counter1>5)
                 {
                    flag_t1_err=1; 
                 }
             }
            dht11_order=0;
        }break;
        default:
        {
           // dht11_order=0;
        }break;
    }
   			
    //delay(250);     //>18ms


}
/******************************************************************************************/

/**
 End of File
*/