#define pino 2 //Pino OUT

// LOW não tem movimento
// HIGH tem movimento
 
void setup()
{
  pinMode(pino, INPUT); //Define pino sensor como entrada
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pino), mov, CHANGE); //Interrupção "mudança" no pino, vai ativar a função mov.
}
 
void loop(){  
}

void mov(){
  int acionamento = digitalRead(pino); //Le o valor do sensor
  Serial.println(acionamento);
 
  if (acionamento == LOW) //Sem movimento
  {
    Serial.println("nada");
  }
  else //Caso seja detectado um movimento
  {
    Serial.println("HUMANOS!!!");
  }
}
