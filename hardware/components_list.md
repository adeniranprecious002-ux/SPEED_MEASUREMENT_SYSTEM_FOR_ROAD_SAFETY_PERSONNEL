# Bill of Materials (BOM)

## Speed Measurement System for Road Safety Personnel

This document lists all components required to build the speed measurement system.

### Electronic Components

| S/N | Component | Specification | Quantity | Unit Price (₦) | Total (₦) | Purpose |
|-----|-----------|--------------|----------|---------------|-----------|---------|
| 1 | Arduino Uno | ATmega328P, 16MHz | 1 | 3,500 | 3,500 | Main microcontroller |
| 2 | Ultrasonic Sensor | HC-SR04, 2cm-400cm range | 1 | 500 | 500 | Distance/Speed measurement |
| 3 | LCD Display | 16x2 characters, I2C/Parallel | 1 | 800 | 800 | Speed display |
| 4 | Buzzer | 5V piezo buzzer | 1 | 100 | 100 | Audio alert |
| 5 | Lithium Battery | 7.4V, 2200mAh | 1 | 2,000 | 2,000 | Power supply |
| 6 | Battery Holder | For Li-ion battery | 1 | 200 | 200 | Battery mounting |
| 7 | Voltage Regulator | 7805, 5V output | 1 | 50 | 50 | Voltage regulation |
| 8 | Transistor | BC547 NPN | 2 | 20 | 40 | Switching circuits |
| 9 | Resistor | 220Ω, 1/4W | 3 | 5 | 15 | LED current limiting |
| 10 | Resistor | 10kΩ, 1/4W | 2 | 5 | 10 | Pull-up resistors |
| 11 | LED | 5mm Red | 1 | 20 | 20 | Over-speed indicator |
| 12 | LED | 5mm Green | 1 | 20 | 20 | Normal speed indicator |
| 13 | Push Button | Momentary switch | 1 | 50 | 50 | Reset/Settings |
| 14 | Potentiometer | 10kΩ linear | 1 | 100 | 100 | LCD contrast adjustment |
| 15 | Breadboard | 830 tie-points | 1 | 500 | 500 | Prototyping |
| 16 | Jumper Wires | Male-to-Male, 20pcs | 1 set | 300 | 300 | Connections |
| 17 | Jumper Wires | Male-to-Female, 20pcs | 1 set | 300 | 300 | Connections |
| 18 | Capacitor | 100μF, 25V electrolytic | 2 | 30 | 60 | Power smoothing |
| 19 | Capacitor | 0.1μF ceramic | 2 | 10 | 20 | Decoupling |
| 20 | USB Cable | Type A to Type B | 1 | 200 | 200 | Programming/Power |

### Enclosure and Mounting

| S/N | Component | Specification | Quantity | Unit Price (₦) | Total (₦) | Purpose |
|-----|-----------|--------------|----------|---------------|-----------|---------|
| 21 | Project Box | ABS plastic, 15x10x5cm | 1 | 800 | 800 | Housing |
| 22 | Mounting Screws | M3 x 10mm | 10 | 5 | 50 | Assembly |
| 23 | Standoffs | M3 x 10mm | 4 | 30 | 120 | PCB mounting |
| 24 | Double-sided Tape | 3M adhesive | 1 roll | 200 | 200 | Component mounting |

### Tools Required (Not Included in Cost)

| Tool | Purpose |
|------|---------|
| Soldering Iron | Component soldering |
| Wire Stripper | Wire preparation |
| Multimeter | Testing and debugging |
| Screwdriver Set | Assembly |
| Pliers | Wire cutting and bending |
| Hot Glue Gun | Secure mounting |

## Cost Summary

| Category | Total Cost (₦) |
|----------|----------------|
| Electronic Components | 8,785 |
| Enclosure and Mounting | 1,170 |
| **Grand Total** | **9,955** |

### Cost Breakdown Pie Chart

```
Electronic Components: 88.3%
Enclosure & Mounting: 11.7%
```

## Notes

1. **Currency:** All prices are in Nigerian Naira (₦)
2. **Market Variation:** Prices may vary depending on supplier and location
3. **Bulk Purchase:** Prices can be reduced with bulk orders
4. **Alternative Sources:** Components can be purchased from:
   - Local electronics markets (Alaba International, Lagos)
   - Online stores (Jumia, Konga, AliExpress)
   - Electronics distributors

## Optional Upgrades

| Component | Specification | Estimated Cost (₦) | Benefit |
|-----------|--------------|-------------------|---------|
| Solar Panel | 5V, 2W | 1,500 | Renewable power source |
| Camera Module | OV7670 | 2,000 | Vehicle identification |
| GPS Module | NEO-6M | 1,800 | Location tracking |
| WiFi Module | ESP8266 | 1,200 | IoT connectivity |
| SD Card Module | With 16GB card | 800 | Data logging |
| OLED Display | 0.96" I2C | 600 | Better display quality |

## Supplier Information

### Recommended Local Suppliers (Nigeria)

1. **Hub360, Abuja**
   - Address: Dummec plaza behind Area 1 Shopping Centre, FCT
   - Products: All electronic components

2. **Microscale Embedded Ltd, Abuja**
   - Address: Dummec plaza behind Area 1 Shopping Centre, FCT
   - Products: Arduino boards, sensors

3. **Online Stores**
   - Jumia Nigeria: <www.jumia.com.ng>
   - Konga: <www.konga.com>
   - RoboMall Nigeria: <www.robomall.ng>

### International Suppliers (Longer Delivery)

1. **AliExpress**
   - Website: <www.aliexpress.com>
   - Shipping: 2-4 weeks to Nigeria

2. **Amazon**
   - Website: <www.amazon.com>
   - Note: Check shipping availability to Nigeria

---

**Last Updated:** January 2024  
**Project:** Speed Measurement System for Road Safety Personnel  
**Author:** Adeniran Precious Adebayo
