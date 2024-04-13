/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_9_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-04-25
 * @brief	3_9_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-04-25     zhouyuebiao     First version
 * 2022-05-11     zhouyuebiao     1.2
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

#if LV_USE_100ASK_DEMO_COURSE_3_9_1

#include "lv_100ask_demo_course_3_9_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/
/* 使用共享样式，设置样式 */
/* 多个组件使用同一个共享样式，可以节省内存 */
static lv_style_t style_part_main;  				// 保存part main样式
static lv_style_t style_part_knob;					// 保存part knob(旋钮)样式
static lv_style_t style_part_indicator;				// 保存part indicator(指示器)样式

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void slider_event_cb(lv_event_t * e);
static void slider_style_init(void);
static void test1_slider(void);
static void test2_slider(void);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_9_1(void)
{

	/* 关闭这个宏开关后，可以尝试后面的 "slider 小实战"： test_slider() */
#if 1
	// 创建一个 slider 组件(对象)，他的父对象是活动屏幕对象
	lv_obj_t *slider = lv_slider_create(lv_scr_act());
	LV_LOG_USER("lv_slider_get_value(slider) %d", lv_slider_get_value(slider));

	/* 设置大小 */
	// 可以不设置，使用默认大小
	//lv_obj_set_size(slider, 200, 50);

	// 当设置进度条的宽度小于其高度，就可以创建出垂直摆放的进度条。
	//lv_obj_set_size(slider, 50, 200);

	/* 设置位置 */
	lv_obj_center(slider); 								   // 方法1：让对象居中，简洁
	//lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0); 		   // 方法2：让对象居中，较为灵活


	/* 设置进度条的模式(modes) */
	/* 进度条有三种模式*/
#if 0
	// 1.normal模式，如果没有设置模式默认是这个模式
	lv_slider_set_mode(slider, LV_BAR_MODE_NORMAL);
	lv_slider_set_range(slider, 0, 100);				// 如果不设置，默认是(0-100)
#endif

#if 0
	// 2.symmetrical模式，这个模式下可以指定负的最小范围。但是只能从零值到当前值绘制指示器。
	lv_slider_set_mode(slider, LV_BAR_MODE_SYMMETRICAL);
	lv_slider_set_range(slider, -100, 100);			// 这个模式下可以指定负的最小范围
	//lv_slider_set_value(slider, 50, LV_ANIM_ON);		// 设置结束值(大于0)
	lv_slider_set_value(slider, -50, LV_ANIM_ON);	// 设置结束值(小于0)
#endif

#if 0
	// 3.range模式，这个模式下也可以指定负的最小范围。这样进度条的起始值可以不是0，而是你指定的数值，这样设置的起始值必须小于结束值。
	lv_slider_set_mode(slider, LV_BAR_MODE_RANGE);
	lv_slider_set_range(slider, -100, 100);				// 这个模式下可以指定负的最小范围
	lv_slider_set_value(slider, 50, LV_ANIM_ON);			// 设置结束值
	lv_slider_set_left_value(slider, -90, LV_ANIM_ON);	// 设置起始值，注意必须小于结束值
#endif

#if 0
	/*Knob-only mode（仅旋钮模式）*/
	// 这个模式下只能通过拖动滑动条的旋钮(PART KNOB)来调整滑动条的数值
	lv_obj_add_flag(slider, LV_OBJ_FLAG_ADV_HITTEST);
#endif

#if 0
	/* 设置指示器的延申方向 */
	// 注意如果 slider 同时设置为 symmetrical 模式时会有显示不出来的情况，此时需要反过来设置数值
	lv_obj_set_style_base_dir(slider, LV_BASE_DIR_RTL, LV_PART_MAIN);
#endif

#if 0
	/* 设置样式 */
	// 假如 'lv_slider_set_value' 或 'lv_slider_set_start_value'
	// 设置了 LV_ANIM_ON，那么这里可以调整动画的时间
	lv_obj_set_style_anim_time(slider, 1000, LV_PART_MAIN);

	lv_obj_set_style_bg_color(slider, lv_color_hex(0xff0000), LV_PART_MAIN);

	// 设置当被按下时，指示器部分的背景颜色
	lv_obj_set_style_bg_color(slider, lv_color_hex(0xbdddba), LV_PART_INDICATOR | LV_STATE_PRESSED);

	// 设置默认状态下，指示器部分的背景颜色
	lv_obj_set_style_bg_color(slider, lv_color_hex(0x1e1e1e), LV_PART_INDICATOR | LV_STATE_DEFAULT);

	lv_obj_set_style_bg_opa(slider, LV_OPA_100, 0);
	lv_obj_set_style_bg_color(slider, lv_color_hex(0xbdddba), LV_PART_KNOB | LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(slider, lv_color_hex(0x1e1e1e), LV_PART_KNOB | LV_STATE_DEFAULT);
#endif


#if 0
	/* 创建一个label 实时展示滑动条当前的数值 */
	lv_obj_t * label = lv_label_create(lv_scr_act());
	lv_label_set_text_fmt(label, "%d%%", lv_slider_get_value(slider));
	lv_obj_align_to(label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

	// 设置事件处理回调函数，接收所有的事件类型
	lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_ALL, label);
#endif	

#endif

	/* slider 小实战，打开下面的宏开关前，请先关闭上面的宏开关 */
	// 视频教程： https://www.bilibili.com/video/BV1Ya411r7K2?p=32
#if 0
	// 共享样式初始化之后，就可以给其他部件使用
	// 如果要创建多个组件，并且他们的样式都是一样的，
	// 那么，使用同一个共享样式就可以达到节省内存的目的
	slider_style_init();

	// 创建并初始化多个slider
	test1_slider();
	test2_slider();

#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void slider_style_init(void)
{
	/* 初始化样式 */
	lv_style_init(&style_part_main);
	lv_style_init(&style_part_knob);
	lv_style_init(&style_part_indicator);

	/* 设置 PART MAIN 样式 */
	lv_style_set_radius(&style_part_main, 15);			// 设置四个角的圆角
	lv_style_set_bg_color(&style_part_main, 
						  lv_color_hex(0xc43e1c));		// 设置背景颜色
	lv_style_set_pad_top(&style_part_main, -2); 		// 设置顶部(top)的填充(top)大小
	lv_style_set_pad_bottom(&style_part_main, -2);		// 设置底部部(bottom)的填充(top)大小
	//lv_style_set_bg_opa(&style_part_main, LV_OPA_100);	// 设置背景透明度

	/* 设置 PART KNOB 样式 */
	// 将 knob 部分整个设置为透明，就能达到去除旋钮的效果
	// set_opa是设置不透明度，设置不透明度为0就是完全透明
	lv_style_set_opa(&style_part_knob, LV_OPA_0);

	/* 设置 PART INDICATOR 样式 */
	lv_style_set_radius(&style_part_indicator, 0);		// 设置四个角的圆角
	lv_style_set_bg_color(&style_part_indicator,
						  lv_color_hex(0xffffff));		// 设置背景颜色

}
static void test1_slider(void)
{
	// 创建一个 slider 组件(对象)，他的父对象是活动屏幕对象
	lv_obj_t *slider = lv_slider_create(lv_scr_act());

	/* 设置位置 */
	lv_obj_center(slider); 								// 方法1：让对象居中，简洁
	//lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0); 		// 方法2：让对象居中，较为灵活

	/*调整大小，让 slider 垂直摆放  */
	lv_obj_set_size(slider, 60, 150);


	/* 将样式应用到 slider */
	// 将保存在 style_part_main 中的样式应用到
	// slider 的 LV_PART_MAIN 上
	lv_obj_add_style(slider, &style_part_main, LV_PART_MAIN);

	// 将保存在 style_part_knob 中的样式应用到
	// slider 的 LV_PART_KNOB 上
	lv_obj_add_style(slider, &style_part_knob, LV_PART_KNOB);

	// 将保存在 style_part_indicator 中的样式应用到
	// slider 的 LV_PART_INDICATOR 上
	lv_obj_add_style(slider, &style_part_indicator, LV_PART_INDICATOR);


	/* 在 slider 内部放一个小图标，用来表明slider的作用 */
	// 这里使用 lvgl 的内置符号(方便、节省内存)，可以使用img展示。
	// lvgl内置符号： http://lvgl.100ask.net/8.2/overview/font.html#special-fonts
	lv_obj_t *label = lv_label_create(slider);
	lv_label_set_text(label, LV_SYMBOL_VOLUME_MAX);

	// 在lvgl中内置符号可以像 text 那样使用，lvgl 内置了很多不一样的字体(ASCII)，
	// 使用不同尺寸的内置字体就能展示不一样大小的 text ，默认是：lv_font_montserrat_14
	// 需要设置内置字体，请查看： lv_conf.h 中的 LV_FONT_MONTSERRAT_...
	lv_obj_set_style_text_font(label, &lv_font_montserrat_20, 0);
	lv_obj_set_style_text_color(label, lv_color_hex(0xac8477), 0);
	lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -20);

}



static void test2_slider(void)
{
	// 创建一个 slider 组件(对象)，他的父对象是活动屏幕对象
	lv_obj_t *slider = lv_slider_create(lv_scr_act());

	/* 设置位置 */
	//lv_obj_center(slider); 								// 方法1：让对象居中，简洁
	//lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0); 		// 方法2：让对象居中，较为灵活

	/*调整大小，让 slider 垂直摆放  */
	lv_obj_set_size(slider, 60, 150);


	/* 将样式应用到 slider */
	// 将保存在 style_part_main 中的样式应用到
	// slider 的 LV_PART_MAIN 上
	lv_obj_add_style(slider, &style_part_main, LV_PART_MAIN);

	// 将保存在 style_part_knob 中的样式应用到
	// slider 的 LV_PART_KNOB 上
	lv_obj_add_style(slider, &style_part_knob, LV_PART_KNOB);

	// 将保存在 style_part_indicator 中的样式应用到
	// slider 的 LV_PART_INDICATOR 上
	lv_obj_add_style(slider, &style_part_indicator, LV_PART_INDICATOR);


	/* 在 slider 内部放一个小图标，用来表明slider的作用 */
	// 这里使用 lvgl 的内置符号(方便、节省内存)，可以使用img展示。
	// lvgl内置符号： http://lvgl.100ask.net/8.2/overview/font.html#special-fonts
	lv_obj_t *label = lv_label_create(slider);
	lv_label_set_text(label, LV_SYMBOL_VOLUME_MAX);

	// 在lvgl中内置符号可以像 text 那样使用，lvgl 内置了很多不一样的字体(ASCII)，
	// 使用不同尺寸的内置字体就能展示不一样大小的 text ，默认是：lv_font_montserrat_14
	// 需要设置内置字体，请查看： lv_conf.h 中的 LV_FONT_MONTSERRAT_...
	lv_obj_set_style_text_font(label, &lv_font_montserrat_20, 0);
	lv_obj_set_style_text_color(label, lv_color_hex(0xac8477), 0);
	lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -20);

}

static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);        // 获取触发事件的部件(对象)
	lv_obj_t * label = lv_event_get_user_data(e);	// 获取事件传递的用户数据(user_data)
    lv_event_code_t code = lv_event_get_code(e);    // 获取当前部件(对象)触发的事件代码

    switch(code){
        case LV_EVENT_CLICKED:
            LV_LOG_USER("LV_EVENT_CLICKED\n");
			if (lv_slider_get_value(obj) == lv_slider_get_max_value(obj))
				lv_slider_set_value(obj, 0, LV_ANIM_ON);
			else
				lv_slider_set_value(obj, 30, LV_ANIM_ON);
			lv_label_set_text_fmt(label, "%d%%", lv_slider_get_value(obj));
            break;
		case LV_EVENT_PRESSING:
            LV_LOG_USER("LV_EVENT_PRESSING\n");
			lv_slider_set_value(obj, lv_slider_get_value(obj)+1, LV_ANIM_ON);
			lv_label_set_text_fmt(label, "%d%%", lv_slider_get_value(obj));
            break;
		/* ...... */
		/*请尝试添加更多的case吧*/
		case LV_EVENT_VALUE_CHANGED:
			//lv_label_set_text_fmt(label, "%d%%", lv_slider_get_value(obj));
			LV_LOG_USER("LV_EVENT_VALUE_CHANGED\n");
			break;
        default:
            //LV_LOG_USER("OTHERS\n");
            break;
    }
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_9_1 */
