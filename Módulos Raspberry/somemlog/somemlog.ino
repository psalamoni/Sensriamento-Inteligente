#include <math.h>
const int pinAdc = A0;
float valorsomdb;
void setup()
{
    Serial.begin(9600);
    //Serial.println("Grove - Sound Sensor Test...");
}

void loop()
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }

    sum >>= 5;
    valorsomdb = (20*log10(sum/35)) + 53;

    Serial.println(valorsomdb);
    delay(10);
}
