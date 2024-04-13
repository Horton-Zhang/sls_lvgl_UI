/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_6_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-03-18
 * @brief	3_6_1 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-03-18     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_6_1

#include "lv_100ask_demo_course_3_6_1.h"

// 用Windows PC模拟器键盘或鼠标需要包含此头文件
//#include "lv_drivers/win32drv/win32drv.h"

/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/
// 通过其他部件打开或关闭下拉列表
static void btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    lv_obj_t *dd  = lv_event_get_user_data(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        // 由于 btn 在初始化时已经设置了 LV_OBJ_FLAG_CHECKABLE
        // 那么这里就可以检查 btn 当前的状态，达到打开或关闭下拉列表的目的
        // 这里的用法请参考 3_5_1 和 3_4_1
        if(lv_obj_has_state(btn, LV_STATE_CHECKED))
            lv_dropdown_open(dd);
        else
            lv_dropdown_close(dd);
    }

}

static void dd_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("%d", lv_dropdown_get_selected(obj));       // 获取选项的索引值，从0开始
        char tmp_buf[32];
        lv_dropdown_get_selected_str(obj, tmp_buf, sizeof(tmp_buf)); // 获取选项的内容
        LV_LOG_USER("%s", tmp_buf);
    }
    else if(code == LV_EVENT_CLICKED)
    {
        // 改变下拉列表中列表的样式
        // 这些修改可以在初始化的时候就设置好，你也可以像下面这样动态地修改样式
        lv_obj_t * dd_list = lv_dropdown_get_list(obj);
        if(dd_list != NULL)
        {
            // 需要在 lv_conf.h 中打开宏 LV_FONT_MONTSERRAT_28，要使用其他内置字体同理
            // 注意：如果你初始化时使用了中文字库，并且设置了中文选项，这里设置之后内容将不能展示出来
            //lv_obj_set_style_text_font(dd_list, &lv_font_montserrat_28, 0);

            // 修改列表的背景颜色
            // 这里只修改颜色，你还可以修改其他样式属性
            lv_obj_set_style_bg_color(dd_list, lv_color_hex(0xc43e1c), 0);
            //lv_obj_set_style_bg_color(dd_list, lv_color_hex(0xc43e1c), LV_PART_MAIN); // 这样写和上面那个是一样的

            // 修改滚动条的样式
            // 这里只修改颜色，你还可以修改其他样式属性
            lv_obj_set_style_border_color(dd_list, lv_color_hex(0xcc3e1c), LV_PART_SCROLLBAR);

            // 修改当按下、选中或按下+选中选项时的样式
            // 这里只修改颜色，你还可以修改其他样式属性
            lv_obj_set_style_bg_color(dd_list, lv_color_hex(0xafbeac), LV_PART_SELECTED);

        }
    }
}

void lv_100ask_demo_course_3_6_1(void)
{

#if 0
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
    lv_indev_set_group(lv_win32_encoder_device_object, g);      // 鼠标上的滚轮(编码器)

#endif // 0

    /* 创建一个 lv_dropdown 部件(对象) */
    lv_obj_t * dd = lv_dropdown_create(lv_scr_act());    // 创建一个 lv_dropdown 部件(对象),他的父对象是活动屏幕对象

    // 将部件(对象)添加到组，如果设置了默认组，这里可以省略，因为 lv_dropdown 是 LV_OBJ_CLASS_GROUP_DEF_TRUE
    //lv_group_add_obj(g, dd);

#if 1
    lv_dropdown_set_options(dd, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10");  // 写法1：添加选项，索引从0开始
#if 0
    lv_dropdown_set_options(dd, "1\n"
                                "2\n"
                                "3\n"
                                "4\n"
                                "5\n"
                                "6\n"
                                "7\n"
                                "8\n"
                                "9\n"
                                "10"); // 写法2：添加选项(连续写两个双引号相当于将两者连起来，相当于上面的方法1)
#endif // 写法1：添加选项，索引从0开始
#endif // 写法2：添加选项(连续写两个双引号相当于将两者连起来，相当于上面的方法1)

    lv_obj_center(dd);                                    // 方法1：让对象居中，简洁
    //lv_obj_align(dd, LV_ALIGN_CENTER, 0, 0);            // 方法2：让对象居中，较为灵活

#if 0
    // 获取下拉列表中的列表来修改样式或其他修改
    lv_obj_t * dd_list = lv_dropdown_get_list(dd);

#if 0
    // 显示中文
    // 修改列表所使用的字体，如果要展示中文则要在这里设置
    LV_FONT_DECLARE(lv_font_source_han_sans_bold_14);   // 声明字体，可以放到函数外部
    lv_obj_set_style_text_font(dd, &lv_font_source_han_sans_bold_14, 0);        // 设置新的字体(下拉列表的按钮)
    lv_obj_set_style_text_font(dd_list, &lv_font_source_han_sans_bold_14, 0);   // 设置新的字体(下拉列表中的列表)
    lv_dropdown_set_options(dd, "一\n二\n三\n四\n五\n六\n七\n八\n九\n十");      // 设置中文选项
    //lv_dropdown_set_symbol(dd, LV_SYMBOL_CALL);   // 注意：如果使用自定义的字库，并且你的字库中没有这些符号，那么下拉列表的符号就不会显示了
#endif

    // 使用内置字体
    lv_obj_set_style_text_font(dd, &lv_font_montserrat_30, 0);          // 设置新的字体(下拉列表的按钮)
    lv_obj_set_style_text_font(dd_list, &lv_font_montserrat_30, 0);     // 设置新的字体(下拉列表中的列表)

    // 设置字体对齐位置
    //lv_obj_set_style_text_align(dd, LV_TEXT_ALIGN_CENTER, 0);           // 这样设置下拉列表的按钮的文字对齐位置不会生效，可以在 LV_EVENT_DRAW_MAIN 事件中修改，但是不建议修改，详情请阅读 lv_dropdown.c 的源码
    lv_obj_set_style_text_align(dd_list, LV_TEXT_ALIGN_RIGHT, 0);       // 设置下拉列表中的列表的文字对齐
    
#endif // 0

    //lv_dropdown_add_option(dd, "11", 10);         // 追加一个选项
    //lv_dropdown_add_option(dd, "十一", 10);       // 追加一个选项(使用中文的时候)
    //lv_dropdown_set_selected(dd, 3);              // 设置默认选中的选项，索引从0开始
    //lv_dropdown_set_symbol(dd, LV_SYMBOL_CALL);   // 设置按钮显示的字符
    //lv_dropdown_set_text(dd, "Some text");        // 设置当选中选项之后展示的内容，如果没有这句，那么选中的是什么就展示什么

#if 0
    // 改变列表创建的方向
    // 下拉列表按钮上的符号会跟随 所设置的方向自动调整(左侧或右侧)
    // 官方参考示例：  http://lvgl.100ask.net/8.2/widgets/core/dropdown.html#drop-down-in-four-directions

    lv_dropdown_set_dir(dd, LV_DIR_LEFT);     // 左侧
    lv_dropdown_set_dir(dd, LV_DIR_RIGHT);    // 右侧
    lv_dropdown_set_dir(dd, LV_DIR_TOP);      // 顶部
    lv_dropdown_set_dir(dd, LV_DIR_BOTTOM);   // 底部
#endif // 0

    // 添加事件
    // 当我们点击下拉列表时，会触发 LV_EVENT_CLICKED 事件类型，并且会创建出一个列表，列表中展示我们在前面设置的选项供我们选择
    // 当我们选中一个选项时，会触发 LV_EVENT_VALUE_CHANGED 事件类型
    lv_obj_add_event_cb(dd, dd_event_handler, LV_EVENT_ALL, NULL);

#if 1
    // 通过其他部件打开或关闭下拉列表
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_align_to(btn, dd, LV_ALIGN_OUT_TOP_MID, 0, -10);
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_VALUE_CHANGED , dd);
#endif // 1

}

#endif /* LV_USE_100ASK_DEMO_COURSE_3_6_1 */
