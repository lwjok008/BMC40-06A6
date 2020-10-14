#include"mcc.h"
#include "head.h"
uint A_RUN_counter,B_RUN_counter,C_RUN_counter;
bit FLAG_AUTO,FLAG_STOP,FLAG_FORCE,FLAG_RST;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page3_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,23,164,23,green);	
/////////////////////////////////////////////////////////////////
    disp_ASCII_8x16(0,2,3,red,black);	 
//    disp_ASCII_8x16(0,2,1,white,black);	
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,yuan3,white,black);  //  
    disp_16x16(16*3,2,fang,white,black);  //    
    disp_16x16(16*4,2,shu1,white,black);  //  
    disp_16x16(16*5,2,ru,white,black);  //   
    disp_16x16(16*6,2,zhuang,white,black);  //  
    disp_16x16(16*7,2,tai,white,black);  // 
//    disp_ASCII_8x16(16*7+8,2,1,red,black);	
//    disp_ASCII_8x16(16*8,2,37,red,black);	   
//    disp_ASCII_8x16(16*8+8,2,1,red,black);	    
//    disp_ASCII_8x16(16*9,2,0,red,black);	

//    disp_16x16(16*0,32,ting,yellow,black);  //  
//    disp_16x16(16*1,32,zhi,yellow,black);  //    
    disp_16x16(16*2,32,ting,yellow,black);  //  
    disp_16x16(16*3,32,zhi,yellow,black);  //   
disp_ASCII_8x16(16*4,32,36,yellow,black);	

    if(FLAG_STOP)
    {
        disp_ASCII_8x16(16*6,32,24,white,black);
        disp_ASCII_8x16(16*6+8,32,23,white,black);
        disp_ASCII_8x16(16*7,32,15,black,black);
    }
    else
    {
        disp_ASCII_8x16(16*6,32,24,white,black);
        disp_ASCII_8x16(16*6+8,32,15,white,black);
        disp_ASCII_8x16(16*7,32,15,white,black);
    }
    
    disp_16x16(16*0,56,qiang,green,black);  //  
    disp_16x16(16*1,56,zhi44,green,black);  //    
    disp_16x16(16*2,56,qi3,green,black);  //  
    disp_16x16(16*3,56,dong,green,black);  // 
disp_ASCII_8x16(16*4,56,36,green,black);

    if(FLAG_FORCE)
    {
        disp_ASCII_8x16(16*6,56,24,white,black);
        disp_ASCII_8x16(16*6+8,56,23,white,black);
        disp_ASCII_8x16(16*7,56,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,56,24,white,black);
        disp_ASCII_8x16(16*6+8,56,15,white,black);
        disp_ASCII_8x16(16*7,56,15,white,black);
    }
    
//    disp_16x16(16*0+8,80,C,red,black);  //  
//    disp_16x16(16*1,80,xiang,red,black);  //    
    disp_16x16(16*2,80,zi4,red,black);  //  
    disp_16x16(16*3,80,dong,red,black);  //   
disp_ASCII_8x16(16*4,80,36,red,black);	

    if(FLAG_AUTO)
    {
        disp_ASCII_8x16(16*6,80,24,white,black);
        disp_ASCII_8x16(16*6+8,80,23,white,black);
        disp_ASCII_8x16(16*7,80,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,80,24,white,black);
        disp_ASCII_8x16(16*6+8,80,15,white,black);
        disp_ASCII_8x16(16*7,80,15,white,black);
    }

    disp_16x16(16*0,104,yuan3,blue,black);  //  
    disp_16x16(16*1,104,fang,blue,black);  //    
    disp_16x16(16*2,104,fu,blue,black);  //  
    disp_16x16(16*3,104,wei,blue,black);  //   
disp_ASCII_8x16(16*4,104,36,blue,black);	

    if(FLAG_RST)
    {
        disp_ASCII_8x16(16*6,104,24,white,black);
        disp_ASCII_8x16(16*6+8,104,23,white,black);
        disp_ASCII_8x16(16*7,104,15,black,black);
    }
    else
    {
        disp_ASCII_8x16(16*6,104,24,white,black);
        disp_ASCII_8x16(16*6+8,104,15,white,black);
        disp_ASCII_8x16(16*7,104,15,white,black);
    }
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page3_change(void)
{
    if(FLAG_STOP)
    {
        disp_ASCII_8x16(16*6,32,24,white,black);
        disp_ASCII_8x16(16*6+8,32,23,white,black);
        disp_ASCII_8x16(16*7,32,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,32,24,white,black);
        disp_ASCII_8x16(16*6+8,32,15,white,black);
        disp_ASCII_8x16(16*7,32,15,white,black);
    }

    if(FLAG_FORCE)
    {
        disp_ASCII_8x16(16*6,56,24,white,black);
        disp_ASCII_8x16(16*6+8,56,23,white,black);
        disp_ASCII_8x16(16*7,56,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,56,24,white,black);
        disp_ASCII_8x16(16*6+8,56,15,white,black);
        disp_ASCII_8x16(16*7,56,15,white,black);
    }

    if(FLAG_AUTO)
    {
        disp_ASCII_8x16(16*6,80,24,white,black);
        disp_ASCII_8x16(16*6+8,80,23,white,black);
        disp_ASCII_8x16(16*7,80,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,80,24,white,black);
        disp_ASCII_8x16(16*6+8,80,15,white,black);
        disp_ASCII_8x16(16*7,80,15,white,black);
    }    
    if(FLAG_RST)
    {
        disp_ASCII_8x16(16*6,104,24,white,black);
        disp_ASCII_8x16(16*6+8,104,23,white,black);
        disp_ASCII_8x16(16*7,104,15,black,black);        
    }
    else
    {
        disp_ASCII_8x16(16*6,104,24,white,black);
        disp_ASCII_8x16(16*6+8,104,15,white,black);
        disp_ASCII_8x16(16*7,104,15,white,black);
    }
}
