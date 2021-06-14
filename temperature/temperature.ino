#include <dht.h> // include the library you just downloaded

dht DHT;

#define DHT11_PIN 7 // define which pin you are using

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN); // read sensor
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature); // print the temperature
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity); // print the humidity
  delay(1000);
}
