// Servo - Version: Latest 
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

/*

*/

void setup() {
  tone(4, 3000, 1000);
  delay(1000);
  pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
  
  servoLeft.attach(13);
  servoRight.attach(12);
  
  //Serial.begin(9600);
    
}

void loop() {
  byte wLeft = digitalRead(5);
  byte wRight = digitalRead(7);

  
  if (wLeft == 0) {
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
  
  if (wRight == 0) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  
  if ((wLeft == 0) && (wRight == 0)) {
    backward(1000);
    turnLeft(800);
  }
  else if (wLeft == 0) {
    backward(1000);
    turnRight(400);
  }
  else if (wRight == 0) {
    backward(1000);
    turnLeft(400);
  }
  else {
    forward(20);
  }
  
    
  Serial.print(wLeft);
  Serial.println(wRight);
  
  delay(50);
}



void forward(int time) {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void turnLeft(int time) {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void turnRight(int time) {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(time);
}

void backward(int time) {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(time);
}

void disableServos(){
  servoLeft.detach();
  servoRight.detach();
}
