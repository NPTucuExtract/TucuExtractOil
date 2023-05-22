// Define os pinos do Arduino
int relePin = 2;      // Pino do relé
int botaoPin = 3;     // Pino do botão

// Variáveis para armazenar estados
int releEstado = LOW; // Estado atual do relé (inicialmente desligado)
int botaoPressionado = 0; // Flag para indicar se o botão foi pressionado

void setup() {
  // Configura os pinos do relé e do botão
  pinMode(relePin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP);
}

void loop() {
  int botaoEstado = digitalRead(botaoPin);

  // Verifica se o botão foi pressionado
  if (botaoEstado == LOW) {
    botaoPressionado = 1;
    delay(100); // Pequeno atraso para evitar leituras incorretas do botão
  }

  // Verifica se o botão foi solto e executa ação correspondente
  if (botaoPressionado && botaoEstado == HIGH) {
    releEstado = !releEstado; // Inverte o estado do relé
    digitalWrite(relePin, releEstado);
    botaoPressionado = 0; // Reinicia a flag de botão pressionado
  }
}
