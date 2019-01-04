// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

// Updated by Rui Santos Costa
// for Tech Zone Tips
// Modification to include scrolling text and Google Assistant Integration


#include "Adafruit_mfGFX.h"   // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library
#include "math.h"
#include "gamma.h"

#define RGBSHIELDVERSION		4

#if (RGBSHIELDVERSION == 4)		// Newest shield with SD socket onboard
	#warning "new shield"
	#define CLK	D6
	#define OE	D7
	#define LAT	TX
	#define A  	A0
	#define B  	A1
	#define C  	A2
	#define D	RX
#else
	#warning "old shield"
	#define CLK	D6
	#define OE 	D7
	#define LAT	A4
	#define A  	A0
	#define B  	A1
	#define C  	A2
	#define D	A3
#endif
/****************************************/


RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const char str[] = "On Air";
int    textX   = matrix.width(),
       textMin = sizeof(str) * -6,
       hue     = 0;

bool onAirBool = false;
bool offAirBool = false;

void setup() {
    
    Particle.subscribe("onair", onAir);
    Particle.subscribe("offair", offAir);
    
    matrix.begin();
    
    matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0)); // draw a box in yellow
    delay(500);
    
    matrix.setCursor(9, 4);   // start at top left, with one pixel of spacing
    matrix.setTextSize(1);    // size 1 == 8 pixels high
    
    matrix.setTextColor(matrix.Color333(7, 0, 7));
    matrix.print('H');
    matrix.setTextColor(matrix.Color333(7, 0, 7)); 
    matrix.print('i');
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.print('!');
 
}

void onAir (const char *event, const char *data) {
    onAirBool = true;
    offAirBool = false;
}

void offAir (const char *event, const char *data) {
    onAirBool = false;
    offAirBool = true;
}

void offAirEndLoop () {
        
    matrix.fillScreen(0);
     
    matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));
    
    
    matrix.setCursor(9, 4);   // start at top left, with one pixel of spacing
    matrix.setTextSize(1);    // size 1 == 8 pixels high
    
    matrix.setTextColor(matrix.Color333(7, 0, 7));
    matrix.print('H');
    matrix.setTextColor(matrix.Color333(7, 0, 7)); 
    matrix.print('i');
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.print('!');
    
}


void loop() {
    
    if (onAirBool) {
        
        matrix.fillScreen(0);
        matrix.setTextWrap(false); // Allow text to run off right edge
        matrix.setTextSize(1);
        matrix.setTextColor(matrix.Color333(7,0,0));
        matrix.setCursor(textX, 4);
        matrix.print(str);
        if((--textX) < textMin) textX = matrix.width();
        matrix.swapBuffers(true);
        delay(75);	// Slow down animation!
        
    }
    
    if (offAirBool) {
        
        offAirEndLoop();
        
    }
    
}