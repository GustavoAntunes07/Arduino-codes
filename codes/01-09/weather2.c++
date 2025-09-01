const int sensor = A0;
int leituraADC;
float tensao, temp;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  leituraADC = analogRead(sensor);
  tensao = leituraADC * (5.0 / 1023.0);
  temp = tensao / 0.01;
  Serial.print(temp);
  Serial.println("°C");
  Serial.println("-------------------");
  delay(1000);
}