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
#include "johnb.c"

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// 3.3 V (optional) - BackLight (BL)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

int border[]={245,237,237,237,237,237,237,237,237,237,237,214,  //╒══════╕
              209,                                        209,  //│          │
              244,237,237,237,237,237,237,237,237,237,237,220}; //╘══════╛
              
static const unsigned char PROGMEM logo16x16[] =
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc7,
 0xff,0xa7,0xff,0x57,0xfe,0xaf,0xf1,0x5f,
 0xe4,0xbf,0xee,0x7f,0xef,0x7f,0xfe,0x7f,
 0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff}; //bitmap
 
void setup()   {

  Serial.begin(9600);
  display.begin(); //initialize and display logo screen
  delay(2500);
  display.clearDisplay();   // clears the buffer
  display.printgreek("\n  ΠΑΡΟΥΣΙΑΣΗ\n   ΓΡΑΦΙΚΩΝ\n    ΟΘΟΝΗΣ\n     5110");
  display.display();
  delay(2500);
  display.clearDisplay();
}

void loop()  {
  display_border();
  display.setCursor(27,20);
  display.print("LINES");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //draw some lines
  for (byte i=0; i<48; i+=5){
    display.drawLine(0,0,83,i,BLACK);
    display.display();
    delay(100);
  }
  for (byte j=80; j<81; j-=5){   // that's tricky!! byte doesn't get negative values
    display.drawLine(0,0,j,47,BLACK);
    display.display();
    delay(100);
  }
  delay(3000);
  display.clearDisplay();
  
  //draw vertical and horizontal lines
  for (byte i=0; i<84; i+=4){
    display.drawFastVLine(i+2,0,48,BLACK);   //vertical line
    display.drawFastHLine(0,i/2+3,84,BLACK); //horizontal line
    display.display();
    delay(100);
  }
  delay(3000);
  display.clearDisplay();
 
  display_border();
  display.setCursor(12,20);
  display.print("RECTANGLES");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //draw some rectangle outlines
  for (byte i=0; i<28; i+=4){
    display.drawRect(i,i,84-2*i,48-2*i,BLACK);
    display.display();
    delay(100);
  }
  delay(3000);
  display.clearDisplay();
  
  //draw some filled rectangles
  for (byte i=0; i<84; i+=14){
    display.fillRect(i,0,7,48,BLACK);
    display.display();
    delay(100);
  }
  delay(3000);
  display.clearDisplay();
  
   //draw some round rectangle outlines
  display.drawRoundRect(0,0,84,48,6,BLACK);
  delay(100);
  for (byte i=3; i<31; i+=27){
    display.drawRoundRect(i,4,24,40,9,BLACK);
    display.display();
    delay(100);
  }
  display.drawCircleHelper(66,13,9,1,BLACK);  //left-top arc of round rect outline
  display.drawCircleHelper(71,13,9,2,BLACK);  //right-top arc of round rect outline
  display.drawCircleHelper(71,34,9,4,BLACK);  //right-bottom arc of round rect outline
  display.drawCircleHelper(66,34,9,8,BLACK);  //left-bottom arc of round rect outline
  display.display();
  delay(3000);
  display.clearDisplay(); 
  
  //draw a round filled rectangle,filled rect sides and circle
  display.fillRoundRect(5,5,74,38,10,BLACK);
  display.fillCircleHelper(64,19,9,1,9,WHITE); //right side of filled round rect
  display.fillCircleHelper(19,19,9,2,9,WHITE); //left side of filled round rect
  display.fillRoundRect(35,19,14,14,7,WHITE);  //circle with even radius
  display.display();
  delay(3000);
  display.clearDisplay();

  display_border();
  display.setCursor(21,20);
  display.print("CIRCLES");
  display.display();
  delay(2500);
  display.clearDisplay();
 
  //draw some circle outlines
  for (byte i=0; i<24; i+=3){
    display.drawCircle(5+2*i,5+i,i,BLACK); //circles with odd radius
    display.display();
    delay(100);
  }
  delay(3000);
  display.clearDisplay();
  
  //draw some filled circles
  for (byte i=6; i<84; i+=12){
    for (byte j=6; j<48; j+=12){
      display.fillCircle(i,j,5,BLACK);
      display.display();
      delay(100);
    }
  }
  delay(3000);
  display.clearDisplay();
  
  display_border();
  display.setCursor(15,20);
  display.print("TRIANGLES");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //draw some triangle outlines
  for (byte i=3; i<24; i+=4) {
    display.drawTriangle(41,23-i,41-i,23+i,41+i,23+i,BLACK);
    display.display();
    delay(120);
  }
  delay(3000);
  display.clearDisplay();
 
  //draw some filled triangles
  for (byte i=0; i<84; i+=12) {
    display.fillTriangle(0+i,0,12+i,0,6+i,20,BLACK);
    display.fillTriangle(0+i,47,12+i,47,6+i,27,BLACK);
    display.display();
    delay(120);
  }
  delay(3000);
  display.clearDisplay();
  
  display_border();
  display.setCursor(24,20);
  display.print("BITMAP");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //draw a bitmap file
  display.drawBitmap(36,16,logo16x16,16,16,BLACK);
  display.display();
  delay(3500);
  display.clearDisplay();
  
  display_border();
  display.setCursor(30,20);
  display.print("FILL");
  display.display();
  delay(2500);
  
  //fill the screen
  display.fillScreen(BLACK);
  display.display();
  delay(2000);
  
 
  display.setTextColor(WHITE);
  display_border();
  display.setCursor(30,20);
  display.print("TEXT");
  display.display();
  delay(2500);
  display.fillScreen(BLACK);
  
  //display english & greek text
  display.setCursor(0,0);
  display.print("print some\nwhite letters\n");
  display.setTextSize(2);
  display.printgreek("ΜΕΓΑΛΕΣΛΕΞΕΙΣ");
  display.display();
  display.setTextSize(1);
  display.setTextColor(BLACK);  
  delay(4500);
  display.clearDisplay();

  display_border();
  display.setCursor(18,20);
  display.print("BITMAP C");
  display.display();
  delay(2500);
  display.clearDisplay();
 
  //draw a picture from a ***.c file
  display.drawXBitmap(0,0, johnbacas, 84,48, BLACK);
  display.display();
  delay(3000);
  display.clearDisplay();
  
  display_border();
  display.setCursor(24,20);
  display.print("INVERT");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //draw a picture and then invert it
  display.drawXBitmap(0,0, johnbacas, 84,48, BLACK);
  display.display();
  delay(900);  
  display.invertDisplay(true);
  delay(2500);
  display.invertDisplay(false);
  display.clearDisplay();  
  
  display_border();
  display.setCursor(30,20);
  display.print("POOL");
  display.display();
  delay(2500);
  display.clearDisplay();
  
  //pool animation
  randomSeed(analogRead(0)); //random seed
  byte x_prev=random(5,80);
  byte y_prev=random(5,44);
  int hor=1;
  int ver=-1;
  
  display.drawRect(0,0,84,48,BLACK); //pool table
   
  display.fillCircle(x_prev,y_prev,2,BLACK); //billiard ball
  display.display();
  
  for (int i=0; i<110; i++){
  display.fillCircle(1,1,2,BLACK);    //pool table holes
  display.fillCircle(41,0,2,BLACK);   //must be redrawn
  display.fillCircle(82,1,2,BLACK);   //in loop
  display.fillCircle(1,46,2,BLACK);   //in case they are
  display.fillCircle(41,47,2,BLACK);  //erased by
  display.fillCircle(82,46,2,BLACK);  //the billiard ball
  
    //if hit pool sides then bounce
    if (hor==1 && ver==-1){
      display.fillCircle(x_prev,y_prev,2,WHITE);
      display.fillCircle(x_prev+hor,y_prev+ver,2,BLACK);
      x_prev = x_prev + hor;
      y_prev = y_prev + ver;
      if (x_prev==80) hor=-1;
      if (y_prev==3) ver=1;
      display.display();
    }
    if (hor==-1 && ver==-1){
      display.fillCircle(x_prev,y_prev,2,WHITE);
      display.fillCircle(x_prev+hor,y_prev+ver,2,BLACK);
      x_prev = x_prev + hor;
      y_prev = y_prev + ver;
      if (x_prev==3) hor=1;
      if (y_prev==3) ver=1;
      display.display();
    }
    if (hor==-1 && ver==1){
      display.fillCircle(x_prev,y_prev,2,WHITE);
      display.fillCircle(x_prev+hor,y_prev+ver,2,BLACK);
      x_prev = x_prev + hor;
      y_prev = y_prev + ver;
      if (x_prev==3) hor=1;
      if (y_prev==44) ver=-1;
      display.display();
    }
    if (hor==1 && ver==1){
      display.fillCircle(x_prev,y_prev,2,WHITE);
      display.fillCircle(x_prev+hor,y_prev+ver,2,BLACK);
      x_prev = x_prev + hor;
      y_prev = y_prev + ver;
      if (x_prev==80) hor=-1;
      if (y_prev==44) ver=-1;
      display.display();
    }
    delay(15 + pow(1.055 , i));
  }
  display.clearDisplay();
}
/****************************************************************/
void display_border(){
  display.setCursor(6,12);
  for (int i=0; i<26;i++){
    if (i==12) display.setCursor(6,20);
    if (i==13) display.setCursor(72,20);
    if (i==14) display.setCursor(6,28);
    display.write(border[i]);
  }
  display.display(); 
}
