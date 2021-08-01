// C++ code
//
const int led = 13;
const int pir = 2;

int motion = 0;

void setup()
{
  Serial.begin(9600); //Initialise serial monitor
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  motion = digitalRead(pir);
  if (motion == HIGH)
  {
    digitalWrite(led,HIGH); //LED ON
    Serial.println("motion detected...");
    delay(1000);}
  else //No motion
  {
    digitalWrite(led,HIGH); //LED OFF
    Serial.println("no motion...");
    delay(1000);} // Wait for 1000 milliseconds
}
