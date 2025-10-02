// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor4.setSpeed(255);
    motor3.setSpeed(255);
      motor2.setSpeed(255);
        motor1.setSpeed(255);

 
  motor4.run(RELEASE);
    motor3.run(RELEASE);
      motor2.run(RELEASE);
        motor1.run(RELEASE);

}

void loop() {
  uint8_t i;
  
  Serial.print("tick");
  
  motor1.run(FORWARD);
    motor2.run(FORWARD);
      motor3.run(FORWARD);
        motor4.run(FORWARD);

  for (i=0; i<255; i++) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
      motor3.run(BACKWARD);
        motor4.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i); 
    delay(10);
 }
  

  Serial.print("tech");
  motor4.run(RELEASE);
    motor3.run(RELEASE);
      motor2.run(RELEASE);
        motor1.run(RELEASE);
  delay(1000);
}
