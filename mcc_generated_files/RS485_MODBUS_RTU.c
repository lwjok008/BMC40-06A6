#include"mcc.h"
#include "head.h"
bit flag_ook1=0,flag_ok1=0;
uint8_t TX_LEN1=8,RX_LEN1=8;
uint8_t TX_BUFF[30];
void RS485_Transmit1(void)  
{    
        static uint8_t i,z;
        if(flag_ok1)
        {
            data_485_analyse();
            flag_ok1=0;
        }
        else
        {
            nop;
        }
        if(flag_ook1)
        {
                 for(i=0;i<TX_LEN1;i++)
                {                       
                     EUSART2_Write(TX_BUFF[i]);
                        while(!TXSTA2bits.TRMT);		//TRMT=1´ú±í¼Ä´æÆ÷Îª¿Õ                    
                }
                flag_ook1=0;
                for(z=0;z<TX_LEN1;z++)       //Çå¿Õ·¢ËÍ»º´æ
                {
                    TX_BUFF[z]=0;
                }
        }
        else
        {
            nop;
        }
}

void data_485_analyse(void)
{
}
/********************************************************************/   
