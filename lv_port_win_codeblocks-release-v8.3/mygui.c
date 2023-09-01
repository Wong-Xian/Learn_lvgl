#include "mygui.h"
#include "lvgl.h"

void mygui()
{
    //Learn_Obj();
    Learn_Arc();
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

    lv_arc_set_bg_angles(arc, 0, 180);              // 设置 arc 的角度
}


