int Dpin =2;
float Apin=A0;
int Lpin =13;
int Dval;
float Aval;

void setup() {
  // put your setup code here, to run once:
  pinMode(Dpin,INPUT);
  pinMode(Apin,INPUT);
  pinMode(Lpin,OUTPUT);
  Serial.begin(9600);
  Serial.println("The system is warming up");
  delay(20000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dval=digitalRead(Dpin);
  Aval=analogRead(Apin);
  Serial.print("Digital value");
  Serial.print(Dval);
  Serial.print("          Analog Value");
  Serial.println(Aval);
  if(Aval>=400){
    digitalWrite(Lpin,HIGH);
    Serial.print("Gas is detected");
  }else{
    digitalWrite(Lpin,LOW);
    Serial.print("Gas is not detected");
  }delay(1000);
}