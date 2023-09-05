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

    lv_arc_set_bg_angles(arc, 120, 60);              // ���� arc �ĽǶ�
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
    lv_obj_t* bar = lv_bar_create(lv_scr_act());    // ���� bar ����
    lv_obj_set_size(bar, 250, 60);                  // ���� bar ��С
    lv_obj_align(bar, LV_ALIGN_LEFT_MID, 0, 0);     // ���� bar λ��
    lv_bar_set_value(bar, 30, LV_ANIM_ON);          // ���ó�ʼֵ

    // �Զ��� style
    static lv_style_t bg_style;     // ���屳�����
    static lv_style_t indic_style;  // ����ָʾ�����

    // ��ʼ���������
    lv_style_init (&bg_style);
    lv_style_set_border_color (&bg_style, lv_palette_main(LV_PALETTE_GREEN));// ���ñ�������ɫ
    lv_style_set_border_width (&bg_style, 3);   // �߽������Ŀ��
    lv_style_set_pad_all(&bg_style, 6);         // ���������ұ߽綼��С6�����أ�
    lv_style_set_radius(&style_bg, 6);          // ģ����
    lv_style_set_anim_time(&style_bg, 1000);    // ����ʱ����

    //��ʼ��ָʾ�����
    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&style_indic, 3);
}

