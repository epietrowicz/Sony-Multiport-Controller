# Sony-Multiport-Controller
Arduino control of a Sony camera with Multiport support. 

This implementation uses the broken out connector from this vendor:
https://www.studio1productions.com/parts/sony-multiport-connector.htm

![Image of Multiport Connector](https://www.studio1productions.com/images/Multiport-Connector-1.jpg)

Pin | Usage
----| -----
A1  |	VBUS (5 volt, max 2A)
A2	| USB D-1
A3	| USB D+1
A4	| USB ID
A5	| Ground
1	  | Power On  / Off - Short to Ground to toggle between Power On or Off.
2	  | Ground
3	  | Composite Video Out - Not supported when using a wired remote control unit
4	  | Audio Out L / Shutter Release - Shutter with direct trigger cable. Note: Audio is not supported when using a wired remote control unit
5	  | Audio Out R Audio / Activate Camera / Focus -  Focus with direct trigger cable. Note: Audio is not supported when using a wired remote control unit
6	  | Select - resistor to detect the connected cable or accessory type.  Resistor to Pin 2 or Pin 10 depending on accessory type or cable.  Use 100 ohm Resistor.
7	  | UART RX / Boot Serial In - optional input for serial interface (debug) and boot loader.  No Boot Loader.
8	  | UART TX / LANC Sig - optional output for serial LANC interface for debug / No LANC control
9	  | XReset Req / Input for reset request
10	| 2.8 volt to 3.3 volt output





In order to control camera power on/off and the shutter function, pins labled 1, 2, 4, & 5 are used.

Short pin 1&2 together to power toggle camera power. 

Short pin 5 to pin 2, delay for a few milliseconds, then short 4 and 2. 

In order to capture an image, both shutter and focus pins must be shorted to ground. 2N2222 BJT transistors
were used as digital switches to protect the internal hardware of the camera.
