int greenLed = 9;
int brioff = 0;
int bri1 = 25;
int bri2 = 110;
int bri3 = 150;
int bri4 = 255;
int wait = 1000;
int waith = 4000;

void setup() {
  // put your setup code here, to run once:

pinMode(greenLed,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//inhale
analogWrite(greenLed, bri1);
delay(wait);
analogWrite(greenLed, bri2);
delay(wait);
analogWrite(greenLed, bri3);
delay(wait);
//inhale hold
analogWrite(greenLed, bri4);
delay(waith);

//exhale
analogWrite(greenLed, bri3);
delay(wait);
analogWrite(greenLed, bri2);
delay(wait);
analogWrite(greenLed, bri1);
delay(wait);
analogWrite(greenLed, brioff);
delay(waith);
}
