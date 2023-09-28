#include <Arduino.h>
#include <lvgl.h>
#include <ATD1.47-S3.h>

#include "UI/ui.h" // include ui header generate by SquareLine

void setup() {
  Serial.begin(115200);

  Display.begin(); // Init LCD
  Display.useLVGL(); // Connect LVGL to Display
  
  // Start User UI code
  ui_init(); // Load UI from SquareLine generate
  
  // Add progress bar animation timer
  lv_timer_create([](lv_timer_t*) {
    static int i = 0;
    i++; // count up 'i'
    if (i > 100) {
        i = 0;
    }
    lv_bar_set_value(ui_progress, i, LV_ANIM_ON); // set 'i' value to progress bar
  }, 30, NULL);
  // END of User UI code
}

void loop() {
  Display.loop(); // keep LVGL still work
}
