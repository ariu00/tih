//Potentiometer
int Ppin = A0;

//LEDs
int l1 = 3;
int l2 = 2;
int l3 = 4;
int l4 = 5;
int l5 = 6;

//buzzer
int Bpin = 9; 

//values

//potentiometer
int potval;

void setup() {
  // put your setup code here, to run once:

pinMode(Ppin,INPUT);

pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);

pinMode(Bpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(Ppin);
  Serial.println(potval);

  analogWrite(Bpin, (255./1023.)*potval);

  if (potval <= 204.6){
  analogWrite(l1,(255./204.6)*potval);
  }
  else if (potval >= 204.6){
    digitalWrite(l1,HIGH);
    }

    
  if (potval >= 409.2){
    digitalWrite(l2,HIGH);
    }
    else{
    digitalWrite(l2,LOW);}
    
  if (potval >= 613.8){
    digitalWrite(l3,HIGH);
    }
    else{
    digitalWrite(l3,LOW);}
    
  if (potval >= 818.4){
    digitalWrite(l4,HIGH);
    }
    else{
    digitalWrite(l4,LOW);}
    
  if (potval >= 1020){
    digitalWrite(l5,HIGH);
    }
    else{
    digitalWrite(l5,LOW);}    
}
