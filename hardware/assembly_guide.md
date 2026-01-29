# Hardware Assembly Guide

## Speed Measurement System - Step-by-Step Assembly

This guide provides detailed instructions for assembling the speed measurement system hardware.

## ⚠️ Safety Precautions

Before you begin:
- [ ] Work in a well-lit, static-free environment
- [ ] Disconnect power before making connections
- [ ] Double-check polarity before connecting power
- [ ] Use proper ESD (Electrostatic Discharge) precautions
- [ ] Keep liquids away from electronic components
- [ ] Verify component ratings before connection

## 📋 Prerequisites

### Required Components
Refer to `components_list.md` for the complete bill of materials.

### Required Tools
- Soldering iron and solder
- Wire stripper
- Multimeter
- Screwdriver set
- Breadboard or PCB
- Wire cutters
- Hot glue gun (optional)

## 🔧 Assembly Steps

### Step 1: Prepare the Breadboard

1. Place the Arduino Uno on the workspace
2. Position the breadboard next to the Arduino
3. Organize components by type for easy access

### Step 2: Power Supply Setup

#### 2.1 Voltage Regulator Circuit
```
Battery (+) → 7805 Regulator (Input)
7805 (Ground) → Common Ground
7805 (Output) → 5V Power Rail
Battery (-) → Common Ground
```

**Connections:**
1. Connect the 7805 voltage regulator to the breadboard
2. Add a 100μF capacitor between input and ground (observe polarity)
3. Add a 100μF capacitor between output and ground
4. Connect battery positive to 7805 input
5. Connect battery negative to ground rail
6. Connect 7805 output to 5V power rail

**Testing:**
- Use multimeter to verify 5V output
- Check for stable voltage (no fluctuation)

### Step 3: Arduino Setup

#### 3.1 Power Connections
```
Breadboard 5V → Arduino 5V (or VIN if using 7.4V directly)
Breadboard GND → Arduino GND
```

1. Connect Arduino GND to breadboard ground rail
2. Connect Arduino 5V to breadboard power rail (if using regulated 5V)
3. Alternatively, power Arduino via USB during testing

### Step 4: Ultrasonic Sensor (HC-SR04)

#### 4.1 Sensor Placement
Mount the sensor at the front of the enclosure facing the road.

#### 4.2 Wiring
```
HC-SR04 VCC → Arduino 5V
HC-SR04 GND → Arduino GND
HC-SR04 TRIG → Arduino Pin 7
HC-SR04 ECHO → Arduino Pin 6
```

**Connection Details:**
1. Red wire (VCC) to 5V rail
2. Black wire (GND) to ground rail
3. Yellow wire (TRIG) to Digital Pin 7
4. Green wire (ECHO) to Digital Pin 6

**Note:** Keep sensor wires short (< 20cm) to minimize interference

### Step 5: LCD Display (16x2)

#### 5.1 Contrast Adjustment Circuit
1. Connect 10kΩ potentiometer:
   - Pin 1 → 5V
   - Pin 2 (wiper) → LCD V0 (Pin 3)
   - Pin 3 → GND

#### 5.2 LCD Connections
```
LCD Pin 1 (VSS) → GND
LCD Pin 2 (VDD) → 5V
LCD Pin 3 (V0) → Potentiometer wiper
LCD Pin 4 (RS) → Arduino Pin 12
LCD Pin 5 (RW) → GND
LCD Pin 6 (E) → Arduino Pin 11
LCD Pin 11 (D4) → Arduino Pin 5
LCD Pin 12 (D5) → Arduino Pin 4
LCD Pin 13 (D6) → Arduino Pin 3
LCD Pin 14 (D7) → Arduino Pin 2
LCD Pin 15 (A) → 5V (through 220Ω resistor for backlight)
LCD Pin 16 (K) → GND
```

**Testing:**
- Power on and adjust potentiometer
- You should see blocks on the first row
- Adjust for optimal contrast

### Step 6: Buzzer Circuit

#### 6.1 Transistor Driver Circuit
The buzzer requires a transistor to handle current.

```
Arduino Pin 8 → 10kΩ Resistor → BC547 Base
BC547 Collector → Buzzer (+)
BC547 Emitter → GND
Buzzer (-) → 5V
```

**Assembly:**
1. Insert BC547 transistor into breadboard
2. Connect 10kΩ resistor from Pin 8 to transistor base
3. Connect transistor collector to buzzer positive
4. Connect transistor emitter to ground
5. Connect buzzer negative to 5V rail

### Step 7: LED Indicators

#### 7.1 Green LED (Normal Speed)
```
Arduino Pin 9 → 220Ω Resistor → LED Anode (+)
LED Cathode (-) → GND
```

#### 7.2 Red LED (Over-speed)
```
Arduino Pin 10 → 220Ω Resistor → LED Anode (+)
LED Cathode (-) → GND
```

**LED Identification:**
- Longer leg = Anode (+)
- Shorter leg = Cathode (-)
- Flat side of LED = Cathode

### Step 8: Push Button

#### 8.1 Button with Pull-up Resistor
```
One side of button → Arduino Pin 13
Same side → 10kΩ Resistor → 5V
Other side of button → GND
```

**Note:** Arduino Pin 13 has internal pull-up, but external resistor ensures reliable operation.

### Step 9: Decoupling Capacitors

Add 0.1μF ceramic capacitors:
1. One near Arduino 5V and GND
2. One near sensor VCC and GND
3. One near LCD VDD and VSS

These reduce electrical noise.

## 🧪 Testing Each Component

### Test 1: Power Supply
```
Expected: 5V between power rail and ground
Tool: Multimeter
Action: Measure voltage with multimeter
Result: Should read 4.8V - 5.2V
```

### Test 2: Ultrasonic Sensor
```
Upload: calibration.ino
Expected: Distance readings on Serial Monitor
Variation: < 1cm for stationary object
```

### Test 3: LCD Display
```
Upload: LiquidCrystal example sketch
Expected: "Hello World" displayed
Action: Adjust potentiometer for contrast
```

### Test 4: Buzzer
```
Upload: tone() example sketch
Expected: Audible sound
Volume: Should be clear, not distorted
```

### Test 5: LEDs
```
Upload: Blink example sketch (modified for pins 9 & 10)
Expected: Both LEDs blinking
Brightness: Should be visible in normal light
```

### Test 6: Complete System
```
Upload: main.ino
Expected: 
- LCD shows "Speed Monitor System Ready"
- Green LED on
- Distance updates when object moves
- Buzzer sounds if "speed" exceeds limit
```

## 📦 Enclosure Assembly

### Step 10: Mounting in Enclosure

1. **Plan the Layout:**
   - LCD on front panel (visible)
   - Ultrasonic sensor on front (facing outward)
   - LEDs near LCD
   - Arduino and breadboard inside
   - Battery in separate compartment

2. **Cut Holes:**
   - LCD: 71mm x 25mm rectangular hole
   - Sensor: 18mm x 45mm for HC-SR04
   - LEDs: Two 5mm holes
   - Power switch: 6mm hole

3. **Mount Components:**
   - Use hot glue for LCD and sensor
   - Use screws for Arduino (with standoffs)
   - Use double-sided tape for breadboard
   - Secure battery with velcro straps

4. **Cable Management:**
   - Bundle wires with cable ties
   - Keep power wires away from signal wires
   - Leave slack for servicing

## 🔍 Troubleshooting Guide

### Problem: No Power
- Check battery voltage
- Verify regulator connections
- Test for short circuits

### Problem: LCD Shows Nothing
- Check potentiometer adjustment
- Verify 5V on VDD
- Check all 14 connections
- Verify code uploaded successfully

### Problem: Erratic Distance Readings
- Check sensor alignment
- Verify 5V power to sensor
- Add decoupling capacitors
- Move away from metal surfaces

### Problem: Buzzer Not Sounding
- Check transistor orientation
- Verify Pin 8 output (use multimeter)
- Test buzzer with direct 5V
- Check transistor with multimeter

### Problem: LEDs Not Lighting
- Check LED polarity
- Verify resistor value (220Ω)
- Test LED with direct power
- Check pin assignments in code

## 📸 Final Checks

Before declaring the system complete:

- [ ] All connections are secure
- [ ] No exposed metal touching
- [ ] Code uploads without errors
- [ ] LCD displays correctly
- [ ] Sensor gives consistent readings
- [ ] Buzzer sounds clearly
- [ ] LEDs illuminate properly
- [ ] System runs for 1 hour continuously
- [ ] Enclosure is properly sealed
- [ ] All mounting is secure

## 🔄 Maintenance

### Regular Checks
- Clean sensor face weekly
- Check battery voltage monthly
- Inspect connections quarterly
- Update code as needed

### Battery Care
- Charge when voltage drops below 6.8V
- Don't over-discharge below 6V
- Store at 50% charge if not using
- Replace after 300-500 charge cycles

## 📝 Revision History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | Jan 2024 | Initial assembly guide |

---

**Need Help?**  
Refer to the Arduino documentation or component datasheets in the `/docs` folder.

**Author:** Adeniran Precious Adebayo  
**University:** University of Abuja
