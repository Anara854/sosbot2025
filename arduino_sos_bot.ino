
const int buzzerPin = 8;
const int ledPin = 9;

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
      while (millis() - startTime < 3000) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(250);
        digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
        delay(250);
      }
    }
  }
}
