#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
void TIM3_PWM_Init(u32 arr,u32 psc);//��ʼ��PA6
void TIM2_PWM_Init(u32 arr,u32 psc);
#endif

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
//	delay_init(168);  //��ʼ����ʱ����

//  if(CAMERA_TRIGGER_25HZ)
//	{
//		PWM_PSC = 84;//��Ƶϵ��.----����Ƶ��Ϊ84M/PWM_PSC = 1M hz
//		PWM_ARR = 40000;//��װ��ֵ----PWMƵ��  (84M/PWM_PSC)/PWM_ARR = 25 hz
//		PWM_a = 0.1;//ռ�ձ�	
//	}else if(CAMERA_TRIGGER_20HZ)
//	{
//		PWM_PSC = 84;//��Ƶϵ��.----����Ƶ��Ϊ84M/PWM_PSC = 1M hz
//		PWM_ARR = 50000;//��װ��ֵ----PWMƵ��  (84M/PWM_PSC)/PWM_ARR = 25 hz
//		PWM_a = 0.1;//ռ�ձ�	
//	}
//	
//	PWM_CCR = (uint32_t)PWM_ARR*PWM_a;	     
// 	TIM14_PWM_Init(PWM_ARR,PWM_PSC);	//����PWM����
//	TIM_SetCompare1(TIM14,PWM_CCR);	//�޸ıȽ�ֵ���޸�ռ�ձ�
