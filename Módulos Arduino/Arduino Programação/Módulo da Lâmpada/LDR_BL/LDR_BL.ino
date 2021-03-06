#include "SoftwareSerial.h"

#define pinLDR 2 //Define o pino 2

SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

//0 define que o sensor detectou luminosidade
//1 define que o sensor não detectou luminosidade

void setup() {
  pinMode(pinLDR, INPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pinLDR), ldr, CHANGE); //Interrupção "mudança" no pinLDR, vai ativar a função ldr.

  bluetooth.begin(9600);
}

void loop() {
}

void ldr() {
  int luz = digitalRead(pinLDR); //salva o valor lido na variável 
  if (luz == 0) {
     Serial.println("luz ligada");
     bluetooth.println("luz ligada");
  }
  else{
    Serial.println("luz desligada");
    bluetooth.println("luz desligada");
   
  }
  
}
