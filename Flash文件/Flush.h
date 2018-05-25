
#ifndef EEROP_H
#define EEROP_H

#include "stdint.h"
extern	uint32_t	STARTADDR;

/************************************************* 
函数名称：  void EEPROM_Configuration(void)
简要描述：  初始化储存芯片			
输入： 	   	NULL
输出： 	    NULL
修改日志： 	2011-03-22
*************************************************/
void EEPROM_Configuration(void);
/************************************************* 
函数名称：  void EEROP_SetSysParm(void *parm)
简要描述：  储存系统参数			
输入： 	   	NULL
输出： 	    NULL
修改日志： 	2011-03-22
*************************************************/
void EEROP_SetSysParm(void *parm);
/************************************************* 
函数名称：  void EEROP_GetSysParm(void *parm)
简要描述：  读取系统参数			
输入： 	   	NULL
输出： 	    NULL
修改日志： 	2011-03-22
*************************************************/
void EEROP_GetSysParm(void *parm);


void ReadFlashNBtye(uint32_t ReadAddress, uint8_t *ReadBuf, int32_t ReadNum);

void WriteFlashOneWord(uint32_t WriteAddress,uint32_t *buf,uint32_t sum);

#endif
