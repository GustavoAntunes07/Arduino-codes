#define sensorU A0
#define sensorL A1
#define ledGreen 12
#define ledRed 9
int estadoUmidade;
int estadoSensorL;
int umidade;
int valorLuz;

const int LowLuz = 10;
const int LowUmidade = 30;
const int HighUmidade = 70;

void setup() {
  pinMode(sensorU, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  estadoUmidade = analogRead(sensorU);
  estadoSensorL = analogRead(sensorL);
  umidade = map(estadoUmidade, 200, 1023, 100, 0);
  valorLuz = map(estadoSensorL, 0, 430, 0, 100);
  Serial.println(estadoSensorL);
  Serial.print(umidade);
  Serial.println("%");
  Serial.print(valorLuz);
  Serial.println("%");
  Serial.println("------------");
  delay(600);
  
  if (umidade <= LowUmidade && valorLuz < LowLuz) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
  } else if(umidade >= HighUmidade || valorLuz >= LowLuz) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
  }
}