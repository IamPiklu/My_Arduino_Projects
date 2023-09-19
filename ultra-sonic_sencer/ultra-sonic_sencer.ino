const int trigPin=11;
const int echoPin=12;
const int LEDpin=13;
//defines variable
long duration=0;
float distance=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);//set tripin as output
  pinMode(echoPin,INPUT);//sets the echopin as an Input
  pinMode(LEDpin,OUTPUT);//set tripin as output
  Serial.begin(9600);//starts the program
}

void loop() {
  // put your main code here, to run repeatedly:
//clear the triPin
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  //set the trigpin high state for 10 seconds
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  //reads ecopin, returns the sound wave traveltime in microsecond
  duration=pulseIn(echoPin,HIGH);
  //calculate the distance
  distance= duration*0.034/2.0;
  //print the distance on the serial Monitor
  Serial.print("Object distance (cm):");
  Serial.println(distance);
  if (distance<50){
    Serial.print("Object Alart");
    Serial.println(distance);
    digitalWrite(LEDpin,HIGH);
  }else{
    digitalWrite(LEDpin,LOW);
  }
  delay(2000);
}
