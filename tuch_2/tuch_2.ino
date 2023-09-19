const int SensorPin = 2;

int lastState = LOW;
int currentState;

void setup(){

  Serial.begin(9600);

  pinMode(SensorPin, INPUT);
}
void loop(){

  currentState = digitalRead(SensorPin); 
  if(lastState == LOW && currentState == HIGH) 
    Serial.println("The sensor is touched"); 
  else if(lastState == HIGH && currentState == LOW) 
    Serial.println("The sensor is released"); 
  else if(lastState == LOW && currentState == LOW) 
    Serial.println("The sensor is Untouched");
  else if(lastState == HIGH && currentState == HIGH) 
    Serial.println("The sensor is in touch"); 
  lastState = currentState;
  delay(500);
}