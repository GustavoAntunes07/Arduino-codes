#define ldr A0
#define Led 2
int valorLdr;
int porcentagemLdr;

void setup() {
  pinMode(ldr, INPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorLdr = analogRead(ldr);
  porcentagemLdr = map(valorLdr, 54, 974, 0, 100);
  Serial.print(porcentagemLdr);
  Serial.println("%");
  Serial.println(valorLdr);
  delay(1000);
  Serial.println("-----------");
  delay(1000);
  
  if (porcentagemLdr <= 95){
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }
}
