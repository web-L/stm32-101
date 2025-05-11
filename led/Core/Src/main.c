#include "main.h"

int main(void)
{
  HAL_Init();
  
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  // 添加速度配置
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  while (1) {
    // 尝试反转极性
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);     /* 尝试高电平 */
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);   /* 尝试低电平 */
    HAL_Delay(500);
  }
}