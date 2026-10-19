//
// Created by zhujunlin on 2026/7/25.
//

#ifndef BALANCE_CAR_MAINTASK_H
#define BALANCE_CAR_MAINTASK_H

#include "oled.h"
#include "tim.h"
#include "usart.h"

#include "mpu6050.h"
#include "dmpKey.h"
#include "dmpmap.h"
#include "IIC.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "usDelay.h"
#include "sr04.h"
#include "motor.h"
#include "encoder.h"


#include <stdio.h>
#include <string.h>



typedef void (*HALCallback)(void);



void Main_Task(void);
void MainTask_Init(void);

#endif //BALANCE_CAR_MAINTASK_H
