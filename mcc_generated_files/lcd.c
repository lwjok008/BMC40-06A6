#include "mcc.h"
#include "head.h"


//传送8位的数据
void data_out(uchar data)
{
	//8080 8bit interface
	CS0 = 0;
	DC0 = 1;
	RD = 1;
	LCD_DB=data;
	//nop;nop;nop;nop;nop;
	WR0 = 0;
	WR0 = 1;
	CS0 = 1;        
}

//传16位数据，16位数据一起赋值
void data_out_16(uint data_16bit)
{
	uchar hdata,ldata;
	hdata=(data_16bit>>8)&0X00FF;
	ldata=data_16bit&0X00FF;
	data_out(hdata);
	data_out(ldata);
}

//传送8位的命令
void comm_out(uchar com)
{
	//8080 8bit interface
	DC0 = 0;
	CS0 = 0;  
	RD = 1;
	LCD_DB=com;	//nop;nop;nop;nop;nop;
	WR0 = 0;
	WR0 = 1;
	CS0 = 1;
}


void disp_ASCII_8x16(uint x,uint y, const uchar number,uint font_color,uint back_color)
{
	uint i1,j,k;
	k=0;
	lcd_address(x,y,8,16);
	for(i1=0;i1<16;i1++)		//高度16
	{
		for(j=0;j<1;j++)	//宽度 8
		{
			mono_data_out(table_asc[number][k],font_color,back_color);
			k++;
		}
	}
}
void disp_24x24(uint x,uint y,uchar *dp,uint font_color,uint back_color)
{
	uint i1,j;
	lcd_address(x,y,24,24);
	for(i1=0;i1<24;i1++)		//高度21
	{
		for(j=0;j<3;j++)	//宽度 2*8=16
		{
			mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}
void disp_16x16(uint x,uint y,const uchar *dp,uint font_color,uint back_color)
{
	uint i1,j;
	lcd_address(x,y,16,16);
	for(i1=0;i1<16;i1++)		//高度21
	{
		for(j=0;j<2;j++)	//宽度 2*8=16
		{
			mono_data_out(*dp,font_color,back_color);
			dp++;
		}
	}
}

//将单色的8位的数据（代表8个像素点）转换成彩色的数据传输给液晶屏
void mono_data_out(uchar mono_data,uint font_color,uint back_color)
{
	uint k;
	for(k=0;k<8;k++)
	{
	 	if(mono_data&0x80)
		{
			data_out_16(font_color);	//当数据是1时，显示字体颜色
		}
		else
		{
			data_out_16(back_color);	//当数据是0时，显示底色
		}

		mono_data<<=1;
	}
}

/*
//将单色的8位的数据的高5位（代表5个像素点）转换成彩色的数据传输给液晶屏
void mono_data_out_5x8(uchar mono_data,uint font_color,uint back_color)
{
	uint k;
	for(k=0;k<6;k++)				 	//显示6列，因为5x8点阵的字中间最好是隔1列，美观一点
	{
	 	if(mono_data&0x80)
		{
			data_out_16(font_color);	//当数据是1时，显示字体颜色
		}
		else
		{
			data_out_16(back_color);	//当数据是0时，显示底色
		}

		mono_data<<=1;
	}
}
*/

//定义窗口坐标：开始坐标（XS,YS)以及窗口大小（x_total,y_total)
void lcd_address(uint XS,uint YS,uint x_total,uint y_total)
{
	uint XE,YE; 
	XE=XS+x_total-1;
	YE=YS+y_total-1;	
	comm_out(0x2a);		// 设置X开始及结束的地址
	data_out_16(XS);	// X开始地址(16位）
	data_out_16(XE);	// X结束地址(16位）
			
	comm_out(0x2b);		// 设置Y开始及结束的地址
	data_out_16(YS);	// Y开始地址(16位）
	data_out_16(YE);	// Y结束地址(16位）

	comm_out(0x2c);	    // 写数据开始
}

//定义单个像素点的坐标（x,y）
void LCD_SetPos(uint x,uint y)
{
	comm_out(0x2a);		// 设置X开始及结束的地址
	data_out_16(x);		// X开始地址(16位）
	data_out_16(x+1);	// X结束地址(16位）

	comm_out(0x2b);		// 设置Y开始及结束的地址
	data_out_16(y);		// Y开始地址(16位）
	data_out_16(y+1);	// Y结束地址(16位）

	comm_out(0x2c);	    // 写数据开始
}



//显示全屏单一色彩
void display_color(uint color)
{  
	uint i1,j;
	
	lcd_address(0,0,160,128);
	for(i1=0;i1<128;i1++)
	{
		for(j=0;j<160;j++)
		{
			data_out_16(color);
		}
	}
	
	/*竖屏显示
	lcd_address(0,0,128,160);
	for(i1=0;i1<160;i1++)
	{
		for(j=0;j<128;j++)
		{
			data_out_16(color);
		}
	}
	*/
}

//整行显示单一色彩
void line_display_color(uchar y_start, uchar y_end, uint color)  //y_start--起始行  y_end--结束行
{  
	uint i1,j;
	
	lcd_address(0,y_start,160,y_end);
	for(i1=0;i1<(y_end-y_start);i1++)
	{
		for(j=0;j<160;j++)
		{
			data_out_16(color);
		}
	}
	
	/*竖屏显示
	lcd_address(0,0,128,160);
	for(i1=0;i1<160;i1++)
	{
		for(j=0;j<128;j++)
		{
			data_out_16(color);
		}
	}
	*/
}


void lcd_init(void)
{
	delay(20);
	RST=0;				//低电平：复位
	delay(20);
	RST=1;				//高电平：复位结束
	delay(10);
	
	//开始初始化：
    comm_out(0x11);      
    
    comm_out(0x26);
    data_out(0x04);	//设置GAMMA参数
    
   	comm_out(0x36);   //行扫描顺序，列扫描顺序，横放/竖放 
    data_out(0xa8); 	//设置：RAM写入方向从左向右、从上到下、数据顺序BGR
                        
    comm_out(0xb1);   //设置fr=61.7hz
    data_out(0x0e);
    data_out(0x14);
    //data_out(0x2d);
    
    comm_out(0x3a);    
    data_out(0x05);		//数据格式16bit
    
    comm_out(0x29);		//开显示
}
//画点函数
void draw_point(uint x, uint y, uint color)
{
	LCD_SetPos(x,y);
	data_out_16(color);	
}

//----------------------------------------
// 画线函数 （算法）
//----------------------------------------
void vDraw_Line(uint x1,uint y1,uint x2,uint y2,uint Fg_Color)
// (x1,y1),(x2,y2)：直线起始和终止位置坐标，以像素点为单位
{
  uint temp;
  int dalt_x,dalt_y,err=0;
  if (y1>y2)                  //要求Y1<Y2，如果不符合要求，则两坐标置换
    {
    temp=x1;
    x1=x2;
    x2=temp;
    temp=y1;
    y1=y2;
    y2=temp;
    }
  draw_point(x1,y1,Fg_Color);             // 画起始点
  dalt_x=x2-x1;                //ΔX=X2-X1
  dalt_y=y2-y1;                //ΔY=Y2-Y1
  if(dalt_x>=0)
     {
      if(dalt_y>dalt_x)        //k=ΔY/ΔX >1时C
      
        {
         while(y1<y2)
         {
          if(err<0)
          {
           x1=x1+1;
           y1=y1+1;
           err=err+dalt_y-dalt_x;
           }
           else
           {
           y1=y1+1;
           err=err-dalt_x;
           }
          draw_point(x1,y1,Fg_Color);     // 画点
         }
       }
     else                      //0<k=ΔY/ΔX=<1
      {
       if (dalt_y==0)
          y1=y1-1;
       while(x1<x2)
         {
          if(err<0)
          {
           x1=x1+1;
           err=err+dalt_y;
           }
           else
           {
           y1=y1+1;
           x1=x1+1;
           err=err+dalt_y-dalt_x;
           }
          draw_point(x1,y1,Fg_Color);     //画点
         }
     }
     
    }
  else
   {
   dalt_x=x1-x2;  
   if(dalt_y>dalt_x)          //k=ΔY/ΔX<-1
     {
      while(y1<y2)
       {
        if(err<0)
         {
          x1=x1-1;
          y1=y1+1;
          err=err+dalt_y-dalt_x;
         }
        else
         {
          y1=y1+1;
          err=err-dalt_x;
         }
        draw_point(x1,y1,Fg_Color);      //画点
      }
    }
   else                       //0>k=ΔY/ΔX>=-1
    {
      if (dalt_y==0)
          y1=y1-1; 
    while(x1>x2)
      {
       if(err<0)
        {
         x1=x1-1;
         err=err+dalt_y;
        }
       else
        {
         x1=x1-1;
         y1=y1+1;
         err=err+dalt_y-dalt_x;
        }
       draw_point(x1,y1,Fg_Color);
      }
    } 
  }
     
}
/*--------------------------------------------------------------------------------------
-函数名称:void TFT_Disp128160(uchar *dat)
----------------------------------------------------------------------------------------
-函数功能:显示128*160大小图片
-入口参数:水平扫高位在前160*128bmp
-出口参数:无
---------------------------------------------------------------------------------------*/
void TFT_Disp128160(const uchar *dat)
{
    int i1,j;
//	横屏显示
	lcd_address(0,0,160,128);
	for(i1=0;i1<128;i1++)
	{
		for(j=0;j<160;j++)
		{
		 data_out(*dat++);
		 data_out(*dat++);
		}
	}
//	//竖屏显示
//	lcd_address(0,0,128,160);
//	for(i1=0;i1<160;i1++)
//	{
//		for(j=0;j<128;j++)
//		{
//		 data_out(*dat++);
//		 data_out(*dat++);
//		}
//	}
}

