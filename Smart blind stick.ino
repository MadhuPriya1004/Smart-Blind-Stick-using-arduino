// Define pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define pins for the buzzer and LED
const int buzzerPin = 5;
const int ledPin = 6;

// Variables to store the distance measurements
long duration;
int distanceCm, distanceInch;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Set the trigger pin as an output and the echo pin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set the buzzer and LED pins as outputs
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters and inches
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Delay for stability
  delay(100);

  // Control the buzzer and LED based on distance
  if (distanceCm < 25) { // Change the threshold value as needed
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
    digitalWrite(ledPin, HIGH);    // Turn the LED on
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn the buzzer off
    digitalWrite(ledPin, LOW);     // Turn the LED off
  }
}
