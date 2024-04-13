/**
 * @file lv_100ask_teach_demos.h
 *
 */

#ifndef LV_100ASK_TECH_DEMOS_H
#define LV_100ASK_TECH_DEMOS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_100ASK_DEMO_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_100ASK_DEMO_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_100ASK_DEMO_CONF_INCLUDE_SIMPLE)
#include "lv_100ask_teach_demos_conf.h"
#else
#include "../lv_100ask_teach_demos_conf.h"
#endif

#include "src/lv_100ask_demo_course_2_1_1/lv_100ask_demo_course_2_1_1.h"    // 基础对象(lv_obj)，"Hello, LVGL!"
#include "src/lv_100ask_demo_course_2_2_2/lv_100ask_demo_course_2_2_2.h"    // 基础对象的大小(size)
#include "src/lv_100ask_demo_course_2_2_3/lv_100ask_demo_course_2_2_3.h"    // 基础对象的位置(position)
#include "src/lv_100ask_demo_course_2_2_4/lv_100ask_demo_course_2_2_4.h"    // 基础对象的盒子模型(border-box)
#include "src/lv_100ask_demo_course_2_2_5/lv_100ask_demo_course_2_2_5.h"    // 基础对象的样式(styles)
#include "src/lv_100ask_demo_course_2_2_6/lv_100ask_demo_course_2_2_6.h"    // 基础对象的事件(events)、事件冒泡

#include "src/lv_100ask_demo_course_3_1_1/lv_100ask_demo_course_3_1_1.h"    // 组件(widgets)： 标签(label)的用法
#include "src/lv_100ask_demo_course_3_1_2/lv_100ask_demo_course_3_1_2.h"    // 组件(widgets)： 标签(label)，显示中文
#include "src/lv_100ask_demo_course_3_2_1/lv_100ask_demo_course_3_2_1.h"    // 组件(widgets)： 按钮(lv_btn)的用法
#include "src/lv_100ask_demo_course_3_3_1/lv_100ask_demo_course_3_3_1.h"    // 组件(widgets)： 使用物理按键代替触摸(groups)
#include "src/lv_100ask_demo_course_3_4_1/lv_100ask_demo_course_3_4_1.h"    // 组件(widgets)： 开关(lv_switch)的用法
#include "src/lv_100ask_demo_course_3_5_1/lv_100ask_demo_course_3_5_1.h"    // 组件(widgets)： 复选框(lv_checkbox)的用法
#include "src/lv_100ask_demo_course_3_6_1/lv_100ask_demo_course_3_6_1.h"    // 组件(widgets)： 下拉列表(lv_dropdown))的用法
#include "src/lv_100ask_demo_course_3_7_1/lv_100ask_demo_course_3_7_1.h"    // 组件(widgets)： 滚轮(lv_roller)的用法
#include "src/lv_100ask_demo_course_3_8_1/lv_100ask_demo_course_3_8_1.h"    // 组件(widgets)： 进度条(lv_bar)的用法
#include "src/lv_100ask_demo_course_3_9_1/lv_100ask_demo_course_3_9_1.h"    // 组件(widgets)： 滑动条(lv_slider)的用法
#include "src/lv_100ask_demo_course_3_10_1/lv_100ask_demo_course_3_10_1.h"  // 组件(widgets)： 圆弧(lv_arc)的用法
#include "src/lv_100ask_demo_course_3_10_3/lv_100ask_demo_course_3_10_3.h"  // 组件(widgets)： 圆弧(lv_arc)-综合实战
#include "src/lv_100ask_demo_course_3_11_1/lv_100ask_demo_course_3_11_1.h"  // 定时器： 定时器(lv_timer)的用法
#include "src/lv_100ask_demo_course_3_11_2/lv_100ask_demo_course_3_11_2.h"  // 为什么创建出来的组件获取到的宽高是0？(在学习2_2_2时遇到的问题)
#include "src/lv_100ask_demo_course_3_11_3/lv_100ask_demo_course_3_11_3.h"  // 为什么创建出来的组件获取到的坐标不正确？(在学习2_2_3时遇到的问题)
#include "src/lv_100ask_demo_course_3_12_1/lv_100ask_demo_course_3_12_1.h"  // 组件(widgets)： 线条(lv_line)的用法
#include "src/lv_100ask_demo_course_3_12_2/lv_100ask_demo_course_3_12_2.h"  // 组件(widgets)： 线条(lv_line)实战


/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(8, 2, 0) == 0
#error "lv_100ask_teach_demos: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_100ASK_TECH_DEMOS_H*/
