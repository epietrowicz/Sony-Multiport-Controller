# Sony-Multiport-Controller
Below illustrates the hardware implementation for the shutter and power on/off of any Sony camera with a multiport connector

This implementation uses the broken out connector from this vendor:
https://www.studio1productions.com/parts/sony-multiport-connector.htm

In order to control camera power on/off and the shutter function, pins labled 1, 2, 4, & 5 are used.

Short pin 1&2 together to power toggle camera power. 

Short pin 5 to pin 2, delay for a few milliseconds, then also short 4 and 2. In order to capture an image, both shutter
and focus must be shorted to ground. 

This is illustrated in the Arduino Sketch. Transistor 2N2222 BJT transistors
were used as digital switches to protect the internal hardware of the camera.
