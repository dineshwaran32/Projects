
#include "DHT.h"
#define Dpin 2

DHT dht(Dpin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
 
  delay(2000);

  
  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) 
  {
    Serial.println("Failed to read from DHT11 sensor!");  
  } 
  else 
  {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("  |  "); 
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
  }
}
