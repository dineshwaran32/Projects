//Tech Trends Shameer

#define BLYNK_TEMPLATE_ID "TMPLIAjddf20T5"
#define BLYNK_DEVICE_NAME "Temperature and Humidity Monitor"
#define BLYNK_AUTH_TOKEN "122RywymdfdddgGfMd1jkZ0STNhRQecR12ayq"

#define BLYNK_PRINT Serial
#include <WiFi.h>
//#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp32.h>

#include <DHT.h>


char auth[] = "tvwURl1k7bQ8zuC50R8JnYIB7rK6OYvb";

char ssid[] = "Dinesh";  // type your wifi name
char pass[] = "DINESH123";  // type your wifi password

BlynkTimer timer;


#define DHTPIN D2 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{   
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
  
}

void loop()
{
  Blynk.run();
  timer.run();
 }
