//this has manual and automatic modes

#include <Servo.h>

Servo servo_pin_5; // initialize servos
Servo servo_pin_9;
Servo servo_pin_12;
bool buttonmode = true;
int buttonPinManual = 3; // Button for manual mode
int buttonPinAutomatic = 10; // Button for automatic mode
int photoPin = A0;

void setup() {
  pinMode(buttonPinManual, INPUT);
  digitalWrite(buttonPinManual, HIGH);
  pinMode(buttonPinAutomatic, INPUT);
  digitalWrite(buttonPinAutomatic, HIGH);

  servo_pin_5.attach(5);
  servo_pin_9.attach(9);
  servo_pin_12.attach(12);

  Serial.begin(9600);
}

void loop() {
  int buttonManualState = digitalRead(buttonPinManual);
  int buttonAutomaticState = digitalRead(buttonPinAutomatic);
  if (buttonAutomaticState == HIGH) {
    buttonmode = !buttonmode;
    delay(500); // Debounce delay
    Serial.println("Mode switched");
  } 

  if (buttonmode == 1) { // Manual mode
    int button3State = digitalRead(3);

    if (button3State == HIGH) {
      Serial.println("Manual Mode: button 3 pressed");
      performActions();
    }
  } else { // Automatic mode
    int light = analogRead(photoPin);

    if (light < 2) {
      Serial.println("Automatic Mode: Light sensor detected zero value");
      delay(3000);
      performActions();
    }
  }
}

void performActions() {
  servo_pin_12.write(160);
  delay(1000);
  servo_pin_12.write(0);
  delay(1000);
  servo_pin_5.write(20);
  delay(1000);
  servo_pin_5.write(180);
  delay(1000);
  servo_pin_9.write(160);
  delay(1000);
  servo_pin_9.write(0);
  delay(1000);
}
