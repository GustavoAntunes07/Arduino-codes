#define led 2
#define buttonPlus 12
#define buttonMinus 13
#define buttonReset 8
int count = 0;
int buttonPState;
int buttonMState;
int buttonRState;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buttonPlus, INPUT);
  pinMode(buttonMinus, INPUT);
  pinMode(buttonReset, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonPState = digitalRead(buttonPlus);
  buttonMState = digitalRead(buttonMinus);
  buttonRState = digitalRead(buttonReset);
  if (buttonPState == HIGH){
    count = count + 1;
  } else if (buttonMState == HIGH) {
    count = count - 1;
  } else if (buttonRState == HIGH){
    count = 0;
  }
  
  if (buttonRState == HIGH){
    count = 0;
  }
  
  if (count >= 10){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  Serial.println(count);
  Serial.println("------------");
  delay(600);
}