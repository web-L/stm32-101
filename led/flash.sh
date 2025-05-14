#!/bin/bash

# STM32 LED项目的编译和烧录脚本

# 输出彩色文本的函数
print_green() {
    echo -e "\033[0;32m$1\033[0m"
}

print_yellow() {
    echo -e "\033[0;33m$1\033[0m"
}

print_red() {
    echo -e "\033[0;31m$1\033[0m"
}

# 检查工具链是否安装
if ! command -v arm-none-eabi-gcc &> /dev/null; then
    print_red "错误: 未找到 arm-none-eabi-gcc 工具链"
    print_yellow "请先安装ARM GCC工具链:
- macOS: brew install arm-none-eabi-gcc
- Linux: sudo apt-get install gcc-arm-none-eabi
- Windows: 安装ARM GNU工具链并添加到PATH"
    exit 1
fi

if ! command -v openocd &> /dev/null; then
    print_red "错误: 未找到 OpenOCD"
    print_yellow "请先安装OpenOCD:
- macOS: brew install openocd
- Linux: sudo apt-get install openocd
- Windows: 安装OpenOCD并添加到PATH"
    exit 1
fi

# 获取脚本所在目录
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
cd "$SCRIPT_DIR"

# 编译项目
print_green "开始编译项目..."
make

if [ $? -ne 0 ]; then
    print_red "编译失败，请检查错误信息"
    exit 1
fi

print_green "编译成功!"

# 检查ST-Link是否连接
print_yellow "检查ST-Link连接..."
if ! openocd -f interface/stlink.cfg -c "init; exit" &> /dev/null; then
    print_red "未检测到ST-Link设备，请检查连接"
    print_yellow "确保:
1. ST-Link已正确连接到电脑
2. SWDIO、SWCLK、电源和地线已正确连接"
    exit 1
fi

# 烧录程序
print_green "开始烧录程序到STM32..."
openocd -f stm32f103c8-stlink.cfg -c "program build/led.elf verify reset exit"

if [ $? -ne 0 ]; then
    print_red "烧录失败，请检查连接和配置"
    exit 1
fi

print_green "烧录成功! LED应该开始闪烁"
print_yellow "如果LED没有闪烁，请检查:
1. LED是否正确连接到PA0引脚
2. LED方向是否正确
3. 是否使用了适当的限流电阻" 