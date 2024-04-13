/**
 ******************************************************************************
 * @file    lv_100ask_demo_course_3_12_2.c
 * @author  百问科技
 * @version V1.0
 * @date    2022-06-16
 * @brief	3_12_2 课的课堂代码
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

#if LV_USE_100ASK_DEMO_COURSE_3_12_2

#include "lv_100ask_demo_course_3_12_2.h"


/*********************
 *      DEFINES
 *********************/
#define DISP_VER_RES  1024  /* 以屏幕宽度为x轴，每一个像素为一个整数点 */
#define SIN_POINT_MAX 600   /* 以屏幕高度为y轴，每一个像素为一个整数点 */
#define PI 3.1415926

/**********************
 *      TYPEDEFS
 **********************/


/**********************
 *  STATIC VARIABLES
 **********************/
/* 以屏幕宽度为x轴，每一个像素为一个整数点 */
static lv_point_t line_points[DISP_VER_RES] = { 0 };

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void sin_timer(lv_timer_t * timer);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_100ask_demo_course_3_12_2(void)
{
    /*初始化line组件的样式*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 8);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    //设置背景颜色
    //lv_style_set_bg_opa(&style_line, LV_OPA_100);
    //lv_style_set_bg_color(&style_line, lv_color_hex(0x78246a));

    /* 设置活动屏幕的背景颜色 */
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_100, 0);
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x1e1e1e), 0);

    /*创建line并应用上面初始化的样式*/
    lv_obj_t * line;
    line = lv_line_create(lv_scr_act());
    // 不用设置大小，line会自动根据points调整大小
    //lv_obj_set_size(line, 1024, 600);
    lv_obj_add_style(line, &style_line, 0);

    //lv_obj_align(line, LV_ALIGN_LEFT_MID, 0, 0);      // 从屏幕左边中间往屏幕右边中间刷新
    //lv_obj_align(line, LV_ALIGN_BOTTOM_LEFT, 0, 0);   // 从屏幕左边往屏幕右边刷新
    lv_obj_align(line, LV_ALIGN_BOTTOM_RIGHT, 0, 0);  // 从屏幕右边往屏幕左边刷新

	// 反转y轴
    lv_line_set_y_invert(line, true);

    /*
        创建一个定时器每隔5ms刷新一次
        这里要注意的是，虽然你设置的每隔5ms一次，
        但是实际最小的周期时间，受限于 lv_task_handler 的睡眠时间；
        所以，我们这里设置的是 5ms，但是实际上是 ≥10ms，因为我们的 lv_task_handler 睡眠时间是 10ms。
        也就说我们创建的定时器的运行周期不可能小于 lv_task_handler 的运行周期
    */
    lv_timer_t * timer = lv_timer_create(sin_timer, 5,  line);
}


/**********************
 *   STATIC FUNCTIONS
 **********************/

/* 通过sin()函数用角度计算出每个点的值 */
// 参考链接：https://juejin.cn/post/6966760481528905764
static void sin_timer(lv_timer_t * timer)
{
  /*Use the user_data*/
  lv_obj_t * line = timer->user_data;
  static uint16_t i = 0;
  uint16_t j = 0;
  float hd = 0.0;     //弧度
  float fz = 0.0;     //峰值

  j = SIN_POINT_MAX / 2;
  hd = PI / j;

  // 超出屏幕宽度？
  if (i >= DISP_VER_RES)  i = 0;

  fz = j * sin( hd * i ) + j;
  line_points[i].y = (uint16_t)fz;
  line_points[i].x = i;

  printf("[%d, %d]\n", line_points[i].x, line_points[i].y);
  lv_line_set_points(line, line_points, i);     /*Set the points*/

  i++;
}


#endif /* LV_USE_100ASK_DEMO_COURSE_3_12_2 */
