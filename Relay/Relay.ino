const int smallfan = 22;
const int door = 21;
const int bigfan = 19;
const int water = 4;

void setup() {
  pinMode(smallfan,OUTPUT);
  pinMode(door,OUTPUT);
  pinMode(bigfan,OUTPUT);
  pinMode(water,OUTPUT);
}
void loop() {
  digitalWrite(smallfan,HIGH); // Active LoW
  digitalWrite(door,HIGH);
  digitalWrite(bigfan,HIGH); 
  digitalWrite(water,HIGH);     
  delay(1000);
 
  digitalWrite(smallfan,LOW);
  delay(5000);  
  digitalWrite(smallfan,HIGH); // Active LoW
  delay(5000);

  digitalWrite(door,LOW);   
  delay(5000);  
  digitalWrite(door,HIGH);
  delay(5000);

  digitalWrite(bigfan,LOW);      
  delay(5000);
  digitalWrite(bigfan,HIGH);      
  delay(5000);
  
  digitalWrite(water,LOW);      
  delay(5000);    
}
