#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_flash.h"
#include "Flush.h"
#include "stdint.h"

// 修改芯片内部的 Flash
//#define  STARTADDR  0x0800FF00                   	//STM32F103c8t6 一共64k的cpu
//#define  STARTADDR  0x0800EE00                   	//STM32F103c8t6 一共64k的cpu
uint32_t	STARTADDR	=	0x0801F800; 									//STM32F030r8t6 一共64k的cpu 3c00

FLASH_Status FLASHStatus = FLASH_COMPLETE;				//Flash

/****************************************************************
*Name:		ReadFlashNBtye
*Function:	???Flash??N????
*Input:		ReadAddress:????(????)ReadBuf:????	ReadNum:?????
*Output:	       ??????  
*Author:        ValerianFan
*Date:		2014/04/09
*E-Mail:	fanwenjingnihao@163.com
*Other:		
****************************************************************/
void ReadFlashNBtye(uint32_t ReadAddress, uint8_t *ReadBuf, int32_t ReadNum) 
{
	int DataNum = 0;
	ReadAddress = (uint32_t)STARTADDR + ReadAddress; 
	while(DataNum < ReadNum) 
	{
		*(ReadBuf + DataNum) = *(__IO uint8_t*) ReadAddress++;
		DataNum++;
	}
//	return DataNum;
}

/****************************************************************
*Name:		WriteFlashOneWord
*Function:	???Flash??32???
*Input:		WriteAddress:????(????)WriteData:????
*Output:	NULL 
*Author:    ValerianFan
*Date:		2014/04/09
*E-Mail:	fanwenjingnihao@163.com
*Other:		
****************************************************************/
void WriteFlashOneWord(uint32_t WriteAddress,uint32_t *buf,uint32_t sum)
{
 	int i = 0;
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR); 
	FLASHStatus = FLASH_ErasePage(STARTADDR);
	for( i = 0 ; i < sum; i++)
	{
			if(FLASHStatus == FLASH_COMPLETE)
			{
				FLASHStatus = FLASH_ProgramWord(STARTADDR + WriteAddress + i*4, *buf);    //flash.c ?API??
				buf++ ;
			}
	}
	FLASH_Lock();
} 
// 
//int flash_read(u32 StartAddr,u32 *p_data,u32 size)
//{
//	u32 EndAddr= StartAddr + size * 4;
//	int MemoryProgramStatus=1;
//	u32 Address = 0x0;
//	int i=0;
//	Address = StartAddr;
//	while((Address < EndAddr) && (MemoryProgramStatus != 0))
//	{
//		p_data[i++]=(*(vu32*) Address);
//		Address += 4;	
//	}
//	return 0;	
//}

