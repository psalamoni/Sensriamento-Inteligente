#define pinChave 2 //PINO DIGITAL UTILIZADO PELA CHAVE FIM DE CURSO
// com ele acionado, digital read é low
// Quando ele estiver pressionado = LOW

void setup() {
Serial.begin(9600);
pinMode(pinChave, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
attachInterrupt(digitalPinToInterrupt(pinChave), chave, CHANGE); //Interrupção
}

void loop(){
}

void chave() {
  int janela = digitalRead(pinChave);
  if(janela == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      Serial.println("janela fechada");
  }
  else{ 
    Serial.println("janela aberta"); 
  }
}
