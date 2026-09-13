// Object Detection using Ultrasonic Sensor and Buzzer

const int triggerPin = 9;
const int echo = 10;
const int buzzer = 11;

long duration;
int distance;

void setup()
{
  pinMode(triggerPin, OUTPUT);   // Trigger pin as Output
  pinMode(echo, INPUT);          // Echo pin as Input
  pinMode(buzzer, OUTPUT);       // Buzzer as Output

  Serial.begin(9600);            // Start Serial Monitor
}

void loop()
{
  // Generate ultrasonic pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echo, HIGH);

  // Calculate distance (in cm)
  distance = duration * 0.034 / 2;

  // Object detection
  if (distance <= 10)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }

  // Print distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(100);
}