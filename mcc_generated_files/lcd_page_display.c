#include"mcc.h"
#include "head.h"
#include "font_library.h"

bit FLAG_SET;
/*

page1---���ܵ���ѹ��״̬
page2--��բ�ܴ���
page3--���ܵ����������
page4--24Сʱ��������
page5--����120S����ʱ
page6--���ܳ�ʱ��Ϣ
page7--24Сʱ��������
page8--�������״̬
page9--������е���
page10--��λ����
*/
//////////////////////////////////////////////////////////////////////////////////////////
void lcd_page_display()		
{
    switch(lcd_page)
    {
        case 0:	page0_change(); break;
        case 1:	page1_change(); break;
        case 2:	page2_change(); break;
        case 3:	page3_change(); break;
        case 4:	
//        case 5: page5_change(); break;
//        case 6:	page6_change(); break;
//        case 7:	page7_change(); break;
//        case 8:	page8_change(); break;
//        case 9:	page9_change(); break;   
//        case 10:
        {
            if(!FLAG_SET)
            {
                page4_change(); 
            }
            else
            {
                if((!flag_page4_set1)&&(!flag_page4_set2)&&(!flag_page4_set3)&&(!flag_page4_set4)&&(!flag_page4_set5))
                {
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
        } break; 
    }      
}


void h_bcd(uint x)
{

	qian=x/1000%10;
	bai=x/100%10;
	shi=x/10%10;
	ge=x%10;

}

///*--  ����36;  �������¶�Ӧ�ĵ���Ϊ����x��=24x48   --*/
void disp_num_24x48(uint x,uint y, uchar number,uint font_color,uint back_color)
{
	static uint i,j,k;
	k=0;
	lcd_address(x,y,24,48);
	for(i=0;i<48;i++)		//�߶�21
	{
		for(j=0;j<3;j++)	//��� 2*8=16
		{
			mono_data_out(NUM1[number][k],font_color,back_color);
			k++;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////