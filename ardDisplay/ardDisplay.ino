#include <Arduino.h>
#include <U8g2lib.h>

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

void setup(void) 
{
  Serial.begin(9600);
  u8g2.begin();
  u8g2_prepare();
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  Serial.print("\nBegun");
}

int rxCounter = 0;
void loop(void) {
  /*for(int i = 0; i < 1000; i++)
  {
    itoa(i, str, 10);
    u8g2.clearBuffer();
    u8g2.drawStr(0, 0, "TEMP: ");
    u8g2.drawStr(35, 0, str);
    u8g2.sendBuffer();
  }*/

  int temp = 0;
  int tempTarget = 0;
  
  if(digitalRead(5) == HIGH)
  {
    //Serial.print("\nTEMP INFORMATION STREAM");
    temp = temp | (digitalRead(4));
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}
    
    temp = temp | (digitalRead(4) << 1);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    temp = temp | (digitalRead(4) << 2);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    temp = temp | (digitalRead(4) << 3);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    temp = temp | (digitalRead(4) << 4);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}
    
    temp = temp | (digitalRead(4) << 5);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    temp = temp | (digitalRead(4) << 6);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    temp = temp | (digitalRead(4) << 7);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    //GETTING TEMP TARGET
    tempTarget = tempTarget | (digitalRead(4));
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}
    
    tempTarget = tempTarget | (digitalRead(4) << 1);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    tempTarget = tempTarget | (digitalRead(4) << 2);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    tempTarget = tempTarget | (digitalRead(4) << 3);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    tempTarget = tempTarget | (digitalRead(4) << 4);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}
    
    tempTarget = tempTarget | (digitalRead(4) << 5);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    tempTarget = tempTarget | (digitalRead(4) << 6);
    while(digitalRead(5) == HIGH){}
    while(digitalRead(5) == LOW){}

    tempTarget = tempTarget | (digitalRead(4) << 7);
    while(digitalRead(5) == HIGH){}

    rxCounter++;

    char str1[8];
    char str2[8];
    char str3[20];
    //Serial.print("\nINFORMATION GOT: ");
    //Serial.print(temp);
    itoa(temp, str1, 10);
    itoa(tempTarget, str2, 10);
    itoa(rxCounter, str3, 10);

    u8g2.clearBuffer();
    u8g2.drawStr(0, 0,  "TEMP  :    C");
    u8g2.drawStr(45, 0, str1);
    u8g2.drawStr(0, 10, "TARGET:   C");
    u8g2.drawStr(45, 10, str2);
    u8g2.drawStr(45, 20, str3);
    u8g2.sendBuffer();
  }
}
