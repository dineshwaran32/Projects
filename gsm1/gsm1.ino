#include <SoftwareSerial.h>

// Define the RX and TX pins for the GSM module
#define GSM_TX_PIN 2 // Connect GSM TX to Arduino pin 2
#define GSM_RX_PIN 3 // Connect GSM RX to Arduino pin 3

SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
  
  // Initialize GSM serial communication with the same baud rate
  gsmSerial.begin(9600);
  
  // Wait for the GSM module to initialize
  delay(2000);
}

void loop() {
  // Send AT command to check if the GSM module is ready
  gsmSerial.println("AT");
  delay(1000);
  
  // Check if the GSM module responds with "OK"
  if(gsmSerial.find("OK")) {
    Serial.println("GSM module is ready.");
    
    // Set GSM module to text mode
    gsmSerial.println("AT+CMGF=1");
    delay(1000);
    
    // Specify the recipient phone number
    gsmSerial.println("AT+CMGS=\"+919597203715\""); // Replace with recipient's phone number
    delay(1000);
    
    // Specify the SMS content
    gsmSerial.print("Hello from Arduino!");
    
    // End the SMS by sending Ctrl+Z
    gsmSerial.write(26);
    delay(1000);
    
    // Print a message to serial monitor
    Serial.println("SMS sent!");
  } else {
    // If GSM module is not ready, print an error message
    Serial.println("Error: GSM module not ready!");
  }
  
  // Wait for 10 seconds before sending another SMS
  delay(10000);
}
