int potPin = A0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redval;
int greenval;
int blueval;

float potRVal;
float potPVal;

String adjustC;

void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potRVal = analogRead(potPin);
potPVal = (255./1023 * potRVal);

//asking questions and looping
Serial.println("What color to adjust");
while (Serial.available()==0){}
adjustC = Serial.readString();

while (adjustC == "red"){
  while (Serial.available() == 0){
  
  potPVal = (255./1023.) * analogRead(potPin);
  redval = potPVal;
  analogWrite(greenPin,greenval);
  analogWrite(bluePin,blueval);
  analogWrite(redPin,redval);

  Serial.print(redval);
  Serial.print(", ");
  Serial.print(greenval);
  Serial.print(", ");
  Serial.println(blueval);
  }

  
  adjustC = "";
  
}

while (adjustC == "green"){
  while (Serial.available() == 0){
  
  potPVal = (255./1023.) * analogRead(potPin);
  greenval = potPVal;
  analogWrite(greenPin,greenval);
  analogWrite(bluePin,blueval);
  analogWrite(redPin,redval);

  Serial.print(redval);
  Serial.print(", ");
  Serial.print(greenval);
  Serial.print(", ");
  Serial.println(blueval);
  }

  
  adjustC = "";
  
}

while (adjustC == "blue"){
  while (Serial.available() == 0){
  
  potPVal = (255./1023.) * analogRead(potPin);
  blueval = potPVal;
  analogWrite(greenPin,greenval);
  analogWrite(bluePin,blueval);
  analogWrite(redPin,redval);

  Serial.print(redval);
  Serial.print(", ");
  Serial.print(greenval);
  Serial.print(", ");
  Serial.println(blueval);
  }

  
  adjustC = "";
  
}



}
