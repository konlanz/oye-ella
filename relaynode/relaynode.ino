#include <Blynk.h>

#include <DHT.h>
#include <DHT_U.h>


int relayInput = 2;
void setup() {
  // put your setup code here, to run once:
pinMode(relayInput, OUTPUT);
}

void loop() {
  
  digitalWrite(relayInput, HIGH); // turn relay on

  delay(1000);

  digitalWrite(relayInput, LOW); // turn relay off

  delay(1000);
  // put your main code here, to run repeatedly:

}
