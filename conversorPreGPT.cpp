//VALOR 12BITS=>AR=>valorAnalog
//VALOR REAL BATERIA => valorRealBateria
#include <LiquidCrystal.h>
//const int pinADC = 36;

float valorRealBateria = 8.4; // Definido como valor inicial para a simulação funcionar
float valorReferencia = 8.4;
float porcentagemBateria = ((valorRealBateria/valorReferencia)*100);
void setup(){
  Serial.begin(9600);
  //pinMode(pinADC, INPUT);
}

void loop(){
  //faz a leitura do valor de 12 bits analogico obtido pelo pino adc 
  //float valorLidoADC = analogRead(pinADC);

  // Na simulação, a porcentagem é calculada antes de decrementarmos o valor
  
  //PRINT VALOR DA TENSAO DA BATERIA:
  Serial.print("Tensão da Bateria: ");
  Serial.print(valorRealBateria);
  Serial.print("V ");

  //CASO 1 => BATERIA 8,4V - 8V --> 100%
  if (8.4>=valorRealBateria && valorRealBateria>8){
    Serial.print("Bateria: "); 
    Serial.print(porcentagemBateria);
    Serial.println("%");
    Serial.println("STATUS: OK - BATERIA SEGURA");
  }
  //CASO 2 => BATERIA 8 - 7,4V --> 80%
  else if (8>=valorRealBateria && valorRealBateria>7.4){
    Serial.print("Bateria: "); 
    Serial.print(porcentagemBateria);
    Serial.println("%");
    Serial.println("STATUS: OK - BATERIA SEGURA");    
  }
  //CASO 3 => BATERIA 7,4V - 6,8V --> 60%
  else if (7.4>=valorRealBateria && valorRealBateria > 6.8){
    Serial.print("Bateria: "); 
    Serial.print(porcentagemBateria);
    Serial.println("%");
    Serial.println("STATUS: ALERTA - BATERIA BAIXA"); 
  }
  //CASO 4 => BATERIA 6,8V - 6,4V --> 20%
  else if (6.8>=valorRealBateria && valorRealBateria > 6.4){
    Serial.print("Bateria: "); 
    Serial.print(porcentagemBateria);
    Serial.println("%");
    Serial.println("STATUS: ALERTA - RECARREGAR BATERIA");    
  }
  //CASO 5 => BATERIA ABAIXO DE 6,4V --> 0%
  else if (valorRealBateria <= 6.4){ // Ajustado para <= para incluir o valor 6.4 exato
    Serial.print("Bateria: "); 
    Serial.print(porcentagemBateria);
    Serial.println("%");
    Serial.println("STATUS: CRÍTICO - BATERIA DANIFICADA");     
  }
  
  // Decrementa o valor para a simulação atualizar no próximo ciclo do loop

  valorRealBateria -= 0.1;
  // Trava em 0V para evitar que a simulação mostre tensões negativas infinitas
  if (valorRealBateria < 0) {
    valorRealBateria = 0;
  }
  
  delay(900);
}
