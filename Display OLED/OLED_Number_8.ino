#include "LedControl.h"
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>


Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);
/*
  Example By ArduinoAll
  Arduino -> Module MAX7219
  ขา7 -> DIN
  ขา6 -> CLK
  ขา5 -> LOAD/CS
  5V -> Vcc
  Gnd -> Gnd
*/
LedControl lc = LedControl(7, 6, 5, 1); // เลข 1 คือจำนวนโมดูลแสดงผลที่ต่อ ในที่นี้ต่อ 1 โมดูล
void setup()
{
  display.begin();
  display.fillScreen(RED);
  delay(300);
  display.fillScreen(GREEN);
  delay(300);
  display.fillScreen(BLUE);
  delay(300);
  display.fillScreen(BLACK);
  delay(1000);
  display.setCursor(20,5);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.print("Hello");

  display.setCursor(30,25);
  display.setTextColor(RED);
  display.setTextSize(2);
  display.print("Cat");

  display.fillRect(10,40, 75, 20, RED);

  display.setCursor(20,47);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Namcha");

  display.drawRect(0,0,96,64,WHITE);
  delay(100);

  
  // กำหนดค่าเริ่มต้น MAX7219 device
  lc.shutdown(0, false); // Enable display
  lc.setIntensity(0, 15); // ปรับระดับความสว่างได้ 16 ระดับ 0 คือค่าต่ำสุด 15 คือค่าสูงสุด
  lc.clearDisplay(0); // Clear display register
}
void loop()
{
  lc.setChar(0, 0, 'D', false);
  lc.setChar(0, 1, 'C', false); // lc.setDigit(0,1,10,false) แสดงค่าแบบตัวเลขที่ หลักที่ 1 แสดงเลข 10
  lc.setChar(0, 2, 'B', false);
  lc.setChar(0, 3, 'A', false);
  lc.setChar(0, 4, '-', false);
  lc.setChar(0, 5, 'L', false);
  lc.setChar(0, 6, 'L', false);
  lc.setChar(0, 7, 'A', false);
  
  display.fillRect(10,40, 75, 20, BLACK);
  delay(1000);
  display.fillRect(10,40, 75, 20, RED);
  display.setCursor(20,47);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Namcha");

}
