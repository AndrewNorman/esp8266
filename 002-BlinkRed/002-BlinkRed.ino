/*
 * Connect the Red LED (plus resistor) to the pin
 * that you have entered the number below
 */
#define RED_LED 16

/*
 * Set the digital pin that has the Red LED
 * attached to operate as an Output pin
 * 
 * i.e. We can turn it on and off by writing to it
 */
void setup()
{
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
}

/*
 * Write a HIGH value to the RED_LED pin, which
 *  will turn on the LED
 * Then sleep 1 second (1000 milliseconds)
 * Write a LOW value to the RED_LED pin, which
 *  will turn the LED off
 * Then sleep 1 second (1000 milliseconds)
 */
void loop()
{
  Serial.println("On");
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  
  Serial.println("Off");
  digitalWrite(RED_LED, LOW);
  delay(1000);
}
