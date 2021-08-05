// C++ code

// set variables and constants
const int led1_pin = 10;
const int led2_pin = 11;
const int led3_pin = 12;
const int led_timer_pin = 13;
const int motion_pin = 2;
const int button1_pin = 3;
const int button2_pin = 6;

// timer interrupt 
const uint16_t timer_load = 0;
const uint16_t timer_comp = 31250;


// setup function 
void setup()
{
  Serial.begin(9600);
  // initalise button pin and motion sensor pin as input
  pinMode(motion_pin, INPUT);
  pinMode(button1_pin, INPUT);
  pinMode(button2_pin, INPUT);
  // initalise led pins as output
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led_timer_pin, OUTPUT);
  
  

  // PCICR -> enabling all ports
  PCICR |=  B00000100;

  // PCMSK2 -> enabling pins in port D2,D3,D5
  PCMSK2 |= B01001100;

  // Setting led timer
  DDRB |= (1 << led_timer_pin);

  
  noInterrupts();
  // Reset timer
  TCCR1A = 0;
  TCCR1B = 0;		
	

  TCNT1 = timer_load;
  OCR1A = timer_comp;
  
  // Set to prescaler 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);

  TIMSK1 = (1 << OCIE1A);		
  TCCR1B |=(1<< WGM12);

  interrupts();
}

// ISR for the timer interrupt
ISR(TIMER1_COMPA_vect){
   digitalWrite(led_timer_pin, digitalRead(led_timer_pin) ^ 1);
}

void loop()
{
  Serial.println("No interrupt");
  delay(500);
}

//Interrupt for button and pir

ISR (PCINT2_vect) 
{
  if (digitalRead(button2_pin) == HIGH)
  {
    digitalWrite(led3_pin, HIGH);
    Serial.println("Button1 pressed");
  }
  else 
  {
    digitalWrite(led3_pin, LOW);
  }
  
  
  if (digitalRead(button1_pin) == HIGH)
  { 
    Serial.println("Button2  pressed");
    digitalWrite(led2_pin, HIGH);
  }
  else
  {
    digitalWrite(led2_pin, LOW);
  }
  
  
   if (digitalRead(motion_pin) == HIGH)
  {
    Serial.println("Motion Detected");
    digitalWrite(led1_pin, HIGH);
  }
  else
  {
    digitalWrite(led1_pin, LOW);
  }

  
}
