#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "icon.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define ENCODER_PIN_A 32
#define ENCODER_PIN_B 33


void setup()
  {
    Serial.begin(115200);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
     display.drawBitmap(0,0,boot(0),128,64,WHITE);
    display.display();
    sys_delay_ms(2000);
    display.clearDisplay();
  }

void clocks(void){for (int i=0;i<27;i++)
  {
    display.drawBitmap(32,0,clock(i),64,64,WHITE);
    display.display();
    sys_delay_ms(10);
    display.clearDisplay();
  }}
void wifis(void){for (int i=0;i<27;i++)
  {
    display.drawBitmap(32,0,wifi(i),64,64,WHITE);
    display.display();
    sys_delay_ms(10);
    display.clearDisplay();
  }}
void infos(void){for (int i=0;i<27;i++)
  {
    display.drawBitmap(32,0,info(i),64,64,WHITE);
    display.display();
    sys_delay_ms(10);
    display.clearDisplay();
  }}
void settings(void){for (int i=0;i<27;i++)
  {
    display.drawBitmap(32,0,setting(i),64,64,WHITE);
    display.display();
    sys_delay_ms(10);
    display.clearDisplay();
  }}
void eyes(void){for (int i=0;i<27;i++)
  {
    display.drawBitmap(32,0,eye(i),64,64,WHITE);
    display.display();
    sys_delay_ms(10);
    display.clearDisplay();
  }}
void loop() 
{
    wifis();
    sys_delay_ms(1000);
    settings();
    sys_delay_ms(1000);
    eyes();
    sys_delay_ms(1000);
    infos();
    sys_delay_ms(1000);
    clocks();
    sys_delay_ms(1000);


}
