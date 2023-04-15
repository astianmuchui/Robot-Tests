#define ENA 6
#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define ENB 11

int pins[] = {6,7,8,9,10,11};

void setup() {
 for (int i = 0; i <5; i++) 
 {
    pinMode(pins[i],OUTPUT);
 }
   Switch_ON();
}

void loop() {
  Forward();
  delay(1000);
  Brake();
  delay(500);
  Switch_ON();
  Backward();
  delay(1000);
  Brake();
  delay(500);
  Switch_ON();
  Left();
  delay(1000);
  Right();
  delay(1000);
  Brake();
  delay(500);
  Switch_ON();
  
}


// TURN ON MOTORS
void Switch_ON()
{
  analogWrite(ENA,190);
  analogWrite(ENB,190);
}

// TURN OFF MOTORS
void Switch_OFF()
{
  digitalWrite(ENA, LOW );
  digitalWrite(ENB, LOW );
}

// Forward
void Forward()
{
  digitalWrite(in1, HIGH); // TURNING MOTOR 1 FORWARD
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH); // TURNING MOTOR 2 FORWARD
  digitalWrite(in4, LOW);
}

// BACKWARD
void Backward()
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1  BACK
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW); // TURNING MOTOR 2  BACK
  digitalWrite(in4, HIGH);
}

// RIGHT
void Right()
{
  digitalWrite(in1, HIGH ); // TURNING MOTOR 1  FORWARD
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW); // TURNING MOTOR 2  BACKWARD
  digitalWrite(in4, HIGH);
}

// TURN ROBOT LEFT
void Left()
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1  BACKWARD
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH); // TURNING MOTOR 2  FORWARD
  digitalWrite(in4, LOW);
}

// BRAKE
void Brake()
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1 off
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW); // TURNING MOTOR 2 off
  digitalWrite(in4, LOW);
}
