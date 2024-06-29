#include <ESP32Servo.h>

// Ultrasonic Sensor Pins
const int trigPin = 5;  // Trigger pin for the ultrasonic sensor
const int echoPin = 18; // Echo pin for the ultrasonic sensor

// Buzzer Pin
const int buzzerPin = 19; // Pin for the buzzer

// Ultrasonic Sensor Variables
float duration, distance; // Variables to store duration and distance

// Servo Motor Setup
Servo myservo;
const int servoPin = 8;    // Pin for the servo motor
int angle = 0;             // Initial angle for the servo motor
const int maxAngle = 90;   // Maximum angle for the servo motor (can be 180)
const int minAngle = 0;    // Minimum angle for the servo motor
int angleStep = 2;         // Step size for changing the angle
unsigned long previousMillis = 0; // To store the last time the servo was updated
const long interval = 200; // Interval at which to move the servo (milliseconds)

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud

  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT); // Set the trig pin as an output
  pinMode(echoPin, INPUT);  // Set the echo pin as an input

  // Buzzer
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output

  // Servo Motor
  myservo.attach(servoPin); // Attach the servo motor to the specified pin

  // Initialize Servo Position
  myservo.write(angle); // Set the initial position of the servo motor

  // Check serial connection
  Serial.println("Setup completed");
}

void loop() {
  // Ultrasonic Sensor Code
  digitalWrite(trigPin, LOW); // Ensure the trig pin is low
  delayMicroseconds(2);       // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Set the trig pin high
  delayMicroseconds(10);       // Wait for 10 microseconds
  digitalWrite(trigPin, LOW);  // Set the trig pin low

  // Read the echo pin and measure the duration of the pulse
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration * 0.0343) / 2; // Calculate the distance based on the duration

  // Buzzer Activation based on Distance
  if (distance < 10) {
    // Turn on the buzzer if the distance is less than 10 cm
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Otherwise, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Servo Motor Code
  // Use millis() to avoid delay() function, which would halt the execution of other parts of the program.
  unsigned long currentMillis = millis();  
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update the last time the servo was updated

    myservo.write(angle); // Always write the current angle to the servo

    // Serial output formatted for Serial Plotter
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);

    angle += angleStep; // Increment or decrement the angle

    // Check and reverse the direction if needed
    if (angle > maxAngle || angle < minAngle) {
      angleStep = -angleStep; // Reverse the direction of the angle step
      
      // Adjust the angle immediately to prevent it from going out of the valid range
      angle += angleStep;
    }
  }
}
