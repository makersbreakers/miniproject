
int sensorPin = 0;
int period = 150; //too low is unstable, too high may not measure high heartrate
float change = 0;
float endMillis = 0;
float startMillis = 0;
float T = 0.00;
int oldValue = 0;
int oldChange = 0;
int pulse = 0;
int n = 0;

void setup ()
{
Serial.begin (9600);
}

void loop ()
{
int rawValue = analogRead (sensorPin);
/*Serial.print (rawValue);
Serial.print (" , ");
Serial.print (oldValue);
Serial.print (" , "); */
change = rawValue - oldValue;
Serial.println (change);
oldValue = rawValue;
if (change >= 0 && oldChange < 0) { //looking for the change in light transmission due to pulse
n++;
Serial.print(" n = ");
Serial.println(n); //can use to check pulses are being caught
}
if (n >= 10) {
endMillis = millis();
T = (endMillis - startMillis) / 1000;
//Serial.print(endMillis - startMillis);
// Serial.print(" T = ");
//Serial.print(T);
pulse = 60 * (n / T);
Serial.print(" Pulse rate = ");
Serial.println(pulse);
n = 0;
pulse = 0;
startMillis = millis();
}


oldChange = change;
delay (period);
}
