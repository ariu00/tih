//button pins
int redbPin = 2;
int greenbPin = 3;
int bluebPin = 4;

//Led pins
int redlPin = 9;
int greenlPin = 10;
int bluelPin = 11;

//potentiometer
int Ppin = A0;
int Ppinval;

//present sensing variables
int redbval;
int greenbval;
int bluebval;

//past value sensing
int predBval = 1;
int pgreenBval;
int pblueBval;

//toggle variables
int redtpval=1;
int greentpval;
int bluetpval;

//color value
int redcval;
int bluecval;
int greencval;



void setup() {
  // put your setup code here, to run once:
//buttons
pinMode(redbPin,INPUT);
pinMode(greenbPin,INPUT);
pinMode(bluebPin,INPUT);
digitalWrite(redbPin,HIGH);
digitalWrite(greenbPin,HIGH);
digitalWrite(bluebPin,HIGH);

pinMode(Ppin, INPUT);

Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

redbval = digitalRead(redbPin);
greenbval = digitalRead(greenbPin);
bluebval = digitalRead(bluebPin);

//for red button
if (redbval == 1 && predBval == 0){
  if (redtpval == 1){
      redtpval = 0;
  }
  else{
  redtpval = 1;
  
  }
}

//for green button
if (greenbval == 1 && pgreenBval == 0){
  if (greentpval == 1){
      greentpval = 0;
  }
  else{
  greentpval = 1;
  
  }
}

//for blue button
if (bluebval == 1 && pblueBval == 0){
  if (bluetpval == 1){
      bluetpval = 0;
  }
  else{
  bluetpval = 1;
  
  }
}

Serial.print(redtpval);
Serial.print(greentpval);
Serial.print(bluetpval);

predBval = redbval;
pgreenBval = greenbval;
pblueBval = bluebval;

if (redtpval == 0){
  Ppinval = analogRead(Ppin);
  redcval = (redlPin, (255./1023.) * Ppinval);
  analogWrite(redlPin,redcval);
  }

if (greentpval == 0){
  Ppinval = analogRead(Ppin);
  greencval = (greenlPin, (255./1023.) * Ppinval);
  analogWrite(greenlPin, greencval);
  }

if (bluetpval == 0){
  Ppinval = analogRead(Ppin);
  bluecval = (bluelPin, (255./1023.) * Ppinval);
  analogWrite(bluelPin, bluecval);
  }

Serial.print(" ");
Serial.print("R: ");
Serial.print(redcval);
Serial.print(", ");

Serial.print(" ");
Serial.print("G: ");
Serial.print(greencval);
Serial.print(", ");

Serial.print(" ");
Serial.print("B: ");
Serial.println(bluecval);

delay(200);
}
