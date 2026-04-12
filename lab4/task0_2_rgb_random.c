const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;

int r = 255;
int g = 255;
int b = 255;

bool ButtonState = LOW;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  randomSeed(analogRead(A0)); 
}

void loop() {

  if (Serial.available() > 0) {
    int input = Serial.parseInt();

    if (input == 1) {
      r = random(0, 256);
    }
    else if (input == 2) {
      g = random(0, 256);
    }
    else if (input == 3) {
      b = random(0, 256);
    }
  }

  bool ButtonState = digitalRead(buttonPin);

  if (ButtonState == HIGH) {
    r = 255;
    g = 255;
    b = 255;
    delay(200);
  }

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}