#include"mcc.h"
#include "head.h"

void page4_set4()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
//    vDraw_Line(0,76,164,76,green);    
//    vDraw_Line(0,124,164,124,green);  
 
    disp_ASCII_8x16(0,2,4,red,black);	
    disp_ASCII_8x16(8,2,52,red,black);	
    disp_ASCII_8x16(16,2,4,red,black);	    
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,C,white,black);  //  
    disp_16x16(16*3,2,T,white,black);  //    
    disp_16x16(16*4,2,gui1,white,black);  //  
    disp_16x16(16*5,2,ge2,white,black);  //   
    disp_16x16(16*6,2,she,white,black);  //  
    disp_16x16(16*7,2,zhi4,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////  

    disp_num_24x48(4+72,48,CT_CURRENT,white,black);
    disp_16x16(4+76+24+8,72,A,white,black);  //   
 
}

void parameter_set4_set(void)
{   
    disp_num_24x48(4+72,48,CT_CURRENT,red,white);
//    FLAG_SET=0;
//    flag_page4_set2=0;
//    page4_fixed();    
}