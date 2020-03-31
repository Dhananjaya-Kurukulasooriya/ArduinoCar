#define motorA1 3
#define motorA2 4
#define motorASpeed 5

#define motorB1 7
#define motorB2 8
#define motorBSpeed 9

int SerialRead;//to store the seria read value from the user


void forward();
void right();
void backward();
void left();

void setup() {
  Serial.begin(38400);//start the serial communication
  Serial.setTimeout(100);

  //define the pin modes
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorASpeed, OUTPUT);

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBSpeed, OUTPUT);


}

void loop() {


  if (Serial.available())
  {
    SerialRead = Serial.parseInt();
    Serial.println(SerialRead);

    switch (SerialRead)
    {
      case 1:
        forward();
        break;

      case 2:
        right();
        break;

      case 3:
        backward();
        break;

      case 4:
        left();
        break;

      default:
        stopCar();
        break;

    }
  }





}

void forward()
{
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, 200);

  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, 200);


}

void backward()
{
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorASpeed, 200);

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorBSpeed, 200);


}

void right()
{
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, 200);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorASpeed, 200);
}

void left()
{
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(motorBSpeed, 200);

  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, 200);
}

void stopCar()
{
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBSpeed, 0);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  analogWrite(motorASpeed, 0);
}
