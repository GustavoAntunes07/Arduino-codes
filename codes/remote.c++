#include <Servo.h>
#include <IRremote.h>
#define ledA 5
#define ledR 6
#define ledG 9
Servo eixo;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int angle;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  eixo.write(0);
  eixo.attach(3);
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("----------------");
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(10);
  }

  switch (results.value) {
    case 0xFFA25D:
      digitalWrite(ledA, HIGH);
      break;
    case 0xFF629D:
      digitalWrite(ledR, HIGH);
      break;
    case 0xFF22DD:
      digitalWrite(ledG, HIGH);
      break;
    case 0xFF38C7:
      digitalWrite(ledA, LOW);
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      eixo.write(0);
      break;
  }

  if (results.value == 0xFF10EF && angle < 180) {
    angle++;
  }

  if (results.value == 0xFF5AA5 && angle > 0) {
    angle--;
  }

  eixo.write(angle);
}