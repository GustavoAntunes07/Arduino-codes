int sensorU = A1;
int sensorL = A0;
int estadoSensorU = 0;
int estadoSensorL = 0;
int rele = 3;
int valorUmidade;

const int LowLuz = 500;
const int LowUmidade = 30;
const int HighUmidade = 70;

void setup() {
  pinMode(sensorU, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(rele, OUTPUT);
}

void loop() {
  estadoSensorU = analogRead(sensorU);
  estadoSensorL = analogRead(sensorL);
  valorUmidade = map(estadoSensorU, 0, 1023, 0, 100);

  if (valorUmidade <= LowUmidade && estadoSensorL < LowLuz) {
    do {
      digitalWrite(rele, HIGH);
    } while (valorUmidade < HighUmidade);
  }
}