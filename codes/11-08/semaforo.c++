// semaforo

int LedSRed = 2;
int LedSYellow = 3;
int LedSGreen = 4;
int LedRed = 6;
int LedGreen = 7;
int Button = 8;
int estadoButton;

void setup()
{
  pinMode(LedSRed, OUTPUT);
  pinMode (LedSYellow, OUTPUT);
  pinMode (LedSGreen, OUTPUT);
  pinMode (LedRed, OUTPUT);
  pinMode (LedGreen, OUTPUT);
  pinMode (Button, INPUT);
}

void loop()
{
  estadoButton = digitalRead(Button);
  
  if (estadoButton == HIGH){
  digitalWrite(LedSRed, HIGH);
  delay(2000); 
  digitalWrite(LedSRed, LOW);
  delay(1000);
  digitalWrite(LedSGreen, HIGH);
  delay(2000);
  digitalWrite(LedSGreen, LOW);
  delay(1000); 
  digitalWrite(LedSYellow, HIGH);
  delay(1000); 
  digitalWrite(LedSYellow, LOW);
  delay(1000); 
  } else {
   digitalWrite(LedRed, HIGH);
   delay(2000);
   digitalWrite(LedRed, LOW);
   delay(1000);
   digitalWrite(LedGreen, HIGH);
   delay(2000);
   digitalWrite(LedGreen, LOW);
   delay(1000);
  }
}