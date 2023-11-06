# Template GPIO Hardware Abstraction Laye

This is a template for a GPIO Hardware Abstraction Layer (HAL) for embedded C projects. It is intended to be used as a starting point for your own HAL. The main purpose of this template is to provide a starting point for your own HAL and to demonstrate how to structure your HAL. It is not intended to be a fully functional HAL.

## Mocking

The HAL allows for mocking of the gpio interface. This is useful for unit testing. To enable mocking, define `GPIO_MOCK`.
This allows checking that given GPIO pins get set or checked etc.  
Another benfit is that it allows to run the HAL off target on a PC for higher level testing as well as on multiple different targets without
changing any higher level code.

## Compile time checking

The library makes use of compile time checking to ensure that the correct number of externally accessable pins are defined. This is done by defining `GPIO_PIN_COUNT` to the number of pins that are externally accessable. Then the designated initialisers used to initalise the internal lookup mapping `input_hardware_mapping` is fixed to that length. This ensures that the correct number of pins are defined but still allows the low level to define the pins in any order, should hardware specific ordering differ.

## alternative style

The library also provides an alternative style of API. This is done by defining `ALTERNATIVE_DEFINES`. This allows pins to be reconfigured dynamically but
would require an implimentation to check the state or type of a pin before performing an operation on it. This is not implimented in this template but would
use much the same principle.