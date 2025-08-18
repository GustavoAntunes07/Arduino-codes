#define potRed A0
#define potGreen A1
#define potBlue A2
#define ledRed 6
#define ledGreen 3
#define ledBlue 5
int valorPotRed;
int valorPotGreen;
int valorPotBlue;
int lumiRed;
int lumiGreen;
int lumiBlue;

void setup()
{
  pinMode(potRed, INPUT);
  pinMode(potGreen, INPUT);
  pinMode(potBlue, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valorPotRed = analogRead(potRed);
  valorPotGreen = analogRead(potGreen);
  valorPotBlue = analogRead(potBlue);
  lumiRed = map(valorPotRed, 0, 1023, 0, 255);
  lumiGreen = map(valorPotGreen, 0, 1023, 0, 255);
  lumiBlue = map(valorPotBlue, 0, 1023, 0, 255);
  analogWrite(ledRed, lumiRed);
  analogWrite(ledGreen, lumiGreen);
  analogWrite(ledBlue, lumiBlue);
  Serial.print("Red: ");
  Serial.println(lumiRed);
  Serial.println("------------");
  Serial.print("Green: ");
  Serial.println(lumiGreen);
  Serial.println("------------");
  Serial.print("Blue: ");
  Serial.println(lumiBlue);
  Serial.println("------------");
  delay(1000);
}