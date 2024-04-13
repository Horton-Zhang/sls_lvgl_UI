/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_10_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-05-13
 * @brief	3_10_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-05-13     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_10_1

#include "lv_100ask_demo_course_3_10_1.h"


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
static void lv_100ask_arc_test(void);
static void arc_event_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

 
void lv_100ask_demo_course_3_10_1(void)
{
#if 1
    // 创建一个 arc 组件(对象)，他的父对象是活动屏幕对象
	lv_obj_t * arc = lv_arc_create(lv_scr_act());

	/* 设置大小 */
	// 对于 arc 来说，影响弧长的因素有两个：角度和半径
	// 可以不设置，使用默认大小
	//lv_obj_set_size(arc, 400, 400);

	/* 调整位置 */
	lv_obj_center(arc);								   // 方法1：让对象居中，简洁
	//lv_obj_align(arc, LV_ALIGN_CENTER, 0, 0);		   // 方法2：让对象居中，较为灵活

	/* 设置 arc 的当前值 */
	/*
	 *  如果不设置，默认值是 INT16_MIN 
	 *  也就是起码要在arc的数值被改变一次之后，再获取arc的当前值使用
	 */
	//lv_arc_set_value(arc, 60);


	/* 设置arc的模式(modes) */
	/* arc 有三种模式 */
#if 1
	// 普通模式。指示器从最小值绘制到当前值。
	// 如果不设置模式，默认就是此模式
	lv_arc_set_mode(arc, LV_ARC_MODE_NORMAL);

	// 反向模式。指示器从最大值到当前值逆时针绘制。
	//lv_arc_set_mode(arc, LV_ARC_MODE_REVERSE);
	
	// 对称模式。指示器从中间点绘制到当前值。
	//lv_arc_set_mode(arc, LV_ARC_MODE_SYMMETRICAL);
#endif

	/* 设置变化率 */
	/* 
	 *  当圆弧被按下时，当前值将根据设置的变化率以有限的速度绘制出来。
	 *  变化率的单位是 “度/秒”
	 *  默认是 720°/s
	 */
	//lv_arc_set_change_rate(arc, 360);


	/* 设置背景弧和前景弧 */
	/* 零度位于对象的中间右侧（3 点钟方向），并且度数沿顺时针方向增加。*/
#if 0
	/* 设置背景弧 */
	/* 如果不设置，默认为         (135°-45°) */
	/* 
     * 背景弧就是我们看到的呈现灰色的弧，
	 * 其决定arc的绘制范围，同时也限制了前景弧的绘制范围
	 */
	// 设置背景弧的起始角度(位置)
	lv_arc_set_bg_start_angle(arc, 0);

	// 设置背景弧的结束角度(位置)	
	lv_arc_set_bg_end_angle(arc, 180);

	// 同时设置背景弧的 起始+结束 角度	
	lv_arc_set_bg_angles(arc, 0, 180);


	/* 设置前景弧 */
	/* 如果不设置，默认为       (135°-270°) */
	/* 
	 *  前置弧就是我们看到的呈现蓝色的弧，
	 *  其直接与用户进行交互，绘制范围受限于背景弧
	 */
	// 设置前景弧的起始角度(位置)
	lv_arc_set_start_angle(arc, 0);

	// 设置前景弧的结束角度(位置)	
	lv_arc_set_end_angle(arc, 180);

	// 同时设置前景弧的 起始+结束 角度	
	lv_arc_set_angles(arc, 0, 180);
	
#endif

	// 在设置好的前景弧和背景弧的基础上，
	// 将其整个旋转一个指定的角度
	lv_arc_set_rotation(arc, 90);

#if 0
	// 让arc不可点击
	// 这个时候指定通过 lv_arc_set_value 改变arc
	// 可以用在加载页面作为 loader 提示
	//lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);

	// 让arc恢复可以点击的属性
	lv_obj_add_flag(arc, LV_OBJ_FLAG_CLICKABLE);
#endif

#if 0
	// 去除指示器部分的样式，相当于让指示器部分整个不存在
	lv_obj_remove_style(arc, NULL, LV_PART_INDICATOR);

	// 去除旋钮部分的样式，相当于让选秀部分整个不存在
	lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
#endif


#if 1
	/* 
	 *  创建一个label实时更新展示arc的当前值
	 *  同时在事件处理回调函数中在
	 *  控制台打印arc的当前值
	 */
	lv_label_t * label = lv_label_create(lv_scr_act());
	lv_obj_align_to(label, arc, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
	
	lv_obj_add_event_cb(arc, arc_event_cb, LV_EVENT_VALUE_CHANGED, label);
#endif

#endif	

#if 0
	lv_100ask_arc_test();
#endif

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

LV_FONT_DECLARE(lv_100ask_font_source_han_mono_extra_light_32);

static void lv_100ask_arc_test(void)
{
	/* 第1层：以屏幕对象为容器(parent)，创建一个arc，其成为后面创建的组件的容器(parent) */
	lv_obj_t * arc_tmp = lv_arc_create(lv_scr_act());
	lv_obj_center(arc_tmp);
	lv_obj_set_size(arc_tmp, 350, 350);
	lv_arc_set_range(arc_tmp, 15, 35);
	lv_arc_set_value(arc_tmp, 23);
	lv_arc_set_bg_angles(arc_tmp, 120, 60);

	lv_obj_set_style_radius(arc_tmp, 360, LV_PART_MAIN);							// 设置part main在默认状态下的圆角		
	lv_obj_set_style_bg_opa(arc_tmp, LV_OPA_COVER, LV_PART_MAIN);  					// 设置part main在默认状态下的背景透明度
	lv_obj_set_style_bg_color(arc_tmp, lv_color_make(30, 35, 45), LV_PART_MAIN); 	// 设置part main在默认状态下的背景颜色
	lv_obj_set_style_pad_all(arc_tmp, 10, LV_PART_MAIN);							// 设置part main在默认状态下的填充/间隔/pad
	lv_obj_set_style_arc_color(arc_tmp, lv_color_make(15, 18, 21), LV_PART_MAIN); 	// 设置背景弧在默认状态下的颜色
	lv_obj_set_style_arc_width(arc_tmp, 15, LV_PART_MAIN);							// 设置背景弧在默认状态下的宽度
	lv_obj_set_style_arc_color(arc_tmp, lv_color_make(54, 185, 246), LV_PART_INDICATOR);	// 设置前景弧在默认状态下的颜色
	lv_obj_set_style_arc_width(arc_tmp, 15, LV_PART_INDICATOR);						// 设置前景弧在默认状态下的宽度

	// 去除旋钮部分的样式，相当于让选秀部分整个不存在
	lv_obj_remove_style(arc_tmp, NULL, LV_PART_KNOB);		// 方法1，去除arc组件中整个PART_KNOB的样式
	lv_obj_set_style_opa(arc_tmp, LV_OPA_0, LV_PART_KNOB);  // 方法2，让PART_KNOB完全透明

	/* 第2层：以前面的组件为容器(parent)，创建一个面板，用来突出层次感，并成为后面创建的组件的容器(parent) */
	lv_obj_t * panel3 = lv_obj_create(arc_tmp);
	lv_obj_set_size(panel3, 280, 280);
	lv_obj_center(panel3);

	lv_obj_set_style_radius(panel3, 360, LV_PART_MAIN);								// 设置part main在默认状态下的圆角		
	lv_obj_set_style_bg_color(panel3, lv_color_make(100, 100, 100), LV_PART_MAIN);	// 设置part main在默认状态下的背景颜色
	lv_obj_set_style_bg_grad_color(panel3, lv_color_make(60, 65, 75), LV_PART_MAIN);// 设置part main在默认状态下的背景渐变颜色
	lv_obj_set_style_bg_grad_dir(panel3, LV_GRAD_DIR_VER, LV_PART_MAIN);			// 设置part main在默认状态下的背景渐变方向
	lv_obj_set_style_border_color(panel3, lv_color_make(45, 50, 60), LV_PART_MAIN); // 设置part main在默认状态下的边框宽度
	lv_obj_set_style_arc_width(panel3, 2, LV_PART_MAIN);							
	lv_obj_set_style_shadow_color(panel3, lv_color_make(5, 10, 15), LV_PART_MAIN);	// 设置part main在默认状态下的阴影颜色
	lv_obj_set_style_shadow_width(panel3, 80, LV_PART_MAIN);						// 设置part main在默认状态下的阴影宽度
	lv_obj_set_style_shadow_spread(panel3, 0, LV_PART_MAIN);						// 设置part main在默认状态下的阴影扩散范围
	lv_obj_set_style_shadow_ofs_x(panel3, 0, LV_PART_MAIN);							// 设置part main在默认状态下的阴影在x轴上的偏移
	lv_obj_set_style_shadow_ofs_y(panel3, 30, LV_PART_MAIN);						// 设置part main在默认状态下的阴影在y轴上的偏移

	/* 第3层：以前面的组件为容器(parent)，再创建一个面板，用来突出层次感，同时成为展示当前数值组件的容器(parent) */
	lv_obj_t * panel_temp_value = lv_obj_create(panel3);
	lv_obj_set_size(panel_temp_value, 200, 200);
	lv_obj_center(panel_temp_value);

	lv_obj_set_style_radius(panel_temp_value, 360, LV_PART_MAIN);								// 设置part main在默认状态下的圆角		
	lv_obj_set_style_bg_color(panel_temp_value, lv_color_make(12, 25, 30), LV_PART_MAIN);		// 设置part main在默认状态下的背景颜色		
	lv_obj_set_style_bg_grad_color(panel_temp_value, lv_color_make(25, 28, 38), LV_PART_MAIN);	// 设置part main在默认状态下的背景渐变颜色
	lv_obj_set_style_bg_grad_dir(panel_temp_value, LV_GRAD_DIR_VER, LV_PART_MAIN);				// 设置part main在默认状态下的背景渐变方向
	lv_obj_set_style_border_color(panel_temp_value, lv_color_make(90, 100, 110), LV_PART_MAIN);	// 设置part main在默认状态下的边框宽度
	//lv_obj_set_style_arc_width(panel3, 2, LV_PART_MAIN);

	/* 第4层：以前面的组件为容器(parent)，创建一个label组件，用来展示 */
	lv_obj_t * label_temp = lv_label_create(panel_temp_value);
	lv_label_set_text_fmt(label_temp, "%d°", 23);
	lv_obj_center(label_temp);

	lv_obj_set_style_text_font(label_temp, &lv_100ask_font_source_han_mono_extra_light_32, LV_PART_MAIN); 	// 设置label_temp在默认状态下的字体
	lv_obj_set_style_text_color(label_temp, lv_color_make(255, 255, 255), LV_PART_MAIN);					// 设置label_temp在默认状态下的字体颜色

	/* 事件处理回调函数，在控制台和label_temp上实时展示当前数值 */
	lv_obj_add_event_cb(arc_tmp, arc_event_cb, LV_EVENT_VALUE_CHANGED, label_temp);
	
}

#endif /* LV_USE_100ASK_DEMO_COURSE_3_10_1 */
