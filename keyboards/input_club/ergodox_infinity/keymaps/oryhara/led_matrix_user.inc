// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the LED_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
LED_MATRIX_EFFECT(my_cool_effect)
LED_MATRIX_EFFECT(my_cool_effect2)

// Step 2.
// Define effects inside the `LED_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef LED_MATRIX_CUSTOM_EFFECT_IMPLS


// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  LED_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    led_matrix_set_value(i, 0xFF);
  }
  return led_matrix_check_finished_leds(led_max);
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
static uint8_t some_global_state;
static void my_cool_effect2_complex_init(effect_params_t* params) {
  some_global_state = 1;
}
static bool my_cool_effect2_complex_run(effect_params_t* params) {
  LED_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    led_matrix_set_value(i, some_global_state++);
  }
  return led_matrix_check_finished_leds(led_max);
}
static bool my_cool_effect2(effect_params_t* params) {
  if (params->init) my_cool_effect2_complex_init(params);
  return my_cool_effect2_complex_run(params);
}

#endif // LED_MATRIX_CUSTOM_EFFECT_IMPLS


keyframe_animation_t sweep_on_sweep_off_left_and_right = {
    .num_frames = 10,
    .loop = true,
    .frame_lengths = {
        gfxMillisecondsToTicks(GRADIENT_TIME), // left  on
        gfxMillisecondsToTicks(GRADIENT_TIME), // right on
        gfxMillisecondsToTicks(GRADIENT_TIME), // left off
        gfxMillisecondsToTicks(GRADIENT_TIME), // right off
        0,           // mirror leds
        gfxMillisecondsToTicks(GRADIENT_TIME), // right on
        gfxMillisecondsToTicks(GRADIENT_TIME), // left on
        gfxMillisecondsToTicks(GRADIENT_TIME), // right off
        gfxMillisecondsToTicks(GRADIENT_TIME), // left off
        0,           // normal leds
    },
    .frame_functions = {
        led_backlight_keyframe_half_period_sweep_to_on,
        keyframe_no_operation,
        led_backlight_keyframe_half_period_sweep_to_off,
        keyframe_no_operation,
        led_backlight_keyframe_mirror_orientation,
        keyframe_no_operation,
        led_backlight_keyframe_half_period_sweep_to_on,
        keyframe_no_operation,
        led_backlight_keyframe_half_period_sweep_to_off,
        led_backlight_keyframe_normal_orientation,

    },
};
keyframe_animation_t both_sides_fade_across = {
    .num_frames = 8,
    .loop = true,
    .frame_lengths = {
        gfxMillisecondsToTicks(GRADIENT_TIME), // left to rigt (outside in)
        0,           // mirror leds
        gfxMillisecondsToTicks(GRADIENT_TIME), // left_to_right (mirrored, so inside out)
        0,           // normal leds
        gfxMillisecondsToTicks(GRADIENT_TIME), // left to rigt (outside in)
        0,           // mirror leds
        gfxMillisecondsToTicks(GRADIENT_TIME), // left_to_right (mirrored, so inside out)
        0,           // normal leds
    },
    .frame_functions = {
        led_backlight_keyframe_one_period_sweep,
        led_backlight_keyframe_mirror_orientation,
        keyframe_no_operation,
        keyframe_no_operation,
        keyframe_no_operation,
        keyframe_no_operation,
        led_backlight_keyframe_one_period_sweep,
        led_backlight_keyframe_normal_orientation,

    },
};
