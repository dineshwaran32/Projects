#include <CD74HC4067.h>

CD74HC4067 my_mux(8, 9, 10, 11);  // (S0, S1, S2, S3)
const int ledChannel = 3;  // Assuming the LED is connected to channel 3

void setup()
{
  // Set the channel to output mode
  my_mux.channel(ledChannel);
}

void loop()
{
  // Turn on the LED
  analogWrite(my_mux.sigPin(), 255);  // 255 for full brightness
  delay(1000);  // Delay for 1 second
  // Turn off the LED
  analogWrite(my_mux.sigPin(), 0);  // 0 for off
  delay(1000);  // Delay for 1 second
}
