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
 * \brief ADC INT 例程，通过 HW 层接口实现
 *
 * - 操作步骤：
 *   1. 9个顺序通道  + 4个插入通道 扫描转换采集电压
 *
 * - 实验现象：
 *   1. 串口输出电压采样值。
 *
 * \note
 *    1. 如需观察串口打印的调试信息，需要将 PIOB_11引脚连接 PC串口的RXD，
 *       PIOB_12引脚连接 PC串口的TXD。
 *
 * \par 源代码
 * \snippet demo_zsl42x_hw_multichan_adc.c src_zsl42x_hw_multichan_adc
 *
 * \internal
 * \par Modification History
 * - 1.00 19-09-25  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_zsl42x_hw_multichan_adc
 * \copydoc demo_zsl42x_hw_multichan_adc.c
 */

/** [src_zsl42x_hw_multichan_adc] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_zsl42x.h"
#include "am_gpio.h"
#include "am_clk.h"
#include "demo_zsl42x_entries.h"
#include "demo_am42x_core_entries.h"

/**
 * \brief 例程入口
 */
void demo_zsl42x_core_hw_multichan_adc_entry (void)
{
    /* 9个顺序通道ADC采集 */ 
    /* 4个插入通道ADC采集 */
    int adc_chan[13] = {AMHW_ZSL42x_CHAN_AIN0_PA0,
                        AMHW_ZSL42x_CHAN_AIN1_PA1,
                        AMHW_ZSL42x_CHAN_AIN2_PA2,
                        AMHW_ZSL42x_CHAN_AIN3_PA3,
                        AMHW_ZSL42x_CHAN_AIN4_PA4,
                        AMHW_ZSL42x_CHAN_AIN8_PB0,
                        AMHW_ZSL42x_CHAN_AIN9_PB1,
                        AMHW_ZSL42x_CHAN_AIN10_PC0,
                        AMHW_ZSL42x_CHAN_AIN11_PC1,
                        AMHW_ZSL42x_CHAN_AIN12_PC2,
                        AMHW_ZSL42x_CHAN_AIN13_PC3,
                        AMHW_ZSL42x_CHAN_AIN14_PC4,
                        AMHW_ZSL42x_CHAN_AIN15_PC5};
    
    AM_DBG_INFO("demo am42x_core hw multichan adc int!\r\n");

    /* 配置引脚 */
    am_gpio_pin_cfg(PIOA_0, PIOA_0_GPIO | PIOA_0_AIN);
    am_gpio_pin_cfg(PIOA_1, PIOA_1_GPIO | PIOA_1_AIN);
    am_gpio_pin_cfg(PIOA_2, PIOA_2_GPIO | PIOA_2_AIN);
    am_gpio_pin_cfg(PIOA_3, PIOA_3_GPIO | PIOA_3_AIN);
    am_gpio_pin_cfg(PIOA_4, PIOA_4_GPIO | PIOA_4_AIN);
    am_gpio_pin_cfg(PIOB_0, PIOB_0_GPIO | PIOB_0_AIN);
    am_gpio_pin_cfg(PIOB_1, PIOB_1_GPIO | PIOB_1_AIN);
    am_gpio_pin_cfg(PIOC_0, PIOC_0_GPIO | PIOC_0_AIN);
    am_gpio_pin_cfg(PIOC_1, PIOC_1_GPIO | PIOC_1_AIN);
    am_gpio_pin_cfg(PIOC_2, PIOC_2_GPIO | PIOC_2_AIN);
    am_gpio_pin_cfg(PIOC_3, PIOC_3_GPIO | PIOC_3_AIN);
    am_gpio_pin_cfg(PIOC_4, PIOC_4_GPIO | PIOC_4_AIN);
    am_gpio_pin_cfg(PIOC_5, PIOC_5_GPIO | PIOC_5_AIN);

    /* 时钟使能  */
    am_clk_enable(CLK_ADC_BGR);

    demo_zsl42x_hw_multichan_adc_entry(ZSL42x_ADC,
                                     INUM_ADC_DAC,
                                     2500,
                                     adc_chan,
                                     9,
                                     4);
}
/** [src_zsl42x_hw_multichan_adc] */

/* end of file */
