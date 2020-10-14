#include"mcc.h"
#include "head.h"
bit FLAG_F1_RUN,FLAG_F2_RUN,FLAG_F3_RUN,FLAG_F4_RUN,FLAG_F5_RUN,FLAG_F6_RUN;
bit FLAG_F1_OVERLODE,FLAG_F2_OVERLODE,FLAG_F3_OVERLODE,FLAG_F4_OVERLODE,FLAG_F5_OVERLODE,FLAG_F6_OVERLODE;
bit FLAG_F1_BREAK,FLAG_F2_BREAK,FLAG_F3_BREAK,FLAG_F4_BREAK,FLAG_F5_BREAK,FLAG_F6_BREAK;
////////////////////////单独显示实时温度数值//////////////////////////////////////////////////////////////////////
void page1_fixed()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
    vDraw_Line(0,76,164,76,green);    
    vDraw_Line(0,124,164,124,green);  

    vDraw_Line(12,0,12,124,green); 
/////////////////////////////////////////////////////////////////
 
    disp_ASCII_8x16(0,2,1,red,black);	
	
    disp_16x16(16*2,2,feng,white,black);  //  
    disp_16x16(16*3,2,ji,white,black);  //    
    disp_16x16(16*4,2,yun,white,black);  //  
    disp_16x16(16*5,2,xing,white,black);  //   

    disp_16x16(16*6,2,zhuang,white,black);  //  
    disp_16x16(16*7,2,tai,white,black);  // 

/////////////////////////////////////////////////////////////////
    if(FLAG_F1_ON)
    {
        disp_ASCII_8x16(8*3,32,15,red,black);	
        disp_ASCII_8x16(8*4,32,1,red,black);
        if(FLAG_F1_OVERLODE)
        {
            disp_16x16(16,56,guo,red,black);  //  
            disp_16x16(16*2,56,zai,red,black);  //         
        }
        else if(FLAG_F1_BREAK)
        {
            disp_16x16(16,56,duan,red,black);  //  
            disp_16x16(16*2,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F1_RUN)
            {
                disp_16x16(16,56,yun,white,black);  //  
                disp_16x16(16*2,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16,56,ting,white,black);  //  
                disp_16x16(16*2,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*3,32,15,black,black);	
        disp_ASCII_8x16(8*4,32,1,black,black);    
        disp_16x16(16,56,guan,black,black);  //  
        disp_16x16(16*2,56,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F2_ON)
    {
        disp_ASCII_8x16(8*8,32,15,orange,black);	
        disp_ASCII_8x16(8*9,32,2,orange,black);
        if(FLAG_F2_OVERLODE)
        {
            disp_16x16(16*3+8,56,guo,red,black);  //  
            disp_16x16(16*4+8,56,zai,red,black);  //         
        }
        else if(FLAG_F2_BREAK)
        {
            disp_16x16(16*3+8,56,duan,red,black);  //  
            disp_16x16(16*4+8,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F2_RUN)
            {
                disp_16x16(16*3+8,56,yun,white,black);  //  
                disp_16x16(16*4+8,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*3+8,56,ting,white,black);  //  
                disp_16x16(16*4+8,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*8,32,15,black,black);	
        disp_ASCII_8x16(8*9,32,2,black,black);
        disp_16x16(16*3+8,56,guan,black,black);  //  
        disp_16x16(16*4+8,56,bi,black,black);  //         
    }    
/////////////////////////////////////////////////////////////////
    if(FLAG_F3_ON)
    {
        disp_ASCII_8x16(8*13,32,15,yellow,black);	
        disp_ASCII_8x16(8*14,32,3,yellow,black);   
        if(FLAG_F3_OVERLODE)
        {
            disp_16x16(16*5+8+8,56,guo,red,black);  //  
            disp_16x16(16*6+8+8,56,zai,red,black);  //         
        }
        else if(FLAG_F3_BREAK)
        {
            disp_16x16(16*5+8+8,56,duan,red,black);  //  
            disp_16x16(16*6+8+8,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F3_RUN)
            {
                disp_16x16(16*5+8+8,56,yun,white,black);  //  
                disp_16x16(16*6+8+8,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*5+8+8,56,ting,white,black);  //  
                disp_16x16(16*6+8+8,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*13,32,15,black,black);	
        disp_ASCII_8x16(8*14,32,3,black,black);    
        disp_16x16(16*5+8+8,56,guan,black,black);  //  
        disp_16x16(16*6+8+8,56,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F4_ON)
    {
    disp_ASCII_8x16(8*3,56+24,15,green,black);	
    disp_ASCII_8x16(8*4,56+24,4,green,black);
        if(FLAG_F4_OVERLODE)
        {
            disp_16x16(16*1,56+40+8,guo,red,black);  //  
            disp_16x16(16*2,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F4_BREAK)
        {
            disp_16x16(16*1,56+40+8,duan,red,black);  //  
            disp_16x16(16*2,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F4_RUN)
            {
                disp_16x16(16*1,56+40+8,yun,white,black);  //  
                disp_16x16(16*2,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*1,56+40+8,ting,white,black);  //  
                disp_16x16(16*2,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*3,56+24,15,black,black);	
        disp_ASCII_8x16(8*4,56+24,4,black,black);
        disp_16x16(16*1,56+40+8,guan,black,black);  //  
        disp_16x16(16*2,56+40+8,bi,black,black);  //         
    }   
/////////////////////////////////////////////////////////////////
    if(FLAG_F5_ON)
    {
    disp_ASCII_8x16(8*8,56+24,15,pink,black);	
    disp_ASCII_8x16(8*9,56+24,5,pink,black);
        if(FLAG_F5_OVERLODE)
        {
            disp_16x16(16*3+8,56+40+8,guo,red,black);  //  
            disp_16x16(16*4+8,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F5_BREAK)
        {
            disp_16x16(16*3+8,56+40+8,duan,red,black);  //  
            disp_16x16(16*4+8,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F5_RUN)
            {
                disp_16x16(16*3+8,56+40+8,yun,white,black);  //  
                disp_16x16(16*4+8,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*3+8,56+40+8,ting,white,black);  //  
                disp_16x16(16*4+8,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*8,56+24,15,black,black);	
        disp_ASCII_8x16(8*9,56+24,5,black,black); 
        disp_16x16(16*3+8,56+40+8,guan,black,black);  //  
        disp_16x16(16*4+8,56+40+8,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F6_ON)
    {
        disp_ASCII_8x16(8*13,56+24,15,blue,black);	
        disp_ASCII_8x16(8*14,56+24,6,blue,black); 
        if(FLAG_F6_OVERLODE)
        {
            disp_16x16(16*5+8+8,56+40+8,guo,red,black);  //  
            disp_16x16(16*6+8+8,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F6_BREAK)
        {
            disp_16x16(16*5+8+8,56+40+8,duan,red,black);  //  
            disp_16x16(16*6+8+8,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F6_RUN)
            {
                disp_16x16(16*5+8+8,56+40+8,yun,white,black);  //  
                disp_16x16(16*6+8+8,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*5+8+8,56+40+8,ting,white,black);  //  
                disp_16x16(16*6+8+8,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*13,56+24,15,black,black);	
        disp_ASCII_8x16(8*14,56+24,6,black,black); 
        disp_16x16(16*5+8+8,56+40+8,guan,black,black);  //  
        disp_16x16(16*6+8+8,56+40+8,bi,black,black);  //         
    } 
  
}

///////////////////////////////////实时温度变化局部刷新显示////////////////////////////////////////////////////////////
void page1_change(void)
{
/////////////////////////////////////////////////////////////////
    if(FLAG_F1_ON)
    {
        disp_ASCII_8x16(8*3,32,15,red,black);	
        disp_ASCII_8x16(8*4,32,1,red,black);
        if(FLAG_F1_OVERLODE)
        {
            disp_16x16(16,56,guo,red,black);  //  
            disp_16x16(16*2,56,zai,red,black);  //         
        }
        else if(FLAG_F1_BREAK)
        {
            disp_16x16(16,56,duan,red,black);  //  
            disp_16x16(16*2,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F1_RUN)
            {
                disp_16x16(16,56,yun,white,black);  //  
                disp_16x16(16*2,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16,56,ting,white,black);  //  
                disp_16x16(16*2,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*3,32,15,black,black);	
        disp_ASCII_8x16(8*4,32,1,black,black);    
        disp_16x16(16,56,guan,black,black);  //  
        disp_16x16(16*2,56,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F2_ON)
    {
        disp_ASCII_8x16(8*8,32,15,orange,black);	
        disp_ASCII_8x16(8*9,32,2,orange,black);
        if(FLAG_F2_OVERLODE)
        {
            disp_16x16(16*3+8,56,guo,red,black);  //  
            disp_16x16(16*4+8,56,zai,red,black);  //         
        }
        else if(FLAG_F2_BREAK)
        {
            disp_16x16(16*3+8,56,duan,red,black);  //  
            disp_16x16(16*4+8,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F2_RUN)
            {
                disp_16x16(16*3+8,56,yun,white,black);  //  
                disp_16x16(16*4+8,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*3+8,56,ting,white,black);  //  
                disp_16x16(16*4+8,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*8,32,15,black,black);	
        disp_ASCII_8x16(8*9,32,2,black,black);
        disp_16x16(16*3+8,56,guan,black,black);  //  
        disp_16x16(16*4+8,56,bi,black,black);  //         
    }    
/////////////////////////////////////////////////////////////////
    if(FLAG_F3_ON)
    {
        disp_ASCII_8x16(8*13,32,15,yellow,black);	
        disp_ASCII_8x16(8*14,32,3,yellow,black);   
        if(FLAG_F3_OVERLODE)
        {
            disp_16x16(16*5+8+8,56,guo,red,black);  //  
            disp_16x16(16*6+8+8,56,zai,red,black);  //         
        }
        else if(FLAG_F3_BREAK)
        {
            disp_16x16(16*5+8+8,56,duan,red,black);  //  
            disp_16x16(16*6+8+8,56,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F3_RUN)
            {
                disp_16x16(16*5+8+8,56,yun,white,black);  //  
                disp_16x16(16*6+8+8,56,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*5+8+8,56,ting,white,black);  //  
                disp_16x16(16*6+8+8,56,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*13,32,15,black,black);	
        disp_ASCII_8x16(8*14,32,3,black,black);    
        disp_16x16(16*5+8+8,56,guan,black,black);  //  
        disp_16x16(16*6+8+8,56,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F4_ON)
    {
    disp_ASCII_8x16(8*3,56+24,15,green,black);	
    disp_ASCII_8x16(8*4,56+24,4,green,black);
        if(FLAG_F4_OVERLODE)
        {
            disp_16x16(16*1,56+40+8,guo,red,black);  //  
            disp_16x16(16*2,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F4_BREAK)
        {
            disp_16x16(16*1,56+40+8,duan,red,black);  //  
            disp_16x16(16*2,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F4_RUN)
            {
                disp_16x16(16*1,56+40+8,yun,white,black);  //  
                disp_16x16(16*2,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*1,56+40+8,ting,white,black);  //  
                disp_16x16(16*2,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*3,56+24,15,black,black);	
        disp_ASCII_8x16(8*4,56+24,4,black,black);
        disp_16x16(16*1,56+40+8,guan,black,black);  //  
        disp_16x16(16*2,56+40+8,bi,black,black);  //         
    }   
/////////////////////////////////////////////////////////////////
    if(FLAG_F5_ON)
    {
    disp_ASCII_8x16(8*8,56+24,15,pink,black);	
    disp_ASCII_8x16(8*9,56+24,5,pink,black);
        if(FLAG_F5_OVERLODE)
        {
            disp_16x16(16*3+8,56+40+8,guo,red,black);  //  
            disp_16x16(16*4+8,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F5_BREAK)
        {
            disp_16x16(16*3+8,56+40+8,duan,red,black);  //  
            disp_16x16(16*4+8,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F5_RUN)
            {
                disp_16x16(16*3+8,56+40+8,yun,white,black);  //  
                disp_16x16(16*4+8,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*3+8,56+40+8,ting,white,black);  //  
                disp_16x16(16*4+8,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*8,56+24,15,black,black);	
        disp_ASCII_8x16(8*9,56+24,5,black,black); 
        disp_16x16(16*3+8,56+40+8,guan,black,black);  //  
        disp_16x16(16*4+8,56+40+8,bi,black,black);  //         
    }
/////////////////////////////////////////////////////////////////
    if(FLAG_F6_ON)
    {
        disp_ASCII_8x16(8*13,56+24,15,blue,black);	
        disp_ASCII_8x16(8*14,56+24,6,blue,black); 
        if(FLAG_F6_OVERLODE)
        {
            disp_16x16(16*5+8+8,56+40+8,guo,red,black);  //  
            disp_16x16(16*6+8+8,56+40+8,zai,red,black);  //         
        }
        else if(FLAG_F6_BREAK)
        {
            disp_16x16(16*5+8+8,56+40+8,duan,red,black);  //  
            disp_16x16(16*6+8+8,56+40+8,xian4,red,black);  // 
        }
        else 
        {
            if(FLAG_F6_RUN)
            {
                disp_16x16(16*5+8+8,56+40+8,yun,white,black);  //  
                disp_16x16(16*6+8+8,56+40+8,xing,white,black);  // 
            }
            else
            {
                disp_16x16(16*5+8+8,56+40+8,ting,white,black);  //  
                disp_16x16(16*6+8+8,56+40+8,zhi,white,black);  //                 
            }
        }
        
    } 
    else
    {
        disp_ASCII_8x16(8*13,56+24,15,black,black);	
        disp_ASCII_8x16(8*14,56+24,6,black,black); 
        disp_16x16(16*5+8+8,56+40+8,guan,black,black);  //  
        disp_16x16(16*6+8+8,56+40+8,bi,black,black);  //         
    }          
}
