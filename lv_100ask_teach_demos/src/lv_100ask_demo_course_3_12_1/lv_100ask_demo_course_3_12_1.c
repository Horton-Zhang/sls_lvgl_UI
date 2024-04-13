/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_12_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-06-16
 * @brief	3_12_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-06-16     zhouyuebiao     First version
 ******************************************************************************
 * @attention
 *
 * Copyright (C) 2008-2022 深圳百问网科技有限公司<https://www.100ask.net>
 * All rights reserved
 *
 ******************************************************************************
 */


/*********************
 *      INCLUDES
 *********************/
#include "../../lv_100ask_teach_demos.h"

#if LV_USE_100ASK_DEMO_COURSE_3_12_1

#include "lv_100ask_demo_course_3_12_1.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_12_1(void)
{
	/*
		设置一组点，用来提供给line组件画线
		这个数组应该是静态、全局或动态分配的，不能是函数中的局部变量
		因为lv_line_set_points保存的只是该数组的指针
	*/
	static lv_point_t line_points[] = { {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };

	/*创建一个共享样式*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
	// 下面3个样式是 line 的专有样式接口，类似于arc
    lv_style_set_line_width(&style_line, 8);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
	// 使用这个样式能让画出来的线条看起来更平滑
    lv_style_set_line_rounded(&style_line, true);

	// 设置line的背景颜色
	//lv_style_set_bg_opa(&style_line, LV_OPA_100);
	//lv_style_set_bg_color(&style_line, lv_color_hex(0xed1c24));

	/* 创建一个 line 组件(对象)，他的父对象是活动屏幕对象 */
	lv_obj_t * line = lv_line_create(lv_scr_act());
	/*
		如果设置了大小，那么有些超出设置大小的部分将会看不到
		默认不需要设置大小，line会根据给出的points自动调整大小以此展示所有的points。这和label组件类似
	 */
	//lv_obj_set_size(line, 150, 60);
	lv_line_set_y_invert(line, true);				// 反转y轴，LCD坐标系->平面直角坐标系第一象限
	lv_obj_center(line);
	//lv_obj_set_align(line, LV_ALIGN_BOTTOM_LEFT); // 放在屏幕的右下角，看起来更直观
	lv_line_set_points(line, line_points, 5);     	// 设置点数组。line将连接这些点，按顺序画出直线
	lv_obj_add_style(line, &style_line, 0);
}


/**********************
 *   STATIC FUNCTIONS
 **********************/


#endif /* LV_USE_100ASK_DEMO_COURSE_3_12_1 */
