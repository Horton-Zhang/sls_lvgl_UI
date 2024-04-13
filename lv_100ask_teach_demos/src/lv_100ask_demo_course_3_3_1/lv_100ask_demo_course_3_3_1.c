/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_3_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-01-20
 * @brief	3_3_1 课的课堂代码
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

#if LV_USE_100ASK_DEMO_COURSE_3_3_1

#include "lv_100ask_demo_course_3_3_1.h"

// 用Windows PC模拟器键盘或鼠标需要包含此头文件
//#include "lv_drivers/win32drv/win32drv.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/

void lv_100ask_demo_course_3_3_1(void)
{
    // 创建一个组，稍后将需要使用键盘或编码器或按钮控制的部件(对象)添加进去，并且将输入设备和组关联
    // 如果将这个组设置为默认组，那么对于那些在创建时会添加到默认组的部件(对象)就可以省略 lv_group_add_obj()
    lv_group_t * g = lv_group_create();

    // 将上面创建的组设置为默认组
    // 如果稍后创建的部件(对象)，使用默认组那必须要在其创建之前设置好默认组，否则不生效
    //lv_group_set_default(g);

    // 将输入设备和组关联(使用前先打开上面注释掉的头文件)
    //lv_indev_set_group(lv_win32_keypad_device_object, g);     // 键盘
    //lv_indev_set_group(lv_win32_encoder_device_object, g);      // 鼠标上的滚轮(编码器)


    /* 创建一个btn部件(对象) */
    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -100);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn3 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn3, 100, 50);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn4 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn4, 100, 50);
    lv_obj_align_to(btn4, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_obj_align_to(slider, btn4, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // 将部件(对象)添加到组，如果设置了默认组，这里可以省略
    //lv_group_add_obj(g, btn1);
    //lv_group_add_obj(g, btn2);
    //lv_group_add_obj(g, btn3);
    //lv_group_add_obj(g, btn4);
    //lv_group_add_obj(g, slider);

}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_3_1 */
