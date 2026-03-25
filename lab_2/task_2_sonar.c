#include <NewPing.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200

#define LED_PIN 3

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Debugging
  //Serial.begin(9600);
}

void loop() {
  delay(50); // small delay for stability

  int distance = sonar.ping_cm();

  //Serial.print("Distance: ");
  //Serial.println(distance);

  if (distance > 0 && distance < 50) {
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
  }
}