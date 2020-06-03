#include <math.h>
const int pinAdc = A0;
float valorsomdb;
float menor;
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
    valorsomdb = 20*log10(sum);

    menor=sum;
    if(sum<menor)
    {
      menor=sum;
    }

    
   Serial.println(menor);
    delay(100);
}
