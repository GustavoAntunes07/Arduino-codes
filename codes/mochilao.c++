#include <LiquidCrystal.h>

#define sensorU A1
#define rele 6
#define ledGreen 13
#define ledRed 9
int estadoUmidade;
int umidade;

const int LowUmidade = 30;
const int HighUmidade = 70;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(sensorU, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  estadoUmidade = analogRead(sensorU);
  umidade = map(estadoUmidade, 200, 1023, 100, 0);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("MakerHero");
  lcd.setCursor(3, 1);
  lcd.print(" LCD 16x2");
  Serial.println(estadoUmidade);
  Serial.print(umidade);
  Serial.println("%");
  Serial.println("------------");
  delay(600);

  if (umidade <= LowUmidade) {
    digitalWrite(rele, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    lcd.setCursor(7, 1);  
    lcd.print("LIGADA ");
  } else if (umidade >= HighUmidade) {
    digitalWrite(rele, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    lcd.setCursor(7, 1);
    lcd.print("DESLIGADA");
  }
}