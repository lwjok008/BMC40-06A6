#include"mcc.h"
#include "head.h"

void page4_set3()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
//    vDraw_Line(0,76,164,76,green);    
//    vDraw_Line(0,124,164,124,green);  
 
    disp_ASCII_8x16(0,2,4,red,black);	
    disp_ASCII_8x16(8,2,52,red,black);	
    disp_ASCII_8x16(16,2,3,red,black);	    
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,wei2,white,black);  //  
    disp_16x16(16*3,2,chi2,white,black);  //    
    disp_16x16(16*4,2,shi1,white,black);  //  
    disp_16x16(16*5,2,jian1,white,black);  //   
    disp_16x16(16*6,2,she,white,black);  //  
    disp_16x16(16*7,2,zhi4,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////  
    h_bcd(keep_time);	

    disp_num_24x48(4+48,48,shi,white,black);    
    disp_num_24x48(4+72,48,ge,white,black);
    disp_16x16(4+76+24+8,72,fen1,white,black);  //   
    disp_16x16(4+76+24+8+16,72,zhong,white,black);  //  

//    disp_16x16(16*2,96+12,ji4,green,black);  //   
//    disp_16x16(16*3,96+12,shi1,green,black);  //      
//    disp_ASCII_8x16(16*4,96+12,36,green,black);	
//    disp_ASCII_8x16(16*5+8+8,96+12,22,green,black);     
//    disp_ASCII_8x16(16*5+8+8+8+8+8,96+12,28,green,black);         
    //disp_16x16(4+76+24+8+8+8,72,e12,white,black);  //     
}

void parameter_set3_set(void)
{   
    h_bcd(keep_time);	
//    if(bai==0)   
//    {
//        disp_num_24x48(4+24,48,12,black,black);	
//    }
//    else
//    {
//        disp_num_24x48(4+24,48,bai,red,white);	
//    }
    disp_num_24x48(4+48,48,shi,red,white);    
    disp_num_24x48(4+72,48,ge,red,white);
    
//    h_bcd(KEEP_FAN_RUN_TIME_1min_disp);	
//
//    disp_ASCII_8x16(16*5,96+12,shi,green,black);    
//    disp_ASCII_8x16(16*5+8,96+12,ge,green,black);   
//
//    h_bcd(KEEP_FAN_RUN_TIME_1s_disp);	
//
//    disp_ASCII_8x16(16*5+8+8+8,96+12,shi,green,black);    
//    disp_ASCII_8x16(16*5+8+8+8+8,96+12,ge,green,black);   
//    disp_ASCII_8x16(16*5+8+8+8+8+8,96+12,28,green,black);     
//    FLAG_SET=0;
//    flag_page4_set2=0;
//    page4_fixed();    
}