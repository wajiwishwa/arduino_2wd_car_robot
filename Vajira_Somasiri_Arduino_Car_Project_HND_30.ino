/*    Vajira Somasiri
 *    HND30 - PIBT
 *    2 Wheel Arduino Arduino Car Robot
 */

#include <AFMotor.h>
#define trig 2
#define echo A0

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


char bt ;
int Speed = 100;


void setup()

{
  Serial.begin(9600);
 
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}


void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  long t = pulseIn(echo,HIGH);
  long cm = t / 29 / 2;

  
  if (Serial.available() > 0) {
    bt = Serial.read();
    
    Stop(); 

switch (bt){
  case 'F':
    if(cm<20){
      Stop();
    }
    else{ forward( );  }     ; break;
    
  case 'B': backward()      ; break;
  case 'L': left()          ; break;
  case 'R': right()         ; break;
  case 'S': Stop()          ; break;

  case '0': Speed = 100     ; break;
  case '1': Speed = 140     ; break;
  case '2': Speed = 153     ; break;
  case '3': Speed = 165     ; break;
  case '4': Speed = 178     ; break;
  case '5': Speed = 191     ; break;
  case '6': Speed = 204     ; break;
  case '7': Speed = 216     ; break;
  case '8': Speed = 229     ; break;
  case '9': Speed = 242     ; break;
  case 'q': Speed = 255     ; break;

}
}}

void forward()
{
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void Stop()
{
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
