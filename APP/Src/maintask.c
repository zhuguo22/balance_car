#include "maintask.h"

float pitch , roll , yaw;
uint8_t MPU_display_buff[20];
uint8_t SR04_display_buff[20];
uint8_t Encoder_display_buff[20];
uint8_t sys_tick = 0;
int Encoder_Left,Encoder_Right;

extern float distance;
extern uint8_t rx_buff[2];

void Read_Encoder(void)
{
    if (uwTick-sys_tick < 10)
    {
        return;
    }
    sys_tick = uwTick;
    Encoder_Left = Read_Speed(&htim2);
    Encoder_Right = -Read_Speed(&htim4);
}


void MPU_Task(void)
{
    mpu_dmp_get_data(&pitch , &roll , &yaw);
    printf("MPU_Task success\r\n");
    sprintf((char *)MPU_display_buff,"roll:%.2f     ",roll);
    OLED_ShowString(0,2,MPU_display_buff,16);

}

void SR04_Task(void)
{
    GET_Distance();
    printf("SR04_Task success\r\n");
    sprintf((char *)SR04_display_buff,"distance:%.2f cm",distance);
    OLED_ShowString(0,4,SR04_display_buff,12);
}

void Encoder_Task(void)
{
    Read_Encoder();
    printf("Encoder_Task success\r\n");
    sprintf((char *)Encoder_display_buff,"Left:%d Right:%d",Encoder_Left,Encoder_Right);
    OLED_ShowString(0,6,Encoder_display_buff,16);
}

void MainTask_Init(void)
{
    DWT_Init();
    OLED_Init();
    OLED_Clear();
    MPU_Init();
    mpu_dmp_init();
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
    HAL_UART_Receive_IT(&huart3,rx_buff,1);
    Load(0,0);
    printf("Init success\r\n");
}

void Main_Task(void)
{
    MPU_Task();
    SR04_Task();
    Encoder_Task();
}