const int ledPin = 8;
const int buzzerPin = 9;

String message = "";
bool active = false;

int dotTime = 200; // time it takes for each dot

// Morse cpde (A-Z & 0-9)
String morseTable[36] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",    // K-T
  "..-", "...-", ".--", "-..-", "-.--", "--..",                            // U-Z
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};
char alphaNum[36] = {
  'A','B','C','D','E','F','G','H','I','J',
  'K','L','M','N','O','P','Q','R','S','T',
  'U','V','W','X','Y','Z',
  '0','1','2','3','4','5','6','7','8','9'
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Unesi poruku:");
}

void loop() {
  if (Serial.available() > 0) {
    message = Serial.readStringUntil('\n');
    message.toUpperCase();
    active = true;
  }

  if (active) {
    for (int i = 0; i < message.length(); i++) {
      char c = message[i];

      if (c == ' ') {
        delay(dotTime * 7); // delay between words
        continue;
      }

      String code = "";
      for (int j = 0; j < 36; j++) {
        if (c == alphaNum[j]) {
          code = morseTable[j];
          break;
        }
      }

      for (int k = 0; k < code.length(); k++) {
        if (code[k] == '.') {
          digitalWrite(ledPin, HIGH);
          digitalWrite(buzzerPin, HIGH);
          delay(dotTime);       // dot delay
        } else if (code[k] == '-') {
          digitalWrite(ledPin, HIGH);
          digitalWrite(buzzerPin, HIGH);
          delay(dotTime * 3);   // dash delay
        }
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
        delay(dotTime);
      }

      delay(dotTime * 3); // delay between letters
    }

    active = false;
    Serial.println("Poruka završena. Unesi novu:");
  }
}