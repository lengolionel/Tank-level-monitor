#include <CayenneMQTTESP8266.h>
const int trigpin = D5;
const int echopin = D6;
int duration;
int distance;
char ssid[] = "yourWifiSSID";
char wifiPassword[] = "WIFI-PASSWORD";
char username[] = "MQTT-USERNAME FROM CAYENNE";
char Password[] = "MQTT-PASSWORD FROM CAYENNE";
char clientID[] = "CAYENNE CLIENT ID";
void setup() {
  Cayenne.begin(username, Password, clientID, ssid, wifiPassword);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}
void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 /2;
  int level = 100 - distance * 100 / 40;// REPLACE THE 40CM with the height of your tank
  delay(2000);
  Cayenne.virtualWrite(1, level);// sending the tank level to the cayenne dashboard
  Cayenne.loop();

}
