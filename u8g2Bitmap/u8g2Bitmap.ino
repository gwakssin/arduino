#include <Arduino.h>
#include <U8g2lib.h>
#define u8g_logo_width 38
#define u8g_logo_height 24

//U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, 10, 9, 12, 11, 13);
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
static unsigned char u8g_logo_bits[] = {
   0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xe0, 0xe0,
   0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f };

void setup(void) {
u8g2.begin();
u8g2.setFlipMode(0);
}

void loop(void) {
//u8g2.clearBuffer(); // clear the internal menory
u8g2.drawXBM( 0, 0, u8g_logo_width, u8g_logo_height, u8g_logo_bits);
//u8g2.sendBuffer(); // transfer internal memory to the display
delay(1000);
}
