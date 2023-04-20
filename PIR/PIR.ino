const int pir = 13;


int pirState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pir, INPUT);
}

void loop() {
  pirState = digitalRead(pir);

  if (pirState == HIGH) {
      Serial.println("1");
  }

  else if (pirState == LOW) {
    Serial.println("0");

  }

}
