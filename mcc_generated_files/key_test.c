#include"mcc.h"
#include "head.h"
bit FLAG_SET=0;
bit FLAG_UP,FLAG_DOWN,FLAG_ENTER,FLAG_RETURN,FLAG_RESET;
bit flag_page4_set1=0,flag_page4_set2=0,flag_page4_set3=0,flag_page4_set4=0,flag_page4_set5=0;
bit FLAG_SET_page10,flag_page4_set2_switch;
uchar set_set1=6,set;
uchar keep_time;
uchar CT_CURRENT;
uchar FAN_ONOFF_BYTE;
uchar addr;
void key_test_AD(void)
{
    uchar press;
    if(!KEY_UP)
    {
        press++;
        if(press>=4)
        {
            press=0;
            FLAG_UP=1;
        }
    }
    else if(!KEY_DOWN)
    {
        press++;
        if(press>=4)
        {
            press=0;
            FLAG_DOWN=1;
        }    
    }
    else if(!KEY_ENTER)
    {
        press++;
        if(press>=4)
        {
            press=0;
            FLAG_ENTER=1;          
        }    
    }
    else if(!KEY_RETURN)
    {
        press++;
        if(press>=4)
        {
            press=0;
            FLAG_RETURN=1;
        }    
    }    
    else if(!KEY_RESET)
    {
        press++;
        if(press>=4)
        {
            press=0;
            FLAG_RST=1;
        }   
    }
    else
    {
        press=0;
    }
    if(FLAG_UP)
    {       
        if(KEY_UP)
        {
            FLAG_UP=0;
            if(!FLAG_SET)
            {
                if(lcd_page<4)			//第4页为设置页面
                {
                    lcd_page++;
                }
                else
                {
                    lcd_page=0;
                }
                switch(lcd_page)
                {
                    case 0:	page0_fixed(); break;                    
                    case 1:	page1_fixed(); break;
                    case 2:	page2_fixed(); break;
                    case 3:	page3_fixed(); break;
                    case 4:	page4_fixed(); break;
//                    case 5: page5_fixed(); break;
//                    case 6:	page6_fixed(); break;
//                    case 7:	page7_fixed(); break;
//                    case 8:	page8_fixed(); break;
//                    case 9:	page9_fixed(); break;   
//                    case 10:page10_fixed(); break; 
                }   
            }
            else
            {
                if((!flag_page4_set1)&&(!flag_page4_set2)&&(!flag_page4_set3)&&(!flag_page4_set4)&&(!flag_page4_set5))
                {                
                    
                    if(set==0)			
                    {   
                        set=2;	
                    }	
                    else
                    {
                        set--;
                    }
                    switch(set)
                    {
                        case 0: parameter_set1(); break;
                        case 1:	parameter_set2(); break;   
                        case 2: parameter_set3(); break;
//                        case 3:	parameter_set4(); break;   
//                        case 4: parameter_set5(); break;           
                    }      
                }  
                else
                {
                    if(flag_page4_set1)
                    {
//                        if(set_set1>3)
//                        {
//                           set_set1=0; 
//                        }                        
                        switch(set_set1)
                        {
                            case 0: 
                            if(TEMP_SET1>=60)
                            {
                                TEMP_SET1 = 0;
                            }
                            else
                            {
                                TEMP_SET1 = TEMP_SET1 + 5;
                            }
                            DATAEE_WriteByte(0X05, TEMP_SET1);
                            parameter_set1_set1();break;
                            case 1:	
                            if(TEMP_SET2>=60)
                            {
                                TEMP_SET2 = 0;
                            }
                            else
                            {
                                TEMP_SET2 = TEMP_SET2 + 5;
                            }
                            DATAEE_WriteByte(0X06, TEMP_SET2);
                                parameter_set1_set2();break;
                            case 2: 
                            if(TEMP_SET3>=60)
                            {
                                TEMP_SET3 = 0;
                            }
                            else
                            {
                                TEMP_SET3 = TEMP_SET3 + 5;
                            }
                            DATAEE_WriteByte(0X07, TEMP_SET3);
                                parameter_set1_set3();break;
//                            case 3:	FLAG_F4_ON = ~FLAG_F4_ON; parameter_set1_set4();break;
//                            case 4:	FLAG_F5_ON = ~FLAG_F5_ON; parameter_set1_set5();break;
//                            case 5: FLAG_F6_ON = ~FLAG_F6_ON; parameter_set1_set6();break;                           
                        }  
                    }
                    else if(flag_page4_set2)
                    {
                        if(keep_time>=99)
                        {
                            keep_time = 1;
                        }
                        else
                        {
                            keep_time++;
                        }
                        DATAEE_WriteByte(0X02, keep_time);
                        parameter_set3_set();
                    }                        
                    else if(flag_page4_set3)
                    {
                        parameter_set5_set();
                    }                          
                }
            }
        }
    }
    else if(FLAG_DOWN)
    {        
        if(KEY_DOWN)
        {
            FLAG_DOWN=0;
            if(!FLAG_SET)
            {
                if(lcd_page>0)			
                {
                    lcd_page--;
                }	
                else
                {
                    lcd_page=4;	
                }
                switch(lcd_page)
                {
                    case 0:	page0_fixed(); break;                        
                    case 1:	page1_fixed(); break;
                    case 2:	page2_fixed(); break;
                    case 3:	page3_fixed(); break;
                    case 4:	page4_fixed(); break;
//                    case 5: page5_fixed(); break;
//                    case 6:	page6_fixed(); break;
//                    case 7:	page7_fixed(); break;
//                    case 8:	page8_fixed(); break;
//                    case 9:	page9_fixed(); break;   
//                    case 10:page10_fixed(); break; 
                }  
            }
            else
            {
                if((!flag_page4_set1)&&(!flag_page4_set2)&&(!flag_page4_set3)&&(!flag_page4_set4)&&(!flag_page4_set5))
                {
                    set++;
                    if(set>=3)			
                    {   
                        set=0;	
                    }	
                    switch(set)
                    {
                        case 0: parameter_set1(); break;
                        case 1:	parameter_set2(); break;   
                        case 2: parameter_set3(); break;
//                        case 3:	parameter_set4(); break;   
//                        case 4: parameter_set5(); break;
                    }      
                }   
                else
                {
                    if(flag_page4_set1)
                    {
//                        if(set_set1>3)
//                        {
//                           set_set1=0; 
//                        }                        
                        switch(set_set1)
                        {
                            case 0: 
                            if(TEMP_SET1<=0)
                            {
                                TEMP_SET1 = 60;
                            }
                            else
                            {
                                TEMP_SET1 = TEMP_SET1 - 5;
                            }
                            DATAEE_WriteByte(0X05, TEMP_SET1);
                            parameter_set1_set1();break;
                            case 1:	
                            if(TEMP_SET2<=0)
                            {
                                TEMP_SET2 = 60;
                            }
                            else
                            {
                                TEMP_SET2 = TEMP_SET2 - 5;
                            }
                            DATAEE_WriteByte(0X06, TEMP_SET2);
                                parameter_set1_set2();break;
                            case 2: 
                            if(TEMP_SET3<=0)
                            {
                                TEMP_SET3 = 60;
                            }
                            else
                            {
                                TEMP_SET3 = TEMP_SET3 - 5;
                            }
                            DATAEE_WriteByte(0X07, TEMP_SET3);
                                parameter_set1_set3();break;
//                            case 3:	FLAG_F4_ON = ~FLAG_F4_ON; parameter_set1_set4();break;
//                            case 4:	FLAG_F5_ON = ~FLAG_F5_ON; parameter_set1_set5();break;
//                            case 5: FLAG_F6_ON = ~FLAG_F6_ON; parameter_set1_set6();break;                           
                        }  
//                            FAN_ONOFF_BYTE=((FLAG_F1_ON)+(FLAG_F2_ON<<1)+(FLAG_F3_ON<<2)+(FLAG_F4_ON<<3)+(FLAG_F5_ON<<4)+(FLAG_F6_ON<<5));
//                            DATAEE_WriteByte(0X00, FAN_ONOFF_BYTE); 
                    }
                    else if(flag_page4_set2)
                    {
                        if(keep_time<=1)
                        {
                            keep_time = 99;
                        }
                        else
                        {
                            keep_time--;
                        }
                        DATAEE_WriteByte(0X02, keep_time);
                        parameter_set3_set();
                    }                        
                    else if(flag_page4_set3)
                    {
                        page4_set5();
                    }                          
                }
            }
        }
    }
    else if(FLAG_ENTER) //进入设置或确认、调整参数
    {    
//            ad_value = ADCC_GetSingleConversion(KEY_AD);
            if(KEY_ENTER)
            {
                FLAG_ENTER=0;
                if(4==lcd_page)
                {                   
                    if(!FLAG_SET)
                    {
                        FLAG_SET_page10=1;
                        FLAG_SET=1;
                        set=0;
                        parameter_set1();
//                        switch(set)
//                        {
//                            case 0: parameter_set1(); break;
//                            case 1:	parameter_set2(); break;  
//                            case 2: parameter_set3(); break;
//                            case 3:	parameter_set4(); break;  
//                            case 4:	parameter_set5(); break; 
//                        }  
                        
                    }
                    else
                    {        
                        if((!flag_page4_set1)&&(!flag_page4_set2)&&(!flag_page4_set3))
                        {
                            switch(set)
                            {
                                case 0: 
                                {
                                    display_color(black);	//全屏写白色（清屏）	
                                    page4_set1();
                                    flag_page4_set1=1;
                                }break;
                                case 1:	
                                {
                                    display_color(black);	//全屏写白色（清屏）	
                                    page4_set3(); 
                                    flag_page4_set2=1;
                                }break;      
                                case 2: 
                                {
                                    display_color(black);	//全屏写白色（清屏）	
                                    page4_set5();
                                    flag_page4_set3=1;
                                }break;                                   
                            } 
                            FLAG_ENTER=0;
                        }
                        else
                        {
                            if(flag_page4_set1)
                            {
                                //FLAG_SET=1;
                                set_set1++;
                                if(set_set1>3)			
                                {   
                                    set_set1=0;	
                                }	
                                switch(set_set1)
                                {
                                    case 0: parameter_set1_set1(); break;
                                    case 1:	parameter_set1_set2();break;
                                    case 2:	parameter_set1_set3(); break;
//                                    case 3:	parameter_set1_set4(); break;
//                                    case 4:	parameter_set1_set5(); break;
//                                    case 5: parameter_set1_set6(); break;              
                                }  
                            }
                            else if(flag_page4_set2)
                            {       
                               parameter_set3_set();   
                            }
                            else if(flag_page4_set3)
                            {
                                parameter_set5_set();
                            }                       
                        }
                    }   
                }
                
                FLAG_ENTER=0;
            }
//            else
//            {
//                ;
//            }              
        
    }

    else if(FLAG_RETURN)
    {
        if(KEY_RETURN)        
        {           
            FLAG_RETURN=0;
            set=10;
            if(FLAG_SET_page10)
            {
                FLAG_SET_page10=0;
                FLAG_SET=0;
                page4_fixed();
            }
            if(flag_page4_set1)
            {
                flag_page4_set1=0;
                set_set1 = 6;
            }
            if(flag_page4_set2)
            {
                flag_page4_set2=0;
               // flag_page4_set2_switch=0;
            }   
            if(flag_page4_set3)
            {
                flag_page4_set3=0;
            }
            if(flag_page4_set4)
            {
                flag_page4_set4=0;
            } 
            if(flag_page4_set5)
            {
                flag_page4_set5=0;
            }            
        }
    } 
    else if(FLAG_RESET)
    {   
        if(KEY_RESET)        
        {         
            FLAG_RESET=0;
        }
    }     
}



















