#include "mcc.h"
#include"head.h"
#define BREAK_WIRE_VALUE 10
#define N  11
BYTE_BITS SYSTEM_FLAG;
bit FLAG_TEST_YES;
bit FLAG_TEST_YES1,FLAG_TEST_YES2,FLAG_TEST_YES3;
void INPUT_COLLECT(void);
void FAN_CTRL(void);  
void ALARM_OUT(void);
void LED_CTRL(void);
void FAN_CURRENT_COLLECT(void);

uchar FLAG_BYTE,FLAG_BYTE_BKP;

uchar add,add1,add2,add3,add4,add5,add6;

uint16_t ad_value_FAN11[11],ad_value_FAN21[11],ad_value_FAN31[11],ad_value_FAN41[11],ad_value_FAN51[11],ad_value_FAN61[11],ad_value_CT1[11];
uint32_t ad_value_FAN1,ad_value_FAN2,ad_value_FAN3,ad_value_FAN4,ad_value_FAN5,ad_value_FAN6,ad_value_CT;
uint FAN1_current,FAN2_current,FAN3_current,FAN4_current,FAN5_current,FAN6_current,CT_current_ad;
//bit FLAG_FAN1_RUN,FLAG_FAN2_RUN,FLAG_FAN3_RUN,FLAG_FAN4_RUN,FLAG_FAN5_RUN,FLAG_FAN6_RUN;
uint A_RUN_counter_24H=0;
uchar AUTO_Key_Input_count,STOP_Key_Input_count,FORCE_Key_Input_count,RST_Key_Input_count;
bit FLAG_CT_RUN,FLAG_CT_STOP,FLAG_RUN,FLAG_STOP_RUN;
bit FLAG_RUN1,FLAG_STOP_RUN1,FLAG_STOP_RUN1_1;
bit FLAG_RUN2,FLAG_STOP_RUN2,FLAG_STOP_RUN2_1;
bit FLAG_RUN3,FLAG_STOP_RUN3,FLAG_STOP_RUN3_1;
bit FLAG_RUN2_1;
bit FLAG_RUN3_1;
bit FLAG_RUN_bkp1,FLAG_RUN_bkp2,FLAG_RUN_bkp3,FLAG_RUN_bkp4;
uint16_t FLAG_BYTE16=0,FLAG_BYTE16_BKP=0;
uint F1_OVERLOAD_TIME,F2_OVERLOAD_TIME,F3_OVERLOAD_TIME,F4_OVERLOAD_TIME,F5_OVERLOAD_TIME,F6_OVERLOAD_TIME;
uint CT_RUN_TIME,CT_RUN_TIME1,CT_RUN_TIME2,CT_RUN_TIME3,CT_STOP_TIME,CT_STOP_TIME1,CT_STOP_TIME2,CT_STOP_TIME3;
uint F1_DOWNLOAD_TIME,F2_DOWNLOAD_TIME,F3_DOWNLOAD_TIME,F4_DOWNLOAD_TIME,F5_DOWNLOAD_TIME,F6_DOWNLOAD_TIME;   
uint LED_100ms;
uint KEEP_FAN_RUN_TIME_100ms,KEEP_FAN_RUN_TIME_1s,KEEP_FAN_RUN_TIME_1min;
uint KEEP_FAN_RUN_TIME_100ms1,KEEP_FAN_RUN_TIME_1s1,KEEP_FAN_RUN_TIME_1min1;
uint KEEP_FAN_RUN_TIME_100ms2,KEEP_FAN_RUN_TIME_1s2,KEEP_FAN_RUN_TIME_1min2;
uint KEEP_FAN_RUN_TIME_100ms3,KEEP_FAN_RUN_TIME_1s3,KEEP_FAN_RUN_TIME_1min3;
uint KEEP_FAN_RUN_TIME_1s_disp,KEEP_FAN_RUN_TIME_1min_disp;
uint KEEP_FAN_RUN_TIME_1s_disp1,KEEP_FAN_RUN_TIME_1min_disp1;
uint KEEP_FAN_RUN_TIME_1s_disp2,KEEP_FAN_RUN_TIME_1min_disp2;
uint KEEP_FAN_RUN_TIME_1s_disp3,KEEP_FAN_RUN_TIME_1min_disp3;
void OUTPUT_CTRL(void)
{  
//    ALARM_OUT();      
//    FAN_CTRL(); 
//    LED_CTRL();
}
void ALARM_OUT(void)
{
    FLAG_BYTE16=((FLAG_F1_OVERLODE)+(FLAG_F1_BREAK<<1)+(FLAG_F2_OVERLODE<<2)+(FLAG_F2_BREAK<<3)+(FLAG_F3_OVERLODE<<4)+(FLAG_F3_BREAK<<5)
            +(FLAG_F4_OVERLODE<<6)+(FLAG_F4_BREAK<<7)+(FLAG_F5_OVERLODE<<8)+(FLAG_F5_BREAK<<9)+(FLAG_F6_OVERLODE<<10)+(FLAG_F6_BREAK<<11));
//    if(FLAG_BYTE16>FLAG_BYTE16_BKP)
//    {
//        FLAG_RST=0;
//    }
//    else
//    {
    if(FLAG_RST)
    {
        RLY_ALARM_LAT = 0;
        (FLAG_F1_OVERLODE)=(FLAG_F1_BREAK)=(FLAG_F2_OVERLODE)=(FLAG_F2_BREAK)=(FLAG_F3_OVERLODE)=(FLAG_F3_BREAK)
            =(FLAG_F4_OVERLODE)=(FLAG_F4_BREAK)=(FLAG_F5_OVERLODE)=(FLAG_F5_BREAK)=(FLAG_F6_OVERLODE)=(FLAG_F6_BREAK)=0;
        FLAG_RST=0;
        FLAG_RUN2_1=0;
        FLAG_RUN3_1=0;
        FLAG_TEST_YES1=0; 
        FLAG_TEST_YES2=0; 
        FLAG_TEST_YES3=0; 
        
    }
    else
    {
        if((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK)||(FLAG_F2_OVERLODE)||(FLAG_F2_BREAK)||(FLAG_F3_OVERLODE)||(FLAG_F3_BREAK)
            ||(FLAG_F4_OVERLODE)||(FLAG_F4_BREAK)||(FLAG_F5_OVERLODE)||(FLAG_F5_BREAK)||(FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
        {
            RLY_ALARM_LAT = 1;
        }
        else
        {
            RLY_ALARM_LAT = 0;
        }
//        FLAG_BYTE16_BKP = FLAG_BYTE16;
    } 
    if(flag_t1_err)
    {
        SELF_ALARM_LAT = 0;//自身故障上电断开
    }
    else
    {
        SELF_ALARM_LAT = 1;//自身故障上电断开
    }
}
void LED_CTRL(void)
{
    LED_100ms++;
    if(LED_100ms<=5)
    {
        //LED_100ms=0;
        if((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))
        {
            F1_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F1_RUN)
            {
                F1_LED_LAT = 1;
            }
            else
            {
                F1_LED_LAT = 0;
            }
        }
        if((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK))
        {
            F2_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F2_RUN)
            {
                F2_LED_LAT = 1;
            }
            else
            {
                F2_LED_LAT = 0;
            }
        } 
        if((FLAG_F3_OVERLODE)||(FLAG_F3_BREAK))
        {
            F3_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F3_RUN)
            {
                F3_LED_LAT = 1;
            }
            else
            {
                F3_LED_LAT = 0;
            }
        }
        if((FLAG_F4_OVERLODE)||(FLAG_F4_BREAK))
        {
            F4_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F4_RUN)
            {
                F4_LED_LAT = 1;
            }
            else
            {
                F4_LED_LAT = 0;
            }
        }      
        if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
        {
            F5_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F5_RUN)
            {
                F5_LED_LAT = 1;
            }
            else
            {
                F5_LED_LAT = 0;
            }
        }
        if((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
        {
            F6_LED_LAT = 1;
        }
        else
        {
            if(FLAG_F6_RUN)
            {
                F6_LED_LAT = 1;
            }
            else
            {
                F6_LED_LAT = 0;
            }
        }        

    }
    else if(LED_100ms>5)
    {
        if(LED_100ms>=10)
        {
            LED_100ms=0;
        }
        if((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))
        {
            F1_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F1_RUN)
            {
                F1_LED_LAT = 1;
            }
            else
            {
                F1_LED_LAT = 0;
            }
        }
        if((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK))
        {
            F2_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F2_RUN)
            {
                F2_LED_LAT = 1;
            }
            else
            {
                F2_LED_LAT = 0;
            }
        } 
        if((FLAG_F3_OVERLODE)||(FLAG_F3_BREAK))
        {
            F3_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F3_RUN)
            {
                F3_LED_LAT = 1;
            }
            else
            {
                F3_LED_LAT = 0;
            }
        }
        if((FLAG_F4_OVERLODE)||(FLAG_F4_BREAK))
        {
            F4_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F4_RUN)
            {
                F4_LED_LAT = 1;
            }
            else
            {
                F4_LED_LAT = 0;
            }
        }      
        if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
        {
            F5_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F5_RUN)
            {
                F5_LED_LAT = 1;
            }
            else
            {
                F5_LED_LAT = 0;
            }
        }
        if((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
        {
            F6_LED_LAT = 0;
        }
        else
        {
            if(FLAG_F6_RUN)
            {
                F6_LED_LAT = 1;
            }
            else
            {
                F6_LED_LAT = 0;
            }
        }        

    }
}

void FAN_CTRL(void)
{
    if(FLAG_STOP)
    {
        FLAG_RUN=0;
        FLAG_RUN1=0;
        FLAG_RUN2=0;
        FLAG_RUN3=0;
        FLAG_RUN2_1=0;
        FLAG_RUN3_1=0;
        FLAG_STOP_RUN = 0;
        FLAG_STOP_RUN1 = 0;
        FLAG_STOP_RUN2 = 0;
        FLAG_STOP_RUN3 = 0;
        CT_STOP_TIME=0;
        CT_STOP_TIME1=0;
        CT_STOP_TIME2=0;
        CT_STOP_TIME3=0;
        CT_RUN_TIME=0;  
        CT_RUN_TIME1=0;
        CT_RUN_TIME2=0;  
        CT_RUN_TIME3=0;        
        FLAG_TEST_YES1=0; 
        FLAG_TEST_YES2=0; 
        FLAG_TEST_YES3=0; 
        FLAG_F1_RUN = 0;    

        FLAG_F2_RUN = 0;          

        FLAG_F3_RUN = 0;          

        FLAG_F4_RUN = 0;          

        FLAG_F5_RUN = 0;          

        FLAG_F6_RUN = 0;   
    }
    else if(FLAG_FORCE)
    {
        FLAG_RUN=0;FLAG_RUN1=0;FLAG_RUN2=0;FLAG_RUN3=0;
        FLAG_RUN2_1=0;
        FLAG_RUN3_1=0;
        FLAG_STOP_RUN = 0;FLAG_STOP_RUN1 = 0;FLAG_STOP_RUN2 = 0;FLAG_STOP_RUN3 = 0;
        CT_STOP_TIME=0;
        CT_STOP_TIME1=0;
        CT_STOP_TIME2=0;
        CT_STOP_TIME3=0;
        CT_RUN_TIME=0;  
        CT_RUN_TIME1=0;
        CT_RUN_TIME2=0;  
        CT_RUN_TIME3=0;      
        if(FLAG_F1_ON)
        FLAG_F1_RUN = 1;
        else
        FLAG_F1_RUN = 0;    
        if(FLAG_F2_ON)
        FLAG_F2_RUN = 1;
        else
        FLAG_F2_RUN = 0;          
        if(FLAG_F3_ON)
        FLAG_F3_RUN = 1;
        else
        FLAG_F3_RUN = 0;          
        if(FLAG_F4_ON)
        FLAG_F4_RUN = 1;
        else
        FLAG_F4_RUN = 0;          
        if(FLAG_F5_ON)
        FLAG_F5_RUN = 1;
        else
        FLAG_F5_RUN = 0;          
        if(FLAG_F6_ON)
        FLAG_F6_RUN = 1; 
        else
        FLAG_F6_RUN = 0;    
    }
    else
    {
        if(FLAG_RUN1)
        {
            if(FLAG_F1_ON)
            FLAG_F1_RUN = 1;
            else
            FLAG_F1_RUN = 0;  
            
            if(FLAG_F2_ON)
            FLAG_F2_RUN = 1;
            else
            FLAG_F2_RUN = 0;          
        }
        else
        {
            if(FLAG_F1_ON)
            FLAG_F1_RUN = 0;
            else
            FLAG_F1_RUN = 0; 
            
            if(FLAG_F2_ON)
            FLAG_F2_RUN = 0;
            else
            FLAG_F2_RUN = 0;              
        }
        if(FLAG_RUN2)
        {         
            if(FLAG_F3_ON)
            FLAG_F3_RUN = 1;
            else
            FLAG_F3_RUN = 0;  
            
            if(FLAG_F4_ON)
            FLAG_F4_RUN = 1;
            else
            FLAG_F4_RUN = 0;                 
        }
        else
        {          
            if(FLAG_F3_ON)
            FLAG_F3_RUN = 0;
            else
            FLAG_F3_RUN = 0;          
            if(FLAG_F4_ON)
            FLAG_F4_RUN = 0;
            else
            FLAG_F4_RUN = 0;              
        }
        if(FLAG_RUN3)
        {         
            if(FLAG_F5_ON)
            FLAG_F5_RUN = 1;
            else
            FLAG_F5_RUN = 0;          
            if(FLAG_F6_ON)
            FLAG_F6_RUN = 1; 
            else
            FLAG_F6_RUN = 0;          
        }
        else
        {          
            if(FLAG_F5_ON)
            FLAG_F5_RUN = 0;
            else
            FLAG_F5_RUN = 0;          
            if(FLAG_F6_ON)
            FLAG_F6_RUN = 0; 
            else
            FLAG_F6_RUN = 0;        
        }        
        if(FLAG_STOP_RUN1)
        {
           KEEP_FAN_RUN_TIME_100ms1++;
           if(KEEP_FAN_RUN_TIME_100ms1>=10)
           {
               KEEP_FAN_RUN_TIME_100ms1=0;
               KEEP_FAN_RUN_TIME_1s1++;
               KEEP_FAN_RUN_TIME_1s_disp1++;

               if(KEEP_FAN_RUN_TIME_1s1>=60)
               {
                    KEEP_FAN_RUN_TIME_1s1=0;
                    KEEP_FAN_RUN_TIME_1s_disp1=0;
                    KEEP_FAN_RUN_TIME_1min1++;
                    KEEP_FAN_RUN_TIME_1min_disp1++;
                    if(KEEP_FAN_RUN_TIME_1min1>=keep_time)
                    {
                        KEEP_FAN_RUN_TIME_1min1=keep_time+10;
                        KEEP_FAN_RUN_TIME_1min_disp1=keep_time;
                        FLAG_F1_RUN = 0; 
                        FLAG_F2_RUN = 0; 
                        if(FLAG_F3_RUN)
                        {
                            FLAG_F3_RUN=0;
                        }
                        if(FLAG_F4_RUN)
                        {
                            FLAG_F4_RUN=0;
                        }
                        if(FLAG_F5_RUN)
                        {
                            FLAG_F5_RUN=0;
                        }
                        if(FLAG_F6_RUN)
                        {
                            FLAG_F6_RUN=0;
                        }      
                       
                        FLAG_STOP_RUN=0;
                        FLAG_RUN=0;
                        FLAG_CT_STOP=0;
                        CT_STOP_TIME=0;
                        CT_RUN_TIME=0;
                        FLAG_RUN1=0;                        
                        FLAG_STOP_RUN1 = 0;
                        CT_STOP_TIME1=0;
                        CT_RUN_TIME1=0;
                  
                    }
               }
           }
        }
        else
        {
            KEEP_FAN_RUN_TIME_1min_disp1=0;
            KEEP_FAN_RUN_TIME_1s_disp1=0;
            KEEP_FAN_RUN_TIME_100ms1=0;
            KEEP_FAN_RUN_TIME_1s1=0;
            KEEP_FAN_RUN_TIME_1min1=0;       
        }
        if(FLAG_STOP_RUN2)
        {
           KEEP_FAN_RUN_TIME_100ms2++;
           if(KEEP_FAN_RUN_TIME_100ms2>=10)
           {
               KEEP_FAN_RUN_TIME_100ms2=0;
               KEEP_FAN_RUN_TIME_1s2++;
               KEEP_FAN_RUN_TIME_1s_disp2++;

               if(KEEP_FAN_RUN_TIME_1s2>=60)
               {
                    KEEP_FAN_RUN_TIME_1s2=0;
                    KEEP_FAN_RUN_TIME_1s_disp2=0;
                    KEEP_FAN_RUN_TIME_1min2++;
                    KEEP_FAN_RUN_TIME_1min_disp2++;
                    if(KEEP_FAN_RUN_TIME_1min2>=keep_time)
                    {
                        KEEP_FAN_RUN_TIME_1min2=keep_time+10;
                        KEEP_FAN_RUN_TIME_1min_disp2=keep_time;

                        FLAG_F3_RUN = 0; 
                        FLAG_F4_RUN = 0; 
                        if(FLAG_F5_RUN)
                        {
                            FLAG_F5_RUN=0;
                        }
                        if(FLAG_F6_RUN)
                        {
                            FLAG_F6_RUN=0;
                        } 

                        if(FLAG_STOP_RUN2_1)
                        {
                            FLAG_STOP_RUN2_1=0;
                        }                        
                        FLAG_STOP_RUN=0;
                        FLAG_RUN=0;
                        FLAG_CT_STOP=0;
                        CT_STOP_TIME=0;
                        CT_RUN_TIME=0;
                        FLAG_RUN2=0;
                        FLAG_RUN2_1=0;
                        FLAG_STOP_RUN2 = 0;
                        CT_STOP_TIME2=0;
                        CT_RUN_TIME2=0;  
                   
                    }
               }
           }
        }
        else
        {
            KEEP_FAN_RUN_TIME_1min_disp2=0;
            KEEP_FAN_RUN_TIME_1s_disp2=0;
            KEEP_FAN_RUN_TIME_100ms2=0;
            KEEP_FAN_RUN_TIME_1s2=0;
            KEEP_FAN_RUN_TIME_1min2=0;       
        }
        if(FLAG_STOP_RUN3)
        {
           KEEP_FAN_RUN_TIME_100ms3++;
           if(KEEP_FAN_RUN_TIME_100ms3>=10)
           {
               KEEP_FAN_RUN_TIME_100ms3=0;
               KEEP_FAN_RUN_TIME_1s3++;
               KEEP_FAN_RUN_TIME_1s_disp3++;

               if(KEEP_FAN_RUN_TIME_1s3>=60)
               {
                    KEEP_FAN_RUN_TIME_1s3=0;
                    KEEP_FAN_RUN_TIME_1s_disp3=0;
                    KEEP_FAN_RUN_TIME_1min3++;
                    KEEP_FAN_RUN_TIME_1min_disp3++;
                    if(KEEP_FAN_RUN_TIME_1min3>=keep_time)
                    {
                        KEEP_FAN_RUN_TIME_1min3=keep_time+10;
                        KEEP_FAN_RUN_TIME_1min_disp3=keep_time;
 
                        FLAG_F5_RUN = 0; 
                        FLAG_F6_RUN = 0; 
                        FLAG_STOP_RUN=0;
                        FLAG_RUN=0;
                        FLAG_CT_STOP=0;
                        CT_STOP_TIME=0;
                        CT_RUN_TIME=0;
                        if(FLAG_STOP_RUN3_1)
                        {
                            FLAG_STOP_RUN3_1=0;
                        }

                        FLAG_RUN3=0;
                        FLAG_RUN3_1=0;
                        FLAG_RUN_bkp1=0;
                        FLAG_RUN_bkp2=0;
                        
                        FLAG_STOP_RUN3 = 0;

                        CT_STOP_TIME3=0;
 
                        CT_RUN_TIME3=0;                    
                    }
               }
           }
        }
        else
        {
            KEEP_FAN_RUN_TIME_1min_disp3=0;
            KEEP_FAN_RUN_TIME_1s_disp3=0;
            KEEP_FAN_RUN_TIME_100ms3=0;
            KEEP_FAN_RUN_TIME_1s3=0;
            KEEP_FAN_RUN_TIME_1min3=0;       
        }        
    }
    if(FLAG_F1_RUN)
    {
        if((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))
        {
            FAN1_LAT = 0;           
            if((FLAG_F5_RUN)&&((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK)))
            {
               FLAG_F6_RUN=1;
               FLAG_RUN3_1=1;
               FLAG_RUN_bkp2=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN3=1;
                   FLAG_STOP_RUN3_1=1;
               }
            }
            else
            {
               FLAG_F5_RUN=1;
               FLAG_RUN3_1=1;
               FLAG_RUN_bkp1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN3=1;
                   FLAG_STOP_RUN3_1=1;
               }                
            }  

            if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
            {
                FLAG_F6_RUN=1;  
                FLAG_RUN3_1=1;
            }
            if((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
            {
                FLAG_F3_RUN=1;
                FLAG_RUN2_1=1;
                if(FLAG_STOP_RUN1)
                {
                    FLAG_STOP_RUN2=1;
                    FLAG_STOP_RUN2_1=1;
                }     
            }    
            if((FLAG_F3_OVERLODE)||(FLAG_F3_BREAK))
            {
                FLAG_F4_RUN=1;
                FLAG_RUN2_1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN2=1;
                   FLAG_STOP_RUN2_1=1;
               }                
            }
            if((((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))&&((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))&&((!FLAG_F3_OVERLODE)&&(!FLAG_F3_BREAK))&&((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK))))
            {
                FLAG_F4_RUN=1;
                FLAG_RUN2_1=1;
                if(FLAG_STOP_RUN1)
                {
                    FLAG_STOP_RUN2=1;
                    FLAG_STOP_RUN2_1=1;
                }     
            }    
            if((((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK))&&((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))&&((!FLAG_F6_OVERLODE)&&(!FLAG_F6_BREAK))))
            {
                FLAG_F3_RUN=1;
                FLAG_RUN2_1=1;
                if(FLAG_STOP_RUN1)
                {
                    FLAG_STOP_RUN2=1;
                    FLAG_STOP_RUN2_1=1;
                }     
            }             
        }
        else
        FAN1_LAT = 1;
    }
    else
    FAN1_LAT = 0;    
    if(FLAG_F2_RUN)
    {
        if((FLAG_F2_OVERLODE)||(FLAG_F2_BREAK))
        {
            FAN2_LAT = 0;
            if((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))
            {
               FLAG_F6_RUN=1;
               FLAG_RUN3_1=1;
               FLAG_RUN_bkp2=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN3=1;
                   FLAG_STOP_RUN3_1=1;
               }
            }
            else
            {
               FLAG_F5_RUN=1;
               FLAG_RUN3_1=1;
               FLAG_RUN_bkp1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN3=1;
                   FLAG_STOP_RUN3_1=1;
               }                
            } 
            ////////////////////////又有风机异常///////////////////////
            if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
            {
                FLAG_F6_RUN=1;
                FLAG_RUN3_1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN3=1;
                   FLAG_STOP_RUN3_1=1;
               }
               
            }
            if((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
            {
                FLAG_F3_RUN=1;
                FLAG_RUN2_1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN2=1;
                   FLAG_STOP_RUN2_1=1;
               }

            }    
            if((FLAG_F3_OVERLODE)||(FLAG_F3_BREAK))
            {
                FLAG_F4_RUN=1;
                FLAG_RUN2_1=1;
               if(FLAG_STOP_RUN1)
               {
                   FLAG_STOP_RUN2=1;
                   FLAG_STOP_RUN2_1=1;
               }
               
            }                            
            if((((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))&&((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))&&((!FLAG_F3_OVERLODE)&&(!FLAG_F3_BREAK))&&((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))))
            {
                FLAG_F4_RUN=1;
                FLAG_RUN2_1=1;
                if(FLAG_STOP_RUN1)
                {
                    FLAG_STOP_RUN2=1;
                    FLAG_STOP_RUN2_1=1;
                }     
            }    
            if((((FLAG_F1_OVERLODE)||(FLAG_F1_BREAK))&&((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))&&((!FLAG_F6_OVERLODE)&&(!FLAG_F6_BREAK))))
            {
                FLAG_F3_RUN=1;
                FLAG_RUN2_1=1;
                if(FLAG_STOP_RUN1)
                {
                    FLAG_STOP_RUN2=1;
                    FLAG_STOP_RUN2_1=1;
                }     
            }             
        }
        else
        FAN2_LAT = 1;
    }
    else
    FAN2_LAT = 0;          
    if(FLAG_F3_RUN)
    {
        if((FLAG_F3_OVERLODE)||(FLAG_F3_BREAK))
        {
            FAN3_LAT = 0;
            if((!FLAG_F5_RUN)&&(!FLAG_F6_RUN))
            {
               FLAG_F5_RUN=1;
               FLAG_RUN3_1=1;
                if(FLAG_STOP_RUN2)
                {
                    FLAG_STOP_RUN3=1;
                    FLAG_STOP_RUN3_1=1;
                }
              
            }            
            else if((FLAG_F5_RUN)&&(!FLAG_F6_RUN))
            {
               FLAG_F6_RUN=1;
               FLAG_RUN3_1=1;
            }   
            ////////////////////////又有风机异常///////////////////////
            if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
            {
                FLAG_F6_RUN=1;
                FLAG_RUN3_1=1;
            }   
        }
        else
        FAN3_LAT = 1;
    }
    else
    FAN3_LAT = 0;          
    if(FLAG_F4_RUN)
    {
        if((FLAG_F4_OVERLODE)||(FLAG_F4_BREAK))
        {
            FAN4_LAT = 0;
            if((!FLAG_F5_RUN)&&(!FLAG_F6_RUN))
            {
               FLAG_F5_RUN=1;
               FLAG_RUN3_1=1;
                if(FLAG_STOP_RUN2)
                {
                    FLAG_STOP_RUN3=1;
                    FLAG_STOP_RUN3_1=1;
                }
               
            }            
            else if((FLAG_F5_RUN)&&(!FLAG_F6_RUN))
            {
               FLAG_F6_RUN=1;
               FLAG_RUN3_1=1;
            }   
            ////////////////////////又有风机异常///////////////////////
            if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
            {
                FLAG_F6_RUN=1;
                FLAG_RUN3_1=1;
            }             
        }        
        else
        FAN4_LAT = 1;
    }
    else
    FAN4_LAT = 0;          
    if(FLAG_F5_RUN)
    {
        if((FLAG_F5_OVERLODE)||(FLAG_F5_BREAK))
        FAN5_LAT = 0;
        else
        FAN5_LAT = 1;
    }
    else
    FAN5_LAT = 0;          
    if(FLAG_F6_RUN)
    {
        if((FLAG_F6_OVERLODE)||(FLAG_F6_BREAK))
        FAN6_LAT = 0;
        else
        FAN6_LAT = 1;
    }
    else
    FAN6_LAT = 0;   
//    }

}
void INPUT_COLLECT(void)
{
    if(!STOP_IN_PORT)
    {
		STOP_Key_Input_count++;
		if(STOP_Key_Input_count>=4)
		{	
			FLAG_STOP=1; 	
			STOP_Key_Input_count=50;	
            FLAG_FORCE=0; 	
            FORCE_Key_Input_count=0;            
            FLAG_AUTO=0; 	
            AUTO_Key_Input_count=0;            
		}
	}
	else
	{
		FLAG_STOP=0; 	
		STOP_Key_Input_count=0;
        if(!FORCE_IN_PORT)
        {
            FORCE_Key_Input_count++;
            if(FORCE_Key_Input_count>=5)
            {	
                FLAG_FORCE=1; 	
                FORCE_Key_Input_count=50;	
                FLAG_AUTO=0; 	
                AUTO_Key_Input_count=0;   
            }
        }
        else
        {
            FLAG_FORCE=0; 	
            FORCE_Key_Input_count=0;
            if(!AUTO_IN_PORT)
            {
                AUTO_Key_Input_count++;
                if(AUTO_Key_Input_count>=4)
                {	
                    FLAG_AUTO=1; 	
                    AUTO_Key_Input_count=50;	
                }
            }
            else
            {
                FLAG_AUTO=0; 	
                FLAG_FORCE=0;
                FLAG_STOP=0;
                AUTO_Key_Input_count=0;                
            }              
        }        
	}
    if(!RST_IN_PORT)
    {
        RST_Key_Input_count++;
        if(RST_Key_Input_count>=4)
        {	
            FLAG_RST=1; 	
            RST_Key_Input_count=0;	
        }
    }
    else
    {	
        RST_Key_Input_count=0;
    } 
  
   
}

uint16_t filter(uint16_t *value_buf,adc_channel_t channel)
{
   uchar count,i,j;
   uint16_t temp;
   for ( count=0;count<N;count++)
   {
      value_buf[count] = ADC_GetConversion(channel);
      if((value_buf[count]&0xf000)==0xf000)
      {
          value_buf[count] = 0;
      }
      delay(1);
   }
   for (j=0;j<N-1;j++)
   {
      for (i=0;i<N-j;i++)
      {
         if ( value_buf[i]>value_buf[i+1] )
         {
            temp = value_buf[i];
            value_buf[i] = value_buf[i+1]; 
             value_buf[i+1] = temp;
         }
      }
   }
   return value_buf[(N-1)/2];
}
/*******************电流转换公式：I=3300*AD值/（1024*440）,显示值再乘以100******************************/
void FAN_CURRENT_COLLECT(void)
{  
       
/******************************************************/  
    ////////////////////第1组//////////////////
    if(((temp1)>(TEMP_SET1)))
    {
        CT_RUN_TIME1++;
        CT_STOP_TIME1=0;
        if(CT_RUN_TIME1>=30)
        {
            CT_RUN_TIME1=31;
            FLAG_RUN1=1;
            //if(!FLAG_STOP_RUN1_1)
            FLAG_STOP_RUN1 = 0;
        }
    }
    else
    {
        CT_RUN_TIME1=0;          
    }
    if(FLAG_RUN1)
    {
        if(((temp1)<(TEMP_SET1-5)))
        {
            CT_STOP_TIME1++;
            CT_RUN_TIME1=0;
            if(CT_STOP_TIME1>=30)
            {
                CT_STOP_TIME1=31;
                FLAG_STOP_RUN1 = 1;
            }
        }
        else
        {
            CT_STOP_TIME1=0;
        }
    }
    else
    {
//        CT_STOP_TIME=0;
//        CT_RUN_TIME=0;    
    }
    ////////////////////第2组//////////////////    
    if(((temp1)>(TEMP_SET2)))
    {
        CT_RUN_TIME2++;
        CT_STOP_TIME2=0;
        if(CT_RUN_TIME2>=30)
        {
            CT_RUN_TIME2=31;
            FLAG_RUN2=1;
            //if(!FLAG_STOP_RUN2_1)
            FLAG_STOP_RUN2 = 0;
        }
    }
    else
    {
        CT_RUN_TIME2=0;          
    }
    if(FLAG_RUN2)
    {
        if(((temp1)<(TEMP_SET2-5)))
        {
            CT_STOP_TIME2++;
            CT_RUN_TIME2=0;
            if(CT_STOP_TIME2>=30)
            {
                CT_STOP_TIME2=31;
                FLAG_STOP_RUN2 = 1;
            }
        }
        else
        {
            CT_STOP_TIME2=0;
        }
    }
    else
    {
//        CT_STOP_TIME=0;
//        CT_RUN_TIME2=0;    
    }
    ////////////////////第三组//////////////////
    if(((temp1)>(TEMP_SET3)))
    {
        CT_RUN_TIME3++;
        CT_STOP_TIME3=0;
        if(CT_RUN_TIME3>=30)
        {
            CT_RUN_TIME3=31;
            FLAG_RUN3=1;
            if(!FLAG_STOP_RUN3_1)
            FLAG_STOP_RUN3 = 0;
        }
    }
    else
    {
        CT_RUN_TIME3=0;          
    }
    if(FLAG_RUN3)
    {
        if(((temp1)<(TEMP_SET3-5)))
        {
            CT_STOP_TIME3++;
            CT_RUN_TIME3=0;
            if(CT_STOP_TIME3>=30)
            {
                CT_STOP_TIME3=31;
                FLAG_STOP_RUN3 = 1;
            }
        }
        else
        {
            CT_STOP_TIME3=0;
        }
    }
    else
    {
//        CT_STOP_TIME=0;
//        CT_RUN_TIME3=0;    
    }    
    ///////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////
    if(FLAG_STOP)
    {
        FAN1_current = 0;
        ad_value_FAN1 = 0;        
        FAN2_current = 0;
        ad_value_FAN2 = 0;        
        FAN3_current = 0;
        ad_value_FAN3 = 0;        
        FAN4_current = 0;
        ad_value_FAN4 = 0;        
        FAN5_current = 0;
        ad_value_FAN5 = 0;        
        FAN6_current = 0;
        ad_value_FAN6 = 0;    
        FLAG_TEST_YES1=0; 
        FLAG_TEST_YES2=0; 
        FLAG_TEST_YES3=0; 
    }
    else if(FLAG_FORCE)
    {
    if(FLAG_F1_RUN)
    {
        //ADCC_DischargeSampleCapacitor();
//            ADRESH = 0x00;ADRESL = 0x00; 
//        ad_value_FAN1=0;
//        FAN1_current=0;
//        delay(10);
//        ad_value_FAN1 = ADC_GetConversion(F1_AD);
ad_value_FAN1=filter(ad_value_FAN11,F1_AD);        
        FAN1_current = (ad_value_FAN1*375>>11);
        if(FAN1_current>=300)
        {
            F1_OVERLOAD_TIME++;
            F1_DOWNLOAD_TIME=0;
            if(F1_OVERLOAD_TIME>=10)
            {
                FLAG_F1_OVERLODE = 1;
                F1_OVERLOAD_TIME=15;
            }
        }
        else if(FAN1_current<=8)
        {
            F1_DOWNLOAD_TIME++;
            F1_OVERLOAD_TIME=0;
            if(F1_DOWNLOAD_TIME>=10)
            {
                FLAG_F1_BREAK = 1;
                F1_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F1_DOWNLOAD_TIME=0;
            F1_OVERLOAD_TIME=0;
//            FLAG_F1_BREAK = 0;
//            FLAG_F1_OVERLODE = 0;
        }
    }
    else
    {
        FAN1_current = 0;
        ad_value_FAN1 = 0;
    }
/******************************************************/    
    if(FLAG_F2_RUN)
    {
//            ADRESH = 0x00;ADRESL = 0x00;         
//        ad_value_FAN2=0;
//        FAN2_current=0;
//        delay(10);
//        ad_value_FAN2 = ADC_GetConversion(F2_AD);
        ad_value_FAN2=filter(ad_value_FAN21,F2_AD);  
        FAN2_current = (ad_value_FAN2*375>>11);
        if(FAN2_current>=300)
        {
            F2_OVERLOAD_TIME++;
            F2_DOWNLOAD_TIME=0;
            if(F2_OVERLOAD_TIME>=10)
            {
                FLAG_F2_OVERLODE = 1;
                F2_OVERLOAD_TIME=15;
            }
        }
        else if(FAN2_current<=8)
        {
            F2_DOWNLOAD_TIME++;
            F2_OVERLOAD_TIME=0;
            if(F2_DOWNLOAD_TIME>=10)
            {
                FLAG_F2_BREAK = 1;
                F2_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F2_DOWNLOAD_TIME=0;
            F2_OVERLOAD_TIME=0;
        }        
    }
    else
    {
        FAN2_current = 0;
        ad_value_FAN2 = 0;
    }    
/******************************************************/
    if(FLAG_F3_RUN)
    {
//            ADRESH = 0x00;ADRESL = 0x00;         
//        ad_value_FAN3=0;
//        FAN3_current=0;
//        delay(10);
//        ad_value_FAN3 = ADC_GetConversion(F3_AD);
        ad_value_FAN3=filter(ad_value_FAN31,F3_AD);  
        FAN3_current = (ad_value_FAN3*375>>11);
        if(FAN3_current>=300)
        {
            F3_OVERLOAD_TIME++;
            F3_DOWNLOAD_TIME=0;
            if(F3_OVERLOAD_TIME>=10)
            {
                FLAG_F3_OVERLODE = 1;
                F3_OVERLOAD_TIME=15;
            }
        }
        else if(FAN3_current<=8)
        {
            F3_DOWNLOAD_TIME++;
            F3_OVERLOAD_TIME=0;
            if(F3_DOWNLOAD_TIME>=10)
            {
                FLAG_F3_BREAK = 1;
                F3_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F3_DOWNLOAD_TIME=0;
            F3_OVERLOAD_TIME=0;
        }        
    }
    else
    {
        FAN3_current = 0;
        ad_value_FAN3 = 0;
    }    
/******************************************************/   
    if(FLAG_F4_RUN)
    {
//            ADRESH = 0x00;ADRESL = 0x00;         
//        ad_value_FAN4=0;
//        FAN4_current=0;
//        delay(10);
//        ad_value_FAN4 = ADC_GetConversion(F4_AD);
        ad_value_FAN4=filter(ad_value_FAN41,F4_AD);  
        FAN4_current = (ad_value_FAN4*375>>11);
        if(FAN4_current>=300)
        {
            F4_OVERLOAD_TIME++;
            F4_DOWNLOAD_TIME=0;
            if(F4_OVERLOAD_TIME>=10)
            {
                FLAG_F4_OVERLODE = 1;
                F4_OVERLOAD_TIME=15;
            }
        }
        else if(FAN4_current<=8)
        {
            F4_DOWNLOAD_TIME++;
            F4_OVERLOAD_TIME=0;
            if(F4_DOWNLOAD_TIME>=10)
            {
                FLAG_F4_BREAK = 1;
                F4_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F4_DOWNLOAD_TIME=0;
            F4_OVERLOAD_TIME=0;
        }        
    }
    else
    {
        FAN4_current = 0;
        ad_value_FAN4 = 0;
    }    
/******************************************************/    
    if(FLAG_F5_RUN)
    {
//            ADRESH = 0x00;ADRESL = 0x00;         
//        ad_value_FAN5=0;
//        FAN5_current=0;
//        delay(10);
//        ad_value_FAN5 = ADC_GetConversion(F5_AD);
       ad_value_FAN5 = filter(ad_value_FAN51,F5_AD);  
        FAN5_current = (ad_value_FAN5*375>>11);
        if(FAN5_current>=300)
        {
            F5_OVERLOAD_TIME++;
            F5_DOWNLOAD_TIME=0;
            if(F5_OVERLOAD_TIME>=10)
            {
                FLAG_F5_OVERLODE = 1;
                F5_OVERLOAD_TIME=15;
            }
        }
        else if(FAN5_current<=8)
        {
            F5_DOWNLOAD_TIME++;
            F5_OVERLOAD_TIME=0;
            if(F5_DOWNLOAD_TIME>=10)
            {
                FLAG_F5_BREAK = 1;
                F5_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F5_DOWNLOAD_TIME=0;
            F5_OVERLOAD_TIME=0;
        }        
    }
    else
    {
        FAN5_current = 0;
        ad_value_FAN5 = 0;
    }    
/******************************************************/    
    if(FLAG_F6_RUN)
    {
//            ADRESH = 0x00;ADRESL = 0x00;         
//        ad_value_FAN6=0;
//        FAN6_current=0;
//        delay(10);
//        ad_value_FAN6 = ADC_GetConversion(F6_AD);
        ad_value_FAN6=filter(ad_value_FAN61,F6_AD);  
        FAN6_current = (ad_value_FAN6*375>>11);
        if(FAN6_current>=300)
        {
            F6_OVERLOAD_TIME++;
            F6_DOWNLOAD_TIME=0;
            if(F6_OVERLOAD_TIME>=10)
            {
                FLAG_F6_OVERLODE = 1;
                F6_OVERLOAD_TIME=15;
            }
        }
        else if(FAN6_current<=8)
        {
            F6_DOWNLOAD_TIME++;
            F6_OVERLOAD_TIME=0;
            if(F6_DOWNLOAD_TIME>=10)
            {
                FLAG_F6_BREAK = 1;
                F6_DOWNLOAD_TIME=15;
            }            
        }
        else
        {
            F6_DOWNLOAD_TIME=0;
            F6_OVERLOAD_TIME=0;
        }        
    }
    else
    {
        FAN6_current = 0;
        ad_value_FAN6 = 0;
    }    
/******************************************************/      
    }
    else
    {    
    if(FLAG_TEST_YES1)
    {
    /******************************************************/       
        if(FLAG_F1_RUN)
        {
            ad_value_FAN1=filter(ad_value_FAN11,F1_AD); 
            FAN1_current = (ad_value_FAN1*375>>11);
            if(FAN1_current>=300)
            {
                F1_OVERLOAD_TIME++;
                F1_DOWNLOAD_TIME=0;
                if(F1_OVERLOAD_TIME>=10)
                {
                    FLAG_F1_OVERLODE = 1;
                    F1_OVERLOAD_TIME=15;
                }
            }
            else if(FAN1_current<=8)
            {
                F1_DOWNLOAD_TIME++;
                F1_OVERLOAD_TIME=0;
                if(F1_DOWNLOAD_TIME>=10)
                {
                    FLAG_F1_BREAK = 1;
                    F1_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F1_DOWNLOAD_TIME=0;
                F1_OVERLOAD_TIME=0;
            }
        }
        else
        {
            FAN1_current = 0;
            ad_value_FAN1 = 0;
        }
    /******************************************************/    
        if(FLAG_F2_RUN)
        {
            ad_value_FAN2=filter(ad_value_FAN21,F2_AD); 
            FAN2_current = (ad_value_FAN2*375>>11);
            if(FAN2_current>=300)
            {
                F2_OVERLOAD_TIME++;
                F2_DOWNLOAD_TIME=0;
                if(F2_OVERLOAD_TIME>=10)
                {
                    FLAG_F2_OVERLODE = 1;
                    F2_OVERLOAD_TIME=15;
                }
            }
            else if(FAN2_current<=8)
            {
                F2_DOWNLOAD_TIME++;
                F2_OVERLOAD_TIME=0;
                if(F2_DOWNLOAD_TIME>=10)
                {
                    FLAG_F2_BREAK = 1;
                    F2_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F2_DOWNLOAD_TIME=0;
                F2_OVERLOAD_TIME=0;
            }        
        }
        else
        {
            FAN2_current = 0;
            ad_value_FAN2 = 0;
        }    
    }
    else
    {
        FAN1_current = 0;
        ad_value_FAN1 = 0;        
        FAN2_current = 0;
        ad_value_FAN2 = 0;         
    }
    if(FLAG_TEST_YES2)
    {
    /******************************************************/
        if(FLAG_F3_RUN)
        {
            ad_value_FAN3=filter(ad_value_FAN31,F3_AD); 
            FAN3_current = (ad_value_FAN3*375>>11);
            if(FAN3_current>=300)
            {
                F3_OVERLOAD_TIME++;
                F3_DOWNLOAD_TIME=0;
                if(F3_OVERLOAD_TIME>=10)
                {
                    FLAG_F3_OVERLODE = 1;
                    F3_OVERLOAD_TIME=15;
                }
            }
            else if(FAN3_current<=8)
            {
                F3_DOWNLOAD_TIME++;
                F3_OVERLOAD_TIME=0;
                if(F3_DOWNLOAD_TIME>=10)
                {
                    FLAG_F3_BREAK = 1;
                    F3_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F3_DOWNLOAD_TIME=0;
                F3_OVERLOAD_TIME=0;
            }        
        }
        else
        {
            FAN3_current = 0;
            ad_value_FAN3 = 0;
        }    
    /******************************************************/   
        if(FLAG_F4_RUN)
        {
            ad_value_FAN4=filter(ad_value_FAN41,F4_AD); 
            FAN4_current = (ad_value_FAN4*375>>11);
            if(FAN4_current>=300)
            {
                F4_OVERLOAD_TIME++;
                F4_DOWNLOAD_TIME=0;
                if(F4_OVERLOAD_TIME>=10)
                {
                    FLAG_F4_OVERLODE = 1;
                    F4_OVERLOAD_TIME=15;
                }
            }
            else if(FAN4_current<=8)
            {
                F4_DOWNLOAD_TIME++;
                F4_OVERLOAD_TIME=0;
                if(F4_DOWNLOAD_TIME>=10)
                {
                    FLAG_F4_BREAK = 1;
                    F4_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F4_DOWNLOAD_TIME=0;
                F4_OVERLOAD_TIME=0;
            }        
        }
        else
        {
            FAN4_current = 0;
            ad_value_FAN4 = 0;
        }    
    }
    else
    {
       
        FAN3_current = 0;
        ad_value_FAN3 = 0;        
        FAN4_current = 0;
        ad_value_FAN4 = 0;        
    }    
    if(FLAG_TEST_YES3)
    {
    /******************************************************/    
        if(FLAG_F5_RUN)
        {
            ad_value_FAN5=filter(ad_value_FAN51,F5_AD); 
            FAN5_current = (ad_value_FAN5*375>>11);
            if(FAN5_current>=300)
            {
                F5_OVERLOAD_TIME++;
                F5_DOWNLOAD_TIME=0;
                if(F5_OVERLOAD_TIME>=10)
                {
                    FLAG_F5_OVERLODE = 1;
                    F5_OVERLOAD_TIME=15;
                }
            }
            else if(FAN5_current<=8)
            {
                F5_DOWNLOAD_TIME++;
                F5_OVERLOAD_TIME=0;
                if(F5_DOWNLOAD_TIME>=10)
                {
                    FLAG_F5_BREAK = 1;
                    F5_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F5_DOWNLOAD_TIME=0;
                F5_OVERLOAD_TIME=0;
            }        
        }
        else
        {
            FAN5_current = 0;
            ad_value_FAN5 = 0;
        }    
    /******************************************************/    
        if(FLAG_F6_RUN)
        {
            ad_value_FAN6=filter(ad_value_FAN61,F6_AD); 
            FAN6_current = (ad_value_FAN6*375>>11);
            if(FAN6_current>=300)
            {
                F6_OVERLOAD_TIME++;
                F6_DOWNLOAD_TIME=0;
                if(F6_OVERLOAD_TIME>=10)
                {
                    FLAG_F6_OVERLODE = 1;
                    F6_OVERLOAD_TIME=15;
                }
            }
            else if(FAN6_current<=8)
            {
                F6_DOWNLOAD_TIME++;
                F6_OVERLOAD_TIME=0;
                if(F6_DOWNLOAD_TIME>=10)
                {
                    FLAG_F6_BREAK = 1;
                    F6_DOWNLOAD_TIME=15;
                }            
            }
            else
            {
                F6_DOWNLOAD_TIME=0;
                F6_OVERLOAD_TIME=0;
            }        
        }
        else
        {
            FAN6_current = 0;
            ad_value_FAN6 = 0;
        }    
    }
    else
    {
        
        FAN5_current = 0;
        ad_value_FAN5 = 0;        
        FAN6_current = 0;
        ad_value_FAN6 = 0;        
    }    
/******************************************************/    
}
    
}