#include <ws2812.h>

extern TIM_HandleTypeDef htim2;

uint16_t DMA_BUFFER[DMA_BUF_SIZE] = {0};
uint8_t rgb_temp[LED_COUNT][COLORS_COUNT];

void WS2812_init(void)
{
    for (uint16_t i = LED_DELAY; i < DMA_BUF_SIZE; i++)
        DMA_BUFFER[i] = PWM_LOW;
}

void WS2812_RGBToDMA_Buffer(uint8_t red, uint8_t green, uint8_t blue, uint8_t led_number)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        uint16_t _red = LED_DELAY + led_number * COLORS_BITS_COUNT + i + RED_START_POSITION;
        uint16_t _green = LED_DELAY + led_number * COLORS_BITS_COUNT + i + GREEN_START_POSITION;
        uint16_t _blue = LED_DELAY + led_number * COLORS_BITS_COUNT + i + BLUE_START_POSITION;

        DMA_BUFFER[_red] = (bitIsSet(red, (7 - i)) == 1) ? PWM_HIGH : PWM_LOW;
        DMA_BUFFER[_green] = (bitIsSet(green, (7 - i)) == 1) ? PWM_HIGH : PWM_LOW;
        DMA_BUFFER[_blue] = (bitIsSet(blue, (7 - i)) == 1) ? PWM_HIGH : PWM_LOW;
    }
}
