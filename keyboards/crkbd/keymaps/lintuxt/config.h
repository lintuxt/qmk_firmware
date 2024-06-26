/* @lintuxt - September 2021 - NO WARRANTY - ISC License */

#pragma once

#define MASTER_RIGHT

#define USE_SERIAL_PD2

#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
  #define RGB_MATRIX_HUE_STEP 10
  #define RGB_MATRIX_SAT_STEP 4
  #define RGB_MATRIX_VAL_STEP 4
  #define RGB_MATRIX_SPD_STEP 10

  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  #define ENABLE_RGB_MATRIX_BAND_VAL
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
