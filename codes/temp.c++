#define temp A0
float valorTemp;
float temp2;

void setup() {
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorTemp = analogRead(temp);
  temp2 = map(valorTemp, 420, 550, 18, 24);
  Serial.print(temp2);
  Serial.println("°C");
  Serial.println("----------------------");
  delay(1000);
}
