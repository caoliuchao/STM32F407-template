/***********************************************************************************
 * @�ļ�  : usart.h
 * @����  : caochao
 * @����  : 2-3-2017
 * @ժҪ  : ���h�ļ�ʱ����usart��printf����������
 *
 * �޸��� :
 *  ����  :
 *
 * �޸��� :
 *  ����  :
 **********************************************************************************/
/* �����ֹ�ݹ�İ��� */
#ifndef _USART_H
#define _USART_H

#ifdef __cplusplus
 extern "C" {
#endif
     
/*------------------------------------USART��غ궨��-------------------------------*/
#define  USART1_PORT         USART1
#define  USART1_BaudRate     115200
#define  USART1_PERIPH       RCC_APB2Periph_USART1
     
#define  USART1_TX_PORT      GPIOA     
#define  USART1_TX_PIN       GPIO_Pin_9 
#define  USART1_TX_PERIPH    RCC_AHB1Periph_GPIOA 
#define  USART1_TX_AF        GPIO_AF_USART1  
#define  USART1_TX_AF_PIN    GPIO_PinSource9
     
#define  USART1_RX_PORT      GPIOA     
#define  USART1_RX_PIN       GPIO_Pin_10 
#define  USART1_RX_PERIPH    RCC_AHB1Periph_GPIOA   
#define  USART1_RX_AF        GPIO_AF_USART1
#define  USART1_RX_AF_PIN    GPIO_PinSource10
  
//------------------------------����������------------------------------------// 
int  fputc(int ch,FILE *p);
int  fgetc(FILE *p); 
void USART1_Configuration(void);	 
    
#ifdef __cplusplus
}
#endif

#endif /* _USART_H */

/*************************************�ı�����*******************************/

