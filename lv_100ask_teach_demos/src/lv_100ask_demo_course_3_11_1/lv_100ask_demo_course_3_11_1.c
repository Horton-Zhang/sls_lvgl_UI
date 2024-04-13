/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_11_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-06-15
 * @brief	3_11_1 课的课堂代码
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

#if LV_USE_100ASK_DEMO_COURSE_3_11_1

#include "lv_100ask_demo_course_3_11_1.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/
lv_obj_t * arc;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_timer1(lv_timer_t * timer);
static void my_timer2(lv_timer_t * timer);
static void my_timer3(lv_timer_t * timer);
static void btn_event_handler(lv_event_t * e);
static void del_obj_async_call_cb(void * scr);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_11_1(void)
{
  /* 创建一个arc组件，稍后我们会对其进行试验 */
  arc = lv_arc_create(lv_scr_act());
  lv_arc_set_rotation(arc, 270);
  lv_arc_set_bg_angles(arc, 0, 360);
  lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
  lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);  /*To not allow adjusting by click*/
  lv_obj_center(arc);

  /*
    下面创建三个timer，最后创建的timer会被放在timer list的最前面，
    lvgl的任务处理器会从timer list从头到尾按顺序遍历检查，执行满足执行条件的timer。
    因此，如果三个定时器的周期设置一样的话，那么最后创建的timer会先执行。
  */
  lv_timer_t * timer;
#if 1  
  /* 创建第一个timer */
  timer = lv_timer_create(my_timer1, 500,  NULL);
	
  //lv_timer_set_cb(timer, my_timer1);
	//lv_timer_set_period(timer, 100);

  // 设置此timer的运行次数，设置后该timer在执行指定次数后会自动删除
  // 设置为 -1 就是无限重复，默认值就是 -1
  //lv_timer_set_repeat_count(timer, 3);

  // 让此timer在下一次调用 lv_timer_handler() 时运行
  // 也就是会马上运行，而不是等过了给定的第一个周期过了之后才运行。
  // 与它相反的是：lv_timer_reset(timer) 其会重置定时器的周期，
  // 这样定时器将在我们设置的毫秒时间段过去后再调用。
  lv_timer_ready(timer);
  //lv_timer_reset(timer);
#endif

#if 1
  /* 创建第二个timer */
  timer = lv_timer_create(my_timer2, 500,  NULL);
  
  // 修改此timer的回调函数和周期时间
	//lv_timer_set_cb(timer, my_timer2);
	//lv_timer_set_period(timer, 100);

  // 设置此timer的运行次数，设置后该timer在执行指定次数后会自动删除
  // 设置为 -1 就是无限重复，默认值就是 -1
  //lv_timer_set_repeat_count(timer, 3);

  // 让此timer在下一次调用 lv_timer_handler() 时运行
  // 也就是会马上运行，而不是等过了给定的第一个周期过了之后才运行。
  // 与它相反的是：lv_timer_reset(timer) 其会重置定时器的周期，
  // 这样定时器将在我们设置的毫秒时间段过去后再调用。
  lv_timer_ready(timer);
  //lv_timer_reset(timer);
#endif

#if 1 
  /* 通过另一个接口创建第三个timer */
	timer = lv_timer_create_basic();

  // 修改此timer的回调函数和周期时间
	lv_timer_set_cb(timer, my_timer3);
  lv_timer_set_period(timer, 100);

  // 设置此timer的运行次数，设置后该timer在执行指定次数后会自动删除
  // 设置为 -1 就是无限重复，默认值就是 -1
  //lv_timer_set_repeat_count(timer, 3);

  // 让此timer在下一次调用 lv_timer_handler() 时运行
  // 也就是会马上运行，而不是等过了给定的第一个周期过了之后才运行。
  // 与它相反的是：lv_timer_reset(timer) 其会重置定时器的周期，
  // 这样定时器将在我们设置的毫秒时间段过去后再调用。
  lv_timer_ready(timer);
  //lv_timer_reset(timer);
#endif

#if 1
  /* 创建一个按钮 */
  lv_obj_t * btn = lv_btn_create(lv_scr_act());
  lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
  
  // 在事件处理回调函数中我们会进行两个试验：
  // 1.点击按钮暂停或继续，上面的第三个timer
  lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, timer);
  lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
#endif

}


/**********************
 *   STATIC FUNCTIONS
 **********************/
 static void my_timer1(lv_timer_t * timer)
{
  /*获取并打印lvgl任务处理器(定时器)的空闲百分比时间*/
  LV_LOG_USER("my_timer1: timer idle %d\n", lv_timer_get_idle());
  /*如果我们只创建一个定时器，并且该定时器调用的是此函数，并且定时器执行周期是500ms，那么：*/
  //usleep(500000); // 定时器的空闲百分比接近 0%
  //usleep(250000); // 定时器的空闲百分比接近 50%
  //usleep(125000); // 定时器的空闲百分比接近 75%
  //usleep(0);      // 定时器的空闲百分比接近 100%
}

static void my_timer2(lv_timer_t * timer)
{
  /*获取并测量并打印lvgl任务处理器(定时器)的空闲百分比时间*/
  LV_LOG_USER("my_timer2: timer idle %d\n", lv_timer_get_idle());
}


static void my_timer3(lv_timer_t * timer)
{
  // 这里不使用NULL判断，如果我们free了arc但是并没有赋值为NULL的时候，
  // 在这里用NULL判断就会出错，通过 lv_obj_check_type 是更好的方法
  if (lv_obj_check_type(arc, &lv_arc_class)) {
    /*每次运行周期都将arc的值+1，
      其中，当arc的值大于所设置的最大值时(默认是100)，
      将arc的值设为所设置的最小值(默认是0)
    */
    if (lv_arc_get_value(arc) >= lv_arc_get_max_value(arc)) {
      lv_arc_set_value(arc, lv_arc_get_min_value(arc));
    }
    else {
      lv_arc_set_value(arc, lv_arc_get_value(arc)+1);
    }
  }
}


static void btn_event_handler(lv_event_t * e)
{
  lv_obj_t *btn = lv_event_get_target(e);
  lv_event_code_t code = lv_event_get_code(e);
  lv_timer_t * timer3 = (lv_timer_t *)lv_event_get_user_data(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
    LV_LOG_USER("Toggled");
    // 这里不使用NULL判断，如果我们free了arc但是并没有赋值为NULL的时候，
    // 在这里用NULL判断就会出错，通过 lv_obj_check_type 是更好的方法
    if (lv_obj_check_type(arc, &lv_arc_class)) {
#if 1
      /*测试1：点击反转第三个timer的状态：暂停、继续*/
      if(lv_obj_has_state(btn, LV_STATE_CHECKED)) {
        LV_LOG_USER("CHECKED!");
        lv_timer_pause(timer3);
      }
      else{
        LV_LOG_USER("UNCHECKED!");
        lv_timer_resume(timer3);
      }
#else
      /*测试2：通过异步调用删除arc*/  
      // 通常情况下，我们可以通过调用 lv_obj_del 当场直接删除对象
      // 但是有些情况我们不能马上删除该对象，
      // 我们可以在下次运行lv_task_handler()时，第一时间(最高优先级)在进行删除

      /* 异步删除对象有两个接口 */
      // 这个是lvgl提供的接口函数，我们只能传入想要删除的对象，该函数只能执行删除操作，
      // 因为它最终也只是调用了 lv_obj_del，仅此而已。
      // 所以我们想在下次运行lv_task_handler()时删除一个对象(及其所有后代)时，可以使用下面的这个函数
      lv_obj_del_async(arc);

      // 通过这个接口函数，我们可以传入自己的操作函数，除了删除操作之外还可以进行其他LVGL的相关操作
      //lv_async_call(del_obj_async_call_cb, arc);
#endif
    }
  }
}


static void del_obj_async_call_cb(void * scr)
{
  /* 这会在下次运行 lv_task_handler() 时，第一时间(最高优先级)得到运行 */
  /* 在这里除了删除操作，还能进行其他操作 */
  // You can do something here with LVGL...

  lv_obj_del(arc);
  arc = NULL;
}

#endif /* LV_USE_100ASK_DEMO_COURSE_3_11_1 */
