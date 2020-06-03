#include "SoftwareSerial.h"

SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

// quando o sensor detecta objeto, envia 0. nao detecta, envia 1.

#define sensor 2


void setup() {
  Serial.begin(9600);
  pinMode (sensor, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção

  bluetooth.begin(9600);
}

void loop() {
}

void infra(){
  int estado = digitalRead(sensor);
  if (estado==0) {
    Serial.println("Persiana fechada");
    bluetooth.println("Persiana fechada");
  }
  else {
    Serial.println("Persiana aberta");
    bluetooth.println("Persiana aberta");
  }
  delay(1000);
}
