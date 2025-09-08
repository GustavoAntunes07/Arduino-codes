#define ledRed 6
#define ledGreen 5
#define SensorD 7
#define rele 8
int SensorA = A0;
int umidadeA;
int umidadeD;
int Porcentagem;

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(SensorA, INPUT);
  pinMode(SensorD, INPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  umidadeA = analogRead(SensorA);
  umidadeD = digitalRead(SensorD);
  Porcentagem = map(umidadeA, 280, 1023, 100, 0);
  Serial.print(Porcentagem);
  Serial.println("%");
  Serial.println(umidadeA);
  Serial.println(umidadeD);
  Serial.println("-----------");
  delay(1000);

  if (Porcentagem >= 70) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(rele, HIGH);
  } else {
    digitalWrite(ledGreen, LOW);
  }
  
  if (umidadeD == 1){
    digitalWrite(ledRed, HIGH);
    digitalWrite(rele, LOW);
  } else {
    digitalWrite(ledRed, LOW);
  }
}