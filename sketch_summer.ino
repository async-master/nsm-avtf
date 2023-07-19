#define led1 9
#define led2 10
#define led3 11

#define button1 2
#define button2 3
#define button3 4

int potentiometer=0;

int ledState1 = LOW;
long previousMillis1 = 0;
int interval1 = 2000;

int ledState2 = LOW;
long previousMillis2 = 0;
int interval2 = 2000;

int ledState3 = LOW;
long previousMillis3 = 0;
int interval3 = 2000;

long previousMillis4 = 0;
long previousMillis5 = 0;
long previousMillis6 = 0;
long interval = 50;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  unsigned long currentMillis4 = millis();
  if(digitalRead(button1) == 1 && (currentMillis4 - previousMillis4 > interval)){
    previousMillis4 = currentMillis4;
    if(interval3>=500){
      interval3/=2;
    }
    if(interval3==250){
      interval3=2000;
    }
  }

  unsigned long currentMillis5 = millis();
  if(digitalRead(button2) == 1 && (currentMillis5 - previousMillis5 > interval)){
    previousMillis5 = currentMillis5;
    if(interval2>=500){
      interval2/=2;
    }
    if(interval2==250){
      interval2=2000;
    }
  }

  unsigned long currentMillis6 = millis();
  if(digitalRead(button3) == 1 && (currentMillis6 - previousMillis6 > interval)){
    previousMillis6 = currentMillis6;
    if(interval1>=500){
      interval1/=2;
    }
    if(interval1==250){
      interval1=2000;
    }
  }
  potentiometer = analogRead(0);
  potentiometer = map(potentiometer,0,1023,0,255);
  
  unsigned long currentMillis1 = millis();
  if(currentMillis1 - previousMillis1 > interval1) {
    previousMillis1 = currentMillis1; 
 
    if (ledState1 == LOW){
      ledState1 = HIGH;
      analogWrite(led1, potentiometer);
    }
    else{
      ledState1 = LOW;
      analogWrite(led1, LOW);
    }
  }

  unsigned long currentMillis2 = millis();
  if(currentMillis2 - previousMillis2 > interval2) {
    previousMillis2 = currentMillis2; 
 
    if (ledState2 == LOW){
      ledState2 = HIGH;
      analogWrite(led2, potentiometer);
    }
    else{
      ledState2 = LOW;
      analogWrite(led2, LOW);
    }
  }

  unsigned long currentMillis3 = millis();
  if(currentMillis3 - previousMillis3 > interval3) {
    previousMillis3 = currentMillis3; 
 
    if (ledState3 == LOW){
      ledState3 = HIGH;
      analogWrite(led3, potentiometer);
    }
    else{
      ledState3 = LOW;
      analogWrite(led3, LOW);
    }
  }
}
