#include "mygui.h"
#include "lvgl.h"

void mygui()
{
    //Learn_Obj();
    //Learn_Arc();
    //Learn_Animimg();
    //Learn_Bar();
    //int bc = 25;
    //Disp_Battery(bc);
    //Temp_Bar();
    //lv_bar_4();
    lv_bar_6();
}

/* Make Object Draggable */
static void drag_event_handler(lv_event_t* e)  // 静态函数仅在当前文件中可见，其他文件不可引用该函数
{
    lv_obj_t* obj = lv_event_get_target(e);     // 获取传入的事件，将其作为一个obj

    lv_indev_t* indev = lv_indev_get_act();     // 定义 input device 对象
    if (indev == NULL) return;

    lv_point_t vect;                            // 定义 点 变量
    lv_indev_get_vect(indev, &vect);            // 把输入设备中获取到的 x，y 值同步给vect

    lv_coord_t x = lv_obj_get_x(obj) + vect.x;  // 更新 x 坐标
    lv_coord_t y = lv_obj_get_y(obj) + vect.y;  // 更新 y 坐标
    lv_obj_set_pos(obj, x,y);                   // 重新设置对象的位置
}

void Learn_Obj()
{
    lv_obj_t* ParentObj = lv_obj_create(lv_scr_act());  // Create ParentObj
    lv_obj_set_size(ParentObj, 500, 500);               // Set obj size
    lv_obj_align(ParentObj, LV_ALIGN_CENTER, 0, 0);     // Set obj align

    lv_obj_t* ChildObj = lv_obj_create(ParentObj);      // Create ChildObj based on ParentObj
    lv_obj_set_size(ChildObj, 200, 100);                // Set ChildObj size
//    lv_obj_align(ChildObj, LV_ALIGN_TOP_MID, 0, 0);      // Set ChildObj pos
    lv_obj_t * label = lv_label_create(ChildObj);       // 在 ChildObj 对象里创建标签子对象
    lv_label_set_text(label, "Drag me");                // 标签显示 Drag me 字样
    lv_obj_center(label);                               // 设置标签居中


    /* Learn to add style */
    static lv_style_t MyStyle;  // 创建对象不能是指针的形式
    lv_style_init(&MyStyle);
    lv_style_set_shadow_width(&MyStyle, 10);
    lv_style_set_shadow_spread(&MyStyle, 5);
    lv_style_set_shadow_color(&MyStyle, lv_palette_main(LV_PALETTE_RED));

    lv_obj_add_style(ChildObj, &MyStyle, 0);

    lv_obj_add_event_cb(ChildObj, drag_event_handler, LV_EVENT_PRESSING, NULL);
}

void Learn_Arc()
{
    lv_obj_t* arc = lv_arc_create(lv_scr_act());    // 创建 arc 对象
    lv_obj_set_size(arc, 300, 300);                 // 设置 arc 的大小
    lv_obj_set_align(arc, LV_ALIGN_CENTER);         // 设置 arc 对齐在中央

    lv_arc_set_range(arc, 0, 100);                  // 设置 arc 指示的值范围
    lv_arc_set_value(arc, 35);

    lv_arc_set_bg_angles(arc, 120, 60);              // 设置 arc 的角度
}

void Learn_Animimg()
{
    LV_IMG_DECLARE(animimg001)
    LV_IMG_DECLARE(animimg002)
    LV_IMG_DECLARE(animimg003)

    static const lv_img_dsc_t * anim_imgs[3] = {
        &animimg001,
        &animimg002,
        &animimg003,
    };


    lv_obj_t * animimg0 = lv_animimg_create(lv_scr_act());
    lv_obj_center(animimg0);
    lv_animimg_set_src(animimg0, (const void **) anim_imgs, 3);
    lv_animimg_set_duration(animimg0, 1000);
    lv_animimg_set_repeat_count(animimg0, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(animimg0);

}

void Learn_Bar()
{
    /************ 自定义 style1 ************/
    static lv_style_t bg_style;     // 定义背景风格
    static lv_style_t indic_style;  // 定义指示器风格

    // 初始化背景风格
    lv_style_init (&bg_style);
    lv_style_set_border_color (&bg_style, lv_palette_main(LV_PALETTE_GREEN));// 设置背景的颜色
    lv_style_set_border_width (&bg_style, 3);   // 边界线条的宽度
    lv_style_set_pad_all(&bg_style, 6);         // 让上下左右边界都缩小6个像素？
    lv_style_set_radius(&bg_style, 16);          // 两端是弧度
    lv_style_set_anim_time(&bg_style, 2000);    // 动画时间间隔，让进度条有动画

    // 初始化指示器风格
    lv_style_init(&indic_style);
    lv_style_set_bg_opa(&indic_style, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style, 16);

    // 把自定义风格应用到新建的 bar1 上
    lv_obj_t* bar1 = lv_bar_create(lv_scr_act());    // 创建 bar 对象
    lv_obj_remove_style_all(bar1);
    lv_obj_add_style(bar1, &bg_style, LV_PART_MAIN);
    lv_obj_add_style(bar1, &indic_style, LV_PART_INDICATOR);
    lv_obj_set_size(bar1, 250, 60);                  // 设置 bar 大小
    lv_obj_align(bar1, LV_ALIGN_LEFT_MID, 100, 0);   // 设置 bar 位置
    lv_bar_set_value(bar1, 30, LV_ANIM_ON);          // 设置初始值


    /*********** 自定义 style2 ***********/
    static lv_style_t bg_style2;     // 定义背景风格
    static lv_style_t indic_style2;  // 定义指示器风格

    // 初始化背景风格
    lv_style_init (&bg_style2);
    lv_style_set_border_color (&bg_style2, lv_palette_main(LV_PALETTE_GREEN));// 设置背景的颜色
    lv_style_set_border_width (&bg_style2, 3);   // 边界线条的宽度
    lv_style_set_pad_all(&bg_style2, 16);        // 让上下左右边界都缩小16个像素
    lv_style_set_radius(&bg_style2, 26);         // 两端弧度
    lv_style_set_anim_time(&bg_style2, 2000);    // 动画时间间隔，让进度条有动画

    // 初始化指示器风格
    lv_style_init(&indic_style2);
    lv_style_set_bg_opa(&indic_style2, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style2, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style2, 3);

    // 把自定义风格应用到新建的 bar2 上
    lv_obj_t * bar2 = lv_bar_create(lv_scr_act());
    lv_obj_remove_style_all(bar2);  /*To have a clean start*/
    lv_obj_add_style(bar2, &bg_style2, LV_PART_MAIN);
    lv_obj_add_style(bar2, &indic_style2, LV_PART_INDICATOR);
    lv_obj_set_size(bar2, 250, 60);
    lv_obj_align(bar2, LV_ALIGN_RIGHT_MID, -100, 0);
    lv_bar_set_value(bar2, 30, LV_ANIM_ON);
}

void Disp_Battery(int battery_capacity)
{
    /********** 画电池主干 **********/

    // 1. 创建 style
    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_border_color(&bg_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_width (&bg_style, 3);   // 边界线条的宽度
    lv_style_set_pad_all(&bg_style, 7);         // 让上下左右边界都缩小6个像素？
    lv_style_set_radius(&bg_style, 20);         // 两端是弧度
    lv_style_set_anim_time(&bg_style, 2000);    // 动画时间间隔，让进度条有动画

    static lv_style_t indic_style;
    lv_style_init(&indic_style);
    lv_style_set_bg_opa(&indic_style, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style, 20);

    // 2. 创建 bar 对象
    lv_obj_t * bar = lv_bar_create(lv_scr_act());
    lv_obj_remove_style_all(bar);
    lv_obj_add_style(bar, &bg_style, LV_PART_MAIN);
    lv_obj_add_style(bar, &indic_style, LV_PART_INDICATOR);
    lv_obj_set_size(bar, 250, 80);
    lv_obj_align(bar, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_value(bar, battery_capacity, LV_ANIM_ON);

    /********** 画电池正极 **********/

    // 1. 创建 style
    static lv_style_t little_style;
    lv_style_init(&little_style);
    lv_style_set_bg_color(&little_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_color(&little_style, lv_palette_main(LV_PALETTE_GREEN));

    // 2. 创建 bar 对象
    lv_obj_t* head = lv_bar_create(lv_scr_act());
    lv_obj_add_style(head, &little_style, LV_PART_INDICATOR);
    lv_obj_set_size(head, 10, 40);
    lv_bar_set_value(head, 100, LV_ANIM_OFF);
    lv_obj_align(head, LV_ALIGN_CENTER, 128, 0);
}


static void set_temp(void * bar, int32_t temp)
{
        lv_bar_set_value(bar, temp, LV_ANIM_ON);
}

void Temp_Bar()
{
    static lv_style_t style_indic;

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_VER);

    lv_obj_t * bar = lv_bar_create(lv_scr_act());
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
    lv_obj_set_size(bar, 20, 200);
    lv_obj_center(bar);
    lv_bar_set_range(bar, -20, 40);

    lv_anim_t a;    // 定义动画对象
    lv_anim_init(&a);// 初始化对象
    lv_anim_set_exec_cb(&a, set_temp);// 绑定动画对象和处理函数
    lv_anim_set_time(&a, 3000); // 设置正向执行用时ms
    lv_anim_set_playback_time(&a, 3000);// 设置反向执行用时ms
    lv_anim_set_var(&a, bar);   // 动画作用在 bar 控件上
    lv_anim_set_values(&a, -20, 40);// 动画取值范围
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);// 设置动画无限重复
    lv_anim_start(&a);  // 动画开始
}

void lv_bar_4()
{
    LV_IMG_DECLARE(img_skew_strip);
    static lv_style_t style_indic;

    lv_style_init(&style_indic);
    lv_style_set_bg_img_src(&style_indic, &img_skew_strip);
    lv_style_set_bg_img_tiled(&style_indic, true);
    lv_style_set_bg_img_opa(&style_indic, LV_OPA_30);

    lv_obj_t * bar = lv_bar_create(lv_scr_act());
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

    lv_obj_set_size(bar, 260, 20);
    lv_obj_center(bar);
    lv_bar_set_mode(bar, LV_BAR_MODE_RANGE);
    lv_bar_set_value(bar, 90, LV_ANIM_ON);
    lv_bar_set_start_value(bar, 20, LV_ANIM_ON);
}

static void set_value(void * bar, int32_t v)
{
    lv_bar_set_value(bar, v, LV_ANIM_OFF);
}

static void event_cb(lv_event_t* e) // 该函数改变标签的【数值】和【位置】
{
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);// 获取传入事件的描述符
    if(dsc->part != LV_PART_INDICATOR) return;  // 若不是indicator触发的事件则返回

    lv_obj_t * obj = lv_event_get_target(e);    // 获取传入对象

    lv_draw_label_dsc_t label_dsc;      // 创建 标签描述符对象
    lv_draw_label_dsc_init(&label_dsc); // 初始化 描述符对象
    label_dsc.font = LV_FONT_DEFAULT;   // 设置标签为默认字体

    char buf[8];    // 开辟一段内存空间

    lv_snprintf(buf, sizeof(buf), "%d", (int)lv_bar_get_value(obj));
    /* 上一行的内容把obj的值格式化写入buf中 */

    lv_point_t txt_size;
    lv_txt_get_size(&txt_size, buf,
                    label_dsc.font,
                    label_dsc.letter_space,
                    label_dsc.line_space,
                    LV_COORD_MAX,
                    label_dsc.flag);// 获取字体参数写入到 txt_size 中

    lv_area_t txt_area; // 定义对象，以下代码做 位置、大小 判断
    /*If the indicator is long enough put the text inside on the right*/
    if(lv_area_get_width(dsc->draw_area) > txt_size.x + 20) {
        txt_area.x2 = dsc->draw_area->x2 - 5;
        txt_area.x1 = txt_area.x2 - txt_size.x + 1;
        label_dsc.color = lv_color_white();
    }
    /*If the indicator is still short put the text out of it on the right*/
    else {
        txt_area.x1 = dsc->draw_area->x2 + 5;
        txt_area.x2 = txt_area.x1 + txt_size.x - 1;
        label_dsc.color = lv_color_black();
    }

    txt_area.y1 = dsc->draw_area->y1 + (lv_area_get_height(dsc->draw_area) - txt_size.y) / 2;
    txt_area.y2 = txt_area.y1 + txt_size.y - 1;

    lv_draw_label(dsc->draw_ctx, &label_dsc, &txt_area, buf, NULL);
}

/**
 * Custom drawer on the bar to display the current value
 */
void lv_bar_6()
{
    lv_obj_t * bar = lv_bar_create(lv_scr_act());
    lv_obj_add_event_cb(bar, event_cb, LV_EVENT_DRAW_PART_END, NULL);// 添加事件
    lv_obj_set_size(bar, 200, 20);// 控件大小
    lv_obj_center(bar);// 控件位置居中

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, bar);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_exec_cb(&a, set_value); // 设置新的值
    lv_anim_set_time(&a, 2000);
    lv_anim_set_playback_time(&a, 2000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);
}

