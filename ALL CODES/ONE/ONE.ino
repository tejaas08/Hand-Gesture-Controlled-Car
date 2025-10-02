#include <SoftwareSerial.h>

// Define RX and TX pins for SoftwareSerial
SoftwareSerial BT(10, 11); // RX (10), TX (11)

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(115200);

  // Initialize Bluetooth communication
  BT.begin(9600);

  // Indicate that setup is complete
  Serial.println("Setup complete, waiting for data...");
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  //Serial.println("HEllo");
  if (BT.available()) {
    //Serial.println("HEllo");
    // Read the incoming byte
    int command = BT.read();

    // Display the received command in the Serial Monitor

    //Serial.println(command);

    // Take action based on the received command
    switch (command) {
      case 'A':
        Serial.println("Move Forward");
        // Add code to move the car forward
        break;
      case 'B':
        Serial.println("Move Backward");
        // Add code to move the car backward
        break;
      case 'C':
        Serial.println("Turn Left");
        // Add code to turn the car left
        break;
      case 'D':
        Serial.println("Turn Right");
        // Add code to turn the car right
        break;
      default:
        Serial.println("Unknown command");
        // Handle unknown commands if necessary
        break;
    }
  }
  delay(10);
}
