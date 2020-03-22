/*************************************************************************************
 * @�ļ�  : led.h
 * @����  : caochao
 * @����  : 22-9-2017
 * @ժҪ  : ���h�ļ�ʱ����led�ĸ�������
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 *************************************************************************************/
/* �����ֹ�ݹ�İ��� */
#ifndef _LED_H
#define _LED_H

#ifdef __cplusplus
extern "C"{
#endif
 
/*-----------------------------------------------------------------------------------*/    
#define LED1_PORT     GPIOE
#define LED1_PIN      GPIO_Pin_3
#define LED1_PERIPH   RCC_AHB1Periph_GPIOE	

#define LED2_PORT     GPIOE
#define LED2_PIN      GPIO_Pin_4
#define LED2_PERIPH   RCC_AHB1Periph_GPIOE	
		
#define LED3_PORT     GPIOG
#define LED3_PIN      GPIO_Pin_9
#define LED3_PERIPH   RCC_AHB1Periph_GPIOG			

/*-----------------------------------------------------------------------------------*/
#define LED1_ON       GPIO_SetBits(LED1_PORT,LED1_PIN)
#define LED1_OFF      GPIO_ResetBits(LED1_PORT,LED1_PIN)
    
#define LED2_ON       GPIO_SetBits(LED2_PORT,LED2_PIN)
#define LED2_OFF      GPIO_ResetBits(LED2_PORT,LED2_PIN)

#define LED3_ON       GPIO_SetBits(LED3_PORT,LED3_PIN)
#define LED3_OFF      GPIO_ResetBits(LED3_PORT,LED3_PIN)

/*-----------------------------------------------------------------------------------*/
void LED1_Init(void);
void LED2_Init(void);
void LED3_Init(void);

#ifdef __cplusplus
}
#endif

#endif/*led.h*/
/************************************�ļ�����***************************************/
