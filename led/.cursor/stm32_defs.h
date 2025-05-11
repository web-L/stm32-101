/**
 * STM32补充定义文件 - 用于解决编辑器报错问题
 * 此文件仅用于提供IntelliSense支持，不参与实际编译
 */

#ifndef STM32_DEFS_H
#define STM32_DEFS_H

/* 基本类型定义 */
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif

#ifndef uint16_t
typedef unsigned short uint16_t;
#endif

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

#ifndef int8_t
typedef signed char int8_t;
#endif

#ifndef int16_t
typedef signed short int16_t;
#endif

#ifndef int32_t
typedef signed int int32_t;
#endif

/* 特殊属性定义 */
#ifndef __IO
#define __IO volatile
#endif

#ifndef __weak
#define __weak __attribute__((weak))
#endif

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

/* GPIO定义 */
#ifndef GPIO_PIN_0
#define GPIO_PIN_0 ((uint16_t)0x0001)
#define GPIO_PIN_1 ((uint16_t)0x0002)
#define GPIO_PIN_2 ((uint16_t)0x0004)
#define GPIO_PIN_3 ((uint16_t)0x0008)
#define GPIO_PIN_4 ((uint16_t)0x0010)
#define GPIO_PIN_5 ((uint16_t)0x0020)
#define GPIO_PIN_6 ((uint16_t)0x0040)
#define GPIO_PIN_7 ((uint16_t)0x0080)
#define GPIO_PIN_8 ((uint16_t)0x0100)
#define GPIO_PIN_9 ((uint16_t)0x0200)
#define GPIO_PIN_10 ((uint16_t)0x0400)
#define GPIO_PIN_11 ((uint16_t)0x0800)
#define GPIO_PIN_12 ((uint16_t)0x1000)
#define GPIO_PIN_13 ((uint16_t)0x2000)
#define GPIO_PIN_14 ((uint16_t)0x4000)
#define GPIO_PIN_15 ((uint16_t)0x8000)
#define GPIO_PIN_ALL ((uint16_t)0xFFFF)
#endif

#ifndef GPIO_MODE_OUTPUT_PP
#define GPIO_MODE_OUTPUT_PP 0x00000001U
#define GPIO_MODE_OUTPUT_OD 0x00000011U
#define GPIO_MODE_INPUT 0x00000000U
#define GPIO_NOPULL 0x00000000U
#define GPIO_PULLUP 0x00000001U
#define GPIO_PULLDOWN 0x00000002U
#define GPIO_SPEED_FREQ_LOW 0x00000000U
#define GPIO_SPEED_FREQ_MEDIUM 0x00000001U
#define GPIO_SPEED_FREQ_HIGH 0x00000002U
#define GPIO_PIN_SET 0x00000001U
#define GPIO_PIN_RESET 0x00000000U
#endif

/* 看门狗定义 */
#ifndef IWDG_PRESCALER_4
#define IWDG_PRESCALER_4 0x00000000U
#define IWDG_PRESCALER_8 0x00000001U
#define IWDG_PRESCALER_16 0x00000002U
#define IWDG_PRESCALER_32 0x00000003U
#define IWDG_PRESCALER_64 0x00000004U
#define IWDG_PRESCALER_128 0x00000005U
#define IWDG_PRESCALER_256 0x00000006U
#endif

#ifndef WWDG_PRESCALER_1
#define WWDG_PRESCALER_1 0x00000000U
#define WWDG_PRESCALER_2 0x00000080U
#define WWDG_PRESCALER_4 0x00000100U
#define WWDG_PRESCALER_8 0x00000180U
#define WWDG_EWI_DISABLE 0x00000000U
#define WWDG_EWI_ENABLE 0x00000200U
#endif

/* 基本外设类型定义 */
#ifndef GPIOA_BASE
#define GPIOA_BASE 0x40010800UL
#define GPIOB_BASE 0x40010C00UL
#define GPIOC_BASE 0x40011000UL
#define GPIOD_BASE 0x40011400UL
#define GPIOE_BASE 0x40011800UL
#define IWDG_BASE 0x40003000UL
#define WWDG_BASE 0x40002C00UL
#endif

/* 外设结构体定义 */
#ifndef GPIO_TypeDef
typedef struct {
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

typedef struct {
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
} IWDG_TypeDef;

typedef struct {
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
} WWDG_TypeDef;

typedef struct {
  __IO uint32_t Pin;
  __IO uint32_t Mode;
  __IO uint32_t Pull;
  __IO uint32_t Speed;
} GPIO_InitTypeDef;

typedef struct {
  IWDG_TypeDef *Instance;
  uint32_t Prescaler;
  uint32_t Reload;
} IWDG_HandleTypeDef;

typedef struct {
  WWDG_TypeDef *Instance;
  uint32_t Prescaler;
  uint32_t Window;
  uint32_t Counter;
  uint32_t EWIMode;
} WWDG_HandleTypeDef;
#endif

/* 外设定义 */
#ifndef GPIOA
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define IWDG ((IWDG_TypeDef *)IWDG_BASE)
#define WWDG ((WWDG_TypeDef *)WWDG_BASE)
#endif

/* RCC定义 */
#ifndef RCC_OSCILLATORTYPE_HSI
#define RCC_OSCILLATORTYPE_HSI 0x00000002U
#define RCC_OSCILLATORTYPE_LSI 0x00000008U
#define RCC_HSI_ON 0x00000001U
#define RCC_LSI_ON 0x00000001U
#define RCC_PLL_NONE 0x00000000U
#define RCC_HSICALIBRATION_DEFAULT 0x10U
#define RCC_CLOCKTYPE_HCLK 0x00000002U
#define RCC_CLOCKTYPE_SYSCLK 0x00000001U
#define RCC_CLOCKTYPE_PCLK1 0x00000004U
#define RCC_CLOCKTYPE_PCLK2 0x00000008U
#define RCC_SYSCLKSOURCE_HSI 0x00000000U
#define RCC_SYSCLK_DIV1 0x00000000U
#define RCC_HCLK_DIV1 0x00000000U
#define FLASH_LATENCY_0 0x00000000U
#endif

/* HAL函数声明 */
#ifndef HAL_Init
void HAL_Init(void);
void HAL_Delay(uint32_t Delay);
HAL_StatusTypeDef HAL_RCC_OscConfig(void *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(void *RCC_ClkInitStruct, uint32_t FLatency);
HAL_StatusTypeDef HAL_IWDG_Init(IWDG_HandleTypeDef *hiwdg);
HAL_StatusTypeDef HAL_WWDG_Init(WWDG_HandleTypeDef *hwwdg);
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint32_t PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_IWDG_Refresh(IWDG_HandleTypeDef *hiwdg);
#endif

/* RCC宏 */
#ifndef __HAL_RCC_GPIOC_CLK_ENABLE
#define __HAL_RCC_GPIOC_CLK_ENABLE() do { } while(0)
#define __HAL_RCC_GPIOD_CLK_ENABLE() do { } while(0)
#endif

/* 状态枚举 */
#ifndef HAL_OK
#define HAL_OK 0x00U
#define HAL_ERROR 0x01U
#define HAL_BUSY 0x02U
#define HAL_TIMEOUT 0x03U

typedef enum {
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;
#endif

/* 中断相关 */
#ifndef __disable_irq
#define __disable_irq() do { } while(0)
#endif

#endif /* STM32_DEFS_H */ 