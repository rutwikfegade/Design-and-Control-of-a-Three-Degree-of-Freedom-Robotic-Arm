#include <Servo.h>
Servo servo[4];
const int push=7;
const int push1=6;
const int push2=5;
const int push3=4;
const int push4=3;
unsigned int n=90,k=90,y=90;
unsigned int x=90,a;

int flag=-1;
bool buttonstate=LOW;
void setup() {
  Serial.begin(9600);
  pinMode(push,INPUT);
  pinMode(push1,INPUT);
  pinMode(push2,INPUT);
  pinMode(push3,INPUT);
  pinMode(push4,INPUT);
  servo[0].attach(9,600,2400);
  servo[1].attach(11);
  servo[2].attach(12,600,2400);
  servo[3].attach(13,600,2400);
  
}

void loop() {
 
if((debounce(buttonstate,push)==HIGH))
{
  
  
  rotate(flag,push,n,0);
  if(flag<0){
  n=min(n,179);
  n++;}
  if(flag>0){
    n=max(1,n);
    n--;
  }
  Serial.print(servo[0].read());
}

 if((debounce(buttonstate,push1)==HIGH))
{
  
  rotate(flag,push1,k,1);
  if(flag<0){
  k=min(k,179);
  k++;}
  if(flag>0){
    k=max(1,k);
    k--;
  }
  Serial.print(servo[1].read());
}
if((debounce(buttonstate,push2)==HIGH))
{
  
 
  rotate(flag,push2,y,2);
  if(flag<0){
    y=min(y,179);                     
  y++;}
  if(flag>0){
    y=max(1,y);
    y--;
  }
  Serial.print(servo[2].read());
}
if((debounce(buttonstate,push3)==HIGH))
{
  
  
  rotate(flag,push3,x,3);
  if(flag<0){
    x=min(x,179);
  x++;}
  if(flag>0){
    x=max(91,x);
    x--;
  }
  Serial.print(servo[3].read());
}
if((debounce(buttonstate,push4)==HIGH))
{
  delay(20);
  flag=-flag;
  Serial.print("reverse");
}

}

void rotate(int flag,int button,int a,int motor)
{
 
    servo[motor].write(a);

 
}

boolean debounce(boolean state,int buttonpin)
{
  boolean stateNow = digitalRead(buttonpin);
  if(state!=stateNow)
  {
    delay(50);
    stateNow = digitalRead(buttonpin);
  }
  return stateNow;
  
}



void waittime(int interval)
{
  unsigned long currentmillis=millis();
  unsigned long previousmillis=0; 
  if ((currentmillis-previousmillis)>=interval)
  {
    previousmillis=currentmillis;
  }
}
