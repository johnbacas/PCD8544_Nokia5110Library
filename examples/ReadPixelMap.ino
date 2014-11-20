/*********************************************************************
This is an example sketch for Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Please support Adafruit and open-source hardware by purchasing
products from Adafruit!

This sketch is written by John Bacas
***********************************************************************/
#include <JBacas_GFX.h>
#include <JBacas_PCD8544.h>
#include "logo.c"

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// (optional) 3.3 V - BackLight (BL)

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
byte dbit = 0;
float decimalf = 0;
int decimal;
void setup()   {

  Serial.begin(9600);
  display.begin(); //initialize and display logo screen

  display.clearDisplay();   // clears the buffer
  
// **** (start) change commands to create your logo using gfx library *******
  display.drawXBitmap(0, 0, logo, 84,48, BLACK); //read pic from logo.c
  display.fillRect(0,19,84,9,WHITE);
  display.setCursor(0,20);
  display.setTextColor(BLACK);
  display.print("JB ELECTRONICS");
  display.display();
// **** (end) ***************************************************************
  
// create a pixel map (in hex format) of the screen.
  for (int bank=0; bank<6; bank+=1){
     for (int j=0; j<84; j+=1){
       for (int i=7+bank*8; i>-1+bank*8; i-=1){
          dbit = display.getPixel(j,i);
          decimalf = decimalf + dbit * pow(2,i-bank*8);
          }
       Serial.print(" ");
       decimal = (int) (decimalf + 0.1);
       Serial.print(" 0x" + String(decimal,HEX)+",");
           if ((j+1)%12 == 0) {
           Serial.println();
           }
       decimalf=0;
     }
  }
// Go to "Tools --> Serial Monitor" and copy the text
// Paste text in the "JBacas_PCD8544.cpp" file, in the "pcd8544_buffer[]" declaration
}

void loop()  {
}
