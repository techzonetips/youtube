# Smart Signage YouTube Episode 2
Create a smart sign using Google Assistant, IFTTT, Adafruit 32x16 LED Matrix and Particle.io Photon.

![Product Image](https://github.com/techzonetips/youtube/images/github-sign-image.png)

## Use Cases

User Types  | Use Case
------------- | -------------
Outdoor Sign | To use with a motion sensor to welcome people to your home.
On-Air  | Let people know your live on a conference call or recording a video.
Anything  | Put it everywhere.

## Display configuration
The configuration supports 16 pixel high and 32 pixel high panels of any multiples of 32 pixels wide. Adafruit sells 16x32, 32x32 and 64x32 panels fully compatible with the library. Daisy chaining displays will also allow for wider configurations.

## Components Required
- 16x32 RGB LED Matrix Panel - https://amzn.to/2R5eeTL
- Particle | Photon Wi-Fi with Headers - https://amzn.to/2Vteuu6
- 5.5mm x 2.1mm DC Power Connector - https://amzn.to/2RxgvGB
- 5V DC Wall Power Adapter UL Listed - https://amzn.to/2LUWZPe
- Jumper Wires Premium Female/Female - https://amzn.to/2R6lQp0
- Jumper Wires Premium Male/Female - https://amzn.to/2VtppUJ

## Wiring
Wiring between the Spark and 16x32 or 32x32 display is as follows:

```
Panel Pin	Photon/Electron Pin
--------------------------------------
  GND			GND		
  CLK			D6		
  OE			D7		
  LAT			TX	
  A			    A0	
  B			    A1		
  C			    A2	
  R1			D0		
  G1			D1		
  B1			D2		
  R2			D3		
  G2			D4		
  B2			D5
  ```
![Wiring Image](https://github.com/techzonetips/youtube/images/wiring.png)

## Pin Arrangement
A 32x16 panel uses the below pin arrangement. The labels might be slightly different, or the pins might not be labeled at all, use this image for reference.

Notice there are four ground connections. To ensure reliable performance, all four should be connected to GND on the Arduino! A solderless breadboard is handy for making this split.

![Wiring Image](https://github.com/techzonetips/youtube/images/pin-layout.png)


