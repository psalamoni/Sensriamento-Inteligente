//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
//#include <CurieTimerOne.h>

//Define os pinos para o trigger e echo
#define pino_trigger 3
#define pino_echo 2
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  //Le as informacoes do sensor
  float tempo = ultrasonic.timing();
  float distancia = ultrasonic.convert(tempo, Ultrasonic::CM);
  Serial.println(distancia);
  delay(1000);
}
