int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
 
void setup () 
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);
  Serial.println (sensorValue, DEC);
  if (sensorValue >= 11) {
    digitalWrite(ledPin, HIGH); 
    delay(100);
  }else{
    digitalWrite(ledPin, LOW); 
  }
 
}
