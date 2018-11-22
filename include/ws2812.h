#ifndef WS2812_H_
#define WS2812_H_

#include "stm32f1xx_hal.h"

/**
  * 24bit data
  * G7 G6 G5 G4 G3 G2 G1 G0
  * R7 R6 R5 R4 R3 R2 R1 R0
  * B7 B6 B5 B4 B3 B2 B1 B0
  */
#define COLORS_BITS_COUNT 24
#define GREEN_START_POSITION  0
#define RED_START_POSITION 8
#define BLUE_START_POSITION 16
#define COLORS_COUNT 3

#define LED_COUNT 8
#define LED_DELAY 48
#define DMA_BUF_SIZE (LED_DELAY + (LED_COUNT * COLORS_BITS_COUNT))

#define PWM_HIGH 65
#define PWM_LOW 26

#define bitIsSet(reg, bit) ((reg & (1 << bit)) != 0)

void WS2812_init(void);
void WS2812_RGBToDMA_Buffer(uint8_t red, uint8_t green, uint8_t blue, uint8_t led_number);

#endif /* WS2812_H_ */
