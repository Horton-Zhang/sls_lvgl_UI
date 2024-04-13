/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_7_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-03-24
 * @brief	3_7_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-03-24     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_7_1

#include "lv_100ask_demo_course_3_7_1.h"

// 用Windows PC模拟器键盘或鼠标需要包含此头文件
#include "lv_drivers/win32drv/win32drv.h"

/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/


// 通过其他部件选择
static void btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    lv_obj_t *roller  = lv_event_get_user_data(e);


    if(code == LV_EVENT_CLICKED) {
        uint32_t sel_opt = lv_roller_get_selected(roller);          // 获取当前选项的索引(位置)
        uint32_t total_opt = lv_roller_get_option_cnt(roller) - 1;  // 获取当前选项的总数，因为索引从 0 开始算，所以减一用于判断最后的选项

        if (sel_opt == total_opt)   sel_opt = 0;
        else                        sel_opt += 1;

        lv_roller_set_selected(roller, sel_opt, LV_ANIM_ON);
        lv_event_send(roller, LV_EVENT_VALUE_CHANGED, 0);           // 向 roller 发送 LV_EVENT_VALUE_CHANGED 事件
    }
}


// 滚轮的事件回调处理函数
static void roller_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *roller = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("%d", lv_roller_get_selected(roller));             // 获取被选中的选项的索引值，从0开始
        char tmp_buf[8];
        lv_roller_get_selected_str(roller, tmp_buf, sizeof(tmp_buf));  // 获取被选中的选项的内容
        LV_LOG_USER("%s", tmp_buf);
    }
}


void lv_100ask_demo_course_3_7_1(void)
{
#if 1
    // 使用物理按键控制，注意上面要包含 "lv_drivers/win32drv/win32drv.h"，
    // LVGL按键控制，视频教程： https://www.bilibili.com/video/BV1Ya411r7K2?p=19
    // 创建一个组，稍后将需要使用键盘或编码器或按钮控制的部件(对象)添加进去，并且将输入设备和组关联
    // 如果将这个组设置为默认组，那么对于那些在创建时会添加到默认组的部件(对象)就可以省略 lv_group_add_obj()
    lv_group_t * g = lv_group_create();

    // 将上面创建的组设置为默认组
    // 如果稍后创建的部件(对象)，使用默认组那必须要在其创建之前设置好默认组，否则不生效
    lv_group_set_default(g);

    // 将输入设备和组关联(使用前先打开上面注释掉的头文件)
    lv_indev_set_group(lv_win32_keypad_device_object, g);     // 键盘
    lv_indev_set_group(lv_win32_encoder_device_object, g);    // 鼠标上的滚轮(编码器)
#endif // 0

    /* 创建一个 lv_roller 部件(对象) */
    lv_obj_t * roller = lv_roller_create(lv_scr_act());    // 创建一个 lv_roller 部件(对象),他的父对象是活动屏幕对象

    // 将部件(对象)添加到组，如果设置了默认组，这里可以省略，因为 lv_roller 是 LV_OBJ_CLASS_GROUP_DEF_TRUE
    //lv_group_add_obj(g, roller);

#if 1
    lv_roller_set_options(roller, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10", LV_ROLLER_MODE_NORMAL);   // 写法1：设置选项，索引从0开始
    //lv_roller_set_options(roller, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10", LV_ROLLER_MODE_INFINITE); // 设置为可以无限滚动的模式
#if 0
    lv_roller_set_options(roller,
                          "1\n"
                          "2\n"
                          "3\n"
                          "4\n"
                          "5\n"
                          "6\n"
                          "7\n"
                          "8\n"
                          "9\n"
                          "10",
                          LV_ROLLER_MODE_NORMAL); // 写法2：设置选项(连续写两个双引号相当于将两者连起来，相当于上面的方法1)
#endif // 写法1：添加选项，索引从0开始
#endif // 写法2：添加选项(连续写两个双引号相当于将两者连起来，相当于上面的方法1)

    // 设置默认选中的选项
    lv_roller_set_selected(roller, 3, LV_ANIM_ON);

#if 0
    // 设置可见的选项个数(行数)
    // 如果滚轮的字体、行距、边框宽度等发生变化，则需要再次调用此函数以重新进行调整。
    lv_roller_set_visible_row_count(roller, 2);

#if 0
    // 可见行也可以通过调整高度设置，但是一般不会这么做
    // 正常是使用 lv_roller_set_visible_row_count 设置
    lv_obj_set_height(roller, 600);
#endif // 0
#endif // 1

    lv_obj_center(roller);                                    // 方法1：让对象居中，简洁
    //lv_obj_align(roller, LV_ALIGN_CENTER, 0, 0);            // 方法2：让对象居中，较为灵活

#if 0
    // 修改滚轮所使用的字体(英文)
    lv_obj_set_style_text_font(roller, &lv_font_montserrat_22, LV_PART_MAIN);                 // 设置没有选中的选项的字体
    lv_obj_set_style_text_font(roller, &lv_font_montserrat_22, LV_PART_SELECTED);             // 设置选中的选项的字体
#endif // 0

#if 0
    // 修改滚轮所使用的字体(中文)
    LV_FONT_DECLARE(lv_font_source_han_sans_bold_14);   // 声明字体，可以放到函数外部
    lv_obj_set_style_text_font(roller, &lv_font_source_han_sans_bold_14, LV_PART_MAIN);                 // 设置没有选中的选项的字体
    lv_obj_set_style_text_font(roller, &lv_font_source_han_sans_bold_14, LV_PART_SELECTED);             // 设置选中的选项的字体
    lv_roller_set_options(roller, "一\n二\n三\n四\n五\n六\n七\n八\n九\n十", LV_ROLLER_MODE_NORMAL);     // 设置中文选项
#endif // 0

#if 0 
    // 改变选项中文字位置
    //lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_LEFT, 0);   // 左对齐
    //lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_RIGHT, 0);  // 右对齐
    //lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_CENTER, 0); // 居中对齐
    //lv_obj_set_style_text_align(roller, LV_TEXT_ALIGN_AUTO, 0);   // 自动对齐
#endif // 0

    // 添加事件
    // 当我们滑动了滚轮中的选项列表时，会触发 LV_EVENT_VALUE_CHANGED 事件类型，这里接收所有的事件类型，在回调处理函数中再过滤处理
    lv_obj_add_event_cb(roller, roller_event_handler, LV_EVENT_ALL, NULL);

#if 1
    // 通过其他部件选择选项
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_align_to(btn, roller, LV_ALIGN_OUT_TOP_MID, 0, -10);
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_CLICKED , roller);
#endif // 1

}

#endif /* LV_USE_100ASK_DEMO_COURSE_3_7_1 */
