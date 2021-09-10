#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
char auth[] = "NiUPomcuA65gVPjaklXv8BK0hqiwicnH"; //Enter the Auth code which was send by Blink
char ssid[] = "Efua T";  //Enter your WIFI Name
char pass[] = "emmanie8"; 
BlynkTimer timer;
const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
int relayInput = 2;
long randNumber;
void setup() {
  // put your setup code here, to run once:
  pinMode(relayInput, OUTPUT);
  Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
    float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin) / 1023.00) * 100.00 ) );
  Serial.println("%");  
  randNumber = random(26, 28);
  int randNumberC = random(70, 75);
  Serial.println(randNumber);
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  Blynk.virtualWrite(V0, moisture_percentage);
  Blynk.virtualWrite(V1, randNumberC);
  Blynk.virtualWrite(V2, randNumber);
  if( moisture_percentage <=40){
    digitalWrite(relayInput, LOW); 
  }else{
    digitalWrite(relayInput, HIGH);
    }
  delay(1000);
   Blynk.run();

}
