//Mock implementation of the GPIO HAL for testing
// This is contained in a header file for brevity but could be split into a .c and .h file

#ifdef GPIO_HAL_MOCK_H
#define GPIO_HAL_MOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MOCK_GPIO_HAL

#include "gpio_hal.h"

static bool mock_gpio_hal_output_state[GPIO_OUTPUT_PINS_MAX] = {false};
static bool mock_gpio_hal_input_state[GPIO_INPUT_PINS_MAX] = {false};

// GPIO HAL functions

// Initialize GPIO HAL
void gpio_hal_init(void)
{
    // Initialize any testing needed
    for (int i = 0; i < GPIO_OUTPUT_PINS_MAX; i++)
    {
        mock_gpio_hal_output_state[i] = false;
    }

    for (int i = 0; i < GPIO_INPUT_PINS_MAX; i++)
    {
        mock_gpio_hal_input_state[i] = false;
    }
}

// get a GPIO input pin state, this is the 
// mock implementation of the standard function
bool gpio_hal_get_input(gpio_input_pins_t pin)
{
    return mock_gpio_hal_input_state[pin];
}

// set a GPIO output pin state, this is the
// mock implementation of the standard function
void gpio_hal_set_output(gpio_output_pins_t pin, bool value)
{
    mock_gpio_hal_output_state[pin] = value;
}

// This allows checking of the current output state for testing
bool mock_gpio_hal_get_current_output_state(gpio_output_pins_t pin)
{
    return mock_gpio_hal_output_state[pin];
}

// This allows setting of the current input state for testing
void mock_gpio_hal_set_input_state(gpio_input_pins_t pin, bool value)
{
    mock_gpio_hal_input_state[pin] = value;
}

#endif // MOCK_GPIO_HAL

#ifdef __cplusplus
}
#endif

#endif // GPIO_HAL_MOCK_H