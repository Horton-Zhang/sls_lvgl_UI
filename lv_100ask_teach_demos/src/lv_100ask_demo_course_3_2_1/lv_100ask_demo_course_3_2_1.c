/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_2_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-01-20
 * @brief	3_2_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-01-20     zhouyuebiao     First version
 ******************************************************************************
 * @attention
 *
 * Copyright (C) 2008-2021 深圳百问网科技有限公司<https://www.100ask.net/>
 * All rights reserved
 *
 ******************************************************************************
 */


/*********************
 *      INCLUDES
 *********************/
#include "../../lv_100ask_teach_demos.h"

#if LV_USE_100ASK_DEMO_COURSE_3_2_1

#include "lv_100ask_demo_course_3_2_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/
static void btn_toggle_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);        // 获取触发事件的部件(对象)
    lv_event_code_t code = lv_event_get_code(e);    // 获取当前部件(对象)触发的事件代码

    switch(code){
        case LV_EVENT_VALUE_CHANGED:
            printf("LV_EVENT_VALUE_CHANGED\n");
            break;
        default:
            //printf("NONE\n");
            break;
    }
}

void lv_100ask_demo_course_3_2_1(void)
{
    /* 创建一个btn部件(对象) */
    lv_obj_t * btn = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象

    // 修改按钮部件（对象）矩形背景部分的样式
    //lv_obj_set_style_bg_color(btn, lv_color_hex(0x1e1e1e), LV_PART_MAIN | LV_STATE_PRESSED);

    // 打开了 LV_OBJ_FLAG_CHECKABLE ，当对象被点击时有选中切换(Toggle)状态的效果
    // 其触发的是 LV_EVENT_VALUE_CHANGED 事件类型
    //lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);

    // 处理 LV_EVENT_VALUE_CHANGED 事件类型示例
    //lv_obj_add_event_cb(btn, btn_toggle_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_2_1 */
