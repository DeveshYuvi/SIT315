// C++ code

// global variables
const int led1_pin = 13;
const int led2_pin = 12;
const int button_pin = 3;
const int motion_pin = 2;

uint8_t button = 0;
uint8_t motion = 0;


// setup function ran before anything else
void setup()
{
  Serial.begin(9600);
  // initalise button pin and motion sensor pin as input
  pinMode(button_pin, INPUT);
  pinMode(motion_pin, INPUT);
  // initalise led pins as output
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  // attach interrupts for button and motion sensor input
  attachInterrupt(digitalPinToInterrupt(button_pin), button_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motion_pin), motion_ISR, CHANGE);
}

void loop()
{
  delay(500);
}

//Interrupt for button
void button_ISR()
{ 
  button = digitalRead(button_pin);
  if(button == HIGH)//When button is pressed
  {
  	Serial.println("Button Pressed ");
  	digitalWrite(led1_pin, HIGH);

  }
  else
  {
    Serial.println("Button Released "); //When button is released
  	digitalWrite(led1_pin, LOW);
	
  }
}

//Interrupt for motion
void motion_ISR()
{ 
  motion = digitalRead(motion_pin);
  if(motion == HIGH)//When there is motion
  {
  	Serial.println("Motion detected ");
  	digitalWrite(led2_pin, HIGH);


  }
  else
  {
    Serial.println("No motion detected "); //When no motion detected
  	digitalWrite(led2_pin, LOW);

  }
}
