// Header for the GPIO abstarction layer

#ifndef GPIO_HAL_H
#define GPIO_HAL_H

//extern c++
#ifdef __cplusplus
extern "C" {
#endif

// Includes
#include <stdint.h>
#include <stdbool.h>


// Defines
#ifndef ALTERNATIVE_DEFINES
typedef enum gpio_input_pins_t
{
    GPIO_INPUT_PIN_0,
    GPIO_INPUT_PIN_1,
#ifdef ALTERNATIVE_HARDWARE // An example of how hardware varients can be handled
    GPIO_INPUT_PIN_4,
#endif
    GPIO_INPUT_PIN_COUNT
} gpio_input_pins_t;

typedef enum gpio_output_pins_t
{
    GPIO_OUTPUT_PIN_2,
    GPIO_OUTPUT_PIN_3,
    GPIO_OUTPUT_PIN_COUNT
} gpio_output_pins_t;

// Function prototypes
extern void gpio_hal_init(void);

extern bool gpio_hal_read_input(gpio_input_pins_t pin);

extern void gpio_hal_set_output(gpio_output_pins_t pin, bool value);


#else // Alternative style for common identifier
typedef enum gpio_pins_t
{
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_COUNT
} gpio_pins_t;

// this could then allow common identifiers for input and output pins
// and therefor cope more easily with pins that can be both input and output
// This would require the hal to check states

extern bool gpio_hal_read_input(gpio_pins_t pin);

extern void gpio_hal_set_output(gpio_pins_t pin, bool value);

extern void gpio_hal_configure_pin(gpio_pins_t pin, bool is_input, bool pull);

#endif // ALTERNATIVE_DEFINES

#ifdef __cplusplus
}
#endif

#endif // GPIO_HAL_H