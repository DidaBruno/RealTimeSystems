int buttonPin = 2;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  for (int i = 3; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }

  randomSeed(analogRead(A0));
}

void loop() {
  
  if (digitalRead(buttonPin) == LOW) {  // LOW because of INPUT_PULLUP
    int diceValue = random(1, 7);
    displayDice(diceValue);
    delay(300); //debounce
  }
}

void turnOffAll() {
  for (int i = 3; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
}

void displayDice(int value) {
  turnOffAll();
  /* dice matrix
  3  4  5
  6  7  8
  9  10 11
  */
  if (value == 1) {
    digitalWrite(7, HIGH);
  }

  if (value == 2) {
    digitalWrite(3, HIGH);
    digitalWrite(11, HIGH);
  }

  if (value == 3) {
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
  }

  if (value == 4) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
  }

  if (value == 5) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
  }

  if (value == 6) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
  }
}