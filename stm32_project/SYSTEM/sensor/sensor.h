#ifndef __SENSOR_H
#define __SENSOR_H	 
#include "sys.h"  
//�� ��1 �������� 
/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
	 //PC1  Sensor1() 	
	//PC2   Sensor2() 


void Sensor_Init(void);	//IO��ʼ��
u8 Sensor1(void);
u8 sensor2(void);
u8 OPENMV_OUT(void);
#endif
