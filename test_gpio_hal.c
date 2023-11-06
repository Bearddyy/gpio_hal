//File to show how to use the GPIO HAL under test

#include "gpio_hal.h"
#include "gpio_hal_mock.h"
#include "unity.h" // or other test framework as needed


void test_gpio_hal_output(void)
{
    // as needed
    gpio_hal_init();

    // Check all output pins can be set
    for (uint8_t i = 0; i < GPIO_OUTPUT_PIN_COUNT; i++)
    {
        gpio_hal_set_output(i, true);
        TEST_ASSERT_TRUE(mock_gpio_hal_get_current_output_state(i));
        gpio_hal_set_output(i, false);
        TEST_ASSERT_FALSE(mock_gpio_hal_get_current_output_state(i));
    }
}

void test_gpio_hal_input(void)
{
    // as needed
    gpio_hal_init();

    // Check all input pins can be read
    for (uint8_t i = 0; i < GPIO_INPUT_PIN_COUNT; i++)
    {
        mock_gpio_hal_set_input_state(i, true);
        TEST_ASSERT_TRUE(gpio_hal_get_input(i));
        mock_gpio_hal_set_input_state(i, false);
        TEST_ASSERT_FALSE(gpio_hal_get_input(i));
    }
}

// Test main 
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_gpio_hal_output);
    RUN_TEST(test_gpio_hal_input);
    return UNITY_END();
}

