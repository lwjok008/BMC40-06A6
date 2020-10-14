#include"mcc.h"
#include "head.h"

void crc_check(uint8_t *ptr,uint8_t len)	//	CRC16  ?????? X^16+X^15+X^2+1
{
	clrwdt;
	volatile uint16_t crc=0xffff;
	volatile uint8_t i_crc,j_crc;
	for(i_crc=0;i_crc<len;i_crc++)
	{
		crc^=ptr[i_crc];
		for(j_crc=0;j_crc<8;j_crc++)
		{
			if(crc&0x0001)
				crc=(crc>>1)^0xA001;	//0xA001
			else
				crc=crc>>1;
		}
	}
	CRC_LOW=crc&0x00ff;
	CRC_HIG=crc>>8;
}

/*
void crc_check(uint8_t *ptr,uint8_t len)
{  
  uint16_t Reg_CRC=0xffff;  
  uint8_t Temp_reg=0x00;  
  uint8_t i,j;   
 for( i = 0; i<len; i ++)  
   {  
   Reg_CRC^= *ptr++;  
   for (j = 0; j<8; j++)  
   {       
   if (Reg_CRC & 0x0001)  
  
   Reg_CRC=Reg_CRC>>1^0xA001;  
else  
Reg_CRC >>=1;  
   }    
   }  
Temp_reg=Reg_CRC>>8;  
	CRC_LOW=Reg_CRC<<8;
	CRC_HIG=Temp_reg;
    //return (Reg_CRC<<8|Temp_reg);  
}  
*/
