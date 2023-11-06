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
typedef enum gpio_input_pins_t
{
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_INPUT_PIN_COUNT
} gpio_input_pins_t;

typedef enum gpio_output_pins_t
{
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_OUTPUT_PIN_COUNT
} gpio_output_pins_t;


// Function prototypes
extern void gpio_hal_init(void);

extern bool gpio_hal_read_input(gpio_input_pins_t pin);

extern void gpio_hal_set_output(gpio_output_pins_t pin, bool value);


#ifdef __cplusplus
}
#endif

#endif // GPIO_HAL_H