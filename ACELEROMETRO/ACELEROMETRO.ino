#include <AcceleroMMA7361.h>

AcceleroMMA7361 accelero;
int x, y, z, ledFrente = 7, ledEsquerda = 6, ledDireita = 5, ledTras = 4;
void setup()
{
  pinMode(ledFrente, OUTPUT);  
  pinMode(ledEsquerda, OUTPUT);  
  pinMode(ledDireita, OUTPUT);  
  pinMode(ledTras, OUTPUT);  
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);  //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);  //sets the sensitivity to +/-6G
  accelero.calibrate();
}

void loop()
{
  x = accelero.getXRaw();
  y = accelero.getYRaw();
  z = accelero.getZRaw();
  Serial.print("nx: ");
  Serial.println(x);
  Serial.println("====================");
  Serial.print("ty: ");
  Serial.println(y);
  Serial.println("====================");
  Serial.print("tz: ");
  Serial.println(z);
  Serial.println("====================");
  Serial.println("");
  Serial.println("");Serial.println("");Serial.println("");Serial.println("");Serial.println("");

  if(z >= 600)
    digitalWrite(ledFrente, HIGH);  
  else                      
    digitalWrite(ledFrente, LOW); 

  if(y <= 485)
    digitalWrite(ledDireita, HIGH);  
  else                      
    digitalWrite(ledDireita, LOW); 

  if(z <= 530)
    digitalWrite(ledTras, HIGH);  
  else                      
    digitalWrite(ledTras, LOW); 

  if(y >= 540)
    digitalWrite(ledEsquerda, HIGH);  
  else                      
    digitalWrite(ledEsquerda, LOW); 
   
  delay(500);                                   
}
