#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
const char* ssid = "thananat   2.4G";
const char* password = "0891550015";
int currentHour;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
String weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//char currentHour[24] = {"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23"};
void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  timeClient.setTimeOffset(25200);
  currentHour = 0;
}
void GetTime() {
  timeClient.update();  
  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);
  currentHour = timeClient.getHours();
  //String currentHour = currentHour[timeClient.getHours()]; 
  Serial.print("Hour: ");
  Serial.println(currentHour);
  String weekDay = weekDays[timeClient.getDay()];
  Serial.println(weekDay);
}
void loop() {
  delay(2000);
  GetTime();
  Serial.println(currentHour);
  if ( weekDays[timeClient.getDay()]  == "Monday" || "Tuesday" || "Wednesday" || "Thursday" || "Friday" ) {
    Serial.println("Today is Weekday");
    if (currentHour > 6 && currentHour < 18) {
      Serial.println("day");
    }
    else {
      Serial.println("Night");
    }
  }
  else {
    Serial.println("Today is Weekend");
        if (currentHour > 6 && currentHour < 18 ) {
      Serial.println("day");
    }
    else {
      Serial.println("Night");
    }
  }
  Serial.println("----------------------------------------------");
}
