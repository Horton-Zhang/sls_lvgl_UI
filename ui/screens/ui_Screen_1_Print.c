// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: 3d_printer

#include "../ui.h"

void ui_Screen_1_Print_screen_init(void)
{
    ui_Screen_1_Print = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_Screen_1_Print, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_1_Print, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Background = lv_img_create(ui_Screen_1_Print);
    lv_img_set_src(ui_Background, &ui_img_3d_printer_bg_png);
    lv_obj_set_width(ui_Background, 800);
    lv_obj_set_height(ui_Background, 480);
    lv_obj_set_align(ui_Background, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Background, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_Panel_Header = lv_obj_create(ui_Screen_1_Print);
    lv_obj_set_width(ui_Panel_Header, 665);
    lv_obj_set_height(ui_Panel_Header, 39);
    lv_obj_set_x(ui_Panel_Header, -30);
    lv_obj_set_y(ui_Panel_Header, 0);
    lv_obj_set_align(ui_Panel_Header, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Panel_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel_Header, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Header = lv_label_create(ui_Panel_Header);
    lv_obj_set_width(ui_Label_Header, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Header, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Header, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Header, "The #ffffff squareline.gcode# word file is being printed");
    lv_label_set_recolor(ui_Label_Header, "true");
    lv_obj_set_style_text_color(ui_Label_Header, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Header, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IMG_Wifi = lv_img_create(ui_Panel_Header);
    lv_img_set_src(ui_IMG_Wifi, &ui_img_icn_wifi_png);
    lv_obj_set_width(ui_IMG_Wifi, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_Wifi, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_IMG_Wifi, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_IMG_Wifi, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_IMG_PC = lv_img_create(ui_Panel_Header);
    lv_img_set_src(ui_IMG_PC, &ui_img_icn_pc_png);
    lv_obj_set_width(ui_IMG_PC, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_PC, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_PC, -42);
    lv_obj_set_y(ui_IMG_PC, 0);
    lv_obj_set_align(ui_IMG_PC, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_IMG_PC, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_IMG_USB = lv_img_create(ui_Panel_Header);
    lv_img_set_src(ui_IMG_USB, &ui_img_icn_usb_png);
    lv_obj_set_width(ui_IMG_USB, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_USB, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_USB, -84);
    lv_obj_set_y(ui_IMG_USB, 0);
    lv_obj_set_align(ui_IMG_USB, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_IMG_USB, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_BTN_Menu_Print_S1 = lv_img_create(ui_Screen_1_Print);
    lv_img_set_src(ui_BTN_Menu_Print_S1, &ui_img_btn_print_png);
    lv_obj_set_width(ui_BTN_Menu_Print_S1, 79);
    lv_obj_set_height(ui_BTN_Menu_Print_S1, 160);
    lv_obj_add_flag(ui_BTN_Menu_Print_S1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BTN_Menu_Print_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BTN_Menu_Move_S1 = lv_img_create(ui_Screen_1_Print);
    lv_img_set_src(ui_BTN_Menu_Move_S1, &ui_img_btn_move_png);
    lv_obj_set_width(ui_BTN_Menu_Move_S1, 79);
    lv_obj_set_height(ui_BTN_Menu_Move_S1, 162);
    lv_obj_set_align(ui_BTN_Menu_Move_S1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_BTN_Menu_Move_S1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BTN_Menu_Move_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_BTN_Menu_Move_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BTN_Menu_Setting_S1 = lv_img_create(ui_Screen_1_Print);
    lv_img_set_src(ui_BTN_Menu_Setting_S1, &ui_img_btn_setting_png);
    lv_obj_set_width(ui_BTN_Menu_Setting_S1, 79);
    lv_obj_set_height(ui_BTN_Menu_Setting_S1, 160);
    lv_obj_set_align(ui_BTN_Menu_Setting_S1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_BTN_Menu_Setting_S1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BTN_Menu_Setting_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_BTN_Menu_Setting_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_S1_Content_Panel = lv_obj_create(ui_Screen_1_Print);
    lv_obj_set_width(ui_S1_Content_Panel, 720);
    lv_obj_set_height(ui_S1_Content_Panel, 430);
    lv_obj_set_align(ui_S1_Content_Panel, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_S1_Content_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_S1_Content_Panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_S1_Content_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_S1_Content_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Slider_Print_View = lv_slider_create(ui_S1_Content_Panel);
    lv_slider_set_value(ui_Slider_Print_View, 70, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider_Print_View) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider_Print_View, 0,
                                                                                                      LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider_Print_View, 332);
    lv_obj_set_height(ui_Slider_Print_View, 396);
    lv_obj_set_x(ui_Slider_Print_View, 0);
    lv_obj_set_y(ui_Slider_Print_View, -10);
    lv_obj_set_align(ui_Slider_Print_View, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_radius(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider_Print_View, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider_Print_View, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider_Print_View, &ui_img_print_view_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider_Print_View, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider_Print_View, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider_Print_View, &ui_img_print_view_front_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider_Print_View, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider_Print_View, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Number_Print = lv_label_create(ui_Slider_Print_View);
    lv_obj_set_width(ui_Number_Print, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Number_Print, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Number_Print, 0);
    lv_obj_set_y(ui_Number_Print, -40);
    lv_obj_set_align(ui_Number_Print, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Number_Print, "70%");
    lv_obj_set_style_text_color(ui_Number_Print, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Number_Print, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Number_Print, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Display_Time_S1 = lv_obj_create(ui_S1_Content_Panel);
    lv_obj_set_width(ui_Display_Time_S1, 350);
    lv_obj_set_height(ui_Display_Time_S1, 79);
    lv_obj_set_x(ui_Display_Time_S1, -26);
    lv_obj_set_y(ui_Display_Time_S1, 30);
    lv_obj_set_align(ui_Display_Time_S1, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Display_Time_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Display_Time_S1, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Display_Time_S1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Display_Time_S1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Display_Time_S1, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Display_Time_S1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Display_Time_S1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Display_Time_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DT1 = lv_obj_create(ui_Display_Time_S1);
    lv_obj_set_width(ui_DT1, lv_pct(50));
    lv_obj_set_height(ui_DT1, lv_pct(100));
    lv_obj_set_align(ui_DT1, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_DT1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DT1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DT1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_DT1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_DT1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DT1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DT1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DT1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DT1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DT1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Time_1 = lv_label_create(ui_DT1);
    lv_obj_set_width(ui_Label_Printing_Time_1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Time_1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Printing_Time_1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label_Printing_Time_1, "Printing Time");
    lv_label_set_recolor(ui_Label_Printing_Time_1, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Time_1, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Time_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Time_1, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IMG_Tine_1 = lv_img_create(ui_DT1);
    lv_img_set_src(ui_IMG_Tine_1, &ui_img_icn_time_1_png);
    lv_obj_set_width(ui_IMG_Tine_1, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_Tine_1, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_Tine_1, 20);
    lv_obj_set_y(ui_IMG_Tine_1, 10);
    lv_obj_set_align(ui_IMG_Tine_1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_IMG_Tine_1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_Label_Time_1 = lv_label_create(ui_DT1);
    lv_obj_set_width(ui_Label_Time_1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Time_1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Time_1, 60);
    lv_obj_set_y(ui_Label_Time_1, 10);
    lv_obj_set_align(ui_Label_Time_1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Time_1, "10:52");
    lv_obj_set_style_text_color(ui_Label_Time_1, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Time_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Time_1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_Display_Time_S1);
    lv_obj_set_width(ui_Panel3, 2);
    lv_obj_set_height(ui_Panel3, 50);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x3A3F4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DT2 = lv_obj_create(ui_Display_Time_S1);
    lv_obj_set_width(ui_DT2, lv_pct(50));
    lv_obj_set_height(ui_DT2, lv_pct(100));
    lv_obj_set_align(ui_DT2, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_DT2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DT2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DT2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_DT2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_DT2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DT2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DT2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DT2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DT2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DT2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Time_2 = lv_label_create(ui_DT2);
    lv_obj_set_width(ui_Label_Printing_Time_2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Time_2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Printing_Time_2, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label_Printing_Time_2, "Printing Time");
    lv_label_set_recolor(ui_Label_Printing_Time_2, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Time_2, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Time_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Time_2, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IMG_Tine_2 = lv_img_create(ui_DT2);
    lv_img_set_src(ui_IMG_Tine_2, &ui_img_icn_time_2_png);
    lv_obj_set_width(ui_IMG_Tine_2, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_Tine_2, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_Tine_2, 20);
    lv_obj_set_y(ui_IMG_Tine_2, 10);
    lv_obj_set_align(ui_IMG_Tine_2, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_IMG_Tine_2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_Label_Time_2 = lv_label_create(ui_DT2);
    lv_obj_set_width(ui_Label_Time_2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Time_2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Time_2, 60);
    lv_obj_set_y(ui_Label_Time_2, 10);
    lv_obj_set_align(ui_Label_Time_2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Time_2, "08:25");
    lv_obj_set_style_text_color(ui_Label_Time_2, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Time_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Time_2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Display_Heat_S1 = lv_obj_create(ui_S1_Content_Panel);
    lv_obj_set_width(ui_Display_Heat_S1, 350);
    lv_obj_set_height(ui_Display_Heat_S1, 79);
    lv_obj_set_x(ui_Display_Heat_S1, -26);
    lv_obj_set_y(ui_Display_Heat_S1, 130);
    lv_obj_set_align(ui_Display_Heat_S1, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Display_Heat_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Display_Heat_S1, lv_color_hex(0x191D26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Display_Heat_S1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Display_Heat_S1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Display_Heat_S1, lv_color_hex(0x414B62), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Display_Heat_S1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Display_Heat_S1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Display_Heat_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DT3 = lv_obj_create(ui_Display_Heat_S1);
    lv_obj_set_width(ui_DT3, lv_pct(50));
    lv_obj_set_height(ui_DT3, lv_pct(100));
    lv_obj_set_align(ui_DT3, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_DT3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DT3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DT3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_DT3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_DT3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DT3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DT3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DT3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DT3, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DT3, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Head_Temp = lv_label_create(ui_DT3);
    lv_obj_set_width(ui_Label_Printing_Head_Temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Head_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Printing_Head_Temp, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label_Printing_Head_Temp, "Head Temp.");
    lv_label_set_recolor(ui_Label_Printing_Head_Temp, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Head_Temp, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Head_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Head_Temp, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IMG_Head = lv_img_create(ui_DT3);
    lv_img_set_src(ui_IMG_Head, &ui_img_icn_head_png);
    lv_obj_set_width(ui_IMG_Head, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_Head, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_Head, 15);
    lv_obj_set_y(ui_IMG_Head, 10);
    lv_obj_set_align(ui_IMG_Head, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_IMG_Head, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_Label_Head_Temp = lv_label_create(ui_DT3);
    lv_obj_set_width(ui_Label_Head_Temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Head_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Head_Temp, 40);
    lv_obj_set_y(ui_Label_Head_Temp, 10);
    lv_obj_set_align(ui_Label_Head_Temp, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Head_Temp, "195°");
    lv_obj_set_style_text_color(ui_Label_Head_Temp, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Head_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Head_Temp, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Head_Temp_2 = lv_label_create(ui_DT3);
    lv_obj_set_width(ui_Label_Printing_Head_Temp_2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Head_Temp_2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Printing_Head_Temp_2, 95);
    lv_obj_set_y(ui_Label_Printing_Head_Temp_2, 13);
    lv_obj_set_align(ui_Label_Printing_Head_Temp_2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Printing_Head_Temp_2, "/ 195°");
    lv_label_set_recolor(ui_Label_Printing_Head_Temp_2, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Head_Temp_2, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Head_Temp_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Head_Temp_2, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Display_Heat_S1);
    lv_obj_set_width(ui_Panel1, 2);
    lv_obj_set_height(ui_Panel1, 50);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x3A3F4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DT3_copy = lv_obj_create(ui_Display_Heat_S1);
    lv_obj_set_width(ui_DT3_copy, lv_pct(50));
    lv_obj_set_height(ui_DT3_copy, lv_pct(100));
    lv_obj_set_align(ui_DT3_copy, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_DT3_copy, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DT3_copy, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DT3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_DT3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_DT3_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DT3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_DT3_copy, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_DT3_copy, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_DT3_copy, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_DT3_copy, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Bed_Temp = lv_label_create(ui_DT3_copy);
    lv_obj_set_width(ui_Label_Printing_Bed_Temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Bed_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Printing_Bed_Temp, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label_Printing_Bed_Temp, "Bed Temp.");
    lv_label_set_recolor(ui_Label_Printing_Bed_Temp, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Bed_Temp, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Bed_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Bed_Temp, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IMG_Head1 = lv_img_create(ui_DT3_copy);
    lv_img_set_src(ui_IMG_Head1, &ui_img_icn_bed_png);
    lv_obj_set_width(ui_IMG_Head1, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_IMG_Head1, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_IMG_Head1, 20);
    lv_obj_set_y(ui_IMG_Head1, 10);
    lv_obj_set_align(ui_IMG_Head1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_IMG_Head1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_Label_Bed_Temp = lv_label_create(ui_DT3_copy);
    lv_obj_set_width(ui_Label_Bed_Temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Bed_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Bed_Temp, 55);
    lv_obj_set_y(ui_Label_Bed_Temp, 10);
    lv_obj_set_align(ui_Label_Bed_Temp, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Bed_Temp, "65°");
    lv_obj_set_style_text_color(ui_Label_Bed_Temp, lv_color_hex(0xDBE6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Bed_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Bed_Temp, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Printing_Bed_Temp1 = lv_label_create(ui_DT3_copy);
    lv_obj_set_width(ui_Label_Printing_Bed_Temp1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Printing_Bed_Temp1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Printing_Bed_Temp1, 100);
    lv_obj_set_y(ui_Label_Printing_Bed_Temp1, 13);
    lv_obj_set_align(ui_Label_Printing_Bed_Temp1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Printing_Bed_Temp1, "/ 65°");
    lv_label_set_recolor(ui_Label_Printing_Bed_Temp1, "true");
    lv_obj_set_style_text_color(ui_Label_Printing_Bed_Temp1, lv_color_hex(0x9098AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Printing_Bed_Temp1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Printing_Bed_Temp1, &ui_font_Small_Font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel_Buttons_S1 = lv_obj_create(ui_S1_Content_Panel);
    lv_obj_set_width(ui_Panel_Buttons_S1, 380);
    lv_obj_set_height(ui_Panel_Buttons_S1, 200);
    lv_obj_set_align(ui_Panel_Buttons_S1, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_Panel_Buttons_S1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel_Buttons_S1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel_Buttons_S1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel_Buttons_S1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BTN_Pause = lv_img_create(ui_Panel_Buttons_S1);
    lv_img_set_src(ui_BTN_Pause, &ui_img_btn_print_down_png);
    lv_obj_set_width(ui_BTN_Pause, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_BTN_Pause, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_BTN_Pause, 10);
    lv_obj_set_y(ui_BTN_Pause, 0);
    lv_obj_set_align(ui_BTN_Pause, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_BTN_Pause, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_BTN_Pause_Top = lv_img_create(ui_BTN_Pause);
    lv_img_set_src(ui_BTN_Pause_Top, &ui_img_btn_print_top_off_png);
    lv_obj_set_width(ui_BTN_Pause_Top, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_BTN_Pause_Top, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_BTN_Pause_Top, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BTN_Pause_Top, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE |
                    LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_set_style_radius(ui_BTN_Pause_Top, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BTN_Pause_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui_BTN_Pause_Top, 9, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(ui_BTN_Pause_Top, 3, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_BTN_Pause_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_BTN_Pause_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_BTN_Pause_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Pause_Top, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_BTN_Pause_Top, lv_color_hex(0x67799B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BTN_Pause_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Image_Pause = lv_img_create(ui_BTN_Pause_Top);
    lv_img_set_src(ui_Image_Pause, &ui_img_icn_pause_png);
    lv_obj_set_width(ui_Image_Pause, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_Image_Pause, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Image_Pause, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image_Pause, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_set_style_img_recolor(ui_Image_Pause, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image_Pause, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BTN_Cancel = lv_img_create(ui_Panel_Buttons_S1);
    lv_img_set_src(ui_BTN_Cancel, &ui_img_btn_print_down_png);
    lv_obj_set_width(ui_BTN_Cancel, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_BTN_Cancel, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_BTN_Cancel, -30);
    lv_obj_set_y(ui_BTN_Cancel, 0);
    lv_obj_set_align(ui_BTN_Cancel, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_BTN_Cancel, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_BTN_Cancel_Top = lv_img_create(ui_BTN_Cancel);
    lv_img_set_src(ui_BTN_Cancel_Top, &ui_img_btn_print_top_off_png);
    lv_obj_set_width(ui_BTN_Cancel_Top, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_BTN_Cancel_Top, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_BTN_Cancel_Top, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BTN_Cancel_Top, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_set_style_radius(ui_BTN_Cancel_Top, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_BTN_Cancel_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui_BTN_Cancel_Top, 9, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(ui_BTN_Cancel_Top, 3, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_x(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_ofs_y(ui_BTN_Cancel_Top, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_color(ui_BTN_Cancel_Top, lv_color_hex(0x00D2FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_BTN_Cancel_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_BTN_Cancel_Top, 5, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor(ui_BTN_Cancel_Top, lv_color_hex(0x67799B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui_BTN_Cancel_Top, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Image_Cancel = lv_img_create(ui_BTN_Cancel_Top);
    lv_img_set_src(ui_Image_Cancel, &ui_img_icn_stop_png);
    lv_obj_set_width(ui_Image_Cancel, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_height(ui_Image_Cancel, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Image_Cancel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image_Cancel, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_set_style_img_recolor(ui_Image_Cancel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image_Cancel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_BTN_Menu_Move_S1, ui_event_BTN_Menu_Move_S1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BTN_Menu_Setting_S1, ui_event_BTN_Menu_Setting_S1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Slider_Print_View, ui_event_Slider_Print_View, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BTN_Cancel_Top, ui_event_BTN_Cancel_Top, LV_EVENT_ALL, NULL);

}
