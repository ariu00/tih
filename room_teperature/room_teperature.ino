//initial
#include <Servo.h>
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

Servo gauge;
DHT dht(DHTPIN, DHTTYPE);

//-PINS
//+LCD
#include <LiquidCrystal_I2C.h>
String sinput;
LiquidCrystal_I2C lcd(0x27,16,2);

//+button
int btn = 3;

//present sensing
int presbtnval;
//past sensing
int prevbtnval=1;
//toggle var
String btnval="f";

//+servo
int servopin = 9;

//variables
//servo
float servoposraw;
float servopos;

//button toggle
int used = 0;


//===SETUP===//
void setup() {
  Serial.begin(9600);
  
  Serial.println(F("DHTxx test!"));
  dht.begin();

  //lcd
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on

  //button
  pinMode(btn,INPUT);
  digitalWrite(btn,HIGH);
  
  //servo
  gauge.attach(servopin);
  gauge.write(0);
  
}

//===LOOP===//
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //servo positioning
  servoposraw =(180./60.)*t;
  servopos = 180 - servoposraw;
  gauge.write(servopos);
  Serial.println(servopos);

  //button toggle

  Serial.println(digitalRead(btn));
  Serial.println(btnval);
  
  presbtnval = digitalRead(btn);
  if (presbtnval == 1 && prevbtnval == 0) {
    if (btnval == "c" && used == 0){
      //change to farenheit
       btnval = "f";
       lcd.setCursor(0,0);
       lcd.print("Celcius to F");
       used = 1;
      }
     if (btnval == "f" && used == 0){
      //change to celcius
       btnval = "c";
       lcd.setCursor(0,0);
       lcd.print("Farenheit to C");
       used = 1;
      }
    delay(1000);
    lcd.clear();
    used = 0;  
    }
prevbtnval = presbtnval;

//  //lcdprint
if (btnval == "c"){
  lcd.setCursor(0,0);
  lcd.print("TempC: ");
  lcd.setCursor(6,0);
  lcd.print(t);
}
if (btnval == "f"){
  lcd.setCursor(0,0);
  lcd.print("TempF: ");
  lcd.setCursor(6,0);
  lcd.print(f);
}
  //lcdprint2
  lcd.setCursor(0,1);
  lcd.print("H: ");
  lcd.setCursor(3,1);
  lcd.print(h);
}
