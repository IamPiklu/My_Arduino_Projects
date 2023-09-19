int  a=0;
int b=0;
int z;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  a = random(100);
  b = random(100);
  z=(a+b);
  Serial.print(a);
  Serial.print("+");
  Serial.print(b);
  Serial.print("=");
  Serial.println(z);

  delay(1000);

}
