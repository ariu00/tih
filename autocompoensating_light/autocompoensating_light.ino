int voltPin = A0;
int voltVal;
int greenPin = 11;
int greenVal;
int greenValF;

void setup() {
  // put your setup code here, to run once:
  pinMode(voltPin,INPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltVal = analogRead(voltPin);
  
  greenVal = (255./1023.)*voltVal;
  greenValF = 255-greenVal;
  analogWrite(greenPin, greenValF);
  Serial.print(greenVal);
  Serial.print(", ");
  Serial.println(greenValF);
}
