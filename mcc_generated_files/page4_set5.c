#include"mcc.h"
#include "head.h"

void page4_set5()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
//    vDraw_Line(0,76,164,76,green);    
//    vDraw_Line(0,124,164,124,green);  
 
    disp_ASCII_8x16(0,2,4,red,black);	
    disp_ASCII_8x16(8,2,52,red,black);	
    disp_ASCII_8x16(16,2,5,red,black);	    
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,ben3,white,black);  //  
    disp_16x16(16*3,2,ji,white,black);  //    
    disp_16x16(16*4,2,xin4,white,black);  //  
    disp_16x16(16*5,2,xi1,white,black);  //   
    disp_16x16(16*6,2,cha2,white,black);  //  
    disp_16x16(16*7,2,xun2,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////  
    disp_16x16(16*1,32,xing2,yellow,black);  //  
    disp_16x16(16*2,32,hao4,yellow,black);  //   
disp_ASCII_8x16(16*3,32,36,yellow,black);	

    disp_ASCII_8x16(16*3+8,32,11,white,black);
    disp_ASCII_8x16(16*4,32,22,white,black);
    disp_ASCII_8x16(16*4+8,32,12,white,black);
    disp_ASCII_8x16(16*4+8+8,32,4,white,black);
    disp_ASCII_8x16(16*4+8+8+8,32,0,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8,32,40,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8+8,32,0,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8+8+8,32,6,white,black);
    
    disp_16x16(16,56,ban3,green,black);  //  
    disp_16x16(16*2,56,ben3,green,black);  //    
    disp_16x16(16*3,56,hao4,green,black);  //  
disp_ASCII_8x16(16*4,56,36,green,black);
    disp_ASCII_8x16(16*5,56,31,white,black);
    disp_ASCII_8x16(16*5+8,56,1,white,black);
    disp_ASCII_8x16(16*5+8+8,56,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8,56,0,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,0,white,black);

//    disp_16x16(16*1,80,dian4,red,black);  //  
//    disp_16x16(16*2,80,hua4,red,black);  //    
//disp_ASCII_8x16(16*3,80,36,red,black);
//
//    disp_ASCII_8x16(16*3+8,80,0,white,black);
//    disp_ASCII_8x16(16*4,80,5,white,black);
//    disp_ASCII_8x16(16*4+8,80,9,white,black);
//    disp_ASCII_8x16(16*4+8+8,80,2,white,black);
//    disp_ASCII_8x16(16*4+8+8+8,80,40,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8,80,7,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8,80,8,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8,80,0,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8,80,6,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8,80,0,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8,80,6,white,black); 
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8+8,80,6,white,black);     

//    disp_16x16(16*1,104,wang3,blue,black);  //  
//    disp_16x16(16*2,104,zhi3,blue,black);  //    
//disp_ASCII_8x16(16*3,104,36,blue,black);
//
//    disp_ASCII_8x16(16*3+8,104,32,white,black);
//    disp_ASCII_8x16(16*4,104,32,white,black);
//    disp_ASCII_8x16(16*4+8,104,32,white,black);
//    disp_ASCII_8x16(16*4+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*4+8+8+8,104,25,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8,104,14,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8,104,10,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8,104,20,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8,104,28,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8,104,12,white,black); 
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8+8,104,23,white,black);        
 
}

void parameter_set5_set(void)
{   
    disp_16x16(16*1,32,xing2,yellow,black);  //  
    disp_16x16(16*2,32,hao4,yellow,black);  //   
disp_ASCII_8x16(16*3,32,36,yellow,black);	

    disp_ASCII_8x16(16*3+8,32,11,white,black);
    disp_ASCII_8x16(16*4,32,22,white,black);
    disp_ASCII_8x16(16*4+8,32,12,white,black);
    disp_ASCII_8x16(16*4+8+8,32,4,white,black);
    disp_ASCII_8x16(16*4+8+8+8,32,0,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8,32,40,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8+8,32,0,white,black);
    disp_ASCII_8x16(16*4+8+8+8+8+8+8,32,6,white,black);
    
    disp_16x16(16,56,ban3,green,black);  //  
    disp_16x16(16*2,56,ben3,green,black);  //    
    disp_16x16(16*3,56,hao4,green,black);  //  
disp_ASCII_8x16(16*4,56,36,green,black);
    disp_ASCII_8x16(16*5,56,31,white,black);
    disp_ASCII_8x16(16*5+8,56,1,white,black);
    disp_ASCII_8x16(16*5+8+8,56,38,white,black);
    disp_ASCII_8x16(16*5+8+8+8,56,0,white,black);
    disp_ASCII_8x16(16*5+8+8+8+8,56,0,white,black);

//    disp_16x16(16*1,80,dian4,red,black);  //  
//    disp_16x16(16*2,80,hua4,red,black);  //    
//disp_ASCII_8x16(16*3,80,36,red,black);
//
//    disp_ASCII_8x16(16*3+8,80,0,white,black);
//    disp_ASCII_8x16(16*4,80,5,white,black);
//    disp_ASCII_8x16(16*4+8,80,9,white,black);
//    disp_ASCII_8x16(16*4+8+8,80,2,white,black);
//    disp_ASCII_8x16(16*4+8+8+8,80,40,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8,80,7,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8,80,8,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8,80,0,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8,80,6,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8,80,0,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8,80,6,white,black); 
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8+8,80,6,white,black);     
//
//    disp_16x16(16*1,104,wang3,blue,black);  //  
//    disp_16x16(16*2,104,zhi3,blue,black);  //    
//disp_ASCII_8x16(16*3,104,36,blue,black);
//
//    disp_ASCII_8x16(16*3+8,104,32,white,black);
//    disp_ASCII_8x16(16*4,104,32,white,black);
//    disp_ASCII_8x16(16*4+8,104,32,white,black);
//    disp_ASCII_8x16(16*4+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*4+8+8+8,104,25,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8,104,14,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8,104,10,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8,104,20,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8,104,28,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8,104,38,white,black);
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8,104,12,white,black); 
//    disp_ASCII_8x16(16*4+8+8+8+8+8+8+8+8+8+8,104,23,white,black);   
}
