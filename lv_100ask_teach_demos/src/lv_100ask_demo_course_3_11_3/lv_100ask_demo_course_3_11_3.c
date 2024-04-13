/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_11_3.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-06-16
 * @brief	3_11_3 课的课堂代码
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2022-06-16     zhouyuebiao     First version
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

#if LV_USE_100ASK_DEMO_COURSE_3_11_3

#include "lv_100ask_demo_course_3_11_3.h"


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
static void get_obj_pos(void * scr);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_11_3(void)
{
    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_arc_set_value(arc, 50);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/

    /*
      我们这里给他设置的坐标只是设置了组件的样式坐标位置，还不是实际的坐标位置，
      实际的坐标位置在display的timer中再根据最新的pos样式进行计算：
        lv_disp_drv_register
            _lv_disp_refr_timer
                lv_obj_update_layout(disp_refr->act_scr);
                    layout_update_core
                        lv_obj_refr_pos
      我们调用 lv_obj_get_x 和 lv_obj_get_x 获取的是根据组件的实际坐标位置计算后的数值。
      并且由于我们所有组件的基类(lv_obj)在创建的时候，其pos(x1, y1)的初始值是[0,100],
      所以，我们在组件创建出来之后马上get_x/get_y获取到的值是[0,100]或者不是最新的值(即使你创建之后马上set pos，得到的仍然是[0,100])。
    */
    LV_LOG_USER("arc x:%d, arc y:%d\n", lv_obj_get_x(arc), lv_obj_get_y(arc));

#if 1
    /* 如果我们在某一时刻设置了对象的pos之后，想马上就获取他当前设置的最新值，可以像下面这样操作 */
    // 给arc设置新的坐标位置(x、y)
    lv_obj_set_pos(arc, 100, 200);
    // 如果想马上获取最新的值，可以通过这两个函数刷新arc的状态
    //lv_obj_refr_pos(arc);
    lv_obj_update_layout(lv_scr_act());  // 这个函数中其实调用的是 lv_obj_refr_pos

    // 假设在lvgl的任务管理器运行了起码一个周期的时候，假设arc之前的的位置为初始值 [0,100]，
    // 如果没有先运行上面两个函数，马上就获取宽高，这时候你获取到的是之前的数值： [0,100]，
    // 因为arc还没有刷新，得到的不是最新的坐标位置。
    LV_LOG_USER("arc refr x:%d, arc refr y:%d\n", lv_obj_get_x(arc), lv_obj_get_y(arc));

#endif

#if 0
    /* Ooooops!!! */
    // 通过异步调获取不到arc的最新宽高数值
    // 这里会在下一个 lv_task_handler() 周期的时候第一时间调用我们的回调函数 get_obj_pos (如果后面没有其他异步调用函数插入进来)
    // 但是我们是在这个 lv_task_handler() 周期设置的 pos ，这需要在下一个 lv_task_handler() 周期计算后才会是最新的数值。
    lv_obj_set_pos(arc, 400, 400);
    lv_async_call(get_obj_pos, arc);
#endif

}


/**********************
 *   STATIC FUNCTIONS
 **********************/


static void get_obj_pos(void * scr)
{
  lv_obj_t * obj = (lv_obj_t *)scr;

  LV_LOG_USER("obj x:%d, obj y:%d\n", lv_obj_get_x(obj), lv_obj_get_y(obj));
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_11_3 */
