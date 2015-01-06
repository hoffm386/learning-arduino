/*
OSEPP Arduino Basics Tutorial 3 - Digital Input
*/

const int buttonPin = 12; // Use digital pin 12 for the button pin
int buttonState = 0;      // Variable for storing the button status

void setup() {
  // Initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  
  // Initialize the serial port
  Serial.begin(9600); // start serial for output
}

void loop() {
  // Read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  
  // Output button state
  Serial.print("The button state is ");
  Serial.println(buttonState);
  
  // Delay 1 second
  delay(1000);
}
