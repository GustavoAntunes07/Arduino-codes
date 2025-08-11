#define pot A0
int valorPot;
// int porcentagemPot;

void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorPot = analogRead(pot);
  // porcentagemPot = map(valorPot, 0, 1023, 0, 100);
  // Serial.print(porcentagemPot);
  // Serial.println("%");
  Serial.println(valorPot);
  delay(1000);
  Serial.println("-----------");
  delay(1000);
}
