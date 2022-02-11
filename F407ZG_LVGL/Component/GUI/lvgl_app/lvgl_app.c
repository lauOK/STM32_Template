#include "lvgl_app.h"

void lv_ex_label(void)
{
	static char* github_addr = "Sid Lau LVGL Example";
	lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label, true);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);
    lv_obj_set_width(label, 150);
    lv_label_set_text_fmt(label, "#ff0000 Github: %s#", github_addr);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -10);
	
    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label2, true);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label2, 150);
    lv_label_set_text_fmt(label2, "#ff0000 Hello# #00ff00 world ! LVGL#");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 10);
}