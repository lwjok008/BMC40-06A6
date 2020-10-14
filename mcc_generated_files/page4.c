#include"mcc.h"
#include "head.h"
uint A_RUN_counter_120S,B_RUN_counter_120S,C_RUN_counter_120S;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page4_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,23,black);  //第一行标题栏 灰色处理
    
/////////////////////////////////////////////////////////////////
    disp_ASCII_8x16(0,1,4,red,black);	 
    disp_16x16(16*3,1,she,red,black);  //    
    disp_16x16(16*4,1,zhi4,red,black);  //  
    disp_16x16(16*5,1,jie,red,black);  //   
    disp_16x16(16*6,1,mian,red,black);  //  
vDraw_Line(0,20,164,20,green);	

    disp_16x16(16*2,1+16+6,qi3,white,black);  //  
    disp_16x16(16*3,1+16+6,dong,white,black);  //    
    disp_16x16(16*4,1+16+6,wen,white,black);  //  
    disp_16x16(16*5,1+16+6,du,white,black);  //   
    disp_16x16(16*6,1+16+6,she,white,black);  //  
    disp_16x16(16*7,1+16+6,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+22,wei2,white,black);  //  
    disp_16x16(16*3,1+16+6+22,chi2,white,black);  //    
    disp_16x16(16*4,1+16+6+22,shi1,white,black);  //  
    disp_16x16(16*5,1+16+6+22,jian1,white,black);  //   
    disp_16x16(16*6,1+16+6+22,she,white,black);  //  
    disp_16x16(16*7,1+16+6+22,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+44,ben3,white,black);  //  
    disp_16x16(16*3,1+16+6+44,ji,white,black);  //    
    disp_16x16(16*4,1+16+6+44,xin4,white,black);  //  
    disp_16x16(16*5,1+16+6+44,xi1,white,black);  //   
    disp_16x16(16*6,1+16+6+44,cha2,white,black);  //  
    disp_16x16(16*7,1+16+6+44,xun2,white,black);  //  
     
}
void parameter_set1()
{
    disp_16x16(16*2,1+16+6,qi3,red,white);  //  
    disp_16x16(16*3,1+16+6,dong,red,white);  //    
    disp_16x16(16*4,1+16+6,wen,red,white);  //  
    disp_16x16(16*5,1+16+6,du,red,white);  //   
    disp_16x16(16*6,1+16+6,she,red,white);  //  
    disp_16x16(16*7,1+16+6,zhi4,red,white);  // 

    disp_16x16(16*2,1+16+6+22,wei2,white,black);  //  
    disp_16x16(16*3,1+16+6+22,chi2,white,black);  //    
    disp_16x16(16*4,1+16+6+22,shi1,white,black);  //  
    disp_16x16(16*5,1+16+6+22,jian1,white,black);  //   
    disp_16x16(16*6,1+16+6+22,she,white,black);  //  
    disp_16x16(16*7,1+16+6+22,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+44,ben3,white,black);  //  
    disp_16x16(16*3,1+16+6+44,ji,white,black);  //    
    disp_16x16(16*4,1+16+6+44,xin4,white,black);  //  
    disp_16x16(16*5,1+16+6+44,xi1,white,black);  //   
    disp_16x16(16*6,1+16+6+44,cha2,white,black);  //  
    disp_16x16(16*7,1+16+6+44,xun2,white,black);  //  

}
/////////////////////////////////////////////////////////////////////////////////////////
void parameter_set2()
{
    disp_16x16(16*2,1+16+6,qi3,white,black);  //  
    disp_16x16(16*3,1+16+6,dong,white,black);  //    
    disp_16x16(16*4,1+16+6,wen,white,black);  //  
    disp_16x16(16*5,1+16+6,du,white,black);  //   
    disp_16x16(16*6,1+16+6,she,white,black);  //  
    disp_16x16(16*7,1+16+6,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+22,wei2,red,white);  //  
    disp_16x16(16*3,1+16+6+22,chi2,red,white);  //    
    disp_16x16(16*4,1+16+6+22,shi1,red,white);  //  
    disp_16x16(16*5,1+16+6+22,jian1,red,white);  //   
    disp_16x16(16*6,1+16+6+22,she,red,white);  //  
    disp_16x16(16*7,1+16+6+22,zhi4,red,white);  // 

    disp_16x16(16*2,1+16+6+44,ben3,white,black);  //  
    disp_16x16(16*3,1+16+6+44,ji,white,black);  //    
    disp_16x16(16*4,1+16+6+44,xin4,white,black);  //  
    disp_16x16(16*5,1+16+6+44,xi1,white,black);  //   
    disp_16x16(16*6,1+16+6+44,cha2,white,black);  //  
    disp_16x16(16*7,1+16+6+44,xun2,white,black);  //   
}
void parameter_set3()
{
    disp_16x16(16*2,1+16+6,qi3,white,black);  //  
    disp_16x16(16*3,1+16+6,dong,white,black);  //    
    disp_16x16(16*4,1+16+6,wen,white,black);  //  
    disp_16x16(16*5,1+16+6,du,white,black);  //   
    disp_16x16(16*6,1+16+6,she,white,black);  //  
    disp_16x16(16*7,1+16+6,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+22,wei2,white,black);  //  
    disp_16x16(16*3,1+16+6+22,chi2,white,black);  //    
    disp_16x16(16*4,1+16+6+22,shi1,white,black);  //  
    disp_16x16(16*5,1+16+6+22,jian1,white,black);  //   
    disp_16x16(16*6,1+16+6+22,she,white,black);  //  
    disp_16x16(16*7,1+16+6+22,zhi4,white,black);  // 

    disp_16x16(16*2,1+16+6+44,ben3,red,white);  //  
    disp_16x16(16*3,1+16+6+44,ji,red,white);  //    
    disp_16x16(16*4,1+16+6+44,xin4,red,white);  //  
    disp_16x16(16*5,1+16+6+44,xi1,red,white);  //   
    disp_16x16(16*6,1+16+6+44,cha2,red,white);  //  
    disp_16x16(16*7,1+16+6+44,xun2,red,white);  //  

}
/////////////////////////////////////////////////////////////////////////////////////////
void parameter_set4()
{
    ;
}
/////////////////////////////////////////////////////////////////////////////////////////
void parameter_set5()
{
    ;
}
///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page4_change(void)
{

}
