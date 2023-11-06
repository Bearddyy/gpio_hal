// C source file for the GPIO HAL

#include "gpio_hal.h"

// # include for whatever distributor code
#include "fake_vendor_lib.h"

// Defines
// Ususally GPIO pins have a hardware specific define or such
// Ideally use designated initializers map the public gpio_hal_pin_t to the hardware specific pin
// Example:

typedef struct hardware_specific_define_t
{
    uint8_t pin;
    uint8_t port;
} hardware_specific_define_t;

// Dedicated initializers allow for easy mapping of the public gpio_hal_pin_t to the hardware specific pin
// It also enforce the correct number of pins are defined and is checked at compile time
static const hardware_specific_define_t input_hardware_mapping[GPIO_INPUT_PIN_COUNT] = {
    [GPIO_PIN_0] = { .pin = 0, .port = 0 },
    [GPIO_PIN_1] = { .pin = 1, .port = 0 },
};

static const hardware_specific_define_t output_hardware_mapping[GPIO_OUTPUT_PIN_COUNT] = {
    [GPIO_PIN_0] = { .pin = 0, .port = 0 },
    [GPIO_PIN_1] = { .pin = 1, .port = 0 },
};

// GPIO HAL functions
void gpio_hal_init(void)
{
    // Initialize GPIO pins
    // Set GPIO pins to input or output
    // Set GPIO pins to high or low
    // EG:
    for (uint8_t i = 0; i < GPIO_INPUT_PIN_COUNT; i++)
    {
        // Set pin to input
        // Set pin to high
    }

    for (uint8_t i = 0; i < GPIO_OUTPUT_PIN_COUNT; i++)
    {
        // Set pin to output
        // Set pin to low
    }
}

bool gpio_hal_get_input(gpio_input_pins_t pin)
{
    // Get GPIO pin value
    // EG:
    if (pin >= GPIO_INPUT_PIN_COUNT)
    {
        return false; // log error...
    }
    return hardware_call_to_get_pin_value(input_hardware_mapping[pin].port, input_hardware_mapping[pin].pin);
}

void gpio_hal_set_output(gpio_output_pins_t pin, bool value)
{
    // Set GPIO pin to high or low
    // EG:
    if (pin >= GPIO_OUTPUT_PIN_COUNT)
    {
        return; // log error...
    }
    hardware_call_to_set_pin_value(output_hardware_mapping[pin].port, output_hardware_mapping[pin].pin, value);
}

