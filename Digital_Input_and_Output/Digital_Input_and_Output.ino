/*
OSEPP Arduino Basics Tutorial 4 - Digital Input and Output
In this game, the LED will loop from white, yellow, green, red, then back to
white.  The goal is to press the push button at the exact moment when the green
LED is ON.  Each time you get it right, the LED will speed up and the 
difficulty will increase
*/

int currentLED = 2;  // current LED, starting with the white LED
int delayValue = 200; // current milliseconds of delay

// digital pins of the LEDs and button
const int whiteLED = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int redLED = 5;
const int BUTTON = 12;

void setup() {
  // initialize button as input
  pinMode(BUTTON, INPUT);
  
  // initialize LEDs as output
  pinMode(whiteLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

/*
Function to check whether the user is pressing the button
Returns 1 if the button is pressed, 0 if the button is not pressed
*/
int checkInput() {
  if (digitalRead(BUTTON) == 0) {
    return 1;
  } else {
    return 0;
  }
}

void loop() {
  // check if the button is pressed while an LED is lit
  if (checkInput()) {
    // blink whichever LED was lit so they know which one they hit
    digitalWrite(currentLED, HIGH);
    delay(200);
    digitalWrite(currentLED, LOW);
    delay(200);
    digitalWrite(currentLED, HIGH);
    delay(200);
    digitalWrite(currentLED, LOW);
    delay(200);
    // check whether they hit the correct (green) LED
    if (currentLED == 4) {
      // yay you got it right!  time to speed up
      delayValue = delayValue - 20;
    } 
  }
  
  
  // display current LED for delayValue milliseconds
  digitalWrite(currentLED, HIGH);
  delay(delayValue);
  digitalWrite(currentLED, LOW);
  delay(delayValue);
  
  // loop LED from white -> yellow -> green -> red
  currentLED = currentLED + 1;
  if (currentLED > redLED) {
    currentLED = whiteLED;
  }
}
