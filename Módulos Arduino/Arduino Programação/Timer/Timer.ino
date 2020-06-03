#include <TimerOne.h>

void setup() {
  Serial.begin(9600);

}

void loop() {
  Timer1.initialize(60000000);
  int tempo = Timer1;
  Serial.println(tempo);

}
