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
 * \brief TIM1 定时器 PWM 例程，通过标准接口实现
 *
 * - 实验现象：
 *   1. PIOA_0(TIM1_CH0)输出 100Hz 的 PWM，占空比为 50%；
 *
 * \par 源代码
 * \snippet demo_hc32f07x_std_tim1_pwm.c src_hc32f07x_std_tim1_pwm
 *
 * \internal
 * \par Modification history
 * - 1.00 19-09-23  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_hc32f07x_std_tim1_pwm
 * \copydoc demo_hc32f07x_std_tim1_pwm.c
 */

/** [src_hc32f07x_std_tim1_pwm] */

#include "ametal.h"
#include "am_vdebug.h"
#include "am_hc32_tim_pwm.h"
#include "am_hc32f07x_inst_init.h"
#include "demo_std_entries.h"
#include "demo_amf07x_core_entries.h"

/**
 * \brief 例程入口
 */
void demo_hc32f07x_core_std_tim1_pwm_entry (void)
{

    AM_DBG_INFO("demo amf07x_core std tim1 pwm!\r\n");

    demo_std_timer_pwm_entry(am_hc32_tim1_pwm_inst_init(), AM_HC32_TIM_PWM_CH0A);
}
/** [src_hc32f07x_std_tim1_pwm] */

/* end of file */
