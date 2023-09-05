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
    Temp_Bar();
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
    /************ �Զ��� style1 ************/
    static lv_style_t bg_style;     // ���屳�����
    static lv_style_t indic_style;  // ����ָʾ�����

    // ��ʼ���������
    lv_style_init (&bg_style);
    lv_style_set_border_color (&bg_style, lv_palette_main(LV_PALETTE_GREEN));// ���ñ�������ɫ
    lv_style_set_border_width (&bg_style, 3);   // �߽������Ŀ��
    lv_style_set_pad_all(&bg_style, 6);         // ���������ұ߽綼��С6�����أ�
    lv_style_set_radius(&bg_style, 16);          // �����ǻ���
    lv_style_set_anim_time(&bg_style, 2000);    // ����ʱ�������ý������ж���

    // ��ʼ��ָʾ�����
    lv_style_init(&indic_style);
    lv_style_set_bg_opa(&indic_style, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style, 16);

    // ���Զ�����Ӧ�õ��½��� bar1 ��
    lv_obj_t* bar1 = lv_bar_create(lv_scr_act());    // ���� bar ����
    lv_obj_remove_style_all(bar1);
    lv_obj_add_style(bar1, &bg_style, LV_PART_MAIN);
    lv_obj_add_style(bar1, &indic_style, LV_PART_INDICATOR);
    lv_obj_set_size(bar1, 250, 60);                  // ���� bar ��С
    lv_obj_align(bar1, LV_ALIGN_LEFT_MID, 100, 0);   // ���� bar λ��
    lv_bar_set_value(bar1, 30, LV_ANIM_ON);          // ���ó�ʼֵ


    /*********** �Զ��� style2 ***********/
    static lv_style_t bg_style2;     // ���屳�����
    static lv_style_t indic_style2;  // ����ָʾ�����

    // ��ʼ���������
    lv_style_init (&bg_style2);
    lv_style_set_border_color (&bg_style2, lv_palette_main(LV_PALETTE_GREEN));// ���ñ�������ɫ
    lv_style_set_border_width (&bg_style2, 3);   // �߽������Ŀ��
    lv_style_set_pad_all(&bg_style2, 16);        // ���������ұ߽綼��С16������
    lv_style_set_radius(&bg_style2, 26);         // ���˻���
    lv_style_set_anim_time(&bg_style2, 2000);    // ����ʱ�������ý������ж���

    // ��ʼ��ָʾ�����
    lv_style_init(&indic_style2);
    lv_style_set_bg_opa(&indic_style2, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style2, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style2, 3);

    // ���Զ�����Ӧ�õ��½��� bar2 ��
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
    /********** ��������� **********/

    // 1. ���� style
    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_border_color(&bg_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_width (&bg_style, 3);   // �߽������Ŀ��
    lv_style_set_pad_all(&bg_style, 7);         // ���������ұ߽綼��С6�����أ�
    lv_style_set_radius(&bg_style, 20);         // �����ǻ���
    lv_style_set_anim_time(&bg_style, 2000);    // ����ʱ�������ý������ж���

    static lv_style_t indic_style;
    lv_style_init(&indic_style);
    lv_style_set_bg_opa(&indic_style, LV_OPA_COVER);
    lv_style_set_bg_color(&indic_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_radius(&indic_style, 20);

    // 2. ���� bar ����
    lv_obj_t * bar = lv_bar_create(lv_scr_act());
    lv_obj_remove_style_all(bar);
    lv_obj_add_style(bar, &bg_style, LV_PART_MAIN);
    lv_obj_add_style(bar, &indic_style, LV_PART_INDICATOR);
    lv_obj_set_size(bar, 250, 80);
    lv_obj_align(bar, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_value(bar, battery_capacity, LV_ANIM_ON);

    /********** ��������� **********/

    // 1. ���� style
    static lv_style_t little_style;
    lv_style_init(&little_style);
    lv_style_set_bg_color(&little_style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_border_color(&little_style, lv_palette_main(LV_PALETTE_GREEN));

    // 2. ���� bar ����
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

//    lv_anim_t a;
//    lv_anim_init(&a);
//    lv_anim_set_exec_cb(&a, set_temp);
//    lv_anim_set_time(&a, 3000);
//    lv_anim_set_playback_time(&a, 3000);
//    lv_anim_set_var(&a, bar);
//    lv_anim_set_values(&a, -20, 40);
//    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
//    lv_anim_start(&a);
}

