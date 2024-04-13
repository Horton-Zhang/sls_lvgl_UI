/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_4_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-02-18
 * @brief	3_4_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-02-18     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_4_1

#include "lv_100ask_demo_course_3_4_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/
static void sw_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *sw = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        // 判断开关状态
        /* 方式1 */
        // 返回 bool 类型， 开-1 ； 关-2
        //if(lv_obj_has_state(sw, LV_STATE_CHECKED))
        //    LV_LOG_USER("ON!");
        //else
        //    LV_LOG_USER("OFF!");

        // 更简介的写法
        LV_LOG_USER("State: %s", lv_obj_has_state(sw, LV_STATE_CHECKED) ? "ON" : "OFF");


        /* 方式2 */
        //if(lv_obj_get_state(sw) & LV_STATE_CHECKED)
        //    LV_LOG_USER("ON!");
        //else
        //    LV_LOG_USER("OFF!");
        //LV_LOG_USER("State: %s", (lv_obj_get_state(sw) & LV_STATE_CHECKED) ? "ON" : "OFF");
    }

}


void lv_100ask_demo_course_3_4_1(void)
{
    /* 创建一个 switch 部件(对象) */
    lv_obj_t * sw = lv_switch_create(lv_scr_act());       // 创建一个 switch 部件(对象),他的父对象是活动屏幕对象
    lv_obj_center(sw);                                    // 方法1：让对象居中，简洁
    //lv_obj_align(sw, LV_ALIGN_CENTER, 0, 0);            // 方法2：让对象居中，较为灵活

    // 修改开关对象的大小，注意比例不能是 1:1 (比如：宽高都是100)，否则只能看到一个大圆
    //lv_obj_set_size(sw, 200, 100);

    // 开操作
    //lv_obj_add_state(sw, LV_STATE_CHECKED);                       // 开关默认处于关闭状态，这里设置为打开状态
    //lv_obj_add_state(sw, LV_STATE_CHECKED | LV_STATE_DISABLED);   // 当前状态是开，并且不可更改

    // 关操作
    //lv_obj_clear_state(sw, LV_STATE_CHECKED);	        // 关
    //lv_obj_add_state(sw, LV_STATE_DISABLED); 		        // 当前状态是关，并且不可更改

    // 清除禁用状态，一般由其他部件(外部)清除
    //lv_obj_clear_state(sw, LV_STATE_ DISABLED);       // 清除禁用状态，按钮可正常使用

    // 添加事件，当我们点击开关，改变开关的状态时，会触发 LV_EVENT_VALUE_CHANGED 事件类型
    // 当然我们可以处理他触发的其他事件类型，比如： LV_EVENT_CLICKED
    lv_obj_add_event_cb(sw, sw_event_handler, LV_EVENT_VALUE_CHANGED, NULL);

}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_4_1 */
