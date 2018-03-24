String bb ;
String data1="FF";
String data2="FF";
String data3="FF";
String data4="FF";
String data5="FF";
String data6="FF";
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
  digitalWrite(A0,HIGH);
  digitalWrite(A2,LOW);
  analogReference(INTERNAL);
}
int i = 0;
char A;
int state = 1;
void loop()
{
  int data = analogRead(A1);
  data = data / 9.31;
  data1 = String (data);
  bb = data1+data2+data3+data4+data5+data6;
  if(Serial.available() > 0)
  {
    A = Serial.read();
    //
    if(A == 'R'|| A == 'r')
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
      if(A == 'S')
      {
        digitalWrite(13,1);
      }
      if(A == 's')
      {
        digitalWrite(13,0);
      }

    }
  }
}






