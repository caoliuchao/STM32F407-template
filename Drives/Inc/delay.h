/********************************************************************************
 * @�ļ�  : delay.h
 * @����  : caochao
 * @����  : 9-19-2018
 * @��λ  : �������ӿƼ���ѧ
 * @ժҪ  : ���ͷ�ļ������˸�����ͬ��ʱ�����Ķ���
 *          ʵ�ֲ�ͬ��ʱ����ʱ
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 ********************************************************************************/
/* �����ֹ�ݹ�İ���*/
#ifndef _DELAY_H
#define _DELAY_H

#ifdef __cplusplus /*C���Ա༭ģʽ*/
 extern "C" {
#endif
     
#include "stm32f4xx.h"
   
/*------------------------------��ʱ����������------------------------------------*/
void Delay1ms(uint16_t nms);
void Delay1us(uint32_t nus);
	 
#ifdef __cplusplus
}
#endif

#endif /* _DELAY_H */
/**********************************�ļ�����************************************/
