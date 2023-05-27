// Declare pins
#define ENA 6
#define in1 7
#define in2 8
#define in3 9
#define in4 10
#define ENB 11

#define trig 2
#define echo 3

long duration;
float distance;
int limit = 5;

int pins[] = {6,7,8,9,10,11};

void setup(void)
{

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

 for (int i = 0; i <5; i++) 
 {
    pinMode(pins[i],OUTPUT);
 }

   Switch_OFF();
   delay(100);
   Switch_ON();

   Forward();

}

void loop(void)
{

  // digitalWrite(trig, LOW);
  // delayMicroseconds(2);

  // digitalWrite(trig, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trig, LOW);

  // duration = pulseIn(echo, HIGH);

  // distance = duration*0.034/2;

  // Serial.println(distance);

  // Forward();
  // delay(1000);

  // Brake();
  // delay(500);

  // Switch_ON();

  // Backward();
  // delay(1000);

  // Brake();
  // delay(500);
  
  // Switch_ON();

  // Left();
  // delay(1000);

  // Right();
  // delay(1000);

  // Brake();
  // delay(500);
  Serial.println(read_distance());
  distance = read_distance();
  if (distance > limit)
  {
    do{
      Forward();
    }
    while(distance > limit);
  }
  else
  {
    Brake();
    delay(100);

    Left();

    delay(500);

  }
  
}

void RestartRobot(void)
{
  Switch_OFF();
  delay(500);
  Switch_ON();
  delay(350);
}

// TURN ON MOTORS
void Switch_ON(void)
{
  analogWrite(ENA,220);
  analogWrite(ENB,220);
}

// TURN OFF MOTORS
void Switch_OFF(void)
{
  digitalWrite(ENA, LOW );
  digitalWrite(ENB, LOW );
}

// Forward
void Forward(void)
{
  digitalWrite(in1, HIGH); // TURNING MOTOR 1 FORWARD
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH); // TURNING MOTOR 2 FORWARD
  digitalWrite(in4, LOW);
}

// BACKWARD
void Backward(void)
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1  BACK
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW); // TURNING MOTOR 2  BACK
  digitalWrite(in4, HIGH);
}

// RIGHT
void Right(void)
{
  digitalWrite(in1, HIGH ); // TURNING MOTOR 1  FORWARD
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW); // TURNING MOTOR 2  BACKWARD
  digitalWrite(in4, HIGH);
}

// TURN ROBOT LEFT
void Left(void)
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1  BACKWARD
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH); // TURNING MOTOR 2  FORWARD
  digitalWrite(in4, LOW);
}

// BRAKE
void Brake(void)
{
  digitalWrite(in1, LOW); // TURNING MOTOR 1 off
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW); // TURNING MOTOR 2 off
  digitalWrite(in4, LOW);
}

int read_distance(void)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration*0.034/2;

  return distance;

}
