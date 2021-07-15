#include <Servo.h>

int servoPin = 5;
int servoVal;
int greenPin = 8;
int redPin = 9;
int buzzpin = 11;
int buzzvol = 5;
Servo miServo;


void setup() {
  // put your setup code here, to run once:

pinMode(greenPin,OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
miServo.attach(servoPin);
miServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(buzzpin,0);
  Serial.println("Servo position?: ");
  digitalWrite(redPin,LOW);
  while (Serial.available() == 0 ) {
    digitalWrite(greenPin,HIGH);
  }
  digitalWrite(greenPin,LOW);
  analogWrite(buzzpin,buzzvol);
  digitalWrite(redPin,HIGH);
  servoVal = Serial.parseInt();
  Serial.print("Writing value: ");
  Serial.println(servoVal);
  miServo.write(servoVal);
}
