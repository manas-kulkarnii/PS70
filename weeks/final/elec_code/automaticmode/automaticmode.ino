// this is just automatic mode

int photoPin = A0;
#include <Servo.h>
Servo servo_pin_5; // initialize servos
Servo servo_pin_9;
Servo servo_pin_12;

void setup() {
  servo_pin_5.attach(5);
  servo_pin_9.attach(9);
  servo_pin_12.attach(12);
  Serial.begin(9600);

}

void loop() {
  int light = analogRead(photoPin);
  Serial.println(light);
  delay(2000);
  if (light == 0)
  {
    servo_pin_12.write(160); // turn motor 1 160 degrees
    delay(1000);
    servo_pin_12.write(0); // turn motor back to 0 degrees
    delay(1000);
    servo_pin_5.write(20); // motor 2 20 degrees
    delay(1000);
    servo_pin_5.write(180); // motor 2 back to 180 degrees
    delay(1000);
    servo_pin_9.write(160); // motor 3 160 degrees
    delay(1000);
    servo_pin_9.write(0); // motor 3 back to 0 degrees
    delay(1000);
  }

}