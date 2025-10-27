#include <Servo.h>
#define mic A0
#define led 5
Servo eixo;

void setup() {
  eixo.attach(6);
  eixo.write(0);
  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int State = analogRead(mic);
  State = map(State, 1023, 0, 0, 1023);
  Serial.println(State);
  Serial.println("--------------");
  if(State >= 600){
    digitalWrite(led, HIGH);                        
  } else {
    digitalWrite(led, LOW);
  } 
  // int angle = State;
  // angle = map(angle, 1023, 0, 0, 180);
  // eixo.write(angle);
  delay(120);
}