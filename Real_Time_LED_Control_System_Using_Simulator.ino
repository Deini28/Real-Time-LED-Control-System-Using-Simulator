// Pin definitions
const int ledPin1 = 13; // Red LED
const int ledPin2 = 12; // Green LED
const int buttonPin1 = 2;
const int buttonPin2 = 3;

// Variables
int blinkRate = 500; // Default blink rate in milliseconds
volatile bool colorToggle = false;
unsigned long previousMillis = 0;
int currentLedPin = ledPin1;

void setup() {
  // Initialize pins
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  // Attach interrupts
  attachInterrupt(digitalPinToInterrupt(buttonPin1), changeBlinkRate, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), changeColor, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();

  // Blink LED at the current rate
  if (currentMillis - previousMillis >= blinkRate) {
    previousMillis = currentMillis;
    digitalWrite(currentLedPin, !digitalRead(currentLedPin));
  }
}

void changeBlinkRate() {
  blinkRate = (blinkRate == 500) ? 250 : 500; // Toggle between 1 Hz and 2 Hz
}

void changeColor() {
  // Toggle LED pin
  currentLedPin = (currentLedPin == ledPin1) ? ledPin2 : ledPin1;
}
