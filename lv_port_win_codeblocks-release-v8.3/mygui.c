#include "mygui.h"
#include "lvgl.h"

void mygui()
{
    //Learn_Obj();
    Learn_Arc();
}

/* Make Object Draggable */
static void drag_event_handler(lv_event_t* e)  // ��̬�������ڵ�ǰ�ļ��пɼ��������ļ��������øú���
{
    lv_obj_t* obj = lv_event_get_target(e);     // ��ȡ������¼���������Ϊһ��obj

    lv_indev_t* indev = lv_indev_get_act();     // ���� input device ����
    if (indev == NULL) return;

    lv_point_t vect;                            // ���� �� ����
    lv_indev_get_vect(indev, &vect);            // �������豸�л�ȡ���� x��y ֵͬ����vect

    lv_coord_t x = lv_obj_get_x(obj) + vect.x;  // ���� x ����
    lv_coord_t y = lv_obj_get_y(obj) + vect.y;  // ���� y ����
    lv_obj_set_pos(obj, x,y);                   // �������ö����λ��
}

void Learn_Obj()
{
    lv_obj_t* ParentObj = lv_obj_create(lv_scr_act());  // Create ParentObj
    lv_obj_set_size(ParentObj, 500, 500);               // Set obj size
    lv_obj_align(ParentObj, LV_ALIGN_CENTER, 0, 0);     // Set obj align

    lv_obj_t* ChildObj = lv_obj_create(ParentObj);      // Create ChildObj based on ParentObj
    lv_obj_set_size(ChildObj, 200, 100);                // Set ChildObj size
//    lv_obj_align(ChildObj, LV_ALIGN_TOP_MID, 0, 0);      // Set ChildObj pos
    lv_obj_t * label = lv_label_create(ChildObj);       // �� ChildObj �����ﴴ����ǩ�Ӷ���
    lv_label_set_text(label, "Drag me");                // ��ǩ��ʾ Drag me ����
    lv_obj_center(label);                               // ���ñ�ǩ����


    /* Learn to add style */
    static lv_style_t MyStyle;  // ������������ָ�����ʽ
    lv_style_init(&MyStyle);
    lv_style_set_shadow_width(&MyStyle, 10);
    lv_style_set_shadow_spread(&MyStyle, 5);
    lv_style_set_shadow_color(&MyStyle, lv_palette_main(LV_PALETTE_RED));

    lv_obj_add_style(ChildObj, &MyStyle, 0);

    lv_obj_add_event_cb(ChildObj, drag_event_handler, LV_EVENT_PRESSING, NULL);
}

void Learn_Arc()
{
    lv_obj_t* arc = lv_arc_create(lv_scr_act());    // ���� arc ����
    lv_obj_set_size(arc, 300, 300);                 // ���� arc �Ĵ�С
    lv_obj_set_align(arc, LV_ALIGN_CENTER);         // ���� arc ����������

    lv_arc_set_range(arc, 0, 100);                  // ���� arc ָʾ��ֵ��Χ
    lv_arc_set_value(arc, 35);

    lv_arc_set_bg_angles(arc, 0, 180);              // ���� arc �ĽǶ�
}


