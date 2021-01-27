#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// ws2812b
#define RGB_DI_PIN D3

// 28 per-side
#define RGBLED_NUM 56
#define RGBLED_SPLIT { 28, 28 }

#define RGBLIGHT_LIMIT_VAL 120

#define RGBLIGHT_SPLIT

#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS

#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
