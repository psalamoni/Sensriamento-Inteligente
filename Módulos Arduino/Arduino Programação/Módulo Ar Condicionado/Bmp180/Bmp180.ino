#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp180;


void setup() {
  Serial.begin(9600);
  bmp180.begin();
}

void loop() {
  float temperatura = bmp180.readTemperature();
  float altitude = bmp180.readAltitude();
  float pressao = bmp180.readPressure();

  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  
  Serial.print("Altitude: ");
  Serial.println(altitude);

  Serial.print("Pressão: ");
  Serial.println(pressao);
  
  delay(2000);
}
