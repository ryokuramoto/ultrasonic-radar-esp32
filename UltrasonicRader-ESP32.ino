#include <Servo.h>

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;

// Buzzer Pin
const int buzzerPin = 11;

// Ultrasonic Sensor Variables
float duration, distance;

// Servo Motor Setup
Servo myservo;
int servoPin = 8;
int angle = 0;
int maxAngle = 90;  // MaxAngle is 180
int minAngle = 0;
int angleStep = 2;
unsigned long previousMillis = 0; // to store last time servo was updated
const long interval = 200;        // interval at which to move servo (milliseconds)

void setup() {
  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Buzzer
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  
  // Servo Motor
  myservo.attach(servoPin);
}

void loop() {
  // Ultrasonic Sensor Code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  // Buzzer Activation based on Distance
  if (distance < 10) {
    // Turn on the buzzer if distance is less than 10 cm
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Otherwise, turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Servo Motor Code
  // Use millis() to avoid delay() function, which would halt the execution of other parts of the program.
  unsigned long currentMillis = millis();  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    myservo.write(angle); // Always write the current angle to servo

    // Serial output formatted for Serial Plotter
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);

    angle += angleStep;   // Always increment or decrement angle

    // Check and reverse the direction if needed
    if (angle > maxAngle || angle < minAngle) {
      angleStep = -angleStep;
      angle += angleStep; // Adjust angle immediately to prevent it from going out of the valid range
    }
  }
}
