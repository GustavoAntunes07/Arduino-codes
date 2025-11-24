#define M1 9 // porta IN2 ponte H - controle de velocidade
#define M2 11 // porta IN4 ponte H - controle de velocidade
#define dir1 8 // porta IN1 ponte H - controle de direção
#define dir2 10 // porta IN3 ponte H - controle de direção
#define S1 7 // sensor infravermelho
#define S2 6
bool Sensor1 = 0;
bool Sensor2 = 0;
int velocidade = 100;

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  Serial.begin(9600);
}

void loop() {
  Sensor1 = digitalRead(S1);
  Sensor2 = digitalRead(S2);
  Serial.println(Sensor1);
  Serial.println(Sensor2);
  Serial.println("-------------");

  if(Sensor1 == 0 && Sensor2 == 0) {
    analogWrite(M1, velocidade);
    analogWrite(M2, velocidade);
  } else if (Sensor1 == 1 && Sensor2 == 0) {
    analogWrite(M1, 0);
    analogWrite(M2, velocidade);
  } else if (Sensor1 == 0 && Sensor2 == 1) {
    analogWrite(M1, velocidade);
    analogWrite(M2, 0);
  } else if(Sensor1 == 1 && Sensor2 == 1){
    analogWrite(M1, 0);
    analogWrite(M2, 0);
  }
}
