int sensorPin = A0; 
int sensorValue;  
const int RELAY_PIN = 3;
int limit = 300; 

void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 pinMode(RELAY_PIN, OUTPUT);
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 if (sensorValue >= 800){
  
    digitalWrite(RELAY_PIN, HIGH);
    
 Serial.println("hello on");
  }else{
    digitalWrite(RELAY_PIN, LOW);
    
 Serial.println("hello LoW");
    }
 if(sensorValue<=400){
  digitalWrite(RELAY_PIN, LOW);
 }else{
  digitalWrite(RELAY_PIN, HIGH);
 }
 
 if (sensorValue<limit) {
 digitalWrite(13, HIGH); 
 }
 else {
 digitalWrite(13, LOW); 
 }
 
 delay(1000); 
}
