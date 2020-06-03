// quando o sensor detecta objeto, envia 0. nao detecta, envia 1.

#define sensor 2


void setup() {
  Serial.begin(9600);
  pinMode (sensor, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor), infra, CHANGE); //Interrupção
}

void loop() {
}

void infra(){
  int estado = digitalRead(sensor);
  if (estado==0) {
    Serial.println("Persiana fechada");
  }
  else {
    Serial.println("Persiana aberta");
  }
  delay(1000);
}
