#include "Servo.h"
#define pot A0
Servo eixo;
int estadoPot;
int potAngle;

void setup()
{
  pinMode(pot, INPUT);
  eixo.attach(5);
  eixo.write(0);
}

void loop()
{
  estadoPot = analogRead(pot);
  potAngle = map(estadoPot, 0, 1023, 0, 180);
  eixo.write(potAngle);
  delay(100);
}