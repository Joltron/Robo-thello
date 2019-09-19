#include <AFMotor.h>

AF_DCMotor port(2); // create motor #2
AF_DCMotor starboard(1); // create motor #1
AF_DCMotor weapon(3); //create spinning weapon motor
int time = 100;
int speed = 255;
int direction = 0;

void setup()
{
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");

  port.setSpeed(speed);     // set the speed to 200/255
  starboard.setSpeed(speed);     // set the speed to 200/255
  weapon.setSpeed(255);
}

void loop() {
weapon.run(FORWARD);
go(direction);
direction = random(-1,2);
}

void go(int) {
switch (direction) {
  case -1:
  //backwards
  port.run(RELEASE);
  starboard.run(RELEASE);
  port.run(BACKWARD);
  starboard.run(BACKWARD);
  delay(time);
  break;
  case 0:
  //forwards
  port.run(RELEASE);
  starboard.run(RELEASE);
  port.run(FORWARD);
  starboard.run(FORWARD);
  delay(time);
  break;
  case 1:
  //rotate left
  port.run(RELEASE);
  starboard.run(RELEASE);
  port.run(FORWARD);
  starboard.run(BACKWARD);
  delay(time);
  break;
  case 2:
  //rotate right
  port.run(RELEASE);
  starboard.run(RELEASE);
  port.run(BACKWARD);
  starboard.run(FORWARD);
  delay(time);
  break;
}
}
