# STM32 LED 闪烁项目 (GCC + OpenOCD + ST-Link V2)

本项目演示如何使用 GCC 编译工具链和 OpenOCD 烧录工具来构建和烧录 STM32F103C8T6 LED 闪烁程序。

## 环境要求

需要安装以下工具：

1. **ARM GCC 工具链**
2. **OpenOCD**
3. **make**
4. **ST-Link V2 硬件调试器**

## 安装指南

### macOS:

```bash
# 使用 Homebrew 安装
brew install arm-none-eabi-gcc
brew install openocd
```

### Linux (Ubuntu/Debian):

```bash
sudo apt-get update
sudo apt-get install gcc-arm-none-eabi
sudo apt-get install openocd
```

### Windows:

1. 下载并安装 [ARM GNU 工具链](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
2. 下载并安装 [OpenOCD](https://openocd.org/pages/getting-openocd.html)
3. 将上述工具的 bin 目录添加到系统 PATH 环境变量中

## 接线方式

ST-Link V2 与 STM32F103C8T6 的连接方式：

| ST-Link V2 | STM32F103C8T6 |
|------------|---------------|
| 3.3V       | 3.3V          |
| GND        | GND           |
| SWDIO      | PA13          |
| SWCLK      | PA14          |

LED连接：
- 将LED正极接到PA0引脚
- 将LED负极通过适当的限流电阻（如220欧姆）接到GND

## 编译和烧录

### 编译项目

```bash
# 进入项目目录
cd led

# 编译
make
```

成功编译后，将在 `build` 目录下生成 `.elf`, `.hex` 和 `.bin` 文件。

### 烧录到单片机

方法1: 使用Makefile的flash目标
```bash
make flash
```

方法2: 手动使用OpenOCD
```bash
# 使用项目提供的OpenOCD配置文件
openocd -f stm32f103c8-stlink.cfg -c "program build/led.elf verify reset exit"
```

## 故障排除

1. **无法找到ST-Link设备**:
   - 检查USB连接
   - 确认驱动程序已正确安装
   - 尝试使用不同的USB端口

2. **编译错误**:
   - 确保已正确安装ARM GCC工具链
   - 检查PATH环境变量是否包含工具链路径

3. **烧录失败**:
   - 检查接线是否正确
   - 确认单片机有足够的电源供应
   - 尝试降低OpenOCD的适配器速度 (在配置文件中修改 `adapter speed` 值，如改为500)

## 项目结构

```
led/
├── Core/              # 核心代码
│   ├── Inc/           # 头文件
│   ├── Src/           # 源文件
│   └── Startup/       # 启动文件
├── Drivers/           # HAL驱动库
├── STM32F103C8TX_FLASH.ld  # 链接脚本
├── Makefile           # 构建系统
└── stm32f103c8-stlink.cfg  # OpenOCD配置文件
``` 