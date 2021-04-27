#include <Servo.h>
int potpin = 0;
int Green = 1;
int Orange = 2;
int Red = 3;
int val;
Servo servo1;
int trigPin = 5;
int echoPin = 6;
long distance;
long duration;
 
void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Orange, OUTPUT);
  pinMode(Green, OUTPUT);
  servo1.attach(11); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop()
{
  ultra();
  servo1.write(0);
  val= analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);
  servo1.write(val);
  delay(15);
  if(distance >=10){
    digitalWrite(Red, HIGH);
    delay(2000);
    digitalWrite(Red, LOW);
    delay(1000); 
    servo1.write(60);
  }
  else{servo1.write(0);}
  if(distance >=10){
    digitalWrite(Orange,HIGH);
    delay(2000);
    digitalWrite(Orange, LOW);
    delay(1000); 
    servo1.write(120);
  }
  else{servo1.write(0);}
  if(distance >=10){
    digitalWrite(Green,HIGH);
    delay(2000);
    digitalWrite(Green, LOW);
    delay(1000); 
    servo1.write(180);
  }
  else{servo1.write(0);}
 
}
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.343/2;
 }