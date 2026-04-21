// Bluetooth module HC-06 pins
// VCC - 5V
// GND - GND
// TXD - pin 0
// RXD - pin 1

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

String data = "";

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      processData(data);
      data = "";
    } else {
      data += c;
    }
  }
}

void processData(String input) {
  int r, g, b;

  if (sscanf(input.c_str(), "%d,%d,%d", &r, &g, &b) == 3) {
    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);

    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
  }
}