#include <LiquidCrystal.h>

// LCD pins (adjustable)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int motorPin = 9;
int ledPin = 8;

char incoming;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("1: Upali motor");
  lcd.setCursor(0, 1);
  lcd.print("0: Ugasi motor");
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == '1') {
      digitalWrite(motorPin, HIGH);
      digitalWrite(ledPin, HIGH);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motor je u radu");

    } else if (input == '0') {
      digitalWrite(motorPin, LOW);
      digitalWrite(ledPin, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1: Upali motor");
      lcd.setCursor(0, 1);
      lcd.print("0: Ugasi motor");
    }
  }
}