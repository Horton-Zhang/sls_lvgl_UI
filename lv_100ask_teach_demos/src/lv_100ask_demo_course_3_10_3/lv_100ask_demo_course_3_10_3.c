/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_10_3.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-05-13
 * @brief	3_10_3 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-05-27     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_10_3

#include "lv_100ask_demo_course_3_10_3.h"


/*********************
 *      DEFINES
 *********************/
// 声明字体文件
LV_FONT_DECLARE(lv_100ask_font_source_han_mono_extra_light_32);

/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/
static lv_style_t style_arc_temp_part_main;
static lv_style_t style_arc_temp_part_indicator;
static lv_style_t style_arc_temp_part_knob;
static lv_style_t style_panel_part_main;
static lv_style_t style_panel_temp_value_part_main;
static lv_style_t style_label_temp_part_main;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_100ask_arc_test_style_init(void);
static lv_obj_t * lv_100ask_arc_test_create(void);
static void arc_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_10_3(void)
{
	lv_100ask_arc_test_style_init();

	lv_obj_t * arc_test = lv_100ask_arc_test_create();
	lv_obj_set_size(arc_test, 250, 250);
	lv_obj_align(arc_test, LV_ALIGN_LEFT_MID, 0, 0);

	arc_test = lv_100ask_arc_test_create();
	lv_obj_align(arc_test, LV_ALIGN_RIGHT_MID, 0, 0);
}


/**********************
 *   STATIC FUNCTIONS
 **********************/
static void arc_event_cb(lv_event_t * e)
{
	lv_obj_t * arc = lv_event_get_target(e);
	lv_obj_t * label = (lv_obj_t *)lv_event_get_user_data(e);
	int16_t value = lv_arc_get_value(arc);

	lv_label_set_text_fmt(label, "%d°", value);
	LV_LOG_USER("lv_arc_get_value(arc) = %d", value);
}


static void lv_100ask_arc_test_style_init(void)
{
	lv_style_init(&style_arc_temp_part_main);
	lv_style_set_radius(&style_arc_temp_part_main, 360);							// 设置part main在默认状态下的圆角		
	lv_style_set_bg_opa(&style_arc_temp_part_main, LV_OPA_COVER);					// 设置part main在默认状态下的背景透明度
	lv_style_set_bg_color(&style_arc_temp_part_main, lv_color_make(30, 35, 45));	// 设置part main在默认状态下的背景颜色
	lv_style_set_pad_all(&style_arc_temp_part_main, 10);							// 设置part main在默认状态下的填充/间隔/pad
	lv_style_set_arc_color(&style_arc_temp_part_main, lv_color_make(15, 18, 21));	// 设置背景弧在默认状态下的颜色
	lv_style_set_arc_width(&style_arc_temp_part_main, 15);							// 设置背景弧在默认状态下的宽度

	lv_style_init(&style_arc_temp_part_indicator);
	lv_style_set_arc_color(&style_arc_temp_part_indicator, lv_color_make(54, 185, 246));	// 设置前景弧在默认状态下的颜色
	lv_style_set_arc_width(&style_arc_temp_part_indicator, 15);								// 设置前景弧在默认状态下的宽度

	lv_style_init(&style_arc_temp_part_knob);
	lv_style_set_opa(&style_arc_temp_part_knob, LV_OPA_0);	// 设置PART_KNOB在默认状态下的透明度

	lv_style_init(&style_panel_part_main);
	lv_style_set_radius(&style_panel_part_main, 360);								// 设置part main在默认状态下的圆角		
	lv_style_set_bg_color(&style_panel_part_main, lv_color_make(100, 100, 100));	// 设置part main在默认状态下的背景颜色
	lv_style_set_bg_grad_color(&style_panel_part_main, lv_color_make(60, 65, 75));	// 设置part main在默认状态下的背景渐变颜色
	lv_style_set_bg_grad_dir(&style_panel_part_main, LV_GRAD_DIR_VER);				// 设置part main在默认状态下的背景颜色渐变的方向
	lv_style_set_border_color(&style_panel_part_main, lv_color_make(45, 50, 60));	// 设置part main在默认状态下的边框宽度
	lv_style_set_arc_width(&style_panel_part_main, 2);				
	lv_style_set_shadow_color(&style_panel_part_main, lv_color_make(5, 10, 15));	// 设置part main在默认状态下的阴影颜色
	lv_style_set_shadow_width(&style_panel_part_main, 80);							// 设置part main在默认状态下的阴影宽度
	lv_style_set_shadow_spread(&style_panel_part_main, 0);							// 设置part main在默认状态下的阴影扩散范围
	lv_style_set_shadow_ofs_x(&style_panel_part_main, 0);							// 设置part main在默认状态下的阴影在x轴上的偏移
	lv_style_set_shadow_ofs_y(&style_panel_part_main, 30);							// 设置part main在默认状态下的阴影在y轴上的偏移

	lv_style_init(&style_panel_temp_value_part_main);		
	lv_style_set_radius(&style_panel_temp_value_part_main, 360);								// 设置part main在默认状态下的圆角		
	lv_style_set_bg_color(&style_panel_temp_value_part_main, lv_color_make(12, 25, 30));		// 设置part main在默认状态下的背景颜色		
	lv_style_set_bg_grad_color(&style_panel_temp_value_part_main, lv_color_make(25, 28, 38));	// 设置part main在默认状态下的背景渐变颜色
	lv_style_set_bg_grad_dir(&style_panel_temp_value_part_main, LV_GRAD_DIR_VER);				// 设置part main在默认状态下的背景颜色渐变的方向
	lv_style_set_border_color(&style_panel_temp_value_part_main, lv_color_make(90, 100, 110));	// 设置part main在默认状态下的边框宽度

	lv_style_init(&style_label_temp_part_main);
	lv_style_set_text_color(&style_label_temp_part_main, lv_color_make(255, 255, 255));					// 设置label_temp在默认状态下的字体
	lv_style_set_text_font(&style_label_temp_part_main, &lv_100ask_font_source_han_mono_extra_light_32);// 设置label_temp在默认状态下的字体颜色
}

static lv_obj_t * lv_100ask_arc_test_create(void)
{
	/* 第1层：以屏幕对象为容器(parent)，创建一个arc，其成为后面创建的组件的容器(parent) */
	lv_obj_t * arc_temp = lv_arc_create(lv_scr_act());
	lv_obj_center(arc_temp);
	lv_obj_set_size(arc_temp, 350, 350);
	lv_arc_set_range(arc_temp, 15, 35);
	lv_arc_set_value(arc_temp, 23);
	lv_arc_set_bg_angles(arc_temp, 120, 60);

	// 应用style_arc_temp_part_main样式到arc_temp的LV_PART_MAIN和默认状态上
	lv_obj_add_style(arc_temp, &style_arc_temp_part_main, LV_PART_MAIN);

	// 应用style_arc_temp_part_indicator样式到arc_temp的LV_PART_INDICATOR和默认状态上
	lv_obj_add_style(arc_temp, &style_arc_temp_part_indicator, LV_PART_INDICATOR);

	// 应用style_arc_temp_part_knob样式到arc_temp的LV_PART_KNOB和默认状态上
	lv_obj_add_style(arc_temp, &style_arc_temp_part_knob, LV_PART_KNOB);

	/* 第2层：以前面的组件为容器(parent)，创建一个面板，用来突出层次感，并成为后面创建的组件的容器(parent) */
	lv_obj_t * panel = lv_obj_create(arc_temp);
	//lv_obj_set_size(panel, 280, 280);
	lv_obj_set_size(panel, LV_PCT(85), LV_PCT(85));
	lv_obj_center(panel);

	// 应用style_panel_part_main样式到panel的PV_PART_MAIN和默认状态上
	lv_obj_add_style(panel, &style_panel_part_main, LV_PART_MAIN);

	/* 第3层：以前面的组件为容器(parent)，再创建一个面板，用来突出层次感，同时成为展示当前数值组件的容器(parent) */
	lv_obj_t * panel_temp_value = lv_obj_create(panel);
	//lv_obj_set_size(panel_temp_value, 200, 200);
	lv_obj_set_size(panel_temp_value, LV_PCT(90), LV_PCT(90));
	lv_obj_center(panel_temp_value);

	// 应用style_panel_temp_value_part_main样式到panel的PV_PART_KNOB和默认状态上
	lv_obj_add_style(panel_temp_value, &style_panel_temp_value_part_main, LV_PART_MAIN);

	/* 第4层：以前面的组件为容器(parent)，创建一个label组件，用来展示 */
	lv_obj_t * label_temp = lv_label_create(panel_temp_value);
	lv_label_set_text_fmt(label_temp, "%d°", 23);
	lv_obj_center(label_temp);

	// 应用style_label_temp_part_main样式到label_temp的PV_PART_MAIN和默认状态上
	lv_obj_add_style(label_temp, &style_label_temp_part_main, LV_PART_MAIN);

	/* 事件处理回调函数，在控制台和label_temp上实时展示当前数值 */
	lv_obj_add_event_cb(arc_temp, arc_event_cb, LV_EVENT_VALUE_CHANGED, label_temp);

	return arc_temp;

}



#endif /* LV_USE_100ASK_DEMO_COURSE_3_10_3 */
