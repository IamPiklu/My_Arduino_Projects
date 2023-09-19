#include <avr/io.h>

long unsigned int lowIn;
long unsigned int pause = 500;
boolean lockLow = true;
boolean takeLowTime;

const int pSuhu = A0;
float suhu, outputlm, adc;
int pirPin = 12;
int pirPos = 13;
int kipas = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(pirPos, OUTPUT);
  pinMode(kipas, OUTPUT);
  digitalWrite(pirPos, LOW); // Change to LOW to turn off the PIR sensor initially
  pinMode(pSuhu, INPUT);

  while (digitalRead(pirPin) == HIGH) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("SENSOR ACTIVE");
}

void lm35() {
  adc = analogRead(pSuhu);
  suhu = adc / 2.0479;
  outputlm = adc * 4.883;
  if (suhu >= 25) {
    analogWrite(kipas, 50);
    Serial.println("Kecepatan=50");
  }
  if (suhu >= 30) {
    analogWrite(kipas, 100);
    Serial.println("Kecepatan=100");
  }
  if (suhu >= 35) {
    analogWrite(kipas, 150);
    Serial.println("Kecepatan=150");
  }
  if (suhu >= 40) {
    analogWrite(kipas, 200);
    Serial.println("Kecepatan=200");
  }
  if (suhu >= 45) {
    analogWrite(kipas, 255);
    Serial.println("Kecepatan=255");
  }
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(pirPos, HIGH); // Turn on the PIR sensor
    lm35();
    if (lockLow) {
      lockLow = false;
      Serial.println("---");
      Serial.print("motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pirPin) == LOW) {
    digitalWrite(kipas, LOW);
    if (takeLowTime) {
      lowIn = millis();
      takeLowTime = false;
    }

    if (!lockLow && millis() - lowIn > pause) {
      lockLow = true;
      Serial.print("motion ended at ");
      Serial.print((millis() - pause) / 1000);
      Serial.println(" sec");
      delay(50);
    }
  }
  
  digitalWrite(pirPos, LOW); // Turn off the PIR sensor
  
  Serial.print(", Suhu: ");
  Serial.println(suhu);
  Serial.print(", ADC: ");
  Serial.println(adc);
  delay(1000);
}