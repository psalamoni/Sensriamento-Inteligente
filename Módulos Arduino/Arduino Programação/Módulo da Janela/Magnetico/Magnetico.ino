#define pinMag 2

// HIGH INDICA PRESENÇA DO SENSOR
// LOW INDICA NÃO PRESENÇA DO SENSOR

void setup() {
  pinMode (pinMag, INPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pinMag), mag, CHANGE); //Interrupção
}

void loop() {
}

void mag() {
  int valorMAG = digitalRead(pinMag);
  if(valorMAG == LOW) {
    Serial.println("Janela Aberta");
  }
  else {
    Serial.println("Janela Fechada");
  }
  //delay(600000); // delay de 10 minutos
}
