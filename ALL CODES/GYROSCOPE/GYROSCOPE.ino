#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial BT(10, 11); // Define RX (10) and TX (11) pins for Bluetooth
const float GYRO_SENSITIVITY = 1;

void setup() {
  Serial.begin(115200); // For Serial Monitor debugging
  BT.begin(9600);  // For HC-05 Bluetooth communication
  Wire.begin();

  // Small delay to ensure MPU6050 initializes correctly
  delay(100);

  // Initialize the MPU6050
  mpu.initialize();

  // Check if the MPU6050 is connected
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
  }

  // Indicate that setup is complete
  Serial.println("Setup complete");
}

void loop() {
  // Create variables to hold the data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read the data from the MPU6050
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calculate the gyroscope data in degrees per second (DPS)
  float xDPS = ax / GYRO_SENSITIVITY;
  float yDPS = ay / GYRO_SENSITIVITY;
  float zDPS = az / GYRO_SENSITIVITY;

  // Print the gyroscope data to the Serial Monitor

float finalAx=movingAverageX(xDPS,10);
float finalAy=movingAverageY(yDPS,10);
float finalAz=movingAverageZ(zDPS,10);

  Serial.print("aX:"); Serial.print(finalAx);
  Serial.print(", aY:"); Serial.print(finalAy);
  Serial.print(", aZ:"); Serial.println(finalAz);

if(finalAx>4000)
{
  BT.print('A');//Front
}
else if (finalAx<-4000) {
BT.print('B');//Back
}
else if(finalAy>4000)
{
  BT.print('C');//Left
}
 else if (finalAy<-4000) {
BT.print('D');//Right
}
else{
  BT.print('X');
  
}

  // Send the gyroscope data over Bluetooth
  //BT.print("gX:"); BT.print(xDPS);
  //BT.print(", gY:"); BT.print(yDPS);
  //BT.print(", gZ:"); BT.println(zDPS);

  
  

  // Add a small delay to avoid spamming data
  delay(100);
}
float movingAverageX(float accInstantenious, int window) {
  static float *values = nullptr;  // Dynamic array to hold recent values
  static float sum = 0.0;          // Sum of the values in the window
  static int index = 0;            // Current index in the circular buffer
  static bool filled = false;      // Flag to check if the buffer is filled

  if (values == nullptr) {
    // Allocate memory for the array on the first call
    values = new float[window];
    
    // Initialize the array with zeros
    for (int i = 0; i < window; i++) {
      values[i] = 0.0;
    }
  }

  // Subtract the oldest value from the sum
  sum -= values[index];

  // Add the new value to the array and the sum
  values[index] = accInstantenious;
  sum += accInstantenious;

  // Update the index and wrap around if necessary
  index = (index + 1) % window;

  // Check if the buffer has been filled
  if (!filled && index == 0) {
    filled = true;
  }

  // Return the moving average
  if (filled) {
    return sum / window;
  } else {
    return sum / (index + 1);  // Avoid division by zero for initial values
  }
}

float movingAverageY(float accInstantenious, int window) {
  static float *values = nullptr;  // Dynamic array to hold recent values
  static float sum = 0.0;          // Sum of the values in the window
  static int index = 0;            // Current index in the circular buffer
  static bool filled = false;      // Flag to check if the buffer is filled

  if (values == nullptr) {
    // Allocate memory for the array on the first call
    values = new float[window];
    
    // Initialize the array with zeros
    for (int i = 0; i < window; i++) {
      values[i] = 0.0;
    }
  }

  // Subtract the oldest value from the sum
  sum -= values[index];

  // Add the new value to the array and the sum
  values[index] = accInstantenious;
  sum += accInstantenious;

  // Update the index and wrap around if necessary
  index = (index + 1) % window;

  // Check if the buffer has been filled
  if (!filled && index == 0) {
    filled = true;
  }

  // Return the moving average
  if (filled) {
    return sum / window;
  } else {
    return sum / (index + 1);  // Avoid division by zero for initial values
  }
}

float movingAverageZ(float accInstantenious, int window) {
  static float *values = nullptr;  // Dynamic array to hold recent values
  static float sum = 0.0;          // Sum of the values in the window
  static int index = 0;            // Current index in the circular buffer
  static bool filled = false;      // Flag to check if the buffer is filled

  if (values == nullptr) {
    // Allocate memory for the array on the first call
    values = new float[window];
    
    // Initialize the array with zeros
    for (int i = 0; i < window; i++) {
      values[i] = 0.0;
    }
  }

  // Subtract the oldest value from the sum
  sum -= values[index];

  // Add the new value to the array and the sum
  values[index] = accInstantenious;
  sum += accInstantenious;

  // Update the index and wrap around if necessary
  index = (index + 1) % window;

  // Check if the buffer has been filled
  if (!filled && index == 0) {
    filled = true;
  }

  // Return the moving average
  if (filled) {
    return sum / window;
  } else {
    return sum / (index + 1);  // Avoid division by zero for initial values
  }
}


