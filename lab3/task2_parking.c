#include <LiquidCrystal.h>
#include <NewPing.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 100

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

int led1 = 11;
int led2 = 12;

char incoming;
bool active = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("1: Upali senzor");
  lcd.setCursor(0, 1);
  lcd.print("0: Ugasi senzor");
}

void loop() {

  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == '1') {
      active = true;
      lcd.clear();

    } else if (input == '0') {
      active = false;

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1: Upali senzor");
      lcd.setCursor(0, 1);
      lcd.print("0: Ugasi senzor");
    }
  }

  if (active) {

    int distance = sonar.ping_cm();

    if (distance == 0) return;

    lcd.setCursor(0, 0);
    lcd.print("Udalj: ");
    lcd.print(distance);
    lcd.print(" cm   ");

    if (distance < 10) {
      lcd.setCursor(0, 1);
      lcd.print("Zaustavi vozilo");
    } else {
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }

    if (distance >= 50) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);

    } else {
      int delayTime = map(distance, 10, 50, 100, 500);

      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      delay(delayTime);

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(delayTime);
    }
  }
}