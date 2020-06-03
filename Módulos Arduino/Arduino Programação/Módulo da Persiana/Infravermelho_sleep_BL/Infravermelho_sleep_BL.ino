// quando o sensor detecta objeto, envia 0. nao detecta, envia 1.

#include <avr/sleep.h>
#include "SoftwareSerial.h"

#define sensor 2

SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

void setup() {
  pinMode (sensor, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção

  bluetooth.begin(9600);
}

void loop() {
  int estado = digitalRead(sensor); //Lê um valor e guarda
  bluetooth.println(estado);
  delay(1000);
  sleep(); //Chama função sleep
}

void infra(){
  sleep_disable(); //Desabilita o modo sleep
  detachInterrupt(0); //Desabilita o pino de interrupção
}
 void sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Habilita o modo sleep
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção
  sleep_cpu();
}
