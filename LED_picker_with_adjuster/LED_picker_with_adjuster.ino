int potpin = A0;
int potval;

int l1 = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;
int l5 = 6;

int buzz = 9;
int bvol = 15;

int btnp = 8;
int btnv = 1;

int cspd;

int lv;

void setup() {
  // put your setup code here, to run once:
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);

pinMode(buzz,OUTPUT);

pinMode(potpin,INPUT);
pinMode(btnp,INPUT);
digitalWrite(btnp,HIGH);

Serial.begin(9600);
}

void loop() {
 //  put your main code here, to run repeatedly:
  potval = analogRead(potpin);
  cspd = potval;

  btnv = digitalRead(btnp);
 
  if (btnv == 1){
  lv = 1;
  digitalWrite(l1,HIGH);
  delay(cspd);
  digitalWrite(l1,LOW);
  delay(cspd);
  }

  btnv = digitalRead(btnp);

  if (btnv == 1){
  lv = 2;
  digitalWrite(l2,HIGH);
  delay(cspd);
  digitalWrite(l2,LOW);
  delay(cspd);
  }

  btnv = digitalRead(btnp);

  if (btnv == 1){

  lv = 3;
  digitalWrite(l3,HIGH);
  delay(cspd);
  digitalWrite(l3,LOW);
  delay(cspd);
  }

  btnv = digitalRead(btnp);

  if (btnv == 1){
  lv = 4;
  digitalWrite(l4,HIGH);
  delay(cspd);
  digitalWrite(l4,LOW);
  delay(cspd);
  }

  btnv = digitalRead(btnp);

  if (btnv == 1){
  lv = 5;
  digitalWrite(l5,HIGH);
  delay(cspd);
  digitalWrite(l5,LOW);
  delay(cspd);
  }
  Serial.println(lv);
  
  while(btnv == 0){
  
    if (lv == 1){
      digitalWrite(l1,HIGH);
      analogWrite(buzz,bvol);
      }
      
     if (lv == 2){
      digitalWrite(l2,HIGH);
      analogWrite(buzz,bvol);
      }

     if (lv == 3){
      digitalWrite(l3,HIGH);
      analogWrite(buzz,bvol);
      }

     if (lv == 4){
      digitalWrite(l4,HIGH);
      analogWrite(buzz,bvol);
      }

     if (lv == 5){
      digitalWrite(l5,HIGH);
      analogWrite(buzz,bvol);
      }
      
      btnv = digitalRead(btnp);
   }

digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
digitalWrite(l3,LOW);
digitalWrite(l4,LOW);
digitalWrite(l5,LOW);
analogWrite(buzz,0);


}
