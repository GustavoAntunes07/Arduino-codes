#define sensorU A1
#define sensorL A0
#define rele 8
int estadoSensorU;
int estadoSensorL;
int valorUmidade;

const int LowLuz = 500;
const int LowUmidade = 30;
const int HighUmidade = 70;

void setup() {
  pinMode(sensorU, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estadoSensorU = analogRead(sensorU);
  estadoSensorL = analogRead(sensorL);
  valorUmidade = map(estadoSensorU, 0, 1023, 0, 100);
  Serial.print(valorUmidade);
  Serial.println("%");
  Serial.println(estadoSensorL);
  Serial.println("------------"); 
  delay(600);
  
  if (valorUmidade <= LowUmidade && estadoSensorL < LowLuz) {
    digitalWrite(rele, HIGH);
  } else if(valorUmidade >= HighUmidade) {
    digitalWrite(rele, LOW);
  }
}