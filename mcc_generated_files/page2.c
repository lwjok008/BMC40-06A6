
#include"mcc.h"
#include "head.h"
uint A_CLOSE_counter,B_CLOSE_counter,C_CLOSE_counter;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page2_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
    vDraw_Line(12,76,164,76,green);    
    vDraw_Line(12,124,164,124,green);  
    
    vDraw_Line(12,0,12,124,green);    
    vDraw_Line(52,28,52,124,green);	
    vDraw_Line(92,28,92,124,green);       
    vDraw_Line(132,28,132,124,green);          
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(0,2,2,red,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,feng,white,black);  //  
    disp_16x16(16*3,2,ji,white,black);  //    
    disp_16x16(16*4,2,yun,white,black);  //  
    disp_16x16(16*5,2,xing,white,black);  //   

    disp_16x16(16*6,2,dian4,white,black);  //  
    disp_16x16(16*7,2,liu,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////      
    disp_ASCII_8x16(16*5+8+8+8+16+16,56,50,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+16+16,56,10,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8+16+16,56,51,white,black);     
 
    disp_ASCII_8x16(16*5+8+8+8+16+16,104,50,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+16+16,104,10,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8+16+16,104,51,white,black);     

/////////////////////////////////////////////////////////////////
    if(FLAG_F1_ON)
    {
        disp_ASCII_8x16(8*3,32,15,red,black);	
        disp_ASCII_8x16(8*4,32,1,red,black);
        h_bcd(FAN1_current);
        disp_ASCII_8x16(16,56,bai,white,black);
        disp_ASCII_8x16(16+8,56,38,white,black);
        disp_ASCII_8x16(16+8+8,56,shi,white,black);
        disp_ASCII_8x16(16+8+8+8,56,ge,white,black);           
    } 
    else
    {
        disp_ASCII_8x16(8*3,32,15,black,black);	
        disp_ASCII_8x16(8*4,32,1,black,black);      
        h_bcd(FAN1_current);
        disp_ASCII_8x16(16,56,bai,black,black);
        disp_ASCII_8x16(16+8,56,38,black,black);
        disp_ASCII_8x16(16+8+8,56,shi,black,black);
        disp_ASCII_8x16(16+8+8+8,56,ge,black,black);           
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F2_ON)
    {
        disp_ASCII_8x16(8*8,32,15,orange,black);	
        disp_ASCII_8x16(8*9,32,2,orange,black);
        h_bcd(FAN2_current);
    disp_ASCII_8x16(16*3+8,56,bai,white,black);
    disp_ASCII_8x16(16*3+8+8,56,38,white,black);
    disp_ASCII_8x16(16*3+8+8+8,56,shi,white,black);
    disp_ASCII_8x16(16*3+8+8+8+8,56,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*8,32,15,black,black);	
        disp_ASCII_8x16(8*9,32,2,black,black);   
        h_bcd(FAN2_current);
    disp_ASCII_8x16(16*3+8,56,bai,black,black);
    disp_ASCII_8x16(16*3+8+8,56,38,black,black);
    disp_ASCII_8x16(16*3+8+8+8,56,shi,black,black);
    disp_ASCII_8x16(16*3+8+8+8+8,56,ge,black,black);  
    }    
/////////////////////////////////////////////////////////////////
    if(FLAG_F3_ON)
    {
        disp_ASCII_8x16(8*13,32,15,yellow,black);	
        disp_ASCII_8x16(8*14,32,3,yellow,black);   
        h_bcd(FAN3_current);
    disp_ASCII_8x16(16*5+8+8,56,bai,white,black);
    disp_ASCII_8x16(16*5+8+8+8,56,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,shi,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*13,32,15,black,black);	
        disp_ASCII_8x16(8*14,32,3,black,black);     
        h_bcd(FAN3_current);
    disp_ASCII_8x16(16*5+8+8,56,bai,black,black);
    disp_ASCII_8x16(16*5+8+8+8,56,38,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,shi,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,ge,black,black);  
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F4_ON)
    {
        disp_ASCII_8x16(8*3,56+24,15,green,black);	
        disp_ASCII_8x16(8*4,56+24,4,green,black);
        h_bcd(FAN4_current);
    disp_ASCII_8x16(16,104,bai,white,black);
    disp_ASCII_8x16(16+8,104,38,white,black);
    disp_ASCII_8x16(16+8+8,104,shi,white,black);
    disp_ASCII_8x16(16+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*3,56+24,15,black,black);	
        disp_ASCII_8x16(8*4,56+24,4,black,black);    
        h_bcd(FAN4_current);
    disp_ASCII_8x16(16,104,bai,black,black);
    disp_ASCII_8x16(16+8,104,38,black,black);
    disp_ASCII_8x16(16+8+8,104,shi,black,black);
    disp_ASCII_8x16(16+8+8+8,104,ge,black,black);  
    }   
/////////////////////////////////////////////////////////////////
    if(FLAG_F5_ON)
    {
        disp_ASCII_8x16(8*8,56+24,15,pink,black);	
        disp_ASCII_8x16(8*9,56+24,5,pink,black);
        h_bcd(FAN5_current);
    disp_ASCII_8x16(16*3+8,104,bai,white,black);
    disp_ASCII_8x16(16*3+8+8,104,38,white,black);
    disp_ASCII_8x16(16*3+8+8+8,104,shi,white,black);
    disp_ASCII_8x16(16*3+8+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*8,56+24,15,black,black);	
        disp_ASCII_8x16(8*9,56+24,5,black,black);       
        h_bcd(FAN5_current);
    disp_ASCII_8x16(16*3+8,104,bai,black,black);
    disp_ASCII_8x16(16*3+8+8,104,38,black,black);
    disp_ASCII_8x16(16*3+8+8+8,104,shi,black,black);
    disp_ASCII_8x16(16*3+8+8+8+8,104,ge,black,black);  
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F6_ON)
    {
        disp_ASCII_8x16(8*13,56+24,15,blue,black);	
        disp_ASCII_8x16(8*14,56+24,6,blue,black); 
        h_bcd(FAN6_current);
    disp_ASCII_8x16(16*5+8+8,104,bai,white,black);
    disp_ASCII_8x16(16*5+8+8+8,104,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,104,shi,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*13,56+24,15,black,black);	
        disp_ASCII_8x16(8*14,56+24,6,black,black);   
        h_bcd(FAN6_current);
    disp_ASCII_8x16(16*5+8+8,104,bai,black,black);
    disp_ASCII_8x16(16*5+8+8+8,104,38,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8,104,shi,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,ge,black,black);  
    }      
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page2_change(void)
{
//h_bcd(FAN1_current);
//    disp_ASCII_8x16(16,56,bai,white,black);
//    disp_ASCII_8x16(16+8,56,38,white,black);
//    disp_ASCII_8x16(16+8+8,56,shi,white,black);
//    disp_ASCII_8x16(16+8+8+8,56,ge,white,black);    
//h_bcd(FAN2_current);
//    disp_ASCII_8x16(16*3+8,56,bai,white,black);
//    disp_ASCII_8x16(16*3+8+8,56,38,white,black);
//    disp_ASCII_8x16(16*3+8+8+8,56,shi,white,black);
//    disp_ASCII_8x16(16*3+8+8+8+8,56,ge,white,black);   
//h_bcd(FAN3_current);
//    disp_ASCII_8x16(16*5+8+8,56,bai,white,black);
//    disp_ASCII_8x16(16*5+8+8+8,56,38,white,black);
//    disp_ASCII_8x16(16*5+8+8+8+8,56,shi,white,black);
//    disp_ASCII_8x16(16*5+8+8+8+8+8,56,ge,white,black);  
/////////////////////////////////////////////////////////////////////////////////////////////       
//h_bcd(FAN4_current);
//    disp_ASCII_8x16(16,104,bai,white,black);
//    disp_ASCII_8x16(16+8,104,38,white,black);
//    disp_ASCII_8x16(16+8+8,104,shi,white,black);
//    disp_ASCII_8x16(16+8+8+8,104,ge,white,black);    
//h_bcd(FAN5_current);
//    disp_ASCII_8x16(16*3+8,104,bai,white,black);
//    disp_ASCII_8x16(16*3+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*3+8+8+8,104,shi,white,black);
//    disp_ASCII_8x16(16*3+8+8+8+8,104,ge,white,black);   
//h_bcd(FAN6_current);
//    disp_ASCII_8x16(16*5+8+8,104,bai,white,black);
//    disp_ASCII_8x16(16*5+8+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*5+8+8+8+8,104,shi,white,black);
//    disp_ASCII_8x16(16*5+8+8+8+8+8,104,ge,white,black);  
//if(FLAG_TEST_YES)
{
/////////////////////////////////////////////////////////////////
    if(FLAG_F1_ON)
    {
        disp_ASCII_8x16(8*3,32,15,red,black);	
        disp_ASCII_8x16(8*4,32,1,red,black);
        h_bcd(FAN1_current);
        disp_ASCII_8x16(16,56,bai,white,black);
        disp_ASCII_8x16(16+8,56,38,white,black);
        disp_ASCII_8x16(16+8+8,56,shi,white,black);
        disp_ASCII_8x16(16+8+8+8,56,ge,white,black);           
    } 
    else
    {
        disp_ASCII_8x16(8*3,32,15,black,black);	
        disp_ASCII_8x16(8*4,32,1,black,black);      
        h_bcd(FAN1_current);
        disp_ASCII_8x16(16,56,bai,black,black);
        disp_ASCII_8x16(16+8,56,38,black,black);
        disp_ASCII_8x16(16+8+8,56,shi,black,black);
        disp_ASCII_8x16(16+8+8+8,56,ge,black,black);           
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F2_ON)
    {
        disp_ASCII_8x16(8*8,32,15,orange,black);	
        disp_ASCII_8x16(8*9,32,2,orange,black);
        h_bcd(FAN2_current);
    disp_ASCII_8x16(16*3+8,56,bai,white,black);
    disp_ASCII_8x16(16*3+8+8,56,38,white,black);
    disp_ASCII_8x16(16*3+8+8+8,56,shi,white,black);
    disp_ASCII_8x16(16*3+8+8+8+8,56,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*8,32,15,black,black);	
        disp_ASCII_8x16(8*9,32,2,black,black);   
        h_bcd(FAN2_current);
    disp_ASCII_8x16(16*3+8,56,bai,black,black);
    disp_ASCII_8x16(16*3+8+8,56,38,black,black);
    disp_ASCII_8x16(16*3+8+8+8,56,shi,black,black);
    disp_ASCII_8x16(16*3+8+8+8+8,56,ge,black,black);  
    }    
/////////////////////////////////////////////////////////////////
    if(FLAG_F3_ON)
    {
        disp_ASCII_8x16(8*13,32,15,yellow,black);	
        disp_ASCII_8x16(8*14,32,3,yellow,black);   
        h_bcd(FAN3_current);
    disp_ASCII_8x16(16*5+8+8,56,bai,white,black);
    disp_ASCII_8x16(16*5+8+8+8,56,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,shi,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*13,32,15,black,black);	
        disp_ASCII_8x16(8*14,32,3,black,black);     
        h_bcd(FAN3_current);
    disp_ASCII_8x16(16*5+8+8,56,bai,black,black);
    disp_ASCII_8x16(16*5+8+8+8,56,38,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,shi,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,ge,black,black);  
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F4_ON)
    {
        disp_ASCII_8x16(8*3,56+24,15,green,black);	
        disp_ASCII_8x16(8*4,56+24,4,green,black);
        h_bcd(FAN4_current);
    disp_ASCII_8x16(16,104,bai,white,black);
    disp_ASCII_8x16(16+8,104,38,white,black);
    disp_ASCII_8x16(16+8+8,104,shi,white,black);
    disp_ASCII_8x16(16+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*3,56+24,15,black,black);	
        disp_ASCII_8x16(8*4,56+24,4,black,black);    
        h_bcd(FAN4_current);
    disp_ASCII_8x16(16,104,bai,black,black);
    disp_ASCII_8x16(16+8,104,38,black,black);
    disp_ASCII_8x16(16+8+8,104,shi,black,black);
    disp_ASCII_8x16(16+8+8+8,104,ge,black,black);  
    }   
/////////////////////////////////////////////////////////////////
    if(FLAG_F5_ON)
    {
        disp_ASCII_8x16(8*8,56+24,15,pink,black);	
        disp_ASCII_8x16(8*9,56+24,5,pink,black);
        h_bcd(FAN5_current);
    disp_ASCII_8x16(16*3+8,104,bai,white,black);
    disp_ASCII_8x16(16*3+8+8,104,38,white,black);
    disp_ASCII_8x16(16*3+8+8+8,104,shi,white,black);
    disp_ASCII_8x16(16*3+8+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*8,56+24,15,black,black);	
        disp_ASCII_8x16(8*9,56+24,5,black,black);       
        h_bcd(FAN5_current);
    disp_ASCII_8x16(16*3+8,104,bai,black,black);
    disp_ASCII_8x16(16*3+8+8,104,38,black,black);
    disp_ASCII_8x16(16*3+8+8+8,104,shi,black,black);
    disp_ASCII_8x16(16*3+8+8+8+8,104,ge,black,black);  
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F6_ON)
    {
        disp_ASCII_8x16(8*13,56+24,15,blue,black);	
        disp_ASCII_8x16(8*14,56+24,6,blue,black); 
        h_bcd(FAN6_current);
    disp_ASCII_8x16(16*5+8+8,104,bai,white,black);
    disp_ASCII_8x16(16*5+8+8+8,104,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,104,shi,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,ge,white,black);  
    } 
    else
    {
        disp_ASCII_8x16(8*13,56+24,15,black,black);	
        disp_ASCII_8x16(8*14,56+24,6,black,black);   
        h_bcd(FAN6_current);
    disp_ASCII_8x16(16*5+8+8,104,bai,black,black);
    disp_ASCII_8x16(16*5+8+8+8,104,38,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8,104,shi,black,black);
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,ge,black,black);  
    }      
}
//else
//{
//
//}
}
