/*************************************************************************************
 * @�ļ�  : led.c
 * @����  : caochao
 * @����  : 22-9-2017
 * @ժҪ  : ���C�ļ�ʱʵ��led�ĳ�ʼ��
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 *************************************************************************************/
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "led.h"

/*************************************************************************************
 *   ��������LED1_Init(void)
 *   ��  �ܣ�LED1�ܽŵĳ�ʼ��
 *   ��  �룺
 *           ��
 *   ��  ����
 *           ��
 ************************************************************************************/
void LED1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	 
    RCC_AHB1PeriphClockCmd(LED1_PERIPH,ENABLE);         //��GPIOE��ʱ��      
    
    GPIO_InitStructure.GPIO_Pin = LED1_PIN;            //GPIOE.3Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;     
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	
	GPIO_Init(LED1_PORT,&GPIO_InitStructure);
}	

/************************************************************************************
 *   ��������LED2_Init(void)
 *   ��  �ܣ�LED2�ܽŵĳ�ʼ��
 *   ��  �룺
 *           ��
 *   ��  ����
 *           ��
 ***********************************************************************************/
void LED2_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	 
    RCC_AHB1PeriphClockCmd(LED2_PERIPH,ENABLE);         //��GPIOE��ʱ��      
    
    GPIO_InitStructure.GPIO_Pin = LED2_PIN;            //GPIOE.4Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;     
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	
	GPIO_Init(LED2_PORT,&GPIO_InitStructure);
}	

/************************************************************************************
 *   ��������LED3_Init(void)
 *   ��  �ܣ�LED2�ܽŵĳ�ʼ��
 *   ��  �룺
 *           ��
 *   ��  ����
 *           ��
 ***********************************************************************************/
void LED3_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	 
    RCC_AHB1PeriphClockCmd(LED3_PERIPH,ENABLE);         //��GPIOE��ʱ��      
    
    GPIO_InitStructure.GPIO_Pin = LED3_PIN;            //GPIOE.4Ϊ�������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;     
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	
	GPIO_Init(LED3_PORT,&GPIO_InitStructure);
}

/********************************�ļ�����********************************************/


