# Quick Start Guide

Get your Speed Measurement System up and running in 30 minutes!

## 📦 What You Need

### Hardware

- ✅ Arduino Uno board
- ✅ HC-SR04 Ultrasonic sensor
- ✅ 16x2 LCD display
- ✅ Buzzer
- ✅ LEDs (1 Red, 1 Green)
- ✅ Breadboard and jumper wires
- ✅ Power supply (USB cable or battery)

### Software

- ✅ Arduino IDE ([Download here](https://www.arduino.cc/en/software))
- ✅ USB cable for Arduino
- ✅ This repository's code

## 🚀 5-Minute Setup

### Step 1: Install Arduino IDE (2 minutes)

1. Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Install following the installer instructions
3. Open Arduino IDE

### Step 2: Get the Code (1 minute)

```bash
# Option A: Clone with Git
git clone https://github.com/adeniranprecious002-ux/SPEED_MEASUREMENT_SYSTEM_FOR_ROAD_SAFETY_PERSONNEL.git

# Option B: Download ZIP
# Click 'Code' → 'Download ZIP' on GitHub
```

### Step 3: Hardware Connections (5 minutes)

#### Quick Connection Table

| Component | Arduino Pin |
|-----------|-------------|
| Ultrasonic VCC | 5V |
| Ultrasonic GND | GND |
| Ultrasonic TRIG | Pin 7 |
| Ultrasonic ECHO | Pin 6 |
| LCD RS | Pin 12 |
| LCD E | Pin 11 |
| LCD D4-D7 | Pins 5,4,3,2 |
| Buzzer | Pin 8 |
| Green LED | Pin 9 |
| Red LED | Pin 10 |

**Tip:** See `hardware/assembly_guide.md` for detailed wiring diagrams.

### Step 4: Upload Code (3 minutes)

1. Connect Arduino to computer via USB
2. Open `src/main.ino` in Arduino IDE
3. Select Tools → Board → Arduino Uno
4. Select Tools → Port → [Your Arduino's port]
5. Click Upload (→) button
6. Wait for "Upload Complete"

### Step 5: Test (1 minute)

1. Open Tools → Serial Monitor (Ctrl+Shift+M)
2. Set baud rate to 9600
3. Wave your hand in front of sensor
4. You should see distance readings!

## 🎯 First Test Run

### What You Should See

- ✅ LCD displays "Speed Monitor System Ready"
- ✅ Green LED is ON
- ✅ Serial monitor shows distance readings
- ✅ Moving objects are detected

### Testing the Alarm

1. Set a low speed limit (edit `SPEED_LIMIT` in code to 5)
2. Re-upload the code
3. Wave hand quickly in front of sensor
4. Buzzer should sound, Red LED should light up

## ⚙️ Configuration

### Changing Speed Limit

Edit this line in `main.ino`:

```cpp
const float SPEED_LIMIT = 60.0;  // Change this value (km/h)
```

### Adjusting LCD Contrast

Turn the potentiometer connected to LCD Pin 3 until text is clear.

### Calibration

For accurate readings:

1. Upload `src/calibration.ino`
2. Follow on-screen instructions
3. Record calibration values
4. Adjust if needed

## 📱 Using the System

### Normal Operation

1. Power on the system
2. Wait for "System Ready" message
3. Position sensor facing the road
4. System automatically measures passing vehicles
5. Buzzer alerts if speed > limit

### Reading the Display

```
┌────────────────┐
│Speed: 45.2 km/h│ ← Current speed
│Dist: 125.5 cm  │ ← Distance to vehicle
└────────────────┘
```

### LED Indicators

- 🟢 **Green LED:** Speed within limit
- 🔴 **Red LED:** Speed exceeds limit

### Push Button

- Press to reset readings
- Hold for 3 seconds to enter settings (future feature)

## 🔧 Troubleshooting

### LCD Shows Nothing

- ✅ Check all 14 LCD connections
- ✅ Adjust potentiometer for contrast
- ✅ Verify 5V power to LCD

### No Distance Readings

- ✅ Check sensor VCC and GND
- ✅ Verify TRIG and ECHO connections
- ✅ Ensure sensor faces open space

### Buzzer Not Working

- ✅ Check Pin 8 connection
- ✅ Verify buzzer polarity
- ✅ Test with different speed threshold

### Erratic Readings

- ✅ Keep sensor away from metal surfaces
- ✅ Ensure stable power supply
- ✅ Check for loose connections

**More help:** See `docs/troubleshooting.md`

## 📚 Next Steps

### Learn More

- 📖 Read the [complete documentation](/docs)
- 🔨 Study the [hardware assembly guide](/hardware/assembly_guide.md)
- 📊 Review [calibration results](/docs/calibration_results.md)
- 💻 Explore the [source code](/src)

### Improve Your System

- Add GPS for location tracking
- Connect to WiFi for IoT features
- Build a weatherproof enclosure
- Integrate with traffic camera

### Share Your Results

- Post photos on social media
- Contribute improvements to this repo
- Help others in issues/discussions
- Write about your experience

## 🆘 Getting Help

**Need assistance?**

1. Check [FAQ](/docs/faq.md)
2. Search [existing issues](https://github.com/adeniranprecious002-ux/SPEED_MEASUREMENT_SYSTEM_FOR_ROAD_SAFETY_PERSONNEL/issues)
3. Open a [new issue](https://github.com/adeniranprecious002-ux/SPEED_MEASUREMENT_SYSTEM_FOR_ROAD_SAFETY_PERSONNEL/issues/new)
4. Contact: <adeniranprecious002@.com>

## ⭐ Success

If everything is working:

- Star this repository ⭐
- Share with friends
- Consider contributing improvements

---

## Happy Building! 🚗💨

**Author:** Adeniran Precious Adebayo  
**University:** University of Abuja
