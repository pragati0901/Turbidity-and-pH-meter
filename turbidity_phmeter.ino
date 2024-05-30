#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Turbidity sensor pin
int turbiditySensorPin = A0;

// pH sensor pin
const int pHSensorPin = A1;  // Analog input pin for pH sensor

// LED indicator pins
int clearLEDPin = 3;
int cloudyLEDPin = 4;
int dirtyLEDPin = 5;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  // Set LED pins as output
  pinMode(clearLEDPin, OUTPUT);
  pinMode(cloudyLEDPin, OUTPUT);
  pinMode(dirtyLEDPin, OUTPUT);

  // Initialize serial communication for pH sensor debugging
  Serial.begin(9600);
}

void loop() {
  // Read turbidity sensor value
  int turbiditySensorValue = analogRead(turbiditySensorPin);
  int turbidity = map(turbiditySensorValue, 0, 640, 100, 0);
  delay(100);

  // Display turbidity on LCD
  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");
  lcd.print(turbidity);
  lcd.print("   ");  // Clear any previous digits
  
  // Turbidity indicator
  if (turbidity < 20) {
    digitalWrite(clearLEDPin, HIGH);
    digitalWrite(cloudyLEDPin, LOW);
    digitalWrite(dirtyLEDPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" It's CLEAR ");
  } else if (turbidity < 50) {
    digitalWrite(clearLEDPin, LOW);
    digitalWrite(cloudyLEDPin, HIGH);
    digitalWrite(dirtyLEDPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print(" It's CLOUDY ");
  } else {
    digitalWrite(clearLEDPin, LOW);
    digitalWrite(cloudyLEDPin, LOW);
    digitalWrite(dirtyLEDPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print(" It's DIRTY ");
  }

  // Read pH sensor value
  int pHSensorValue = analogRead(pHSensorPin);

  // Convert the analog voltage to pH using your sensor's specifications
  // Adjust the mapping range according to your pH sensor specifications
  float pHValue = map(pHSensorValue, 0, 1023, 0, 14);

  // Print the pH value to serial monitor
  Serial.print("pH Value: ");
  Serial.println(pHValue);

  // Display pH value on LCD
  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(pHValue, 2); // Display with 2 decimal places
  lcd.print("   ");  // Clear any previous digits

  delay(1000);  // Adjust delay as needed
}
