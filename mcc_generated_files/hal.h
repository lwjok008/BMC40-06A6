#ifndef	_HAL_H_
#define	_HAL_H_


/*液晶屏驱动相关宏定义内容*/
#define	CS0	 	CS_LAT		//片选 低电平有效
#define	DC0		DC_LAT		//数据，为1时数据   为0时指令
#define	WR0		WR_LAT		//读写，为1时读数据  为0时写数据
#define	RD		RD_LAT		//使能信号
#define	RST		RES_LAT
#define	LCD_DB	LATB
#define BACK_LIGHT_CONTROL	BLK_LAT		//背光驱动打开

#define red    0xf800		//定义红色
#define blue   0x001f		//定义蓝色
#define green  0x07e0 	//定义绿色				
#define white  0xffff 		//定义白色	
#define black  0x0000 	//定义黑色	
#define orange 0xfc08 	//定义橙色
#define yellow 0xffe0		//定义黄色
#define pink   0xf3f3 	//定义粉红色
#define purple 0xa1d6	 	//定义紫色
#define brown  0x8200	 //定义棕色
#define gray   0x8410	 	//定义灰色

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#define KEY_UP		KEY_UP_PORT
#define KEY_DOWN	KEY_DOWN_PORT
#define KEY_ENTER	KEY_ENTER_PORT
#define KEY_RETURN	KEY_CANCEL_PORT
#define KEY_RESET	KEY_RESET_PORT

#endif






















