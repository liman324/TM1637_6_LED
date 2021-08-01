//  TM1637_6_LED
//  Alexander Liman
//  liman324@yandex.ru
//  rcl-radio.ru

#ifndef  TM1637_6_LED_H
#define  TM1637_6_LED_H

#include <Arduino.h>

#define CODE0    0b10001000
#define CODE1    0x40
#define ADDR0    0xC0

class  TM1637_6_LED
  {
    public:

  TM1637_6_LED(uint8_t, uint8_t);
  void print(long t, byte pd_t,      int h0, int h1, int h2, int h3, int h4, int h5); 
  void brig(byte br);
  
    private:
  
  void dec(byte dig);
  void stop();
  void start();
  void del();
  byte qwer;
  uint8_t DIO;
  uint8_t CLK;
  };
#endif
