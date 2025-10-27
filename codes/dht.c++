#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#define sensor A0
#define DHTTYPE DHT11
#define ledH 8
#define ledT 7
#define buzzer 10

DHT dht(sensor, DHTTYPE);
int count;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(ledH, OUTPUT);
  pinMode(ledT, OUTPUT);
  pinMode(buzzer, OUTPUT);
  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INICIALIZANDO");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  lcd.setCursor(0, 1);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("umidade: ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("temperura: ");
  lcd.print(t);

  // for (count = 10; count > 8;) {
  //   delay(300);
  //   lcd.scrollDisplayRight();
  // }

  delay(2000);

  if (h < 50) {
    digitalWrite(ledH, HIGH);
  } else {
    digitalWrite(ledH, LOW);
  };

  if (t > 28) {
    digitalWrite(ledT, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(ledT, LOW);
    digitalWrite(buzzer, LOW);
  }
}