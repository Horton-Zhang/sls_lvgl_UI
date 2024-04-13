/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_8_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-04-22
 * @brief	3_8_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-04-22     zhouyuebiao     First version
 ******************************************************************************
 * @attention
 *
 * Copyright (C) 2008-2022 深圳百问网科技有限公司<https://www.100ask.net/>
 * All rights reserved
 *
 ******************************************************************************
 */


/*********************
 *      INCLUDES
 *********************/
#include "../../lv_100ask_teach_demos.h"

#if LV_USE_100ASK_DEMO_COURSE_3_8_1

#include "lv_100ask_demo_course_3_8_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/

static void bar_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);        // 获取触发事件的部件(对象)
	lv_obj_t * label = lv_event_get_user_data(e);	// 获取事件传递的用户数据(user_data)
    lv_event_code_t code = lv_event_get_code(e);    // 获取当前部件(对象)触发的事件代码

    switch(code){
        case LV_EVENT_CLICKED:
            LV_LOG_USER("LV_EVENT_CLICKED\n");
			if (lv_bar_get_value(obj) == lv_bar_get_max_value(obj))
				lv_bar_set_value(obj, 0, LV_ANIM_ON);
			else
				lv_bar_set_value(obj, 30, LV_ANIM_ON);
			lv_label_set_text_fmt(label, "%d%%", lv_bar_get_value(obj));
            break;
		case LV_EVENT_PRESSING:
            LV_LOG_USER("LV_EVENT_PRESSING\n");
			lv_bar_set_value(obj, lv_bar_get_value(obj)+1, LV_ANIM_ON);
			lv_label_set_text_fmt(label, "%d%%", lv_bar_get_value(obj));
            break;
		/* ...... */
		/*请尝试添加更多的case吧*/
        default:
            //LV_LOG_USER("NONE\n");
            break;
    }
}


void lv_100ask_demo_course_3_8_1(void)
{
	// 创建一个 bar 组件(对象)，他的父对象是活动屏幕对象
    lv_obj_t *bar = lv_bar_create(lv_scr_act());
	LV_LOG_USER("lv_bar_get_value(bar) %d", lv_bar_get_value(bar));

	/* 设置大小 */
	// 可以不设置，使用默认大小
	//lv_obj_set_size(bar, 200, 30);

	// 当设置进度条的宽度小于其高度，就可以创建出垂直摆放的进度条。
	//lv_obj_set_size(bar, 30, 200);

	/* 设置位置 */
	lv_obj_center(bar);                                    // 方法1：让对象居中，简洁
    //lv_obj_align(bar, LV_ALIGN_CENTER, 0, 0);            // 方法2：让对象居中，较为灵活

	/* 设置进度条的模式(modes) */
	/* 进度条有三种模式*/
#if 0
	// 1.normal模式，如果没有设置模式默认是这个模式
	lv_bar_set_mode(bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(bar, 0, 100); 				// 如果不设置，默认是(0-100)
#endif

#if 0
	// 2.symmetrical模式，这个模式下可以指定负的最小范围。但是只能从零值到当前值绘制指示器。
	lv_bar_set_mode(bar, LV_BAR_MODE_SYMMETRICAL);
	lv_bar_set_range(bar, -100, 100); 			// 这个模式下可以指定负的最小范围
	lv_bar_set_value(bar, 50, LV_ANIM_ON);		// 设置结束值(大于0)
	//lv_bar_set_value(bar, -50, LV_ANIM_ON);	// 设置结束值(小于0)
#endif

#if 0
	// 3.range模式，这个模式下也可以指定负的最小范围。这样进度条的起始值可以不是0，而是你指定的数值，这样设置的起始值必须小于结束值。
	lv_bar_set_mode(bar, LV_BAR_MODE_RANGE);
	lv_bar_set_range(bar, -100, 100);				// 这个模式下可以指定负的最小范围
	lv_bar_set_value(bar, 50, LV_ANIM_ON);			// 设置结束值
	lv_bar_set_start_value(bar, -90, LV_ANIM_ON);	// 设置起始值，注意必须小于结束值
#endif

	/* 设置样式 */
	// 假如 'lv_bar_set_value' 或 'lv_bar_set_start_value'
	// 设置了 LV_ANIM_ON，那么这里可以调整动画的时间
	lv_obj_set_style_anim_time(bar, 1000, LV_PART_MAIN);

	// 设置当被按下时，指示器部分的背景颜色
	//lv_obj_set_style_bg_color(bar, lv_color_hex(0xbdddba), LV_PART_INDICATOR | LV_STATE_PRESSED);

	// 设置默认状态下，指示器部分的背景颜色
	//lv_obj_set_style_bg_color(bar, lv_color_hex(0x1e1e1e), LV_PART_INDICATOR | LV_STATE_DEFAULT);

	// 设置指示器的延申方向
	// 注意 bar 设置为 symmetrical 模式时显示不出来的情况，需要反过来设置数值
	//lv_obj_set_style_base_dir(bar, LV_BASE_DIR_RTL, LV_PART_MAIN);

	lv_obj_t * label = lv_label_create(lv_scr_act());
	lv_label_set_text_fmt(label, "%d%%", lv_bar_get_value(bar));
	lv_obj_align_to(label, bar, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

	// 设置事件处理回调函数，接收所有的事件类型
	lv_obj_add_event_cb(bar, bar_event_cb, LV_EVENT_ALL, label);
}

#endif /* LV_USE_100ASK_DEMO_COURSE_3_8_1 */
