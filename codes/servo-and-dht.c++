#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define sensor A0
#define DHTTYPE DHT11
DHT dht(sensor, DHTTYPE);
Servo eixo;

int angle;

void setup() {
  eixo.write(0);
  eixo.attach(3);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  angle = map(t, 20, 40, 0, 90);

  Serial.println(h);
  Serial.println(t);
  Serial.println("-------------");
  eixo.write(angle);
  delay(600);
}
