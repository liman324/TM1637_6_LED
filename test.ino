#include <TM1637_6_LED.h>
TM1637_6_LED tm(3, 2); // CLK, DIO

void setup() {
  tm.brig(1); // ЯРКОСТЬ 0...7

}

void loop() {
  tm.print(123456, 0, -1, -1, -1, -1, -1, -1);
  delay(100);

}

/*
  tm.print_time(x, dp, h0, h1, h2, h3, h4, h5);
  x - число от 0 до 999999
  dp - положение запятой от 0 до 5
  h0-h5 - замена цифры на символ
  h0-h5 = -1 замена цифры не происходит

  Для замены цифры символом можно использовать следующие значения:
  0              //   (пусто)
  0b01000000     // - (минус)
  0b01110111     // A
  0b01111100     // b
  0b00111001     // C
  0b01011110     // d
  0b01111001     // E
  0b01110001     // F
  0b01111000     // t
  0b01110011     // P
  
****************************
    XGFEDCBA
  0b00000000  
   
        A
       ---
    F |   | B
       -G-
    E |   | C
       ---.
        D   X
****************************  
 */
