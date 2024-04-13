#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "lv_100ask_teach_demos/lv_100ask_teach_demos.h"

#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define DISP_BUF_SIZE (128 * 1024)

int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 1024;
    disp_drv.ver_res    = 600;
    lv_disp_drv_register(&disp_drv);

    evdev_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);


    /*Set a cursor for the mouse*/
    LV_IMG_DECLARE(mouse_cursor_icon)
    lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/


    /*Create a Demo*/
    // lv_demo_widgets();
    // lv_demo_printer();

    /*Run the demo*/
    // lv_100ask_demo_course_2_1_1();      // 基础对象(lv_obj)，"Hello, LVGL!"
	// lv_100ask_demo_course_2_2_2();    // 基础对象的大小(size)
	//lv_100ask_demo_course_2_2_3();    // 基础对象的位置(position)
	//lv_100ask_demo_course_2_2_4();    // 基础对象的盒子模型(border-box)
	//lv_100ask_demo_course_2_2_5();    // 基础对象的样式(styles)
	//lv_100ask_demo_course_2_2_6();    // 基础对象的事件(events)、事件冒泡

	//lv_100ask_demo_course_3_1_1();    // 组件(widgets)： 标签(label)的用法
	//lv_100ask_demo_course_3_1_2();    // 组件(widgets)： 标签(label)，显示中文
	//lv_100ask_demo_course_3_2_1();    // 组件(widgets)： 按钮(lv_btn)的用法
	//lv_100ask_demo_course_3_3_1();    // 组件(widgets)： 使用物理按键代替触摸(groups)
	// lv_100ask_demo_course_3_4_1();    // 组件(widgets)： 开关(lv_switch)的用法
	//lv_100ask_demo_course_3_5_1();    // 组件(widgets)： 复选框(lv_checkbox)的用法
	//lv_100ask_demo_course_3_6_1();    // 组件(widgets)： 下拉列表(lv_dropdown))的用法
    
    /*OFF*/
	////lv_100ask_demo_course_3_7_1();    // 组件(widgets)： 滚轮(lv_roller)的用法
	
    //lv_100ask_demo_course_3_8_1();    // 组件(widgets)： 进度条(lv_bar)的用法
	//lv_100ask_demo_course_3_9_1();    // 组件(widgets)： 进度条(lv_slider)的用法
	//lv_100ask_demo_course_3_10_1();   // 组件(widgets)： 圆弧(lv_arc)的用法
	// lv_100ask_demo_course_3_10_3();   // 组件(widgets)： 圆弧(lv_arc)-综合实战
    //lv_100ask_demo_course_3_11_1();   // 定时器： 定时器(lv_timer)的用法
    //lv_100ask_demo_course_3_11_2();   // 为什么创建出来的组件获取到的宽高是0？(在学习2_2_2时遇到的问题)
    //lv_100ask_demo_course_3_11_3();   // 为什么创建出来的组件获取到的坐标不正确？(在学习2_2_3时遇到的问题)
    //lv_100ask_demo_course_3_12_1();   // 组件(widgets)： 线条(lv_line)的用法
    //lv_100ask_demo_course_3_12_2();   // 组件(widgets)： 线条(lv_line)实战
    ui_init();
    
    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
