/*
 * Calibration Code for Speed Measurement System
 * 
 * This code is used to calibrate the ultrasonic sensor and verify
 * the accuracy of distance and speed measurements.
 * 
 * Author: Adeniran Precious Adebayo
 * University: University of Abuja
 */

#include <LiquidCrystal.h>

// Pin Definitions
#define TRIG_PIN 7
#define ECHO_PIN 6

// LCD Pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Calibration variables
const int NUM_SAMPLES = 10;
float distances[NUM_SAMPLES];
int sample_count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  lcd.print("Calibration Mode");
  delay(2000);
  lcd.clear();
  
  Serial.println("=== ULTRASONIC SENSOR CALIBRATION ===");
  Serial.println("Place object at known distances and record readings");
  Serial.println();
}

void loop() {
  float distance = measureDistance();
  
  if (distance > 0 && distance < 400) {
    // Store sample
    if (sample_count < NUM_SAMPLES) {
      distances[sample_count] = distance;
      sample_count++;
    } else {
      // Calculate statistics
      calculateStatistics();
      sample_count = 0; // Reset for next batch
    }
    
    // Display on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance, 2);
    lcd.setCursor(0, 1);
    lcd.print("Sample: ");
    lcd.print(sample_count);
    lcd.print("/");
    lcd.print(NUM_SAMPLES);
    
    // Display on Serial
    Serial.print("Sample ");
    Serial.print(sample_count);
    Serial.print(": ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(500);
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2;
  
  return distance;
}

void calculateStatistics() {
  float sum = 0;
  float mean = 0;
  float variance = 0;
  float std_dev = 0;
  float min_dist = distances[0];
  float max_dist = distances[0];
  
  // Calculate mean
  for (int i = 0; i < NUM_SAMPLES; i++) {
    sum += distances[i];
    if (distances[i] < min_dist) min_dist = distances[i];
    if (distances[i] > max_dist) max_dist = distances[i];
  }
  mean = sum / NUM_SAMPLES;
  
  // Calculate variance and standard deviation
  for (int i = 0; i < NUM_SAMPLES; i++) {
    variance += pow(distances[i] - mean, 2);
  }
  variance = variance / NUM_SAMPLES;
  std_dev = sqrt(variance);
  
  // Display results
  Serial.println("\n=== STATISTICS ===");
  Serial.print("Mean: ");
  Serial.print(mean, 2);
  Serial.println(" cm");
  
  Serial.print("Min: ");
  Serial.print(min_dist, 2);
  Serial.println(" cm");
  
  Serial.print("Max: ");
  Serial.print(max_dist, 2);
  Serial.println(" cm");
  
  Serial.print("Range: ");
  Serial.print(max_dist - min_dist, 2);
  Serial.println(" cm");
  
  Serial.print("Standard Deviation: ");
  Serial.print(std_dev, 2);
  Serial.println(" cm");
  
  Serial.print("Variance: ");
  Serial.print(variance, 2);
  Serial.println(" cm²");
  
  Serial.println("\nPress any key to continue...\n");
  
  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mean:");
  lcd.print(mean, 1);
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("SD:");
  lcd.print(std_dev, 2);
  lcd.print("cm");
  
  delay(5000);
}
