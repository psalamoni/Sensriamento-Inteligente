#include "SoftwareSerial.h"

#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp180;

SoftwareSerial bluetooth(5, 6); //TX, RX (Bluetooth)

void setup() {
  Serial.begin(9600);
  bmp180.begin();

  bluetooth.begin(9600);
}

void loop() {
  float temperatura = bmp180.readTemperature();
  float altitude = bmp180.readAltitude();
  float pressao = bmp180.readPressure();

  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  bluetooth.print("Temperatura: ");
  bluetooth.println(temperatura);
  
  Serial.print("Altitude: ");
  Serial.println(altitude);
  bluetooth.print("Altitude: ");
  bluetooth.println(altitude);

  Serial.print("Pressão: ");
  Serial.println(pressao);
  bluetooth.print("Pressão: ");
  bluetooth.println(pressao);
  
  delay(2000);
}
