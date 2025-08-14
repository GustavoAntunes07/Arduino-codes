#define ldr A0
#define led2 2
#define led3 3
#define led4 4
#define led5 5
#define led6 6
int valorLdr;
int porcentagemLdr;

void setup()
{
    pinMode(ldr, INPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    valorLdr = analogRead(ldr);
    porcentagemLdr = map(valorLdr, 54, 974, 0, 100);
    Serial.println(valorLdr);
    Serial.print(porcentagemLdr);
    Serial.println("%");
    Serial.println("---------------");
    delay(600);

    if (porcentagemLdr <= 95) {
        digitalWrite(led2, HIGH);
    } else {
        digitalWrite(led2, LOW);
    }
    if (porcentagemLdr <= 89) {
        digitalWrite(led3, HIGH);
    } else {
        digitalWrite(led3, LOW);
    }
    if (porcentagemLdr <= 75) {
        digitalWrite(led4, HIGH);
    } else {
        digitalWrite(led4, LOW);
    }
    if (porcentagemLdr <= 60) {
        digitalWrite(led5, HIGH);
    } else {
        digitalWrite(led5, LOW);
    }
    if (porcentagemLdr <= 50) {
        digitalWrite(led6, HIGH);
    } else {
        digitalWrite(led6, LOW);
    }
}