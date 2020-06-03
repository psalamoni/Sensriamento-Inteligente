// início temp. e umidade -------------------------------------------------------------------------------------
#include <Wire.h>
#include "ClosedCube_HDC1080.h"
ClosedCube_HDC1080 hdc1080;
// fim temp. e umidade -----------------------------------------------------------------------------------------


// início luz -------------------------------------------------------------------------------------------------------------
#include <BH1750.h>
BH1750 lightMeter(0x23);
// fim luz -------------------------------------------------------------------------------------------------------------


// início poeira e fumaça -------------------------------------------------------------------------------------------------------------
int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;//sampe 30s ;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;
// fim poeira e fumaça -------------------------------------------------------------------------------------------------------------


void setup()
// início temp. e umidade -------------------------------------------------------------------------------------------------
{
  Serial.begin(9600);
  Serial.println("ClosedCube HDC1080 Arduino Test");

  
  hdc1080.begin(0x40);

  Serial.print("Manufacturer ID=0x");
  Serial.println(hdc1080.readManufacturerId(), HEX); // 0x5449 ID of Texas Instruments
  Serial.print("Device ID=0x");
  Serial.println(hdc1080.readDeviceId(), HEX); // 0x1050 ID of the device
  
  


// fim temp. e umidade -------------------------------------------------------------------------------------------------
// início luz -------------------------------------------------------------------------------------------------------------

  
  Wire.begin();
  
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }



// fim luz -------------------------------------------------------------------------------------------------------------

// início poeira e fumaça -------------------------------------------------------------------------------------------------------------

pinMode(8,INPUT);
 starttime = millis();//get the current time;

}
// fim poeira e fumaça -------------------------------------------------------------------------------------------------------------
void loop()

// início temp. e umidade -----------------------------------------------------------------------------------------------
{
  Serial.print("T=");
  Serial.print(hdc1080.readTemperature());
  Serial.print("C, RH=");
  Serial.print(hdc1080.readHumidity());
  Serial.println("%");
  delay(3000);

// início luz -------------------------------------------------------------------------------------------------------------
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
  // fim luz -------------------------------------------------------------------------------------------------------------

duration = pulseIn(pin, LOW);
 lowpulseoccupancy = lowpulseoccupancy+duration;
 if ((millis()-starttime) > sampletime_ms)//if the sampel time == 30s
 {
 ratio = lowpulseoccupancy/(sampletime_ms*10.0); // Integer percentage 0=>100
 concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve
 Serial.print("concentration = ");
 Serial.print(concentration);
 Serial.println(" pcs/0.01cf");
 Serial.println("\n");
 lowpulseoccupancy = 0;
 starttime = millis();
 }


}

void printSerialNumber() {
  Serial.print("Device Serial Number=");
  HDC1080_SerialNumber sernum = hdc1080.readSerialNumber();
  char format[12];
  sprintf(format, "%02X-%04X-%04X", sernum.serialFirst, sernum.serialMid, sernum.serialLast);
  Serial.println(format);
}
// fim temp. e umidade----------------------------------------------------------------------------------------------



