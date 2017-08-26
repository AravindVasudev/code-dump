#include <Servo.h>

// Init vars
Servo servo;
int servoPin = 8;
int buzzerPin = 4;

int pirPin = 7;
int pirValue;

void setup() {
  // setup pin modes
  pinMode(pirPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  servo.attach(8);
}

void loop() {
  // read PIR input
  pirValue = digitalRead(pirPin);

  // if motion is detected
  if (pirValue == 1) {
    digitalWrite(buzzerPin, HIGH); // BEEP
    servo.write(180); // Lock the door
  } else { // if motion is still
    digitalWrite(buzzerPin, LOW); // DON'T BEEP
    servo.write(0); // unlock the door
  }

}
