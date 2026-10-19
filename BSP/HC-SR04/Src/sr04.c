//
// Created by zhujunlin on 2026/9/22.
//

#include "../Inc/sr04.h"

uint32_t count = 0;
float distance = 0;

extern TIM_HandleTypeDef htim3;

uint32_t us = 11;

void GET_Distance(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
    delay_us(us);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == GPIO_PIN_SET)
    {
        __HAL_TIM_SetCounter(&htim3, 0);
        HAL_TIM_Base_Start(&htim3);
    }
    else
    {
        HAL_TIM_Base_Stop(&htim3);
        count = __HAL_TIM_GetCounter(&htim3);
        distance = count*0.017; //计算距离为几厘米
    }

}
