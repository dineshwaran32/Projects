int motorpin1 = 7;

int led = 3;           // The pin that the LED is attached to
int speakerPin = 8;       // The digital pin connected to the speaker
 

void setup() {
  // Initialize serial communication:
  Serial.begin(9600);

  // Initialize the LED pin as an output:
  pinMode(led, OUTPUT);

  // Initialize the motor control pins as outputs:
  pinMode(motorpin1, OUTPUT);
  

  // Initialize the speaker pin as an output:
  pinMode(speakerPin, OUTPUT);

  // Set an initial state for the motor control pins (e.g., stop the motor):
  digitalWrite(motorpin1, HIGH);
  
  noTone(speakerPin);  // Turn off the speaker initially.
}

void loop() {

  // Read incoming data from serial communication:
  
//if (Serial.available() > 0){
    char incomingByte = Serial.read();
    Serial.println(incomingByte);
    Serial.println("out if");
  // Check the received character
  if (incomingByte == 'O') {
    // Do something when 'H' is received, e.g., turn on the LED, start the motor, and play a beep sound.
    Serial.println("in if");
    digitalWrite(led, HIGH);
    digitalWrite(motorpin1, LOW);

    tone(speakerPin, 1000);  // Play a 1000Hz tone on the speaker.
    delay(10000);            // Delay to control the duration of the beep.
    noTone(speakerPin);      // Turn off the speaker.
  }
  Serial.println("asf");
  delay(1000);
}
