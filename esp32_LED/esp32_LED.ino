void setup() {
 pinMode(23,OUTPUT);

 Serial.begin(115200);
 
}
void loop() {
    digitalWrite(23,HIGH);
    delay(1000);
    digitalWrite(23,LOW);     
delay(1000);
}
