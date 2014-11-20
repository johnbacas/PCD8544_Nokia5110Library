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

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
//3.3 V (optional) - BackLight (BL)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
int readByte;

void setup()   {
  Serial.begin(9600);
  display.begin(); //initialize and display logo screen
  delay(1500);
  display.clearDisplay();
//  display.printgreek("ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩ Ά Έ Ή Ί Ό Ύ Ώ");
  display.printgreek("Στείλε ένα χα-ρακτήρα από τοSerial Monitorγιά να δεις \nτην επόμενη \nσελίδα.");
  display.display();
  while (!Serial.available()){
    ;//wait until a character is send from Serial Monitor
  }
  readByte = Serial.read();
  display.clearDisplay();
  display.printgreek("Στις επόμενες σελίδες θα \nδεις τη \nβιβλιοθήκη \nglcdfont_greek.c         -->");
  display.display();
}

void loop()  {
  
  for (byte i=0; i<256; i++){
    if (i%84 == 0){
      while (!Serial.available()){
        ; //wait until a character is send from Serial Monitor
      }
      readByte = Serial.read(); 
      display.clearDisplay();
    }
    display.drawChar((i%14)*6,((int)((i%84)/14))*8,i,BLACK,WHITE,1);
    display.display();
    delay(90);
  }
}
