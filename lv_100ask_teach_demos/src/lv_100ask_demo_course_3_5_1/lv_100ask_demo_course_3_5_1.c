/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_5_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-02-18
 * @brief	3_5_1 课的课堂代码
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

#if LV_USE_100ASK_DEMO_COURSE_3_5_1

#include "lv_100ask_demo_course_3_5_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/
static void cb_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *cb = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        const char * txt = lv_checkbox_get_text(cb);

        // 判断开关状态
        /* 方式1 */
        // 返回 bool 类型， 开-1 ； 关-2
        //if(lv_obj_has_state(cb, LV_STATE_CHECKED))
        //    LV_LOG_USER("%s: CHECKED!", txt);
        //else
        //    LV_LOG_USER("%s: UNCHECKED!", txt);

        // 更简介的写法
        LV_LOG_USER("%s: %s", txt, lv_obj_has_state(cb, LV_STATE_CHECKED) ? "CHECKED" : "UNCHECKED");


        /* 方式2 */
        //if(lv_obj_get_state(cb) & LV_STATE_CHECKED)
        //    LV_LOG_USER("%s: CHECKED!", txt);
        //else
        //    LV_LOG_USER("%s: UNCHECKED!", txt);
        //LV_LOG_USER("%s: %s", txt, (lv_obj_get_state(cb) & LV_STATE_CHECKED) ? "CHECKED" : "UNCHECKED");
    }

}

void lv_100ask_demo_course_3_5_1(void)
{
    /* 创建一个 checkbox 部件(对象) */
    lv_obj_t * cb = lv_checkbox_create(lv_scr_act());     // 创建一个 switch 部件(对象),他的父对象是活动屏幕对象
    lv_checkbox_set_text(cb, "100ASK LVGL Tutorial" LV_SYMBOL_PLAY);  // 修改复选框的提示文字(覆盖)

    lv_obj_center(cb);                                    // 方法1：让对象居中，简洁
    //lv_obj_align(cb, LV_ALIGN_CENTER, 0, 0);            // 方法2：让对象居中，较为灵活

    //lv_obj_set_style_text_font(cb, &lv_font_montserrat_32, 0); // 修改复选框提示文字的字体
    //lv_obj_set_style_pad_all(cb, 20, LV_PART_INDICATOR);       // 修改复选框勾选框的大小
    //lv_obj_set_style_pad_column(cb, 100, 0);                   // 设置复选框的勾选框和提示文字的距离

    //lv_obj_set_style_bg_opa(cb, 100, LV_PART_MAIN);                         // 修改复选框的背景透明度
    //lv_obj_set_style_bg_color(cb, lv_color_hex(0xc43e1c), LV_PART_MAIN);    // 修改复选框的背景颜色

    //lv_obj_set_style_bg_color(cb, lv_color_hex(0xc43e1c), LV_PART_INDICATOR);   // 修改勾选框部分，勾选时的背景颜色
    //lv_obj_set_style_bg_color(cb, lv_color_hex(0x7719aa), LV_PART_INDICATOR | LV_STATE_CHECKED); // 修改勾选框部分，不勾选时的背景颜色


    // 勾选操作
    //lv_obj_add_state(cb, LV_STATE_CHECKED);                       // 复选框默认处于不勾选状态，这里设置为勾选状态状态
    //lv_obj_add_state(cb, LV_STATE_CHECKED | LV_STATE_DISABLED);   // 当前状态是勾选状态，并且不可更改

    // 不勾选操作
    //lv_obj_clear_state(cb, LV_STATE_CHECKED);	        // 不勾选
    //lv_obj_add_state(cb, LV_STATE_DISABLED); 		    // 当前状态是不勾选状态，并且不可更改

    // 清除禁用状态，一般由其他部件(外部)清除
    //lv_obj_clear_state(cb, LV_STATE_DISABLED);       // 清除禁用状态，复选框可正常使用

    // 添加事件，当我们点击复选框，改变勾选框的状态时，会触发 LV_EVENT_VALUE_CHANGED 事件类型
    // 当然我们可以处理他触发的其他事件类型，比如： LV_EVENT_CLICKED
    lv_obj_add_event_cb(cb, cb_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_5_1 */
