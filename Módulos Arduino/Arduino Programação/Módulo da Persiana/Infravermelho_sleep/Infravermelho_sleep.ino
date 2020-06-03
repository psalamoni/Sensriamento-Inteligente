// quando o sensor detecta objeto, envia 0. nao detecta, envia 1.

#include <avr/sleep.h>

#define sensor 2


void setup() {
  Serial.begin(9600);
  pinMode (sensor, INPUT);
  pinMode(13, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção
}

void loop() {
  int estado = digitalRead(sensor); //Lê um valor e guarda 
  Serial.println(estado); //Printa o valor lido
  digitalWrite(13, HIGH); //Liga o LED
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
  digitalWrite(13, LOW); //Desliga o LED
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção
  sleep_cpu();
}
