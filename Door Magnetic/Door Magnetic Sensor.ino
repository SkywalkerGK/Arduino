int ledred = 11; //Door Closed Status
int ledgreen = 12; // Door Open Status
int door = 6; // Door sensor connected to Pin 6 in Arduino
const int pir = 5;
void setup()
{
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(door, INPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(pir) == HIGH) {
    digitalWrite(ledred, HIGH);
  }
  else  {
    digitalWrite(ledred, LOW);
  }
  Serial.print("pirState : "); Serial.println(digitalRead(pir));
  
  if (digitalRead(door) == HIGH)
  {
    digitalWrite(ledgreen, LOW);
    //Serial.println("Your Door is Closed");
  }
  else 
  {
    digitalWrite(ledgreen, HIGH);
    //Serial.println("Your Door is Open");
  }
  delay(100);
}
