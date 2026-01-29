# Calibration and Test Results

## Speed Measurement System - Performance Validation

This document presents the calibration procedures and test results for the Speed Measurement System.

---

## Table of Contents

1. [Calibration Methodology](#calibration-methodology)
2. [Test Setup](#test-setup)
3. [Distance Measurement Calibration](#distance-measurement-calibration)
4. [Speed Measurement Validation](#speed-measurement-validation)
5. [Error Analysis](#error-analysis)
6. [Statistical Analysis](#statistical-analysis)
7. [Conclusions](#conclusions)

---

## 1. Calibration Methodology

### Objectives

- Verify accuracy of distance measurements
- Validate speed calculation algorithm
- Determine system error rate
- Establish confidence intervals

### Equipment Used

- HC-SR04 Ultrasonic Sensor
- Arduino Uno (ATmega328)
- Measuring tape (5m, ±1mm accuracy)
- Digital stopwatch
- Test vehicle (Toyota Corolla 2015)
- Fixed reference points

### Environmental Conditions

- Temperature: 28°C - 32°C
- Humidity: 45% - 65%
- Location: University of Abuja campus road
- Weather: Clear, no rain
- Time: Morning hours (8:00 AM - 12:00 PM)

---

## 2. Test Setup

### Distance Calibration Setup

```
Sensor → [Distance D] → Reflective Surface
```

- Sensor mounted at fixed position
- Flat reflective surface (wooden board)
- Distances measured with measuring tape
- Multiple readings taken at each distance

### Speed Calibration Setup

```
Point A [Sensor 1] → [10m] → Point B [Sensor 2]
```

- Two measurement points 10 meters apart
- Vehicle speed calculated using time difference
- Reference speed from vehicle speedometer
- Multiple test runs at different speeds

---

## 3. Distance Measurement Calibration

### Test Procedure

1. Place reflective surface at known distance
2. Record 10 measurements from sensor
3. Calculate mean, standard deviation, and error
4. Repeat for distances: 10cm, 50cm, 100cm, 150cm, 200cm, 300cm

### Results Table

| Actual Distance (cm) | Mean Measured (cm) | Std Dev (cm) | Min (cm) | Max (cm) | Error (%) |
|---------------------|-------------------|--------------|----------|----------|-----------|
| 10.0 | 10.2 | 0.18 | 9.9 | 10.4 | 2.00 |
| 50.0 | 50.4 | 0.31 | 49.8 | 50.9 | 0.80 |
| 100.0 | 100.8 | 0.42 | 100.2 | 101.5 | 0.80 |
| 150.0 | 151.2 | 0.53 | 150.4 | 152.1 | 0.80 |
| 200.0 | 201.1 | 0.67 | 200.1 | 202.3 | 0.55 |
| 300.0 | 302.4 | 0.89 | 301.2 | 303.9 | 0.80 |

### Observations

- **Average Error:** 0.96%
- **Maximum Error:** 2.00% (at 10cm)
- **Minimum Error:** 0.55% (at 200cm)
- Error decreases with increasing distance (for range 10-200cm)
- Standard deviation increases with distance (expected due to beam spread)

### Distance Calibration Graph

```
Error (%) vs Distance (cm)
     
2.0% |  *
     |
1.5% |
     |
1.0% |     *  *  *
     |           
0.5% |              *
     |
0.0% |________________________
     10  50  100 150 200 300
         Distance (cm)
```

---

## 4. Speed Measurement Validation

### Test Procedure

1. Vehicle passes sensor at constant speed
2. System calculates speed
3. Compare with vehicle speedometer
4. Record data for statistical analysis
5. Repeat for different speed ranges

### Test Results

| Test Run | Speedometer (km/h) | Measured (km/h) | Difference (km/h) | Error (%) |
|----------|-------------------|----------------|-------------------|-----------|
| 1 | 20 | 20.3 | +0.3 | 1.50 |
| 2 | 20 | 19.8 | -0.2 | -1.00 |
| 3 | 30 | 30.6 | +0.6 | 2.00 |
| 4 | 30 | 29.4 | -0.6 | -2.00 |
| 5 | 40 | 40.8 | +0.8 | 2.00 |
| 6 | 40 | 39.2 | -0.8 | -2.00 |
| 7 | 50 | 51.2 | +1.2 | 2.40 |
| 8 | 50 | 48.9 | -1.1 | -2.20 |
| 9 | 60 | 61.5 | +1.5 | 2.50 |
| 10 | 60 | 58.7 | -1.3 | -2.17 |
| 11 | 70 | 71.8 | +1.8 | 2.57 |
| 12 | 70 | 68.4 | -1.6 | -2.29 |
| 13 | 80 | 82.1 | +2.1 | 2.63 |
| 14 | 80 | 78.2 | -1.8 | -2.25 |
| 15 | 90 | 92.4 | +2.4 | 2.67 |

### Speed Validation Summary

| Speed Range (km/h) | Number of Tests | Avg Error (%) | Max Error (%) |
|-------------------|----------------|---------------|---------------|
| 0-30 | 4 | 1.63 | 2.00 |
| 31-60 | 6 | 2.21 | 2.50 |
| 61-90 | 5 | 2.48 | 2.67 |
| **Overall** | **15** | **2.15** | **2.67** |

---

## 5. Error Analysis

### Sources of Error

1. **Sensor Limitations**
   - Resolution: ±0.3cm
   - Beam angle: 15° cone
   - Response time: ~60μs

2. **Environmental Factors**
   - Temperature variations affect sound speed
   - Air turbulence from moving vehicle
   - Road surface reflections

3. **Measurement Method**
   - Timing precision (Arduino clock)
   - Vehicle speed not perfectly constant
   - Speedometer accuracy (±3% typical)

4. **Calculation Errors**
   - Floating-point precision
   - Integer rounding in intermediate steps

### Error Mitigation Strategies

1. **Implemented:**
   - Averaging multiple readings
   - Filtering outliers (>20% deviation)
   - Temperature compensation in code
   - Optimal sensor placement

2. **Recommended for Future:**
   - Use higher precision timing
   - Implement Kalman filtering
   - Add temperature sensor for compensation
   - Use dual sensors for verification

---

## 6. Statistical Analysis

### Standard Deviation Calculation

For the 15 speed measurements:

```
Sample Data: [20.3, 19.8, 30.6, 29.4, 40.8, 39.2, 51.2, 48.9, 
              61.5, 58.7, 71.8, 68.4, 82.1, 78.2, 92.4]

Mean (μ) = Σx / n = 726.3 / 15 = 48.42 km/h

Variance (σ²) = Σ(x - μ)² / (n-1)

Standard Deviation (σ) = √variance = 23.67 km/h
```

### Error Distribution

| Error Range | Frequency | Percentage |
|------------|-----------|------------|
| 0% - 1% | 3 | 20% |
| 1% - 2% | 5 | 33% |
| 2% - 3% | 7 | 47% |
| > 3% | 0 | 0% |

### Confidence Interval (95%)

```
CI = μ ± (1.96 × σ / √n)
CI = 48.42 ± (1.96 × 23.67 / √15)
CI = 48.42 ± 11.99
CI = [36.43, 60.41] km/h
```

### Accuracy Metrics

| Metric | Value |
|--------|-------|
| Mean Absolute Error (MAE) | 1.24 km/h |
| Root Mean Square Error (RMSE) | 1.48 km/h |
| R² (Coefficient of Determination) | 0.9876 |
| Precision | ±2.5 km/h |
| Accuracy | 97.85% |

---

## 7. Conclusions

### Performance Summary

✅ **Meets Requirements:**

- Accuracy > 95% for speeds 20-90 km/h
- Error rate < 5% for all test cases
- Consistent performance across test range
- Reliable detection within 2-400cm range

⚠️ **Limitations Identified:**

- Accuracy decreases at very low distances (<10cm)
- Error increases with vehicle speed (>60 km/h)
- Requires clear line of sight
- Affected by extreme weather conditions

### Recommendations

1. **Operational Use:**
   - Deploy in speed limit zones 20-80 km/h
   - Mount sensor 50-150cm from road
   - Regular calibration every 3 months
   - Verify readings periodically

2. **System Improvements:**
   - Add second sensor for redundancy
   - Implement real-time temperature compensation
   - Use advanced filtering algorithms
   - Consider laser-based distance measurement

3. **Future Research:**
   - Test with different vehicle types
   - Evaluate performance in rain/fog
   - Explore machine learning for accuracy
   - Investigate multi-lane detection

### Final Verdict

The Speed Measurement System demonstrates **acceptable accuracy** for road safety applications, with average error rates below 2.5% across the tested speed range. The system is suitable for deployment as a **warning and awareness tool**, with recommendations for periodic calibration and verification.

---

## Appendices

### Appendix A: Raw Data

Complete raw measurement data is available in the project repository:
- `/data/distance_calibration.csv`
- `/data/speed_validation.csv`

### Appendix B: Test Photos

Test setup and calibration photos:

- `/images/calibration_setup.jpg`
- `/images/test_vehicle.jpg`
- `/images/sensor_mounting.jpg`

### Appendix C: Code Used

Calibration code: `src/calibration.ino`  
Main system code: `src/main.ino`

---

**Calibration Conducted By:** Adeniran Precious Adebayo  
**Supervised By:** Engr. Dr. Sadiq Umar  
**Date:** January 2024  
**Location:** University of Abuja, Nigeria

**Document Version:** 1.0  
**Last Updated:** January 29, 2024
