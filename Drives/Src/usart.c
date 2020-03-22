/***********************************************************************************
 * @�ļ�  : usart.c
 * @����  : caochao
 * @����  : 2-3-2017
 * @ժҪ  : ���C�ļ�ʱ����usart��printf�������ض����usart1�ĳ�ʼ��
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 **********************************************************************************/
#include <stdio.h>
#include "stm32f4xx.h"
#include "usart.h"

/* �������´���,֧��printf����,������Ҫѡ��use MicroLIB	 */ 
#pragma import(__use_no_semihosting) 

//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
	/* Whatever you require here. If the only file you are using is */ 
	/* standard output using printf() for debugging, no file handling */ 
	/* is required. */ 
}; 
/* FILE is typedef�� d in stdio.h. */ 
FILE __stdout;       
FILE __stdin;

void _ttywrch(int ch) 
{
    while(USART_GetFlagStatus(USART1_PORT, USART_FLAG_TXE) == RESET)
    {
        ;
    }
    
    USART_SendData(USART1_PORT, ch);
}

/* ����_sys_exit()�Ա���ʹ�ð�����ģʽ  */  
void _sys_exit(int x) 
{ 
	x = x; 
} 

/**********************************************************************************
 *   ��������fputc(int ch,FILE *p)
 *   ��  �ܣ�printf�����ض���
 *   ��  �룺
 *          ch Ҫ��ӡ���ַ�
 *   ��  ����
 *********************************************************************************/
int fputc(int ch,FILE *p)
{
	while (USART_GetFlagStatus(USART1_PORT,USART_FLAG_TC) == RESET)
	{
		;
	}
	
	USART_SendData(USART1_PORT,(uint8_t)ch);
	return ch;
}

/***********************************************************************************
 *   ��������fgetc(FILE *p)
 *   ��  �ܣ�scanf�����ض���
 *   ��  �룺
 *          
 *   ��  ����
 *          ���յ����ַ�
 **********************************************************************************/
int fgetc(FILE *p)
{
	while (USART_GetFlagStatus(USART1_PORT,USART_FLAG_RXNE) == RESET)
	{
		;
	}
    
	return USART_ReceiveData(USART1_PORT);
}

/*************************************************************************************
 *  ������:   USART1_Configuration
 * ��������:  usart�Ĺ�������
 * ��    ��:   
 *           �� 
 * ��    ��:   
 *           ��
 ***********************************************************************************/
void USART1_Configuration(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    
    RCC_AHB1PeriphClockCmd(USART1_TX_PERIPH,ENABLE);       //��GPIOA��ʱ��  
    RCC_AHB1PeriphClockCmd(USART1_RX_PERIPH,ENABLE);       //��GPIOA��ʱ��  
    RCC_APB2PeriphClockCmd(USART1_PERIPH ,ENABLE);         //��usart1ʱ��
    
	GPIO_PinAFConfig(USART1_TX_PORT,USART1_TX_AF_PIN,USART1_TX_AF);  //GPIO����ΪUSART1
	GPIO_PinAFConfig(USART1_RX_PORT,USART1_RX_AF_PIN,USART1_RX_AF); //GPIO����ΪUSART1
    
    GPIO_InitStructure.GPIO_Pin	= USART1_TX_PIN  ; //GPIOΪ�����������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    
    GPIO_Init(USART1_TX_PORT,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin	= USART1_RX_PIN ; //GPIOΪ�����������ģʽ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    
	GPIO_Init(USART1_RX_PORT,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = USART1_BaudRate;         //����������Ϊ9600
	USART_InitStructure.USART_WordLength  = USART_WordLength_8b;  //��������Ϊ8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;        //ֹͣλΪ1
	USART_InitStructure.USART_Parity = USART_Parity_No;           //��������żλ���
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //��Ӳ����
    USART_InitStructure.USART_Mode =  USART_Mode_Rx | USART_Mode_Tx;     //����usart���ܺͷ�������
    USART_Init(USART1_PORT,&USART_InitStructure);         //��ʼ��usart

	USART_Cmd(USART1_PORT,ENABLE);                  //����usart                                                         
}

/************************************�ļ�����*****************************************/

