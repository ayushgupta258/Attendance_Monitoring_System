#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // 2- rxd 3-txd
//SoftwareSerial mySerial1(5,4); // 5- rxd \1-txd

#include <String.h>

LiquidCrystal lcd(12,11,10,9,8,7);
String temp;
String emp1="020036ADE37A";
String emp2="8400811FA0BA";
String emp3="120088F3EA83";
String emp4="55000CAAAE5D";
int len;
String total[ 4]={"Aarti","Ayush","Prachi","Yukti"};
int present[4]={0,0,0,0};
int i;
String bt="*";

void my_init()
{
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("Welcome");
  lcd.setCursor(7,1);
  lcd.print("User");
}

void setup()
{
  
  Serial.begin(9600);
  //mySerial1.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16,2);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
}


void loop()
{
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Welcome");
  lcd.setCursor(7,1);
  lcd.print("User");
  lcd.setCursor(0,0);
  if(digitalRead(6)==HIGH)
  {
    //while(!Serial.available());
    if(Serial.available()>0)
    {
      temp=Serial.readString();
    }
    
  //a
  if(temp==emp1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Aarti");
    delay(1000);
    my_init();
    present[0]=1;
    temp="000000000000";
   
  }
  
  //b
  else
  if(temp==emp2)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ayush");
    delay(1000);
    my_init();
    present[1]=1;
    temp="000000000000";
    
  }
  //c
  else
  if(temp==emp3)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Prachi");
    delay(1000);
    my_init();
    present[2]=1;
    temp="000000000000";
   }

  //d
  else
  if(temp==emp4)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Yukti");
    delay(1000);
    my_init();
    present[3]=1;
    temp="000000000000";
    
  }

  }
  if(digitalRead(6)==LOW)
  {
    for(i=0;i<4;i++)
    {
      if(present[i]==0)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Students Absent");
        lcd.setCursor(0,1);
        lcd.print(total[i]);
        bt+=i;
        bt+=',';
        delay(2000);
      }
    }
    len=bt.length();
    bt.remove(len-1);
    mySerial.print(bt);
    mySerial.println("#");
  }
  delay(500);
}
