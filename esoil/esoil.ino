#include <DHT.h>

#define SOIL_MOISTURE_PIN A0  // Analog pin for soil moisture sensor
#define DHT_PIN 2             // Digital pin for DHT sensor
#define DHT_TYPE DHT22        // DHT sensor type (DHT11, DHT22, DHT21)

#define SOIL_MOISTURE_THRESHOLD_LOW 30  // Soil moisture level to turn the motor on (in percentage)
#define SOIL_MOISTURE_THRESHOLD_HIGH 80 // Soil moisture level to turn the motor off (in percentage)

#define MOTOR_PIN 9  // Digital pin for controlling the motor

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);  // Ensure the motor is initially turned off
  Serial.begin(9600);
}

void loop() {
  // Read soil moisture value
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Soil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.println("%");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  // Check soil moisture level
  if (soilMoistureValue < SOIL_MOISTURE_THRESHOLD_LOW) {
    // Soil is too dry, turn the motor on
    digitalWrite(MOTOR_PIN, HIGH);
    Serial.println("Turning motor ON");
  } else if (soilMoistureValue > SOIL_MOISTURE_THRESHOLD_HIGH) {
    // Soil is too wet, turn the motor off
    digitalWrite(MOTOR_PIN, LOW);
    Serial.println("Turning motor OFF");
  }

  delay(1000);  // Delay for reading at 1-second intervals
}
