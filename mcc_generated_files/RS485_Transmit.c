#include"mcc.h"
#include "head.h"
void RS485_Transmit(void)  
{    
    uint16_t a,z;
        if(flag_ok1)
        {
            //data_485_analyse();
            flag_ok1=0;
        }
        else
        {
            nop;
        }
        if(flag_ook1)
        {
//                CON_485II_TX();
                 for(a=0;a<TX_LEN1;a++)
                {                       
                     EUSART2_Write(TX_BUFF[a]);
//                    for(z=0;z<1000;z++)
//                    {
                        while(!EUSART2_is_tx_done);		//TRMT=1´ú±í¼Ä´æÆ÷Îª¿Õ
//                        {break;}	//	asm("nop");
//                    }
                }
                //delay(10);
//                CON_485II_RX();
                flag_ook1=0;
                for(z=0;z<8;z++)       //Çå¿Õ·¢ËÍ»º´æ
                {
                    TX_BUFF[z]=0;
                }
        }
        else
        {
            nop;
        }
}