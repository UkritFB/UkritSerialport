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
  if(Serial.available() > 0)
  {
    A = Serial.read();
    //
    if(A == 'R'|| A == 'r')
    {
      //Serial.print(i);
      //Serial.println(" ");
      // i++;
      digitalWrite(13,1);  
      //delay(1000);
      Serial.print(data);
      Serial.print("\n");
    }
    else
    {
      digitalWrite(13,0);
      if(A == 'S')
      {
        digitalWrite(12,1);
      }
      if(A == 's')
      {
        digitalWrite(12,0);
      }
      
    }
  }
}





