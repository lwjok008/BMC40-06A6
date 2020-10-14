#include"mcc.h"
#include "head.h"

bit FLAG_F1_ON,FLAG_F2_ON,FLAG_F3_ON,FLAG_F4_ON,FLAG_F5_ON,FLAG_F6_ON;

void page4_set1()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,white);	    
/////////////////////////////////////////////////////////////////

    disp_ASCII_8x16(0,2,4,red,black);	
    disp_ASCII_8x16(8,2,52,red,black);	
    disp_ASCII_8x16(16,2,1,red,black);	    
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,qi3,white,black);  //  
    disp_16x16(16*3,2,dong,white,black);  //    
    disp_16x16(16*4,2,wen,white,black);  //  
    disp_16x16(16*5,2,du,white,black);  //   
    disp_16x16(16*6,2,she,white,black);  //  
    disp_16x16(16*7,2,zhi4,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////  
    disp_16x16(16*1,32,di,white,black);  //    
    disp_ASCII_8x16(16*2,32,1,white,black);	
    disp_16x16(16*3,32,zu3,white,black);  //         
    disp_ASCII_8x16(16*5,32,36,white,black);	
  
    h_bcd(TEMP_SET1);	
    disp_ASCII_8x16(16*5+8+8,32,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,32,ge,white,black);        
    
    disp_16x16(16*1,68,di,white,black);  //    
    disp_ASCII_8x16(16*2,68,2,white,black);	
    disp_16x16(16*3,68,zu3,white,black);  //         
    disp_ASCII_8x16(16*5,68,36,white,black);	
   
    h_bcd(TEMP_SET2);	
    disp_ASCII_8x16(16*5+8+8,68,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,68,ge,white,black);   

    disp_16x16(16*1,104,di,white,black);  //    
    disp_ASCII_8x16(16*2,104,3,white,black);	
    disp_16x16(16*3,104,zu3,white,black);  //         
    disp_ASCII_8x16(16*5,104,36,white,black);	
  
    h_bcd(TEMP_SET3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,white,black);   
    
    disp_16x16(16*5+8+8+8+8,32,sheshidu,white,black);  
    disp_16x16(16*5+8+8+8+8,68,sheshidu,white,black);  
    disp_16x16(16*5+8+8+8+8,104,sheshidu,white,black);  
}
//////////////////////////////////////////////////////////////////////////////
void parameter_set1_set1(void)
{
///////////////////////////////////////////////////////////////////////////////////////////      
    h_bcd(TEMP_SET1);	
    disp_ASCII_8x16(16*5+8+8,32,shi,red,white);    
    disp_ASCII_8x16(16*5+8+8+8,32,ge,red,white);        
   
    h_bcd(TEMP_SET2);	
    disp_ASCII_8x16(16*5+8+8,68,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,68,ge,white,black);   
  
    h_bcd(TEMP_SET3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,white,black);   
}
void parameter_set1_set2(void)
{
///////////////////////////////////////////////////////////////////////////////////////////      
    h_bcd(TEMP_SET1);	
    disp_ASCII_8x16(16*5+8+8,32,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,32,ge,white,black);        
   
    h_bcd(TEMP_SET2);	
    disp_ASCII_8x16(16*5+8+8,68,shi,red,white);    
    disp_ASCII_8x16(16*5+8+8+8,68,ge,red,white);   
  
    h_bcd(TEMP_SET3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,white,black);   
}
void parameter_set1_set3(void)
{
///////////////////////////////////////////////////////////////////////////////////////////      
    h_bcd(TEMP_SET1);	
    disp_ASCII_8x16(16*5+8+8,32,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,32,ge,white,black);        
   
    h_bcd(TEMP_SET2);	
    disp_ASCII_8x16(16*5+8+8,68,shi,white,black);    
    disp_ASCII_8x16(16*5+8+8+8,68,ge,white,black);   
  
    h_bcd(TEMP_SET3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,red,white);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,red,white);    
}
void parameter_set1_set4(void)
{
///////////////////////////////////////////////////////////////////////////////////////////      
  
}
void parameter_set1_set5(void)
{

}
void parameter_set1_set6(void)
{

}