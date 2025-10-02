#include <SoftwareSerial.h>

//0023:09:013257

// Declare SoftwareSerial object
SoftwareSerial mySerial(8, 9);

void setup() {
  // Start serial communication with the computer
  Serial.begin(38400);

  // Start serial communication with the SoftwareSerial device
  mySerial.begin(38400);
  Serial.write("Hello");
}

void loop() {
  // Read from Serial and write to mySerial
  if (Serial.available()) {
    char c=Serial.read();
    mySerial.write(c);
  }

  // Read from mySerial and write to Serial
  if (mySerial.available()) {
    char c=mySerial.read();
    Serial.write(c);
  }
  delay(10);
}
