#include "sensor.h"
#include "usart.h" 	 

//������ʼ������
void Sensor_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOCʱ��
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_4; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_DOWN;//���� 
  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��
} 


u8 Sensor1(void)
{
	return GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1);
	
}
u8 sensor2(void)
{
	return GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2);
}


u8 OPENMV_OUT(void)
{
	return GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4);
}
	


















