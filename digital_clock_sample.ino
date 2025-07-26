/****************************************************************************************************************************
  RP2040_RTC_Time.ino

  For RP2040-based boards using internal RTC
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields

  Built by Khoi Hoang https://github.com/khoih-prog/RP2040_RTC
  Licensed under MIT license
 *****************************************************************************************************************************/

// Important notes: Currently, RP2040-based boards RTC has no battery backup. So the time will be lost when power down
// Therefore, NTP client is necessary to get NTP time and update RTC.

#include "defines.h"
#include <TimeLib.h>
#include <TM1637Display.h>

#define CLK_PIN  2  // Pico の任意 GPIO
#define DIO_PIN  3

TM1637Display display(CLK_PIN, DIO_PIN);

/*
typedef struct 
{
  int16_t year;     ///< 0..4095
  int8_t  month;    ///< 1..12, 1 is January
  int8_t  day;      ///< 1..28,29,30,31 depending on month
  int8_t  dotw;     ///< 0..6, 0 is Sunday
  int8_t  hour;     ///< 0..23
  int8_t  min;      ///< 0..59
  int8_t  sec;      ///< 0..59
} datetime_t; 
*/

// Example set at 05:00:00 Fri 21 Jan 2022 UTC or 00:00:00 Fri 21 Jan 2022 EST

datetime_t currTime = { 2025, 7, 26, 6, 8, 45, 0 };

//////////////////////////////////////////
void setup()
{
  delay(200);

  display.setBrightness(0x0f);

  rtc_init(); // Start the RTC

  rtc_set_datetime(&currTime);
}

void loop()
{ 
  rtc_get_datetime(&currTime);

  // Display time from RTC
  DateTime now = DateTime(currTime);

  time_t gt = now.get_time_t();

  int tm = hour(gt) * 100 + minute(gt);
  int colon = second(gt)%2?0x40:0;
  display.showNumberDecEx(tm,colon,true);
}
