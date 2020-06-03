#include <avr/sleep.h> //Biblioteca Sleep

#define pinLDR 2 //pino do LDR

void setup() {
  pinMode(13, OUTPUT); //define pino do LED
  pinMode(pinLDR, INPUT); //define pino do LDR
  Serial.begin(9600); // Inicia monitor serial
}

void loop() {
  int luz = digitalRead(pinLDR); //salva o valor lido na variável 
  Serial.println(luz); //printa a informação lida
  digitalWrite(13, HIGH); //desliga o LED
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
  digitalWrite(13, LOW); //liga o led
  attachInterrupt(digitalPinToInterrupt(pinLDR), ldr, FALLING); //Interrupção "mudança" no pinLDR, vai ativar a função ldr.
  sleep_cpu();
}
