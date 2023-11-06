// Fake vendor lib to use as an example, would be some stm32, nordic, esp32, etc. vendor lib

#ifndef FAKE_VENDOR_LIB_H_
#define FAKE_VENDOR_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

// Fake vendor lib functions
bool hardware_call_to_get_pin_value(uint8_t port, uint8_t pin)
{
    return true;
}

void hardware_call_to_set_pin_value(uint8_t port, uint8_t pin, bool value)
{
    return;
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FAKE_VENDOR_LIB_H_