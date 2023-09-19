int motionSensor = 2; // motion sensor input pin
int fanPin = 3; // fan output pin
int motionState = 0; // motion sensor state
int fanState = 0; // fan state

void setup() {
  pinMode(motionSensor, INPUT);
  pinMode(fanPin, OUTPUT);
}

void loop() {
  motionState = digitalRead(motionSensor); // read motion sensor state
  if (motionState == HIGH) { // if motion is detected
    fanState = HIGH; // turn on the fan
  } else { // if no motion is detected
    fanState = LOW; // turn off the fan
  }
  digitalWrite(fanPin, fanState); // set fan state
  delay(100); // wait for a short period before checking again
}  