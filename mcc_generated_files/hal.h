#ifndef	_HAL_H_
#define	_HAL_H_


/*Һ����������غ궨������*/
#define	CS0	 	CS_LAT		//Ƭѡ �͵�ƽ��Ч
#define	DC0		DC_LAT		//���ݣ�Ϊ1ʱ����   Ϊ0ʱָ��
#define	WR0		WR_LAT		//��д��Ϊ1ʱ������  Ϊ0ʱд����
#define	RD		RD_LAT		//ʹ���ź�
#define	RST		RES_LAT
#define	LCD_DB	LATB
#define BACK_LIGHT_CONTROL	BLK_LAT		//����������

#define red    0xf800		//�����ɫ
#define blue   0x001f		//������ɫ
#define green  0x07e0 	//������ɫ				
#define white  0xffff 		//�����ɫ	
#define black  0x0000 	//�����ɫ	
#define orange 0xfc08 	//�����ɫ
#define yellow 0xffe0		//�����ɫ
#define pink   0xf3f3 	//����ۺ�ɫ
#define purple 0xa1d6	 	//������ɫ
#define brown  0x8200	 //������ɫ
#define gray   0x8410	 	//�����ɫ

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#define KEY_UP		KEY_UP_PORT
#define KEY_DOWN	KEY_DOWN_PORT
#define KEY_ENTER	KEY_ENTER_PORT
#define KEY_RETURN	KEY_CANCEL_PORT
#define KEY_RESET	KEY_RESET_PORT

#endif






















