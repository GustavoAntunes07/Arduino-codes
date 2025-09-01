#define temp A0
#define led 2
float valorTemp;

void setup() {
  pinMode(temp, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorTemp = analogRead(temp);
  valorTemp = map(valorTemp, 420, 550, 18, 24);
  
  if (valorTemp >= 20 && valorTemp <= 22) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.print(valorTemp);
  Serial.println("°C");
  Serial.println("----------------------");
  delay(1000);
}