int  myvalue=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  myvalue = random(100);
  Serial.println("this value is:");
  Serial.println(myvalue);
  delay(1000);

}
