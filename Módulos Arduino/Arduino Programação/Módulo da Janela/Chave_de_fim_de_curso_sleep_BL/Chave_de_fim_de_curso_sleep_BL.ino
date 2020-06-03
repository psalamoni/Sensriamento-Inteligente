#include <avr/sleep.h>
#include "SoftwareSerial.h"

#define pinChave 2 //PINO DIGITAL UTILIZADO PELA CHAVE FIM DE CURSO
// 1 ABERTA
// 0 FECHADA

SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

void setup() {
  pinMode(pinChave, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
    //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)

  bluetooth.begin(9600);
}

void loop(){
  int janela = digitalRead(pinChave); //Lê o valor e salva em uma variável
  bluetooth.println(janela);
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
  attachInterrupt(digitalPinToInterrupt(pinChave), chave, CHANGE); //Interrupção
  sleep_cpu();
}
