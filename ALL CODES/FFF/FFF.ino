#include <SoftwareSerial.h>
#include <AFMotor.h>

// Define RX and TX pins for SoftwareSerial
SoftwareSerial BT(10, 11); // RX (10), TX (11)

// Initialize the motors on the Adafruit Motor Shield
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(115200);

  // Initialize Bluetooth communication
  BT.begin(9600);

  // Initialize motors
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  // Set motors to RELEASE (stopped)
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  // Indicate that setup is complete
  Serial.println("Setup complete, waiting for data...");
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  if (BT.available()) {
    // Read the incoming byte
    int command = BT.read();

    // Take action based on the received command
    switch (command) {
      case 'A':
        Serial.println("Move Forward");
        moveForward();
        break;
      case 'B':
        Serial.println("Move Backward");
        moveBackward();
        break;
      case 'C':
        Serial.println("Turn Left");
        turnLeft();
        break;
      case 'D':
        Serial.println("Turn Right");
        turnRight();
        break;
      default:
        Serial.println("Unknown command");
        stopMotors();
        break;
    }
  }
  delay(10);
}

void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
