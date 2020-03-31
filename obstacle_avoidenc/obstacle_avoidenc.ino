#include <NewPing.h>
#include <Servo.h>

//ultrasonic sensor details
#define trig 2
#define echo 3
#define max_distance 200

//servo motor details
#define servo_pwm 5
#define rotate_time 300

//motor control detials
#define motorA1 4
#define motorA2 7
#define motorASpeed 6

#define motorB1 10
#define motorB2 12
#define motorBSpeed 11

#define defaultSpeed 200


//object creation
NewPing sonar(trig, echo, max_distance);
Servo sg90;


//all varioable declarations
int left = 0, right = 0, front = 0;

void setup() {

  sg90.attach(servo_pwm);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorASpeed, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBSpeed, OUTPUT);


  sg90.write(90);//first lookthe forward direction
  delay(500);
  front = readDistance();
  delay(50);
  front = readDistance();
  delay(50);
  front = readDistance();
  delay(50);

}

void loop() {

  right = 0;
  left = 0;

  if (front <= 20)
  {
    stopCar();
    delay(200);

    left = lookLeft();
    delay(100);
    right = lookRight();
    delay(100);

    if (right > left)
    {
      rightSide();
      delay(300);
      goto here;
    }
    else
    {
      leftSide();
      delay(300);
      goto here;
    }


  }
  else
  {
    forward();
  }
here:
  
  front = lookFront();

}


int readDistance()//this is the method for read the distance
{

  int cm = sonar.ping_cm();
  delay(70);
  cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = max_distance;
  }
  delay(70);
  return cm;
}

int  lookFront()
{
  sg90.write(90);
  delay(rotate_time);
  int frontValue = readDistance();
  return frontValue;

}

int lookRight()
{
  sg90.write(0);
  delay(rotate_time);
  int rightValue = readDistance();
  return rightValue;
}

int lookLeft()
{
  sg90.write(180);
  delay(rotate_time);
  int leftValue = readDistance();
  return leftValue;
}


void forward()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, defaultSpeed);

  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, defaultSpeed);


}

void backward()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorASpeed, defaultSpeed);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorBSpeed, defaultSpeed);
}

void leftSide()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, defaultSpeed);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorBSpeed, defaultSpeed);

}

void rightSide()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorASpeed, defaultSpeed);

  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, defaultSpeed);

}

void stopCar()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, 0);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, 0);

}
