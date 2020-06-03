#include <Wire.h>
#include <BH1750.h>
#include <avr/sleep.h> //Biblioteca Sleep
#include "SoftwareSerial.h"

#define pino 2 //Pino OUT

BH1750 lightMeter; //Definição de objeto
SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

void setup(){
  pinMode(pino, INPUT); //Define pino sensor como entrada

  Wire.begin();
  lightMeter.begin();

  bluetooth.begin(9600);
}
 
void loop(){
  int acionamento = digitalRead(pino); //Le o valor do sensor PIR
  unsigned lux = lightMeter.readLightLevel();

  bluetooth.println("HUMANOS!!!");
  bluetooth.println(lux);
  
  delay(100);
  sleep(); //ativa a função sleep
}

void movimento() {
  sleep_disable(); //desabilita o modo sleep
  detachInterrupt(0); //desativa o pino de interrupção
}

void sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //ativa o modo sleep
  sleep_enable();
  attachInterrupt(digitalPinToInterrupt(pino), movimento, RISING); //Interrupção "mudança" no pinLDR, vai ativar a função ldr.
  sleep_cpu();
}
