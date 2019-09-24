//successfully driving one wheel so far

// Program: Control 2 DC motors using L298N H Bridge

// Definitions Arduino pins connected to input H Bridge
int IN1 = 8;
int IN2 = 7;

int IN3 = 9;
int IN4 = 10;

int time = 1000;
int speed = 255;
int direction = 0;

void setup()
{
 // Set the output pins
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}
  
void loop()
{
  go(direction);
  delay(time);
  direction = random(-1,2);
}

void leftForward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void rightForward()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftBackward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void rightBackward()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void go(int direction)
{
switch(direction)
{
  case -1:
  //backwards
  leftBackward();
  rightBackward();
  break;
  case 0:
  //forwards
  leftForward();
  rightForward();
  break;
  case 1:
  //left
  leftBackward();
  rightForward();
  break;
  case 2:
  leftForward();
  rightBackward();
  break;
  }
}
