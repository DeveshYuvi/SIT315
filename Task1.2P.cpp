// C++ code
//
int led = 13;
int pir = 2;

int motion = 0;


void setup()
{
  Serial.begin(9600); //Initialise serial monitor
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), pin_ISR, CHANGE); //Attach an interrupt to the ISR vector
}

void loop()
{	
  delay(1000);
}

void pin_ISR(){
  motion = digitalRead(pir);
  if (motion == HIGH)
  {
    digitalWrite(led,HIGH); //LED ON
    Serial.println("motion detected...");
  }
  else //No motion
  {
    digitalWrite(led,HIGH); //LED OFF
    Serial.println("no motion...");
  }
}  
