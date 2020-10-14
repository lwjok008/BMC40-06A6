#include"mcc.h"
#include "head.h"
uchar start_current;
uchar TEMP_SET1,TEMP_SET2,TEMP_SET3;
void page4_set2()
{
	display_color(black);	//全屏写白色（清屏）	
	line_display_color(0,28,black);  //第一行标题栏 灰色处理
    vDraw_Line(0,28,164,28,green);	
//    vDraw_Line(0,76,164,76,green);    
//    vDraw_Line(0,124,164,124,green);  
 
    disp_ASCII_8x16(0,2,4,red,black);	
    disp_ASCII_8x16(8,2,52,red,black);	
    disp_ASCII_8x16(16,2,2,red,black);	    
//    disp_ASCII_8x16(8,2,38,white,black);		
    disp_16x16(16*2,2,qi3,white,black);  //  
    disp_16x16(16*3,2,dong,white,black);  //    
    disp_16x16(16*4,2,tiao2,white,black);  //  
    disp_16x16(16*5,2,jian4,white,black);  //   
    disp_16x16(16*6,2,she,white,black);  //  
    disp_16x16(16*7,2,zhi4,white,black);  // 
///////////////////////////////////////////////////////////////////////////////////////////  
//    h_bcd(start_current);	
//    if(bai==0)   
//    {
//        disp_num_24x48(4+24,48,12,black,black);	
//    }
//    else
//    {
//        disp_num_24x48(4+24,48,bai,white,black);	
//    }
//    disp_num_24x48(4+48,48,shi,white,black);    
//    disp_num_24x48(4+72,48,ge,white,black);
//    disp_16x16(4+76+24+8,72,baifenhao12,white,black);  //   
//    disp_16x16(4+76+24+8+8,72,I12,white,black);  //  
//    disp_16x16(4+76+24+8+8+8,72,e12,white,black);  //     
    
    
    ////////////***************//////////////////
///////////////////////////T1温度//////////////////////////////////////
//disp_ASCII_8x16(40,32,29,yellow,black);	
//disp_ASCII_8x16(48,32,1,yellow,black);	
disp_16x16(16*1,32,qi3,yellow,black);  //    
disp_16x16(16*2,32,dong,yellow,black);  // 
disp_16x16(16*3,32,dian4,yellow,black);  //    
disp_16x16(16*4,32,liu,yellow,black);  //   
disp_ASCII_8x16(16*5,32,36,yellow,black);	
//disp_16x16(88+16,32,xiaoyudengyu,yellow,black);
    h_bcd(start_current);
    if(bai==0)   
    {
        disp_ASCII_8x16(16*7,32,12,black,black);	
    }
    else
    {
        disp_ASCII_8x16(16*7,32,bai,white,black);	
    }    
    disp_ASCII_8x16(16*7+8,32,shi,white,black);	    
    disp_ASCII_8x16(16*8,32,ge,white,black);
    disp_16x16(16*8+8+4,32,baifenhao12,yellow,black);  //  
///////////////////////////1#湿度//////////////////////////////////////    

    
///////////////////////////2#温度//////////////////////////////////////
disp_16x16(16*1,80,qi3,yellow,black);  //    
disp_16x16(16*2,80,dong,yellow,black);  // 
disp_16x16(16*3,80,wen,yellow,black);  //    
disp_16x16(16*4,80,du,yellow,black);  //   
disp_ASCII_8x16(16*5,80,36,yellow,black);	
//disp_16x16(88+16,80,xiaoyudengyu,yellow,black);	

h_bcd(TEMP_SET1);
disp_ASCII_8x16(16*7+8,80,shi,white,black);	    
disp_ASCII_8x16(16*8,80,ge,white,black);
disp_16x16(16*8+8+4,80,sheshidu,yellow,black);  //   
///////////////////////////2#湿度//////////////////////////////////////    

}
//void parameter_set2_set(void)
//{   
//    h_bcd(start_current);	
//    if(bai==0)   
//    {
//        disp_num_24x48(4+24,48,12,black,black);	
//    }
//    else
//    {
//        disp_num_24x48(4+24,48,bai,red,white);	
//    }
//    disp_num_24x48(4+48,48,shi,red,white);    
//    disp_num_24x48(4+72,48,ge,red,white);
////    FLAG_SET=0;
////    flag_page4_set2=0;
////    page4_fixed();    
//}

//////////////////////////////////////////////////////////////////////////////
void parameter_set2_set1(void)
{
    ///////////////////////////1#启动温度//////////////////////////////////////
    h_bcd(start_current);
    if(bai==0)   
    {
        disp_ASCII_8x16(16*7,32,12,black,black);	
    }
    else
    {
        disp_ASCII_8x16(16*7,32,bai,red,white);	
    }     
    disp_ASCII_8x16(16*7+8,32,shi,red,white);	    
    disp_ASCII_8x16(16*8,32,ge,red,white);

    ///////////////////////////2#启动温度//////////////////////////////////////
    h_bcd(TEMP_SET1);
    disp_ASCII_8x16(16*7+8,80,shi,white,black);	    
    disp_ASCII_8x16(16*8,80,ge,white,black);


}

void parameter_set2_set3(void)
{
    ///////////////////////////1#启动电流//////////////////////////////////////
    h_bcd(start_current);
    if(bai==0)   
    {
        disp_ASCII_8x16(16*7,32,12,black,black);	
    }
    else
    {
        disp_ASCII_8x16(16*7,32,bai,white,black);	
    }  
    disp_ASCII_8x16(16*7+8,32,shi,white,black);	    
    disp_ASCII_8x16(16*8,32,ge,white,black);
 
    ///////////////////////////2#启动温度//////////////////////////////////////
    h_bcd(TEMP_SET1);
    disp_ASCII_8x16(16*7+8,80,shi,red,white);	    
    disp_ASCII_8x16(16*8,80,ge,red,white);

    ///////////////////////////2#湿度//////////////////////////////////////    

}