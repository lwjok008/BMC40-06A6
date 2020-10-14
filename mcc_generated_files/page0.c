#include"mcc.h"
#include "head.h"
void page0_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	

    disp_ASCII_8x16(0,2,0,black,black);	
  
    disp_16x16(16*3,2,shi2,white,black);  //  
    disp_16x16(16*4,2,shi1,white,black);  //   
    disp_16x16(16*5,2,shu,white,black);  //  
    disp_16x16(16*6,2,ju4,white,black);  // 

    disp_16x16(16*1,32,huan,yellow,black);  //    
    disp_16x16(16*2,32,jing4,yellow,black);  // 
    disp_16x16(16*3,32,wen,yellow,black);  //    
    disp_16x16(16*4,32,du,yellow,black);  //   
    disp_ASCII_8x16(16*5,32,36,yellow,black);	
    h_bcd(temp1);
    if(flag_minus_t1)
    {
       disp_ASCII_8x16(16*7,32,40,white,black);	 
    }
    else
    {
        disp_ASCII_8x16(16*7,32,bai,black,black);	
    } 
    disp_ASCII_8x16(16*7+8,32,shi,white,black);	    
    disp_ASCII_8x16(16*8,32,ge,white,black);
    disp_16x16(16*8+8+4,32,sheshidu,yellow,black);  //   

   // disp_16x16(16*0+8+8,56,yi,green,black);  // 
    disp_ASCII_8x16(16*0+8+8+8,56,1,green,black);	
    disp_16x16(16*1+8+8,56,zu3,green,black);  //         
    disp_16x16(16*2+8+8,56,wei2,green,black);  //   
    disp_16x16(16*3+8+8,56,chi2,green,black);  //      
    disp_ASCII_8x16(16*4+8+8,56,36,green,black);	
    disp_ASCII_8x16(16*5+8+8+8+8,56,22,green,black);     
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,56,28,green,black);       
    h_bcd(KEEP_FAN_RUN_TIME_1min_disp1);	
    disp_ASCII_8x16(16*5+8+8,56,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,56,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp1);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,56,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,56,28,green,black);       
    
    disp_ASCII_8x16(16*0+8+8+8,80,2,green,black);	
    disp_16x16(16*1+8+8,80,zu3,green,black);  //         
    disp_16x16(16*2+8+8,80,wei2,green,black);  //   
    disp_16x16(16*3+8+8,80,chi2,green,black);  //      
    disp_ASCII_8x16(16*4+8+8,80,36,green,black);	
    disp_ASCII_8x16(16*5+8+8+8+8,80,22,green,black);     
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,80,28,green,black);       
    h_bcd(KEEP_FAN_RUN_TIME_1min_disp2);	
    disp_ASCII_8x16(16*5+8+8,80,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,80,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp2);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,80,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,80,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,80,28,green,black);   

    disp_ASCII_8x16(16*0+8+8+8,104,3,green,black);	
    disp_16x16(16*1+8+8,104,zu3,green,black);  //         
    disp_16x16(16*2+8+8,104,wei2,green,black);  //   
    disp_16x16(16*3+8+8,104,chi2,green,black);  //      
    disp_ASCII_8x16(16*4+8+8,104,36,green,black);	
    disp_ASCII_8x16(16*5+8+8+8+8,104,22,green,black);     
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,104,28,green,black);       
    h_bcd(KEEP_FAN_RUN_TIME_1min_disp3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp3);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,104,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,104,28,green,black);       
}
void page0_change(void)
{   
///////////////////////////////////////////////////////////////////////////////////////////  
    h_bcd(temp1);
    if(!flag_t1_err)
    {
        if(flag_minus_t1)
        {
           disp_ASCII_8x16(16*7,32,40,white,black);	 
        }
        else
        {
            disp_ASCII_8x16(16*7,32,bai,black,black);	
        } 
        disp_ASCII_8x16(16*7+8,32,shi,white,black);	    
        disp_ASCII_8x16(16*8,32,ge,white,black);
    }
    else
    {
        disp_ASCII_8x16(16*7,32,40,white,black);	 
        disp_ASCII_8x16(16*7+8,32,40,white,black);	    
        disp_ASCII_8x16(16*8,32,40,white,black);        
    }
    h_bcd(KEEP_FAN_RUN_TIME_1min_disp1);	
    disp_ASCII_8x16(16*5+8+8,56,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,56,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp1);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,56,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,56,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,56,28,green,black);    
    
    h_bcd(KEEP_FAN_RUN_TIME_1min_disp2);	
    disp_ASCII_8x16(16*5+8+8,80,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,80,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp2);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,80,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,80,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,80,28,green,black);    

    h_bcd(KEEP_FAN_RUN_TIME_1min_disp3);	
    disp_ASCII_8x16(16*5+8+8,104,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8,104,ge,green,black);   

    h_bcd(KEEP_FAN_RUN_TIME_1s_disp3);	
    disp_ASCII_8x16(16*5+8+8+8+8+8,104,shi,green,black);    
    disp_ASCII_8x16(16*5+8+8+8+8+8+8,104,ge,green,black);   
    disp_ASCII_8x16(16*5+8+8+8+8+8+8+8,104,28,green,black);        
}

