#include <Servo.h>

// Cues test

Servo indexServo;
Servo thumbServo;

int posIndex = 90;  // Reference position for the mouvements
int posThumb = 90;
int integerValue;
int angle = 8;
byte byteRead;
int state;

void setup() {
  indexServo.attach(9);
  thumbServo.attach(6);
  indexServo.write(posIndex); //90 initial motors position
  thumbServo.write(posThumb);  //90
  Serial.begin(9600);
  integerValue = 0;
  state = 0;
  Serial.println("Press M to start Motor Control.");
  Serial.print("Angle: ");
  Serial.println(angle);
  Serial.println("Press E/D to Increase/Decrease angle.");

}

void loop() {
  if (Serial.available() > 0) {
    byteRead = Serial.read();

    // angle adjustment state
    if (state == 0) {
      if (byteRead == 'e') {
        angle += 1;
        Serial.print("Angle: ");
        Serial.println(angle);
      }
      else if (byteRead == 'd') {
        angle -= 1;
        Serial.print("Angle: ");
        Serial.println(angle);
      }
      else if (byteRead == 'm') {
        state = 1;
        Serial.println("Motor Control State, Press A to switch to Angle Adjustment State");
              Serial.println("I: Forward/Up");
              Serial.println("K: Backward/Down");
              Serial.println("J: Twist Left");
              Serial.println("L: Twist Right");
              Serial.println("Z: Left");
              Serial.println("X: Right");
              
      }
    }


    // motor control state
    if (state == 1) {

      if (byteRead == 'i') {
        posIndex = posIndex + angle;
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex - angle;
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);
      }
      else if (byteRead == 'k') {

        posIndex = posIndex - angle;
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex + angle;
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);

      }

      else if (byteRead == 'l') {

        posIndex = posIndex + angle;
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex - angle;
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);
      }

      else if (byteRead == 'j') {
        posIndex = posIndex - angle;
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex + angle;
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);

      }

      // left
      else if (byteRead == 'z') {
        posIndex = posIndex - angle;
        posThumb = posThumb - (angle/2);
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex + angle;
        posThumb = posThumb + (angle/2);
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);

      }

      // right
      else if (byteRead == 'x') {
        posIndex = posIndex + (angle/2);
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex - (angle/2);
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);
      }

/*
      // left2
      else if (byteRead == 'z') {
        posIndex = posIndex - angle;
        posThumb = posThumb - (angle/2);
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex + angle;
        posThumb = posThumb + (angle/2);
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);

      }

      // right2
      else if (byteRead == 'x') {
        posIndex = posIndex - (angle/2);
        posThumb = posThumb - angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(2000);
        posIndex = posIndex + (angle/2);
        posThumb = posThumb + angle;
        indexServo.write(posIndex);
        thumbServo.write(posThumb);
        delay(1000);
      }
      */
      else if (byteRead == 'a') {
        state = 0;
        Serial.println("Angle Adjustment State. Press M to switch to Motor Control State");
        Serial.println("E: increase angle");
        Serial.println("D: decrease angle");
        

      }
    }


  }
}
