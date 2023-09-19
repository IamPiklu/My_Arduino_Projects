const int SensorPin=2;
int state;
void setup() {
  Serial.begin(9600);
  pinMode(SensorPin,INPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  state=digitalRead(SensorPin);
  Serial.println(state);
  if(state==HIGH)
    Serial.println("ToUCH Detected");
  else
    Serial.println("ToUCH Not Detected");
  delay(500);
}
