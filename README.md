# RDrive
This is an experimental refactor of the ODrive firmware. RDrive is the following things:

- A learning exercise (USE AT YOUR OWN RISK)!
- A C based alternative to the C++ approach that the ODrive firmware uses.
- A closer fit for the CANOpen model of drive control where everything is configurable and runs over the CAN network stack.

The RDrive firmware is not guaranteed to maintain feature parity or backwards compatibility with older versions of the ODrive hardware platform. This is done in an effort to simplify some of the functionality that the firmware supports.

## Commissioning Interface
Due to the prevalance of USB based frustrations that people have been running into, I plan to be eliminating the USB interface. Any initial commissioning of the board must be done using the serial link (and a USB to serial converter).
