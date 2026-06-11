#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define col 16
#define lin 2
#define ende 0x27;
LiquidCrystal_I2C lcd(0x27,16,2);

bool v = LOW;
int valorBinario = 4095;
float valorRealBateria = (valorBinario/487.5);      // Valor inicial da simulação
float valorReferencia = 8.4;
float porcentagemBateria;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  // pinMode(pinADC, INPUT);
}

void loop() {
  lcd.setCursor(1,0);
  // Recalcula a porcentagem a cada leitura
  porcentagemBateria = (valorRealBateria / valorReferencia) * 100.0;

  // PRINT VALOR DA TENSAO DA BATERIA
  lcd.setCursor(0,0);
  lcd.print("Tensao: ");
  lcd.print(valorRealBateria, 1); // Exibe 1 casa decimal
  lcd.print("V ");

  //PRINT PORCENTAGEM DA BATERIA
  lcd.setCursor()

  // CASO 1 => BATERIA 8,4V - 8V --> 100%
  if (8.4 >= valorRealBateria && valorRealBateria > 8.0) {
    lcd.setCursor(0,1);
    lcd.print("Bateria: ");
    lcd.print(porcentagemBateria, 1);
    lcd.print("%");
  }

  // CASO 2 => BATERIA 8V - 7,4V --> 80%
  else if (8.0 >= valorRealBateria && valorRealBateria > 7.4) {
    lcd.setCursor(0,1);
    lcd.print("Bateria: ");
    lcd.print(porcentagemBateria, 1);
    lcd.print("%");
  }

  // CASO 3 => BATERIA 7,4V - 6,8V --> 60%
  else if (7.4 >= valorRealBateria && valorRealBateria > 6.8) {
    lcd.setCursor(0,1);
    lcd.print("Bateria: ");
    lcd.print(porcentagemBateria, 1);
    lcd.print("%");
  }

  // CASO 4 => BATERIA 6,8V - 6,4V --> 20%
  else if (6.8 >= valorRealBateria && valorRealBateria > 6.4) {
    lcd.setCursor(0,1);
    lcd.print("Bateria: ");
    lcd.print(porcentagemBateria, 1);
    lcd.print("%");
  }

  // CASO 5 => BATERIA ABAIXO DE 6,4V --> 0%
  else if (valorRealBateria <= 6.4) {
    lcd.setCursor(0,1);
    lcd.print("Bateria: ");
    lcd.print(porcentagemBateria, 1);
    lcd.print("%");
  }

  lcd.println();

  // Simulação: reduz 0,1 V por ciclo
  valorRealBateria -= 0.1;

  // Evita tensões negativas
  if (valorRealBateria <= 0.0) {
    valorRealBateria = 0.0;
    v = HIGH;
    if(v == HIGH){ lcd.print("Bateria: "); lcd.print(valorRealBateria); lcd.println("%"); delay(1000); exit(0);}
  }

  delay(1000);

  lcd.clear();
}
