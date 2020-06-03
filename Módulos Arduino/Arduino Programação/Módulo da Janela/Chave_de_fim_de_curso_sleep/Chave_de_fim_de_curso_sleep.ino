#include <avr/sleep.h>

#define pinChave 2 //PINO DIGITAL UTILIZADO PELA CHAVE FIM DE CURSO
// com ele acionado, digital read é low

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(pinChave, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
    //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  attachInterrupt(digitalPinToInterrupt(pinChave), chave, CHANGE); //Interrupção
}

void loop(){
  int janela = digitalRead(pinChave); //Lê o valor e salva em uma variável
  Serial.println(janela); //printa esse valor
  digitalWrite(13, HIGH); //liga o LED
  delay(1000);
  sleep(); //Entra na função sleep
}

void chave() {
  sleep_disable(); //Desativa o sleep
  detachInterrupt(0); //Desativa o pino de interrupção
}

void sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Ativa o modo sleep
  sleep_enable();
  digitalWrite(13, LOW); //Desliga o LED
  attachInterrupt(digitalPinToInterrupt(pinChave), chave, CHANGE); //Interrupção
  sleep_cpu();
}
