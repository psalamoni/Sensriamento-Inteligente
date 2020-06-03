/* ========================================================================================================
 
   Curso de Arduino e AVR 155
   
   WR Kits Channel


   Medidor de Luz (luxímetro)

    
   Autor: Eng. Wagner Rambo  Data: Janeiro de 2018
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits

    
   
======================================================================================================== */


// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <Wire.h>
#include <BH1750.h>


// ========================================================================================================
// --- Mapeamento de Hardware ---
#define   led   13


// ========================================================================================================
// --- Definição de Objetos ---
BH1750 lightMeter;


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  Serial.begin(9600);

  Wire.begin();

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  lightMeter.begin();
  
} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{
 
  unsigned lux = lightMeter.readLightLevel();
  
 
  Serial.print("Luminosidade: ");
  Serial.print(lux);
  Serial.println(" lux");

  if(lux < 400) digitalWrite(led, HIGH);
  else          digitalWrite(led,  LOW);
  
  delay(741);
  

} //end loop
