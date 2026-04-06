const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int buttonPin = 2;

int state = 1;

bool lastButtonState = HIGH;
bool currentButtonState;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  // falling edge
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    state++;

    if (state > 3) {
      state = 1;
    }

    delay(200); // debounce
  }

  lastButtonState = currentButtonState;

  if (state == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (state == 2) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } 
  else { // state == 3
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}