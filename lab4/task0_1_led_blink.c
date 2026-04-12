const int led1 = 8;
const int led2 = 9;
const int button = 2;

volatile int state = 0;

unsigned long delayValue[3] = {1000, 500, 200};

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(button), changeState, FALLING);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(delayValue[state]);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(delayValue[state]);
}

void changeState() {
  state++;
  if (state > 2) state = 0;
}