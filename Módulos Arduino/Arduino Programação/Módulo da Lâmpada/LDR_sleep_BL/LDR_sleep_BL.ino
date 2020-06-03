#include <avr/sleep.h> //Biblioteca Sleep
#include "SoftwareSerial.h"

#define pinLDR 2 //pino do LDR
SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

//0 define que o sensor detectou luminosidade
//1 define que o sensor não detectou luminosidade

void setup() {
  pinMode(pinLDR, INPUT); //define pino do LDR

  bluetooth.begin(9600);
}

void loop() {
  int luz = digitalRead(pinLDR); //salva o valor lido na variável 
  bluetooth.println(luz); //envia 1, ou seja, luz ligada
  delay(1000);
  sleep(); //ativa a função sleep
}

void ldr() {
  sleep_disable(); //desabilita o modo sleep
  detachInterrupt(0); //desativa o pino de interrupção
}

void sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //ativa o modo sleep
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(pinLDR), ldr, CHANGE); //Interrupção "nível alto p/ baixo" no pinLDR, vai ativar a função ldr.
  sleep_cpu();
}
