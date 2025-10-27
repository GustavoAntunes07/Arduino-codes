#include <Servo.h>
#define pot A0
Servo eixo;
int posAngle;

void setup() {
  eixo.attach(5);
  eixo.write(0);
}

void loop() {
  for (posAngle = 0; posAngle < 90; posAngle++) {
    eixo.write(posAngle);
    delay(20);
  }

  for (posAngle = 90; posAngle >= 0; posAngle--) {
    eixo.write(posAngle);
    delay(20);
  }

  delay(1000);
}