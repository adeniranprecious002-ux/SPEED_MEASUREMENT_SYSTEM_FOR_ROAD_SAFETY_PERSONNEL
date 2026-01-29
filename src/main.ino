/*
 * Speed Measurement System for Road Safety Personnel
 *
 * Author: Adeniran Precious Adebayo
 * University: University of Abuja
 * Department: Electrical/Electronics Engineering
 * Year: 2024
 *
 * Description: This system measures vehicle speed using an ultrasonic sensor
 * and alerts when the speed limit is exceeded using a buzzer and LCD display.
 *
 * Components:
 * - Arduino Uno (ATmega328)
 * - HC-SR04 Ultrasonic Sensor
 * - 16x2 LCD Display
 * - Buzzer
 * - LEDs for status indication
 */

#include <Arduino.h>
#include <LiquidCrystal.h>

// Pin Definitions
#define TRIG_PIN 7    // Ultrasonic sensor trigger pin
#define ECHO_PIN 6    // Ultrasonic sensor echo pin
#define BUZZER_PIN 8  // Buzzer pin
#define LED_GREEN 9   // Green LED for safe speed
#define LED_RED 10    // Red LED for over-speed
#define BUTTON_PIN 13 // Push button for reset/settings

// LCD Pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// System Constants
const float SPEED_LIMIT = 60.0;    // Speed limit in km/h
const int MEASUREMENT_DELAY = 100; // Delay between measurements (ms)
const float SOUND_SPEED = 0.0343;  // Speed of sound in cm/μs

// Variables for speed calculation
float duration, distance;
float speed_kmh = 0;
float previous_distance = 0;
unsigned long previous_time = 0;
bool first_measurement = true;

void setup()
{
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize LCD (16 columns, 2 rows)
  lcd.begin(16, 2);

  // Configure pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initial state
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);

  // Display welcome message
  displayWelcomeMessage();
  delay(2000);

  // Clear LCD and prepare for measurements
  lcd.clear();
}

void loop()
{
  // Get current distance measurement
  distance = measureDistance();

  // Calculate speed if we have a previous measurement
  if (!first_measurement && distance > 0 && distance < 400)
  {
    unsigned long current_time = millis();
    float time_diff = (current_time - previous_time) / 1000.0; // Convert to seconds

    // Calculate speed: distance difference / time difference
    if (time_diff > 0)
    {
      float distance_diff = abs(previous_distance - distance) / 100.0; // Convert cm to meters
      float speed_ms = distance_diff / time_diff;                      // Speed in m/s
      speed_kmh = speed_ms * 3.6;                                      // Convert to km/h

      // Filter out unrealistic speeds (noise)
      if (speed_kmh > 0 && speed_kmh < 200)
      {
        updateDisplay(speed_kmh, distance);
        checkSpeedLimit(speed_kmh);
      }
    }

    previous_time = current_time;
  }
  else
  {
    previous_time = millis();
    first_measurement = false;
  }

  previous_distance = distance;

  // Check for button press (reset/clear)
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    resetSystem();
    delay(300); // Debounce delay
  }

  delay(MEASUREMENT_DELAY);
}

float measureDistance()
{
  // Clear trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10μs pulse to trigger pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pin and calculate duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm (duration * speed of sound / 2)
  float dist = (duration * SOUND_SPEED) / 2;

  return dist;
}

void updateDisplay(float speed, float dist)
{
  lcd.clear();

  // First line: Speed
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(speed, 1);
  lcd.print(" km/h");

  // Second line: Distance
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(dist, 1);
  lcd.print(" cm");

  // Debug output
  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(" km/h | Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
}

void checkSpeedLimit(float speed)
{
  if (speed > SPEED_LIMIT)
  {
    // Over speed - activate alarm
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);

    // Sound buzzer with pulsing pattern
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }

    Serial.println("WARNING: SPEED LIMIT EXCEEDED!");
  }
  else
  {
    // Normal speed
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void displayWelcomeMessage()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed Monitor");
  lcd.setCursor(0, 1);
  lcd.print("System Ready!");
}

void resetSystem()
{
  // Reset all variables
  speed_kmh = 0;
  previous_distance = 0;
  first_measurement = true;

  // Reset LEDs and buzzer
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);

  // Display reset message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Reset");
  delay(1000);
  lcd.clear();

  Serial.println("System reset");
}
