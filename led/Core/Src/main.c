/* 用户代码开始 Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : 主程序体
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2025 意法半导体。
  * 保留所有权利。
  *
  * 此软件的许可条款可在本软件组件根目录下的LICENSE文件中找到。
  * 如果没有随此软件提供LICENSE文件，则按"原样"提供。
  *
  ******************************************************************************
  */
/* 用户代码结束 Header */
/* 包含文件 ------------------------------------------------------------------*/
#include "main.h"

/* 私有包含 ----------------------------------------------------------*/
/* 用户代码开始 Includes */

/* 用户代码结束 Includes */

/* 私有类型定义 -----------------------------------------------------------*/
/* 用户代码开始 PTD */

/* 用户代码结束 PTD */

/* 私有定义 ------------------------------------------------------------*/
/* 用户代码开始 PD */
#define LED_PIN                         GPIO_PIN_13      /* LED引脚定义，PC13通常连接到板载用户LED */
#define LED_GPIO_PORT                   GPIOC            /* LED所在的GPIO端口 */
#define LED_ON()                        HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET) /* LED点亮（低电平有效） */
#define LED_OFF()                       HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET)   /* LED熄灭（高电平） */
#define LED_TOGGLE()                    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN)               /* LED状态翻转 */
/* 用户代码结束 PD */

/* 私有宏 -------------------------------------------------------------*/
/* 用户代码开始 PM */

/* 用户代码结束 PM */

/* 私有变量 ---------------------------------------------------------*/
IWDG_HandleTypeDef hiwdg;

WWDG_HandleTypeDef hwwdg;

/* 用户代码开始 PV */

/* 用户代码结束 PV */

/* 私有函数原型 -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_IWDG_Init(void);
static void MX_WWDG_Init(void);
/* 用户代码开始 PFP */

/* 用户代码结束 PFP */

/* 私有用户代码 ---------------------------------------------------------*/
/* 用户代码开始 0 */

/* 用户代码结束 0 */

/**
  * @brief  应用程序入口点
  * @retval int
  */
int main(void)
{

  /* 用户代码开始 1 */

  /* 用户代码结束 1 */

  /* MCU配置--------------------------------------------------------*/

  /* 复位所有外设，初始化Flash接口和Systick */
  HAL_Init();

  /* 用户代码开始 Init */

  /* 用户代码结束 Init */

  /* 配置系统时钟 */
  SystemClock_Config();

  /* 用户代码开始 SysInit */

  /* 用户代码结束 SysInit */

  /* 初始化所有已配置的外设 */
  MX_GPIO_Init();
  MX_IWDG_Init();
  MX_WWDG_Init();
  /* 用户代码开始 2 */

  /* 用户代码结束 2 */

  /* 无限循环 */
  /* 用户代码开始 WHILE */
  while (1)
  {
    /* 用户代码结束 WHILE */

    /* 用户代码开始 3 */
    LED_TOGGLE();                /* 切换LED状态(亮变灭，灭变亮) */
    HAL_Delay(500);              /* 延时500ms(0.5秒) */
    
    /* 喂狗 - 防止看门狗超时复位系统 */
    HAL_IWDG_Refresh(&hiwdg);
  }
  /* 用户代码结束 3 */
}

/**
  * @brief 系统时钟配置
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** 根据RCC_OscInitTypeDef结构中指定的参数初始化RCC振荡器
  * 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** 初始化CPU、AHB和APB总线时钟
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief IWDG初始化函数
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* 用户代码开始 IWDG_Init 0 */

  /* 用户代码结束 IWDG_Init 0 */

  /* 用户代码开始 IWDG_Init 1 */

  /* 用户代码结束 IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_4;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* 用户代码开始 IWDG_Init 2 */

  /* 用户代码结束 IWDG_Init 2 */

}

/**
  * @brief WWDG初始化函数
  * @param None
  * @retval None
  */
static void MX_WWDG_Init(void)
{

  /* 用户代码开始 WWDG_Init 0 */

  /* 用户代码结束 WWDG_Init 0 */

  /* 用户代码开始 WWDG_Init 1 */

  /* 用户代码结束 WWDG_Init 1 */
  hwwdg.Instance = WWDG;
  hwwdg.Init.Prescaler = WWDG_PRESCALER_1;
  hwwdg.Init.Window = 64;
  hwwdg.Init.Counter = 64;
  hwwdg.Init.EWIMode = WWDG_EWI_DISABLE;
  if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* 用户代码开始 WWDG_Init 2 */

  /* 用户代码结束 WWDG_Init 2 */

}

/**
  * @brief GPIO初始化函数
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* 用户代码开始 MX_GPIO_Init_1 */

  /* 用户代码结束 MX_GPIO_Init_1 */

  /* GPIO端口时钟使能 */
  __HAL_RCC_GPIOC_CLK_ENABLE();  /* 使能GPIOC端口时钟 */
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*配置GPIO引脚输出电平 */
  HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET);  /* 设置LED初始状态为熄灭 */
  
  /*配置GPIO引脚：PC13 */
  GPIO_InitStruct.Pin = LED_PIN;                    /* 配置LED引脚 */
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;       /* 设置为推挽输出模式 */
  GPIO_InitStruct.Pull = GPIO_NOPULL;               /* 无上下拉电阻 */
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;      /* 配置为低速输出(降低功耗和噪声) */
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  /* 用户代码开始 MX_GPIO_Init_2 */

  /* 用户代码结束 MX_GPIO_Init_2 */
}

/* 用户代码开始 4 */

/* 用户代码结束 4 */

/**
  * @brief  错误发生时执行的函数
  * @retval None
  */
void Error_Handler(void)
{
  /* 用户代码开始 Error_Handler_Debug */
  /* 用户可以添加自己的实现来报告HAL错误返回状态 */
  __disable_irq();
  while (1)
  {
  }
  /* 用户代码结束 Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  报告源文件名和assert_param错误发生的源行号
  * @param  file: 指向源文件名的指针
  * @param  line: assert_param错误行源码行号
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* 用户代码开始 6 */
  /* 用户可以添加自己的实现来报告文件名和行号，
     例如：printf("参数值错误：文件 %s 第 %d 行\r\n", file, line) */
  /* 用户代码结束 6 */
}
#endif /* USE_FULL_ASSERT */
