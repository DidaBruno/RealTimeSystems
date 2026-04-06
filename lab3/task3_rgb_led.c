int buttonPin = A0;
int lastButtonState = HIGH;
int currentButtonState;

int pattern = 1;

int ledPins[3][3] = {
  {3, 5, 6},   // LED1
  {9, 10, 11}, // LED2
  {2, 4, 7}    // LED3
};

void setup() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      pinMode(ledPins[i][j], OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    pattern++;
    if (pattern > 3) pattern = 1;
    delay(200); // debounce
  }

  lastButtonState = currentButtonState;

  if (pattern == 1) pattern1();
  else if (pattern == 2) pattern2();
  else if (pattern == 3) pattern3();
}

void pattern1() {   // blinking
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      digitalWrite(ledPins[i][j], HIGH);
  delay(200);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      digitalWrite(ledPins[i][j], LOW);
  delay(200);
}

void pattern2() {   // wave
  for (int color = 0; color < 3; color++) {
    for (int led = 0; led < 3; led++) {
      digitalWrite(ledPins[led][color], HIGH);
      delay(150);
      digitalWrite(ledPins[led][color], LOW);
    }
  }
}

void pattern3() {   // random
  int led = random(0, 3);
  int color = random(0, 3);
  digitalWrite(ledPins[led][color], HIGH);
  delay(100);
  digitalWrite(ledPins[led][color], LOW);
  delay(100);
}