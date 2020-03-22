/********************************************************************************
 * @�汾  ��V1.0
 * @�ļ�  : sys.c
 * @����  : caochao
 * @����  : 9-19-2018
 * @��λ  : �������ӿƼ���ѧ
 * @ժҪ  : ���C�ļ�systick���õ�ʵ��
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 ********************************************************************************/
#include "stm32f4xx.h"
#include "os_cfg_app.h"

/*-----------------------------------------------------------------------*/
#define  DELAY_GLOBALS
#include "sys.h"
/*
 **************************************************************************************
 *  ��������Systick_Init(void)
 *  ��  �ܣ����õδ�ʱ��
 *  ��  �룺
 *         ��
 *  ��  ����
 *         ��
 **************************************************************************************
 */
void Systick_Init(void)
{ 
#if SYSTEM_SUPPORT_OS	//���SYSTEM_SUPPORT_OS��Ϊ�� ��˵��ʹ��ucosII��.	
    uint32_t reload;    
#endif  
    
    SysTick->CTRL &= SysTick_CLKSource_HCLK_Div8; //ѡ���ⲿʱ��  HCLK/8
    fac_us = SystemCoreClock/8000000; //Systick�δ�1us�ļ�������
    
#if SYSTEM_SUPPORT_OS  //���SYSTEM_SUPPORT_OS��Ϊ�� ��˵��ʹ��ucosIII��.
    reload = fac_us * 1000000/OS_CFG_TICK_RATE_HZ;  //����OS_CFG_TICK_RATE_HZ �趨���ʱ��
							            //reloadΪ24λ�Ĵ���,���ֵ:16777216,��72M��,Լ��1.86s����	
    fac_ms = 1000/OS_CFG_TICK_RATE_HZ;  //����ucos������ʱ�����ٵ�λ	
    
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;   	//����SYSTICK�ж�
    SysTick->LOAD = reload - 1; 	  //ÿ1/OS_TICKS_PER_SEC���ж�һ��	
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;   	//����SYSTICK    
#else 
	fac_ms = (uint16_t)fac_us*1000; //��ucos��,����ÿ��ms��Ҫ��systickʱ����
#endif     
    
}

/**********************************�ļ�����**************************************/


