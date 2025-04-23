const int buzzerPin = 8;
const int ledPin = 9;
const unsigned long alertDuration = 3000; // 3 секунды
const unsigned long blinkInterval = 250;  // 250 мс

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char incoming = Serial.read();

    if (incoming == '1') {
      unsigned long startTime = millis();

      while (millis() - startTime < alertDuration) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(blinkInterval);

        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        delay(blinkInterval);
      }
    }
  }
}
