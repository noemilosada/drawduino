
#include <Servo.h>
Servo frontServo;
Servo leftServo;
Servo rightServo;

// Define signal pulse for wheels
#define WHEELS_PULSE_MIN 1300
#define WHEELS_PULSE_MAX 1700

// Left servo
#define LEFT_WHEEL_BACKWARD 10
#define LEFT_WHEEL_FORWARD 20
#define WHEELS_STOP 15

// Right servo
#define RIGHT_WHEEL_BACKWARD 20
#define RIGHT_WHEEL_FORWARD 10

// Servo engines
#define FRONT_ENGINE_PIN 11
#define LEFT_ENGINE_PIN 13
#define RIGHT_ENGINE_PIN 12

// Servo configurations
#define FRONT_ENGINE_UP 0
#define FRONT_ENGINE_DOWN 31

// Define directions
#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4
#define UP 5
#define DOWN 6

void setup() {
  // Attach servos
  frontServo.attach(FRONT_ENGINE_PIN);
  rightServo.attach(RIGHT_ENGINE_PIN, WHEELS_PULSE_MIN, WHEELS_PULSE_MAX);
  leftServo.attach(LEFT_ENGINE_PIN, WHEELS_PULSE_MIN, WHEELS_PULSE_MAX);

  // Set start point for servos
  move(UP, 100);
  stopEngines();
  
  // Draw
  delay(1000);
  // sayHi();
  drawSquare();
  // drawTriangle();
}

void loop() {}

// SAY HI
void sayHi() {
  // H
  move(DOWN, 100);
  move(FORWARD, 1000);
  move(UP, 100);
  move(BACKWARD, 500);
  turnRight();
  move(DOWN, 100);
  move(FORWARD, 500);
  move(UP, 100);
  turnRight();
  move(FORWARD, 500);
  move(DOWN, 100);
  move(BACKWARD, 1000);
  move(UP, 100);
  
  // Space
  turnRight();
  move(FORWARD, 750);
  turnRight();

  // i
  move(DOWN, 100);
  move(BACKWARD, 1000);
  move(UP, 100);
}

// DRAW SQUARE
void drawSquare() {
  for(int x=0;x<4;x++) {
    move(DOWN, 100);
    move(FORWARD, 1000);
    move(UP, 100);
    turnRight();
  }
}

// DRAW TRIANGLE
void drawTriangle() {
  for(int x=0;x<3;x++) {
    move(DOWN, 100);
    move(FORWARD, 1000);
    move(UP, 100);
    turn60deg();
  }
}

// HELPER FUNCTIONS
void move(int dir, int time) {
  switch (dir) {
    case FORWARD:
      leftServo.write(LEFT_WHEEL_FORWARD);
      rightServo.write(RIGHT_WHEEL_FORWARD);
      break;
    case BACKWARD:
      leftServo.write(LEFT_WHEEL_BACKWARD);
      rightServo.write(RIGHT_WHEEL_BACKWARD);
      break;
    case RIGHT:
      leftServo.write(LEFT_WHEEL_BACKWARD);
      rightServo.write(WHEELS_STOP);
      break;
    case UP:
      frontServo.write(FRONT_ENGINE_UP);
      break;
    case DOWN:
      frontServo.write(FRONT_ENGINE_DOWN);
      break;
  }
  
  delay(time);
  stopEngines();
  delay(500);
}

void turnRight() {
    move(FORWARD, 1420);
    move(RIGHT, 1615);
    move(BACKWARD, 290);  
}

void turn60deg() {
    move(FORWARD, 1780);
    move(RIGHT, 2205);
    move(FORWARD, 230);  
}

void stopEngines() {
  leftServo.write(WHEELS_STOP);
  rightServo.write(WHEELS_STOP);
}
