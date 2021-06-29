int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int btn4 = 5;
int btn5 = 6;

int btn1v;
int btn2v;
int btn3v;
int btn4v;
int btn5v;

int buzztone1 = 800;
int buzztone2 = 1200;
int buzztone3 = 1400;
int buzztone4 = 1600;
int buzztone5 = 1800;

int buzzpin = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(btn3,INPUT);
pinMode(btn4,INPUT);
pinMode(btn5,INPUT);

digitalWrite(btn1,HIGH);
digitalWrite(btn2,HIGH);
digitalWrite(btn3,HIGH);
digitalWrite(btn4,HIGH);
digitalWrite(btn5,HIGH);

pinMode(buzzpin,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  
btn1v = digitalRead(btn1);
btn2v = digitalRead(btn2);
btn3v = digitalRead(btn3);
btn4v = digitalRead(btn4);
btn5v = digitalRead(btn5);

Serial.println(btn3v);

  if (btn1v == 0){
    digitalWrite(buzzpin,HIGH);
    delayMicroseconds(buzztone1);
    digitalWrite(buzzpin,LOW);
    delayMicroseconds(buzztone1);
  }
  if (btn2v == 0){
    digitalWrite(buzzpin,HIGH);
    delayMicroseconds(buzztone2);
    digitalWrite(buzzpin,LOW);
    delayMicroseconds(buzztone2);  
  }
  if (btn3v == 0){
    digitalWrite(buzzpin,HIGH);
    delayMicroseconds(buzztone3);
    digitalWrite(buzzpin,LOW);
    delayMicroseconds(buzztone3);
  
  }
  if (btn4v == 0){
    digitalWrite(buzzpin,HIGH);
    delayMicroseconds(buzztone4);
    digitalWrite(buzzpin,LOW);
    delayMicroseconds(buzztone4);
    
  }
  if (btn5v == 0){
    digitalWrite(buzzpin,HIGH);
    delayMicroseconds(buzztone5);
    digitalWrite(buzzpin,LOW);
    delayMicroseconds(buzztone5);
  }
}
