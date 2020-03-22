/*************************************************************************************
 * @�ļ�  : key.c
 * @����  : caochao
 * @����  : 22-9-2017
 * @ժҪ  : ���C�ļ�ʱʵ�ְ����Լ��жϵĳ�ʼ��
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 *************************************************************************************/
#include "misc.h"
#include "stm32f4xx.h"
#include "key.h"

/************************************************************************************
*   ��������KEY1_Init(void)
*   ��  �ܣ����ð���key1��I/O�Ĺ���
*   ��  �룺
*          ��
*   ��  ����
*          ��
************************************************************************************/
void KEY1_Init(void)
{
    GPIO_InitTypeDef   GPIO_InitStructure;
    EXTI_InitTypeDef   EXTI_InitStructure;
    NVIC_InitTypeDef   NVIC_InitStructure;
    
    /*�򿪰�����GPIOʱ��*/
    RCC_AHB1PeriphClockCmd(KEY1_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*��ʼ��GPIO����*/
    GPIO_Init(KEY1_PORT,&GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY1_EXTI_PORT,KEY1_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY1_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //�½��ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*��ʼ���ж�ģʽ*/
    EXTI_Init(& EXTI_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY1_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;  //�����ȼ�Ϊ0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
    /*��ʼ���ж����ȼ�*/
    NVIC_Init(&NVIC_InitStructure);
}

/***********************************************************************************
 *   ��������KEY2_Init(void)
 *   ��  �ܣ����ð���key2��I/O�Ĺ���
 *   ��  �룺
 *          ��
 *   ��  ����
 *          ��
 **********************************************************************************/
void KEY2_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef  EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    /*�򿪰�����GPIOʱ��*/
    RCC_AHB1PeriphClockCmd(KEY2_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*��ʼ��GPIO����*/
    GPIO_Init(KEY2_PORT,&GPIO_InitStructure);  

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY2_EXTI_PORT,KEY2_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY2_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;    //�½��ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*��ʼ���ж�ģʽ*/
    EXTI_Init(&EXTI_InitStructure);   

    NVIC_InitStructure.NVIC_IRQChannel = KEY2_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;   //��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;  //�����ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /*��ʼ���ж����ȼ�*/
    NVIC_Init(&NVIC_InitStructure);
}

/***********************************************************************************
 *   ��������KEY3_Init(void)
 *   ��  �ܣ����ð���key3��I/O�Ĺ���
 *   ��  �룺
 *          ��
 *   ��  ����
 *          ��
 **********************************************************************************/
void KEY3_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef   EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    /*�򿪰�����GPIOʱ��*/
    RCC_AHB1PeriphClockCmd(KEY3_CLK,ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = KEY3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*��ʼ��GPIO����*/
    GPIO_Init(KEY3_PORT,&GPIO_InitStructure); 
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY3_EXTI_PORT,KEY3_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY3_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;   //�½��ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*��ʼ���ж�ģʽ*/
    EXTI_Init(&EXTI_InitStructure); 
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY3_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;    //�����ȼ�Ϊ2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    
    /*��ʼ���ж����ȼ�*/
    NVIC_Init(&NVIC_InitStructure);
}

/**********************************************************************************
 *   ��������KEY4_Init(void)
 *   ��  �ܣ����ð���key4��I/O�Ĺ���
 *   ��  �룺
 *          ��
 *   ��  ����
 *          ��
 ********************************************************************************/
void KEY4_Init(void)   
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    EXTI_InitTypeDef  EXTI_InitStructure;
    NVIC_InitTypeDef  NVIC_InitStructure;
    
    RCC_AHB1PeriphClockCmd(KEY4_CLK,ENABLE);
    /*�򿪰�����GPIOʱ��*/
    GPIO_InitStructure.GPIO_Pin = KEY4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
    /*��ʼ��GPIO����*/
    GPIO_Init(KEY4_PORT,&GPIO_InitStructure);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    SYSCFG_EXTILineConfig(KEY4_EXTI_PORT,KEY4_EXTI_PIN);
    
    EXTI_InitStructure.EXTI_Line = KEY4_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;     //�½��ش���
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    /*��ʼ���ж�ģʽ*/
    EXTI_Init(&EXTI_InitStructure); 
    
    NVIC_InitStructure.NVIC_IRQChannel = KEY4_NVIC_IRQ ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;  //��ռ���ȼ�Ϊ1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;         //�����ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /*��ʼ���ж����ȼ�*/
    NVIC_Init(&NVIC_InitStructure);
}
/**************************************�ļ�����*************************************/
