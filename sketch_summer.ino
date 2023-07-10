#define led1 8
#define led2 12
#define led3 13

#define button1 2
#define button2 3
#define button3 4

int potentiometer=0;

int ledState1 = LOW;
long previousMillis1 = 0;
volatile long interval1 = 500;

int ledState2 = LOW;
long previousMillis2 = 0;
volatile long interval2 = 500;

int ledState3 = LOW;
long previousMillis3 = 0;
volatile long interval3 = 500;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  attachInterrupt(button1, blink1, RISING);
  attachInterrupt(button2, blink2, RISING);
  attachInterrupt(button3, blink3, RISING);
}

void loop() {
  potentiometer = analogRead(0);
  potentiometer = map(potentiometer,0,1023,0,255);
  
  unsigned long currentMillis1 = millis();
  if(currentMillis1 - previousMillis1 > interval1) {
    previousMillis1 = currentMillis1; 
 
    if (ledState1 == LOW){
      ledState1 = HIGH;
      digitalWrite(led1, potentiometer);
    }
    else{
      ledState1 = LOW;
      digitalWrite(led1, LOW);
    }
  }

  unsigned long currentMillis2 = millis();
  if(currentMillis2 - previousMillis2 > interval2) {
    previousMillis2 = currentMillis2; 
 
    if (ledState2 == LOW){
      ledState2 = HIGH;
      digitalWrite(led2, potentiometer);
    }
    else{
      ledState2 = LOW;
      digitalWrite(led2, LOW);
    }
  }

  unsigned long currentMillis3 = millis();
  if(currentMillis3 - previousMillis3 > interval3) {
    previousMillis3 = currentMillis3; 
 
    if (ledState3 == LOW){
      ledState3 = HIGH;
      digitalWrite(led3, potentiometer);
    }
    else{
      ledState3 = LOW;
      digitalWrite(led3, LOW);
    }
  }
}

void blink1()
{
  if(interval1==2000){
    interval1=500;
    return;
  }
  interval1*=2;
  return;
}

void blink2()
{
  if(interval2==2000){
    interval2=500;
    return;
  }
  interval2*=2;
  return;
}

void blink3()
{
  if(interval3==2000){
    interval3=500;
    return;
  }
  interval3*=2;
  return;
}
