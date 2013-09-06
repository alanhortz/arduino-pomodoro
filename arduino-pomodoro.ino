// Alan Hortz - 2013

const int switchPin = 2;     
const int ledPin =  13;      


int switchState = 0;         
int currentState = 0;

unsigned long lastMillis = 0;
unsigned long counter = 0;
unsigned long currentDuration = 0;

const long STATE_POMODORO_ACTIVE = 1;
const long STATE_SMALL_BREAK_ACTIVE = 0;

const unsigned long DURATION_IN_ACTIVE = (6 * 1 * 1000);
const unsigned long DURATION_IN_BREAK = (3 * 1 * 1000);


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(switchPin, INPUT); 
  counter = currentDuration = DURATION_IN_BREAK;
  currentState = 0;
}

void loop(){
  
  switchState = digitalRead(switchPin);

  if((counter >= currentDuration) or (switchState  == HIGH))
  {
    if(currentState == STATE_POMODORO_ACTIVE)
    {
      setInactive();
    }
    else
    {
      setActive();    
    }  
  }
  
  counter = (millis() - lastMillis);    
  delay(300);
}

void setActive()
{
  counter = 0;              
  lastMillis = millis();
  currentDuration = DURATION_IN_ACTIVE;
  currentState = STATE_POMODORO_ACTIVE;
  digitalWrite(ledPin,HIGH);
}
void setInactive()
{
  counter = 0;              
  lastMillis = millis();
  currentDuration = DURATION_IN_BREAK;  
  currentState = STATE_SMALL_BREAK_ACTIVE;
  digitalWrite(ledPin,LOW);
}

