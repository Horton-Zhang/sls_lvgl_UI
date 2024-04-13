/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_11_2.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-06-15
 * @brief	3_11_2 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-06-15     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_11_2

#include "lv_100ask_demo_course_3_11_2.h"


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
static void get_obj_size(void * scr);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_11_2(void)
{
    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_arc_set_value(arc, 50);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
    lv_obj_center(arc);

    /*
      我们这里给他设置的大小只是设置了组件的样式大小，还不是实际的区域大小，
      实际的区域大小在display的timer中再根据最新的size样式进行计算：
        lv_disp_drv_register
            _lv_disp_refr_timer
                lv_obj_update_layout(disp_refr->act_scr);
                    layout_update_core
                        lv_obj_refr_size
      我们调用 lv_obj_get_width 和 lv_obj_get_height 获取的是根据组件的实际区域大小计算后的数值。
      所以，我们在set size之后马上get_xx获取到的值是0或者不是最新的值。 
    */
    LV_LOG_USER("arc w:%d, arc h:%d\n", lv_obj_get_width(arc), lv_obj_get_height(arc));

#if 0
    /* 如果我们在某一时刻设置了对象的size之后，想马上就获取他当前设置的最新值，可以像下面这样操作 */
    // 给arc设置新的大小(宽、高)
    lv_obj_set_size(arc, 300, 300);
    // 如果想马上获取最新的值，可以通过这两个函数刷新arc的状态
    lv_obj_refr_size(arc);
    //lv_obj_update_layout(lv_scr_act());  // 这个函数中其实调用的是 lv_obj_refr_size
    
    // 假设在lvgl的任务管理器运行了起码一个周期的时候，假设arc之前的的宽高为 200*200，
    // 如果没有先运行上面两个函数，马上就获取宽高，这时候你获取到的是之前的数值： 200*200，
    // 因为arc还没有刷新，它的宽高样式属性还没有计算出来。
    LV_LOG_USER("arc refr w:%d, arc refr h:%d\n", lv_obj_get_width(arc), lv_obj_get_height(arc));
#endif

#if 0
    /* Ooooops!!! */
    // 通过异步调获取不到arc的最新宽高数值
    // 这里会在下一个 lv_task_handler() 的时候第一时间调用(如果后面没有其他异步调用函数插入进来)我们的回调函数 get_obj_size
    // 但是我们是在这个 lv_task_handler() 设置的 size ，这需要在下一个 lv_task_handler() 计算后才会是最新的数值。
    lv_obj_set_size(arc, 400, 400);
    lv_async_call(get_obj_size, arc);
#endif

}


/**********************
 *   STATIC FUNCTIONS
 **********************/


static void get_obj_size(void * scr)
{
  lv_obj_t * obj = (lv_obj_t *)scr;

  LV_LOG_USER("obj w:%d, obj h:%d\n", lv_obj_get_width(obj), lv_obj_get_height(obj));
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_11_2 */
