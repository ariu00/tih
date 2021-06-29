int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int voltPin = A0;
int td;

void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(voltPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
td = analogRead(voltPin);
Serial.println(td);

while (true){

  td = analogRead(voltPin);
  Serial.println(td);
  
  digitalWrite(led1,HIGH);
  delay(td);
  digitalWrite(led1,LOW);
  delay(td);
  td = analogRead(voltPin);
  Serial.println(td);

  digitalWrite(led2,HIGH);
  delay(td);
  digitalWrite(led2,LOW);
  delay(td);
  td = analogRead(voltPin);
  Serial.println(td);

  digitalWrite(led3,HIGH);
  delay(td);
  digitalWrite(led3,LOW);
  delay(td);
  td = analogRead(voltPin);
  Serial.println(td);

  digitalWrite(led4,HIGH);
  delay(td);
  digitalWrite(led4,LOW);
  delay(td);
  Serial.println(td);
  td = analogRead(voltPin);
  }

}
