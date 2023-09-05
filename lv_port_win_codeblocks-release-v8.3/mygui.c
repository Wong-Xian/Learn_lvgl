#include "mygui.h"
#include "lvgl.h"

void mygui()
{
    //Learn_Obj();
    //Learn_Arc();
    //Learn_Animimg();
    Learn_Bar();
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
    lv_obj_t* bar = lv_bar_create(lv_scr_act());    // 创建 bar 对象
    lv_obj_set_size(bar, 250, 60);                  // 设置 bar 大小
    lv_obj_align(bar, LV_ALIGN_LEFT_MID, 0, 0);     // 设置 bar 位置
    lv_bar_set_value(bar, 30, LV_ANIM_ON);          // 设置初始值

    // 自定义 style
    static lv_style_t bg_style;     // 定义背景风格
    static lv_style_t indic_style;  // 定义指示器风格

    // 初始化背景风格
    lv_style_init (&bg_style);
    lv_style_set_border_color (&bg_style, lv_palette_main(LV_PALETTE_GREEN));// 设置背景的颜色
    lv_style_set_border_width (&bg_style, 3);   // 边界线条的宽度
    lv_style_set_pad_all(&bg_style, 6);         // 让上下左右边界都缩小6个像素？
    lv_style_set_radius(&style_bg, 6);          // 模糊吗？
    lv_style_set_anim_time(&style_bg, 1000);    // 动画时间间隔

    //初始化指示器风格
    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&style_indic, 3);
}

