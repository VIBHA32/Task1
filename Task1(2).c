/ Air Sensor System

// Pin assignments
const int gasSensorPin = A0;  // Analog input pin for gas sensor
const int buzzerPin = 9;     // Digital output pin for buzzer

// Threshold values for gas detection
const int gasThreshold = 500;  // Adjust this value according to your sensor's sensitivity

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize buzzer pin
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasSensorPin);

  // Print gas sensor value to serial monitor
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  // Check if gas value exceeds threshold
  if (gasValue > gasThreshold) {
    // Activate the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
  }

  // Delay before the next reading
  delay(1000);
}