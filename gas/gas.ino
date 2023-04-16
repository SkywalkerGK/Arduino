
int smokeA0 = 4;
int sensorThres = 400; //910

void setup() {
  pinMode(smokeA0, INPUT);
  analogReadResolution(10);
  Serial.begin(115200);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  delay(100);
}
