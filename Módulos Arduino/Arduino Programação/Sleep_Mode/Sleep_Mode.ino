#include <avr/sleep.h>

#define interrupcao 2
#define led 13
 
void setup()
{
  // Define o pino 2 como entrada e ativa o resistor de pull-up
  pinMode(interrupcao, INPUT_PULLUP);

  // Define o LED como saida
  pinMode(led, OUTPUT);  
}
 

 
void loop()
{
  // Código do blink
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
  delay(1000);

  // Manda o Arduino dormir
  dormir();
}


void acordar(){
  // Desabilita o sleep
  sleep_disable();

  // Desabilita a interrupção
  detachInterrupt(0);  
}


void dormir(){
    // Define o modo de sleep
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);  

    // Habilita o sleep
    sleep_enable(); 

    // Cria a interrupção com a função auxiliar acordar
    attachInterrupt(digitalPinToInterrupt(interrupcao), acordar, LOW); 

    // Manda o Arduino dormir
    sleep_cpu();           
}
