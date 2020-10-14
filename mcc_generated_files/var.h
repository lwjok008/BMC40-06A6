#ifndef _VAR_H
#define	_VAR_H

extern uint i,num,refresh_time;



extern uchar qian, bai, shi, ge;

extern uchar hours;

extern uchar rx_buff[8];
extern uchar tx_buff[19];
extern uchar TX_BUFF[30];
extern uchar test_buff[5];

extern 	uchar rx_count;
extern	uchar tx_count;

extern  uchar bytes_send;
extern	uchar *ptr;
//extern  uchar RUN1,RUN2,RUN3;
//typedef union 
//{
//	struct
//	{
//		unsigned lcd_on:		1;
//		unsigned relay_out:	1;
//		unsigned l1_subzero:	1;
//		unsigned l2_subzero:	1;
//		unsigned l3_subzero:	1;
//		unsigned subzero:	1;
//		unsigned :2;
//	}Bits;
//	unsigned char Byte;
//}STATE_FLAG;
//
//extern	STATE_FLAG flag1;
//
//#define flag_lcd_on			flag1.Bits.lcd_on
//#define flag_relay_out			flag1.Bits.relay_out
//#define flag_l1_subzero		flag1.Bits.l1_subzero
//#define flag_l2_subzero		flag1.Bits.l2_subzero
//#define flag_l3_subzero		flag1.Bits.l3_subzero
//#define flag_subzero			flag1.Bits.l3_subzero		//用于数据处理过程中传递值
//
//typedef union 
//{
//	struct
//	{
//		unsigned l1_i_err:		1;
//		unsigned l1_t_err:		1;	
//		unsigned l2_i_err:		1;
//		unsigned l2_t_err:		1;
//		unsigned l3_i_err:		1;
//		unsigned l3_t_err:		1;
//		unsigned g_i_err:		1;
//		unsigned :1;
//	}Bits;
//	unsigned char Byte;
//}ALARM_FLAG;
//
//extern	ALARM_FLAG flag2;
//
//#define flag_l1_i_err			flag2.Bits.l1_i_err
//#define flag_l1_t_err			flag2.Bits.l1_t_err
//#define flag_l2_i_err			flag2.Bits.l2_i_err
//#define flag_l2_t_err			flag2.Bits.l2_t_err
//#define flag_l3_i_err			flag2.Bits.l3_i_err
//#define flag_l3_t_err			flag2.Bits.l3_t_err
//#define flag_g_i_err			flag2.Bits.g_i_err
//
//
//typedef union 
//{
//	struct
//	{
//		unsigned rx_start:		1;
//		unsigned tx_start:		1;	
//		unsigned rx_end:			1;
//		unsigned tx_end:			1;
//		unsigned remote_reset:	1;
//		unsigned : 3;
//	}Bits;
//	unsigned char Byte;
//}USART_FLAG;
//
//extern	USART_FLAG flag3;
//
//#define flag_rx_start			flag3.Bits.rx_start
//#define flag_tx_start			flag3.Bits.tx_start
//#define flag_rx_end			flag3.Bits.rx_end
//#define flag_tx_end			flag3.Bits.tx_end
//#define flag_remote_reset		flag3.Bits.remote_reset
//
//
//typedef union 
//{
//	struct
//	{
//		unsigned l1_break:		1;
//		unsigned l2_break:		1;	
//		unsigned l3_break:		1;
//		unsigned g_break:		1;
//		unsigned l1_reset_err:	1;
//		unsigned l2_reset_err:	1;
//		unsigned l3_reset_err:	1;
//		unsigned g_reset_err:	1;
//		
//	}Bits;
//	unsigned char Byte;
//}BREAK_FLAG;
//
//extern	BREAK_FLAG flag4;
//
//#define flag_l1_break			flag4.Bits.l1_break
//#define flag_l2_break			flag4.Bits.l2_break
//#define flag_l3_break			flag4.Bits.l3_break
//#define flag_g_break			flag4.Bits.g_break
//
//#define flag_l1_reset_err		flag4.Bits.l1_reset_err
//#define flag_l2_reset_err		flag4.Bits.l2_reset_err
//#define flag_l3_reset_err		flag4.Bits.l3_reset_err
//#define flag_g_reset_err		flag4.Bits.g_reset_err

#endif









