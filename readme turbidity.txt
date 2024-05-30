# Turbidity and pH Meter Project

## Overview
This Arduino project measures turbidity and pH levels in a liquid using a turbidity sensor, a pH sensor, and displays the results on an LCD with an I2C module. The turbidity sensor provides real-time turbidity readings, and the pH sensor measures the acidity or alkalinity of the liquid. The LCD displays both turbidity and pH values, and an RGB LED indicates the pH level through different colors.

## Components
- Arduino board
- Turbidity sensor
- pH sensor
- RGB LED
- LCD display with I2C module
- Jumper wires

## Dependencies
- Arduino IDE
- LiquidCrystal_I2C library (for LCD)
- Adafruit pH Sensor library (for pH sensor)
- Wire library (for I2C communication)

## Setup
1. Connect the turbidity sensor to the analog pin of the Arduino.
2. Connect the VCC and GND of the turbidity sensor to the appropriate pins on the Arduino.
3. Connect the SDA and SCL pins of the I2C module to the corresponding pins on the Arduino.
4. Connect the pH sensor to the designated pins on the Arduino (refer to the sensor datasheet).
5. Connect the RGB LED to the appropriate pins on the Arduino.
6. Upload the provided Arduino code to the Arduino board using the Arduino IDE.
7. Open the serial monitor to view the turbidity and pH readings.

## Pin Configuration
- Turbidity Sensor:
  - VCC: 5V
  - GND: GND
  - Signal: A0 (Analog Pin)

- I2C Module:
  - VCC: 5V
  - GND: GND
  - SDA: A4 (Analog Pin 4)
  - SCL: A5 (Analog Pin 5)

- pH Sensor:
  - Follow the sensor datasheet for specific pin connections.

- RGB LED:
  - Connect the R, G, and B pins to designated pins on the Arduino.

## Calibration
- Adjust the mapping function in the code to match the characteristics of your turbidity sensor.
- Calibrate the pH sensor according to the sensor's datasheet.

## Troubleshooting
If you encounter issues, double-check the connections, ensure libraries are installed, and refer to the datasheets for the components.

## Author
Your Name

## License
This project is licensed under the [MIT License](LICENSE).
