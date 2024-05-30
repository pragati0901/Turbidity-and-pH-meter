#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);

int sensorPin = A0;

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int turbidity = map(sensorValue, 0, 640, 100, 0);
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("turbidity:");
  lcd.print("   ");
  lcd.setCursor(10, 0);
  lcd.print(turbidity);
  delay(100);

  if (turbidity < 20) {
    digitalWrite(3, HIGH);  // Update pin number to 3
    digitalWrite(4, LOW);   // Update pin number to 4
    digitalWrite(5, LOW);   // Update pin number to 5
    lcd.setCursor(0, 1);
    lcd.print(" its CLEAR ");
  }
  if ((turbidity > 10) && (turbidity < 50)) {
    digitalWrite(3, LOW);   // Update pin number to 3
    digitalWrite(4, HIGH);  // Update pin number to 4
    digitalWrite(5, LOW);   // Update pin number to 5
    lcd.setCursor(0, 1);
    lcd.print(" its CLOUDY ");
  }
  if (turbidity > 50) {
    digitalWrite(3, LOW);   // Update pin number to 3
    digitalWrite(4, LOW);   // Update pin number to 4
    digitalWrite(5, HIGH);  // Update pin number to 5
    lcd.setCursor(0, 1);
    lcd.print(" its DIRTY ");
  }
}
