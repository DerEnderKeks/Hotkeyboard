int inputPin = A0;         // Input pin for buttons
int minButtonDelay = 300;  // Minimal delay between sending the same button

int buttons[16][2] = {     // Array of buttons, while each array contains the boundaries for a button {min, max}
  {7, 12},
  {22, 26},
  {54, 57},
  {325, 329},
  
  {152, 157},
  {292, 298},
  {489, 494},
  {897, 901},
  
  {232, 236},
  {410, 414},
  {617, 621},
  {942, 946},
  
  {469, 473},
  {672, 676},
  {831, 835},
  {992, 997},
};

// NO DON'T TOUCH THAT
int inputValue = 0;                  // Current input
int button = -1;                     // Last button
int buttonCount = 0;                 // Number of buttons, get's calculated automatically
unsigned long lastButtonChange = 0;  // Timestamp of last button press to enforce delay

void setup() {
  Serial.begin(115200);
  buttonCount = sizeof(buttons) / sizeof(int[2]); // Calculate how many buttons there are
}

void loop() {
  inputValue = analogRead(inputPin); // Read the current input value

  for (int i = 0; i < buttonCount; i++) { // Check for every possible button whether it's pressed
    if ((i != button || lastButtonChange < millis() - minButtonDelay) && buttons[i][0] <= inputValue && buttons[i][1] >= inputValue) { // Check if it's a different button than the last one or if the delay is over and if the input matches the currently iterated button
      button = i; // set the current button id

      lastButtonChange = millis(); // Update the timestamp
      
      Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT | MODIFIERKEY_SHIFT | MODIFIERKEY_GUI); // Set the modifiers
      Keyboard.set_key1((uint8_t) (button + 4)); // Set the key based on button id (where button 1 = a)
      Keyboard.send_now(); // Submit input 
      
      Keyboard.set_modifier(0); // Reset the modifiers
      Keyboard.set_key1(0); // Reset the key
      Keyboard.send_now(); // Submit input

      Serial.println("Button: " + String(button + 1) + " (" + String((char) (button + 65)) + ")"); // Log the button to serial
    }
  }
  
  //Serial.println("Input: " + String(average) + ", Button: " + String(button + 1) + " (" + String((char) (button + 65)) + ")"); // Debug logging

  delay(1);
}
