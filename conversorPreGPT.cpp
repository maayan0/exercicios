// VALOR 12BITS=>AR=>valorAnalog
// VALOR REAL BATERIA => valorRealBateria

#include <LiquidCrystal.h>

// const int pinADC = 36;

float valorRealBateria = 8.4;      // Valor inicial da simulação
float valorReferencia = 8.4;
float porcentagemBateria;

void setup() {
  Serial.begin(9600);
  // pinMode(pinADC, INPUT);
}

void loop() {

  // Recalcula a porcentagem a cada leitura
  porcentagemBateria = (valorRealBateria / valorReferencia) * 100.0;

  // PRINT VALOR DA TENSAO DA BATERIA
  Serial.print("Tensao da Bateria: ");
  Serial.print(valorRealBateria, 1); // Exibe 1 casa decimal
  Serial.print("V ");

  // CASO 1 => BATERIA 8,4V - 8V --> 100%
  if (8.4 >= valorRealBateria && valorRealBateria > 8.0) {
    Serial.print("Bateria: ");
    Serial.print(porcentagemBateria, 1);
    Serial.println("%");
    Serial.println("STATUS: OK - BATERIA SEGURA");
  }

  // CASO 2 => BATERIA 8V - 7,4V --> 80%
  else if (8.0 >= valorRealBateria && valorRealBateria > 7.4) {
    Serial.print("Bateria: ");
    Serial.print(porcentagemBateria, 1);
    Serial.println("%");
    Serial.println("STATUS: OK - BATERIA SEGURA");
  }

  // CASO 3 => BATERIA 7,4V - 6,8V --> 60%
  else if (7.4 >= valorRealBateria && valorRealBateria > 6.8) {
    Serial.print("Bateria: ");
    Serial.print(porcentagemBateria, 1);
    Serial.println("%");
    Serial.println("STATUS: ALERTA - BATERIA BAIXA");
  }

  // CASO 4 => BATERIA 6,8V - 6,4V --> 20%
  else if (6.8 >= valorRealBateria && valorRealBateria > 6.4) {
    Serial.print("Bateria: ");
    Serial.print(porcentagemBateria, 1);
    Serial.println("%");
    Serial.println("STATUS: ALERTA - RECARREGAR BATERIA");
  }

  // CASO 5 => BATERIA ABAIXO DE 6,4V --> 0%
  else if (valorRealBateria <= 6.4) {
    Serial.print("Bateria: ");
    Serial.print(porcentagemBateria, 1);
    Serial.println("%");
    Serial.println("STATUS: CRITICO - BATERIA DANIFICADA");
  }

  Serial.println();

  // Simulação: reduz 0,1 V por ciclo
  valorRealBateria =- 0.1;

  // Evita tensões negativas
  if (valorRealBateria < 0.0) {
    valorRealBateria = 0.0;
  }

  delay(900);
}
