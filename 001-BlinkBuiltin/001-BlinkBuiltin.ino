/*
 * Set the digital pin that has the built in LED
 * attached to operate as an Output pin
 * 
 * i.e. We can turn it on and off by writing to it
 */
void setup()
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
}

/*
 * Write a HIGH value to the BUILTIN pin, which
 *  will turn on the LED
 * Then sleep 1 second (1000 milliseconds)
 * Write a LOW value to the BUILTIN pin, which
 *  will turn the LED off
 * Then sleep 1 second (1000 milliseconds)
 */
void loop()
{
  Serial.println("On");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  
  Serial.println("Off");
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
