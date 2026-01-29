# Speed Measurement System for Road Safety Personnel

![Project Status](https://img.shields.io/badge/status-completed-success)
![License](https://img.shields.io/badge/license-MIT-blue)
![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino)

## 📋 Project Overview

This repository contains the complete documentation and implementation of a **Speed Measurement System for Road Safety Personnel**, developed as an undergraduate final year project at the University of Abuja, Department of Electrical/Electronics Engineering.

The system is designed to measure vehicle speed using ultrasonic sensors and alert road users when they exceed the designated speed limit, contributing to improved road safety and accident prevention.

### Key Features

- ✅ Real-time speed measurement using ultrasonic sensors
- ✅ Visual display of speed on LCD screen
- ✅ Audible alert system using buzzer for speeding violations
- ✅ Accurate distance and speed calculation
- ✅ Portable and cost-effective design
- ✅ Arduino-based implementation for easy customization

## 🎯 Project Context

### Problem Statement

The continuous increase in death rates caused by road accidents led to the innovation of this speed measuring device to help control the rate of over-speeding on roads.

### Statistics

According to the World Health Organization (WHO):

- Over **1.3 million people** die annually due to road accidents worldwide
- In Nigeria alone, approximately **41,693 deaths** occur yearly (2.82% of global total)
- Over-speeding is identified as a major contributing factor

## 🛠️ Technical Specifications

### Hardware Components

| Component | Specification | Purpose |
|-----------|--------------|---------|
| Microcontroller | Arduino Uno (ATmega328) | Main processing unit |
| Sensor | HC-SR04 Ultrasonic | Distance and speed measurement |
| Display | 16x2 LCD | Speed visualization |
| Alert System | Buzzer | Speeding alarm |
| Power Supply | Lithium Battery | Portable power source |
| Other | Resistors, Transistors, LEDs, Breadboard | Supporting circuitry |

### Software

- **Development Environment:** Arduino IDE
- **Programming Language:** C/C++ (Arduino)
- **Simulation Software:** Proteus 8
- **Libraries Used:**
  - LiquidCrystal.h (LCD control)
  - Standard Arduino libraries

## 📊 System Architecture

```
┌─────────────────┐
│  Power Supply   │
│  (Li Battery)   │
└────────┬────────┘
         │
         ▼
┌─────────────────┐     ┌──────────────────┐
│  Arduino Uno    │◄────┤ Ultrasonic       │
│  (ATmega328)    │     │ Sensor (HC-SR04) │
└────────┬────────┘     └──────────────────┘
         │
         ├──────────────┐
         │              │
         ▼              ▼
┌─────────────┐  ┌─────────────┐
│  LCD Display│  │   Buzzer    │
│  (16x2)     │  │  (Alert)    │
└─────────────┘  └─────────────┘
```

## 🔧 Working Principle

1. **Detection Phase:** The ultrasonic sensor emits sound waves that bounce off approaching vehicles
2. **Calculation Phase:** The Arduino calculates speed using the formula:

   ```
   Speed (km/h) = (Distance / Time) × 3.6
   ```

3. **Display Phase:** Real-time speed is shown on the LCD display
4. **Alert Phase:** If speed exceeds the set threshold, the buzzer activates
5. **Reset Phase:** System resets for the next measurement cycle

## 📁 Repository Structure

```
├── README.md                   # This file
├── LICENSE                     # MIT License
├── docs/                       # Documentation
│   ├── project_report.pdf      # Complete project report
│   ├── circuit_diagram.png     # Schematic diagram
│   ├── flowchart.png          # System flowchart
│   └── calibration_results.md  # Test results
├── src/                        # Source code
│   ├── main.ino               # Main Arduino sketch
│   └── calibration.ino        # Calibration code
├── simulation/                 # Proteus simulation files
│   └── speed_sensor.pdsprj   # Proteus project file
├── hardware/                   # Hardware documentation
│   ├── components_list.md     # Bill of materials
│   └── assembly_guide.md      # Assembly instructions
└── images/                     # Project images
    ├── prototype.jpg
    └── component_photos/
```

## 🚀 Getting Started

### Prerequisites

- Arduino IDE (version 1.8.x or higher)
- Arduino Uno board
- HC-SR04 Ultrasonic sensor
- 16x2 LCD display
- Buzzer and other components (see Bill of Materials)

### Installation

1. Clone this repository:

```bash
git clone https://github.com/adeniranprecious002-ux/SPEED_MEASUREMENT_SYSTEM_FOR_ROAD_SAFETY_PERSONNEL.git
cd speed-measurement-system
```

1. Open the Arduino IDE and load the main sketch:

```bash
File -> Open -> src/main.ino
```

1. Install required libraries (if not already installed):
   - Sketch -> Include Library -> Manage Libraries
   - Search for "LiquidCrystal" and install

2. Connect your Arduino Uno and upload the code:
   - Tools -> Board -> Arduino Uno
   - Tools -> Port -> [Select your port]
   - Sketch -> Upload

### Hardware Setup

1. Connect the ultrasonic sensor:
   - VCC → 5V
   - GND → GND
   - TRIG → Pin 7
   - ECHO → Pin 6

2. Connect the LCD display:
   - VSS → GND
   - VDD → 5V
   - RS → Pin 12
   - E → Pin 11
   - D4-D7 → Pins 5, 4, 3, 2

3. Connect the buzzer:
   - Positive → Pin 8 (through transistor)
   - Negative → GND

4. Power the system using the lithium battery

## 📈 Results and Performance

### Accuracy Testing

- **Average Error Rate:** < 5%
- **Standard Deviation:** Calculated for multiple test runs
- **Operating Range:** 2cm - 400cm
- **Speed Detection Range:** 0 - 120 km/h

### Test Results Summary

The system was tested under various conditions with different vehicle speeds. Detailed results can be found in `docs/calibration_results.md`.

## 🎓 Academic Information

- **Student:** Adeniran Precious Adebayo
- **Matric No:** 18245011
- **Supervisor:** Engr. Dr. Sadiq Umar
- **Department:** Electrical/Electronics Engineering
- **Institution:** University of Abuja, Nigeria
- **Degree:** B.Eng in Electrical/Electronic Engineering
- **Year:** 2024

## 🔮 Future Improvements

- [ ] Integration with IoT for cloud-based monitoring
- [ ] Camera module for vehicle identification
- [ ] GPS module for location tracking
- [ ] Solar power option for remote deployment
- [ ] Mobile app for real-time alerts
- [ ] Machine learning for traffic pattern analysis
- [ ] Multi-lane detection capability
- [ ] Weather compensation algorithms

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Engr. Dr. Sadiq Umar (Project Supervisor)
- Department of Electrical/Electronics Engineering, University of Abuja
- All lecturers and staff who provided guidance
- Family and friends for their support

## 📞 Contact

For questions or collaborations, please contact:

- Email: [adeniranprecious002@gmail.com]
- LinkedIn: ([Adeniran Precious Adebayo](https://www.linkedin.com/in/precious-adeniran-842b58294))
- GitHub: [@adeniranprecious002-ux](https://github.com/adeniranprecious002-ux)

## 📚 References

Complete references are available in the project documentation. Key sources include:

- World Health Organization (WHO) road safety statistics
- Arduino official documentation
- Ultrasonic sensor datasheets and application notes

## ⭐ Star this Repository

If you found this project helpful, please consider giving it a star! It helps others discover this work and motivates further development.

---

**Disclaimer:** This project was developed for educational purposes as part of an undergraduate degree program. While the system demonstrates functional speed measurement capabilities, it should be further tested and certified before deployment in production road safety applications.
