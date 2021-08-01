#include <TM1637_6_LED.h>

TM1637_6_LED::TM1637_6_LED(uint8_t clk, uint8_t dio){
         CLK = clk;
         DIO = dio;
};

void TM1637_6_LED::brig(byte br){
     qwer = br + CODE0;
  }

void TM1637_6_LED::del(){delayMicroseconds(150);}


void TM1637_6_LED::dec(byte dig){
         for(int i = 0; i < 8; i++) {
           pinMode(CLK, OUTPUT);del();
         if (dig & 0x01)
           pinMode(DIO, INPUT);
         else
           pinMode(DIO, OUTPUT);del();
           pinMode(CLK, INPUT);del();
           dig = dig >> 1;
  }
           pinMode(CLK, OUTPUT);
           pinMode(DIO, INPUT);del();
           pinMode(CLK, INPUT);del();
           uint8_t ack = digitalRead(DIO);
         if (ack == 0)
           pinMode(DIO, OUTPUT);del();
           pinMode(CLK, OUTPUT);del();
  }
            
void TM1637_6_LED::stop(){
           pinMode(DIO, OUTPUT);del();
           pinMode(CLK, INPUT);del();
           pinMode(DIO, INPUT);del();
  }  

void TM1637_6_LED::start(){
           pinMode(DIO, OUTPUT);del();
  }


void TM1637_6_LED::print(long t, byte pd,  int h0, int h1, int h2, int h3, int h4, int h5){
        start();dec(qwer);stop();start();dec(CODE1);stop();start();
        
        long data2 = t/100000;
        long data1 = t/10000%10;
        long data0 = t/1000%10;
        long data5 = t/100%10;
        long data4 = t/10%10;
        long data3 = t/1%10;
        
        for(int n=0;n<6;n++){
        byte data;
        if(n==0){data=data0;}
        if(n==1){data=data1;}
        if(n==2){data=data2;}
        if(n==3){data=data3;}
        if(n==4){data=data4;}
        if(n==5){data=data5;}
              
        switch(data){  // XGFEDCBA
        case 0:  data = 0b00111111;break;     // 0
        case 1:  data = 0b00000110;break;     // 1
        case 2:  data = 0b01011011;break;     // 2
        case 3:  data = 0b01001111;break;     // 3
        case 4:  data = 0b01100110;break;     // 4
        case 5:  data = 0b01101101;break;     // 5
        case 6:  data = 0b01111101;break;     // 6
        case 7:  data = 0b00000111;break;     // 7
        case 8:  data = 0b01111111;break;     // 8
        case 9:  data = 0b01101111;break;     // 9
        }
              
        if(n==0){data0=data;}
        if(n==1){data1=data;}
        if(n==2){data2=data;}
        if(n==3){data3=data;}
        if(n==4){data4=data;}
        if(n==5){data5=data;}
        }
        switch(pd){
        case 1 : data4 = data4+0b10000000;break;
        case 2 : data5 = data5+0b10000000;break;
        case 3 : data0 = data0+0b10000000;break;
        case 4 : data1 = data1+0b10000000;break;
        case 5 : data2 = data2+0b10000000;break;
        }

        if(h2>-1){data0 = h2;}
        if(h1>-1){data1 = h1;}
        if(h0>-1){data2 = h0;}
        if(h5>-1){data3 = h5;}
        if(h4>-1){data4 = h4;}
        if(h3>-1){data5 = h3;}
        
        dec(ADDR0);dec(data0);dec(data1);dec(data2);dec(data3);dec(data4);dec(data5);stop();
}
