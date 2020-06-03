#include <Wire.h>
#include <BH1750.h>
#include <avr/sleep.h> //Biblioteca Sleep

#define pino 2 //Pino OUT

BH1750 lightMeter; //Definição de objeto

void setup(){
  pinMode(13, OUTPUT); //define pino do LED
  pinMode(pino, INPUT); //Define pino sensor como entrada
  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();
}
 
void loop(){
  int acionamento = digitalRead(pino); //Le o valor do sensor PIR
  unsigned lux = lightMeter.readLightLevel();
  
  Serial.println("HUMANOS!!!"); //printa a informação lida
  Serial.println(lux);
  digitalWrite(13, HIGH); //desliga o LED
  
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
  digitalWrite(13, LOW); //liga o led
  attachInterrupt(digitalPinToInterrupt(pino), movimento, RISING); //Interrupção "mudança" no pinLDR, vai ativar a função ldr.
  sleep_cpu();
}
