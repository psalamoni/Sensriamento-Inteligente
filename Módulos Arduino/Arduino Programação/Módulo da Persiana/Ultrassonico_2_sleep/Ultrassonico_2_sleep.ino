//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
#include <TimerOne.h>
#include <avr/sleep.h>
//#include <CurieTimerOne.h>

//Define os pinos para o trigger e echo
#define pino_trigger 3
#define pino_echo 2
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
 
void loop()
{
  //Le as informacoes do sensor
  float tempo = ultrasonic.timing();
  float distancia = ultrasonic.convert(tempo, Ultrasonic::CM);
  Serial.println(distancia);
  digitalWrite(13, LOW);
  delay(1000);
  sleep();
}

void ultra() {
  sleep_disable();
  Timer1.detachInterrupt();
}

void sleep(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  digitalWrite(13, HIGH);
  sleep_cpu();
  Timer1.initialize(60000000);
  Timer1.attachInterrupt(ultra);
}
