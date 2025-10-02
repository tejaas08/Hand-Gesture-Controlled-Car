#include <Adafruit_MotorShield.h>

// Define motor pins
#define ENA 9  // Enable pin for Motor A
#define ENB 10 // Enable pin for Motor B
#define ENC 11 // Enable pin for Motor C
#define END 12 // Enable pin for Motor D
#define IN1 2  // Control pin 1 for Motor A
#define IN2 3  // Control pin 2 for Motor A
#define IN3 4  // Control pin 3 for Motor B
#define IN4 5  // Control pin 4 for Motor B
#define IN5 6  // Control pin 1 for Motor C
#define IN6 7  // Control pin 2 for Motor C
#define IN7 8  // Control pin 3 for Motor D
#define IN8 13 // Control pin 4 for Motor D

void setup() {
  // Set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(END, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Move forward
  Serial.write("Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENA, 255); // Set speed for Motor A (0-255)
  analogWrite(ENB, 255); // Set speed for Motor B (0-255)
  analogWrite(ENC, 255); // Set speed for Motor C (0-255)
  analogWrite(END, 255); // Set speed for Motor D (0-255)
  delay(2000);

Serial.write("Back");
  // Move backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENA, 255); // Set speed for Motor A (0-255)
  analogWrite(ENB, 255); // Set speed for Motor B (0-255)
  analogWrite(ENC, 255); // Set speed for Motor C (0-255)
  analogWrite(END, 255); // Set speed for Motor D (0-255)
  delay(2000);
Serial.write("Stop");
  // Stop motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  delay(2000);
}
