/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief 光谱传感器 AS7341 例程，通过标准接口实现(通过查询方式获取数据)
 *
 * - 实验现象：
 *   1. 每过一秒，通过串口打印光谱通道AD值
 *
 * \par 源代码
 * \snippet demo_zlg237_core_sensor_as7341.c src_zlg237_core_sensor_as7341
 *
 * \internal
 * \par Modification history
 * - 1.00 20-04-26  fzb, first implementation
 * \endinternal
 */

#include "am_gpio.h"
#include "am_delay.h"
#include "am_zlg237.h"
#include "am_sensor.h"
#include "am_hwconf_sensor_as7341.h"
#include "demo_std_entries.h"
#include "demo_am237_core_entries.h"

/* 1.8V使能引脚，用于控制相同从机地址的通断电 */
#define PIN_1P8_OUT1    PIOC_4
#define PIN_1P8_OUT2    PIOC_5

/**
 * \brief 传感器例程入口
 */
void demo_zlg237_core_sensor_as7341_entry (void)
{
    /* 使能 1.8V_OUT1 引脚 */
    am_gpio_pin_cfg(PIN_1P8_OUT1, AM_GPIO_OUTPUT_INIT_HIGH);

    /* 等待供电稳定 */
    am_mdelay(2);

    am_sensor_handle_t handle = am_sensor_as7341_inst_init();

    demo_std_as7341_entry(handle);
}


/* end of file */
