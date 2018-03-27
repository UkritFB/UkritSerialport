#include <OneWire.h>
#include <DS18B20.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

const byte ONEWIRE_PIN = 5;
// Number of sensors
const byte SENSORS_NUM = 6/* number */;
// 1-Wire object
OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors object
DS18B20 sensors(&onewire);

const byte sensorsAddress[SENSORS_NUM][8] PROGMEM = {
  0x28, 0xFF, 0x4C, 0x71, 0x81, 0x14, 0x2, 0x5,  //1 Outbox
  0x28, 0xFF, 0xC, 0x71, 0x81, 0x14, 0x2, 0xEC,  //2 Hot Fin
  0x28, 0xFF, 0xD4, 0x46, 0x81, 0x14, 0x2, 0x42, //3 Water
  0x28, 0xFF, 0xCC, 0x44, 0x81, 0x14, 0x2, 0x7 , //4 Systm
  0x28, 0xFF, 0x19, 0x9F, 0x24, 0x17, 0x3, 0xD6, //5 Inbox
  0x28, 0xFF, 0x51, 0x71, 0x81, 0x14, 0x2, 0x95  //6 Cool Fin
};


int i = 0;
char A;
int state = 1;

String bb ;
String data[6] = {"FF", "FF", "FF", "FF", "FF", "FF"};
int data_int[6];


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);
  analogReference(INTERNAL);

  sensors.begin();
  sensors.request();

  lcd.begin();
}

void loop()
{
  if (sensors.available())
  {
    for (byte i = 0; i < SENSORS_NUM; i++)
    {

      int temperature = sensors.readTemperature(FA(sensorsAddress[i]));
      data[i] = String(temperature);
      data_int[i] = temperature;
    }
    sensors.request();
  }
  bb = data[0] + data[1] + data[2] + data[3] + data[4] + data[5];


  lcd.setCursor(0, 0);
  lcd.print("IN :");
  lcd.print(data_int[4]);

  lcd.setCursor(0, 1);
  lcd.print("OUT:");
  lcd.print(data_int[0]);

  lcd.setCursor(0, 2);
  lcd.print("WA :");
  lcd.print(data_int[2]);

  lcd.setCursor(9, 0);
  lcd.print("SYS:");
  lcd.print(data_int[3]);

  lcd.setCursor(9, 1);
  lcd.print("FC :");
  lcd.print(data_int[5]);

  lcd.setCursor(9, 2);
  lcd.print("FH :");
  lcd.print(data_int[1]);
  if (Serial.available() > 0)
  {
    A = Serial.read();
    //

    if (A == 'R' || A == 'r')
    {
      //Serial.print(i);
      //Serial.println(" ");
      // i++;
      //digitalWrite(13,1);
      //delay(1000);
      Serial.print(bb);
      Serial.print("\n");
    }
    else
    {
      if (A == 'S')
      {
        digitalWrite(13, 1);
      }
      if (A == 's')
      {
        digitalWrite(13, 0);
      }

    }
  }
}






