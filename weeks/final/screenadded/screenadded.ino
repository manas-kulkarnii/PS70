//this has manual and automatic modes

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };


#include <Servo.h>

Servo servo_pin_5; // initialize servos
Servo servo_pin_9;
Servo servo_pin_11;
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
  servo_pin_11.attach(11);

  Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  welcome();

}

void loop() {
  int buttonManualState = digitalRead(buttonPinManual);
  int buttonAutomaticState = digitalRead(buttonPinAutomatic);
  if (buttonAutomaticState == HIGH) {
    buttonmode = !buttonmode;
    
    if (buttonmode == 1)
    {Serial.println("Mode switched to manual"); declaremanualswitch();}
    else
    {Serial.println("Mode switched to auto"); declareautoswitch();}
  } 

  if (buttonmode == 1) { // Manual mode
    int button3State = digitalRead(3);

    if (button3State == HIGH) {
      Serial.println("Manual Mode: button 3 pressed");
            declaremanual();
      performActions();
    }
  } else { // Automatic mode
    int light = analogRead(photoPin);

    if (light == 0) {
      Serial.println("Automatic Mode: Light sensor detected zero value");
      declareauto();
      delay(2000);
      performActions();
      light == 7;
    }
  }
}

void performActions() {
  servo_pin_11.write(160);
  delay(1000);
  servo_pin_11.write(0);
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

void welcome(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Manas' PS70 Project!"));
  display.display();
  delay(2000);
}


void declaremanual(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("manual fold time!"));
  display.display();
  delay(2000);
}

void declareauto(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("auto fold time!"));
  display.display();
  delay(2000);
}

void declaremanualswitch(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("mode switched to manual!"));
  display.display();
  delay(2000);
}

void declareautoswitch(void) {
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("mode switched to auto!"));
  display.display();
  delay(2000);
}
