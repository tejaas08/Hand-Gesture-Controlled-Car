#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <SoftwareSerial.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect to the motors
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);//right front
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);//left front
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);//right back
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);//left back

SoftwareSerial BT(10, 11); // Define RX (10) and TX (11) pins for Bluetooth

void setup() {
  Serial.begin(115200); // For Serial Monitor debugging
  BT.begin(9600);       // For HC-05 Bluetooth communication

  // Start the motor shield
  AFMS.begin();
}

void loop() {
  if (BT.available()) {
    BT.readBytes()
    String data = BT.readStringUntil('\n');
    Serial.println("Received: " + data);

    // Parse the received data
    float gx, gy, gz;
    sscanf(data.c_str(), "xDPS:%f,yDPS:%f,zDPS:%f", &gx, &gy, &gz);

    // Control the car based on gyroscope readings
   // controlCar(gx, gy, gz);
  }
}


