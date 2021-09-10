const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */
int relayInput = 2;
long randNumber;
void setup() {
  pinMode(relayInput, OUTPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
  randomSeed(analogRead(0));
}

void loop() {
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin) / 1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");  randNumber = random(10, 20);
  Serial.println(randNumber);
  if( moisture_percentage <=40){
    digitalWrite(relayInput, HIGH); 
  }else{
    digitalWrite(relayInput, LOW);
    }
  delay(1000);
}
