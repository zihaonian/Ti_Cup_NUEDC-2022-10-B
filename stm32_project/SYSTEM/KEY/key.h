#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 	 

/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
#define KEY1 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) //PA1
#define KEY2 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)	//PA2
#define KEY3 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)	//PA3 
#define KEY4 		GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)	//PA4 


/*���淽ʽ��ͨ��λ��������ʽ��ȡIO*/
/*
#define KEY1 		PAin(1)   //PA1
#define KEY2 		PAin(2)		//PA2
#define KEY3 		PAin(3)		//PA3
#define KEY4  	PAin(4)		//PA4
*/

extern u8 KEY_Num;
#define KEY1_PRES 1
#define KEY2_PRES	2
#define KEY3_PRES	3
#define KEY4_PRES	4

void KEY_Init(void);	//IO��ʼ��
u8 KEY_Scan(u8);  		//����ɨ�躯��	 1:����ɨ�� 0��������ɨ��//  ����ֵ1 2 3 4�ֱ��ʾ��Ӧ���ְ���

#endif
