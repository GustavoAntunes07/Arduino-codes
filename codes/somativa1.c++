// Definindo os pinos para os sensores e LEDs
#define sensorU A0     // Pino A0 para o sensor de umidade
#define temp A1         // Pino A1 para o sensor de temperatura
#define ledGreen 12     // Pino 12 para o LED verde
#define ledRed 9        // Pino 9 para o LED vermelho
// Definição das variáveis de controle
int estadoUmidade;    // Armazena o valor lido do sensor de umidade
int estadoTemp;       // Armazena o valor lido do sensor de temperatura
int umidade;          // Armazena o valor de umidade convertido
int valorTemp;        // Armazena o valor de temperatura convertido
// Limites de temperatura e umidade para acionar LEDs
const int LowTemp = 24;        // Temperatura baixa (em °C) para acionar o LED vermelho
const int HighTemp = 28;       // Temperatura alta (em °C) para acionar o LED verde
const int LowUmidade = 65;     // Umidade baixa (%) para acionar o LED vermelho
const int HighUmidade = 75;    // Umidade alta (%) para acionar o LED verde

void setup() {
  // Inicializando os pinos
  pinMode(sensorU, INPUT);   // O pino do sensor de umidade é de entrada
  pinMode(temp, INPUT);       // O pino do sensor de temperatura é de entrada
  pinMode(ledRed, OUTPUT);    // O pino do LED vermelho é de saída
  pinMode(ledGreen, OUTPUT);  // O pino do LED verde é de saída
  
  Serial.begin(9600);         // Inicializando a comunicação serial a 9600 bps
}

void loop() {
  // Lendo os valores dos sensores analógicos
  estadoUmidade = analogRead(sensorU);   // Lê o valor do sensor de umidade (0-1023)
  estadoTemp = analogRead(temp);         // Lê o valor do sensor de temperatura (0-1023)
  
  // Convertendo os valores dos sensores para escalas utilizáveis
  umidade = map(estadoUmidade, 200, 1023, 100, 0);  // Mapeia o valor da umidade (escala inversa)
  valorTemp = map(estadoTemp, 70, 82, 20, 33);       // Mapeia o valor da temperatura (escala em °C)
  // Enviando os valores lidos para o monitor serial
  Serial.println(estadoTemp);  // Valor bruto da temperatura lida
  Serial.print(umidade);       // Valor da umidade em %
  Serial.println("%");         // Exibe o símbolo de porcentagem
  Serial.print(valorTemp);     // Valor da temperatura em °C
  Serial.println("°");         // Exibe o símbolo de grau
  Serial.println("------------");
  delay(600);
  // Lógica de controle de LEDs com base nas condições de temperatura e umidade
  if (valorTemp >= HighTemp && umidade >= HighUmidade) {  // Se a temperatura e a umidade estiverem altas
    digitalWrite(ledGreen, HIGH);   // Aciona o LED verde
    digitalWrite(ledRed, LOW);      // Desliga o LED vermelho
  } else if (valorTemp <= LowTemp && umidade <= LowUmidade) {  // Se a temperatura e a umidade estiverem baixas
    digitalWrite(ledGreen, LOW);    // Desliga o LED verde
    digitalWrite(ledRed, HIGH);    // Aciona o LED vermelho
  }
}