int buzzer = 18;
void setup()
{
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,HIGH);
}
void loop()
{
      digitalWrite(buzzer,LOW);
      delay(1000);
      digitalWrite(buzzer,HIGH);
      delay(1000);
}
