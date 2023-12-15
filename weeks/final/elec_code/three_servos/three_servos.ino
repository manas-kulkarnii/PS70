//this is just manual mode

#include <Servo.h>
Servo servo_pin_5; // initialize servos
Servo servo_pin_9;
Servo servo_pin_12;
int buttonmode = 0;

void setup()
{
  pinMode(3, INPUT); // button as input
  digitalWrite(3, HIGH);
  servo_pin_5.attach(5);
  servo_pin_9.attach(9);
  servo_pin_12.attach(11);
  Serial.begin(9600);
}

void loop()
{
  Serial.print(digitalRead(3));
  if (digitalRead(3) == HIGH) { 
    if (buttonmode == 0) {
      buttonmode = 1;
    } else if (buttonmode == 1) {
      buttonmode = 0;
    }
    delay(500);
  }
  if (buttonmode == 1)
  {
    Serial.println("button=1");
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
    buttonmode = 0;
  }
}

