#ifndef	_HEAD_H
#define	_HEAD_H

#define	uint 	unsigned int
#define  uchar 	unsigned char
#define 	ulong 	unsigned long

#define clrwdt		asm("clrwdt")
#define	nop		asm("nop")


#include "hal.h"
#include <xc.h>
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>

#include	"function.h"
//#include "const.h"
#include "var.h"
#include "stdint.h"
#include "font_library.h"

//#define CON_485II_RX()    do { LATC3 = 1; } while(0)
//#define CON_485II_TX()   do { LATC3 = 0; } while(0)

extern uchar lcd_page;
extern bit FLAG_SET;
extern uchar addr;
extern void FAN_CURRENT_COLLECT(void);
extern bool EUSART2_is_tx_done(void);
extern void crc_check(uchar *ptr,uchar len);
extern unsigned char CRC_LOW, CRC_HIG; 
extern bit flag_ook1,flag_ok1;
extern uint8_t TX_LEN1,RX_LEN1;
extern volatile uint8_t eusart2RxHead;

extern volatile uint8_t eusart2RxCount;

extern volatile uint8_t eusart2RxBuffer[8];
extern uchar temp1;
//extern bit flag_TIMEA_NG,flag_TIMEB_NG,flag_TIMEC_NG;

//extern bit flag_COUNTA_NG_disp,flag_COUNTB_NG_disp,flag_COUNTC_NG_disp;


extern bit flag_page4_set1,flag_page4_set2,flag_page4_set3,flag_page4_set4,flag_page4_set5;

extern bit flag_page4_set2_switch;

extern bit FLAG_F1_ON,FLAG_F2_ON,FLAG_F3_ON,FLAG_F4_ON,FLAG_F5_ON,FLAG_F6_ON;

extern bit FLAG_TEST_YES,FLAG_TEST_YES1,FLAG_TEST_YES2,FLAG_TEST_YES3;
extern bit FLAG_RUN1,FLAG_STOP_RUN1;
extern bit FLAG_RUN2,FLAG_STOP_RUN2;
extern bit FLAG_RUN3,FLAG_STOP_RUN3;
extern uchar set_set1,set;
extern uchar start_current,keep_time;
extern uchar TEMP_SET1,TEMP_SET2,TEMP_SET3;
extern bit flag_minus_t1,flag_t1_err;
extern uchar CT_CURRENT;
extern bit FLAG_F1_RUN,FLAG_F2_RUN,FLAG_F3_RUN,FLAG_F4_RUN,FLAG_F5_RUN,FLAG_F6_RUN;
extern bit FLAG_F1_OVERLODE,FLAG_F2_OVERLODE,FLAG_F3_OVERLODE,FLAG_F4_OVERLODE,FLAG_F5_OVERLODE,FLAG_F6_OVERLODE;
extern bit FLAG_F1_BREAK,FLAG_F2_BREAK,FLAG_F3_BREAK,FLAG_F4_BREAK,FLAG_F5_BREAK,FLAG_F6_BREAK;
extern uint FAN1_current,FAN2_current,FAN3_current,FAN4_current,FAN5_current,FAN6_current,CT_current_ad;
extern bit FLAG_AUTO,FLAG_STOP,FLAG_FORCE,FLAG_RST;
extern uint RUN_CT_time,STOP_CT_time;
extern uint KEEP_FAN_RUN_TIME_1s_disp,KEEP_FAN_RUN_TIME_1min_disp;
extern uint KEEP_FAN_RUN_TIME_1s_disp1,KEEP_FAN_RUN_TIME_1min_disp1;
extern uint KEEP_FAN_RUN_TIME_1s_disp2,KEEP_FAN_RUN_TIME_1min_disp2;
extern uint KEEP_FAN_RUN_TIME_1s_disp3,KEEP_FAN_RUN_TIME_1min_disp3;
extern uchar FAN_ONOFF_BYTE;
typedef union 
{
	uchar Byte;
	struct 
	{
    	unsigned  BIT0:1; 
        unsigned  BIT1:1; 
        unsigned  BIT2:1; 
        unsigned  BIT3:1; 
        unsigned  BIT4:1; 
        unsigned  BIT5:1; 
        unsigned  BIT6:1; 
        unsigned  BIT7:1; 
    } Bits;
}BYTE_BITS;
#endif













