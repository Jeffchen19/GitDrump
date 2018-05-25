
#ifndef EEROP_H
#define EEROP_H

#include "stdint.h"
extern	uint32_t	STARTADDR;

/************************************************* 
�������ƣ�  void EEPROM_Configuration(void)
��Ҫ������  ��ʼ������оƬ			
���룺 	   	NULL
����� 	    NULL
�޸���־�� 	2011-03-22
*************************************************/
void EEPROM_Configuration(void);
/************************************************* 
�������ƣ�  void EEROP_SetSysParm(void *parm)
��Ҫ������  ����ϵͳ����			
���룺 	   	NULL
����� 	    NULL
�޸���־�� 	2011-03-22
*************************************************/
void EEROP_SetSysParm(void *parm);
/************************************************* 
�������ƣ�  void EEROP_GetSysParm(void *parm)
��Ҫ������  ��ȡϵͳ����			
���룺 	   	NULL
����� 	    NULL
�޸���־�� 	2011-03-22
*************************************************/
void EEROP_GetSysParm(void *parm);


void ReadFlashNBtye(uint32_t ReadAddress, uint8_t *ReadBuf, int32_t ReadNum);

void WriteFlashOneWord(uint32_t WriteAddress,uint32_t *buf,uint32_t sum);

#endif
