// Pin Connection
const int LEDPins[] = {2, 3, 4, 5, 6}; // LED Pin
const int LEDCount = 5; // LED Number

int INCREMENT_VALUE = 1; 
int WAIT_TIME = 500; // Waiting time (miliseconds)

int binaryIncrement[5] = {0};
int DECIMAL_NUMBER = 0;

void updateLEDs() {
  for (int i = 0; i < LEDCount; i++) {
    digitalWrite(LEDPins[i], binaryIncrement[i]);
  }
}

void setup() {
  for (int i = 0; i < LEDCount; i++) {
    pinMode(LEDPins[i], OUTPUT);
  }
}

void loop() {
  // INCREMENT_VALUE control
  if (DECIMAL_NUMBER <= 1 || DECIMAL_NUMBER > 31) {
    DECIMAL_NUMBER = DECIMAL_NUMBER % 32;
  }

  // WAIT_TIME control
  if (WAIT_TIME <= 0) {
    Serial.println("Error: WAIT_TIME must be a positive integer.");
    return; // Stop program
  }

  // Binary with INCREMENT_VALUE value
  for (int i = 0; i < LEDCount; i++) {
    binaryIncrement[i] = (DECIMAL_NUMBER >> i) & 1;
  }
  // LED Update
  updateLEDs();
  
  delay(WAIT_TIME);

  DECIMAL_NUMBER += INCREMENT_VALUE;
}
