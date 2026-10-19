//
// Created by zhujunlin on 2026/9/22.
//

#include "../Inc/usDelay.h"

void DWT_Init(void) {
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // 开启 TRC
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;          // 开启 CYCCNT 计数器
}

void delay_us(uint32_t us) {
    uint32_t startTick = DWT->CYCCNT;
    uint32_t delayTicks = us * (SystemCoreClock / 1000000);
    while ((DWT->CYCCNT - startTick) < delayTicks);
}
